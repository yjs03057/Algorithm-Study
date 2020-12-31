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
	// �޸������̼ǿ� prePrice �� �߰�
	int& ret = cache[cur][visited][prePrice];
	// ������ ������� ���� �������� �� 1 ���� (������ depth)
	// (1<<num) - 1
	// 0111
	if (visited == (1 << num) - 1)
		return ret = 1;
	// �޸������̼� �迭�� �̹� ���� ���� ��
	if (ret != 0)
		return ret;

	ret = 1;
	for (int next = 0; next < num; next++)
	{
		// �̹� �湮�� ����� ��
		// 000000000001000 : 1<<next
		// 000111111110000 : visited
		// 000000000000000 => 0
		if (visited & (1 << next))
			continue;
		// ���� �����ϰ� �ִ� ����� ���� ����� ��
		if (next == cur)
			continue;

		// ������ �� ���� ��쿡�� �Ǹ��Ѵ�
		//
		if (map[cur][next] >= prePrice)
			ret = max(ret, dfs(next, (visited | 1 << next), map[cur][next]) + 1);
		// 000000000001000 : 1<<next
		// 000111111110000 : visited
		// 000111111111000 : or����ó��
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