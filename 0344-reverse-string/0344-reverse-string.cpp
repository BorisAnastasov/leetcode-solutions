class Solution {
public:
    void swap(char& a, char& b){
        char temp = a;
        a = b;
        b = temp;
    }

    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            swap(s[left++], s[right--]);
        }
    }
};