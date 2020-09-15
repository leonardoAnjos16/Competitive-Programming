num_test_cases = int(input())

for i in range(num_test_cases):
    number = int(input())

    sum = 0
    first = 1
    second = 1
    fib = 0

    while fib < number:
        fib = first + second
        if fib > number:
            break

        if fib % 2 == 0:
            sum += fib

        first = second
        second = fib

    print(sum)