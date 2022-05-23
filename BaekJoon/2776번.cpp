#include<bits/stdc++.h>
using namespace std;
int num[1000010];
int n, m;
void binary_search(int number) {
	int low = 0;
	int high = n - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (num[mid] == number) {
			cout << '1' << "\n";
			return;
		}
		else if (num[mid] < number) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << '0' << "\n";
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		sort(num, num + n);
		cin >> m;
		for (int i = 0; i < m; i++) {
			int a; cin >> a;
			binary_search(a);
		}
	}
	return 0;
}
/*
// map 활용
#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M;
	cin >> T;
	for (int k = 0; k < T; k++) {
		cin >> N;
		map<int, int> m; //해쉬 맵
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			m[num] = 1;
		}
		cin >> M;
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			if (m[num] == 1) //존재할 때
				cout << "1\n";
			else //존재하지 않을 때
				cout << "0\n";
		}
	}
	return 0;
}
*/
/*
// unordered_map
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M;
	cin >> T;
	for (int k = 0; k < T; k++) {
		cin >> N;
		unordered_map<int, int> um; //해쉬맵
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			um[num] = 1;
		}
		cin >> M;
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			if (um[num] == 1) //존재할 때
				cout << "1\n";
			else //존재하지 않을 때
				cout << "0\n";
		}
	}
	return 0;
}
*/