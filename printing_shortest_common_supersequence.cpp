
#include<bits/stdc++.h>
using namespace std;
int** lcs(string x,string y,int m,int n)
{
    int **t;
    t = new int*[m+1];
    for(int i=0;i<m+1;i++)
    {
        t[i] = new int[n+1];
    }

    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
           if(i ==0||j==0) t[i][j] = 0;
        }
    }
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
           if(x[i-1]==y[j-1])
           {
               t[i][j] = 1+t[i-1][j-1];
           }
           else
           {
               t[i][j] = max(t[i-1][j],t[i][j-1]);
           }
        }
    }
    return t;
}
string printing_scs(string a,string b,int m,int n)
{
     int i = m;
     int j = n;
     string s = "";
     int **t = lcs(a,b,m,n);
     while(i >0&& j>0)
     {
         if(a[i-1]==b[j-1])
         {
             s.push_back(a[i-1]);
             i--;
             j--;
         }
         else
            {
                if(t[i][j-1] > t[i-1][j])
                {
                    s.push_back(b[j-1]);
                    j--;
                }
                else
                {
                    s.push_back(a[i-1]);
                    i--;
                }
            }
     }
     while(i>0)
     {
         s.push_back(a[i-1]);
         i--;
     }
     while(j>0)
     {
         s.push_back(b[j-1]);
         j--;
     }
     reverse(s.begin(),s.end());
     return s;
}
int main()
{
    string x,y;
    cout<<"enter the strings"<<endl;
    cin>>x>>y;
    cout<<printing_scs(x,y,x.length(),y.length())<<endl;
}


