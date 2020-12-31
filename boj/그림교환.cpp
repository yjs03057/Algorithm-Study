#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define INF 987654321;

int num;
int map[16][16];
int cache[16][(1 << 15) + 1][10];
// (1<<15) + 1 : 100000000000001

int dfs(int cur, int visited, int prePrice)
{
	// 메모이제이션에 prePrice 를 추가
	int& ret = cache[cur][visited][prePrice];
	// 나머지 사람들이 전부 소유했을 때 1 리턴 (마지막 depth)
	// (1<<num) - 1
	// 0111
	if (visited == (1 << num) - 1)
		return ret = 1;
	// 메모이제이션 배열에 이미 값이 있을 때
	if (ret != 0)
		return ret;

	ret = 1;
	for (int next = 0; next < num; next++)
	{
		// 이미 방문한 사람일 때
		// 000000000001000 : 1<<next
		// 000111111110000 : visited
		// 000000000000000 => 0
		if (visited & (1 << next))
			continue;
		// 현재 소유하고 있는 사람과 같은 사람일 때
		if (next == cur)
			continue;

		// 가격이 더 높은 경우에만 판매한다
		//
		if (map[cur][next] >= prePrice)
			ret = max(ret, dfs(next, (visited | 1 << next), map[cur][next]) + 1);
		// 000000000001000 : 1<<next
		// 000111111110000 : visited
		// 000111111111000 : or연산처리
	}

	return ret;
}

void solve()
{
	cout << dfs(0, 1, 0) << endl;
}

int main()
{
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < num; j++)
		{
			map[i][j] = s[j] - '0';
		}
	}


	solve();
	return 0;
}