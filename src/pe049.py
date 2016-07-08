# The arithmetic sequence, 1487, 4817, 8147, in which each of the terms
# increases by 3330, is unusual in two ways: (i) each of the three terms are
# prime, and, (ii) each of the 4-digit numbers are permutations of one
# another.
#
# There are no arithmetic sequences made up of three 1-, 2-, or 3-digit
# primes, exhibiting this property, but there is one other 4-digit increasing
# sequence.
#
# What 12-digit number do you form by concatenating the three terms in this
# sequence?

from __future__ import generators
import collections
import itertools
from itertools import izip

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

def num_digits(n):
    return len(str(n))

def findsubsets(L, m):
    '''Finds all possible subsets of L with length m'''
    return set(itertools.combinations(L, m))

def is_arithmetic(seq):
    '''Test if seq is an arithmetic sequence'''
    gen = (i - j for i, j in izip(seq[:-1], seq[1:]))
    diff = next(gen, None)  # get the first element in the generator
    return all(d == diff for d in gen) # check all the others are equal to it

primes = eratosthenes()

# Chains of each prime permutation, represented by a list.
permutations = collections.defaultdict(list)


# Populate the permutations dict
for p in primes:
    if num_digits(p) == 4:
        permutations[int(''.join(sorted(str(p))))].append(p)
    if num_digits(p) > 4:
        break

for l in permutations:
    if len(permutations[l]) > 2:
        # Check each subset with length of 3 for arithmetic seq property.
        sublists = findsubsets(permutations[l], 3)
        for s in sublists:
            if is_arithmetic(s):
                print s
                break

