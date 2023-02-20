#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int a{ 0 }, b{ 0 };
	int A[10] = { 0, }, B[10] = { 0, };
	for (int& num : A)
	{
		cin >> num;
	}
	for (int& num : B)
	{
		cin >> num;
	}
	for (int i = 0; i < 10; i++)
	{
		if (A[i] > B[i])a++;
		else if (A[i] < B[i]) b++;
	}
	if (a > b)cout << "A\n";
	else if (a < b)cout << "B\n";
	else cout << "D\n";
	return 0;
}