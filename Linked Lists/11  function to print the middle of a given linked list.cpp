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
struct node* printmiddle(struct node *head){
	struct node *temp1=head;
	struct node *temp2=head;
	
	while(temp2->next!=NULL){
	temp1=temp1->next;
	temp2=temp2->next->next;
	}
 return temp1;
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
	struct node *temp=NULL;
	temp=printmiddle(head);
	cout<<"Middle "<<temp->data;
}
