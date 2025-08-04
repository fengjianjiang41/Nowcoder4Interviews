#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 100000+1;
int cost[MAXN];
int dp[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i<n; ++i)cin>>cost[i];
    if (n==1) {
        cout<< cost[0];
        return 0;
    }else if (n == 2){
        cout<< min(cost[0], cost[1]);
        return 0;
    }else{
        memset(dp,0,sizeof(dp));
        dp[n-1]=cost[n-1];
        dp[n-2]=cost[n-2];
        for (int i = n-3; i>=0; --i)dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        cout<<min(dp[0],dp[1])<<endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
