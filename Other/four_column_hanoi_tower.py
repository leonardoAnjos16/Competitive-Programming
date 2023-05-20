MAX = 10005

hanoi = [1] * MAX
for i in range(2, MAX):
    hanoi[i] = 2 * hanoi[i - 1] + 1

ans = [-1] * MAX
ans[0] = 0
ans[1] = 1

for i in range(2, MAX):
    for j in range(max(i - 200, 0), i - 1):
        nans = 2 * ans[j] + hanoi[i - j]
        if ans[i] == -1 or nans < ans[i]:
            ans[i] = nans

T = int(input())
while T > 0:
    N = int(input())
    print(ans[N])
    T -= 1
