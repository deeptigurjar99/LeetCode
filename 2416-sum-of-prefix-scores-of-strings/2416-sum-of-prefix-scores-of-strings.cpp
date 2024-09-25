#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int count; // To keep track of how many words pass through this node

    TrieNode() : count(0) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->count++; // Increment the count at this node
        }
    }

    // Calculate the prefix score for the given word
    int calculatePrefixScore(const string& word) {
        TrieNode* node = root;
        int score = 0;

        for (char c : word) {
            node = node->children[c];
            score += node->count; // Add the count of this prefix
        }

        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;

        // Insert all words into the trie
        for (const string& word : words) {
            trie.insert(word);
        }

        vector<int> answer;

        // Calculate the total score for each word
        for (const string& word : words) {
            answer.push_back(trie.calculatePrefixScore(word));
        }

        return answer;
    }
};
