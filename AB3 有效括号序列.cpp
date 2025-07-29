class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here
        stack<char> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(!st.empty() && ((s[i] == ']' && st.top()=='[') || (s[i] == '}' && st.top()=='{')|| (s[i] == ')' && st.top()=='(')))
                st.pop();
            else
                st.push(s[i]);
        }
        return st.empty();
    }
};
