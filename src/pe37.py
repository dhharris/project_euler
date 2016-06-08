# Find the sum of the only eleven primes that are both truncatable from
# left to right and right to left

def is_prime(n):
    """Returns True if n is prime."""
    if n <= 1:
        return False
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

def trunc_left(s):
    return s[1:]
def trunc_right(s):
    return s[0:-1]



primes = []
for i in range(23, 740000, 2):
    if i % 10 != 3 and i % 10 != 7:             # Last digit must me 3 or 7
        continue
    first = int(str(i)[0])
    if not is_prime(first):                     # First digit must be prime
        continue

    flag = True

    l = r = str(i)
    while l and r:
        if not is_prime(int(r)) or not is_prime(int(l)):
            flag = False
            break
        l = trunc_left(l)
        r = trunc_right(r)

    if flag and i not in primes:
        primes.append(i)

print sum(primes)
