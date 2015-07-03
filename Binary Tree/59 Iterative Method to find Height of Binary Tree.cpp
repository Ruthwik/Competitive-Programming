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

int heightoftree(struct node* root) {
	int h = 0;
	if (root == NULL)
		return 0;
	queue<node *> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {

		struct node *curr = q.front();
		q.pop();

		if (curr == NULL) {
			h++;
			if (!q.empty())
				q.push(NULL);
			cout << h << " ";
		}

		else {
			//	cout<<curr->data<<" ";
			//cout<<"left and right  "<<curr->left->data<<curr->right->data;
			if (curr->left != NULL)
				q.push(curr->left);
			if (curr->right != NULL)
				q.push(curr->right);
		}

	}
	return h;
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

	cout << "height of tree " << heightoftree(root);
	return 0;
}

