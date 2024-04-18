#include "dict.h"

// add to Tools/Compilers Options/Compiler/ Add linker -lws2_32
int main(int argc, char **argv)
{
    int dict;
	char fal[2]="0"; 
	char word[256];
	char* w;
	dict = atoi (argv[1]);
	w = argv[2];
	if (dict==0||dict==4) {
        str_replace('=',' ',w);
        tolowercase(w);
		get(dict,w,(!strcomp(argv[3],fal,true)));
	} else {
		fw(word);
		tolowercase(word);
		get(dict,word,(!strcomp(argv[3],fal,true)));
	}
        
	return 0;
}

