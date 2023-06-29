#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int x, y;
    Node* left, * right;
    Node(int x, int y) : x(x), y(y), left(NULL), right(NULL) {}
};

void addNode(Node*& root, int x, int y) {
    if (!root) {
        root = new Node(x, y);
    }
    else if (x >= root->x && y < root->y) {
        addNode(root->right, x, y);
    }
    else if (x > root->x && y >= root->y) {
        addNode(root->left, x, y);
    }
    else if (x <= root->x && y > root->y) {
        Node* temp = new Node(x, y);
        temp->right = root;
        root = temp;
    }
    else if (x < root->x && y <= root->y) {
        Node* temp = new Node(x, y);
        temp->left = root;
        root = temp;
    }
}

int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void output(Node* root) {
    if (root) {
        cout << "(" << root->x << ", " << root->y << ") ";
        output(root->left);
        output(root->right);
    }
}

int main() {
    int x, y;
    Node* root = NULL;
    while (true) {
        cin >> x;
        if (x == 0) {
            cout << height(root) << endl;
            output(root);
            break;
        }
        else {
            cin >> y;
            addNode(root, x, y);
        }
    }
    return 0;
}