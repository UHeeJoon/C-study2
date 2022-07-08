#include<bits/stdc++.h>
using namespace std;
int want, n, m, temp, cnt;
int a[1001], b[1001], ret, aSum, bSum, psum_a[2002], psum_b[2002];
map<int, int> aCnt, bCnt;
void make(int n, int psum[], map<int, int>& _map) {
    for (int interval = 1; interval <= n; interval++) {
        for (int start = interval; start <= n + interval - 1; start++) {
            int sum = psum[start] - psum[start - interval];
            _map[sum]++;
            if (interval == n) break;
        }
    }
    return;
}
int main() {
    scanf("%d %d %d", &want, &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i); psum_a[i] = psum_a[i - 1] + a[i];
    }
    for (int i = n + 1; i <= 2 * n; i++) psum_a[i] = psum_a[i - 1] + a[i - n];
    for (int i = 1; i <= m; i++) {
        scanf("%d", b + i);
        psum_b[i] = psum_b[i - 1] + b[i];
    }
    for (int i = m + 1; i <= 2 * m; i++)psum_b[i] = psum_b[i - 1] + b[i - m];
    make(n, psum_a, aCnt);
    make(m, psum_b, bCnt);
    int sum = 0;
    for (int i = 1; i < want; i++){
        sum += aCnt[want - i] * bCnt[i];
    }
    sum += aCnt[want];
    sum += bCnt[want];
    cout << sum << "\n";
}
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int pizza1[1000];
int pizza2[1000];
vector<int> pizzasum1;
vector<int> pizzasum2;
int main() {
	int count = 0;
	int S, pizza1n, pizza2n;
	scanf("%i%i%i", &S,&pizza1n,&pizza2n);
	for (int x = 0; x < pizza1n; x++) {
		scanf("%i", &pizza1[x]);
	}
	for (int x = 0; x < pizza2n; x++) {
		scanf("%i", &pizza2[x]);
	}
	for (int x = 0; x < pizza1n; x++) {
		int sum = 0;
		for (int y = 0; y < pizza1n-1; y++){
			sum += pizza1[(x + y)%pizza1n];
			pizzasum1.push_back(sum);
			if (sum == S) {
				count++;
			}
		}
	}
	for (int x = 0; x < pizza2n; x++) {
		int sum = 0;
		for (int y = 0; y < pizza2n-1; y++) {
				sum += pizza2[(x + y) % pizza2n];
				pizzasum2.push_back(sum);
				if (sum == S) {
					count++;
				}
		}
	}
	int sum = 0;
	for (int x = 0; x < pizza2n; x++) {
		sum += pizza2[x];
	}
	pizzasum2.push_back(sum);
	if (sum == S) {
		count++;
	}
	sum = 0;
	for (int x = 0; x < pizza1n; x++) {
		sum += pizza1[x];
	}
	pizzasum1.push_back(sum);
	if (sum == S) {
		count++;
	}
	sort(pizzasum1.begin(), pizzasum1.end());
	sort(pizzasum2.begin(), pizzasum2.end());
	int left = 0;
	int right = pizzasum2.size() - 1;
	int tempsum = 0;
	while (left <= pizzasum1.size() - 1 && right >= 0) {
		tempsum = pizzasum1[left] + pizzasum2[right];
		if (tempsum <= S) {
			if (tempsum == S) {
				int ncount1 = 1;
				int ncount2 = 1;
				for (int x = left; x < pizzasum1.size() - 1; x++) {
					if (pizzasum1[x] == pizzasum1[x + 1])
					{
						ncount1++;
						left++;
					}
					else {
						break;
					}
				}
				for (int x = right; x >= 1; x--) {
					if (pizzasum2[x] == pizzasum2[x - 1]) {
						ncount2++;
						right=x-1;
					}
					else {
						break;
					}
				}
				count += ncount1 * ncount2;
			}
			left++;
		}
		else {
			right--;
		}
	}
	printf("%i", count);
}
*/
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, m, n;
	long long int res = 0;
	int cnt_A[2000001] = {1, };
	int cnt_B[2000001] = {1, };
	int amt_A[1001][1001] = {};
	int amt_B[1001][1001] = {};

	cin >> N >> m >> n;
	for (int i=0; i<m; i++)
		cin >> amt_A[i][i];
	for (int i=0; i<n; i++)
		cin >> amt_B[i][i];

	for (int i=0; i<m; i++) {
		for (int k=1; k<m; k++) {
			amt_A[i][(i+k)%m] = amt_A[i][(i+k-1)%m] + amt_A[(i+k)%m][(i+k)%m];
		}
	}
	for (int i=0; i<n; i++) {
		for (int k=1; k<n; k++) {
			amt_B[i][(i+k)%n] = amt_B[i][(i+k-1)%n] + amt_B[(i+k)%n][(i+k)%n];
		}
	}
	for (int i=0; i<m; i++)
		for (int k=0; k<m-1; k++)
			cnt_A[amt_A[i][(i+k)%m]]++;
	for (int i=0; i<n; i++)
		for (int k=0; k<n-1; k++)
			cnt_B[amt_B[i][(i+k)%n]]++;
	cnt_A[amt_A[0][m-1]]++;
	cnt_B[amt_B[0][n-1]]++;

	for (int a=0; a<=N; a++)
		res += (long long int) cnt_A[a] * cnt_B[N-a];
	cout << res;
}
*/