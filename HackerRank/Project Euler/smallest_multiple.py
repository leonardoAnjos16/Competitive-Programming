import math

def is_prime(number):
    sqrt = math.sqrt(number)

    counter = 2
    while counter <= sqrt:
        if number % counter == 0:
            return False

        counter += 1

    return True


def get_primes(number):
    primes = dict()

    while number > 1:
        counter = 2
        while True:
            if is_prime(counter) and number % counter == 0:
                break

            counter += 1

        if counter in primes.keys():
            primes[counter] += 1
        else:
            primes[counter] = 1

        number /= counter

    return primes


def main():
    num_cases = int(input())

    for i in range(num_cases):
        limit = int(input())

        primes = dict()
        counter = 2

        while counter <= limit:
            aux = get_primes(counter)

            for key, value in aux.items():
                if not key in primes.keys() or primes[key] < value:
                    primes[key] = value

            counter += 1

        mult = 1
        for key, value in primes.items():
            mult *= key ** value

        print(mult)


if __name__ == "__main__":
    main()