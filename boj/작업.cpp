#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer;
vector<int> graph[10001]; //그래프 정보
int times[10001];
int topology[10001]; //진입차수
vector<pair<int, int>> q;

bool compare(pair<int, int>&a, pair<int, int>&b) {
	return a.first < b.first;
}

void findNode() {
	for (int i = 1; i <= N; i++) {
		if (topology[i] == 0) {
			q.push_back({ times[i], i }); //시간, 노드 정보 저장
			topology[i] = -1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int jobs;
	for (int i = 1; i <= N; i++) {
		cin >> times[i] >> topology[i];
		for (int j = 0; j < topology[i]; j++) {
			cin >> jobs;
			graph[jobs].push_back(i); //1이 2의 선행과제: 1->2
		}
	}

	findNode();
	while (!q.empty()) {
		sort(q.begin(), q.end(), compare);
		int current_time = q.front().first;
		int current_node = q.front().second;
		q.erase(q.begin());

		answer += current_time;
		for (auto &ele: graph[current_node]) topology[ele]--; //진입차수 갱신
		for (auto &ele : q) ele.first -= current_time; //남은 시간 갱신 <- 동시에 일 수행하는 것 처리
		findNode();
	}

	cout << answer;
}