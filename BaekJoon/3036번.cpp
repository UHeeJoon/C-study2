#include<iostream>
using namespace std;
int n,temp, num[101];
int gcd(int a, int b) {
	if (b)
		return gcd(b, a % b);
	return a;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (!i) temp = num[i];
		else {
			int GCD = gcd(temp, num[i]);
			cout << temp / GCD << "/" << num[i] / GCD << "\n";
		}
	}
	return 0;
}