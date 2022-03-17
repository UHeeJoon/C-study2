#pragma warning(disable :4996)
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	int pos; //시작 위치를 받는 변수
	for (int i = 'a'; i <= 'z'; i++)
	{

		pos = (int)s.find(i); //s라는 문자열에서 i에 해당하는 문자가 몇번째에 있는지 알려주는 함수+ 주의할 점: 위에 i를 아스키코드'a'로 표현해야함. ? abc입력하면 문자열에 a는 그대로 a인게 아니라 숫자'a'인것임?
		cout << pos << " ";
	}
	return 0;
}