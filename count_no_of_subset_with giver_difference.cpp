#include<bits/stdc++.h>
using namespace std;
int subset_sum(int arr[],int n,int sum)
{

    int t[n+1][sum+1];
    for(int i =0;i<n+1;i++)
    {
        for(int j =0;j<sum+1;j++)
        {
            if(j == 0)
            {
                t[i][j] = 1;
            }
            else if(i ==0 && j!=0)
            {
                t[i][j] = 0;
            }
        }
    }
    for(int i =1;i<n+1;i++)
    {
        for(int j =1;j<sum+1;j++)
        {
            if(arr[i-1] <= j)
            {
                t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j]);
            }
            else t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}
int main()
{
    int n;
    cout<<"enter the  size of array"<<endl;
    cin>>n;
    int diff;
    cout<<"enter  diff"<<endl;
    cin>>diff;
    int arr[n];
    cout<<"enter the  element of array"<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum = 0;
    for(int i =0;i<n;i++)
    {
        sum = sum +arr[i];
    }
    int sub1 = (diff + sum)/2;
    cout<<subset_sum(arr,n,sub1)<<endl;

}


