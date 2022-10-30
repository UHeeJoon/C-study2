#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 100'000 + 10
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
void print(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 5; j++) {
			cout << '@';
		}
		cout << '\n';
	}
}
void print2(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 5; j++) {
			if (j / n >= 1 && j / n <= 3)
				cout << ' ';
			else
				cout << '@';
		}
		cout << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
	print(n);
	print2(n);
	print2(n);
	print2(n);
	print(n);
	return 0;
}