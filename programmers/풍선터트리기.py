
def solution(a):
    N = len(a)
    answer = 0
    left = []
    right = []

    left_val = a[0]
    right_val = a[-1]
    for i in range(N):
        left_val = min(left_val, a[i])
        left.append(left_val)
        right_val = min(right_val, a[N-i-1])
        right.insert(0, right_val)
    
    print(right)
    for i in range(N):
        if left[i] < a[i] and right[i] < a[i]: continue
        answer += 1

    return answer

print(solution([-16,27,65,-2,58,-92,-71,-68,-61,-33]))