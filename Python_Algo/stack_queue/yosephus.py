# use list for queue
n, k = map(int, input().split())

# add 1..n into the queue
queue = [ i for i in range(1, n+1)]

# while queue is not empty
while len(queue)>0:
    # k-1 pop and put
    for _ in range(k-1):
        queue.append(queue.pop(0))
    # print popped item
    print(queue.pop(0))