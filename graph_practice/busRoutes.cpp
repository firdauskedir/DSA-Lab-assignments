#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); ++i)
            for (int stop : routes[i])
                stopToRoutes[stop].push_back(i);

        queue<int> q;
        unordered_set<int> visitedStops;
        unordered_set<int> visitedRoutes;

        q.push(source);
        visitedStops.insert(source);
        int buses = 0;

        while (!q.empty()) {
            int sz = q.size();
            ++buses;
            while (sz--) {
                int stop = q.front(); q.pop();
                for (int route : stopToRoutes[stop]) {
                    if (visitedRoutes.count(route)) continue;
                    visitedRoutes.insert(route);
                    for (int nextStop : routes[route]) {
                        if (nextStop == target) return buses;
                        if (!visitedStops.count(nextStop)) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
    int source = 1, target = 6;
    Solution sol;
    cout << "Minimum buses to reach destination: " << sol.numBusesToDestination(routes, source, target) << endl;
    return 0;
}
