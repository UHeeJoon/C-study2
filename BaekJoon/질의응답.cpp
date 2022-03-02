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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	string name[n];
	int age[n];
	for (int i = 0; i < n; i++) {
		cin >> age[i] >> name[i];
	}
	for (int i = 1; i < 200; i++) {
		for (int j = 0; j < n; j++) {
			if (i == age[j]) {
				cout << age[j] << " " << name[j];
			}
		}
	}

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