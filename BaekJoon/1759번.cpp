#include<bits/stdc++.h>
using namespace std;
char cha[20];
char cha2[20];
bool visited[20];
int l, c;
void dfs(int tmp, int cnt) {
	if (cnt == l) {
		int con = 0, vow = 0;
		for (int i = 0; i < l; i++) {
			if (cha2[i] == 'a' || cha2[i] == 'e' || cha2[i] == 'i' || cha2[i] == 'o' || cha2[i] == 'u')
				vow++;
			else con++;
		}
		if (vow > 0 && con > 1) {
			for (int i = 0; i < l; i++) {
				cout << cha2[i];
			}
			cout << '\n';
		}
		return;
	}
	for (int i = tmp; i < c; i++) {
		if (!visited[i]) {
			visited[i] = true;
			cha2[cnt] = cha[i];
			dfs(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> cha[i];
	sort(cha, cha + c);
	dfs(0, 0);
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int l, c; 
vector<char> vec;
int vowel, consonant;
bool check[15];
void func(int cnt, string s, int idx){
	if(cnt == l && vowel >=1 && consonant >=2){
		cout << s << '\n';
	}
	for(int i=0;i<c;i++){
		if(check[i]) continue;
		if(i<idx)continue;
		check[i] = true;
		if(vec[i] == 'a' || vec[i] == 'e' || vec[i] == 'i' || vec[i] == 'o' || vec[i] == 'u'){
			vowel++;
			func(cnt+1, s+vec[i], i);
			vowel--;
			check[i] = false;
		}
		else{
			consonant++;
			func(cnt+1, s+vec[i], i);
			consonant--;
			check[i] = false;
		}
	}	
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> l >> c;
	for(int i=0;i<c;i++){
		char ch;
		cin >>ch;
		vec.push_back(ch);
	}
	sor(vec.begin(), vec.end());
	func(0,"",0);
	return 0;
}
*/