#include<bits/stdc++.h>
using namespace std;
//#define MAX 1010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
typedef long long ll;
int n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	if (n > 1022) {
		cout << -1 << '\n';
		return 0;
	}
	queue<ll> q;
	if (n <= 9) {
		cout << n << '\n';
		return 0;
	}
	for (int i = 1; i <= 9; i++) {
		q.push(i);
	}
	int idx = 10;
	ll ans = 0;
	while (idx <= n && !q.empty()) {
		ll num = q.front();
		q.pop();
		int last = num % 10;
		for (int i = 0; i < last; i++) {
			ans = num * 10 + i;
			q.push(ans);
			if (idx == n) {
				cout << ans << '\n';
				return 0;
			}
			idx++;
		}
	}
	cout << -1 << '\n';
	return 0;
}

/*
#include <iostream>
using namespace std;

int n, c=0;
int num[10]={0, };
bool flag=false;

void Btrack(int r, int k, int x) {
  if(k==r) {
	c++;
	if(n!=c) return;
	flag=true;
	for(int i=0; i<k; i++) {
	  cout<<num[i];
	}
	cout<<'\n';
	return;
  }
  for(int i=r-k-1; i<x; i++) {
	if(i==0 && k==0) continue;
	num[k]=i;
	Btrack(r, k+1, i);
	if(flag) break;
  }
  return;
}

int main() {
  cin>>n;
  if(n==0) {
	cout<<"0\n";
	return 0;
  }
  for(int i=1; i<=10; i++) {
	Btrack(i, 0, 10);
	if(flag) break;
  }
  if(!flag) cout<<"-1\n";
  return 0;
}
*/