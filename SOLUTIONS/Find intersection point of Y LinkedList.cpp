/*
Approach 2: Hash Table    
Complexity Analysis
Time complexity : O(m+n).
Space complexity : O(m) or O(n).
*/


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        
        unordered_map<ListNode*,int>mp;
        while(headA!=NULL)
        {
            mp[headA]++;
            headA=headA->next;
        }
        
        while(headB!=NULL)
        {
            if(mp.find(headB)!=mp.end())
            {
                return headB;
            }
            headB=headB->next;
        }
        return NULL;
    }
        
};

/*
Approach 1: Two Pointers 
Complexity Analysis
Time complexity : O(m+n).
Space complexity : O(1).
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *temp1= headA;
        ListNode *temp2= headB;
        
        if(temp1==NULL || temp2==NULL)
            return NULL;
        
        while(temp1!=temp2)
        {
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==temp2)
                return temp1;
            
            if(temp1==NULL)
                temp1=headB;
            
            if(temp2==NULL)
                temp2=headA;
            
            
            
        }
        return temp1;
        
    }
};