#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Employee class as given in the problem
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;

    Employee(int _id, int _importance, vector<int> _subs)
        : id(_id), importance(_importance), subordinates(_subs) {}
};

class Solution {
public:
    int getImportance(vector<Employee*>& employees, int id) {
        unordered_map<int, Employee*> map;
        for (auto emp : employees) {
            map[emp->id] = emp;
        }
        return dfs(map, id);
    }

private:
    int dfs(unordered_map<int, Employee*>& map, int id) {
        Employee* emp = map[id];
        int total = emp->importance;
        for (int subId : emp->subordinates) {
            total += dfs(map, subId);
        }
        return total;
    }
};

int main() {
    // Sample data to test the function
    Employee* e1 = new Employee(1, 5, {2, 3});
    Employee* e2 = new Employee(2, 3, {});
    Employee* e3 = new Employee(3, 3, {});

    vector<Employee*> employees = {e1, e2, e3};

    Solution sol;
    int result = sol.getImportance(employees, 1);
    cout << "Total importance for employee 1: " << result << endl; // Expected: 11

    // Cleanup allocated memory
    delete e1;
    delete e2;
    delete e3;

    return 0;
}
