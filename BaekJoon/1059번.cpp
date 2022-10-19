#include<bits/stdc++.h>
using namespace std;
int arr[55];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int L; cin >> L;
	int scaleRight = 1001, scaleLeft = -1001;
	int arr[51];
	for (int i = 0; i < L; ++i) {
		cin >> arr[i];
	}
	int n; cin >> n;
	for (int i = 0; i < L; ++i) {
		if (arr[i] - n >= 0)
			scaleRight = min(scaleRight, arr[i] - n);
		else
			scaleLeft = max(scaleLeft, arr[i] - n);
	}
	if (scaleRight != 1001 && scaleLeft != -1001 && scaleRight != 0) {
		cout << abs(scaleRight * scaleLeft) - 1 << '\n';
	}
	else if (scaleLeft == -1001 && scaleRight != 0) {
		cout << n * scaleRight - 1 << '\n';
	}
	else if (scaleRight == 0) {
		cout << 0 << '\n';
	}
	return 0;
}