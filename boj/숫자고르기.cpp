#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int nums[101];
bool visited[101];
vector<int> answer;

void addAnswer(int start, int goal) {
	int current = start;
	answer.push_back(current);
	while (current != goal) {
		current = nums[current];
		answer.push_back(current);
	}
}

void checkCycle(int node) {
	visited[node] = true;
	int next = nums[node];
	
	if (visited[next]) {
		addAnswer(next, node);
		return;
	}
	checkCycle(next);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) cin >> nums[i];

	for (int i = 1; i <= N; i++) {
		if (!visited[i] && !visited[nums[i]]) checkCycle(i);
		visited[i] = true;
	}

	cout << answer.size()<<'\n';
	sort(answer.begin(), answer.end());
	for (auto& ele : answer) cout << ele << '\n';
}