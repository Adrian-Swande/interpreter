#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char
	style_reset[]="\033[0m",
    style_bold[]="\033[01m",
    style_disable[]="\033[02m",
    style_underline[]="\033[04m",
    style_reverse[]="\033[07m",
    style_strikethrough[]="\033[09m",
    style_invisible[]="\033[08m",
    fg_black[]="\033[30m",
    fg_red[]="\033[31m",
    fg_green[]="\033[32m",
    fg_orange[]="\033[33m",
    fg_blue[]="\033[34m",
    fg_purple[]="\033[35m",
    fg_cyan[]="\033[36m",
    fg_lightgrey[]="\033[37m",
    fg_darkgrey[]="\033[90m",
    fg_lightred[]="\033[91m",
    fg_lightgreen[]="\033[92m",
    fg_yellow[]="\033[93m",
    fg_lightblue[]="\033[94m",
    fg_pink[]="\033[95m",
    fg_lightcyan[]="\033[96m",
    bg_black[]="\033[40m",
    bg_red[]="\033[41m",
    bg_green[]="\033[42m",
    bg_orange[]="\033[43m",
    bg_blue[]="\033[44m",
    bg_purple[]="\033[45m",
    bg_cyan[]="\033[46m",
    bg_lightgrey[]="\033[47m";

//SYSTEM
void error_P_SYSTEM(int m); //SYSTEM ERROR MEDDELANDE
void error_S_SYSTEM(char m[]);

unsigned int alert_number_SYSTEM=0;

//VIRITUELL STACK
#define _STACK_SIZE_ 100 //STACKKAPACITET

int STACK[_STACK_SIZE_];
int TOP_STACK=-1;

void clear_STACK();

void push_STACK(int val);
int   pop_STACK();
int  peek_STACK(int d);

//HEMMAGJORT MINNESSYSTEM + PEKARE
#define _MEMORY_X_SIZE_ 3 //STRÄNGSTORLEK
#define _MEMORY_Y_SIZE_ 10 //STRÄNGKAPACITET

char CHAR_MEMORY[_MEMORY_X_SIZE_*_MEMORY_Y_SIZE_];
//char  INT_MEMORY[_MEMORY_X_SIZE_*_MEMORY_Y_SIZE_];

void clear_MEMORY();

void debug_CHAR_MEMORY();
//void debug_INT_MEMORY();

char getChar_MEMORY(int y,int x);
//int   getInt_MEMORY(int y,int x);

void putChar_MEMORY(int y,int x,char c);
void putString_MEMORY(int y,char s[_MEMORY_X_SIZE_]);

int putString_RandomAcess_MEMORY(char s[_MEMORY_X_SIZE_]);
int find_RandomAccess_MEMORY(int n);

void printChar_MEMORY(int y,int x);
void printString_MEMORY(int y,int endLine);

void free_MEMORY(int y);

//STRÄNG-MANIPULATIONSFUNKTIONER
void concatStrings_PP_MEMORY(int a,int b,int del); //PEKARE, PEKARE
void concatStrings_PS_MEMORY(int a,char b[_MEMORY_X_SIZE_]); //PEKARE, STRÄNG

int compareStrings_PP_MEMORY(int a,int b);
int compareStrings_PS_MEMORY(int a,char b[_MEMORY_X_SIZE_]);

int stringLength_MEMORY(int y);

void copyString_MEMORY(int a,int b);

//FUNKTIONER HANTERANDE STRÄNGLISTOR M.M.
char EMPTY_STRING_LIST[]="_e";//"_empty_string_list_";
char END_OF_STRING_LIST[]="_q";//"_end_of_string_list_";

int createStringList_RandomAccess_MEMORY(int l);

int stringListLength_MEMORY(int y);

int  getStringInList_MEMORY(int l,int y);
void copyStringIntoList_MEMORY(int l,int y,int p);
void copyStringFromList_MEMORY(int l,int y,int p);
void putStringIntoList_MEMORY(int l,int y,char s[_MEMORY_X_SIZE_]);
int  appendStringList_P_MEMORY(int l,int y);
int  appendStringList_S_MEMORY(int l,char s[_MEMORY_X_SIZE_]);

void freeStringList_MEMORY(int y);

//SPECIFIKA PROGRAMFUNKTIONER
void prompt(char esc,int promptY,int destinationY,int max);
void lexer();
void parse();

//SPECIFIKA GLOBALA KONSTANTA PROGRAMVÄRDEN
const char DIV_CHARS[]=".,:;+-*/?!\"\'=([{}])<>|&%%@£$¤#~^\\→↓↑←«»±";

