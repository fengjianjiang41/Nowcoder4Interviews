#include<iostream>
using namespace std;
struct queue
{
    int q[100001];
    int head;
    int rear;
    queue()
    {
        head = 0;
        rear = 0;
    }
};
int len; // 循环队列可使用的总大小
void push(queue& que, int num) // 模拟入队的函数
{
    if(que.head == (que.rear + 1) % len) // 在循环中，当队头指针处于队尾指针后一个位置时，表示队满
    {
        cout<<"full"<<endl;
        return ;
    }
    que.q[que.rear] = num;
    que.rear = (que.rear + 1) % len; // 移动指针需模len
}
int front(queue& que) // 模拟查看队头元素的函数
{
    return que.q[que.head];
}
int pop(queue& que) // 模拟出队的函数
{
    int tNum = front(que);
    que.head = (que.head + 1) % len; // 移动指针需模len
    return tNum;
}
bool isEmpty(queue& que) // 判断队列是否为空的函数
{
    return que.head == que.rear;
}
int main()
{
    int n;
    cin>>len>>n;
    len++; // 因为判断队满的条件是队头处于队尾的后一个位置，因此需要多申请一个空位置
    queue que;
    for(int i = 0; i < n; i++)
    {
        string op;
        cin>>op;
        if(op == "push")
        {
            int num;
            cin>>num;
            push(que, num);
        }
        else if(isEmpty(que)) // 在队列进行pop和front操作前需要先判断队列此时是否为空
        {
            cout<<"empty"<<endl;
        }
        else if(op == "pop")
        {
            cout<<pop(que)<<endl;
        }
        else if(op == "front")
        {
            cout<<front(que)<<endl;
        }
    }
    return 0;
}
