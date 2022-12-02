#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'000 + 10
//#define INF 2'100'000'000
//#define MOD 1000
//typedef unsigned long long ull;
//typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int num[10] ={0,}, num2[10] = {0,};
	for (int i = 1; i <= 9; i++) {
		cin >> num[i];
		num[i] += num[i - 1];
	}
	for (int i = 1; i <= 9; i++) {
		cin >> num2[i];
		num2[i] += num2[i - 1];
	}
	int flag = 0;
	for (int i = 1; i <= 9; i++) {
		if (num[i] > num2[i - 1])
		{
			flag = 1;
			break;
		}
	}
	if ((num[9] < num2[9]) && (flag == 1))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}