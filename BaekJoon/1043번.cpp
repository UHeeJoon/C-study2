#include<bits/stdc++.h>
using namespace std;
int person[55];
bool visited[55];
int n, m;
int getParent(int child) {
	if (person[child] == child)return child;
	return person[child] = getParent(person[child]);
}
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b) person[a] = b;
	else person[b] = a;
}
bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	else return false;
}
void makeRelation(int personCnt, vector<int> person) {
	int _left = 0, _right = 1;
	while (_left < _right && _right < personCnt) {
		unionParent(person[_left], person[_right]);
		_left += 1;
		_right += 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		person[i] = i;
	}
	int knowPersonCnt; cin >> knowPersonCnt;
	vector<int> knowPerson(knowPersonCnt);
	for (int i = 0; i < knowPersonCnt; i++) {
		cin >> knowPerson[i];
	}
	makeRelation(knowPersonCnt, knowPerson);

	vector<vector<int>> partyPerson(m);
	for (int i = 0; i < m; i++) {
		int partyPersonCnt; cin >> partyPersonCnt;
		partyPerson[i].resize(partyPersonCnt);
		for (int j = 0; j < partyPersonCnt; j++)
			cin >> partyPerson[i][j];
		makeRelation(partyPersonCnt, partyPerson[i]);
	}
	if (knowPersonCnt == 0) cout << m << '\n';
	else {
		int ans = m;
		for (int knowperson : knowPerson) {
			for (int i = 0; i < m; i++) {
				if (!visited[i]) {
					for (int partyperson : partyPerson[i]) {
						if (findParent(knowperson, partyperson)) {
							visited[i] = true;
							ans -= 1;
							break;
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
#include <iostream>
using namespace std;
#define MAX_N 50

int par[MAX_N+1], per[MAX_N];

int find(int a) {
	if(par[a] == a) return a;
	return par[a] = find(par[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	par[a] = b;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, M; cin >> N >> M;
	for(int i=0;i<=N;++i) par[i] = i;
	int T; cin >> T;
	for(int i=0;i<T;++i) {
		int a; cin >> a;
		par[a] = 0;
	}
	for(int i=0;i<M;++i) {
		int P, o; cin >> P >> o;
		per[i] = o;
		for(int j=1;j<P;++j) {
			int a; cin >> a;
			merge(a, o);
		}
	}
	int ans = 0;
	for(int i=0;i<M;++i)
		if(find(0) != find(per[i])) ++ans;
	cout << ans;
	return 0;
}
*/

//#include <bits/stdc++.h>
//using namespace std;
//
//int n, m, t;
//int adj[55][55], p[55];
//vector<int> v[55];
//
//int vis[55];
//
//void dfs(int x) {
//	if (vis[x]) return;
//	vis[x] = 1;
//	for (int i = 1; i <= n; i++) if (adj[x][i]) dfs(i);
//}
//
//int main() {
//	scanf("%d %d %d", &n, &m, &t);
//	for (int i = 0; i < t; i++) cin >> p[i];
//	for (int i = 0; i < t; i++) {
//		for (int j = 0; j < i; j++) {
//			adj[p[i]][p[j]] = adj[p[j]][p[i]] = 1;
//		}
//	}
//	for (int i = 0; i < m; i++) {
//		int q;
//		cin >> q;
//		v[i].resize(q);
//		for (int j = 0; j < q; j++) {
//			cin >> v[i][j];
//			for (int k = 0; k < j; k++) {
//				adj[v[i][j]][v[i][k]] = 1;
//				adj[v[i][k]][v[i][j]] = 1;
//			}
//		}
//	}
//	dfs(p[0]);
//	int cnt = 0;
//	for (int i = 0; i < m; i++) {
//		if (!vis[v[i][0]]) cnt++;
//	}
//	printf("%d", cnt);
//}
