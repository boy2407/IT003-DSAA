#include <iostream>
using namespace std;
struct Node {
	int val;
	int level;
	string s;
	Node* left, * right;
	Node(int x) : val(x), left(NULL), right(NULL) {}
};

void add_Node(Node*& root, int x, int level = 0,string s="") {
	if (root == NULL) {
		root = new Node(x);
		root->level = level;
		root->s = s;
	}
	else if (x < root->val) {
		add_Node(root->left, x, level + 1,s+ "l");
	}
	else if (x > root->val) {
		add_Node(root->right, x, level + 1,s+ "r");
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

void LNR(Node* node,string pre="", bool isleft = true) {
	if (node == NULL) return; 
	LNR(node->left, pre+(isleft ? "    ":"|   "), true);
	string temp = pre;
	cout << temp.erase(0,4);
	
	if (node->level > 0) { 
		cout << "|---";
	}
	cout << node->val << endl; 
	LNR(node->right,pre+(isleft ? "|   " : "    "), false);
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
			LNR(root);
			cout << endl;			
			break;
		}
		else
		{
			add_Node(root, x);
		}
	}
	return 0;
}