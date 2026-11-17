class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        queue<int> q;
        int curr = 0;
        int maxSum = 0;
        for(int i = 0; i < k;i++){
            curr+=nums[i];
            q.push(nums[i]);
        }
        maxSum = curr;
        for(int i = k;i < nums.size();i++){
            curr-=q.front();
            q.pop();
            curr+=nums[i];
            q.push(nums[i]);
            if(curr > maxSum) maxSum = curr;
        }

        return ((double)maxSum)/k;
    }
};