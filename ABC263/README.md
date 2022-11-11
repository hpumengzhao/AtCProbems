# Solution

## E

令 $dp[i]$ 表示从 $i$ 移动到 $n$ 的期望次数，显然有：

$dp[n]$ = $0$

对于第 $i$ 个位置我们可以掷出$[0, A[i]]$的结果，因此我们可以得到如下转移方程：
$$
dp[i] = \frac{\sum_{j = i}^{j + A[i]}dp[j]}{A[i] + 1} + 1
$$
移项可得：
$$
dp[i] = (\frac{\sum_{j = i + 1} ^ {A[i] + i}dp[j]}{A[i] + 1}) \times \frac{A[i] + 1}{A[i]}
$$
地推转移即可，时间复杂度$O(nlog(mod))$。