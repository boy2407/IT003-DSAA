#include <iostream>

using namespace std;
int binarySearch(int *a, int n,int x) {
	int l = 0;
	int r = n - 1;
	int m;
	while (l <= r) {
		m = l + ((r-l)/2);
		if (a[m] == x) return m;
		else if (a[m] > x) r = m - 1;
		else  l = m + 1;
	}
	return -1;
}
void insertion_bs_sort(int *a,int &n,int x ){
    if(binarySearch(a,n,x)!=-1);
    else{
        a[n] = x;
		int i = n - 1;
		while (i >= 0 && a[i] > x)
		{
			a[i + 1] = a[i];
			--i;
		}
		a[i + 1] = x;
		++n;
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    srand(time(0));

	int* arr = new int[1000005];
	int x;
	int n = 0, idUser;
	do {
		std::cin >> x;
		if (x == 0) break;

		cin >> idUser;
		if (x == 1) insertion_bs_sort(arr,n,idUser);
		else if (x == 2)
            cout << binarySearch(arr,n,idUser) + 1 <<endl;

	} while (x > 0);

    delete []arr;
	return 0;
}