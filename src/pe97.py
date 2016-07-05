# In 2004 there was found a massive non-Mersenne prime which contains
# 2,357,207 digits: 28433 * 2^7830457 + 1
# Find the last ten digits of this prime number.

p = 28433 * 2**7830457 + 1
digits = []
for i in range(0, 10):
    digits.append(str(p % 10))
    p /= 10
digits.reverse()
print ''.join(digits)
