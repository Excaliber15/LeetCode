class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                // opening brackets
                st.push(ch);
            }
            else{
                // closing brackets
                if(!st.empty()){
                    if(ch==')' && st.top()=='('){
                        st.pop();
                    }
                    else if(ch=='}' && st.top()=='{'){
                        st.pop();
                    }
                    else if(ch==']' && st.top()=='['){
                        st.pop();
                    }
                    else{
                        // no match
                        return false;
                    }
                }
                else{
                    // stack is empty
                    return false;
                }
            }
        }
        if(st.size()==0) return true;
        else return false;
    }
};