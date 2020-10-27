//#include <iostream>
//#include <vector>
//using namespace std;
//
//int N, M;
//int a, b;
//vector<vector<int>> relation(101);
//vector<int> q;
//int visit[101];
//
//int main() {
//	cin >> N >> a >> b >> M;
//	int x, y;
//	while (M--) {
//		cin >> x >> y;
//		relation[x].push_back(y);
//		relation[y].push_back(x);
//	}
//
//	if (a == b) {
//		cout << 0;
//		return 0;
//	}
//
//	vector<int> temp;
//	q.push_back(a);
//	int current;
//	int answer = 0;
//	while (!q.empty()) {
//		current = q.front();
//		visit[current] = 1;
//		q.erase(q.begin());
//		for (auto &ele : relation[current]) {
//			if (ele == b && !visit[ele]) {
//				cout << answer + 1;
//				return 0;
//			}
//			else if (!visit[ele]) temp.push_back(ele);
//		}
//		if (q.empty()) {
//			q = temp;
//			temp.clear();
//			answer++;
//		}
//	}
//	cout << -1;
//	return 0;
//}