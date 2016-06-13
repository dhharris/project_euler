# What is the smallest odd composite that cannot be written as the sum of a
# prime and twice a square?
import math

def is_prime(n):
    if n == 2:
        return True
    if n % 2 == 0:
        return False

    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

def generate_primes(N):
    '''Generate all primes between 2 and N'''
    primes = []
    primes.append(2)

    for i in range(3, N + 1, 2):
        if is_prime(i):
            primes.append(i)
    return primes

def generate_squares(N):
    '''Generate all squares between 1 and N'''
    squares = []
    for i in range(1, N + 1):
        squares.append(i**2)

    return squares

def check(N):
    if N in p:
        return False
    for j in p:
        for k in s:
            if i == j + 2 * k:
                return False
    return True

N = 6000
p = generate_primes(5000)
s = generate_squares(1000)

for i in range(9, N, 2):
    if check(i):
        print i
        break
