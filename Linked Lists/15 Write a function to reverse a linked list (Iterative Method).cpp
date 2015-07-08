#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;
struct node{
	int data;
	node * next;
};

void push(struct node* *head,int k){
	struct node *temp=new node;
	struct node *curr=*head;
	temp->data=k;
	temp->next=NULL;
	if(*head==NULL){
	*head=temp;
	return;	
	}
	 		while(curr->next!=NULL)
			curr=curr->next;
	
		curr->next=temp;

	return; 
}
void printlist(struct node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
void reverselist(struct node* *head){
	struct node *prev=NULL;
	struct node *curr=*head;
	struct node *nextnode=(*head)->next;
	
	while(curr!=NULL){
		curr->next=prev;
		prev=curr;
		curr=nextnode;
		if(curr!=NULL)
		nextnode=curr->next;
	}
*head=prev;
}
int main(){
	struct node* head=NULL;
	push(&head,85);
	push(&head,15);
	push(&head,4);
	push(&head,20);
	push(&head,10);
	
	printlist(head);
	cout<<"\n";
	reverselist(&head);
	printlist(head);
}
