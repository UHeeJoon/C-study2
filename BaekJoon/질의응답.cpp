#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<int, vector<int>, less<>> qp_l;
	priority_queue<int, vector<int>, greater<>> qp_g;
	for (int i = 1; i < 10; i++)
		qp_l.push(i), qp_g.push(i);
	for (int i = 1; i < 10; i++) {
		cout << qp_l.top() << ' ';
		qp_l.pop();
	} cout << '\n';
	for (int i = 1; i < 10; i++) {
		cout << qp_g.top() << ' ';
		qp_g.pop();
	}
	return 0;
}
