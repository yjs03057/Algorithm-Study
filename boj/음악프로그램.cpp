//#include <iostream>
//#include <queue>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int N, M, K;
//vector<vector<int>> arr(1001);
//int cnt[1001];
//int visit[1001];
//vector<int> result;
//
//int main() {
//	cin >> N >> M;
//	while (M--) {
//		cin >> K;
//		int prev;
//		for (int i = 0; i < K; i++) {
//			int current;
//			if (i == 0) cin >> prev;
//			else {
//				cin >> current;
//				cnt[current] = cnt[current] + 1;
//				arr[prev].push_back(current);
//				prev = current;
//			}
//		}
//	}
//
//	queue<int> q;
//	for (int i = 1; i < N + 1; i++) {
//		if (cnt[i] == 0 && visit[i] == 0) {
//			q.push(i);
//			visit[i] = 1;
//		}
//	}
//	
//	while (!q.empty()) {
//		int current = q.front();
//		q.pop();
//		result.push_back(current);
//
//		for (int i = 0; i < arr[current].size(); i++) {
//			cnt[arr[current][i]]--;
//		}
//
//		for (int i = 1; i < N + 1; i++) {
//			if (cnt[i] == 0 && visit[i] == 0) {
//				q.push(i);
//				visit[i] = 1;
//			}
//		}
//	}
//
//	if (result.size() != N) cout << 0;
//	else {
//		for (int i = 0; i < N; i++) cout << result[i] << endl;
//	}
//}