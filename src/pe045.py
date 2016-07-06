# Find the next triangle number that is also pentagonal and hexagonal
#
# So, given T, P, H which are sets of triangle, pentagonal and hexagonal
# numbers, respectively, we simply take the union of the three sets

def generate_triangle(N):
    T = set()
    for i in range(1, N + 1):
        T.add(i * (i + 1) / 2)
    return T

def generate_pentagonal(N):
    P = set()
    for i in range(1, N + 1):
        P.add(i * (3 * i - 1) / 2)
    return P

def generate_hexagonal(N):
    H = set()
    for i in range(1, N + 1):
        H.add(i * (2 * i - 1))
    return H

N = 60000
T = generate_triangle(N)
P = generate_pentagonal(N)
H = generate_hexagonal(N)

print T.intersection(P.intersection(H))
