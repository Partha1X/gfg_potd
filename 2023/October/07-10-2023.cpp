/*

Author : Partha Biswas
Date : 07/10/2023
Problem : Pairwise swap elements of a linked list
Problem Link : https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        if(head ==NULL || head->next==NULL)
        {
            return head;
        }
        //intialize pointers for Swapping
        Node*prev=head;
        Node*curr=head->next;
        Node*newHead=curr; //New  Head After Swapping
        while (true) {
            Node* next = curr->next; // Save the next node

            // Swap 'prev' and curr
            curr->next = prev;
            
            // If 'next' is NULL or its next is NULL, we have reached the end of the list
            if (next == NULL || next->next == NULL) {
                prev->next = next;
                break;
            }

            // Link 'prev' to the next pair
            prev->next = next->next;

            // Move to the next pair
            prev = next;
            curr = prev->next;
        }

        return newHead;
    }
};

//{ Driver Code Starts.

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		map<Node*, int> mp;
		mp[head] = head->data;
		for (int i = 0; i<n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
			mp[tail] = tail->data;
		}
		struct Node *failure = new Node(-1);
		Solution ob;
		head = ob.pairWiseSwap(head);
		int flag = 0;
		struct Node *temp = head;
		while(temp){
		    if(mp[temp] != temp->data){
		        flag = 1;
		        break;
		    }
		    temp = temp->next;
		}
		if(flag)
		    printList(failure);
		else
		    printList(head);
	}
	return 0; 
}

// } Driver Code Ends
