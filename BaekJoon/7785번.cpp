#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	int n; cin >> n;
	map<string, bool> _map;
	while (n--)
	{
		string person, statement;
		cin >> person >> statement;
		_map[person] = statement == "enter" ? true : false;
	}
	int count = 0;
	vector<string> v;
	for (const auto& m : _map)
	{
		if (m.second)
			v.push_back(m.first);
	}
	sort(v.begin(), v.end(), greater<>());
	for (const string& s : v)
	{
		cout << s << '\n';
	}
	return 0;
}



/*
 #include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	int n; cin >> n;

	set <string> st;

	for (int i = 0; i < n; i++) {
		string s, doit; cin >> s >> doit;

		if (doit == "enter") {
			st.insert(s);
		}
		else if (doit == "leave") {
			st.erase(s);
		}
	}

	for (auto iter = st.rbegin(); iter != st.rend(); iter++)
		cout << *iter << '\n';
	return 0;
}
 */