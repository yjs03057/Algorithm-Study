#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int N;
int numbers[19];
char ops[19];
int max_dp[19][19];
int min_dp[19][19];

int cal(int a, int b, char op) {
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	else return a * b;
}

void print_dp() {
	for (int i = 0; i <= N / 2; i++) {
		for (int j = 0; j <= N / 2; j++) cout << max_dp[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill_n(&max_dp[0][0], 19*19, INT_MIN);
	fill_n(&min_dp[0][0], 19*19, INT_MAX);
	//print_dp();
}

int main() {
	init();
	cin >> N;
	string str;
	cin >> str;

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			numbers[i / 2] = str[i] - '0';
			max_dp[i / 2][i / 2] = numbers[i / 2];
			min_dp[i / 2][i / 2] = numbers[i / 2];
		}
		else ops[i / 2] = str[i];
	}

	int dist = 1;

	while (dist <= N / 2) {
		for (int i = 0; i <= N / 2 - dist; i++) {
			for (int j = i; j <= i + dist - 1; j++) {
				int results[4]{
					cal(max_dp[i][j], max_dp[j + 1][i + dist], ops[j]),
					cal(max_dp[i][j], min_dp[j + 1][i + dist], ops[j]),
					cal(min_dp[i][j], max_dp[j + 1][i + dist], ops[j]),
					cal(min_dp[i][j], min_dp[j + 1][i + dist], ops[j]),
				};

				sort(results, results + 4);
				max_dp[i][i + dist] = max(max_dp[i][i + dist], results[3]);
				min_dp[i][i + dist] = min(min_dp[i][i + dist], results[0]);
			}
		}
		//print_dp();
		dist++;
	}

	cout << max_dp[0][N / 2];
}