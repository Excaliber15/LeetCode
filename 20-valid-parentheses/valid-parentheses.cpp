class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                // open brackets
                st.push(ch);
            }
            else{
                // closed brackets
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
                        // invalid case
                        return false;
                    }
                }
                else{
                    // stack is empty
                    return false;
                }
            }
        }
        if(st.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
};