#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {
	int data;
	struct node *left, *right;
};

struct node* createNode(int k) {
	struct node* temp = new node;
	temp->left = NULL;
	temp->right = NULL;
	temp->data = k;
	return temp;
}

int height(node * root)
{
    struct node * curr=root;
    if(curr==NULL)
        return 0;
    else
        return(1+max(height(curr->left),height(curr->right)));
        
  
}
int main() {
	/* Constructed binary tree is
	     10
	    /   \
       8     2
	  /  \   /
	 3   5  2
	 */
	struct node *root = createNode(10);
	root->left = createNode(8);
	root->right = createNode(2);
	root->left->left = createNode(3);
	root->left->right = createNode(5);
	root->right->left = createNode(2);
	//root->right->left->right=createNode(9);

	cout << "height of tree " << height(root);
	return 0;
}

