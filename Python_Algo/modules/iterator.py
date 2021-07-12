def mul2o3(n):
    for i in range(1, n+1):
        if i%2==0 or i%3==0:
            yield  i

n = int(input("n = "))
sum = 0
for k in mul2o3(n):
    sum += k 
print(sum)               