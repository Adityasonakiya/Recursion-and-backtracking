#include<iostream>
#include<vector>
using namespace std;
//1- Print all subsequences
void printS1(int idx,vector<int>&v,int s,int sum,int arr[],int n)
{
    if(idx==n){
        if(s==sum){
            for(int i=0;i<v.size();i++)
                cout<<v[i]<<" ";
            cout<<endl;
        }
        return;
    }
    v.push_back(arr[idx]);
    s+=arr[idx];
    
    //pick
    printS1(idx+1,v,s,sum,arr,n);

    v.pop_back();
    s-=arr[idx];

    //Not pick
    printS1(idx+1,v,s,sum,arr,n);
}

//2- To print only 1 subsequence
bool printS2(int idx,vector<int>&v,int s,int sum,int arr[],int n)
{
    if(idx==n){
        if(s==sum){
            for(int i=0;i<v.size();i++)
                cout<<v[i]<<" ";
            return true;
        }
        else return false;
    }
    v.push_back(arr[idx]);
    s+=arr[idx];
    
    //pick
    if(printS2(idx+1,v,s,sum,arr,n)==true)
        return true;

    v.pop_back();
    s-=arr[idx];

    //Not pick
    if(printS2(idx+1,v,s,sum,arr,n)==true)
        return true;
}

//3- To count the subsequences with sum k;
int count(int idx,int s,int sum,int arr[],int n)
{
    // if(s>sum)   for preventing extra traversal
    //     return 0;  
    if(idx==n){
        if(s==sum)
            return 1;
        else
            return 0;
    }
    s+=arr[idx];
    
    //pick
    int l=count(idx+1,s,sum,arr,n);

    s-=arr[idx];

    //Not pick
    int r=count(idx+1,s,sum,arr,n);

    return l+r;
}


int main()
{
    int arr[]={1,2,1,1,5,3,4};
    int n=7;
    int sum=5;
    vector<int>v;

    printS1(0,v,0,sum,arr,n);
    cout<<endl<<count(0,0,sum,arr,n);


}