#include <iostream>
#include <vector>
using namespace std;
void solve(int idx, vector<int> v, int arr[], int n)
{
    if (idx == n){
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;    
        return;
    }

    v.push_back(arr[idx]);
    //pick
    solve(idx + 1, v, arr, n);

    v.pop_back();
    //not pick
    solve(idx + 1, v, arr, n);
}

int main()
{
    int arr[] = {3, 2, 1};
    int n = 3;
    vector<int> v;

    solve(0, v, arr, n);
}