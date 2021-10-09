num = input()
num = list(num)

s = input()
s = list(s)

s.sort(reverse=True)

for i in range(len(num)):
    if len(s) > 1 and num[i] < s[0]:
        num[i] = s[0]
        s.pop(0)

num = ''.join(num)
print(num)
