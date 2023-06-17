#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void qsort(int *a, int n){
    int b = 0,e=n-1;
    int *stack= new int [e-b+1];
    int top = -1;
    stack[++top] = b;
    stack[++top] = e;
    while (top >= 0) {
        e = stack[top--];
        b = stack[top--];

        if (b >= e) continue;

        int x = a[b], i = b, j = e;
        while (i < j) {
            while (a[i] < x) i++;
            while (a[j] > x) j--;
            if (i <= j) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
                j--;
            }
        }

        stack[++top] = b;
        stack[++top] = j;
        stack[++top] = i;
        stack[++top] = e;
    }
    delete []stack;
}
int main(){
	std::ios_base::sync_with_stdio(false  );
	std::cin.tie(0);
	int n;
	cin >> n;

	int *a = new int [n];

	for(int i = 0; i < n; i++){
        	cin >> a[i];
	}

    qsort(a, n);
	for(int i = 0; i < n; i++) std::cout << a[i] << " ";

}
