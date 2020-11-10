#include <iostream>
#include <queue>
using namespace std;

int A, B, N, M, ele, cnt;
bool visit[100001];
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> N >> M;

	q.push({ N, 0 });
	visit[N] = 1;
	while (!q.empty()) {
		ele = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (ele == M) {
			cout << cnt <<'\n';
			return 0;
		}

		int dirs[8] = { ele + 1, ele - 1, ele + A, ele + B, ele - A, ele - B, ele * A, ele * B };
		for (int i = 0; i < 8; i++) {
			int n_ele = dirs[i];
			if (n_ele < 0 or n_ele > 100000) continue;
			if (visit[n_ele]) continue;
			q.push({ n_ele, cnt + 1 });
			visit[n_ele] = 1;
		}
		
	}
}