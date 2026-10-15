class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> arr(128);
        for (int i = 0; i < s.size(); i++) {
            arr[s[i]].second++;
            arr[s[i]].first = s[i];
        }
        sort(arr.begin(), arr.end(),
             [](const auto& a, const auto& b) { return a.second > b.second; });

        string str;

        for (int i = 0; i < arr.size(); i++) {
            while (arr[i].second-- > 0) {
                str.push_back(arr[i].first);
            }
        }

        return str;
    }
};