#-*-coding:utf-8-*-
n, k = map(int, input().split())
numbers = input()

# make a stack
stack = []

n -= k
for c in numbers:
    # len(stack) : pop해야해서 0보다 커야 함
    # k : 삭제할 수 있는 개수가 0보다 커야 함
    while len(stack) > 0 and k > 0 and stack[-1]<c: 
        stack.pop()
        k -= 1
    stack.append(c)

print(''.join(stack[:n]))



