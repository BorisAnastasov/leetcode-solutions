class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [&](vector<int>& v1, vector<int>& v2) { return v1[0] < v2[0]; });
        int count = 0;
        int last = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (last > intervals[i][0]) {
                last = min(intervals[i][1], last);
                count++;
            } else {
                last = intervals[i][1];
            }
        }
        return count;
    }
};