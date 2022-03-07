#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int dp[1001], sum[1000001], N, M;
long long calculate() {
    long long rst = 0;
    for (int i = 0; i < M; i++) {
        if (dp[i] == 0) continue;
        rst += (long long)dp[i] * (dp[i] - 1) / 2;
    }
    return rst + dp[0];
}
int main() {
    scanf("%d %d", &N, &M);
    for (int k = 1; k <= N; k++) {
        int value;
        scanf("%d", &value);
        (sum[k] = sum[k - 1] + value) %= M;
        dp[sum[k]]++;

    }
    printf("%lli\n", calculate());
    return 0;
}

/*
#include <iostream>
using namespace std;
long long rem[1010];
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N,M;
    long long ans=0;
    cin >> N >> M;
    int sum = 0;
    rem[0]++;
    for(int i=0;i<N;i++)
    {
        int A;
        cin >> A;
        sum = (sum + A) % M;
        rem[sum]++;
    }
    for(int i=0;i<M;i++)
    {
        ans += rem[i]*(rem[i]-1)/2;
    }
    cout << ans;
    return 0;
}
*/
/*
#include <iostream>
using namespace std;

long long list[1001]={0,};

int main(){
  cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
  int n, m, tmp, s=0;
  long long k=0;
  cin >> n >> m;
  list[0]++;
  for(int i=0; i<n; i++){
    cin >> tmp;
    s+=tmp;
    s%=m;
    k+=list[s];
    list[s]++;
  }
  cout << k;
}
*/