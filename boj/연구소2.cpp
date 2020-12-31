#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 99999

int N, M, answer;
int lab[50][50];
int visit[50][50];
vector<pair<int, int>> virus_q; //virus를 놓을 수 있는 자리들
deque<pair<int, pair<int, int>>> q; //<cnt(시간) <x, y>> 형태의 양방향 큐(스택, 큐)
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool check_infection() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!lab[i][j] && !visit[i][j]) return false;
		}
	}
	return true;
}

int BFS(deque<pair<int, pair<int, int>>> st) {
	int cnt; int x; int y;
	while (!st.empty()) {
		pair<int, pair<int, int>> current = st.front();
		st.pop_front();
		cnt = current.first;
		x = current.second.first;
		y = current.second.second;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (lab[nx][ny] != 1 && !visit[nx][ny]) {
				visit[nx][ny] = 1;
				st.push_back({ cnt + 1, {nx, ny} });
			}
		}
	}

	if (check_infection()) return cnt;
	else return MAX;
}

void select_virus(int num, int index) {
	if (num > 0) {
		for (int i = index; i < virus_q.size(); i++) {
			q.push_back({ 0, {virus_q[i].first, virus_q[i].second} });
			lab[virus_q[i].first][virus_q[i].second] = 1;
			select_virus(num - 1, i + 1);
			q.pop_back();
			lab[virus_q[i].first][virus_q[i].second] = 2;
		}
	}
	else {
		answer = min(answer, BFS(q));
		memset(visit, 0, sizeof(visit));
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 2) virus_q.push_back({ i, j });
		}
	answer = MAX;
	select_virus(M, 0);

	if (answer == MAX) cout << -1;
	else cout << answer;
}