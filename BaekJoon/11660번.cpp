#include<bits/stdc++.h>
using namespace std;
int arr[1030][1030];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a; cin >> a;
			arr[i][j] = arr[i][j - 1] + a;
		}
	}
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2 && y1 == y2) {
			cout << arr[x1][y1] - arr[x1][y1 - 1] << '\n';
			continue;
		}
		if (x1 == x2) {
			cout << arr[x2][y2] - arr[x1][y1 - 1] << '\n';
		}
		else {
			int sum = 0;
			for (int i = 0; i <= x2 - x1; i++)
				sum += arr[x1 + i][y2] - arr[x1 + i][y1 - 1];
			cout << sum << '\n';
		}
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int arr[1025][1025],dp[1025][1025];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
			dp[i][j] = dp[i-1][j]+dp[i][j-1] - dp[i-1][j-1]+arr[i][j];
		}
	}
	int x1,y1,x2,y2;
	int ans;
	for(int i=0;i<m;i++){
		cin>>x1>>y1>>x2>>y2;
		ans = dp[x2][y2] - dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
		cout<<ans<<'\n';
	}
	return 0;
}
*/