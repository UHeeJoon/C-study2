#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int tmp[50'0002];
void merge(int* arr, const int p, const int q, const int r, int& count, const int k)
{
	int i = p, j = q + 1, t = 0;
	while (i <= q && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			tmp[t++] = arr[i++];
		}
		else
		{
			tmp[t++] = arr[j++];
		}
	}
	while (i <= q)
	{
		tmp[t++] = arr[i++];
	}
	while (j <= r)
	{
		tmp[t++] = arr[j++];
	}
	i = p; t = 0;
	while (i <= r)
	{
		arr[i++] = tmp[t++];
		count++;
		if (count == k)
		{
			cout << tmp[t - 1] << '\n';
			exit(0);
		}
	}
}

void merge_sort(int* arr, const int p, const int r, int& count, const int k)
{
	if (p >= r) return;
	const int q = (p + r) / 2;
	merge_sort(arr, p, q, count, k);
	merge_sort(arr, q + 1, r, count, k);
	merge(arr, p, q, r, count, k);
}
int main() {
	FAST_IO;
	int n, k; cin >> n >> k;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int count = 0;
	merge_sort(arr, 0, n - 1, count, k);
	cout << -1 << '\n';
	return 0;
}