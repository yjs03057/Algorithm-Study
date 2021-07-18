// 백준 11967: 불켜기

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, M;
int visit[102][102]; //0: 불 안켜진 상태, 1: 불 켜진 상태, 2: 방문 가능 상태
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<pair<int, int>> connect[101][101];

int main() {
    cin >> N >> M;
    while (M--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        connect[x][y].push_back({a, b});
    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    visit[1][1] = 2;
    int cnt = 1;
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        for (auto rooms: connect[x][y]) {
            int room_x = rooms.first;
            int room_y = rooms.second;

            if (!visit[room_x][room_y]) {
                for (int i = 0; i < 4; i++) {
                    int ny = room_y + dy[i];
                    int nx = room_x + dx[i];

                    if (visit[nx][ny] == 2) {
                        q.push({nx, ny});
                        break;
                    }
                }
                visit[room_x][room_y] = 1;
                cnt++;
            }
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (visit[nx][ny] == 1) {
                visit[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
    cout << cnt;
}
