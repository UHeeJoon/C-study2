#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
bool isPrime[1003002];

void eratos() {

	isPrime[0] = true;
	isPrime[1] = true;
	for (int i = 2; i <= sqrt(1003002); i++) {
		if (isPrime[i]) { continue; }
		for (int j = i * i; j <= 1003002; j += i) {
			isPrime[j] = true;
		}
	}
}

bool isSame(int N) {
	const string s = to_string(N);
	for (string::size_type i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]) { return false; }
	}
	return true;
}

int main()
{
	FAST_IO;
	int N;
	cin >> N;
	eratos();
	for (int i = N; i <= 1003002; i++) {
		if (!isPrime[i] && isSame(i)) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}