#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

void upside_down(vector<vector<int>>& arr, const int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		swap(arr[i], arr[n - i - 1]);
	}
}

void reverse_left_right(vector<vector<int>>& arr, const int n, const int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			swap(arr[i][j], arr[i][m - j - 1]);

		}
	}
}
void degree90(vector<vector<int>>& arr, int& n, int& m, const int cal)
{
	vector<vector<int>>tmp(m, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (cal == 3)
				tmp[j][n - i - 1] = arr[i][j];
			else
				tmp[m - j - 1][i] = arr[i][j];

		}
	}
	arr.swap(tmp);
	swap(n, m);
}

void swap_clockwise(int& a, int& b, int& c, int& d)
{
	swap(a, b);
	swap(a, c);
	swap(a, d);
}
void swap_counterclockwise(int& a, int& b, int& c, int& d)
{
	swap(a, d);
	swap(a, c);
	swap(a, b);
}
void rotate(vector<vector<int>>& arr, const int n, const int m, const int cal)
{
	void(*_swap)(int&, int&, int&, int&) = cal == 5 ? swap_clockwise : swap_counterclockwise;
	const int y = n / 2, x = m / 2;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			_swap(arr[i][j], arr[i][j + x], arr[i + y][j + x], arr[i + y][j]);
		}
	}
}
void rotate(const int cal, vector<vector<int>>& arr, int& n, int& m)
{
	switch (cal)
	{
	case 1:upside_down(arr, n); break;
	case 2:reverse_left_right(arr, n, m); break;
	case 3: case 4:degree90(arr, n, m, cal); break;
	case 5: case 6:rotate(arr, n, m, cal); break;
	default:break;
	}
}

int main() {
	FAST_IO;
	int n, m, r; cin >> n >> m >> r;
	vector<vector<int>> arr(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	while (r--)
	{
		int cal; cin >> cal;
		rotate(cal, arr, n, m);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}




// other people solved

/*
 #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>>* cur;
vector<vector<int>>* copyObj;
vector<vector<int>>* temp;

vector<vector<int>> map1;
vector<vector<int>> map2;

void swaping()
{
    temp = cur;
    cur = copyObj;
    copyObj = temp;
}

void order1() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            copyObj->at(n - i - 1).at(j) = cur->at(i).at(j);
}
void order2() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            copyObj->at(i).at(m-j-1) = cur->at(i).at(j);
}
void order3() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            copyObj->at(j).at(n - i - 1) = cur->at(i).at(j);

    swap(n, m);
}
void order4() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            copyObj->at(m-j-1).at(i) = cur->at(i).at(j);

    swap(n, m);
}
void order5() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i < n / 2 && j < m / 2)
                copyObj->at(i).at(j + m / 2) = cur->at(i).at(j);
            else if (i < n / 2)
                copyObj->at(i + n / 2).at(j) = cur->at(i).at(j);
            else if (j < m / 2)
                copyObj->at(i - n / 2).at(j) = cur->at(i).at(j);
            else
                copyObj->at(i).at(j - m / 2) = cur->at(i).at(j);
        }
}
void order6() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i < n / 2 && j < m / 2)
                copyObj->at(i + n / 2).at(j) = cur->at(i).at(j);
            else if (i < n / 2)
                copyObj->at(i).at(j - m / 2) = cur->at(i).at(j);
            else if (j < m / 2)
                copyObj->at(i).at(j + m / 2) = cur->at(i).at(j);
            else
                copyObj->at(i - n / 2).at(j) = cur->at(i).at(j);
        }
}


int main()
{
    int r;
    cin >> n >> m >> r;

    int MAX = std::max(n, m);

    map1.assign(MAX, vector<int>(MAX));
    map2.assign(MAX, vector<int>(MAX));

    cur = &map1;
    copyObj = &map2;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map1[i][j];

    for (int i = 0; i < r; i++)
    {

        int order;
        cin >> order;
        switch (order) {
        case 1:
            order1();
            break;
        case 2:
            order2();
            break;
        case 3:
            order3();
            break;
        case 4:
            order4();
            break;
        case 5:
            order5();
            break;
        case 6:
            order6();
            break;
        }
        swaping();

    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << cur->at(i).at(j) << " ";
        cout << '\n';
    }

}

 */