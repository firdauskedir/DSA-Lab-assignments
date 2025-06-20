#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    maxArea = max(maxArea, dfs(grid, r, c, rows, cols));
                }
            }
        }
        return maxArea;
    }

private:
    int dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0)
            return 0;

        grid[r][c] = 0;  // mark visited
        int area = 1;
        area += dfs(grid, r + 1, c, rows, cols);
        area += dfs(grid, r - 1, c, rows, cols);
        area += dfs(grid, r, c + 1, rows, cols);
        area += dfs(grid, r, c - 1, rows, cols);
        return area;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    int result = sol.maxAreaOfIsland(grid);
    cout << "Max area of island: " << result << endl; // Expected: 6

    return 0;
}
