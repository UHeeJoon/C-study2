#include<bits/stdc++.h>
using namespace std;
#define MAX 2188
int _map[MAX][MAX];
int o, z, m;
void dfs(int y, int x, int size) {
	bool one = true, zero = true, minus = true;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (_map[i][j] == 1) zero = minus = false;
			if (_map[i][j] == 0) one = minus = false;
			if (_map[i][j] == -1) zero = one = false;
		}
	}
	if (one) {
		o++;
		return;
	}
	if (zero) {
		z++;
		return;
	}
	if (minus) {
		m++;
		return;
	}
	dfs(y, x, size / 3);
	dfs(y, x + size / 3, size / 3);
	dfs(y, x + size / 3 + size / 3, size / 3);


	dfs(y + size / 3, x, size / 3);
	dfs(y + size / 3, x + size / 3, size / 3);
	dfs(y + size / 3, x + size / 3 + size / 3, size / 3);

	dfs(y + size / 3 + size / 3, x, size / 3);
	dfs(y + size / 3 + size / 3, x + size / 3, size / 3);
	dfs(y + size / 3 + size / 3, x + size / 3 + size / 3, size / 3);
}
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> _map[i][j];
	dfs(0, 0, n);
	cout << m << '\n' << z << '\n' << o << '\n';
	return 0;
}
/*
#include <iostream>
#include <vector>
using namespace std;

int mo, z, po;

void chk(vector<vector<short>>& v, int r, int c, int s)
{
    bool succ = true;
    short init;
    if (s < 2)
    {
        if (v[r][c] == -1)
            mo++;
        else if (v[r][c] == 0)
            z++;
        else
            po++;
        return;
    }

    init = v[r][c];
    for (int i = r; i < r+s; i++)
    {
        for (int j = c; j < c+s; j++)
        {
            if (v[i][j] != init)
            {
                succ = false;
                break;
            }
        }
        if (!succ)
            break;
    }
    if (succ)
    {
        if (v[r][c] == -1)
            mo++;
        else if (v[r][c] == 0)
            z++;
        else
            po++;
    }
    else
    {
        chk(v, r, c, s/3);
        chk(v, r, c + s/3, s/3);
        chk(v, r, c + s/3*2, s/3);
        chk(v, r + s/3, c, s/3);
        chk(v, r + s/3, c + s/3, s/3);
        chk(v, r + s/3, c + s/3*2, s/3);
        chk(v, r + s/3*2, c, s/3);
        chk(v, r + s/3*2, c + s/3, s/3);
        chk(v, r + s/3*2, c + s/3*2, s/3);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    short inp;
    vector<vector<short>> paper;
    cin >> N;
    paper.assign(N, vector<short>(N, 0));
    mo = z = po = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> inp;
            paper[i][j] = inp;
        }
    }
    chk(paper, 0, 0, N);
    cout << mo << '\n' << z << '\n' << po;
    return 0;
}
*/