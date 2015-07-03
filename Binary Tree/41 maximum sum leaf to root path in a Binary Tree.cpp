#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};
struct node* createNode(int k) {
	struct node* temp = new node;
	temp->left = NULL;
	temp->right = NULL;
	temp->data = k;
	return temp;
}

int maxsum(struct node* root, vector<int> &v) {

	if (root == NULL)
		return 0;

	vector<int> l, r;
	int lsum = 0, rsum = 0;
	lsum = maxsum(root->left, l);
	rsum = maxsum(root->right, r);

	if (lsum > rsum) {
		v = l;
		v.push_back(root->data);
		return (root->data + lsum);
	} else {
		v = r;
		v.push_back(root->data);
		return (root->data + rsum);
	}

}
int main() {

	int sum = 0;
	std::vector<int> arr;
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

	int s = maxsum(root, arr);
	cout << "SUM" << s << "\n" << "PATH";

	reverse(arr.begin(), arr.end());
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
		cout << *it << " ";

	return 0;
}

