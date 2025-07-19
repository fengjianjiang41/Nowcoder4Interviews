#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class myHeap {
  private:
    vector<T> heap;
    void swap(T& a, T& b) {
        T tmp = a;
        a = b;
        b = tmp;
    }
    void down_adjust(int root) {
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        int largest = root;
        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;
        if (largest != root) {
            swap(heap[largest], heap[root]);
            down_adjust(largest);
        }
    }
    void up_adjust() {
        int last = heap.size() - 1;
        int root = (last - 1) / 2;
        while (root >= 0 && heap[last] > heap[root]) {
            swap(heap[last], heap[root]);
            last = root;
            root = (root - 1) / 2;
        }
    }
  public:
    void push(T val) {
        heap.push_back(val);
        up_adjust();
    }
    T pop() {
        T tmp = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        down_adjust(0);
        return tmp;
    }
    T top() {
        return heap[0];
    }
    bool empty() {
        return heap.size() == 0;
    }
};

int main() {
    int n;
    cin >> n;
    string opt;
    int val;
    myHeap<int> mh;
    for (int i = 0; i < n; i++) {
        cin >> opt;
        if (opt == "push") {
            cin >> val;
            mh.push(val);
        } else if (opt == "pop") {
            if (mh.empty())
                cout << "empty" << endl;
            else
                cout << mh.pop() << endl;
        } else {
            if (mh.empty())
                cout << "empty" << endl;
            else
                cout << mh.top() << endl;
        }
    }
}
// 64 位输出请用 printf("%lld")
