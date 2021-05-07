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
TC: O(n)+O(n/2)
SC: O(1)


int findMiddle()
{
	struct node *temp=head;
	int count =0;
	while(temp != NULL)
	{
		temp=temp->link;
		count++;
	}
	return count;
}

void printMiddle()
{
	int n= (findMiddle()/2) +1;
	struct node *d=head;
	for(int i=1;i<n;i++)
	{
		d=d->link;
	}
	cout<<d->data;
}
*/

/*
Complexity Analysis
Time Complexity: O(N/2), where N is the number of nodes in the given list.
Space Complexity: O(1), the space used by slow and fast.
*/
void printMiddle()
{
	struct node*slow =head;
	struct node*fast =head;
	while(fast!=NULL && fast->link !=NULL )
	{
		slow=slow->link;
		fast=(fast->link)->link;
	}
	cout<<endl;
	cout<<slow->data;
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
 	printMiddle();
 	cout<<endl;
	return 0;
}