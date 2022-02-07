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
 // 更好的解法是使用双指针，先遍历链表使两个指针相隔固定的长度n，然后一起移动到最后
class Solution {
    ListNode* node[30];
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;
        while (head){
            node[i++] = head;
            head = head->next;
        }
        int pos = i - n;
        if (!pos){
            return node[0]->next;
        }
        node[pos-1]->next = node[pos]->next;
        return node[0];        
    }
};