#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[entrance[0]][entrance[1]] = true;
        int steps = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {
            int sz = q.size();
            steps++;
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny] || maze[nx][ny] == '+')
                        continue;
                    if (nx == 0 || ny == 0 || nx == m - 1 || ny == n - 1)
                        return steps;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<char>> maze = {
        {'+','+','.','+'},
        {'.','.','.','+'},
        {'+','+','+','.'}
    };
    vector<int> entrance = {1, 2};

    Solution sol;
    int result = sol.nearestExit(maze, entrance);

    if (result != -1)
        cout << "Nearest exit is " << result << " steps away." << endl;
    else
        cout << "No exit reachable." << endl;

    return 0;
}
