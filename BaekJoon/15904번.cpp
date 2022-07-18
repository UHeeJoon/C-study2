#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	string str = "";
	getline(cin, str); //공백이 있는 문장을 입력받기 위함

		//문제 풀이
	int n1, n2, n3, n4; //각 문자의 위치

	n1 = str.find('U');
	n2 = str.find('C', n1);
	n3 = str.find('P', n2);
	n4 = str.find('C', n3);

	//결과 출력
	if (n1 == -1 || n2 == -1 || n3 == -1 || n4 == -1) {
		cout << "I hate UCPC";
	}
	else {
		cout << "I love UCPC";
	}

}