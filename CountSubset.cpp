# include <bits/stdc++.h>
using namespace std;

int count_subset_sum(int a[], int sum, int n)
    {
        int dp[n+1][sum+1];
        //Initialisation
        for(int i=0;i<n+1;i++)
            for(int j=0;j<sum+1;j++){
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1
                    ;
            }

        //Choice diagram
        for(int i=1;i<n+1;i++)
            for(int j=1;j<sum+1;j++)
                {
                    if(a[i-1] <= j)
                        dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j];
                }
        
        return dp[n][sum];
    }
int main()  
    {
        int arr[] = {10, 20, 0, 4};
        int sum = 50;
        cout<<"\nTOTAL NO.OF SUBSET OF SUM : "<<sum<<" IS = ";
        cout<<count_subset_sum(arr, sum, 4);
        
        return 0;
    }