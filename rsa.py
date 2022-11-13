p = 94330614439790080372283084894409247771060628112247
q = 60264862959201431356289639716633433305531911461177


# power calculation using binary exponentiation with modulo arithmetic
def power(x, y, p) :
    res = 1     # Initialize result
 
    x = x % p
     
    if (x == 0) :
        return 0
 
    while (y > 0) :
         
        # If y is odd, multiply
        # x with result
        if ((y & 1) == 1) :
            res = (res * x) % p
 
        # y must be even now
        y = y >> 1      # y = y/2
        x = (x * x) % p
         
    return res

 

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

def getInverse(a,n):
    r1 = n
    r2 = a

    t1 = 0
    t2 = 1

    while r2 > 0:
        q = r1 // r2;
        r = r1 - q * r2
        t = t1 - q * t2

        r1 = r2
        r2 = r

        t1 = t2
        t2 = t
    
    return t1
def getPublicKey(p,q):
    phin = (p - 1) * (q - 1)

    for i in range(2,phin):
        if getGcd(i,phin) == 1:
            return i
    return -1

def getPrivateKey(e,phin):
    return (getInverse(e,phin) + phin) % phin

print("Enter the first Prime Number(p): ")

p = (int)(input())

print("Enter Second Prime Number(q): ")

q = (int)(input())

n = p * q

phin = (p - 1) * (q - 1)

print("Processing for public key (e): ")

e = getPublicKey(p,q)

print('Public Key: [e,n] --> [{},{}]'.format(e,n))

d = getPrivateKey(e,phin)

print('Private Key: [d,n] --> [{},{}]'.format(d,n))

print("Verificartion......")

print("Enter Integer message(This will be encrypted using public key: ")

M = (int)(input())

C = power(M,e,n)

print('CipherText: {}'.format(C))

message = power(C,d,n)

print('Decrypted Message: {}'.format(message))



























