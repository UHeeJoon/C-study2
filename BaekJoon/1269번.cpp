#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;

    cin >> A >> B;

    vector<int> intersection;
    vector<int> v1(A);
    vector<int> v2(B);

    for (int i = 0; i < A; i++)
        cin >> v1[i];

    for (int i = 0; i < B; i++)
        cin >> v2[i];

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(intersection));

    cout << A + B - intersection.size() * 2;
}

/*
#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include <bits/stdc++.h>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> va(n);
	for (auto& c : va)
		cin >> c;

	vector<int> vb(m);
	for (auto& c : vb)
		cin >> c;

	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	int counter = 0;
	int p1 = 0, p2 = 0;

	while (p1 < n && p2 < m) {
		if (va[p1] == vb[p2]) {
			++p1, ++p2;
			++counter;
		}
		else if (va[p1] < vb[p2]) {
			++p1;
		}
		else {
			++p2;
		}
	}

	cout << (n+m) - 2*counter << '\n';

	return 0;
}
*/