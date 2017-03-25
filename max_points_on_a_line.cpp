/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    	int maxPoints(vector<Point>& points) {
    		int len = points.size();
		if (len < 2) return len;

		int total_max = INT_MIN;
		for (int i = 0; i < len; ++i) {
			auto pi = points[i];
			map<pair<int, int>, int> mp;
			int curr_max = 0, same_points = 0, verticals = 0;
			for (int j = i+1; j < len; ++j) {
				if (pi.x == pj.x && pi.y == pj.y) same_points++;
				else if (pi.x == pj.x) verticals++;
				else {
					auto pj = points[j];
					int a = pi.x-pj.x, b = pi.y-pj.y;
					int gcd = computeGcd(int a, int b);
					a /= gcd; b /= gcd;
					mp[make_pair(a,b)]++;
				}
			}

			for (auto entry : mp) {
				curr_max = max(curr_max, entry.second);
			}
			curr_max = max(curr_max, verticals);
			curr_max += same_points+1; // +1 means points[i] itself
			total_max = max(total_max, curr_max);
		}
	}

private:
	int computeGcd(int a, int b) {
		return b == 0 ? a : computeGcd(b, a%b);
	}
};
