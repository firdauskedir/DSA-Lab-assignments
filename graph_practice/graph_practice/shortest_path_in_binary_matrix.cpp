#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

// Solution class as before...
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // ...
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0},
        {1, 0, 0},
        {1, 1, 0}
    };
    Solution sol;
    cout << "Shortest path: " << sol.shortestPathBinaryMatrix(grid) << endl;
    return 0;
}

