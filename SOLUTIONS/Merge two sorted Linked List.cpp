/*
 Using Recursion       
Complexity analysis
Time complexity : O(N + M). Assume that N and M are the length of lists, the time complexity is O(N + M) as only one traversal of linked list is needed.
Space complexity : O(N + M).If the recursive stack space is taken into consideration.
*/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        else if(l1->val <= l2->val)
        {
            l1->next= mergeTwoLists(l1->next,l2);
            return l1;
        }
        
        else
        {
            l2->next= mergeTwoLists(l1,l2->next);
            return l2;
        }        
        
    }
};

/*
 Using Iteration 
Complexity analysis
Time complexity : O(N+M). Assume that N and M are the length of lists, the time complexity is O(N + M).
Space complexity : O(1)
*/

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        
        ListNode fake(0);
        struct ListNode *trav= &fake;
        
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val <= l2->val)
            {
                trav->next=l1;
                trav=l1;
                l1=l1->next;
                
            }
            else
            {
                trav->next=l2;
                trav=l2;
                l2=l2->next;
            }
        }
        if(l1!=NULL)
        {
            trav->next=l1;
        }
        else
        {
            trav->next=l2;
        }
        return fake.next;
    }
};