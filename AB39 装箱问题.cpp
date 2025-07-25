#include <iostream>
using namespace std;

int v, n;
int a[40];
int dp[20100];
 
int main() {
    cin >> v >> n;  // 读取背包容量v和物品数量n
    for(int i = 1; i <= n; i++) cin >> a[i];  // 读取每个物品的体积
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {  // 遍历每个物品
        for(int j = v; j >= a[i]; j--) {  // 从大到小遍历背包容量
            dp[j] = dp[j] || dp[j - a[i]];  // 更新状态
        }
    }
    for(int j = v; j >= 0; j--) {  // 从最大容量开始向下查找
    if(dp[j]) {  // 找到第一个可以恰好装满的容量j
        cout << v - j;  // 输出剩余空间（v - j）
        break;
        }
    }
}
// 64 位输出请用 printf("%lld")
