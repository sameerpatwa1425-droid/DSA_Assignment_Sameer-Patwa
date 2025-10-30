#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of altitude changes: ";
    cin >> n;

    int gain[100];
    cout << "Enter altitude changes: ";
    for (int i = 0; i < n; i++)
        cin >> gain[i];

    int current = 0, highest = 0;

    for (int i = 0; i < n; i++) {
        current += gain[i];
        if (current > highest)
            highest = current;
    }

    cout << "Highest altitude reached: " << highest;
    return 0;
}
