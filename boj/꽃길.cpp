#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, answer;
int board[10][10];
int visit[10][10];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool checkFlower(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) return false;
		if (visit[nx][ny]) return false;
	}
	return true;
}

int bloomFlower(int x, int y) {
	int cost = board[x][y];
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		cost += board[nx][ny];
		visit[nx][ny] = 1;
	}
	return cost;
}

void backward(int x, int y) {
	visit[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		visit[nx][ny] = 0;
	}
}

void DFS(int cnt, int cost) {
	if (cnt == 3) {
		answer = min(answer, cost);
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j]) continue;
			if (checkFlower(i, j)) {
				DFS(cnt + 1, bloomFlower(i, j) + cost);
				backward(i, j);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	answer = 987654321;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			cin >> board[i][j];

	DFS(0, 0);
	cout << answer;

}