def main():
    while True:
        B = input("Enter bit string: ")
        d = int(input("Enter division length: "))
        if len(B) % d != 0:
            print("Can not perform the operation, please check your input")
        else:
            break
    print("Message: ", generateCode(B, d))
        

def cutString(B, d):
    strList = []
    while len(B) >= d:
        strList.append(B[:d])
        B = B[d:]
    return strList

def generateCode(B, d):
    B = cutString(B, d)
    if len(B) > 1:
        Sum = addBinStrings(B[0], B[1])
        for i in range(2, len(B)):
            Sum = addBinStrings(Sum, B[i])
    else:
        Sum = B[0]

    compl = ''
    
    for i in Sum:
        if i == '0':
            compl += '1'
        else:
            compl += '0'

    outMsg = ""
    for i in B:
        outMsg += i + " "
    outMsg += compl
    return outMsg

def addBinStrings(a, b):
    if len(a) > len(b):
        b = '0' + b
        
    i = len(a)
    res = '0' * i

    while i > 0:
        i = i - 1
        if a[i] == '1' and b[i] == '1':
            if res[i] == '0':
                res = res[:i] + '0' + res[i+1:]
                if i != 0:
                    res = res[:i - 1] + '1' + res[i:]
                else:
                    res = '1' + res
            else:
                res = res[:i] + '1' + res[i+1:]
                if i != 0:
                    res = res[:i - 1] + '1' + res[i:]
                else:
                    res = '1' + res
            
        elif (a[i] == '1' and b[i] == '0') or (a[i] == '0' and b[i] == '1'):
            if res[i] == '0':
                res = res[:i] + '1' + res[i+1:]
            else:
                res = res[:i] + '0' + res[i+1:]
                if i != 0:
                    res = res[:i - 1] + '1' + res[i:]
                else:
                    res = '1' + res

    return res
    
if __name__ == '__main__':
    main()
