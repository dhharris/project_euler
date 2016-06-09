# Which prime, below one million, can be written as the sum of the most
# consecutive primes?

def is_prime(n):
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    i = 3
    while i * i <= n:
        if n % i == 0:
            return False
        i += 2
    return True

prime_sum = 0
largest = 0

for i in filter(is_prime, range(7, 4000)):
    if prime_sum >= 1000000:
        break
    prime_sum += i
    if is_prime(prime_sum):
        largest = prime_sum

print largest
