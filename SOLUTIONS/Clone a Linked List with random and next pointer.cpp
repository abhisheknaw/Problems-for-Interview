/*
Intution :- The idea is to use Hashing
1. Traverse the original linked list and make a copy in terms of data.
2. Make a hash map of key value pair with original linked list node and copied linked list node.
3. Traverse the original linked list again and using the hash map adjust the next and random reference of cloned linked list nodes.
*/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* headHelper = head;
        Node* dummy = new Node(0);
        Node* helper = dummy;
        unordered_map<Node*, Node*>hashMap;

        while (headHelper != NULL) {
            Node* newNode = new Node(headHelper -> val);
            helper -> next = newNode;
            hashMap[headHelper] = newNode;
            helper = newNode;
            headHelper = headHelper -> next;
        }

        headHelper = head;
        helper = dummy -> next;

        while (headHelper != NULL && helper != NULL) {
            helper -> random = hashMap[headHelper -> random];
            helper = helper -> next;
            headHelper = headHelper -> next;
        }

        return dummy -> next;

    }
};

/*
Method 1 : Inserting clone node at middle or original node       
Complexity Analysis:

Time Complexity: O(N). We will traverse each Node at most twice.
Space complexity : O(1). we don't require additional space in our program.
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head; 
          Node *front = head;

          // First round: make copy of each node,
          // and link them together side-by-side in a single list.
          while (iter != NULL) {
            front = iter->next;

            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;

            iter = front;
          }

          // Second round: assign random pointers for the copy nodes.
          iter = head;
          while (iter != NULL) {
            if (iter->random != NULL) {
              iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
          }

          // Third round: restore the original list, and extract the copy list.
          iter = head;
          Node *pseudoHead = new Node(0);
          Node *copy = pseudoHead;

          while (iter != NULL) {
            front = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = front;
              
            copy = copy -> next; 
            iter = front;
          }

          return pseudoHead->next;
    }
};