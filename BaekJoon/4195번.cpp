#include<bits/stdc++.h>
using namespace std;
#define MAX 200'000 + 10
int friends[MAX];
int friend_cnt[MAX];
int getParent(int x) {
	if (friends[x] == x) return x;
	else return getParent(friends[x]);
}
int unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a != b) {//���� ���տ� ���� �ʴٸ�
		friends[b] = a;//�� ������ ����
		friend_cnt[a] += friend_cnt[b];//v������ u�� ������
		friend_cnt[b] = 1;//v�� ���߿� �ٸ� ������ ���� �� ������ 1�� �ʱ�ȭ ������
	}
	return friend_cnt[a];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while (tc--) {
		int F; cin >> F;
		map<string, int> _map;
		for (int i = 1; i <= 2 * F; i++) {
			friends[i] = i;
			friend_cnt[i] = 1;
		}
		int p = 1;
		for (int i = 0; i < F; i++) {
			string s, s1; cin >> s >> s1;
			if (_map.find(s) == _map.end()) {
				_map[s] = p++;
			}
			if (_map.find(s1) == _map.end()) {
				_map[s1] = p++;
			}
			cout << unionParent(_map[s], _map[s1]) << '\n';
		}
	}
	return 0;
}