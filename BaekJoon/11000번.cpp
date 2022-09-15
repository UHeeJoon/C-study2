#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;
// ���� �ð� ���
vector< pair<int, int> > class_time;

// ���� �ð� ť (���� ���� ���� �켱������ �Ǵ� ť)
priority_queue< int, vector<int>, greater<int> > pq_less;

int greedy(int class_count) {
	// ù ��° ������ ���� �ð��� pq �� ����
	pq_less.push(class_time[0].second);

	// �ʿ��� ���ǽ� Ž��
	for (int i = 1; i < class_count; ++i) {
		// i ��° ������ ���� �ð��� pq �� ����
		pq_less.push(class_time[i].second);
		// top �� ���� �ð����� i ��° ������ �ʰ� �����Ѵٸ�, ���� ���ǽǿ��� ���� ����
		if (pq_less.top() <= class_time[i].first) {
			// ������ top �� ����
			pq_less.pop();
		}
	}
	// pq �� ��Ұ����� �� �ʿ��� ���ǽ� ����
	return pq_less.size();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	// ���� ���� ��ŭ ���� �ð� ����
	for (int i = 0; i < n; ++i) {

		// ���� ����, ���� �ð�
		int start_time, end_time;
		cin >> start_time >> end_time;

		// ���� �ð� ����
		class_time.push_back(make_pair(start_time, end_time));
	}

	// ���� �ð� �������� ���� ����
	sort(class_time.begin(), class_time.end());

	cout << greedy(n) << '\n';
	return 0;
}