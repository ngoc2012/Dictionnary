#include <fstream>
#include <winsock2.h>
#define nsuggest 9
using namespace std;
bool strcomp(char *str1,char *str2,bool match);
int getword(char* fdict_name,unsigned long word_data_offset, unsigned long word_data_size);
int get(int dict,char* word,bool suggest) { 
	char c,data[256],*pdata;  // a utf-8 string terminated by '\0'.
    unsigned long word_data_offset;  // word data's offset in .dict file
    unsigned long word_data_size;  // word data's total size in .dict file 

	// Choose dictionnary
	ifstream fidx;
	char fidx_name[256]="C:\\wamp\\www\\Eurocodes\\Dict_data\\";
	char fdict_name[256]="C:\\wamp\\www\\Eurocodes\\Dict_data\\";
	
	switch (dict) {
		case 0:
			strcat(fidx_name,"en_vi.idx");
			strcat(fdict_name,"en_vi.dict");
			break;
		case 1:
			strcat(fidx_name,"star_vietanh.idx");
			strcat(fdict_name,"star_vietanh.dict");
			break;
		case 2:
			strcat(fidx_name,"dictd_phap-viet.idx");
			strcat(fdict_name,"dictd_phap-viet.dict");
			break;
		case 3:
			strcat(fidx_name,"star_vietphap.idx");
			strcat(fdict_name,"star_vietphap.dict");
			break;
		case 4:
			strcat(fidx_name,"wordnet.idx");
			strcat(fdict_name,"wordnet.dict");
			break;
		case 5:
			strcat(fidx_name,"woaifayu-ff.idx");
			strcat(fdict_name,"woaifayu-ff.dict");
			break;
	}
    fidx.open (fidx_name,ios::binary); if (!fidx.is_open()) { printf ("File \"%s\" does not exist",fidx_name); return 0;}
	
	int suggest10;
	suggest10 = 0;
	while (!fidx.eof()){
		// Initilize
		pdata = data;
        do {
			fidx.read (&c,1); //printf("%c",c);
			*pdata++ = c;
		} while (c!='\0');
		fidx.read ((char*)&word_data_offset,4); word_data_offset = ntohl(word_data_offset); //printf(" %i",word_data_offset);
		fidx.read ((char*)&word_data_size,4); word_data_size = ntohl(word_data_size); //printf(" %i",word_data_size); printf("\n");
        if(!suggest){
			if (strcomp(word,data,true)) {
				getword(fdict_name, word_data_offset, word_data_size);
			}
		}
		// Suggest first 10 word
		if(suggest){
			if (suggest10>0) { 
				if (suggest10<nsuggest) {
					printf("<a onMouseOver=\"this.style.textDecoration='underline';\" onMouseOut=\"this.style.textDecoration='none';\" onclick=\"read(this)\">%s<a/></br>",data);
					//if (suggest10 == (nsuggest-1)) {printf("</div>");}
					suggest10++;
				}
			} else { 
				if (strcomp(word,data,false)) {
					//printf("<div>");
					printf("<a onMouseOver=\"this.style.textDecoration='underline';\" onMouseOut=\"this.style.textDecoration='none';\" onclick=\"read(this)\">%s<a/></br>",data);
					suggest10++;
				} 
			}
		}
    }
    fidx.close();
}
int getword(char* fdict_name,unsigned long word_data_offset, unsigned long word_data_size){
	ifstream fdict;
	int i;
	char c;
	fdict.open (fdict_name,ios::binary); if (!fdict.is_open()) { printf ("File \"%s\" does not exist",fdict_name); return 0;}
	fdict.seekg ((word_data_offset),ios_base::beg);
	word_data_size--;
	for (i=0;i<word_data_size;i++){
		fdict.read (&c,1);
		switch (c) {
			case '@': // word
				for(; c!='\n'; i++){fdict.read (&c,1);}
				break;
			case '*': // word type
				printf("<b><u>");
				printf("%c",c);
				for(; c!='\n'; i++){fdict.read (&c,1);printf("%c",c);}
				printf("</u></b><br/>");
				break;
			case '-': // mean
				printf("%c",c);
				for(; (c!='\n'&&i<word_data_size); i++){fdict.read (&c,1);printf("%c",c);}
				printf("<br/>");
				break;
			case '=': // example
				printf("<i>   ");
				for(; (c!='\n'&&i<word_data_size); i++){fdict.read (&c,1);printf("%c",c);}
				printf("</i><br/>");
				break;
			case '#': // synonyme and after "="
				for(; (c!='\n'&&i<word_data_size); i++){fdict.read (&c,1);printf("%c",c);}
				printf("<br/>");
				break;
			default:
				printf("%c",c);
				break;
		}
	}
	fdict.close();
	return 0;
}

bool strcomp(char *str1,char *str2,bool match){
	for(; *str1; str1++){
		if (*str1!=*str2){return false;}
		str2++;
	}
	if(match){if (*str2) {return false;}}
	return true;
}
int fw(char* pword){
	char c,d;
	ifstream fword;
	fword.open ("word",ios::binary); if (!fword.is_open()) { printf ("Word does not exist"); return 0;} 

	char decimal[5], *pdecimal;
	int dec;
	
	while (!fword.eof()) {
        fword.read (&c,1);
		if (c=='&') { 
			fword.read (&c,1);
			fword.read (&c,1);
			pdecimal = decimal;
			// Convert from Decimal to Char (UTF-8)
			while (c!=';') {*pdecimal++ = c; fword.read (&c,1);} 
			*pdecimal = '\0';
			dec = atoi (decimal);
			//printf("%i ",dec);
			if (dec<=2047) {
				d = static_cast<char>(192 + int(dec/64));
				*pword++ = d;
				//printf("%c",d);
				d = static_cast<char>(128 + int(dec%64));
				*pword++ = d;
				//printf("%c",d);
			} else if(dec<=65535) {
				d = static_cast<char>(224 + int(dec/4096));
				*pword++ = d;
				//printf("%c",d);
				d = static_cast<char>(128 + int(int(dec/64)%64));
				*pword++ = d;
				//printf("%c",d);
				d = static_cast<char>(128 + int(dec%64));
				*pword++ = d;
				//printf("%c",d);
			}
		} else {*pword++ = c;}
    }
	*pword--;
	*pword = '\0';
    fword.close();
	
	return 0;
}
int str_replace(char s,char r,char* str){
	for(; *str; str++){if (*str==s){*str=r;}}
	return 0;
}
bool instr(char *str1,char c){
	for(; *str1; str1++){ if (*str1==c){return true;}}
	return false;
}
int tolowercase(char *str) {
	//char c;
	for(; *str; str++){ *str=(char)tolower(*str);}
}
