line = input()
t1,t2,n = line.split()

t1 = int(t1)
t2 = int(t2)
n = int(n)

tab=[]
tab.append(t1)
tab.append(t2)


for i in range(n-2):
    tab.append((tab[i+2-1]*tab[i+2-1])+ tab[i+2-2])

print(tab[n-1])


