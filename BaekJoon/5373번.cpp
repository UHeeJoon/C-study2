#include<bits/stdc++.h>
using namespace std;
#define MAX 1010
#define INF 2147483647
char cube[8][4][4];
void init() {
	for (int i = 0; i < 6; i++) {
		char color = 0;
		switch (i) {
		case 0:color = 'w'; break; // À­¸é
		case 1:color = 'o'; break; // µÞ¸é
		case 2:color = 'b'; break; // ¿À¸¥ÂÊ ¸é
		case 3:color = 'r'; break; // ¾Õ¸é
		case 4:color = 'g'; break; // ¿ÞÂÊ ¸é
		case 5:color = 'y'; break; // ¾Æ·§¸é
		}
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cube[i][j][k] = color;
			}
		}
	}
	return;
}
void turn(int side, char direct) {
	if (direct == '+') {
		swap(cube[side][0][0], cube[side][0][2]);
		swap(cube[side][0][0], cube[side][2][2]);
		swap(cube[side][0][0], cube[side][2][0]);

		swap(cube[side][0][1], cube[side][1][2]);
		swap(cube[side][0][1], cube[side][2][1]);
		swap(cube[side][0][1], cube[side][1][0]);
	}
	else {
		swap(cube[side][0][0], cube[side][2][0]);
		swap(cube[side][0][0], cube[side][2][2]);
		swap(cube[side][0][0], cube[side][0][2]);

		swap(cube[side][0][1], cube[side][1][0]);
		swap(cube[side][0][1], cube[side][2][1]);
		swap(cube[side][0][1], cube[side][1][2]);
	}
}
void up(char direct) {
	int dir = direct == '+' ? 1 : -1;
	int idx = dir == 1 ? 2 : 4;
	while (2 <= idx && idx <= 4) {
		swap(cube[1][0][0], cube[idx][0][0]);
		swap(cube[1][0][1], cube[idx][0][1]);
		swap(cube[1][0][2], cube[idx][0][2]);
		idx += dir;
	}
	turn(0, direct);
}
void down(char direct) {
	int dir = direct == '+' ? -1 : 1;
	int idx = dir == 1 ? 2 : 4;
	while (2 <= idx && idx <= 4) {
		swap(cube[1][2][0], cube[idx][2][0]);
		swap(cube[1][2][1], cube[idx][2][1]);
		swap(cube[1][2][2], cube[idx][2][2]);
		idx += dir;
	}
	turn(5, direct);
}
void front(char direct) {
	//0 2 5 4
	if (direct == '+') {
		swap(cube[0][2][0], cube[2][0][0]);
		swap(cube[0][2][1], cube[2][1][0]);
		swap(cube[0][2][2], cube[2][2][0]);

		swap(cube[0][2][0], cube[5][2][0]);
		swap(cube[0][2][1], cube[5][2][1]);
		swap(cube[0][2][2], cube[5][2][2]);

		swap(cube[0][2][0], cube[4][2][2]);
		swap(cube[0][2][1], cube[4][1][2]);
		swap(cube[0][2][2], cube[4][0][2]);
	}
	// 0 4 5 2
	else {
		swap(cube[0][2][0], cube[4][2][2]);
		swap(cube[0][2][1], cube[4][1][2]);
		swap(cube[0][2][2], cube[4][0][2]);

		swap(cube[0][2][0], cube[5][2][0]);
		swap(cube[0][2][1], cube[5][2][1]);
		swap(cube[0][2][2], cube[5][2][2]);

		swap(cube[0][2][0], cube[2][0][0]);
		swap(cube[0][2][1], cube[2][1][0]);
		swap(cube[0][2][2], cube[2][2][0]);

	}
	turn(3, direct);

}
void back(char direct) {
	//0 4 5 2
	if (direct == '+') {
		swap(cube[0][0][0], cube[4][2][0]);
		swap(cube[0][0][1], cube[4][1][0]);
		swap(cube[0][0][2], cube[4][0][0]);

		swap(cube[0][0][0], cube[5][0][0]);
		swap(cube[0][0][1], cube[5][0][1]);
		swap(cube[0][0][2], cube[5][0][2]);

		swap(cube[0][0][0], cube[2][0][2]);
		swap(cube[0][0][1], cube[2][1][2]);
		swap(cube[0][0][2], cube[2][2][2]);
	}
	// 0 2 5 4
	else {
		swap(cube[0][0][0], cube[2][0][2]);
		swap(cube[0][0][1], cube[2][1][2]);
		swap(cube[0][0][2], cube[2][2][2]);

		swap(cube[0][0][0], cube[5][0][0]);
		swap(cube[0][0][1], cube[5][0][1]);
		swap(cube[0][0][2], cube[5][0][2]);

		swap(cube[0][0][0], cube[4][2][0]);
		swap(cube[0][0][1], cube[4][1][0]);
		swap(cube[0][0][2], cube[4][0][0]);

	}
	turn(1, direct);

}
void left(char direct) {
	//0 3 5 1
	if (direct == '+') {
		swap(cube[0][0][0], cube[3][0][0]);
		swap(cube[0][1][0], cube[3][1][0]);
		swap(cube[0][2][0], cube[3][2][0]);

		swap(cube[0][0][0], cube[5][2][2]);
		swap(cube[0][1][0], cube[5][1][2]);
		swap(cube[0][2][0], cube[5][0][2]);

		swap(cube[0][0][0], cube[1][2][2]);
		swap(cube[0][1][0], cube[1][1][2]);
		swap(cube[0][2][0], cube[1][0][2]);

	}
	// 0 1 5 3
	else {
		swap(cube[0][0][0], cube[1][2][2]);
		swap(cube[0][1][0], cube[1][1][2]);
		swap(cube[0][2][0], cube[1][0][2]);

		swap(cube[0][0][0], cube[5][2][2]);
		swap(cube[0][1][0], cube[5][1][2]);
		swap(cube[0][2][0], cube[5][0][2]);

		swap(cube[0][0][0], cube[3][0][0]);
		swap(cube[0][1][0], cube[3][1][0]);
		swap(cube[0][2][0], cube[3][2][0]);

	}
	turn(4, direct);

}
void right(char direct) {
	// 0 1 5 3
	if (direct == '+') {
		swap(cube[0][0][2], cube[1][2][0]);
		swap(cube[0][1][2], cube[1][1][0]);
		swap(cube[0][2][2], cube[1][0][0]);

		swap(cube[0][0][2], cube[5][2][0]);
		swap(cube[0][1][2], cube[5][1][0]);
		swap(cube[0][2][2], cube[5][0][0]);

		swap(cube[0][0][2], cube[3][0][2]);
		swap(cube[0][1][2], cube[3][1][2]);
		swap(cube[0][2][2], cube[3][2][2]);

	}
	else {
		//0 3 5 1
		swap(cube[0][0][2], cube[3][0][2]);
		swap(cube[0][1][2], cube[3][1][2]);
		swap(cube[0][2][2], cube[3][2][2]);

		swap(cube[0][0][2], cube[5][2][0]);
		swap(cube[0][1][2], cube[5][1][0]);
		swap(cube[0][2][2], cube[5][0][0]);

		swap(cube[0][0][2], cube[1][2][0]);
		swap(cube[0][1][2], cube[1][1][0]);
		swap(cube[0][2][2], cube[1][0][0]);
	}
	turn(2, direct);
}

void printCubeTopSide() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << cube[0][i][j];
		cout << '\n';
	}
}
void print() {
	for (int i = 0; i < 6; i++) {
		switch (i) {
		case 0:cout << "À­¸é\n"; break; // À­¸é
		case 1:cout << "µÞ¸é\n"; break; // µÞ¸é
		case 2:cout << "¿À¸¥ÂÊ ¸é\n"; break; // ¿À¸¥ÂÊ ¸é
		case 3:cout << "¾Õ¸é ¸é\n"; break; // ¾Õ¸é
		case 4:cout << "¿ÞÂÊ ¸é\n"; break; // ¿ÞÂÊ ¸é
		case 5:cout << "¾Æ·§¸é\n"; break; // ¾Æ·§¸é
		}
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cout << cube[i][j][k];
			}
			cout << '\n';
		}
		cout << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while (tc--) {
		init();
		int n; cin >> n;
		while (n--) {
			char sides(0), direct(0);
			cin >> sides >> direct;
			switch (sides) {
			case 'U': up(direct); break;
			case 'D': down(direct); break;
			case 'F': front(direct); break;
			case 'B': back(direct); break;
			case 'L': left(direct); break;
			case 'R': right(direct); break;
			}
		}
		//print();
		printCubeTopSide();
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define MAX 1010
#define INF 2147483647
char cube[8][4][4];
void init() {
	for (int i = 0; i < 6; i++) {
		char color = 0;
		switch (i) {
		case 0:color = 'w'; break; // À­¸é
		case 1:color = 'o'; break; // µÞ¸é
		case 2:color = 'b'; break; // ¿À¸¥ÂÊ ¸é
		case 3:color = 'r'; break; // ¾Õ¸é
		case 4:color = 'g'; break; // ¿ÞÂÊ ¸é
		case 5:color = 'y'; break; // ¾Æ·§¸é
		}
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cube[i][j][k] = color;
			}
		}
	}
	return;
}
void turn(int side, char direct) {
	if (direct == '+') {
		swap(cube[side][0][0], cube[side][0][2]);
		swap(cube[side][0][0], cube[side][2][2]);
		swap(cube[side][0][0], cube[side][2][0]);

		swap(cube[side][0][1], cube[side][1][2]);
		swap(cube[side][0][1], cube[side][2][1]);
		swap(cube[side][0][1], cube[side][1][0]);
	}
	else {
		swap(cube[side][0][0], cube[side][2][0]);
		swap(cube[side][0][0], cube[side][2][2]);
		swap(cube[side][0][0], cube[side][0][2]);

		swap(cube[side][0][1], cube[side][1][0]);
		swap(cube[side][0][1], cube[side][2][1]);
		swap(cube[side][0][1], cube[side][1][2]);
	}
}
void upNdown(char sides, char direct) {
	int dir = direct == '+' ? 1 : -1;
	if (sides == 'D') dir *= -1;
	int idx = dir == 1 ? 2 : 4;
	int upDown = sides == 'U' ? 0 : 2;
	while (2 <= idx && idx <= 4) {

		swap(cube[1][upDown][0], cube[idx][upDown][0]);
		swap(cube[1][upDown][1], cube[idx][upDown][1]);
		swap(cube[1][upDown][2], cube[idx][upDown][2]);
		idx += dir;
	}
	turn(sides == 'U' ? 0 : 5 , direct);
}
void frontNback(char sides, char direct) {
	int front = sides == 'F' ? 2 : 0;
	//0 2 5 4
	if (sides == 'F' && direct == '+' || sides == 'B' && direct == '-') {
		swap(cube[0][front][0], cube[2][0][front == 2 ? 0 : 2]);
		swap(cube[0][front][1], cube[2][1][front == 2 ? 0 : 2]);
		swap(cube[0][front][2], cube[2][2][front == 2 ? 0 : 2]);

		swap(cube[0][front][0], cube[5][front][0]);
		swap(cube[0][front][1], cube[5][front][1]);
		swap(cube[0][front][2], cube[5][front][2]);

		swap(cube[0][front][0], cube[4][2][front]);
		swap(cube[0][front][1], cube[4][1][front]);
		swap(cube[0][front][2], cube[4][0][front]);
	}
	// 0 4 5 2
	else {
		swap(cube[0][front][0], cube[4][2][front]);
		swap(cube[0][front][1], cube[4][1][front]);
		swap(cube[0][front][2], cube[4][0][front]);

		swap(cube[0][front][0], cube[5][front][0]);
		swap(cube[0][front][1], cube[5][front][1]);
		swap(cube[0][front][2], cube[5][front][2]);

		swap(cube[0][front][0], cube[2][0][front == 2 ? 0 : 2]);
		swap(cube[0][front][1], cube[2][1][front == 2 ? 0 : 2]);
		swap(cube[0][front][2], cube[2][2][front == 2 ? 0 : 2]);

	}
	turn(sides == 'F' ? 3 : 1, direct);

}
void leftNright(char sides, char direct) {
	int left = sides == 'L' ? 0 : 2;
	//0 3 5 1
	if (sides == 'L' && direct == '+' || sides=='R' && direct == '-') {
		swap(cube[0][0][left], cube[3][0][left]);
		swap(cube[0][1][left], cube[3][1][left]);
		swap(cube[0][2][left], cube[3][2][left]);

		swap(cube[0][0][left], cube[5][2][left == 0 ? 2 : 0 ]);
		swap(cube[0][1][left], cube[5][1][left == 0 ? 2 : 0]);
		swap(cube[0][2][left], cube[5][0][left == 0 ? 2 : 0]);

		swap(cube[0][0][left], cube[1][2][left == 0 ? 2 : 0]);
		swap(cube[0][1][left], cube[1][1][left == 0 ? 2 : 0]);
		swap(cube[0][2][left], cube[1][0][left == 0 ? 2 : 0]);

	}
	// 0 1 5 3
	else {
		swap(cube[0][0][left], cube[1][2][left == 0 ? 2 : 0]);
		swap(cube[0][1][left], cube[1][1][left == 0 ? 2 : 0]);
		swap(cube[0][2][left], cube[1][0][left == 0 ? 2 : 0]);

		swap(cube[0][0][left], cube[5][2][left == 0 ? 2 : 0]);
		swap(cube[0][1][left], cube[5][1][left == 0 ? 2 : 0]);
		swap(cube[0][2][left], cube[5][0][left == 0 ? 2 : 0]);

		swap(cube[0][0][left], cube[3][0][left]);
		swap(cube[0][1][left], cube[3][1][left]);
		swap(cube[0][2][left], cube[3][2][left]);
	}
	turn(sides == 'L' ? 4 : 2, direct);

}
void printCubeTopSide() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << cube[0][i][j];
		cout << '\n';
	}
}
//void print() {
//	for (int i = 0; i < 6; i++) {
//		switch (i) {
//		case 0:cout << "À­¸é\n"; break; // À­¸é
//		case 1:cout << "µÞ¸é\n"; break; // µÞ¸é
//		case 2:cout << "¿À¸¥ÂÊ ¸é\n"; break; // ¿À¸¥ÂÊ ¸é
//		case 3:cout << "¾Õ¸é ¸é\n"; break; // ¾Õ¸é
//		case 4:cout << "¿ÞÂÊ ¸é\n"; break; // ¿ÞÂÊ ¸é
//		case 5:cout << "¾Æ·§¸é\n"; break; // ¾Æ·§¸é
//		}
//		for (int j = 0; j < 3; j++) {
//			for (int k = 0; k < 3; k++) {
//				cout << cube[i][j][k];
//			}
//			cout << '\n';
//		}
//		cout << '\n';
//	}
//}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while (tc--) {
		init();
		int n; cin >> n;
		while (n--) {
			char sides(0), direct(0);
			cin >> sides >> direct;
			switch (sides) {
			case 'U': case 'D': upNdown(sides, direct); break;
			case 'F': case 'B': frontNback(sides, direct); break;
			case 'L': case 'R': leftNright(sides, direct); break;
			}
		}
		//print();
		 printCubeTopSide();
	}
	return 0;
}
*/




