//백준 2234: 성곽
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int map[51][51];
int visited[51][51];
int N, M, answer_1, answer_2, answer_3;
int max_size = -987654321;

void BFS(int x, int y) {
    if (visited[x][y]) return;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    int count = 0;
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        x = current.first;
        y = current.second;
        count++;

        for (int i = 0; i < 4; i++) {
            if (((1 << i) & map[x][y]) == 0) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!visited[nx][ny] && nx >= 0 && nx < M && ny >= 0 && ny < N) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    answer_1++;
    if (max_size < count) max_size = count;
}

void break_wall(int x, int y) {
    for (int i = 0; i < 4; i++) {
        if ((map[x][y] & (1 << i)) != 0) {
            memset(visited, 0, sizeof(visited));
            map[x][y] = map[x][y] - (1 << i);
            BFS(x, y);
            map[x][y] = map[x][y] + (1 << i);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            BFS(i, j);
            answer_2 = max_size;
        }
    }
    cout << answer_1 << '\n';
    max_size = -987654321;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            break_wall(i, j);
            answer_3 = max_size;
        }
    }

    cout << answer_2 << '\n' << answer_3;
}

