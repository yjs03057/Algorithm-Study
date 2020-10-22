//#include <iostream>
//#include <queue>
//#include <algorithm>
//using namespace std;
//#define INF 99999
//
//int N;
//int cave[125][125];
//int money[125][125];
//priority_queue<pair<int, pair<int, int>>> q;
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//
//int main() {
//	int index = 1;
//	while (1) {
//		cin >> N;
//		if (N == 0) return 0;
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				cin >> cave[i][j];
//				money[i][j] = INF;
//			}
//		}
//		money[0][0] = cave[0][0];
//		q.push(make_pair(-money[0][0], make_pair(0, 0)));
//
//		while (!q.empty()) {
//			int current = -q.top().first;
//			int x = q.top().second.first;
//			int y = q.top().second.second;
//			q.pop();
//
//			for (int i = 0; i < 4; i++) {
//				int nx = x + dx[i];
//				int ny = y + dy[i];
//
//				if (nx >= 0 and ny >= 0 and nx < N and ny < N) {
//					int new_money = current + cave[nx][ny];
//					if (money[nx][ny] > new_money) {
//						money[nx][ny] = new_money;
//						q.push(make_pair(-new_money, make_pair(nx, ny)));
//					}
//				}
//			}
//		}
//
//		cout << "Problem " << index << ": " << money[N - 1][N - 1] << endl;
//		index++;
//	}
//}