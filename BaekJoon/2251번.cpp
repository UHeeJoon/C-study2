#include<bits/stdc++.h>
using namespace std;
#define MAX 201
int A, B, C;
bool check[MAX][MAX][MAX];
vector<int> BFS(void) {
    queue < pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), C));
    vector<int> result;
    while (!q.empty()) {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();
        if (check[a][b][c])
            continue;
        check[a][b][c] = true;
        if (a == 0)
            result.push_back(c);
        if (a + b > B)
            q.push({ {a + b - B, B}, c });
        else
            q.push({ {0, a + b}, c });
        if (a + c > C)
            q.push({ {a + b - C, b}, C });
        else
            q.push({ {0, b}, a + c });
        if (b + a > A)
            q.push({ {A, b + a - A}, c });
        else
            q.push({ {b + a, 0}, c });
        if (b + c > C)
            q.push({ {a, b + c - C}, C });
        else
            q.push({ {a, 0}, b + c });
        if (c + a > A)
            q.push({ {A, b}, c + a - A });
        else
            q.push({ { c + a, b }, 0 });
        if (c + b > B)
            q.push({ {a, B}, c + b - B });
        else
            q.push({ {a, c + b}, 0 });
    }
    return result;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> C;
    vector<int> result = BFS();
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}