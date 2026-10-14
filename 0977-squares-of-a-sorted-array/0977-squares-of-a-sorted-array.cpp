class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int idx = 0;
        int neg = -1, pos = 0;
        vector<int> result(nums.size());
        if(nums.size() ==0 ) return {};
        while(idx < nums.size() && nums[idx] < 0){
            neg++;
            idx++;
        }
        pos = idx;
        idx = 0;

        while(neg >= 0 && pos < nums.size()){
            if(-nums[neg] > nums[pos]){
                result[idx] = nums[pos]*nums[pos];
                pos++;
            }
            else{
                result[idx] = nums[neg]*nums[neg];
                neg--;
            }
            idx++;
        }

        while(neg >= 0){
            result[idx++] = nums[neg]* nums[neg];
            neg--;
        }

        while(pos < nums.size()){
            result[idx++] = nums[pos]* nums[pos];
            pos++;
        }

        return result;
    }
};