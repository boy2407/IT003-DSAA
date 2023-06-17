#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define MAX 1005
int repeat[MAX];
int ranking[MAX];
int M[MAX];
int main()
{
	int n,rank=1;
	cin >> n;
	int max=0, min=0;
	int max_repeat = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> M[i];
		repeat[M[i]]++;
		max_repeat = max_repeat < repeat[M[i]] ? repeat[M[i]] : max_repeat;
		max = max < M[i] ? M[i] : max;
		min = min < M[i] ? min : M[i];

	}
	sort(M, M + n);
	while (max>=min)
	{
		if (repeat[max] >= 0)
		{
			ranking[max] = rank;
			rank += repeat[max];
		}
		max--;
	}
	int temp = 0;	
	for (int i = n-1; i >= 0; i--)
	{
	
		if (repeat[M[i]] == max_repeat)
		{
			temp = M[i];
			break;
		}
	}	
	for (int i =n-1; i >=0; i--)
	{
		cout<< M[i] <<" "<<ranking[M[i]] <<endl;
	}
	
	cout << temp << " " << ranking[M[0]];
	return 0;
}