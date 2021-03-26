struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode *cur_node = head->next;
        ListNode *pre_node = head;
        
        while (cur_node != nullptr){
            if (cur_node->val == pre_node->val){
                pre_node->next = cur_node->next;
                delete cur_node;
                cur_node = pre_node->next;
            }else{
                pre_node = cur_node;
                cur_node = cur_node->next;
            }
        }
        return head;
    }
};