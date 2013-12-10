#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n , q;

    scanf("%d%d" , &n , &q);

    int a[n];
    int dp[n];
    vector <pair<int ,int > > g;
    vector<pair<int , int> > t;

    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &a[i]);

        if(i==0)
            dp[0] = a[0];
        else
            dp[i] = dp[i-1]+a[i];

    }


    while(q--)
    {
        char ch;
        int i , j;

        scanf(" %c%d%d" , &ch ,&i , &j);


        if(ch=='S')
        {
            unsigned long long  total = dp[j] ;
            if(i==0)
            {
                if(g.size())
                {
                    for(int k=0 ; k<g.size() ; k++)
                    {
                        if(j>=g[k].first)
                            total+=g[k].second;
                    }
                }

                if(t.size())
                {
                    for(int k=0 ; k<t.size() ; k++)
                    {
                        if(j>=t[k].first)
                            total-=t[k].second;
                    }
                }
                printf("%llu\n" , total);
            }
            else
            {
                if(g.size())
                {
                    for(int k=0 ; k<g.size() ; k++)
                    {
                        if(i<=g[k].first && j>=g[k].first)
                            total+=g[k].second;
                    }
                }

                if(t.size())
                {
                    for(int k=0 ; k<t.size() ; k++)
                    {
                        if(i<=t[k].first && j>=t[k].first)
                            total-=t[k].second;
                    }
                }
                printf("%llu\n" , total-dp[i-1]);
            }
        }
        else
            if(ch=='G')
            {
                g.push_back(make_pair(i , j));
            }
            if(ch=='T')
            {
                t.push_back(make_pair(i , j));
            }
    }
}
