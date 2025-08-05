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
     * @param val int整型 
     * @return ListNode类
     */
    ListNode* deleteNode(ListNode* head, int val) {
        // write code here32f
        ListNode* cur = head;
        if (!cur) return nullptr;
        if (cur->val==val) return cur->next;

        while (cur->next) {
            if (cur->next->val==val)cur->next=cur->next->next;
            cur = cur->next;        
        }

        return head;
    }
};
