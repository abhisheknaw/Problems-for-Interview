/*
tC= O(1);
sc= O(1);
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        node->val=node->next->val;
        node->next=node->next->next;
    }
};