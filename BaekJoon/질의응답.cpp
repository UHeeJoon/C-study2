#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<int, vector<int>, greater<>> pqRight;
	priority_queue<int, vector<int>, less<>> pqLeft;
	int n; cin >> n;
	int num; cin >> num;
	n--;
	cout << num << '\n';
	pqLeft.push(num);
	//if (n > 0) {
	//	cin >> num;
	//	n--;
	//	if (pqLeft.top() > num) {
	//		pqRight.push(pqLeft.top());
	//		pqLeft.pop();
	//		pqLeft.push(num);
	//	}
	//	else
	//		pqRight.push(num);
	//	cout << pqLeft.top() << '\n';
	//}
	for (int i = 1; i <= n; i++) {
		cin >> num;
		if (pqLeft.size() <= pqRight.size()) {
			if (pqRight.top() < num) {
				pqLeft.push(pqRight.top());
				pqRight.pop();
				pqRight.push(num);
			}
			else
				pqLeft.push(num);
		}
		else {
			if (pqLeft.top() > num) {
				pqRight.push(pqLeft.top());
				pqLeft.pop();
				pqLeft.push(num);
			}
			else
				pqRight.push(num);
		}
		cout << pqLeft.top() << '\n';
	}

	return 0;
}
