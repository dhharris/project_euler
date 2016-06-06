# What is the index of the first term in the fibonacci sequence to contain 1000 digits?

cache = {0: 0, 1: 1, 2: 1}

def fib(n):
    global cache
    if n not in cache:
        cache[n] = fib(n - 1) + fib(n - 2)
    return cache[n]

def count_digits(num):
    return len(str(num))

i = 1
while True:
    f = fib(i)
    if count_digits(f) >= 1000:
        break
    i += 1
print i
