//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//int N, M;
//vector<int> trust[10001];
//bool visit[10001];
//vector<pair<int, int>> most_hacked;
//int cnt;
//
//bool compare(pair<int, int>a, pair<int, int>b) {
//	if (a.first == b.first) return a.second < b.second;
//	else return a.first > b.first;
//}
//
//void DFS(int a) {
//	visit[a] = 1;
//	cnt++;
//	for (auto& ele : trust[a]) {
//		if (!visit[ele]) DFS(ele);
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//
//	int x, y;
//	while (M--) {
//		y = M;
//		x = 10001 - M;
//		cin >> x >> y;
//		trust[y].push_back(x);
//	}
//
//	for (int i = 1; i <= N; i++) {
//		cnt = 0;
//		DFS(i);
//		most_hacked.push_back(make_pair(cnt, i));
//		memset(visit, 0, sizeof(visit));
//	}
//	sort(most_hacked.begin(), most_hacked.end(), compare);
//	
//	int before = most_hacked[0].first;
//	for (auto& ele : most_hacked) {
//		if (ele.first == before) cout << ele.second << ' ';
//		else break;
//	}
//}