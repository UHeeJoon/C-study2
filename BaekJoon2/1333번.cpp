#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> music; //�뷡�� ����Ǵ� ������ ���ͷ� ǥ��
	int N, L, D; //N�� �ٹ��� ���ϵ� �뷡 ��, L�� �뷡�� ����, D�� ���Ҹ� ����
	int bell = 0; //���Ҹ��� 0�ʿ��� ����

	cin >> N >> L >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < L; j++) { //�뷡�� ����Ǵ� ������
			music.push_back(1); //1�� ���Ϳ� ����
		}
		for (int j = 0; j < 5; j++) { //�뷡�� ������� �ʴ� ������
			music.push_back(0); //0�� ���Ϳ� ����
		}
	}

	while (1) {
		if (bell > music.size()) { //�뷡�� ���� �� ���Ҹ��� ����Ǹ�
			break; //Ż��
		}
		if (music[bell] == 0) { //�뷡������ ���ݿ� ���Ҹ��� �︮��
			break; //Ż��
		}
		else { //���Ҹ��� D�� �������� �︰��. ���Ҹ��� �︮�� ������ 1��
			bell = bell + D;
		}
	}
	cout << bell << '\n';
	return 0;
}
