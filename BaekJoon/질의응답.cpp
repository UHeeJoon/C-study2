﻿//#pragma warning(disable : 4996)
//https://www.acmicpc.net/problem/1517
#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int main()
{
	//FAST_IO;
	constexpr long long MOD = 1e12;
	int n; cin >> n;
	long long mul = 1;
	for (int i = 2; i <= n; i++) {
		mul *= i;
		while (mul % 10 == 0) {
			mul /= 10;
		}
		mul %= MOD;
	}
	printf("%05lld", mul % 100'000);
	return 0;
}