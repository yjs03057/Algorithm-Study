import sys
from collections import deque

N = int(input())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
q = deque()

for x in range(N):
    for y in range(N):
        end_point = True
        for dx, dy in dirs:
            nx, ny = x + dx, y + dy
            if nx < 0 or ny < 0 or nx >= N or ny >= N: continue
            if board[x][y] < board[nx][ny]: end_point = False
        if end_point: q.append([x, y])

answer = 1
temp = deque()
while q:
    x, y = q.pop()
    for dx, dy in dirs:
        nx, ny = x + dx, y + dy
        if nx < 0 or ny < 0 or nx >= N or ny >= N: continue
        if board[x][y] > board[nx][ny]: 
            temp.append([nx, ny])
    if not q:
       if temp: 
           q = temp
           answer += 1
       temp.clear()
print(answer)