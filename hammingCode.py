import numpy
def main():
    B = input("Enter bit string: ")
    print("Message: ", generateCode(B))
        
def generateCode(B):
    r = findR(len(B))
    M = ['0' for i in range(r + len(B) + 1)]
    j = 0
    for i in range(1, len(M)):
        if numpy.log2(i) % 1 != 0:
            M[i] = B[j]
            j += 1
    R = []
    for i in range(r):
        R.append(findPos(i, r, len(B) + r))
        
    j = 0;
    for r in R:
        c = 0;
        for i in r:
            if M[i] == '1':
                c += 1
        if c % 2 != 0:
            M[2**j] = '1'
        j += 1

    outMsg = ""
    for i in range(1, len(M)):
        outMsg += M[i]
    return outMsg
    
    
def findR(m):
    r = 1
    while 2 ** r < m + r + 1:
        r += 1
    return r

def findPos(i, r, maxL):
    R = []
    for k in range(2 ** i, 2 ** (i + 1)):
        j = k
        while j <= maxL:
            R.append(j)
            j += 2**(i + 1)        
    return R

if __name__ == '__main__':
    main()

