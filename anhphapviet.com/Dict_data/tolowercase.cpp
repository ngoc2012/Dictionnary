#include "dict.h"

// add to Tools/Compilers Options/Compiler/ Add linker -lws2_32
int main(int argc, char **argv)
{
	char c,data[256],*pdata,d;
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

	char f_name[256]="en_vi.idx";
	strcat(fidx_name,f_name);
	strcat(fidx0_name,"0");
	strcat(fidx0_name,f_name);
    fidx.open (fidx_name,ios::binary); if (!fidx.is_open()) { printf ("File %s does not exist",fidx_name); return 0;}
	fidx0.open (fidx0_name,ios::binary); if (!fidx0.is_open()) { fidx.close();printf ("File %s does not exist",fidx0_name); return 0;}

	while (!fidx.eof()){
		// Initilize
		pdata = data;
        do {
			fidx.read (&c,1); //printf("%c",c);
			d = (char)tolower(c);
			fidx0.write (&d,1);
			*pdata++ = c;
		} while (c!='\0');
		fidx.read ((char*)&word_data_offset,4);
		fidx.read ((char*)&word_data_size,4);
		fidx0.write ((char*)&word_data_offset,4);
		fidx0.write ((char*)&word_data_size,4);
    }
	fidx0.close();
    fidx.close();

	return 0;
}

