#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int main()
{
	FAST_IO;
	int n, k; cin >> n >> k;
	vector<int> v(n);
	vector<int> v2(n - 1);
	for (int& el : v) {
		cin >> el;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 1; i++) {
		v2[i] = v[i + 1] - v[i];
	}
	sort(v2.begin(), v2.end());
	int sum = 0;
	for (int i = 0; i < n - k; i++) {
		sum += v2[i];
	}
	cout << sum << '\n';
	return 0;
}

/*
Sensor 갯수가 N개이고 Reception 갯수가 K라고 할때
N - K 인 이유

만약 Sensor 갯수가 6개이고 Reception의 갯수가 2개라고 할때

<1 3> <6 6 7 9> 로 나뉘어지게 됩니다.
이렇게 되면 3과 6 사이의 거리를 구할 필요가 없을 겁니다.
그러면 구하신 Sensor 사이의 거리 5개중 가장 큰 3을 제외한 나머지를 더하면 저희가 원하는 답이 나오게 됩니다.

즉 1 과 3, 6 과 6, 6 과 7, 7 과 9 사이의 거리를 구하게 되면 Reception의 수신 가능한 거리를 구하게 되는 겁니다.

그러면 Reception의 갯수가 3개일때는 어떨까요

<1 3> <6 6 7> <9> 로 나뉘어 질수 있을겁니다.
그러면 3과 6, 7과 9 사이의 거리를 구할 필요가 없겠죠?

즉 구하신 Sensor 사이의 거리 5개중 가장 큰 3과 두번째로 큰 2를 제외한 나머지를 더하면 정답이 나오게 됩니다.
*/