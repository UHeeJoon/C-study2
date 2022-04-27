#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265359
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        double balloonNum, weight, radius, totalHelium = 0;
        cin >> balloonNum >> weight;
        for (int j = 1; j <= balloonNum; j++) {
            cin >> radius;
            totalHelium += 4.0 / 3.0 * PI * pow(radius, 3) / 1000;
        }
        cout << "Data Set " << i << ":\n";
        if (totalHelium >= weight) cout << "Yes";
        else cout << "No";
        cout << "\n\n";
    }
	return 0;
}