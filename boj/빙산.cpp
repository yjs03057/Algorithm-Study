#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int iceberg[301][301];
int visit[301][301];
int temp[301][301];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void melting() {
	memcpy(temp, iceberg, sizeof(iceberg));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (iceberg[i][j]) {
				for (int k = 0; k < 4; k++) {
					int ni = i + dx[k];
					int nj = j + dy[k];
					if (ni < 0 || nj < 0 || ni >= N || nj >= M) continue;
					if (!temp[ni][nj] && iceberg[i][j] > 0) iceberg[i][j] -= 1;
				}
			}
		}
	}
}

void DFS(int x, int y){
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (iceberg[nx][ny] && !visit[nx][ny]) DFS(nx, ny);
	}
}
//
//int checkNum() {
//	int num = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (iceberg[i][j] && !visit[i][j]) {
//				if (num == 0) DFS(i, j);
//				else return 0;
//				num++;
//			}
//		}
//	}
//	if (num == 1) return 1;
//	else return -1;
//}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> iceberg[i][j];
	}

	int answer = 0;

	while (1) {
		int num = 0;
		bool check = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (iceberg[i][j] && !visit[i][j]) {
					num++;
					if (num == 2) {
						check = true;
						break;
					}
					DFS(i, j);
				}
			}
		}

		if (check) break;
		if (num == 0) {
			cout << 0;
			return 0;
		}
		melting();
		memset(visit, 0, sizeof(visit));
		answer++;
	}
	cout << answer;
}