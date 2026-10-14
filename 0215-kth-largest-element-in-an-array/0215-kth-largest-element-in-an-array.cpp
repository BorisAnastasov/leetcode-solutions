class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right){
        int n1 = mid-left+1;
        int n2 = right-mid;

        vector<int> L(n1);
        vector<int> R(n2);

        for(int i = 0;i< n1;i++){
            L[i] = nums[left+i];
        }
        for(int i = 0;i< n2;i++){
            R[i] = nums[mid+i+1];
        }
        int idx1 = 0, idx2 = 0, idx = left;
        while(idx1 < n1 && idx2 < n2){
            if(L[idx1] <= R[idx2]){
                nums[idx++] = L[idx1++];
            }
            else{
                nums[idx++] = R[idx2++];
            }
        }

        while(idx1 < n1){
            nums[idx++] = L[idx1++];
        }
        while(idx2 < n2){
            nums[idx++] = R[idx2++];
        }
    }
    void merge_sort(vector<int>& nums, int left, int right){
        if(left >= right) return ;
        int mid = left + (right-left)/2;

        merge_sort(nums, left, mid);
        merge_sort(nums, mid+1, right);
        merge(nums, left,mid,right);
    }

    int findKthLargest(vector<int>& nums, int k) {
        //merge_sort(nums, 0 , nums.size()-1);
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};