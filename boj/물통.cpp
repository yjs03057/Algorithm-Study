#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int A, B, C;
bool visit[201][201][201];
vector<int> answer;
queue<pair<int, pair<int, int>>> q; //(a, b, c) 형태의 자료형을 가진 큐

int main() {
	cin >> A >> B >> C;
	q.push(make_pair(0, make_pair(0, C)));

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		if (visit[a][b][c]) continue;
		visit[a][b][c] = 1;

		if (a == 0) answer.push_back(c);

		//1. C -> A
		if (c + a <= A) q.push(make_pair(c + a, make_pair(b, 0)));
		else q.push(make_pair(A, make_pair(b, c + a - A)));

		//2. C -> B
		if (c + b <= B) q.push(make_pair(a, make_pair(c + b, 0)));
		else q.push(make_pair(a, make_pair(B, c + b - B)));

		//3. B -> A
		if (b + a <= A) q.push(make_pair(b + a, make_pair(0, c)));
		else q.push(make_pair(A, make_pair(a + b - A, c)));

		//4. B -> C
		if (b + c <= C) q.push(make_pair(a, make_pair(0, b + c)));
		else q.push(make_pair(a, make_pair(b + c - C, C)));

		//5. A -> B
		if (a + b <= B) q.push(make_pair(0, make_pair(a + b, c)));
		else q.push(make_pair(a + b - B, make_pair(B, c)));

		//6. A -> C
		if (c + a <= C) q.push(make_pair(0, make_pair(b, a + c)));
		else q.push(make_pair(a + c - C, make_pair(b, C)));
	}

	sort(answer.begin(), answer.end());
	for (auto &ele : answer) cout << ele << ' ';
}