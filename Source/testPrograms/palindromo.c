#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool stop(char* s){
	if(strlen(s)==3 && s[0]=='F' && s[1]=='I' && s[2]=='M') return true;
	else return false;
}

bool pali(char* s){
	int len = strlen(s)-1,
		i = 0,
		f = len;
	len = len/2 + 1;
	bool result = true;
	while(result && i!=f && i<len){
		if(s[i] != s[f]) result = false;
		i++;
		f--;
	}
	return result;
}

int main(){
	char* s;
	bool work = true;
	while(work){
		s = malloc (769 * sizeof(char));
		//fgets(s, 768, stdin);
		//scanf(" %s", s);
		scanf(" %1000[^\n]", s);
		if(stop(s)) {
			work = false;
		}
		else if(pali(s)) printf("SIM\n");
		else printf("NAO\n");
		free(s);
	}
	//free(s);
	return 0;
}
