# Although I solved this problem with mathematics (see ../proofs/pe31.png)
# I found the provided solution to be very interesting so I wrote the
# algorithm in python here. It's very fast and can compute answers for
# large amounts in a matter of milliseconds.
#
# How many ways can two pounds be made using any number of coins?
amount = 200

coins = [1, 2, 5, 10, 20, 50, 100, 200]
ways = []
for i in range(amount + 1):
    ways.append(0)

ways[0] = 1

for coin in coins:
    for j in range(coin, amount + 1):
        ways[j] += ways[j - coin]
print ways[amount]
