class Solution {
public:
    //深度优先遍历与i，j相邻的所有1
    void dfs(vector<vector<char>>& grid, int i, int j) { 
        int n = grid.size();
        int m = grid[0].size();
        //置为0
        grid[i][j] = '0'; 
        //后续四个方向遍历
        if(i - 1 >= 0 && grid[i - 1][j] == '1') 
            dfs(grid, i - 1, j);
        if(i + 1 < n && grid[i + 1][j] == '1') 
            dfs(grid, i + 1,j);
        if(j - 1 >= 0 && grid[i][j - 1] == '1') 
            dfs(grid, i, j - 1);
        if(j + 1 < m && grid[i][j + 1] == '1') 
            dfs(grid, i, j + 1);
    }
    int solve(vector<vector<char> >& grid) {
        int n = grid.size();
        //空矩阵的情况
        if (n == 0)  
            return 0;
        int m = grid[0].size();
        //记录岛屿数
        int count = 0; 
        //遍历矩阵
        for(int i = 0; i < n; i++){ 
            for(int j = 0; j < m; j++){
                //遍历到1的情况
                if(grid[i][j] == '1'){ 
                    //计数
                    count++; 
                    //将与这个1相邻的所有1置为0
                    dfs(grid, i, j); 
                }
            }
        }
        return count;
    }
};
