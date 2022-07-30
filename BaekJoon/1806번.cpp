#include<bits/stdc++.h>
using namespace std;
int num[100010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, s; cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		int tmp; cin >> tmp;
		num[i] = num[i - 1] + tmp;
	}
	int i = 0, j = 1, res = n + 1;
	while (i < j && j <= n) {
		if (num[j] - num[i] >= s && j - i < res) res = j - i;
		if (num[j] - num[i] < s)j++;
		else i++;
	}
	cout << (res == n + 1 ? 0 : res) << '\n';
	return 0;
}
/*
#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001];
int N, M; //S대신 M사용
int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> arr[i];
    int st=1, en=1, total = arr[1], ans = 987654321;
    while(st <= en && en <= N){
        if(total >= M) ans = min(ans, (en-st+1));
        if(total < M) {
            en++;
            total += arr[en];
        } else {
            total -= arr[st];
            st++;
        }
    }
    if(ans == 987654321) cout << "0";
    else cout << ans;
}
*/