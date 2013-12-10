#include <iostream>
#include <stdio.h>

using namespace std;

int max(int a, int b)
{
    if(a>=b)
        return a;
    return b;
}

int max_score(int **s , int n)
{
    int dp[n][n];

    dp[0][0] = s[0][0];

    for(int i=1 ; i<n ; i++)
    {
        dp[i][0] = dp[i-1][0] + s[i][0];
        dp[0][i] = dp[0][i-1] + s[0][i];
    }

    for(int i=1 ; i<n ; i++)
        for(int j=1 ; j<n ; j++)
            dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) + s[i][j];

    return dp[n-1][n-1];
}
int main()
{
    int t ;

    scanf("%d" , &t);

    while(t--)
    {
        int n;
        scanf("%d" , &n);

        int **s = new int*[n];

        for(int i=0 ; i<n ; i++)
            s[i] = new int[n];

        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<n ; j++)
                scanf("%d" , &s[i][j]);

        int d = max_score(s , n);
        if( d >= 0)
            printf("%.6f\n" , d/double(2*n-3));
        else
            printf("%s\n" , "Bad Judges");
    }



}
