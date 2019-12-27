num_cases = int(input())

for i in range(num_cases):
    number = int(input())

    sum_squares = (number * (number +  1) * ((2 * number) + 1)) // 6
    square_sum = ((number * (number + 1)) // 2) ** 2

    difference = sum_squares - square_sum
    if difference < 0:
        difference *= -1

    print(difference)