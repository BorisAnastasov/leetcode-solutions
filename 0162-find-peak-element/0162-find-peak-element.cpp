class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) {return 0;}
            else return 1;
        }

        int l = 1, r = nums.size() - 2;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {return mid;}
            if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {l = mid + 1;}
            else {r = mid - 1;}
         }

        if (nums[0] > nums[1]) return 0;
        return nums.size() - 1;
    }
};