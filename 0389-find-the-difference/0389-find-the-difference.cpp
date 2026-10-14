class Solution {
public:
    char findTheDifference(string s, string t) {
        int idx1 = 0, idx2 = 0;
        vector<int> temp('z'-'a'+1, 0);
        for(int i = 0; i< s.size();i++){
            temp[s[i]-'a']++;
        }

        for(int i = 0; i < t.size();i++){
            if(temp[t[i]-'a'] == 0){
                return t[i];
            }
            temp[t[i]-'a']--;
        }
        return ' ';
    }
};