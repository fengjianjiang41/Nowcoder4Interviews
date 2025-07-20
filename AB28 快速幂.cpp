#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    long long a, b, p;
    for (int i = 0; i < n; i++) {
        long long sum = 1;
        scanf("%lld %lld %lld", &a, &b, &p);
        while (b > 0) {
            if (b%2==1) 
            {
                sum = sum * a % p;
            }
            b = b >> 1;
            a = a * a % p;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
