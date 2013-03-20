/**
UVA 00494
Kindergarden Counting Game
*/
#include<cstdio>
int main(){
	char c, cn;
	int count=0, wst=0;
	for (int count=0; (c = getchar())!=EOF;){
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{
			wst=1;
		}
		else if( wst==1)
		{
			wst=0;
			count++;
		}
		if(c=='\n'){
		printf("%d\n", count);
		count=0;	
		}
	}
	return 0;
}

