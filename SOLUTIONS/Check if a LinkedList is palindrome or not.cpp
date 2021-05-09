/*
METHOD 1 : By reversing list from mid
Complexity Analysis
Time Complexity: O(N/2)+O(N/2)+O(N/2), where N is the number of nodes in the given list.
Space Complexity: O(1)
*/


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return true;
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while( fast->next!=NULL && fast->next->next!=NULL ) //find middle of the linked list
        {
            slow=slow->next;
            fast=(fast->next)->next;                
        }
        
        slow->next=reverse(slow->next);   //reverse the linked list from the next of slow
        slow=slow->next;
        
        while(slow!=NULL)
        {
            if(head->val!=slow->val)
                return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev,*next;
        prev=NULL;
        next=NULL;
        while(head!=NULL)
        {
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;     
        }
        
        return prev;    
    }
};