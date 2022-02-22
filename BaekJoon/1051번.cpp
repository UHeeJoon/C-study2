#include<iostream>
#include<string>
using namespace std;
int n, m;
string square[51];
void check(int& tmp) {
	if (tmp == 0) return;
	for (int i = 0; i < n - tmp; i++) {
		for (int j = 0; j < m - tmp; j++) {
			if (square[i][j] == square[i + tmp][j] && square[i][j + tmp] == square[i + tmp][j + tmp] && square[i][j + tmp] == square[i + tmp][j])
				return;
		}
	}
	tmp -= 1;
	check(tmp);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> square[i];
	int tmp = n < m ? n - 1 : m - 1;
	check(tmp);
	cout << (tmp + 1) * (tmp + 1) << "\n";
}