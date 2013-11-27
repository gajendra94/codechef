#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int t , n , ans , otherDivisor;

    scanf("%d" , &t);

    while(t--)
    {
        scanf("%d" , &n);

        ans = n-1;

        for(int i = (int)sqrt(n) ; i>=1 ; i--)
            if(n%i==0)
            {
                otherDivisor = n/i;
                ans = otherDivisor - i;
                break;
            }

        printf("%d\n",ans);


    }
}
