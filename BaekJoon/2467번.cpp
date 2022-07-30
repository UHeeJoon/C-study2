#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int i = 0, j = n - 1;
	int value = 2000'000'010;
	int y = 0, x = 0;
	while (i != j) {
		if (v[i] + v[j] < 0) {
			if (abs(v[i] + v[j]) < value) {
				value = abs(v[i] + v[j]);
				y = v[i]; x = v[j];
			}
			i++;
		}
		else if (v[i] + v[j] > 0) {
			if (abs(v[i] + v[j]) < value) {
				value = abs(v[i] + v[j]);
				y = v[i]; x = v[j];
			}
			j--;
		}
		else {
			y = v[i];
			x = v[j];
			break;
		}
	}
	cout << y << ' ' << x << '\n';
	return 0;
}
/*
 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,n,L,R;
int result= 2000000001;
vector<int> v;
int finalL, finalR;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());

	L = 0; R = N - 1;
	int tmpSum;
	while (L < R) {
		tmpSum = v[L] + v[R];
		if (result > abs(tmpSum)) {
			result = abs(tmpSum);
			finalL = v[L];
			finalR = v[R];
		}
		if (tmpSum > 0)R--;
		else L++;
	}
	cout << finalL << " " << finalR << endl;
}
 */