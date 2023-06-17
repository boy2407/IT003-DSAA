#include <iostream>
#include <vector>
#define MAX 1000005;

using namespace std;
bool  Palindrome(vector<int>m) {
    int count = 0;
    int length = m.size();
    for (int i = 0; i < length/2; i++){
        if (m[i] != m[length-1-i])
           ++count;          
    }
    return (count <= 1);
}
int main()
{
    int n;
    vector<int>a;
    cin >>n;
    for (int i = 0; i< n; i++){
        int k;
        cin>>k;
        a.push_back(k);
    }

    if (Palindrome(a))
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
    return 0;
}
