class Solution {
public:
    char findTheDifference(string s, string t) {
        int idx1 = 0, idx2 = 0;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        while (idx1 < s.size() && idx2 < t.size()) {
            if (s[idx1] != t[idx2]) {
                return t[idx2];
            }
            idx1++;
            idx2++;
        }
        return t[t.size() - 1];
    }
};