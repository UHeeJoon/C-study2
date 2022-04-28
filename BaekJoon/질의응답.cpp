#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> ret;
	for (int i = 0; i < progresses.size(); i++) {
		ret.push_back((100 - progresses[i]) % speeds[i] == 0 ? (100 - progresses[i]) / speeds[i] : (100 - progresses[i]) / speeds[i] + 1);
	}
	int tmp = ret[0], cnt = 1;
	for (int i = 1; i < ret.size(); i++) {
		if (tmp >= ret[i])
			cnt++;
		else {
			answer.push_back(cnt);
			cnt = 1;
			tmp = ret[i];
		}
	}
	answer.push_back(cnt);
	return answer;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> v, v2;
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		v2.push_back(a);
	}
	vector<int> res = solution(v, v2);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
	return 0;
}