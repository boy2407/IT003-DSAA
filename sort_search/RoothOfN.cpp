#include<iostream>
double multiply(double x, int n) {
    double result = 1;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}
double nthRoot(double a, int n, double e) {
    double low = 0;
    double high = a;
    while (high - low > e) {
        double mid = (low + high) / 2;
        if (multiply(mid, n) < a) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}
int main() {
    double a, e;
    int n;
    std::cin >> a;
    std::cin >> n;
    std::cin >> e;
    double result = nthRoot(a, n, e);
    std::cout.precision(33);
    std::cout <<result<<std::endl;
    return 0;
}