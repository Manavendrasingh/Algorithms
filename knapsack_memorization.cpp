#include<bits/stdc++.h>
using namespace std;
int t[101][1001];

int knapsack(int wt[],int val[],int w,int n)
{
    if(n == 0||w==0)
    {
        return 0;
    }
    if(t[n][w] != -1)
    {
        return t[n][w];
    }
    if(wt[n-1] <= w)
    {
       return t[n][w] = max(val[n-1] + knapsack(wt,val,w - wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    else if(wt[n-1] > w)
    {
       return t[n][w] = knapsack(wt,val,w,n-1);

    }
}
int main()
{
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int wt[n];
    int val[n];
    cout<<"enter the knapsack capacity"<<endl;
    int weight;
    cin>>weight;
    cout<<"enter the weight array"<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>wt[i];
    }
    cout<<"enter the value array"<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>val[i];
    }
    memset(t,-1,sizeof(t));
    cout<<knapsack(wt,val,weight,n)<<endl;


}
