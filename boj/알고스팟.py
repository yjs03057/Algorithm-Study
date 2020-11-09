import sys
from collections import deque
M, N = map(int, input().split())
board = [list(map(int, sys.stdin.readline().strip())) for _ in range(N)]
check = [[10000 for _ in range (M)] for _ in range (N)]

dir = [(-1, 0), (1, 0), (0, -1), (0, 1)]
q = deque()
q.append([0, 0])
check[0][0] = 0

while q:
    x, y = q.popleft()
    for dx, dy in dir:
        nx, ny = x+dx, y+dy
        if nx < 0 or ny < 0 or nx >= N or ny >= M: continue
        if check[x][y] + board[nx][ny] < check[nx][ny]:
            check[nx][ny] = check[x][y] + board[nx][ny]
            q.append([nx, ny])

print(check[N-1][M-1])