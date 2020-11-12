def pickCard(turn, i, j):
    if i > j: return 0
    if dp[i][j]: return dp[i][j]
    if turn:
        score = max(pickCard(False, i+1, j) + cards[i], pickCard(False, i, j-1) + cards[j])
        dp[i][j] = score
        return score
    elif not turn:
        score = min(pickCard(True, i+1, j), pickCard(True, i, j-1))
        dp[i][j] = score
        return score

import sys
T = int(input())

for _ in range(T):
    N = int(input())
    cards = list(map(int, sys.stdin.readline().split()))
    dp = [[0 for _ in range(N)] for _ in range(N)]
    dp[0][0] = cards[0]
    pickCard(True, 0, N-1)
    print(dp[0][N-1])
