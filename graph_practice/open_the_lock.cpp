#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

string rotate(string s, int i, int dir) {
    s[i] = (s[i] - '0' + dir + 10) % 10 + '0';
    return s;
}

int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    unordered_set<string> visited;

    if (dead.count("0000")) return -1;

    queue<pair<string, int>> q;
    q.push({"0000", 0});
    visited.insert("0000");

    while (!q.empty()) {
        auto [code, steps] = q.front(); q.pop();
        if (code == target) return steps;

        for (int i = 0; i < 4; ++i) {
            string up = rotate(code, i, 1);
            string down = rotate(code, i, -1);

            if (!dead.count(up) && !visited.count(up)) {
                q.push({up, steps + 1});
                visited.insert(up);
            }

            if (!dead.count(down) && !visited.count(down)) {
                q.push({down, steps + 1});
                visited.insert(down);
            }
        }
    }

    return -1;
}

int main() {
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";

    int moves = openLock(deadends, target);
    if (moves == -1)
        cout << "Cannot reach the target." << endl;
    else
        cout << "Minimum moves: " << moves << endl;

    return 0;
}
