/*

Author : Partha Biswas
Date : 08/10/2023
Problem : Insert in a Sorted List
Problem Link : https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1
*/
//{ Driver Code Starts
//

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


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        Node*curr=head;
        Node*prev=NULL;
        Node*newNode=new Node(data);
        
        while(curr!=NULL)
        {
            if(curr->data<=data)
            {
                prev=curr;
                curr=curr->next;
            }
            else{
                if(prev==NULL)
                {
                    newNode->next=curr;
                    head=newNode;
                }
                else
                {
                    newNode->next=prev->next;
                    prev->next=newNode;
                }
                break;
            }
        }
            if(prev != NULL && prev->next == NULL){
            prev->next = newNode;
        }
        return head;
    }
};


//{ Driver Code Starts.
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
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends
