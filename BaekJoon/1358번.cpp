#include<bits/stdc++.h>
using namespace std;
double W, H, X, Y, P;

bool Square(double x, double y) { // �簢�� W * H �ȿ� ��������
	if (x >= X && x <= X + W && y >= Y && y <= Y + H) return true;
	return false;
}

double Dist(double a1, double b1, double a2, double b2) { // ���� ���� �Ÿ�
	return sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
}

bool Circle(double x, double y) { // �簢�� �� �� �ݿ� �ȿ� ��������
	// �߽� (X, Y+H/2), ������ Y/2 ���� (x,y)�� ��������
	if (Dist(X, Y + H / 2, x, y) <= H / 2) return true;
	// �߽� (X+W, Y+H/2), ������ Y/2 ���� (x,y)�� ��������
	if (Dist(X + W, Y + H / 2, x, y) <= H / 2) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> W >> H >> X >> Y >> P;
	int ans = 0;
	for (int i = 0; i < P; ++i) {
		double x, y;
		cin >> x >> y;
		if (Square(x, y)) ans++;
		else if (Circle(x, y)) ans++;
	}
	cout << ans << '\n';
	return 0;
}