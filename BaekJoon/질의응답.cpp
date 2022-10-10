#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 1'000'000 + 10
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		string s; int age, weight;
		cin >> s >> age >> weight;
		if (s == "#" && !age && !weight)break;
		if (age > 17 || weight >= 80)
			cout << s + " Senior\n";
		else
			cout << s + " Junior\n";
	}
	return 0;
}