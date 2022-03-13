#pragma warning(disable :4996)
#include<bits/stdc++.h>
using namespace std;
int snail[1010][1010];
int n, m, row, col;
void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << snail[i][j] << " ";
		}
		cout << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
	cin >> n >> m;
	int value = n * n, y = -1, x = 0, inc = 1;
	int tmp = n;
	while (tmp > 0) {
		for (int i = 0; i < tmp; i++) {
			y += inc;
			snail[y][x] = value;
			if (snail[y][x] == m)
				row = y, col = x;
			value--;
		}
		tmp--;
		if (tmp == 0) break;
		for (int i = 0; i < tmp; i++) {
			x += inc;
			snail[y][x] = value;
			if (snail[y][x] == m)
				row = y, col = x;
			value--;
		}
		inc *= -1;
	}
	Print();
	cout << row + 1 << " " << col + 1 << '\n';
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int a[1001][1001], n, m, dir, rety, retx, y, x;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int main() {
	cin >> n >> m;
	for(int i = n * n; i > 0; i--){
		a[y][x] = i;
		if(i == m){rety = y + 1; retx = x + 1;}
		if(y + dy[dir] < 0 || y + dy[dir] >= n || x + dx[dir] < 0 || x + dx[dir] >= n || a[y + dy[dir]][x + dx[dir]] != 0){
			dir = (dir + 1) % 4;
		}
		y = y + dy[dir];
		x = x + dx[dir];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout <<"\n";
	}
	cout << rety << " " << retx << "\n";
	return 0;
}
*/