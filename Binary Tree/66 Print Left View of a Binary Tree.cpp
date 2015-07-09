#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {
	int data;
	struct node *left, *right;
};

struct node* newNode(int k) {
	struct node* temp = new node;
	temp->left = NULL;
	temp->right = NULL;
	temp->data = k;
	return temp;
}

void LeftViewoftree(struct node* root) {

	if (root == NULL)
		return ;
	queue<node *> q;
	cout<<root->data<<" ";
	int flag=0;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {

		struct node *curr = q.front();
		q.pop();

		if (curr == NULL) {
		
			if (!q.empty()){
				q.push(NULL);
				flag=1;
			}

		}

		else {
				if(flag==1){
					cout<<curr->data<<" ";
					flag=0;
				}
			if (curr->left != NULL){			    
				q.push(curr->left);
							
			}
			if (curr->right != NULL){
				q.push(curr->right);
			
			}
				
		}

	}

}
int main() {
  struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
	//root->right->left->right=createNode(9);

 LeftViewoftree(root);
	return 0;
}

