# https://projecteuler.net/problem=33

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def simplify_denom(n, d):
    return d / gcd(n, d)

def check(n, d):
    digit = None

    if str(n)[0] in str(d):
        digit = n / 10
    elif str(n)[1] in str(d):
        digit = n % 10

    # Account for trivial examples and non-matches
    if not digit:
        return False

    # Perform cancellation of digit
    num = int(str(n).replace(str(digit), '', 1))
    den = int(str(d).replace(str(digit), '', 1))

    # Check for divide by zero
    if not den:
        return False

    return float(num)/den == float(n)/d

pn = pd = 1
for n in range(10, 100):
    for d in range(n + 1, 100):
        if check(n, d):
            pn *= n
            pd *= d

print simplify_denom(pn, pd)

