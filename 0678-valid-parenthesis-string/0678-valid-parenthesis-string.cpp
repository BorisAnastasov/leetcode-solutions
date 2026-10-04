class Solution {
public:
    bool checkValidString(string s) {
        stack<char> stack;
        auto dfs = [&s](auto&& self, int start, std::stack<char> stack)->bool{
            for(int i = start;i < s.size();i++){
                if(s[i] == '(') stack.push(s[i]);
                else if(s[i] == ')'){
                    if(stack.empty()) {
                        return false;
                    }

                    if(stack.top() == '('){
                        stack.pop();
                    }
                    else{
                        stack.push(s[i]);
                    }
                }
                else{//s[i] = *
                    s[i] = '(';
                    bool result = self(self, i, stack);
                    
                    s[i] = ')';
                    result |= self(self,i, stack);

                    result |= self(self, i+1, stack);

                    return result;
                }
            }
            return stack.empty();
        };
        return dfs(dfs, 0, stack);
    }
};