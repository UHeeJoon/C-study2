#include <iostream>
#include <cctype>   //isupper�� �������� �������
#include <string>   

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);        // ����� �ð� ���

    string s;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        cin >> s;

        for (int i = 0; i < s.length(); i++) {
            if (isupper(s[i])) {      //isupper : �빮�� �Ǻ�
                s[i] = tolower(s[i]); //���ڿ��� �빮�ڰ� ������ tolower:�ҹ��ڷ� �ٲ��
            }

            //�ݴ�
            /*if(islower(s[i])){
                s[i]=toupper(s[i]);
            }*/
        }
        cout << s << "\n";
    }
}
