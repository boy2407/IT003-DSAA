#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void countOnline()
{
    int m, n, count = 0;
    cin >> m >> n;
    vector<int> userOline(m);
     vector<int> userFriendOline(n);
    for (auto &i :userOline){
        cin >> i;
    }
    for (auto &i :userFriendOline){
        cin >> i;
    }
    for(auto i:userFriendOline){
        if (binary_search(userOline.begin(),userOline.end(), i)==true)
            count +=1;
    }
    cout<<count;
}
int main()
{
    countOnline();
    return 0;
}