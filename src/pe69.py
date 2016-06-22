# Find the value of n <= 1000000 for which n / Phi(n) is a maximum
#
# Well, we can simply multiply all primes together until we get a number
# greater than 1000000 because the function is going to be maximized
# when n has the most prime factors.

from __future__ import generators

def eratosthenes():
    '''Yields the sequence of prime numbers via the Sieve of Eratosthenes.'''
    D = {}  # map composite integers to primes witnessing their compositeness
    q = 2   # first integer to test for primality
    while 1:
        if q not in D:
            yield q        # not marked composite, must be prime
            D[q*q] = [q]   # first multiple of q not already marked
        else:
            for p in D[q]: # move each witness to its next multiple
                D.setdefault(p+q,[]).append(p)
            del D[q]       # no longer need D[q], free memory
        q += 1

pgen = eratosthenes()
product = 1

for i in pgen:
    if (product * i < 1000000):
        product *= i
    else:
        break

print product
