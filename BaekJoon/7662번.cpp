#include<bits/stdc++.h>
using namespace std;
int T, Q;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> Q;
        priority_queue<ll, vector<ll>, greater<ll>> minQ;
        priority_queue<ll, vector<ll>, less<ll>> maxQ;
        map<ll, ll> m;
        char op;
        ll num;
        while (Q--) {
            cin >> op >> num;
            if (op == 'I') {
                maxQ.push(num);
                minQ.push(num);
                m[num]++;
            }
            else if (num == 1) {
                while (!maxQ.empty() && m[maxQ.top()] == 0)
                    maxQ.pop();

                if (!maxQ.empty()) {
                    m[maxQ.top()]--;
                    maxQ.pop();
                }
            }
            else {
                while (!minQ.empty() && m[minQ.top()] == 0)
                    minQ.pop();

                if (!minQ.empty()) {
                    m[minQ.top()]--;
                    minQ.pop();
                }
            }
        }
        while (!maxQ.empty() && m[maxQ.top()] == 0)
            maxQ.pop();
        while (!minQ.empty() && m[minQ.top()] == 0)
            minQ.pop();
        if (minQ.empty())
            cout << "EMPTY\n";
        else
            cout << maxQ.top() << " " << minQ.top() << "\n";
    }
    return 0;
}
/*
#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    int n;
    while (t--)
    {
        cin >> n;
        char order;
        int num;
        multiset<int> ms;
        while (n--)
        {
            cin >> order >> num;
            if (order == 'I')
            {
                ms.insert(num);
            }
            else
            {
                if (!ms.empty() && num == -1)
                {
                    ms.erase(ms.begin());
                }
                else if (!ms.empty() && num == 1)
                {
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                }
            }
        }
        if (ms.empty())
        {
            cout << "EMPTY" << '\n';
        }
        else
        {
            auto end_iter = ms.end();
            end_iter--;
            cout << *end_iter << ' ' << *ms.begin() << '\n';
        }
    }
    return 0;
}
*/