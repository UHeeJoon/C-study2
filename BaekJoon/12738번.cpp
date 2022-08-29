#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
#define INF 2147483647
int n, lis[MAX], len, num;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num);
        if (*lowerPos == 0) len++;
        *lowerPos = num;
    }
    cout << len << '\n';
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using pr = pair<int, int>;

int query(vector<int> &seg, int v, int l, int r, int from, int to)
{
	if (to < l || r < from)
		return 0;

	if (from <= l && r <= to)
		return seg[v];

	return max(
		query(seg, 2*v, l, (l+r)/2, from, to),
		query(seg, 2*v+1, (l+r)/2+1, r, from, to)
	);
}

void update(vector<int> &seg, int v, int l, int r, int target, int val)
{
	if (l == r)
	{
		seg[v] = val;
	}
	else
	{
		int mid = (l+r)/2;

		if (target <= mid)
			update(seg, 2*v, l, mid, target, val);
		else
			update(seg, 2*v+1, mid+1, r, target, val);

		seg[v] = max(seg[2*v], seg[2*v+1]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int n;
	cin >> n;

	vector<pr> vt(n);
	vector<int> seg(1 << ((int)ceil(log2(n))+1));

	for (int i=0; i<n; i++)
	{
		cin >> vt[i].first;
		vt[i].second = i;
	}

	sort(vt.begin(), vt.end(), [](pr &l, pr &r) -> bool {
		if (l.first != r.first)	return l.first < r.first;
		return l.second > r.second;
	});

	for (int i=0; i<n; i++)
	{
		int v = query(seg, 1, 0, n-1, 0, vt[i].second) + 1;
		update(seg, 1, 0, n-1, vt[i].second, v);
	}

	cout << seg[1];
}
*/



/*
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_SIZE 1000001
using namespace std;

int n;
int arr[MAX_SIZE];
vector<int> indexList;

int get_idx(int target) {
	int l = 0;
	int r = (int)indexList.size() - 1;

	while (l < r) {
		int mid = (l + r) / 2;

		if (indexList[mid] < target) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return (indexList[r] < target) ? r + 1 : r;
}

int LIS() {
	for (int i = 0; i < n; i++) {
		if (i == 0 || indexList.back() < arr[i]) {
			indexList.push_back(arr[i]);
		}
		else {
			int idx = get_idx(arr[i]);
			indexList[idx] = arr[i];
		}
	}
	return (int)indexList.size();
}

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

int main() {
	fastio;

	init();
	cout << LIS();
}
*/