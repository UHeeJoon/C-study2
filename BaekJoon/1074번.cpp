#include <bits/stdc++.h>
using namespace std;
int Z(int sz, int x, int y) {
    if (sz == 1) return 0;
    sz /= 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (x < sz * (i + 1) and y < sz * (j + 1)) {
                return (i * 2 + j) * sz * sz + Z(sz, x - sz * i, y - sz * j);
            }
        }
    }
    return 0; // ���� ����
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, r, c; cin >> N >> r >> c;
    // shift �������� 2^N�� 1 << Nó�� ��� ���� (�ڷ��� ���� ������)
    cout << Z(1 << N, r, c);
}