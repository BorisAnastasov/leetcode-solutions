class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> list;
        string s;
        auto f = [&](auto&& self, int o, int c) -> void {
            if(o == 0 && c == 0){
                list.push_back(s);
                return;
            }

            if(o>0){
                s.push_back('(');
                self(self, o-1, c);
                s.pop_back();
            }

            if(c>o){
                s.push_back(')');
                self(self, o, c-1);
                s.pop_back();
            }
        };
        f(f, n,n);
        return list;
    }
};