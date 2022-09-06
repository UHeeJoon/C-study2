#include<bits/stdc++.h>
using namespace std;
#define MAX 1'000'010
//#define INF 60'000'000'000
#define MOD 1'000'000'007
typedef long long ll;
int N, M, K;
vector<ll> arr;
vector<ll> segment_tree;

ll init(int left, int right, int node) {
	if (left == right)
		return segment_tree[node] = arr[left];

	int mid = (left + right) / 2;
	segment_tree[node] = (init(left, mid, node * 2) * init(mid + 1, right, node * 2 + 1)) % MOD;
	return segment_tree[node];
}

ll update(int left, int right, int node, int idx, ll num) {
	if (right < idx || idx < left)
		return segment_tree[node];  //변화 x의 값을 반환

	if (left == right) {  //== idx인 경우
		return segment_tree[node] = num;
	}

	int mid = (left + right) / 2;
	segment_tree[node] = (update(left, mid, node * 2, idx, num) * update(mid + 1, right, node * 2 + 1, idx, num)) % MOD;
	return segment_tree[node];
}

ll query(int left, int right, int query_left, int query_right, int node) {

	if (right < query_left || query_right < left)
		return 1;

	if (query_left <= left && right <= query_right)
		return segment_tree[node];
	//else

	int mid = (left + right) / 2;
	return (query(left, mid, query_left, query_right, node * 2) * query(mid + 1, right, query_left, query_right, node * 2 + 1)) % MOD;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	arr = vector<ll>(N + 1);
	int tree_height = (int)ceil(log2(N));
	segment_tree = vector<ll>(1 << (tree_height + 1));
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	init(1, N, 1);
	M += K;
	int a, b, c;
	while (M--) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, N, 1, b, c);
		}
		else {
			cout << query(1, N, b, c, 1) << '\n';
		}
	}
	return 0;
}