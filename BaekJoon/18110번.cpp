#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int pro[3 * 100000 + 1], n, tmp, avg;
int main() {
	cin >> n;
	if (n == 0) {
		cout << 0 << "\n";
		return 0;
	}
	tmp = (int)round((double)n * 15 / 100);
	for (int i = 0; i < n; i++)
		cin >> pro[i];
	sort(pro, pro + n);
	for (int i = tmp; i < n - tmp; i++)
		avg += pro[i];
	cout << round((double)avg / (n - tmp - tmp)) << "\n";
}