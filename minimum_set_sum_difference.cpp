#include<bits/stdc++.h>
using namespace std;
vector<int> subset_sum(int arr[],int n,int sum)
{

    int t[n+1][sum+1];
    for(int i =0;i<n+1;i++)
    {
        for(int j =0;j<sum+1;j++)
        {
            if(j == 0)
            {
                t[i][j] = true;
            }
            else if(i ==0 && j!=0)
            {
                t[i][j] = false;
            }
        }
    }
    for(int i =1;i<n+1;i++)
    {
        for(int j =1;j<sum+1;j++)
        {
            if(arr[i-1] <= j)
            {
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else {t[i][j] = t[i-1][j];}
        }
    }
    vector<int> v;
    for(int j =0;j<sum/2+1;j++)
    {

        if(t[n][j]== true)
        {
            v.push_back(j);
        }
    }
    return v;

}
int main()
{
    int n;
    cout<<"enter the  size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the  element of array"<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum = 0;
    int mn = INT_MAX;
    for(int i =0;i<n;i++)
    {
        sum = sum + arr[i];
    }
    vector<int> v = subset_sum(arr,n,sum);
    for(int j =0;j<v.size();j++)
    {
        mn = min(mn,sum - 2*v[j]);
    }
    cout<<mn<<endl;
}


