cases = 1
while True:
    line = input().split()
    if line[0] == '0' and line[1] == '0':
        break

    deg = int(line[0])

    coeffs = []
    for i in range(deg + 1):
        coeffs.append(int(line[i + 1]))

    x = int(line[-1])

    ans = 0
    for i in range(deg + 1):
        ans += coeffs[i] * (x ** (deg - i))

    sub = 0
    cnt = len(str(coeffs[-1])) + 1

    for i in range(deg - 1, -1, -1):
        if coeffs[i] > 0:
            cnt += 1 + 2 * (deg - i - sub) + len(str(coeffs[i]))
            sub += deg - i - sub

    if coeffs[0] == 1:
        cnt -= 2

    if coeffs[-1] == 0:
        cnt -= 2

    print("Polynomial " + str(cases) + ": " + str(ans) + " " + str(cnt))
    cases += 1
