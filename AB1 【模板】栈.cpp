#include <iostream>
#include <string>
using namespace std;

class stack {
    private:
        int q[100000];
        int top_idx = -1;
    public:
        void push(int x){
            top_idx++;
            q[top_idx]=x;
        }
        void pop(){
            if (top_idx >= 0){
                cout << q[top_idx] << endl;
                top_idx--;
            }
            else {
                cout << "error" << endl;
            }
        }
        void top(){
            if (top_idx >= 0){
                cout << q[top_idx] << endl;
            }
            else {
                cout << "error" << endl;
            }
        }
};

int main() {
    stack s;
    int n;
    cin >> n;
    for (int i = 0; i<n; i++){
        string op;
        cin >> op;
        if (op == "push"){
            int x;
            cin >> x;
            s.push(x);
        }
        else if (op == "pop"){
            s.pop();
        }
        else {
            s.top();
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
