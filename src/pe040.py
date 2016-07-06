# Champernowne's constant

num = '.'
for i in range(1, 200000):
    num += str(i)

prod = i = 1
while i <= 1000000:
    prod *= int(num[i])
    i *= 10
print prod
