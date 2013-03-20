/**
UVA 11559
Event Planning
*/
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include<climits>
#include<cstdio>
using namespace std;

int main()
{
    int p,b,h,w;
    while(scanf("%d %d %d %d",&p,&b,&h,&w)==4){
        int i,min=INT_MAX;
        for(i=0;i<h;i++){
            int pr=0,pl=0,j=0;
            scanf("%d",&pr);
            int c=pr*p;
            for(j=0;j<w;j++)
            {
            	scanf("%d",&pl);	
            	if(c<=b && pl>=p && min>c)
            		min=c;
            }
        }
        if(min==INT_MAX){
            printf("stay home\n");
        }
        else{
            printf("%d\n",min);
        }
     }
    return 0;
}