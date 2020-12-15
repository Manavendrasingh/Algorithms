#include<bits/stdc++.h>
using namespace std;
int minimumcoin(int coin[],int n,int sum)
{
    int t[n+1][sum+1];
    for(int i =0 ;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i ==0)
            {
                t[i][j] = INT_MAX -1;
            }
            if(j ==0 & i!=0)
            {
                t[i][j] = 0;

            }
        }
    }
     for(int i =1 ;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(j%coin[i-1] == 0)
            {
                t[i][j] = j/coin[i-1];
            }
            if(j%coin[i-1] != 0)
            {
                t[i][j] = INT_MAX -1;

            }
        }
    }
    for(int i =2 ;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(coin[i-1]<=j)
            {
                t[i][j] = min(t[i][j-coin[i-1]]+1,t[i-1][j]);
            }
            else
                {
                    t[i][j] = t[i-1][j];

            }
        }
    }
    return t[n][sum];

}
int main()
{
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int coin[n];
    cout<<" enter the array element "<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>coin[i];
    }
    int sum;
    cout<<"enter the sum"<<endl;
    cin>>sum;
    cout<<minimumcoin(coin,n,sum)<<endl;
    return 0;
}

