#include <iostream>
using namespace std;

#define MAX_SIZE 1000010
bool arr[MAX_SIZE + 1];

int main() {

    long long min, max;
    cin >> min >> max;
    fill(arr, arr + MAX_SIZE, true);
    for (int i = 0; i <= max - min; i++)
        arr[i] = true;


    long long multi_min, squared;
    for (long long k = 2; k * k <= max; k++) {
        squared = k * k;
        if (min % squared == 0) multi_min = min;
        else multi_min = (min / squared + 1) * squared;

        for (long long j = multi_min; j <= max; j += squared)
            arr[j - min] = false;
    }

    int sum = 0;
    for (int i = 0; i <= max - min; i++) {
        if (arr[i]) sum++;
    }
    cout << sum;
}