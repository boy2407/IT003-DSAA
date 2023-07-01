
#include <iostream>
using namespace std;
struct Node {
	int val;
	int level;
	Node* left, * right;
	Node(int x) : val(x), left(NULL), right(NULL) {}
};

void add_Node(Node*& root, int x, int level = 0) {
	if (root == NULL) {
		root = new Node(x);
		root->level = level;
	}
	else if (x < root->val) {
		add_Node(root->left, x, level + 1);
	}
	else if (x > root->val) {
		add_Node(root->right, x, level + 1);
	}
}
int check_Node(Node* root, int x)
{
	if (root != NULL)
	{
		if (root->val == x) return 1;
		else if (x < root->val) return check_Node(root->left, x);
		else if (x > root->val) return check_Node(root->right, x);
	}
	return 0;
}
void replace(Node*& t, Node*& root)
{
	if (root->left != NULL)
	{
		replace(t, root->left);
	}
	else
	{
		t->val = root->val;
		t = root;
		root = root->right;
	}
}
void delete_Node(Node*& root, int x)
{
	if (root != NULL)
	{
		if (root->val < x) delete_Node(root->right, x);
		else {
			if (root->val > x) delete_Node(root->left, x);
			else {
				Node* t = root;
				if (root->left == NULL) root = root->right;
				else {
					if (root->right == NULL) root = root->left;
					else replace(t, root->right);
				}
				delete t;
			}
		}
	}
}
void NLR(Node* root) {
	if (root == NULL) return;
	for (int i = 0; i < root->level; i++)
	{
		cout << "....";
	}
	cout << root->val << endl;
	NLR(root->left);
	NLR(root->right);
}
void RNL(Node* root) {
	if (root == NULL) return;
	
	
	RNL(root->right);
	for (int i = 0; i < root->level; i++)
	{
		cout << "....";
	}
	cout << root->val << endl;
	RNL(root->left);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Node* root = NULL;
	int x;
	while (true) {
		cin >> x;
		if (x == 0) {
			RNL(root);
			cout << endl;
			NLR(root);
			break;
		}
		else
		{
			add_Node(root, x);
		}
	}
	return 0;
}