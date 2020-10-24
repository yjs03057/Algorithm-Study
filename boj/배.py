import sys
N = int(input())
limits = map(int, sys.stdin.readline().split())
M = int(input())
packages = map(int, sys.stdin.readline().split())

limits = sorted(limits, reverse=True)
packages = sorted(packages, reverse=True)

if packages[0] > limits[0] : print(-1)
else:
    answer = 0
    while len(packages) > 0:
        for l in limits:
            for j in range(len(packages)):
                if l >= packages[j]:
                    packages.pop(j)
                    break
        answer += 1
    print(answer)