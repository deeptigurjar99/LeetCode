#include <vector>
#include <queue>

class Solution {
public:
    int minDays(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Check if the grid is already disconnected or is a 1x1 grid
        if (isDisconnected(grid) || rows * cols == 1) return 0;
        
        // Try changing each land cell to water and check if it disconnects the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (isDisconnected(grid)) return 1;
                    grid[i][j] = 1; // revert the change if it doesn't disconnect the grid
                }
            }
        }
        
        // If the grid is still connected after trying to change each cell, return 2
        return 2;
    }

private:
    std::vector<int> directions{-1, 0, 1, 0, -1};
    
    bool isDisconnected(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::vector<std::vector<int>> visited(rows, std::vector<int>(cols, 0));
        int islands = 0;
        
        // Use BFS or DFS to count islands
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    if (islands > 0) return true; // More than one island found
                    bfs(grid, visited, i, j);
                    islands++;
                }
            }
        }
        
        return islands != 1;
    }
    
    void bfs(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& visited, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::queue<std::pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nr = r + directions[i];
                int nc = c + directions[i+1];
                
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1 && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
