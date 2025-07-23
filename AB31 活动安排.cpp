#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    /* 详细解析：
    ios::sync_with_stdio(0)

    默认情况下，C++的cin/cout与C的stdio是同步的，以保证混合使用cin/cout和scanf/printf时顺序一致

    关闭同步（设为0）可以使cin/cout速度大幅提升（接近scanf/printf速度）

    副作用：关闭后不能与C的stdio函数混用

    cin.tie(0)

    默认情况下，cin和cout是绑定的（tied），即在每次cin操作前会自动刷新cout缓冲区

    解除绑定（设为0）可以进一步提高速度

    副作用：需要手动控制输出缓冲（如使用endl或flush）

    cout.tie(0)

    对cout影响较小，主要是为了完整性

    某些实现中可能有额外优化

    适用场景：

    需要处理大量输入输出时（如算法竞赛）

    不需要混合使用C++和C的IO函数时

    性能影响：

    关闭同步后，cin/cout速度可提升2-5倍

    对于输入规模>10^5的情况，效果显著 */
    int n;
    cin >> n;
    vector<array<int, 2>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i][0] >> v[i][1];
    sort(v.begin(), v.end(), [](const array<int, 2>& a, const array<int, 2>& b) {
        return a[1] < b[1];
    });
    /* 组成部分：
    排序范围：

    v.begin(), v.end()：对整个vector排序

    Lambda比较函数：

    [](const array<int,2>& a, const array<int, 2>& b) {...}：匿名函数

    等价写法：
    bool compare(const array<int,2>& a, const array<int, 2>& b) {
        return a[1] < b[1];
    }
    sort(v.begin(), v.end(), compare);

    参数：两个array<int,2>元素的常量引用

    返回值：bool类型，表示a是否应该排在b前面

    比较逻辑：

    return a[1] < b[1];：按每个元素的第二个值（结束时间）升序排序

    关键点：
    排序稳定性：

    std::sort不是稳定排序（等值元素可能改变相对顺序）

    如需稳定排序应使用std::stable_sort

    Lambda函数优势：

    就地定义，代码更紧凑

    可以直接捕获外部变量（本例中未使用）

    性能考虑：

    比较函数应尽可能简单高效

    使用引用避免拷贝开销

    排序原理：

    使用内省排序（IntroSort）

    平均时间复杂度：O(n log n)

    活动选择问题中的意义：
    这种排序方式确保了：

    总是优先考虑结束时间最早的活动

    为后续活动留下尽可能多的时间

    是贪心算法正确性的关键保证 */
    int endTime = v[0][1], cnt = 1;
    for (int i = 1; i < n; i++) {
        if (v[i][0] >= endTime) {
            endTime = v[i][1];
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
// 64 位输出请用 printf("%lld")
