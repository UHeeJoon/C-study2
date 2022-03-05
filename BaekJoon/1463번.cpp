
#include<bits/stdc++.h>
using namespace std;
int arr[1000005];
int N;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	arr[2] = 1, arr[3] = 1;
	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + 1;
		if ((i % 3) == 0)
			arr[i] = min(arr[i / 3] + 1, arr[i]);
		if ((i % 2) == 0)
			arr[i] = min(arr[i / 2] + 1, arr[i]);
		if ((i - 1) > 0)
			arr[i] = min(arr[i - 1] + 1, arr[i]);
	}
	cout << arr[N];
}

/*
#include<bits/stdc++.h>
using namespace std;
int num[5000010], n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
    fill(num, num + 5000010, 987654321);
    num[1] = 0;
    for (int i = 1;i<n;i++){
        num[i + 1] = min(num[i + 1], num[i] + 1);
        num[i * 2] = min(num[i * 2], num[i] + 1);
        num[i * 3] = min(num[i * 3], num[i] + 1);
    }
	cout << num[n] << '\n';
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int arr[1000005];
int N;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	arr[1] = 0;
	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + 1;
		if ((i % 3) == 0)
			arr[i] = min(arr[i / 3] + 1, arr[i]);
		if ((i % 2) == 0)
			arr[i] = min(arr[i / 2] + 1, arr[i]);
	}
	cout << arr[N];
}
*/