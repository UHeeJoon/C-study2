#pragma warning(disable:4996)
#include<stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int num;
    char arr[85];
    int len = 0;
    scanf("%d\n", &num);
    int scorearr[100];

    for (int i = 0; i < num; i++)
    {
        int score = 0, len = 0;
        int add = 1;
        scanf("%s", arr);
        while (arr[len] != '\0')
        {
            len++;
        }
        for (int j = 0; j < len; j++)
        {
            if (arr[j] == 'O')
            {
                score += add;
                add++;
            }
            if (arr[j] == 'X')
            {
                add = 1;
            }
        }
        scorearr[i] = score;
        score = 0;
    }

    for (int i = 0; i < num; i++)
    {
        printf("%d\n", scorearr[i]);
    }



    return 0;
}