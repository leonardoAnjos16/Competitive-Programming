n, s = input().split()
n, s = int(n), int(s)

bidders = []
for i in range(n):
    t, b = input().split()
    bidders.append((int(b), t))

bidders.sort(reverse=True)

ans = []
for i in range(n):
    if bidders[i][0] <= s:
        ans.append(bidders[i][1])
        s -= bidders[i][0]

if s > 0:
    ans = []

print(len(ans))
for name in ans:
    print(name)
