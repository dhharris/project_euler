# The number 145 is well known for the property that the sum of the factorial
# of its digits is equal to 145:
#
#   1! + 4! + 5! = 1 + 24 + 120 = 145
#
# Perhaps less well known is 169, in that it produces the longest chain of
# numbers that link back to 169; it turns out that there are only three such
# loops that exist:
#
#   169 -> 363601 -> 1454 -> 169
#   871 -> 45361 -> 871
#   872 -> 45362 -> 872
#
# It is not difficult to prove that EVERY starting number will eventually get
# stuck in a loop. For example,
#
#   69 -> 363600 -> 1454 -> 169 -> 363601 (-> 1454)
#
# Starting with 69 produces a chain of five non-repeating terms, but the
# longest non-repeating chain with a starting number below one million is
# sixty terms.
#
# How many chains, with a starting number below one million, contain exactly
# sixty non-repeating terms?

import math

# Small table so we don't need to compute factorials every time
factorials = [math.factorial(i) for i in range(0, 10)]

def next_term(n):
    '''Computes the next term in the digit factorial chain'''
    ret = 0
    while n:
        ret += factorials[n % 10]
        n /= 10
    return ret

def count_terms(n):
    '''Computes the sequence of digit factorial chains starting with n
    ending when a repeated term is reached. Returns the number of terms
    This function is memoized so if it reaches a number for which it
    already computed the sequence, it will return.'''
    seq = []
    while n not in seq:
        seq.append(n)
        n = next_term(n)

        # Check if we've already computed this sequence
        if n in cache:
            return len(seq) + cache[n]
    return len(seq)

cache = {}
count = 0
for i in range(1, 1000000):
    if i not in cache:
        cache[i] = count_terms(i)
        if cache[i] == 60:
            count += 1

print count
