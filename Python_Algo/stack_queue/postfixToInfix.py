exprs = input("Enter the expression: ").split()

# 스택을 생성합니다. (파이썬에서는 리스트로 사용해도 OK)
stack = []

# exprs 리스트에서 항목을 하나씩 가져옵니다.
for e in exprs:
    if e == '+' or e == '-' or e == '*' or e =='/':
        # get 2 operands from stack
        opr2 = stack.pop()
        opr1 = stack.pop() # 첫 번째 operand를 나중에 가져옴
        if e == '+':
            r = opr1+opr2
        elif e == '-':
            r = opr1-opr2
        elif e == '*':
            r = opr1*opr2
        elif e == "/":
            r = opr1/opr2
        # put result into stack
        stack.append(r)
    else :
        # put number into stack
        stack.append(float(e))

print(stack[0])