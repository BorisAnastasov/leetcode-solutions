class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1);
        vector<int> R(n2);

        for (int i = 0; i < n1; i++) {
            L[i] = arr[left + i];
        }

        for (int i = 0; i < n2; i++) {
            R[i] = arr[mid + i + 1];
        }

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        while (i < n1) {
            arr[k++] = L[i++];
        }
        while (j < n2) {
            arr[k++] = R[j++];
        }
    }

    void merge_sort(vector<int>& arr, int left, int right) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return false;
        int left = 0;
        int right = nums.size() - 1;

        merge_sort(nums, left, right);
        int el = nums[0];
        for (int i = 1; i < right; i++) {
            if (el == nums[i]) {
                return true;
            } else {
                el = nums[i];
            }
        }
        if (el == nums[right]) {
            return true;
        }
        return false;
    }
};