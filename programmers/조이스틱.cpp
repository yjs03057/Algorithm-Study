#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int answer;

int check_move(int N, int i, string name, string compare) {
	int left = 0; int right = 0; int index = 0;
	for (int j = i + 1; j < i + N; j++) {
		if (name[j % N] != compare[j % N]) {
			right = j - i;
			index = j % N;
			break;
		}
	}

	for (int j = i - 1; j > i - N; j--) {
		if (name[(N + j) % N] != compare[(N + j) % N]) {
			left = i - j;
			if(left < right) index = (N + j) % N;
			break;
		}
	}
	answer += min(left, right);
	return index;
}

int solution(string name) {
	answer = 0;
	int N = name.length();
	int a_num = 'A' - '0';
	string compare(N, 'A');

	int i = 0;
	while (name != compare) {
		if(name[i] == compare[i]) i = check_move(N, i, name, compare);
		if (name[i] != 'A') {
			int move = (name[i] - '0') - a_num;
			if (move > 13) move = 26 - move;
			answer += move;
			compare[i] = name[i];
		}
	}
	return answer;
}

int main() {
	cout<<solution("JEROEN")<<endl;
	cout << solution("JAN") << endl;
	cout << solution("ABABAAAAABA") << endl;
}