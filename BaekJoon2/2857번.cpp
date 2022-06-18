#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<string> str(5);
	vector<int> num;


	for (auto& c : str) {
		cin >> c;
	}

	for (int i = 0; i < 5; i++) {
		if (str[i].find("FBI") != string::npos) {
			num.push_back(i + 1);
		}
	}

	if (num.size() == 0) cout << "HE GOT AWAY!";
	else {
		for (auto c : num) cout << c << " ";
	}
	return 0;
}