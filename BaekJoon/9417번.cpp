#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
static int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
static vector<int> split(string& str) {
	vector<int> v;
	int num;
	stringstream stream(str);
	while (stream >> num) {
		v.push_back(num);
	}
	return v;
}
int main()
{
	FAST_IO;
	int tc; cin >> tc;
	cin.ignore();
	while (tc--) {
		int max_gcd = 1;
		string str;
		getline(cin, str);
		vector<int> v = split(str);
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				max_gcd = max(max_gcd, gcd(v[i], v[j]));
			}
		}
		cout << max_gcd << '\n';
	}
	return 0;
}

#include <iostream>
 
using namespace std;
int x, y;
int p1, p2;
 
bool check[100100];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    cin >> x >> y >> p1 >> p2;
 
    int ans = -1;
 
    for (int i = p1; i < 100100; i += x)
    {
        check[i] = 1;
    }
 
    for (int i = p2; i < 100100; i += y)
    {
        if (check[i])
        {
            ans = i;
            break;
        }
    }
 
    cout << ans;
 
    return 0;
}
