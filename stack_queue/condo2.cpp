#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int boatLength, amount;
    cin >> boatLength >> amount;
    boatLength = boatLength * 100;

    vector<pair<int, int>> leftQueue;
    vector<pair<int, int>> rightQueue;

    for (int i = 0; i < amount; ++i) {
        int vehicleLength;
        string side, type;

        cin >> vehicleLength;
        cin >> type;
        cin >> side;

        int priority = 0;
        if (type == "civilian")
            priority = 20000;
        else if (type == "police")
            priority = 40000;
        else if (type == "army")
            priority = 60000;
        else if (type == "fire")
            priority = 80000;
        else if (type == "ambulance")
            priority = 100000;

        pair<int, int> vehicle(priority - i, vehicleLength);

        if ("left" == side) {
            leftQueue.push_back(vehicle);
        } else {
            rightQueue.push_back(vehicle);
        }
    }

    sort(leftQueue.begin(), leftQueue.end());
    sort(rightQueue.begin(), rightQueue.end());

    bool currentSide = true;
    int numberOfTrips = 0;
    while (!leftQueue.empty() || !rightQueue.empty()) {
        int spaceLeft = boatLength;
        if (currentSide) {
            while (!leftQueue.empty() && leftQueue.back().second <= spaceLeft) {
                spaceLeft -= leftQueue.back().second;
                leftQueue.pop_back();
            }
        } else {
            while (!rightQueue.empty() && rightQueue.back().second <= spaceLeft) {
                spaceLeft -= rightQueue.back().second;
                rightQueue.pop_back();
            }
        }

        numberOfTrips++;
        currentSide = !currentSide;
    }

    cout << "\n" << numberOfTrips;
    return 0;
}