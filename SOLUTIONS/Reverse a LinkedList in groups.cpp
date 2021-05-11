/*

METHOD 1 :  
Complexity Analysis
Time Complexity: O(n) where n is the number of nodes in the given list.
Space Complexity: O(1).
*/
class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    {
        node *curr=head;
        node *end=NULL;
        while(curr!=NULL)
        {
            int t=k;
            node *start=curr;
            node *prev=NULL;
            while(curr!=NULL && t--)
            {
                node *next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            
            if(end!=NULL)
            {
                end->next=prev;
            }
            else
            {
                head=prev;
            }
            end=start;
        }
        return head;
    }
};