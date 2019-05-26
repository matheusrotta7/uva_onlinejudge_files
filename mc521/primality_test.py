import random

def is_probably_prime(p, k):
    for i in range(k):
        a = random.randint(1, p-1)
        if (((a**(p-1)) % p) != 1):
            return False

    return True


n = int(input())
# print(n)
for i in range(n):
    p = int(input())
    if (is_probably_prime(p, 2)):
        print(str(p) + " is a prime")
    else:
        print(str(p) + " is not a prime")
