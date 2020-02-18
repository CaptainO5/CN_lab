M = input("Enter bit string: ")
r = int(input("Enter length of r: "))

def findPos(i, r, maxL):
    R = []
    for k in range(2 ** i, 2 ** (i + 1)):
        j = k
        while j <= maxL:
            R.append(j)
            j += 2**(i + 1)        
    return R

R = []
for i in range(r):
    R.append(findPos(i, r, len(M)))


t = '0' + M
err = ''

for i in R:
    c = 0
    for j in i:
        if t[j] == '1':
            c += 1
    if c % 2 == 0:
        err = '0' + err
    else:
        err = '1' + err

print("Error is at:", err)
