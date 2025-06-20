#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front(); q.pop();
            for (int i = 1; i <= 6; ++i) {
                int next = curr + i;
                if (next > n * n) break;

                auto [row, col] = getCoordinates(next, n);
                if (board[row][col] != -1)
                    next = board[row][col];

                if (next == n * n) return moves + 1;

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1;
    }

    pair<int, int> getCoordinates(int num, int n) {
        int r = (num - 1) / n;
        int c = (num - 1) % n;
        if (r % 2 == 1) c = n - 1 - c;
        return {n - 1 - r, c};
    }
};

int main() {
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}
    };

    Solution sol;
    int result = sol.snakesAndLadders(board);
    if (result != -1)
        cout << "Minimum number of moves: " << result << endl;
    else
        cout << "Cannot reach the end of the board." << endl;

    return 0;
}
