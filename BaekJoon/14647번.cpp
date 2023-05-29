#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
const int MAX = 500;
int N, M;
int bingo[MAX][MAX];

int findNine(int num)
{
    int result = 0;
    while (num)
    {
        if (num % 10 == 9)
            result++;
        num /= 10;
    }
    return result;
}
int main()
{
    FAST_IO;
    int nine = 0;
    int rowMax = 0, colMax = 0;
    for (int i = 0; i < N; i++)
    {
        int colSum = 0;
        for (int j = 0; j < M; j++)
        {
            int temp;
            cin >> temp;
            bingo[i][j] = findNine(temp);
            colSum += bingo[i][j];
            nine += bingo[i][j];
        }
        colMax = max(colMax, colSum);
    }
    for (int i = 0; i < M; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < N; j++)
            rowSum += bingo[j][i];
        rowMax = max(rowMax, rowSum);
    }
    cout << nine - max(colMax, rowMax) << "\n";
    return 0;
}