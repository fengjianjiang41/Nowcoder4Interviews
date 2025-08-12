/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        ListNode* res = new ListNode(-1);
        res->next = head;

        ListNode* pre = res;
        ListNode* cur = head;

        for (int i = 1; i<m; i++){
            pre = cur;
            cur = cur->next;
        }
        ListNode* temp = new ListNode(0);
        for (int i = m; i<n; i++){
            temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return res->next;
    }
};
