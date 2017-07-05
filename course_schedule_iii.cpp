class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int, vector<int>, less<int>> pq;
        int start = 0;
        sort(courses.begin(), courses.end(), [&](vector<int> a, vector<int> b) { return a[1] < b[1];});
        for (const auto& course : courses) {
            start += course[0];
            pq.push(course[0]);
            while (start > course[1]) { // greedy
                auto curr = pq.top();
                pq.pop();
                start -= curr;
            }
        }
        return pq.size();
    }
};
