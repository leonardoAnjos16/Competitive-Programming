import math

def is_prime(number):
    sqrt = math.sqrt(number)

    counter = 2
    while counter <= sqrt:
        if number % counter == 0:
            return False

        counter += 1

    return True


def get_first_prime_from(number):
    number += 1

    while True:
        if is_prime(number):
            return number

        number += 1


def get_prime(primes, pos):
    if primes[pos] == 0:
        counter = 1
        while primes[counter] != 0:
            counter += 1

        while counter <= pos:
            primes[counter] = get_first_prime_from(primes[counter - 1])
            counter += 1

    return primes[pos]


def main():
    num_cases = int(input())

    primes = []
    cases = []

    max = 0
    for i in range(num_cases):
        cases.append(int(input()))
        
        if cases[i] > max:
            max = cases[i]

    for i in range(max):
        primes.append(0)

    primes[0] = 2
    for i in range(num_cases):
        print(get_prime(primes, cases[i] - 1))


if __name__ == "__main__":
    main()