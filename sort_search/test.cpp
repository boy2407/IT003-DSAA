#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector<int>arr;
	int x;
	int n = 0, idUser;
	while(cin>>x>>idUser){
		if (x == 0) break;
		if (x == 1) {
		    auto it = lower_bound(arr.begin(),arr.end(),x);
		    arr.insert(it,idUser);
		}
		else if (x == 2)
            cout << binary_search(arr.begin(),arr.end(),idUser) + 1 <<endl;
	}
	return 0;
}