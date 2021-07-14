#-*-coding:utf-8-*-
x = int(input("K = "))
coins = list(map(int, input().split()))

dp = [0]*(K+1)
dp[0] = 1
for coin in coins : 
    for i in range(K, -1, -1):
        sum = dp[i]
        for j in range(i-coin, -1, -coin):
            sum += dp[j]
        dp[i] = sum

print(dp[K])