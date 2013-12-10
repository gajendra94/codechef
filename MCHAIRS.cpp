#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

#define MOD 1000000007;

 long long int fast_exp(long long int a ,long long int b)
{
  if(b==0)
        return 1;
  long long int x = fast_exp(a , b/2);
  x = (x*x)%MOD;
  if(1&b)
    x = (x*a)%MOD;
  return x;
}

int main()
{
    int t , n;

    scanf("%d" , &t);

    while(t--)
    {
        scanf("%d" , &n);

        long long int p = (fast_exp(2 , n)-1)%MOD;

        printf("%lld\n" , p);
    }
}
