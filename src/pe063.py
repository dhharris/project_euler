# How many n-digit positive integers exist which are also an nth power?

def count_digits(n):
    count = 0
    while (n):
        count += 1
        n /= 10
    return count

def check(base, exponent):
    '''We are checking to see if i^n has n digits'''
    return count_digits(base**exponent) == exponent

count = 0
for i in range(1, 10):
    for n in range(1, 25):
        if check(i, n):
            count += 1

print count
