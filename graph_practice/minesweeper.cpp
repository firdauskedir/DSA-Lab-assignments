#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dirs = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
        } else {
            dfs(board, x, y);
        }
        return board;
    }

private:
    void dfs(vector<vector<char>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();
        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] != 'E') return;

        int mines = countMines(board, x, y);
        if (mines > 0) {
            board[x][y] = '0' + mines;
            return;
        }

        board[x][y] = 'B';
        for (auto& dir : dirs) {
            dfs(board, x + dir[0], y + dir[1]);
        }
    }

    int countMines(vector<vector<char>>& board, int x, int y) {
        int count = 0;
        for (auto& dir : dirs) {
            int nx = x + dir[0], ny = y + dir[1];
            if (nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size()) {
                if (board[nx][ny] == 'M') count++;
            }
        }
        return count;
    }
};

void printBoard(const vector<vector<char>>& board) {
    for (auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board = {
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'}
    };
    vector<int> click = {3, 0};

    Solution sol;
    vector<vector<char>> updatedBoard = sol.updateBoard(board, click);

    cout << "Updated Board after click:" << endl;
    printBoard(updatedBoard);

    return 0;
}
