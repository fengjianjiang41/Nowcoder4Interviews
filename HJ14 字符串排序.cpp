#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string a, string b) {
    //return a.compare(b)<0;   //升序
    return a < b; //两个效果一样
}
int main() {
    int n;
    cin >> n;
    string str[1001];
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sort(str, str + n, cmp); //自定义的cmp函数
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }
    return 0;
}