//SPECIFIKA GLOBALA PROGRAMVARIABLER
char userInput[_MEMORY_X_SIZE_];

int main(int argc,char*argv[]){clear_MEMORY();
	return 0;
}

//SPECIFIKA PROGRAMFUNKTIONER
void lexer(){

}

void prompt(char esc,int promptY,int destinationY,int max){
	printString_MEMORY(promptY,0);
	if(esc!='\n')printf(" (enter='%c')",esc);
	printf("> ");

    char c;int i=0;
    for(;(c=getchar())!=esc&&i<max;i++)putChar_MEMORY(destinationY,i,c);
    putChar_MEMORY(destinationY,i+1,'\0');
}

//HEMMAGJORT MINNESSYSTEM + PEKARE
void clear_MEMORY(){
    for(int i=0;i<_MEMORY_X_SIZE_*_MEMORY_Y_SIZE_;i++)
        CHAR_MEMORY[i]='\0'
        //,INT_MEMORY[i]=0
        ;
}

void debug_CHAR_MEMORY(){
	int mem=0;
    for(int i=0;i<_MEMORY_X_SIZE_*_MEMORY_Y_SIZE_;i++){
        printf("CHAR_MEMORY[%d]:",i);
        if(i<10)printf(" ");
        printf(" %c",CHAR_MEMORY[i]);
		if(i%_MEMORY_X_SIZE_==0)printf("\t(%d)\n",mem),mem++;
		else printf("\n");
    }
}

/*void debug_INT_MEMORY(){
    for(int i=0;i<_MEMORY_X_SIZE_*_MEMORY_Y_SIZE_;i++)
        printf("INT_MEMORY[%d]:\t\t%d\n",i,INT_MEMORY[i]);
}*/

char getChar_MEMORY(int y,int x){
    return CHAR_MEMORY[y*_MEMORY_X_SIZE_+x];
}

void putChar_MEMORY(int y,int x,char c){
    CHAR_MEMORY[y*_MEMORY_X_SIZE_+x]=c;
}

void putString_MEMORY(int y,char s[_MEMORY_X_SIZE_]){
    int i=0;
    for(;s[i]!='\0'&&i<_MEMORY_X_SIZE_;i++)
        putChar_MEMORY(y,i,s[i]);
    for(;i<_MEMORY_X_SIZE_;i++)
        putChar_MEMORY(y,i,'\0');
}

int putString_RandomAcess_MEMORY(char s[_MEMORY_X_SIZE_]){
    int i=0;
    for(;i<_MEMORY_Y_SIZE_;i++){
        if(getChar_MEMORY(i,0)=='\0')break;
    }
    putString_MEMORY(i,s);
    return i;
}

int find_RandomAccess_MEMORY(int n){
	int m=n;
	for(int l=0;l<_MEMORY_Y_SIZE_;l++){
    	for(int i=l;1;i++){//printf("i:%d, m:%d, n:%d\n",i,m,n);
        	if(getChar_MEMORY(i,0)=='\0'){m--;}
			else{m=n;l=i;/*printf("f\n")*/;break;}

			if(!m)return l;
			if(i==_MEMORY_Y_SIZE_-1)goto end;
    	}
	}
end:
	error_S_SYSTEM("memory capacity exeeded");
}

void printChar_MEMORY(int y,int x){
    printf("%c",getChar_MEMORY(y,x));
}

void printString_MEMORY(int y,int endLine){
    for(int i=0;getChar_MEMORY(y,i)!='\0'&&i<_MEMORY_X_SIZE_;i++)
        printf("%c",getChar_MEMORY(y,i));
    if(endLine)printf("\n");
}

void free_MEMORY(int y){
    for(int i=0;i<_MEMORY_X_SIZE_&&getChar_MEMORY(y,i)!='\0';i++)
        putChar_MEMORY(y,i,'\0');
}

//STRÄNG-MANIPULATIONSFUNKTIONER
void concatStrings_PP_MEMORY(int a,int b,int del){
    int i=0;
    for(;getChar_MEMORY(a,i)!='\0'&&i<_MEMORY_X_SIZE_;i++);
    for(int i2=0;getChar_MEMORY(b,i2)!='\0'&&i<_MEMORY_X_SIZE_;i++,i2++)
        putChar_MEMORY(a,i,getChar_MEMORY(b,i2));
    if(del)
        free_MEMORY(b);
}

