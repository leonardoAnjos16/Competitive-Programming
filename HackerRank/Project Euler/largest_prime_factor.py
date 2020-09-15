import math

def is_prime(number):
    sqrt = math.sqrt(number)

    counter = 2
    while counter <= sqrt:
        if number % counter == 0:
            return False

        counter += 1

    return True


def get_max(number):
    if is_prime(number):
        return number

    if number % 2 == 0:
        return get_max(number // 2)

    counter = 3
    while True:
        if is_prime(counter) and number % counter == 0:
            break

        counter += 2

    return get_max(number // counter)


def main():
    num_cases = int(input())

    for i in range(num_cases):
        number = int(input())
        print(get_max(number))


if __name__ == "__main__":
    main()