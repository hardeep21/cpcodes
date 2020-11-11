#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int sum = 0;//current subarray sum
    int max = arr[0];//maximum subarray sum
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>max)
        {
            max=sum;
        }
        if(sum<0)//wont make any difference if i add anything to this sum
            sum=0;
    }
    return max;
}

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
