#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    stack<int> st;
    int max_area = 0;
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || heights[st.top()] > heights[i])) {
            int h = heights[st.top()];
            st.pop();
            int w = st.empty() ? i * 10 : (i - st.top() - 1) * 10;
            max_area = max(max_area, h * w);
        }
        st.push(i);
    }

    cout << max_area << endl;

    return 0;
}