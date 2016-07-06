# Find the smallest cube for which exactly five permutations of its digits
# are cube.

from collections import defaultdict

def generate_cubes(N):
    '''Returns a list of all cubes from 0 to N'''
    C = []
    for i in range(1, N + 1):
        C.append(i**3)
    return C

def sort_digits(N):
    return ''.join(sorted(str(N)))

cubes = generate_cubes(10000)
mapping = defaultdict(int) # Map from sorted digit values to num occurences
smallest = {} # Holds smallest cube for each sorted digit value

for i in cubes:
    dsort = sort_digits(i)
    mapping[dsort] += 1
    if (mapping[dsort] == 1):
        smallest[dsort] = i # First occurence of dsort
    if (mapping[dsort] == 5): # Fifth occurence of dsort -> print smallest
        print smallest[dsort]
        break

