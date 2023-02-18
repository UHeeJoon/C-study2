#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
constexpr int move_way[8][2] = { {-1, 0}, {-1,1}, {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
struct fireball
{
	void location_clearance(const int grid_size)
	{
		r = r % grid_size;
		r = r < 0 ? r + grid_size : r;
		c = c % grid_size;
		c = c < 0 ? c + grid_size : c;
	}
	int r;
	int c;
	int m;
	int s;
	int d;
};
struct merged_contents
{
	merged_contents() : count(0), m(0), s(0) {}
	bool odd_even() const
	{
		bool flag = true;
		for (int i = 1; i < static_cast<int>(d.size()); i++)
		{
			(d[0] & 1) == (d[i] & 1) ? flag : flag = false;
		}
		return flag;
	}
	int count;
	int m;
	int s;
	vector<int> d;
};
typedef map<int, merged_contents> merged_fireball;
void move(vector<fireball>& fireballs, const int grid_size)
{
	for (fireball& fireball : fireballs)
	{
		fireball.r += move_way[fireball.d][0] * fireball.s;
		fireball.c += move_way[fireball.d][1] * fireball.s;
		fireball.location_clearance(grid_size);
	}
}
merged_fireball merged_fireballs(const vector<fireball>& fireballs)
{
	merged_fireball merged;
	for (const fireball fireball : fireballs)
	{
		const int location = fireball.r * 100 + fireball.c;
		merged[location].count++;
		merged[location].m += fireball.m;
		merged[location].s += fireball.s;
		merged[location].d.push_back(fireball.d);
	}
	return merged;
}
void divide_4_fireballs(vector<fireball>& fireballs, const merged_fireball& merged)
{
	for (auto fireball : merged)
	{
		const int r = fireball.first / 100;
		const int c = fireball.first % 100;
		const int mass = fireball.second.m / 5;
		const int speed = fireball.second.s / fireball.second.count;
		if (fireball.second.count == 1)
		{
			fireballs.push_back({ r, c, fireball.second.m, fireball.second.s, fireball.second.d[0] });
			continue;
		}
		if (!mass) {
			continue;
		}
		int idx = 1;
		if (fireball.second.odd_even())
		{
			idx = 0;
		}

		for (; idx < 8; idx += 2)
			fireballs.push_back({ r, c, mass, speed, idx });
	}
}
void print_mass_sum(const vector<fireball>& fireballs)
{
	int mass_sum = 0;
	for (const fireball fireball : fireballs)
	{
		mass_sum += fireball.m;
	}
	cout << mass_sum << '\n';
}
void command(vector<fireball>& fireballs, const int grid_size)
{
	move(fireballs, grid_size);
	const merged_fireball merged = merged_fireballs(fireballs);
	vector<fireball>().swap(fireballs); // free
	divide_4_fireballs(fireballs, merged);
}
int main()
{
	FAST_IO;
	int n, m, k; cin >> n >> m >> k;
	vector<fireball> fireballs(m);
	for (fireball& fireball : fireballs)
	{
		cin >> fireball.r >> fireball.c >> fireball.m >> fireball.s >> fireball.d;
	}
	while (k--)
	{
		command(fireballs, n);
	}
	print_mass_sum(fireballs);
	return 0;
}