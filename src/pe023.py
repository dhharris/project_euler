# Find the sum of all the positive integers which cannot be written as the
# sum of two abundant numbers.

def is_abundant(n):
    s = 0
    i = 1

    while i * i <= n:
        if n % i == 0:
            s += i
            if n / i != i:
                s += n / i
        i += 1

    return s > 2 * n

abundants = {}
for i in range(12, 20162 - 12):
    if is_abundant(i):
        abundants[i] = True

sums = {}
s = 0
for a in abundants:
    for b in abundants:
        if b <= a:
            sums[a + b] = True
for i in range(1, 20162):
    if i not in sums:
        s += i
print s
