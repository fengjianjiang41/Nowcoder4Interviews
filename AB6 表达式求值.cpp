class Solution {
  public:
    vector<int> function(string s, int index) {
        stack<int> stack;
        int num = 0;
        char op = '+';
        int i;
        for (i = index; i < s.length(); i++) {
            //数字转换成int数字
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
                if (i != s.length() - 1)
                    continue;
            }
            //碰到'('时，把整个括号内的当成一个数字处理
            if (s[i] == '(') {
                //递归处理括号
                vector<int> res = function(s, i + 1);
                num = res[0];
                i = res[1];
                if (i != s.length() - 1)
                    continue;
            }
            switch (op) {
                //加减号先入栈
                case '+':
                    stack.push(num);
                    break;
                case '-':
                    //相反数
                    stack.push(-num);
                    break;
                //优先计算乘号
                case '*':
                    int temp = stack.top();
                    stack.pop();
                    stack.push(temp * num);
                    break;
            }
            num = 0;
            //右括号结束递归
            if (s[i] == ')')
                break;
            else
                op = s[i];
        }
        int sum = 0;
        //栈中元素相加
        while (!stack.empty()) {
            sum += stack.top();
            stack.pop();
        }
        return vector<int> {sum, i};
    }

    int solve(string s) {
        return function(s, 0)[0];
    }
};
