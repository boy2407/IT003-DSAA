#include <iostream>
using namespace std;
struct Node {
    int x;
    Node* left, *right;
    Node(int x) :  x(x), left(NULL), right(NULL) {}
};

void addNode(Node*& root, int x) {
    if (!root) root = new Node(x);
    else if (x < root->x) addNode(root->left, x);
    else if (x > root->x) addNode(root->right, x);
   
}
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int x, y;
    Node* root = NULL;
    while (true) {
        cin >> x;
        if (x == 0) {
            cout << height(root) << endl; 
            break;
        }
        else {          
            addNode(root, x);
        }
    }
    /*
393
981
841
133
891
739
663
119
497
865
54
631
561
51
227
841
352
996
505
0
    
    */
    return 0;
}