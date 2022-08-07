#include<bits/stdc++.h>
using namespace std;
int green_onion[1000001];
int s, c;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s >> c;
    long long Sum = 0;
    for (int i = 0; i < s; i++) {
        cin >> green_onion[i];
        Sum += green_onion[i];
    }
    int low = 1, high = 1000000000;
    long long greenOnion = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        long long sum = 0;
        for (int i = 0; i < s; i++) {
            sum += green_onion[i] / mid;
        }
        if (sum >= c) {
            low = mid + 1;
            greenOnion = mid;
        }
        else
            high = mid - 1;
    }
    cout << Sum - (greenOnion * c) << '\n';
    return 0;
}