#include<bits/stdc++.h>
using namespace std;
int rod_cutting(int len[],int pri[],int n,int length)
{
      int t[n+1][length+1];
      for(int i= 0;i<n+1;i++)
      {
          for(int j =0;j<length+1;j++)
          {

              if(i ==0||j ==0)
              {
                  t[i][j] = 0;
              }
          }
      }
      for(int i= 1;i<n+1;i++)
      {
          for(int j =1;j<length+1;j++)
          {

             if(len[i-1] <= j)
             {
                 t[i][j] = max(pri[i-1]+ t[i][j - len[i-1]],t[i-1][j]);
             }
             else
             {
                 t[i][j] = t[i-1][j];
             }
          }
      }
      int j = length;
      for(int i= 1;i<n+1;i++)
      {
          if(t[i][j] != 0)
          {
              cout<<i<<endl;
          }
      }
   return t[n][length];
}
int main()
{
    int n;
    cout<<"enter the size length of array"<<endl;
    cin>>n;
    int len[n];
    int pri[n];
    cout<<"enter the length o f rod"<<endl;
    int length;
    cin>>length;
    cout<<"enter the length array"<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>len[i];
    }
    cout<<"enter the price array"<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>pri[i];
    }

    cout<<rod_cutting(len,pri,n,length)<<endl;


}
