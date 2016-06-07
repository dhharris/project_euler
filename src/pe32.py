# Find the sum of all products whos multiplicand/multiplier/product identity
# can be written as a 1 through 9 pandigital

products = set()

def is_pandigital(prod, m, n):
    digits = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0}
    string = str(prod) + str(m) + str(n)
    if '0' in string:
        return False
    for i in string:
        if digits[int(i)] == 1:
            return False
        digits[int(i)] += 1
    return min(digits.values()) == 1

for m in range(1, 9999):
    for n in range(1, 9999 / m):            # Disclude 5 digit numbers
        prod = m * n
        if (is_pandigital(prod, m, n)):
            products.add(prod)

print sum(products)
