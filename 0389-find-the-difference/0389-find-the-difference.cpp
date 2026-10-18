class Solution {
public:
    char findTheDifference(string s, string t) {
        for(int i = 0; i< t.size()-1;i++){
            t[i+1] += t[i]-s[i];
        }
        return t[t.size()-1];
    }
};