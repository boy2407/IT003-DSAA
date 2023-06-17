#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isBalanced(string str) {
    vector<char> s;
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            s.push_back(c);
        } else {
            if (s.empty()) return false;
            char top = s.back();
            s.pop_back();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) return false;
        }
    }
    return s.empty();
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == "END") break;
        cout << (isBalanced(line) ? "TRUE" : "FALSE") << endl;
    }
    return 0;
}