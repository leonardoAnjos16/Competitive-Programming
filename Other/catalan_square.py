def fact(n):
    ans = 1
    for i in range(n):
        ans *= i + 1

    return ans

def comb(n, k):
    return fact(n) // (fact(k) * fact(n - k))

def catalan(n):
    return comb(2 * n, n) // (n + 1)

n = int(input())

ans = catalan(n + 1)
print(ans)