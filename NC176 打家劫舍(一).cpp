class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    /*
    1 2 3 4 5 6
    start at 0 or 1

    */
    int rob(vector<int>& nums) {
        // write code here
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }

        vector<unsigned int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2] + dp[0];


        for (unsigned int i = 3; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
        }

        unsigned int maxMoney = 0;
        for (unsigned int i = dp.size() - 2; i < dp.size(); ++i) {
            if (maxMoney < dp[i]) {
                maxMoney = dp[i];
            }
        }


        return maxMoney;

    }
};

const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}
();
