def cutString(B, d):
    strList = []
    while len(B) >= d:
        strList.append(B[:d])
        B = B[d:]
    return strList

def lngPrt(B, d):
    lng = ''
    for i in range(d):
        c = 0
        for s in B:
            if s[i] == '1':
                c += 1
        if c % 2 == 0:
            lng += '0'
        else:
            lng += '1'

    return lng

def addPrt(B):
    for i in range(len(B)):
        s = B[i]
        c = 0
        for b in s:
            if b == '1':
                c += 1
        if c % 2 == 0:
            s += '0'
        else:
            s += '1'
        B[i] = s

def generateCode(B, d):
    B = cutString(B, d)
    addPrt(B)
    s = lngPrt(B, d)
    outMsg = ''
    for i in B:
        outMsg += i
        outMsg += " "
    outMsg += s
    return outMsg

def main():
    while True:
        B = input("Enter bit string: ")
        d = int(input("Enter division length: "))
        if len(B) % d != 0:
            print("Can not perform the operation, please check your input")
        else:
            break
    print("Message: ", generateCode(B, d))
        
if __name__ == '__main__':
    main()
        
