#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int main() {
	while (1) {
		int h, m, h1, m1, cnt = 0;
		scanf("%d:%d %d:%d", &h, &m, &h1, &m1);
		if (!h && !m && !h1 && !m1)break;
		h = h + h1; m = m + m1;
		if (m >= 60) {
			h += m / 60;
			m = m % 60;
			
		}
		if (h >= 24) {
			cnt = h / 24;
			h = h % 24;
		}
		printf("%02d:%02d", h, m);
		if (cnt) printf(" +%d\n", cnt);
		else printf("\n");
	}
	return 0;
}