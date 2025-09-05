import sys
num=int(sys.stdin.readline().strip())
ll=list()
for i in range(num):
    ll.append(sys.stdin.readline().strip())

ll.sort(key=str)
for item in ll:
    print(item)
