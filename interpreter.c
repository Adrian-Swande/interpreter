#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _SIZE_ 10

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

//HEMMAGJORT MINNESSYSTEM + PEKARE
#define _MEMORY_X_SIZE_ 10 //STRÄNGSTORLEK
#define _MEMORY_Y_SIZE_ 5  //STRÄNGKAPACITET

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

void printChar_MEMORY(int y,int x);
void printString_MEMORY(int y,int endLine);

//STRÄNG-MANIPULATIONSFUNKTIONER
//void str_concat(int a,int b);
//int  str_compare(int a,int b);

//SPECIFIKA PROGRAMFUNKTIONER
void prompt(char esc,int promptY,int destinationY,int max);
void lexer();
void parse();

//SPECIFIKA GLOBALA KONSTANTA PROGRAMVÄRDEN
const char DIV_CHARS[]=".,:;+-*/?!\"\'=([{}])<>|&%%@£$¤#~^\\→↓↑←«»±";

//SPECIFIKA GLOBALA PROGRAMVARIABLER
char userInput[_SIZE_];

int main(int argc,char*argv[]){
    return 0;
}

//SPECIFIKA PROGRAMFUNKTIONER
void lexer(){

    /*
    char**t;
    t=malloc(R*sizeof(char*));
    for(int i=0;i<C;i++)t[i]=malloc(C*sizeof(char));

    int ti=0;char prev='a';
    for(int i=0;*s!='\0';s++,i++){
        if(*s==' '){//TA BORT BLANKSTEG (OCH BRYT UPP)
            if(prev!=' '){
                if(t[0][0])
                    t[ti][i]='\0',ti++,i=-1;
            }
            else i--;
        }
        
        for(int u=0;u<strlen(&DIV_CHARS[0]);u++){//BRYTER UT SPECIALKARAKTÄRER
            if(*s==DIV_CHARS[u]){
                if(ti){
                    if(t[ti-1][0]=='\0')ti++;
                }
                t[ti][0]=*s;
                ti++;
                i=-1;
                printf("break-char found: '%c'\n",*s);
                break;
            }
        }

        if(*s!=' ')t[ti][i]=*s;
        prev=*s;
    }t[ti+1][0]='\0';

    return t;
    */

    //GLÖM INTE ATT FRIGÖRA MINNET EFTER ANVÄNDNING MED 'freeArray(pointer)'
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
    for(int i=0;i<_MEMORY_X_SIZE_*_MEMORY_Y_SIZE_;i++){
        printf("CHAR_MEMORY[%d]:",i);
        if(i<10)printf(" ");
        printf(" %c\n",CHAR_MEMORY[i]);
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
}

void printChar_MEMORY(int y,int x){
    printf("%c",getChar_MEMORY(y,x));
}

void printString_MEMORY(int y,int endLine){
    for(int i=0;getChar_MEMORY(y,i)!='\0'&&i<_MEMORY_X_SIZE_;i++)
        printf("%c",getChar_MEMORY(y,i));
    if(endLine)printf("\n");
}
