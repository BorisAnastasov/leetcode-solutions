class Solution {
public:
    int getSum(vector<int>& nums, int left, int right){
        set<int> s;
        for(int i = left;i <= right;i++){
            s.insert(nums[i]);
        }
        return s.size()*s.size();
    }

    int sumCounts(vector<int>& nums) {
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
            for(int j = i;j < nums.size();j++){
                sum+=getSum(nums, i,j);
            }
        }
        return sum;
    }
};