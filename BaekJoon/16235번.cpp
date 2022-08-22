#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>map[11][11];			//�� ��ǥ�� �ɾ��� ������ ���ͷ� ������ ����
int a[11][11] = { 0, };			//�ų� ������ ��� ( �Է����� �� ����)
int ground[11][11] = { 0, };		//���� ���� ���� ����� ������ �迭
struct tree { int x, y, age; };		//���� �������͸� ���� ����ü
int n, m, k;				//�� ũ��, ��������, k��
vector<tree>dead;			//���� ���� ����

int dx[8] = { -1,-1,-1,0,0,+1,+1,+1 };
int dy[8] = { -1,0,+1,-1,+1,-1,0,+1 };
void input() {
	cin >> n >> m >> k;
	//�� ó�� �� ����� ��� 5
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			ground[r][c] = 5;
		}
	}
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			cin >> a[r][c];
		}
	}
	//m�� ���� �Է�
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		map[x][y].push_back(z);//z�� age
	}
}

void spring() {
	//���̾�� ���� ����
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			sort(map[r][c].begin(), map[r][c].end());
		}
	}
	//�� ĭ���� ��� �Դ� ������ �״� ���� Ȯ��
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			for (int i = 0; i < map[r][c].size(); i++) {
				if (ground[r][c] >= map[r][c][i]) {//��иԱⰡ��
					ground[r][c] = ground[r][c] - map[r][c][i];//��и԰�
					map[r][c][i]++;//���� 1����
				}
				else {//��� ������
					dead.push_back({ r,c,map[r][c][i] });
					map[r][c].erase(map[r][c].begin() + i);//����
					i--;//vector.erase�� ������ ���� i�ε��� �ٿ��� ��
				}
			}
		}
	}
}

void summer() {
	for (int i = dead.size() - 1; i >= 0; i--) {
		int r = dead[i].x;
		int c = dead[i].y;
		ground[r][c] = ground[r][c] + dead[i].age / 2;
	}
	dead.clear(); dead.resize(0);//�� �� �״� ���� ������Ʈ�� ����
}

void fall() {
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			for (int i = 0; i < map[r][c].size(); i++) {
				if (map[r][c][i] % 5 == 0 && map[r][c][i] >= 5) {
					for (int j = 0; j < 8; j++) {
						int nx = r + dx[j];
						int ny = c + dy[j];
						if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
							map[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			ground[r][c] = ground[r][c] + a[r][c];
		}
	}
}

int main() {
	input();
	while (k > 0) {
		k--;
		spring();
		summer();
		fall();
		winter();
	}
	int answer = 0;
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			answer = answer + map[r][c].size();
		}
	}
	cout << answer << '\n';
	return 0;
}