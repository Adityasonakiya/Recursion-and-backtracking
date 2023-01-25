#include<iostream>
#include<vector>
using namespace std;

//using double pointer
void reverse1(int a[],int start,int end)
{
    if(start>=end)
        return;
    swap(a[start],a[end]);
    reverse1(a,start+1,end-1);
}

//using single pointer
void reverse2(int a[],int i,int n){
	if(i==n/2)
		return;
	swap(a[i],a[n-1-i]);
	reverse2(a,i+1,n);
}

//palindrome check
bool isPalindrome(string s,int i)
{
    if(i>=s.size()/2)
        return 1;
    if(s[i]!=s[s.size()-i-1])
        return 0;
    return isPalindrome(s,i+1);        
}

int main()
{
    int a[]={1,2,3,4,5};
    // reverse1(a,0,4);
    reverse2(a,0,5);

    //check palindrome
    string s="MADAM";
    cout<<"Is palindrome=> "<<isPalindrome(s,0)<<endl;

    for(int i =0;i<5;i++)
        cout<<a[i]<<" ";
}