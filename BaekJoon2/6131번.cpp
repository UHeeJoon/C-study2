#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, cnt = 0; cin >> n;
    for (int i = 1; i <= 500; i++)
        for (int j = i; j <= 500; j++)
            if (j * j == i * i + n)
                cnt++;
	cout << cnt << '\n';
	return 0;
 }