/*
#include <bits/stdc++.h>
using namespace std;
int node[74], T, n, d, e;
int a[6][20] = {
	{0, 2, 8, 6, 1, 5, 7, 3, 51, 31, 41, 21, 50, 30, 40, 20, 52, 32, 42, 22},
	{10, 12, 18, 16, 11, 15, 17, 13, 56, 26, 46, 36, 57, 27, 47, 37, 58, 28, 48, 38},
	{20, 22, 28, 26, 21, 25, 27, 23, 0, 40, 18, 58, 3, 43, 15, 55, 6, 46, 12, 52},
	{30, 32, 38, 36, 31, 35, 37, 33, 8, 50, 10, 48, 5, 53, 13, 45, 2, 56, 16, 42},
	{40, 42, 48, 46, 41, 45, 47, 43, 6, 30, 16, 28, 7, 33, 17, 25, 8, 36, 18, 22},
	{50, 52, 58, 56, 51, 55, 57, 53, 2, 20, 12, 38, 1, 23, 11, 35, 0, 26, 10, 32}
};
char color[6] = {'w', 'y', 'g', 'b', 'r', 'o'}, _a, _b;
map<char, int> _map;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	_map['U'] = 0;
	_map['D'] = 1;
	_map['L'] = 2;
	_map['R'] = 3;
	_map['F'] = 4;
	_map['B'] = 5;
	cin >> T;
	while(T--){
		for(int i = 0; i < 60; i++){
			node[i] = i / 10;
		}
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> _a >> _b;
			int c = _map[_a];
			if(_b == '+'){d = 3; e = 1;}
			else {d = 1; e = 3;}
			for(int j = 0; j < 20; j+= 4){
				int temp = node[a[c][j]];
				node[a[c][j]] = node[a[c][j + d]];
				node[a[c][j + d]] = node[a[c][j + 2]];
				node[a[c][j + 2]] = node[a[c][j + e]];
				node[a[c][j + e]] = temp;
			}
		}
		for(int i = 0; i < 9; i++){
			cout << color[node[i]];
			if(i == 2 || i == 5 || i == 8) cout << "\n";
		}
	}
	return 0;
}
*/