# Considering natural numbers of the form, a^b, where a, b < 100, what is the
# maximum digital sum?

def digital_sum(n):
    sum = 0
    while n:
        sum += n % 10
        n /= 10
    return sum

max = 0

for a in range(1, 100):
    for b in range(1,100):
        sum = digital_sum(a**b)
        if sum > max:
            max = sum

print max
