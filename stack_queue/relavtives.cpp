#include <iostream>
#include <stack>

int main() {
    int n;
    std::cin >> n;

    long long result = 0;
    std::stack<int> stack;

    for (int i = 0; i < n; i++) {
        int h;
        std::cin >> h;

        while (!stack.empty() && stack.top() <= h) {
            stack.pop();
        }

        result += stack.size();
        stack.push(h);
    }

    std::cout << result << std::endl;

    return 0;
}
