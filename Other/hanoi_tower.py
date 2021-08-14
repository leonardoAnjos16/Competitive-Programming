with open('input.txt', 'r') as f:
    N = int(f.readline())
    N = N // 3

ans = 2 ** (2 * N - 1)
aux = 2 ** (2 * ((N + 1) // 2) - 1)

if N % 2 > 0:
    ans += aux - 2
else:
    ans += aux - 1

with open('output.txt', 'w') as f:
    f.write(str(ans))