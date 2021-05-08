


/*
tc : O(3n)
sc : O(1)
*/

class Solution
{
    public:
    
    Node* reverse (Node *head)
    {
        Node* prev,*current,*next;
        prev=NULL;
        current =head;
        while(current!=NULL)
        {
            next=current->next;
            current->next =prev;
            prev=current;
            current =next;
        }
        head=prev;
        return head;
    }
    Node* addOne(Node *head) 
    {
        head=reverse(head);
        Node *curr=head;
        bool check=true;
        while(curr != NULL && check==true)
        {
            if(curr->next==NULL && curr->data==9)
            {
                curr->data=1;
                Node *temp= new Node(0);
                temp->next=head;
                head=temp;
                curr =curr->next;
            }
            else if(curr->data == 9)
            {
                curr->data=0;
                curr=curr->next;
            }
            else
            {
                curr->data=curr->data+1;
                curr=curr->next;
                check=false;
            }
            
        }
        head=reverse(head);
        return head;
    }
};
