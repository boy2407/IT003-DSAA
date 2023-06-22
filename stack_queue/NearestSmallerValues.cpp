#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    stack<int> st;
    int a[n + 1];
    a[0] = 0;
    st.push(0);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        while(a[st.top()] >= a[i]){
            st.pop();
        }
        cout << st.top() << " ";
        st.push(i);
    }
    return 0;
}