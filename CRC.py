bitString = input("Enter Bit String: ")
key = input("Enter Key: ")

def div(dividend, divisor):
    l = len(divisor)
    t = dividend[0:l]
    r = xor(t, divisor)
    dividend = dividend[l:]
    
    while(True):
        r = r[1:]
        t = r + dividend[0]
        if r[0] == '1':
            r = xor(t, divisor)
        else:
            r = xor(t, '0' * l)
            
        if len(dividend) == 1:
            return r
        dividend = dividend[1:]


def xor(a, b):
    if len(a) != len(b):
        print("Don't want to XOR, lengths are different..")
        return -5

    res=""
    for i in range(len(a)):
        if a[i] == b[i]:
            res += '0'
        else:
            res += '1'

    return res

dividend = bitString + '0' * (len(key) - 1)
reminder = div(dividend, key)

message = bitString + reminder

print(message)
