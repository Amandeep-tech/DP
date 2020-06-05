# include <bits/stdc++.h>
using namespace std;

bool subset_sum(int a[], int sum, int n)
    {
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
                        dp[i][j] = max(dp[i-1][j-a[i-1]], dp[i-1][j]);
                    else
                        dp[i][j] = dp[i-1][j];
                }
        
        return dp[n][sum];
    }
int main()  
    {
        int arr[] = {10, 20, 30, 40};
        int sum = 50;
        int res = subset_sum(arr, sum, 4);
        if(res == 1)
            cout<<"\n YES, AN SUBSET OF SUM : "<<sum<<" IS PRESENT";
        else
            cout<<"\n NO, AN SUBSET OF SUM : "<<sum<<" IS NOT PRESENT";
        return 0;
    }