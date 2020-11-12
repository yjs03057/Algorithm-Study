import sys

def find(x):
    if x == root[x]:
        return x
    else: return find(root[x])

def union(a, b):
    root_a, root_b = find(a), find(b)
    root[root_b] = root_a

N = int(input())
stars = [list(map(float, sys.stdin.readline().split())) for _ in range(N)]
root = [_ for _ in range(N)]
costs = {}

for i in range(N):
    for j in range(i+1, N):
        a = stars[i]
        b = stars[j]
        dist = round(((a[0] - b[0])**2 + (a[1] - b[1])**2)**0.5, 2)
        costs[(i, j)] = dist
costs = sorted(costs.items(), key = lambda x: x[1])

answer = 0
while costs:
    current = costs.pop(0)
    a, b = current[0]
    cost = current[1]
    if find(a) != find(b):
        answer += cost
        union(a, b)

print(answer)