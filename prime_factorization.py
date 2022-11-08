import math

def check_prime(A):
    end = (int)(math.sqrt(A)) + 1;
    for i in range(2, end):
        print(i)
        if A % i == 0:
            return True
    return False;


number = 12545213545623546547;

print(check_prime(number))