# Find the last ten digits of the series 1^1 + 2^2 + ... + 1000^1000
# My first 'one liner' solution :)

print str(sum([i**i for i in range(1, 1001)]))[-10:]
