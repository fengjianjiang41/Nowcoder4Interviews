#include <cctype>
#include <cstdlib>
#include <cstring>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param tokens string字符串vector 
     * @return int整型
     */
    int evalRPN(vector<string>& tokens) {
        // write code here
        stack<int> st;
        for (string & tmp:tokens){
            if(isdigit(tmp[0])||tmp.size()>1){
                int val=strtol(tmp.c_str(), nullptr, 10);
                st.push(val);
            }
            else {
                int v2=st.top();
                st.pop();
                int v1=st.top();
                st.pop();
                int res=cal(v1, v2, tmp);
                st.push(res);
            }
        }
        return st.top();
    }
private:
    int cal(int v1, int v2, string s){
        switch(s[0]){
            case '+':return v1+v2;
            case '-':return v1-v2;
            case '*':return v1*v2;
            case '/':return v1/v2;
        }
        return 0;
    }
};

// 1. for(string &tmp:tokens)
// 这是 C++11 引入的范围 - based for 循环，用于遍历容器（如 vector）中的每个元素：

// 作用：遍历输入的 tokens 向量，依次处理每个字符串 tmp。
// 引用符号 &：通过引用传递避免拷贝，提高效率。
// 2. isdigit(tmp[0])
// 这是 C++ <cctype> 库中的函数，用于判断字符是否为数字：

// 原型：int isdigit(int c)（参数会被隐式转换为 unsigned char）。
// 返回值：
// 若 tmp[0] 是数字字符（0~9），返回非零值（通常为 1）。
// 否则返回 0。
// 用途：判断字符串是否以数字开头（可能是正数或负数）。
// 3. tmp.size() > 1
// 这是字符串长度判断，用于处理负数：

// 为什么需要？：
// 若字符串长度大于 1 且以 - 开头（如 "-5"），说明是负数，需作为操作数处理。
// 若长度为 1 且为 -，则是减法运算符。
// 4. strtol(tmp.c_str(), nullptr, 10)
// 这是 C++ <cstdlib> 库中的字符串转长整型函数：

// 原型：long int strtol(const char* str, char** endptr, int base)。
// 参数：
// tmp.c_str()：将 string 转换为 C 风格字符串（const char*）。
// nullptr：若无需获取未转换部分的指针，可传 nullptr。
// 10：指定进制为十进制。
// 作用：将字符串 tmp 转换为长整型 long int，并截断为 int 压入栈。
// 示例：
// strtol("123", nullptr, 10) → 123
// strtol("-456", nullptr, 10) → -456
