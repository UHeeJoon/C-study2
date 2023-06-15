#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
    FAST_IO;
    int test;
    cin >> test;
    cin.ignore();

    for (int i = 0; i < test; i++) {
        string str;
        getline(cin, str);

        vector<string> vec;

        stringstream ss(str); // 공백 기준으로 문자열을 짜른다.

        string word;
        while (ss >> word) {
            vec.push_back(word);
        }

        for (vector<string>::size_type j = 2; j < vec.size(); j++) {
            cout << vec[j] << " ";
        }
        cout << vec[0] << " " << vec[1] << "\n";
    }
    return 0;
}