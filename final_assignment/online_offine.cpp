#include <iostream>
#include <cstring>
using namespace std;
struct node {
	char val[30];
	node* left, * right;
};
node* get_node(char x[])
{
	node* t = new node;
	strcpy(t->val, x);
	t->left = t->right = NULL;
	return t;
}
void add_node(node*& root, char x[])
{
	if (root == NULL) root = get_node(x);
	else if (strcmp(x, root->val) < 0) add_node(root->left, x);
	else if (strcmp(x, root->val) > 0) add_node(root->right, x);
}
int check_node(node* root, char x[])
{
	if (root != NULL)
	{
		if (strcmp(x, root->val) == 0) return 1;
		else if (strcmp(x, root->val) < 0) return check_node(root->left, x);
		else if (strcmp(x, root->val) > 0) return check_node(root->right, x);
	}
	return 0;
}
void replace_node(node*& t, node*& root)
{
	if (root->left != NULL)
	{
		replace_node(t, root->left);
	}
	else
	{
		strcpy(t->val, root->val);
		t = root;
		root = root->right;
	}
}
void delete_node(node*& root, char x[])
{
	if (root != NULL)
	{
		if (strcmp(x, root->val) > 0) delete_node(root->right, x);
		else {
			if (strcmp(x, root->val) < 0) delete_node(root->left, x);
			else {
				node* t = root;
				if (root->left == NULL) root = root->right;
				else {
					if (root->right == NULL) root = root->left;
					else replace_node(t, root->right);
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
	node* root = NULL;
	int x;
	char y[30];
	while (true) {
		cin >> x;
		if (x == 0) break;
		else
		{
			cin >> y;
			if (x == 1) add_node(root, y);
			else if (x == 2) cout << check_node(root, y) << "\n";
			else if (x == 3) delete_node(root, y);
		}
	}
	return 0;
}