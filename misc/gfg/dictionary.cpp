/*
Implementing  a trie
@Author : Rohit


Auto complete feature:-
1)given prefix of a word now find that prefix of all other words and retrieve them



for a mobile dictionary implement a trie with all words and give them namin
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;


typedef struct trie{
	int words;
	int prefixes;
	struct trie *edges[26];
}trie;


trie *initialize(trie *node){
	if (node == NULL){
		node = (trie *)malloc(sizeof(trie));
		node -> words = 0;
		node -> prefixes =0;
		for(int i=0;i<26;i++)
			node -> edges[i]=NULL;
		return node;
	}
}



trie *addword(trie *ver,char* str){
	printf("%c",str[0]);

	if(str[0]=='\0')
			ver -> words = ver -> words + 1;
	else{
			ver -> prefixes = ver -> prefixes + 1;
			char k = str[0];
			int index = k - 'a';
			str++;

			if(ver -> edges[index] == NULL)
				ver -> edges [index] = initialize(ver -> edges[index]);

			ver -> edges[index] = addword(ver -> edges[index] , str);
	}
}


int countword(trie *ver,char *str){
		if(str[0]=='\0')
			return ver -> words;
		else{
			int k = str[0]-'a';
			str++;
			if(ver -> edges[k] == NULL)
				return 0;
			return countword(ver -> edges[k], str);
		}
}


int countprefix(trie *ver,char *str){
		if(str[0]=='\0')
			return ver -> prefixes;
		else{
			int k = str[0]-'a';
			str++;
			if(ver -> edges[k] == NULL)
				return 0;
			return countprefix(ver -> edges[k], str);
		}
}



int countmissingwords(trie *ver,char *str,int missingletters){
	if(str[0]=='\0')
		return ver->words;
	else{
		int k = str[0] - 'a';
		if(ver->edges[k] == NULL || missingletters == 0)
			return 0;
		else if(ver -> edges[k]==NULL){
			str++;
			return countmissingwords(ver,str,missingletters-1);
		}
		else{
			int r = countmissingwords(ver,str,missingletters-1);
			str++;
			r = r + countmissingwords(ver->edges[k],str,missingletters);
			return r;
		}
	}
}



int main(){
		//initializing a trie

		trie *start = NULL;
		start = initialize(start);

		int ch = 1;
		while(ch){

			printf(	"\n 1) Enter a word");
			printf( "\n 2) count words");
			printf( "\n 3) count prefixes");
			printf("\n  4) count 1 missed letter words");
			printf("\n  5) press 0 for exit");
			printf("\n  Enter options");
			printf ("\n");
			scanf("%d",&ch);
			char input[1000];

			switch(ch){
				case 1:
						printf("Enter a word to search\n");
						scanf ("%s",input);
						start = addword(start,input);
						break;
				case 2:
						printf("Enter a word to count words\n");
						scanf("%s",input);
						printf("%d\n",countword(start,input));
						break;
				case 3:
						printf("Enter a word to count prefixes\n");
						scanf("%s",input);
						printf("%d\n",countprefix(start,input));
						break;
				case 4:
						printf("Enter a deleted single word\n");
						scanf("%s",input);
						printf("%d\n",countmissingwords(start,input,1));
						break;
			}
		}
	return 0;
}
