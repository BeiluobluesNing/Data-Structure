#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int next[100];

int * findNext(char *P){
	int i = 0;
	int k = -1;
	int m = strlen(P);
	next[0] = -1;
	while(i<m)
	{
		while(k >= 0 && P[i] != P[k])
			k = next[k];
		i++;
		k++;
		if( i == m) break;
		next[i] = k;

	}
	return next;
}

int main(){
	printf("Input a string:\n");
	char s[100];
	scanf("%s",s);
	findNext(s);
	for(int i=0; i<strlen(s);i++)
		printf("%i",next[i]);
}