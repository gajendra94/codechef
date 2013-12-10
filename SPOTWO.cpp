#include <iostream>
#include <stdio.h>

using namespace std;

#define MOD 1000000007

unsigned long long fast_exp(unsigned long long a , unsigned long long  b)
{
    if(b==0)
        return 1;
    unsigned long long  x = fast_exp(a , b/2);

    x = (x*x)%MOD;

    if(b&1)
        x = (x*a)%MOD;

    return x;
}

unsigned long long finalSol(unsigned long long ans)
{
    ans = (ans*ans)%MOD;
    return ans;
}

unsigned long long findDecimal(unsigned long long p)
{
    if(p==0)
        return 0;
    if(p==1)
        return 1;
    unsigned long long q = findDecimal(p/2);

    if(p&1)
        q = q*10 + 1;
    else
        q = q*10;

    return q;
}
int main()
{
    int t , n;
    scanf("%d" , &t);

    while(t--)
    {
        scanf("%d" , &n);


        unsigned long long p = finalSol(fast_exp(2 , findDecimal(n)))%MOD;

        printf("%llu\n" ,p );
    }

}
