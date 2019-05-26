import sys

def binomial(n, k):
	if 0 <= k <= n:
		ntok = 1
		ktok = 1
		for t in range(1, min(k, n - k) + 1):
			ntok *= n
			ktok *= t
			n -= 1
		return ntok // ktok
	else:
		return 0

while True :
	N, K = map(int, input().split())

	if (N == 0 and K == 0) :
		break
	
	print(binomial(N+K-1, K-1) % 1000000)
	







