class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> pairs(nums.size());
        for(int i = 0;i< nums.size();i++){
            pairs[i] = {nums[i], i};
        }
        int n = nums.size();
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n-i-1;j++){
                if(pairs[j].first > pairs[j+1].first) swap(pairs[j], pairs[j+1]);
            }
        }
        int left = 0;
        int right = n-1;
        while(left < right){
            int sum = pairs[left].first + pairs[right].first;
            if(sum < target){
                left++;
            }
            else if(sum > target){
                right--;
            }
            else{
                break;
            }
        }
        return {pairs[left].second, pairs[right].second};
    }
};