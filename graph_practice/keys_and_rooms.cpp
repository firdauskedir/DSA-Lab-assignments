#include <iostream>
#include <vector>
using namespace std;

void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited) {
    visited[room] = true;
    for (int key : rooms[room]) {
        if (!visited[key]) {
            dfs(key, rooms, visited);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);
    dfs(0, rooms, visited);

    for (bool v : visited) {
        if (!v) return false;
    }
    return true;
}

int main() {
    vector<vector<int>> rooms = {
        {1}, {2}, {3}, {}
    };

    cout << (canVisitAllRooms(rooms) ? "All rooms can be visited." : "Some rooms are not reachable.") << endl;
    return 0;
}

