#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Adjacency list for graph
        vector<vector<pair<int, double>>> graph(n);
        
        // Build the graph
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }
        
        // Max-heap to store (probability, node)
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        
        // Visited array to store the maximum probability to reach each node
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        
        while (!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // Early exit if we reach the end node
            if (node == end_node) {
                return prob;
            }
            
            // Explore neighbors
            for (auto& neighbor : graph[node]) {
                int next_node = neighbor.first;
                double edge_prob = neighbor.second;
                
                // If we find a path with a higher probability, update and push to the queue
                if (maxProb[next_node] < prob * edge_prob) {
                    maxProb[next_node] = prob * edge_prob;
                    pq.push({maxProb[next_node], next_node});
                }
            }
        }
        
        // If the end node is unreachable, return 0
        return 0.0;
    }
};
