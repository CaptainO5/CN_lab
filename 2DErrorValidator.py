# Checks for single error in the given message
bitString = input("Enter your Message, format: xxxxr xxxxr xxxxr rrrr\n")
divs = bitString.split()

# Horizontal Check
def horCheck(divs):
    for B in divs[:-1]:
        count = 0
        for b in B:
            if b == '1':
                count += 1
        if count % 2 != 0:
            return divs.index(B)
    return -5


def verCheck(divs):
    for i in range(len(divs[-1])):
        count = 0
        for B in divs:
            if B[i] == '1':
                count += 1
        if count % 2 != 0:
            return i
    return -5

col = verCheck(divs) + 1
row = horCheck(divs) + 1

if col > 0 and row > 0:
    print(f"Error is at ({row}, {col})")
else:
    print("The message is error free")
