class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pushV int整型vector 
     * @param popV int整型vector 
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        int n = pushV.size();

        stack<int> s;

        int j = 0;

        for (int i = 0; i < n; i++){
            while (j < n && (s.empty() || s.top() != popV[i])) {
                s.push(pushV[j]);
                j++;
            }
            if(s.top() == popV[i]) s.pop();
            else
                return false;
        }
        return true;
    }
};
