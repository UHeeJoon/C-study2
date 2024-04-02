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
Sensor ������ N���̰� Reception ������ K��� �Ҷ�
N - K �� ����

���� Sensor ������ 6���̰� Reception�� ������ 2����� �Ҷ�

<1 3> <6 6 7 9> �� ���������� �˴ϴ�.
�̷��� �Ǹ� 3�� 6 ������ �Ÿ��� ���� �ʿ䰡 ���� �̴ϴ�.
�׷��� ���Ͻ� Sensor ������ �Ÿ� 5���� ���� ū 3�� ������ �������� ���ϸ� ���� ���ϴ� ���� ������ �˴ϴ�.

�� 1 �� 3, 6 �� 6, 6 �� 7, 7 �� 9 ������ �Ÿ��� ���ϰ� �Ǹ� Reception�� ���� ������ �Ÿ��� ���ϰ� �Ǵ� �̴ϴ�.

�׷��� Reception�� ������ 3���϶��� ����

<1 3> <6 6 7> <9> �� ������ ���� �����̴ϴ�.
�׷��� 3�� 6, 7�� 9 ������ �Ÿ��� ���� �ʿ䰡 ������?

�� ���Ͻ� Sensor ������ �Ÿ� 5���� ���� ū 3�� �ι�°�� ū 2�� ������ �������� ���ϸ� ������ ������ �˴ϴ�.
*/