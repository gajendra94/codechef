#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
   int t ;
   scanf("%d" , &t);
   while(t--)
   {
       unsigned long long n;

       scanf("%llu",&n);

       string str;

       scanf("%s" , &str);

       printf("%llu\n" , (n*(n-1)/2));
   }
}
