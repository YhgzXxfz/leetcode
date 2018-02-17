/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for (auto e : employees) {
            mp[e->id] = e;
        }
        
        int result = 0;
        queue<int> q;
        q.push(id);
        
        while (!q.empty()) {
            auto curr_id = q.front();
            q.pop();
            
            auto curr = mp[curr_id];
            result += curr->importance;
            for (auto sub : curr->subordinates) {
                q.push(sub);
            }
        }
        return result;
    }
};
