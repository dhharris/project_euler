# Using words.txt, how many words are triangle words?

def char_to_int(c):
    """Find value of a character. Ignores anything that isn't a letter"""
    return {
        'A':1,
        'B':2,
        'C':3,
        'D':4,
        'E':5,
        'F':6,
        'G':7,
        'H':8,
        'I':9,
        'J':10,
        'K':11,
        'L':12,
        'M':13,
        'N':14,
        'O':15,
        'P':16,
        'Q':17,
        'R':18,
        'S':19,
        'T':20,
        'U':21,
        'V':22,
        'W':23,
        'X':24,
        'Y':25,
        'Z':26,
    }.get(c,0)

def strsum(s):
    """Calculate word value"""
    sum = 0
    for c in s:
        sum += char_to_int(c)
    return sum

def generate_tri_seq(N, t):
    """Create triangle sequence for i = 1, ..., N"""
    for i in range(1, N + 1):
        t[i * (i + 1) / 2] = 1


# Read in data
f = open('../data/p042_words.txt', 'r')
data = f.read().split(',')

# Create dictionary with triangle numbers as keys
t = {}
generate_tri_seq(1000, t)

# Calculate result
count = 0
for word in data:
    if strsum(word) in t:
        count += 1
print count
