def getGcd(a,b):
    r1 = 0
    r2 = 0

    r1 = a
    r2 = b

    while(r2 > 0):
        q = r1 // r2;
        r = r1 - q * r2
        r1 = r2
        r2 = r
    return r1

print("Enter Two numbers: ");

a = int(input())
b = int(input())

print(getGcd(a,b))