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

bool roottoleafsum(struct node* root, int sum, std::vector<int> &arr) {
	if (root == NULL)
		return false;
	if (root->left == NULL && root->right == NULL) {
		if (root->data == sum) {
			arr.push_back(root->data);
			return true;
		} else
			return false;
	}
	if (roottoleafsum(root->left, sum - root->data, arr)) {
		arr.push_back(root->data);
		return true;
	}
	if (roottoleafsum(root->right, sum - root->data, arr)) {
		arr.push_back(root->data);
		return true;
	}
	return false;
}
int main() {

	int sum = 21;
	std::vector<int> arr;
	/* Constructed binary tree is
	 10
	 /   \
        8      2
	 /  \    /
	 3     5  2
	 */
	struct node *root = createNode(10);
	root->left = createNode(8);
	root->right = createNode(2);
	root->left->left = createNode(3);
	root->left->right = createNode(5);
	root->right->left = createNode(2);

	if (roottoleafsum(root, sum, arr)) {
		reverse(arr.begin(), arr.end());
		printf("There is a root-to-leaf path with sum %d \n Path ", sum);
		for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
			cout << *it << " ";
		}
	} else
		printf("There is no root-to-leaf path with sum %d", sum);

	getchar();
	return 0;
}

