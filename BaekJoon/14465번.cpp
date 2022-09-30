#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
#define MAX 100010
#define INF 2'100'000'000
int n, b, k;
int cnt[MAX];
void query(int idx) {
	while (idx <= n + 1) {
		cnt[idx] += 1;
		idx += (idx & -idx);
	}
}
int sum(int idx) {
	int _sum = 0;
	while (idx) {
		_sum += cnt[idx];
		idx -= (idx & -idx);
	}
	return _sum;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> b >> k;
	for (int i = 0; i < k; i++) {
		int num; cin >> num;
		query(num);
	}
	int _min = INF, left = 1, right = b;
	while (right <= n) {
		_min = min(_min, (sum(right) - sum(left - 1)));
		right += 1, left += 1;
	}
	cout << _min << '\n';
	return 0;
}

/*
#include <cstdio>

int main(void) {
	bool sign[100001]{};
	int N, K, B, num, count = 0, min; scanf("%d %d %d", &N, &K, &B);
	for (int i = 0; i < B; i++) scanf("%d", &num), sign[num] = true;

	for (int i = 1; i <= K; i++) if (sign[i]) count++;

	min = count;
	for (int i = K + 1; i <= N; i++) {
		if (sign[i]) count++;
		if (sign[i - K]) count--;
		if (count < min) min = count;
	}
	printf("%d", min);
}
*/