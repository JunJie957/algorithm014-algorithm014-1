/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // 某个链表为空 或 全为空
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        // 确定头结点
        ListNode* newHead = nullptr;
        if (l1->val <= l2->val) {
            newHead = l1;
            l1 = l1->next;
        }
        else {
            newHead = l2;
            l2 = l2->next;
        }

        // 将之后的节点按照值的大小，依次串联起来
        ListNode* cur = newHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        // 将未遍历完的节点串联
        l1 != nullptr ? cur->next = l1 : cur->next = l2;

        return newHead;
    }
};
