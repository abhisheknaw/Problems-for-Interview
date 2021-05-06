#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *link=NULL;
};
struct node *head;
void insert(int x)
{
	struct node *temp =new node();
	temp->data=x;
	temp->link=NULL;

	if(head==NULL)
	{
		head=temp;
		return;
	}

	struct node *last = head;
	while(last->link != NULL)
	{
		last=last->link;
	}
	last->link=temp;

} 
  
/*
Method 1 : Using Iteration       Verdict Accepted
Complexity analysis
Time complexity : O(n). Assume that N is the list's length, the time complexity is O(N).
Space complexity : O(1).
*/
/*
void reverse()
{
	struct node * prev,*current,*link;
	prev= NULL;
	current=head;

	while(current!= NULL)
	{
		link=current->link;
		current->link=prev;
		prev=current;
		current=link;

	}

	head=prev;
}*/



/*
Method 2 : Using recursion         
Complexity analysis
Time complexity : O(n). Assume that n is the list's length, the time complexity is O(n).
Space complexity : O(n). The extra space comes from implicit stack space due to recursion. The recursion could go up to nn levels deep.
idea : key idea here is traverse list to end once we get the node with next as NULL it will be our new head and
       from there we will do our further operation.
*/
void reverse(node *p)
{
	if(p->link==NULL)
	{
		head=p;
		return;
	}
	reverse(p->link);
	struct node *q=p->link;
	q->link=p;
	p->link=NULL;
}
void print ()
{
	struct node *yo=head;

	while(yo!= NULL)
	{
		cout<<yo->data<<" ";
		yo=yo->link;
	}
}
int main() 
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	head=NULL;
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		insert(x);
	}

	print();
	reverse(head);
	cout<<endl;
	print();
	return 0;
}
