#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left, *right;
    Node(int val) : val(val), left(NULL), right(NULL) {}
};

void addNode(Node*& root, int val) {
    if (!root) {
        root = new Node(val);
    }
    else if (root->val > val) {
        addNode(root->left, val);
    }
    else if (root->val < val) {
        addNode(root->right, val);
    }
}

bool find(Node* root, int val) {
    if (!root) return false;
    if (root->val == val) return true;
    else if (root->val > val) return find(root->left, val);
    else return find(root->right, val);
}

void output(Node* root) {
    if (root) {
        output(root->left);
        cout << root->val << endl;
        output(root->right);
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    Node* root = NULL;
    int x, ms;
    while (true) {
        cin >> x;
        if (x == 0) break;
        cin >> ms;
        if (x == 1) addNode(root, ms);
        else if (x == 2) cout << find(root, ms) << endl;
    }
}