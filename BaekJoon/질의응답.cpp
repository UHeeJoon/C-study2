#pragma warning (disable :4996)
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
#include<tuple>
#include<cmath>
using namespace std;
int	rope[100001], n, k;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> rope[i];
	sort(rope, rope + n);
	for (int i = 0; i < n; i++) 
		k = max(rope[i] * (n - i), k);
	cout << k << '\n';
	return 0;
}

/*
#pragma warning (disable :4996)
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
#include<tuple>
#include<cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL);


}

*/