#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int paper[502][502];
bool visit[502][502];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<int> painting = {0};

int DFS(int x, int y, int width) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!visit[nx][ny] && paper[nx][ny]) width = DFS(nx, ny, width + 1);
	}
	return width;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> paper[i][j];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visit[i][j] && paper[i][j]) {
				int width = DFS(i, j, 1);
				painting.push_back(width);
			}
		}
	}
	sort(painting.begin(), painting.end());
	cout << painting.size()-1 << '\n' << painting.back();
}