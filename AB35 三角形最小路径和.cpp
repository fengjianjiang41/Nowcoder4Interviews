#include <algorithm>
#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param triangle int整型vector<vector<>> 
     * @return int整型
     */
    int minTrace(vector<vector<int> >& triangle) {
        // write code here
        int depth = triangle.size();
        vector<vector<int>> dp(depth, vector<int>(depth, 0));

        for (int i = depth-1; i>=0; i--){
            for (int j = 0; j<=i; j++){
                if (i == depth - 1) dp[i][j] = triangle[i][j];
                else dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
};
