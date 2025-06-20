#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int>> q;
        unordered_set<string> visited;
        q.push({0, 1});
        visited.insert("0_1");

        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [pos, speed] = q.front(); q.pop();
                if (pos == target) return steps;

                int newPos = pos + speed;
                int newSpeed = speed * 2;
                string state1 = to_string(newPos) + "_" + to_string(newSpeed);

                if (abs(newPos) <= 2 * target && !visited.count(state1)) {
                    visited.insert(state1);
                    q.push({newPos, newSpeed});
                }

                newSpeed = speed > 0 ? -1 : 1;
                string state2 = to_string(pos) + "_" + to_string(newSpeed);

                if (!visited.count(state2)) {
                    visited.insert(state2);
                    q.push({pos, newSpeed});
                }
            }
            steps++;
        }

        return -1;
    }
};

int main() {
    int target = 6;
    Solution sol;
    cout << "Minimum instructions to reach target: " << sol.racecar(target) << endl;
    return 0;
}
