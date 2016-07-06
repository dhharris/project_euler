# Find the sum of all numbers less than one million which are palindromic
# in base 10 and base 2

def is_pal(s):
    return s == s[::-1]

count = 0
for i in range(1, 1000000, 2):
    if is_pal(str(i)) and is_pal(str(bin(i))[2:]):
            count += i

print count
