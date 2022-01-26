#include<iostream>
#include<algorithm>
using namespace std;
int num[6];
bool divide(int a) {
	int cnt = 0;
	for (int i = 0; i < 5; i++) 
		if (a % num[i] == 0) 
			cnt++;
	return cnt > 2;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 5; i++)
		cin >> num[i];
	sort(num, num + 5);
	int i = 1;
	while (i++) 
		if (divide(i))
			break;
	cout << i <<"\n";
}