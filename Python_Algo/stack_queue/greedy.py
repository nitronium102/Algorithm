#-*-coding:utf-8-*-
n, k = map(int, input().split())
numbers = input()

# make a stack
stack = []

n -= k
for c in numbers:
    # len(stack) : pop�ؾ��ؼ� 0���� Ŀ�� ��
    # k : ������ �� �ִ� ������ 0���� Ŀ�� ��
    while len(stack) > 0 and k > 0 and stack[-1]<c: 
        stack.pop()
        k -= 1
    stack.append(c)

print(''.join(stack[:n]))



