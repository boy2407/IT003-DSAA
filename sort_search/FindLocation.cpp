#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include<map>
using namespace std;
void findPosition()
{
	int n;
	cin >> n;
	//firt - value ; second - pos
	map<int,int> arr;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr[t] = i;
	}
	int m;
	cin >> m;
	vector<int>arrFind(m);
	vector<int>ans;
	for (auto& i : arrFind) {
		cin >> i;
		if (arr.count(i) > 0) {
			ans.push_back(arr[i]);
		}
		else {
			ans.push_back(-1);
		}	
	}
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << endl;
}
int main()
{
	findPosition();
	return 0;
}