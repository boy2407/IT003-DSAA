#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    stack<int> s;
    int op;
    while (cin >> op) {
        if (op==1) {
            int n;
            cin >> n;
            s.push(n);
        } else if (op==2) {
            if (s.empty()) {
                cout << "EMPTY" << endl;
            } else {
                 cout << s.top() << endl;
                 s.pop();
            }
        } else if (op==3) {
            if (s.empty()) {
                cout << "EMPTY" << endl;
            } else {
                cout << s.top() << endl;
            }
        } else if (op==4) {
            break;
        }
    }
    return 0;
}