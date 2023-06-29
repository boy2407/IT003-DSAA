#include <iostream>
using namespace std;
struct Node {
	int val;
	Node* left, * right;
	Node(int x) : val(x), left(NULL), right(NULL) {}
};

void add_Node(Node*& root, int x)
{
	if (root == NULL) root = new Node(x);
	else if (x < root->val) add_Node(root->left, x);
	else if (x > root->val) add_Node(root->right, x);
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Node* root = NULL;
	int x, y;
	while (true) {
		cin >> x;
		if (x == 0) break;
		else
		{
			cin >> y;
			if (x == 1) add_Node(root, y);
			else if (x == 2) cout << check_Node(root, y) << "\n";
			else if (x == 3) delete_Node(root, y);
		}
	}
	return 0;
}