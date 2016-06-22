# By listing the set of reduced proper fractions for d <= 1000000 in
# ascending order of size, find the numerator of the fraction immediately to
# the left of 3/7.

from fractions import Fraction
from fractions import gcd

fractions = [Fraction(3, 7)]
d = 999997 # Optimized from d in range(999990, 1000000)
for n in range(1, d / 2):
    if gcd(n, d) == 1:
        fractions.append(Fraction(n, d))

fractions.sort()
print fractions[fractions.index(Fraction(3, 7)) - 1]

