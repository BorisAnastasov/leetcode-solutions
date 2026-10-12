class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int read = 0;
        int write = 0;

        for(;read<nums.size();read++){
            if(nums[read] != 0){
                nums[write++] = nums[read];
            }
        }

        while(write < nums.size()){
            nums[write++] = 0;
        }
    }
};