void concatStrings_PS_MEMORY(int a,char b[_MEMORY_X_SIZE_]){
    int i=0;
    for(;getChar_MEMORY(a,i)!='\0'&&i<_MEMORY_X_SIZE_;i++);
    for(int i2=0;b[i2]!='\0'&&i<_MEMORY_X_SIZE_;i++,i2++)
        putChar_MEMORY(a,i,b[i2]);
}

int compareStrings_PP_MEMORY(int a,int b){
    for(int i=0;i<_MEMORY_X_SIZE_&&
    (getChar_MEMORY(a,i)!='\0'||getChar_MEMORY(b,i)!='\0');i++)
        if(getChar_MEMORY(a,i)!=getChar_MEMORY(b,i))
            return 0;
    return 1;
}

int compareStrings_PS_MEMORY(int a,char b[_MEMORY_X_SIZE_]){
    for(int i=0;i<_MEMORY_X_SIZE_&&
    (getChar_MEMORY(a,i)!='\0'||b[i]!='\0');i++)
        if(getChar_MEMORY(a,i)!=b[i])
            return 0;
    return 1;
}

int stringLength_MEMORY(int y){
    int i=0;
    for(;getChar_MEMORY(y,i)!='\0'&&i<_MEMORY_X_SIZE_;i++);
    return i;
}

void copyString_MEMORY(int a,int b){
    free_MEMORY(b);
    for(int i=0;i<_MEMORY_X_SIZE_&&getChar_MEMORY(a,i)!='\0';i++)
        putChar_MEMORY(b,i,getChar_MEMORY(a,i));
}

//VIRITUELL STACK
void clear_STACK(){
	for(int i=0;i<_STACK_SIZE_;i++)
        STACK[i]=0;
}

void push_STACK(int val){
    if(TOP_STACK>=_STACK_SIZE_-1)error_S_SYSTEM("stack overflow");
    else TOP_STACK++,STACK[TOP_STACK]=val;
}

int pop_STACK(){
    if(TOP_STACK<=-1)error_S_SYSTEM("stack underflow");
    else TOP_STACK--;
}

//FUNKTIONER HANTERANDE STRÄNGLISTOR M.M.
int createStringList_RandomAccess_MEMORY(int l){
	int p=find_RandomAccess_MEMORY(l+1);
	for(int i=p;i<p+l;i++)putString_MEMORY(i,EMPTY_STRING_LIST);
	putString_MEMORY(p+l,END_OF_STRING_LIST);
	return p;
}

int stringListLength_MEMORY(int y){
	int i=y;
	for(;!compareStrings_PS_MEMORY(i,END_OF_STRING_LIST);i++){
		if(i==_MEMORY_Y_SIZE_-1)error_S_SYSTEM("faulty list pointing pointer");
	}
	return i-y;
}

int getStringInList_MEMORY(int l,int y){
	if(y>stringListLength_MEMORY(l))error_S_SYSTEM("list index out of range");
	return l+y;
}


void copyStringIntoList_MEMORY(int l,int y,int p){
	copyString_MEMORY(p,l+y);
}

void copyStringFromList_MEMORY(int l,int y,int p){
	copyString_MEMORY(l+y,p);
}

void putStringIntoList_MEMORY(int l,int y,char s[_MEMORY_X_SIZE_]){
	putString_MEMORY(l+y,s);
}

int  appendStringList_P_MEMORY(int l,int y){

}

int  appendStringList_S_MEMORY(int l,char s[_MEMORY_X_SIZE_]){

}

void freeStringList_MEMORY(int y){
	for(int i=y;1;i++){
		//printf("i:%d - ",i);
		//printString_MEMORY(i,1);
		if(compareStrings_PS_MEMORY(i,END_OF_STRING_LIST)){free_MEMORY(i);return;}
		free_MEMORY(i);
		if(i==_MEMORY_Y_SIZE_-1)error_S_SYSTEM("unknown");
	}
}

//SYSTEM
void error_P_SYSTEM(int m){
    printf("\n%s%s_SYSTEM_BEGIN_ {\"system alert\":{\"number\":%d,\"type\":\"error\",\"message\":\"",
    bg_red,fg_black,alert_number_SYSTEM);
    printString_MEMORY(m,0);
    printf("\"}} _SYSTEM_END_%s\n",style_reset);
    alert_number_SYSTEM++;
	
	exit(0);
}

void error_S_SYSTEM(char m[]){
    printf("\n%s%s_SYSTEM_BEGIN_ {\"system alert\":{\"number\":%d,\"type\":\"error\",\"message\":\"%s\"}} _SYSTEM_END_%s\n",
    bg_red,fg_black,
    alert_number_SYSTEM,
    m,
    style_reset);
    alert_number_SYSTEM++;
	
	exit(0);
}
