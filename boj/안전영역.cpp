#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, next_height, answer;
int map[100][100];
bool visit[100][100];
bool sink[100][100];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void check_sink(int height) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == height) sink[i][j] = 1;
		}
	}
}

void DFS(int x, int y) {
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (sink[nx][ny] || visit[nx][ny]) continue;
		DFS(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int min_val = 101;
	int max_val = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			min_val = min(map[i][j], min_val);
			max_val = max(map[i][j], max_val);
		}
	}

	

	int height = min_val;
	answer = 1;
	int cnt = 0;
	while (height < max_val) {
		check_sink(height);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j] && !sink[i][j]) {
					cnt++;
					DFS(i, j);
				}
			}
		}
		height++;
		answer = max(answer, cnt);
		cnt = 0;
		memset(visit, 0, sizeof(visit));
	}

	cout << answer;
}