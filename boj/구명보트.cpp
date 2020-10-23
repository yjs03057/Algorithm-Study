#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());
	int lo = 0;
	int hi = people.size() - 1;

	while (lo <= hi) {
		if (people[lo] + people[hi] >= limit) {
			lo++;
			hi--;
		}
		else {
			hi--;
		}
		answer++;
	}

	return answer;
}

int main() {
	cout << solution({70, 50, 80, 50 }, 100);
}