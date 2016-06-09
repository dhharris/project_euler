# Find the pair of pentagonal numbers, Pj and Pk, for which their sum and
# differences are pentagonal and D = | Pk - Pj | is minimised;
# What is the value of D?

def generate_pentagonals(N):
    """Generates a set of all pentagonal numbers from n = 1, ..., N"""
    P = set()
    for i in range(1, N + 1):
        P.add(i * (3 * i - 1) / 2)
    return P

def check(P, j, k):
    """
    Checks the condition stated in the problem. Note that j and k
    are both pentagonal numbers, not indices for the sequence
    """
    return j - k in P and j + k in P

def main():
    P = generate_pentagonals(2400)

    for k in P:
        for j in P:
            if j > k and check(P, j, k):
                print j - k
                return
main()


