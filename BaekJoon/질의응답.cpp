#pragma warning(disable :4996)
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	int pos; //���� ��ġ�� �޴� ����
	for (int i = 'a'; i <= 'z'; i++)
	{

		pos = (int)s.find(i); //s��� ���ڿ����� i�� �ش��ϴ� ���ڰ� ���°�� �ִ��� �˷��ִ� �Լ�+ ������ ��: ���� i�� �ƽ�Ű�ڵ�'a'�� ǥ���ؾ���. ? abc�Է��ϸ� ���ڿ��� a�� �״�� a�ΰ� �ƴ϶� ����'a'�ΰ���?
		cout << pos << " ";
	}
	return 0;
}