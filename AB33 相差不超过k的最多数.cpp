#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    int a[n];
    for (int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int l=0,r=1;
    int max=1;
    while (r<n) {
        if(a[r]-a[l]<=k){
            if(max<r-l+1)max=r-l+1;
            r++;
        }
        else l++;
    }
    cout<<max;
}
// 64 位输出请用 printf("%lld")
