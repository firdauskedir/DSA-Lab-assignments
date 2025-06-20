#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // parent map: variable -> (parent variable, ratio to parent)
    unordered_map<string, pair<string, double>> parent;

    pair<string, double> find(const string& x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = {x, 1.0};
        }

        if (parent[x].first != x) {
            auto p = find(parent[x].first);
            parent[x].first = p.first;
            parent[x].second *= p.second;
        }
        return parent[x];
    }

    void unite(const string& x, const string& y, double val) {
        auto px = find(x);
        auto py = find(y);
        if (px.first != py.first) {
            parent[px.first].first = py.first;
            parent[px.first].second = val * parent[y].second / parent[x].second;
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (size_t i = 0; i < equations.size(); i++) {
            unite(equations[i][0], equations[i][1], values[i]);
        }

        vector<double> ans;
        for (auto& q : queries) {
            string x = q[0];
            string y = q[1];
            if (parent.find(x) == parent.end() || parent.find(y) == parent.end()) {
                ans.push_back(-1.0);
                continue;
            }
            auto px = find(x);
            auto py = find(y);
            if (px.first != py.first) {
                ans.push_back(-1.0);
            } else {
                ans.push_back(parent[x].second / parent[y].second);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example equations: a / b = 2.0, b / c = 3.0
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    vector<double> results = sol.calcEquation(equations, values, queries);

    cout << "Evaluate Division results:" << endl;
    for (double res : results) {
        cout << res << endl;
    }
    // Expected output:
    // 6.0
    // 0.5
    // -1.0
    // 1.0
    // -1.0

    return 0;
}