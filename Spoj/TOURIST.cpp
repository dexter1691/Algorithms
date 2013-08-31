#include <cstdio>
#include <algorithm>
#include<iostream>
using namespace std;

int dp[200][100][100], f[200][100][100];
char v[110][100];
int r,c;
int max1(int a, int b)
{
    return a>=b?a:b;
}
int solve()
{
    for(int steps=0;steps<r+c-1;steps++)    //steps=[0,r-1+c-1]
    {
        for(int c1=0; c1<=steps&&c1<c ;c1++)     //row=[0,W]
        {
            for(int c2=0;c2<=c1;c2++)        //c2<c1
            {
                int r1=steps - c1;
                int r2=steps - c2;
                
                if(r1>r||r2>r||v[r1][c1]=='#'||v[r2][c2]=='#')
                    dp[steps][c1][c2]=dp[steps][c2][c1]=0;
                else
                {
                    int c=0;
                    if(steps>0)
                    {
                        c=max1(c,dp[steps-1][c1][c2]);
                        if(c1>0)
                            c=max1(c,dp[steps-1][c1-1][c2]);
                        if(c2>0)
                            c=max1(c,dp[steps-1][c1][c2-1]);
                        if(c1>0 && c2>0)
                            c=max1(c,dp[steps-1][c1-1][c2-1]);
                        
                    }
                    
                    if(v[r1][c1]=='*')
                    {
              //          printf("%d\t%d\n",r1,c1);
                        c++;
                    }
                    if(v[r2][c2]=='*' && c1!=c2 ){
                        c++;
            //            printf("%d\t%d\n",r2,c2);
                    }
                    dp[steps][c1][c2]=dp[steps][c2][c1]=c;
          //          printf("%d\t%d\t%d\t%d\n",steps, c1, c2, dp[steps][c1][c2]);
                }
            }
        }
    }
     return dp[r+c-2][c-1][c-1];

}
int main() {
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &c, &r);
        getchar();
        for(int i = 0; i < r; i++){
            for(int j=0;j<c;j++)
                scanf("%c", &v[i][j]);
            getchar();
        }
        /*
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                printf("%c\t",v[i][j]);
            printf("\n");
        }
        */
        printf("%d\n", solve()); 
    }
    return 0;
}
