class Solution {
public:
    void swap(vector<int>& a, vector<int>& b) {
        vector<int> temp = a;
        a = b;
        b = temp;
    }

    int partition(vector<vector<int>>& arr, int left, int right) {
        int j = left;
        for (int i = left; i < right; i++) {
            if (arr[i][0] <= arr[right][0]) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
        if (j != right) swap(arr[j], arr[right]);
        return j;
    }

    void quick_sort(vector<vector<int>>& arr, int left, int right) {
        if (left >= right)
            return;
        int pi = partition(arr, left, right);

        quick_sort(arr, left, pi-1);
        quick_sort(arr, pi+1, right);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //quick_sort(intervals, 0, intervals.size()-1);
        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b){ return a[0] < b[0]; });
        int count = 0;
        int last = intervals[0][1];
        for(int i = 1;i < intervals.size();i++){
            if(last > intervals[i][0]){
                count++;
                last = min(last, intervals[i][1]);
            }
            else{
                last = intervals[i][1];
            }
        }
        return count;
    }
};