#include <iostream>
#include <stdio.h>
#include <string>
#include <limits>
#include <cctype>
#include <algorithm>
#include<vector>

using namespace std;

int main()
{
    unsigned long long t;
    cin>>t;

    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    while(t--)
    {
        string str1 , str2;

        char ch = 'a';

        vector< pair<int , char> > alpha;

        for(int i=0 ; i<26 ; i++)
            alpha.push_back(make_pair(0 , ch++));


        getline(cin , str1);

        getline(cin , str2);

        unsigned long long q = str2.length();

        for(unsigned long long  i=0 ; i<q ; i++)
        {
            if((str2[i]>='a'&&str2[i]<='z')||(str2[i]>='A' && str2[i]<='Z'))
            {
                if(isupper(str2[i]))
                    alpha[str2[i]-'A'].first++;
                else
                    alpha[str2[i]-'a'].first++;
            }
        }

        sort(alpha.begin() , alpha.end());


        char a[q];

        unsigned long long  k=0;

        for(unsigned long long  i=0 ; i<q ; i++)
        {
            char c = str2[i];

            if( (c>='a' && c<='z') || (c>='A' && c<='Z'))
            {
                if(isupper(c))
                {
                    for(int j=0 ; j<26 ; j++)
                    {
                        if(alpha[j].second == tolower(c))
                        {
                            a[k++] = toupper(str1[j]);
                            break;
                        }
                    }
                }
                else
                {
                    for(int j=0 ; j<26 ; j++)
                    {
                        if(alpha[j].second == c)
                        {
                            a[k++] = str1[j];
                            break;
                        }
                    }

                }
            }
            else
            {
                a[k++] = str2[i];
            }
        }

        for(unsigned long long i=0 ; i<q ; i++)
            cout<<a[i];

        cout<<endl;
    }

}
