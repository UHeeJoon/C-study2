#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define X second.first.first
#define Y second.first.second
#define TIME second.second
#define TYPE first
typedef pair<int, pair<pair<int, int>, int>> pi_p_pii_i;
typedef vector<vector<int>> vvi;
constexpr int dx[] = { 1,0,-1,0 };
constexpr int dy[] = { 0,1,0,-1 };
void transmission(vvi& test_tube, const int size_test_tube, queue<pi_p_pii_i>& viruses, const int check_time)
{
	while (!viruses.empty())
	{
		const pi_p_pii_i virus = viruses.front();
		viruses.pop();
		for (int i = 0; i < 4; i++)
		{
			const int x = virus.X + dx[i];
			const int y = virus.Y + dy[i];
			const int type_of_virus = virus.TYPE;
			const int current_time = virus.TIME + 1;
			if (current_time > check_time) return;
			if (x < 0 || x >= size_test_tube || y < 0 || y >= size_test_tube || test_tube[x][y])continue;
			test_tube[x][y] = type_of_virus;
			viruses.push({ type_of_virus, {{x, y}, current_time } });
		}
	}
}
int main() {
	FAST_IO;
	int n, k; cin >> n >> k;
	queue<pi_p_pii_i> viruses;
	vector<pi_p_pii_i> sort_virus_type;
	vvi test_tube(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> test_tube[i][j];
			if (test_tube[i][j])
			{
				sort_virus_type.push_back({ test_tube[i][j],{{i, j},0 } });
			}
		}
	}
	sort(sort_virus_type.begin(), sort_virus_type.end());
	for (pi_p_pii_i tmp : sort_virus_type) { viruses.push(tmp); }
	vector<pi_p_pii_i>().swap(sort_virus_type);
	int s, x, y; cin >> s >> x >> y;
	transmission(test_tube, n, viruses, s);
	cout << test_tube[x - 1][y - 1] << '\n';
	return 0;
}
