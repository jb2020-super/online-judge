// 61. 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;
        int len = 1;        
        ListNode* tail = head;        
        while (tail->next){            
            len++;
            tail = tail->next;
        }
        int inc = len - k % len;
        if (inc == len){
            return head;
        }
        int i = 0;
        ListNode* new_tail = head;
        while (i < inc - 1) {
            new_tail = new_tail->next;
            i++;
        }
        tail->next = head;
        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr;
        return new_head;
    }
};