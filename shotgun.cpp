#include <iostream>

int main() {
    while(true)
    {
        int arr[5];
        for (int & i : arr) {
        std::cin >> i;
        }

        int result = 0;
        int currentAmmo = arr[2];

        do {
            if (arr[3] < currentAmmo) {
                result = result + (arr[3] * arr[4]);
                break;
            } else {
                result = result + (currentAmmo * arr[4]);
            }

            arr[3] = arr[3] - currentAmmo;

            if ((arr[3] < arr[2] && (arr[3] * arr[0]) < arr[1]) || (arr[2] * arr[0]) < arr[1]) {
                result = result + (arr[0] * arr[3]);
                currentAmmo = arr[3];
            } else {
                result = result + arr[1];
                currentAmmo = arr[2];
            }
        } while (arr[3] > 0);

        std::cout << result <<"\n";

    }
   
    return 0;
}