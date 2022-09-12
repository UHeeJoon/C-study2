#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	priority_queue<int> minus;
	priority_queue<int, vector<int>, greater<>> plus;
	int one = 0;
	bool zero = false;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (num == 1) one++;
		else if (num == 0) zero = true;
		else if (num > 0) plus.push(num);
		else minus.push(num);
	}
	int sum = 0;
	if (minus.size() & 1)minus.push(zero ? 0 : 1);
	while (!minus.empty()) {
		int num1 = minus.top(); minus.pop();
		int num2 = minus.top(); minus.pop();
		sum += (num1 * num2);
	}
	if (plus.size() & 1)plus.push(1);
	while (!plus.empty()) {
		int num1 = plus.top(); plus.pop();
		int num2 = plus.top(); plus.pop();
		sum += (num1 * num2);
	}
	cout << sum + one << '\n';
	return 0;
}