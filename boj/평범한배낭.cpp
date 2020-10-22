#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001][2];
int N;
int K;

int main() {
	cin >> N >> K;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		cin >> arr[temp][0];
	}
	
	for (int i = 1; i <= K; i++) {
		if (K - i < i) {
			arr[i][1] = max(arr[K - i][1] + arr[i][0], arr[i - 1][1]);
		}
		else arr[i][1] = arr[i][0];
	}

	cout << arr[K][1] << endl;
}