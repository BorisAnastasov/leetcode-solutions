class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stackS;
        stack<char> stackT;
        for(int i = 0;i< s.size();i++){
            if(s[i] == '#'){
                if(!stackS.empty()) stackS.pop();
            }
            else{
                stackS.push(s[i]);
            }
        }
        for(int i = 0;i< t.size();i++){
            if(t[i] == '#'){
                if(!stackT.empty()) stackT.pop();
            }
            else{
                stackT.push(t[i]);
            }
        }
        while(!stackS.empty() && !stackT.empty()){
            if(stackS.top() != stackT.top()) return false;
            stackS.pop();
            stackT.pop();
        }
        return stackS.empty() && stackT.empty();
    }
};