#include<iostream>
using namespace std;
string L, R;
int cnt;
int main() {
	cin >> L >> R;
	if (L.length() == R.length()) {
		for (int i = 0; i < (int)L.length(); i++) {
			if (L[i] == R[i] && R[i] == '8')
				cnt++;
			else if (L[i] != R[i])
				break;
		}
	}
	cout << cnt << "\n";
}