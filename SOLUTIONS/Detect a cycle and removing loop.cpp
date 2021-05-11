/*
METHOD 1 : Floyd’s Cycle-Finding Algorithm   
Time Complexity: O(n) Only one traversal of the loop is needed.
Space Complexity: O(1).
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head==NULL || head->next==NULL)
            return false;
        
        ListNode *fast=head;
        ListNode *slow=head;
        
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return true;

        }
        
        return false;
    }
};

/*
METHOD 2 : Hashing  
Complexity Analysis
Time Complexity: O(n) Only one traversal of the loop is needed.
Space Complexity: O(1) n is the space required to store the value in hashmap.
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode*>mp;
        
        while(head)
        {
            if(mp.find(head) != mp.end())
            {
                return head;
            }
            
            else
            {
                mp.insert(head);
            }
            head=head->next;
        }
        return NULL;
        
    }
};