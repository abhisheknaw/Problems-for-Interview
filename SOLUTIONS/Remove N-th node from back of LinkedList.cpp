/*
Method 1: Single Pass Algorithm 
Complexity Analysis
Time complexity : O(L).
The algorithm makes one traversal of the list of L nodes. Therefore time complexity is O(L).
Space complexity : O(1).
We only used constant extra space.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        struct ListNode *slow=head;
        struct ListNode *fast=head;
        for(int i=0;i<n;i++)
        {
            if(fast->next==NULL)
            {
                if(i==n-1)
                   head=head->next;       
                return head;
            }
            fast=fast->next;
        }
        while(fast->next != NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        
        return head;
    }
};
/*
Method 1: Single Pass Algorithm using dummy node.
Complexity Analysis
Time complexity : O(L).
The algorithm makes one traversal of the list of L nodes. Therefore time complexity is O(L).
Space complexity : O(1).
We only used constant extra space.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        struct ListNode *dummy= new ListNode();
        dummy->next=head;
        ListNode *slow=dummy;
        ListNode *fast=dummy;
        
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        
        while(fast->next != NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return dummy->next;
        
        
        
    }
};