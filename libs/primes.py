# Sieve of Eratosthenes
# David Eppstein, UC Irvine, 28 Feb 2002

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

pgen = eratosthenes()
for i in pgen:
    if is_prime(i + 4):
        print i
