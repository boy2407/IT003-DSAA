#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int k, x;
    std::cin >> k >> x;
    std::vector<std::pair<int, int>> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = {std::abs(arr[i] - x), arr[i]};
    }
    std::sort(diff.begin(), diff.end());
    std::vector<int> result(k);
    for (int i = 0; i < k; i++) {
        result[i] = diff[i].second;
    }
    std::sort(result.begin(), result.end());
    for (int i = 0; i < k; i++) {
        std::cout << result[i] << ' ';
    }
}