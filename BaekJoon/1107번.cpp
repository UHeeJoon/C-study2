#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	char button[11]; // find�Լ��� ���� ���ؼ� char�� �Էƹ���
	bool channels[1000002];//ä���� ������ִ��� ����
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> button[i];
	}
	string num;
	int result = 99999999;
	int result2 = 99999999;
	if (n != 100) {
		for (int i = 0; i < 1000001; i++) {
			channels[i] = true;
			num = to_string(i);//ä���� string���� �ٲ� (�񱳸� ���ؼ�)
			for (int j = 0; j < m; j++) {
				if (num.find(button[j]) != std::string::npos) {
					channels[i] = false;
					break;
				}//find �Լ��� ���� ���峭 ��ư�� ���Ե� ��� false
			}
		}
		channels[100] = true;//ä�� 100���� �����ϱ� ������ true

		//��ǥ ä�η� ���� ��ư���� ���� �� �ִ� ���� ����� ä���� ã��
		for (int i = n; i >= 0; i--) { // n���� ���� ä�ο��� Ž��
			if (channels[i]) {
				result = i;
				break;
			}
		}
		for (int i = n; i < n + abs(n - 100); i++) {
			if (channels[i]) {
				result2 = i;
				break;
			} // n���� ū ä�ο��� Ž��
		}

		//�� ä�� ��
		int first = abs(result - n) + (to_string(result).length());
		// ���� ä�α��� ���µ� �������ϴ� ��
		// + or - ��ư ������ �� + ���� ��ư ������ ��

		int second = abs(result2 - n) + (to_string(result2).length());
		// ū ä�α��� ���µ� �������ϴ� ��

		int third = abs(100 - n);
		//ä�� 100������ �׳� + or - �������� ������ ���� ��

		//���Ͽ� �ּ� ���� ã�� ��
		if (first <= second) {
			if (first < third) {
				cout << first;
			}
			else {
				cout << third;
			}
		}
		else if (first > second) {
			if (second < third) {
				cout << second;
			}
			else {
				cout << third;
			}
		}
	}
	else {
		cout << 0;
	}