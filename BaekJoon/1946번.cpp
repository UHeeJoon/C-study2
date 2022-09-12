#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while (tc--) {
        int n;  cin >> n;

        vector<pair<int, int>> grades;

        for (auto i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            grades.push_back({ x,y });
        }

        sort(grades.begin(), grades.end());

        int temp = 0;
        int result = 1;

        for (int i = 1; i < n; i++) {
            if (grades[temp].second > grades[i].second) {
                result++;
                temp = i;
            }
        }
        cout << result << "\n";
    }
    return 0;
}