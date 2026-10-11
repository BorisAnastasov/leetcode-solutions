class Solution {
public:
    bool isValid(int left, int right, int count, string& s) {
        while (left < right) {
            if (s[left] != s[right]) {
                if (count == 1)
                    return false;
                if(right-left == 1) return true;
                bool res1 = false, res2 = false;
                if(s[left+1] == s[right]){ 
                    res1 = isValid(left + 2, right - 1, count + 1, s);
                }
                if(s[left] == s[right-1]){ 
                    res2 = isValid(left + 1, right - 2, count + 1, s);
                }
                return res1 || res2;
            }
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        int count = 0;
        
        return isValid(left, right, count,s);
    }
};