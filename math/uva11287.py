# def is_prime(n):
#     if (n <= 1):
#         return False;
#     elif (n <= 3):
#         return True;
#     elif (n % 2 == 0 or n % 3 == 0):
#         return False;
#     i = 5;
#     while (i * i <= n):
#         if (n % i == 0 or n % (i + 2) == 0):
#             return False;
#         i = i + 6;
#
#     return True;

import random

def miller_rabin(n, k):



    if n == 2:
        return True

    if n % 2 == 0:
        return False

    r, s = 0, n - 1
    while s % 2 == 0:
        r += 1
        s //= 2
    for _ in range(k):
        a = random.randint(2, n - 1)
        x = pow(a, s, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True

p, a = input().split()
p = int(p)
a = int(a)
while (a != 0 and p != 0):
    check = ((a**p) % p == a) and not miller_rabin(p, 5)
    if (check):
        print("yes")
    else:
        print("no")
    p, a = input().split()
    p = int(p)
    a = int(a)
