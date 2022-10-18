def solve(x, y, n, m):
	odd = (x + 1) // 2
	even = x - odd

	L = 1
	R = 1 + ((y + 1) // 2 - 1) * 2
	fi = (L + R) // 2 * ((y + 1) // 2)
	ans = 0
	ans += odd * (2 * fi + (odd - 1) * 2 * m * ((y + 1) // 2)) // 2

	L = m + 2
	R = m + 2 * (y // 2)
	fi = (y // 2) * (L + R) // 2
	ans += even * (2 * fi + (even - 1) * 2 * m * (y // 2)) // 2
	return ans





n, m  = map(int, input().split())
q = int(input())

for qq in range(q):
	a, b, c, d = map(int, input().split())
	print((solve(b, d, n, m) - solve(b, c - 1, n, m) - solve(a - 1, d, n, m) + solve(a - 1, c - 1, n, m)) % 998244353)
