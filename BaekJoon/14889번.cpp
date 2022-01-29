#include<iostream>
#include<cmath>
using namespace std;
int N, _min = 987654321;
int start_link[21][21];
bool check[22];
void dfs(int x, int cnt) {
	if (x == N / 2){
		int start = 0, link = 0;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (check[i] == true && check[j] == true) start += start_link[i][j];
				if (check[i] == false && check[j] == false) { 
					link += start_link[i][j];
				}
			}
		}
		int temp = abs(start - link);
		if (_min > temp) _min = temp;
		return;
	}

	for (int i = cnt; i < N; i++){
		check[i] = true;
		dfs(x + 1, i + 1);
		check[i] = false;
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> start_link[i][j];
	dfs(0, 0);
	cout << _min << "\n";
}