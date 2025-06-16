#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[room] = true;
        for (int key : rooms[room]) {
            if (!visited[key]) dfs(key, rooms, visited);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(0, rooms, visited);
        return all_of(visited.begin(), visited.end(), [](bool v) { return v; });
    }
};

