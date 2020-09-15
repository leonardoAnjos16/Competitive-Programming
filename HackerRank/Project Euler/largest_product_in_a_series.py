num_cases = int(input())

for i in range(num_cases):
    num_digits, num_consec_digits = map(int, input().split())
    number_str = input()

    number = []
    for c in number_str:
        number.append(int(c))

    max_mult = 0
    for j in range(num_digits - num_consec_digits):
        mult = 1
        for k in range(j, j + num_consec_digits):
            mult *= number[k]

        if mult > max_mult:
            max_mult = mult

    print(max_mult)