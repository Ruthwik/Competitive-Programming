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

void RightViewoftree(struct node* root) {

	if (root == NULL)
		return ;
	struct node* last=NULL;
	queue<node *> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {

		struct node *curr = q.front();
		q.pop();

		if (curr == NULL) {
		   cout<<last->data<<" ";
			if (!q.empty()){
				q.push(NULL);
			}

		}

		else {
			last=curr;
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

 RightViewoftree(root);
	return 0;
}

