import math
import time

def getFactors(A,n):
    print("Factorizing.....")
    end = (int)(math.sqrt(A)) + 1;
    start_time = time.time()
    for i in range(2, end):
        if A % i == 0:
            print(f"Factors --> {i} , {A // i}")
            break
    end_time = time.time()
    print("Number of Digits: ", n)
    print("Execution Time: ", end_time - start_time)
    print("")
    

semiprimes = [1000010666663, 10000079888899, 100000008888889, 1000000518888883, 10000000058888887, 100000005178888819, 1000000000099987889, 10000000000097987989, 100000000088787877679]
digits = [12, 13, 14, 15, 16, 18, 17, 19, 20]


for i in range(0,len(semiprimes)):
    getFactors(semiprimes[i],digits[i])


