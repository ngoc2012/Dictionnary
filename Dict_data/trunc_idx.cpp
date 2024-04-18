#include "dict.h"

// add to Tools/Compilers Options/Compiler/ Add linker -lws2_32
int main(int argc, char **argv)
{
	char c,data[256],*pdata;
    unsigned long word_data_offset;  // word data's offset in .dict file
    unsigned long word_data_size;  // word data's total size in .dict file
    ifstream fidx;
	ofstream fidx0;
    
	// letter 
	//char str[256]="ABCDEFGHabcdefgh";
	//A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
	//a b c d e f g h i j k l m n o p q r s t u v w x y z
	char fidx_name[256]="C:\\wamp\\www\\Eurocodes\\Dict_data\\";
	char fidx0_name[256]="C:\\wamp\\www\\Eurocodes\\Dict_data\\";
	char str[256]="Vv";
	//char str[256]="Aa";
	//char str[256]="b";
	//char str[256]="c";
	//char str[256]="d";
	//char str[256]="e";
	//char str[256]="f";
	//char str[256]="gh";
	//char str[256]="i";
	//char str[256]="jkl";
	//char str[256]="mn";
	//char str[256]="op";
	//char str[256]="qr";
	//char str[256]="s";
	//char str[256]="t";
	//char str[256]=;
	//char str[256]="abcdefghijklmnopqrst"; //"uvwxyz" and " "
	char f_name[256]="en_vi.idx";
	strcat(fidx_name,f_name);
	strcat(fidx0_name,str);
	strcat(fidx0_name,f_name);
    fidx.open (fidx_name,ios::binary); if (!fidx.is_open()) { printf ("File %s does not exist",fidx_name); return 0;}
	//fidx0.open (fidx0_name,ios::binary); if (!fidx0.is_open()) { fidx.close();printf ("File %s does not exist",fidx0_name); return 0;}
	int size;
	unsigned long ipos,pos,pos1;
	bool p1;
	p1 = false;
	pos = 1;
	while (!fidx.eof()){
		// Initilize
		pdata = data;
		size = 0;
		ipos = 0;
        do {
			fidx.read (&c,1); //printf("%c",c);
			*pdata++ = c;
			size++;
			ipos++;
		} while (c!='\0');
		if ( (instr(str,(char)tolower(data[0]))) && p1==false) {
			p1=true;
			printf("First met: %i\n",pos);
			printf("%s\n",data);
			pos1 = pos;
		}
		if ( !(instr(str,(char)tolower(data[0]))) && p1==true) {
			p1=false;
			printf("Last met: %i\n",pos);
			printf("%s\n",data);
		}
		pos+=ipos;
		fidx.read ((char*)&word_data_offset,4);
		fidx.read ((char*)&word_data_size,4);
		pos+=8;
        /*if(instr(str,(char)tolower(data[0]))){
			fidx0.write (data,size);
			fidx0.write ((char*)&word_data_offset,4);
			fidx0.write ((char*)&word_data_size,4);
		}*/
    }
	//fidx0.close();
    fidx.close();
    
    ifstream fidxx;
    fidxx.open (fidx_name,ios::binary); if (!fidxx.is_open()) { printf ("File %s does not exist",fidx_name); return 0;}
    fidxx.seekg(pos1-1,ios::beg);
    unsigned long length;
    length=fidxx.tellg();
    printf("where?: %i\n",length);
    //while (!fidxx.eof()){
    do {
	fidxx.read (&c,1); printf("%c",c);
		} while (c!='\0');
	fidxx.read ((char*)&word_data_offset,4);
	fidxx.read ((char*)&word_data_size,4);
    //fidxx.seekg (0, ios::end);
    //}
	fidxx.close();	
    //printf("%c",(char)(tolower('A')));
    printf("Size of file: %i\n",pos);
    printf("end of check");
    getchar();
	return 0;
}

