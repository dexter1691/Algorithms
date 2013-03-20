/**
UVA 00499 
Whats the Frequency
*/
#include<cstdio>
#include<cstring>
int main(){
	char c;
	int f[26]={0},f1[26]={0},max=0;
	for (int count=0; (c = getchar())!=EOF;){		
		if(c-'a'<=26&&c-'a'>=0){
			++f[c-'a'];
			if (max<f[c-'a'])
				max++;
		}
		else if(c-'A'<=26&&c-'A'>=0){
			++f1[c-'A'];
			if (max<f1[c-'A'])
				max++;
		}
		if(c=='\n')
		{
			for(int i=0;i<26;i++)
			{
				if(f1[i]==max) printf("%c", i+'A');
			}
			for(int i=0;i<26;i++)
			{
				if(f[i]==max) printf("%c", i+'a');
			}
			printf(" %d\n",max);
			memset(f,0,26*sizeof(int));
			memset(f1,0,26*sizeof(int));
			max=0;
			
		}
	}
}

