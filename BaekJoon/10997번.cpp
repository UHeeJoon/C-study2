#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
char star[399][397];
void draw_star(const int n, int x, int y) {

    const int width = 4 * n - 3;
    const int height = width + 2;

    for (int i = 1; i < width; i++) star[x][y--] = '*';
    for (int i = 1; i < height; i++) star[x++][y] = '*';
    for (int i = 1; i < width; i++) star[x][y++] = '*';
    for (int i = 1; i < height - 2; i++) star[x--][y] = '*';


    star[x][y] = '*';
    y--;
    star[x][y] = '*';

    if (n == 2) {
        star[x][y - 1] = '*';
        star[x + 1][y - 1] = '*';
        star[x + 2][y - 1] = '*';
        return;
    }

    draw_star(n - 1, x, y - 1);
}
int main()
{
    FAST_IO;
    int n;
    cin >> n;

    if (n == 1) {
        printf("*");
        return 0;
    }

    const int width = 4 * n - 3;
    const int height = width + 2;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            star[i][j] = ' ';
        }
    }

    const int x = 0, y = 4 * n - 4;

    draw_star(n, x, y);

    for (int i = 0; i < height; i++) {
        if (i == 1) {
            cout << "*\n";
            continue;
        }

        for (int j = 0; j < width; j++) {
            cout << star[i][j];
        }
        cout << "\n";
    }

    return 0;
}