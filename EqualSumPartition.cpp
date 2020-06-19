// Is it possible to split the given array in two sets such that sum of these sets is equal to
// SUM of given array...
// problem is similar(reduced) to subset sum problem...
#include <bits/stdc++.h>
using namespace std;

bool equal_sum_partition(int a[], int n)
    {
        int sum = 0;
        for(int i=0;i<n;i++)
            sum += a[i];
        
        //if sum is ODD i can't split the array in 2 parts
        if((sum % 2) != 0)
            return false;

        sum = sum/2;
        bool dp[n+1][sum+1];
        //Initialisation
        for(int i=0;i<n+1;i++)
            for(int j=0;j<sum+1;j++){
                if(i==0)
                    dp[i][j]=false;
                if(j==0)
                    dp[i][j]=true;
            }

        //Choice diagram
        for(int i=1;i<n+1;i++)
            for(int j=1;j<sum+1;j++)
                {
                    if(a[i-1] <= j)
                        dp[i][j] = (dp[i-1][j-a[i-1]] || dp[i-1][j]);
                    else
                        dp[i][j] = dp[i-1][j];
                }
        
        return dp[n][sum];
    }
int main()  
    {
        int arr[] = {100, 20, 30, 40};
        int res = equal_sum_partition(arr, 4);
        if(res == 1)
            cout<<"\n YES, PARTITION IS POSSIBLE ";
        else
            cout<<"\n NO, PARTITION NOT POSSIBLE ";
        return 0;
    }