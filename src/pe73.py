# How many fractions lie between 1/3 and 1/2 in the sorted set of
# reduced proper fractions for d <= 12000?

from fractions import gcd

count = 0

# None for d < 5
for d in range(5, 12001):
    for n in range(d / 3, d / 2):
        if gcd(n, d) == 1:
            count += 1

print count
