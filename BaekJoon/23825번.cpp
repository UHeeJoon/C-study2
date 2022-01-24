#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	int tmp = min(N, M);
	cout << tmp / 2 <<"\n";
}