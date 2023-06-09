#include <iostream>
#include <vector>
using namespace std;
vector<int> mergePairs(const vector<int> &arr, int k) {
    k = k * 2;
    vector<int> mergedArr;
    int n = arr.size();
    int i = 0;
    while (i + k <= n) {
        int j = i;
        int temp = j + (k / 2);
        while (j < (i + (k / 2)) || (temp < (i + k) && temp < n)) {
            if ((j == (i + (k / 2))) || (temp < (i + k) && arr[temp] <= arr[j])) {
                mergedArr.push_back(arr[temp]);
                temp++;
            } else {
                mergedArr.push_back(arr[j]);
                j++;
            }
        }

        i = i + k;
    }
    // Check phần còn lại
    int temp = i + (k / 2);
    int stop = temp;
    if ((n - i) > (k / 2)) {
        while (true) {
            if (i == stop && temp == n)
                break;

            if (i == stop || (temp < n && arr[temp] < arr[i])) {
                mergedArr.push_back(arr[temp]);
                temp++;
            } else {
                mergedArr.push_back(arr[i]);
                i++;
            }
        }
    } else {
        while (true) {
            if (i == n)
                break;
            mergedArr.push_back(arr[i]);
            i++;
        }
    }
    return mergedArr;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> mergedArr = mergePairs(arr, k);
    for (int i = 0; i < mergedArr.size(); i++) {
        cout << mergedArr[i] << " ";
    }
    cout << endl;
    return 0;
}