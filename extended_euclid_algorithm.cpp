/* 
    Problem:
    Given the two integers a and b
    find the values of the variables s,t and gcd(a,b) for the following equation:
    s * a + t * b = gcd(a,b)
*/
#include<bits/stdc++.h>
using namespace std;


class Variables
{
    public:
    long long s;
    long long t;
    long long gcd;

    Variables(long long s,long long t,long long gcd)
    {
        this -> s = s;
        this -> t = t;
        this -> gcd = gcd;
    }
};

Variables extendedEuclid(long long a,long long b)
{
    long long q,r1,r2,r,s1,s2,s,t1,t2,t;

    r1 = a;
    r2 = b;

    s1 = 1;
    s2 = 0;

    t1 = 0;
    t2 = 1;

    while(r2 > 0)
    {
        q = r1 / r2;

        r = r1 - q * r2;
        s = s1 - q * s2;
        t = t1 - q * t2;

        r1 = r2;
        r2 = r;

        s1 = s2;
        s2 = s;

        t1 = t2;
        t2 = t;

    }

    return Variables(s1,t1,r1);
}

int main()
{
    long long a,b;

    cout << "Enter values of a and b: ";
    cin >> a >> b;

    Variables answer = extendedEuclid(a,b);

    cout << "\ns: " << answer.s << '\n';

    cout << "\nt: " << answer.t << '\n';
    cout << "\ngcd(a,b): " << answer.gcd << '\n';

}