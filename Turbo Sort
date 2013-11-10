#include <iostream>
#include<stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    unsigned long long t , i=0;
    cin>>t;
    vector<unsigned long long> number(t);
    while(t--)
    {
        scanf("%llu",&number[i]);
        i++;
    }

    sort(number.begin() , number.end());

    for(unsigned long long i = 0 ; i<number.size() ; i++)
        printf("%llu\n" ,number[i]);
    return 0;
}
