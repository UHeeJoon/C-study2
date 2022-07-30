#include<bits/stdc++.h>
using namespace std;
int palin(int i, int j, int cnt, string s) {
	while (i < j) {
		if (s[i] != s[j]) {
			if (!cnt) {
				if (palin(i + 1, j, 1, s) == 0 || palin(i, j - 1, 1, s) == 0)return 1;
				return 2;
			}
			else return 2;
		}
		else {
			i++; j--;
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int i = 0, j = (int)s.length() - 1;
		cout << palin(i, j, 0, s) << '\n';
	}
	return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
enum {
	PALINDROME = 0,
	SEMI_PALINDROME,
	NOT_PALINDROME
};
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++){
		string s;
		cin >> s;
		int result = PALINDROME;
		for (int i = 0, j = s.length() - 1; i < j; i++, j--){
			if (s[i] == s[j]) continue;
			// 문자 하나를 삭제해도 팰린드롬이 아닐 경우
			if (s[i + 1] != s[j] && s[i] != s[j - 1]){
				result = NOT_PALINDROME;
				break;
			}
			bool isPalindrome = false;
			// 하나 삭제한 뒤 팰린드롬인지 판별
			for (int k = 0; k < 2 && isPalindrome == false; k++){
				int start = i;
				int end = j;
				k == 0 ? start++ : end--;
				isPalindrome = true;
				for (int a = start, b = end; a < b; a++, b--){
					if (s[a] != s[b]){
						isPalindrome = false;
						break;
					}
				}
			}
			result = isPalindrome ? SEMI_PALINDROME : NOT_PALINDROME;
			break;
		}
		cout << result << "\n";
	}
	return 0;
}
*/