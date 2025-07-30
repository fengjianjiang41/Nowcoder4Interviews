#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack <char> st;

    for (int i = 0; i < s.length(); i++){
        if (!st.empty() && st.top() == s[i]) st.pop();    
        else st.push(s[i]);
    }

    string result;
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    if (result.empty()) cout << 0;
    else cout << result;
    
    return 0;
}
// 64 位输出请用 printf("%lld")
