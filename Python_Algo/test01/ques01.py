
# �ܹ��� �� �ֹ��ϱ� 
N, M = map(int, input().split())

# �ּҰ��� ã�� ����
pmin, omin = 1000, 1000

for _ in range(M):
    p, o = map(int, input().split())
    if p < pmin: pmin = p
    if o < omin: omin = o

# set price is higher than 6 goods
q, r = N//6, N%6 # q,r = divmod(n, 6)
price = q*pmin

# if set price is lower than r goods
if pmin < omin*r : price += pmin
else : price += omin*r
print(price)