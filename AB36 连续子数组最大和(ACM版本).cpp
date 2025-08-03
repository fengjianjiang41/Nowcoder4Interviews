
// #include<bits/stdc++.h>
// using namespace std;
// long long a[101010],dp[101010];
// int main(){
//     int n,i;
//     cin>>n;
//     for(i=1;i<=n;i++)cin>>a[i];
//     dp[0]=-1e9;
//     long long res=-1e9;
//     for(i=1;i<=n;i++){
//         dp[i]=max(dp[i-1]+a[i],a[i]);
//         res=max(res,dp[i]);
//     }
//     cout<<res;

// }


#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[101010];
ll a[101010];
int main() {
    int n, i;
    cin >> n;
    int jud = 0;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= 0)jud = 1;
    }
    if (!jud) {
        ll res = -1e9;
        for (i = 1; i <= n; i++)res = max(res, a[i]);
        cout << res;
        return 0;
    }
    ll res = a[1], sum = max(0LL, a[1]);
    for (i = 2; i <= n; i++) {
        sum = max(0LL, sum + a[i]);
        res = max(res, sum);
    }
    cout << res;
}
