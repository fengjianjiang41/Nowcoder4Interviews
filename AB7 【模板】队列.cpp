#include <iostream>
#include <string>
using namespace std;

class queue {
    private:
        int s[100000];
        int front_idx = 0;
        int tail_idx = -1;
    public:
        void push(int x){
            tail_idx++;
            s[tail_idx] = x;
        }
        void pop(){
            if (front_idx <= tail_idx){
                cout << s[front_idx] << endl;
                front_idx++;
            }
            else{
                cout << "error" << endl;
            }
        }
        void front(){
            if (front_idx <= tail_idx){
                cout << s[front_idx] << endl;
            }
            else{
                cout << "error" << endl;
            }
        }
};

int main() {
    struct queue q;
    int n;
    cin >> n;
    for (int i = 0; i<n; i++){
        string op;
        cin >> op;
        if (op == "push"){
            int x;
            cin >> x;
            q.push(x);
        }
        else if (op == "pop"){
            q.pop();
        }
        else {
            q.front();
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
