# If p is the perimeter of a right angle triangle with integral length sides
# {a,b,c}, there are exactly three solutions for p = 120.
# {20,48,52}, {24,45,51}, {30,40,50}
# For which value of p <= 1000 is the number of solutions maximised?
#
# My solution uses a map reduce technique to generate perimeters from
# pythagorean triples, and finds the most common occuring value

# Generate triples until perimeter hits N
def generate_triples(N, triples):
    for x in range(1, N):
        y = x + 1
        z = y + 1
        while x + y + z <= N:
            while z * z < x * x + y * y:
                z += 1
            if z * z == x * x + y * y and x + y + z <= N:
                triples.append([x, y, z])
            y += 1

triples = []
generate_triples(1000, triples)         # Create list of pythagorean triples
perimeters = [sum(t) for t in triples]  # Convert triples to sums ("Map")

reduced = {}

# Create dictionary with number of occurences for each perimeter ("Reduce")
for t in set(perimeters):
    reduced[t] = perimeters.count(t)

# Print key with max value
print max(reduced.iterkeys(), key=(lambda key: reduced[key]))
