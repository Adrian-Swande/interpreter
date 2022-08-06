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

//HEMMAGJORT MINNESSYSTEM + PEKARE
#define _MEMORY_X_SIZE_ 100	//STRÄNGSTORLEK
#define _MEMORY_Y_SIZE_ 100	//STRÄNGKAPACITET

char CHAR_MEMORY[_MEMORY_X_SIZE_*_MEMORY_Y_SIZE_];
//char  INT_MEMORY[_MEMORY_X_SIZE_*_MEMORY_Y_SIZE_];

void clear_MEMORY();

void debug_CHAR_MEMORY();
//void debug_INT_MEMORY();

char getChar_MEMORY(int y,int x);
//int   getInt_MEMORY(int y,int x);

void putChar_MEMORY(int y,int x,char c);
void putString_MEMORY(int y,const char s[_MEMORY_X_SIZE_]);

int putString_RandomAccess_MEMORY(const char s[_MEMORY_X_SIZE_]);
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

void prompt_MEMORY(char esc,int promptY,int destinationY,int max);


//FUNKTIONER HANTERANDE STRÄNGLISTOR M.M.
char EMPTY_STRING_LIST[]="_empty_string_list_";
char END_OF_STRING_LIST[]="_end_of_string_list_";

int createStringList_RandomAccess_MEMORY(int l);

int stringListLength_MEMORY(int y);

int  getStringInList_MEMORY(int l,int y);
void copyStringIntoList_MEMORY(int l,int y,int p);
void copyStringFromList_MEMORY(int l,int y,int p);
void putStringIntoList_MEMORY(int l,int y,char s[_MEMORY_X_SIZE_]);
int  appendCopyStringList_MEMORY(int l,int y);
int  appendStringList_S_MEMORY(int l,char s[_MEMORY_X_SIZE_]);

void freeStringList_MEMORY(int y);



#define bool byte
#define true 1
#define false 0

//PROGRAMSTORLEK
#define L_MAX	100
#define W_MAX	100
#define S_STACK	100

typedef unsigned char byte;

const char DEAD_CHARS[]=" \n\t";
const char DIV_CHARS[]=".,:;+-*/?!\"\'=([{}])<>|&%%@£$¤#~^\\→↓↑←«»±";
const char RES_WORDS[L_MAX][W_MAX]={
	"print",
	"input",
	"goto",
	"or",
	"and",
	"not",
	"if",
	"else",
	"while",
	"def",
	"true",
	"false",
	"yamete",
	"end",
	"int",
	"str",
	"__assign_int__",
	"__assign_str__",
	"__str_concat__",
	"__str_stack_mode__",
	"__int_stack_mode__",
	"free",
	"write",
	"return"};


void prompt(char esc,const char p[],char x[],int max);

char tokens[L_MAX][W_MAX];
void lex(const char inp[],char x[L_MAX][W_MAX]);
bool deadChar(char c);
bool divChar(char c);

char orders[L_MAX][W_MAX];
void next();
void place(const char t[W_MAX]);
bool check(const char t[W_MAX]);
bool checkNext(const char t[W_MAX]);
bool stringIsIn(const char s[W_MAX],const char p[L_MAX][W_MAX]);
bool stringContainsChar(const char s[W_MAX],const char p[W_MAX]);
bool isInteger(const char s[W_MAX]);
bool isSymbol(const char s[W_MAX]);
void parse();

bool SW___=false;
int tokenIndex=0;
int orderIndex=0;

void code();
void block();
void expression();

void declareNumeric();
void declareString();

void stringExpression();
void string();

void numeric();
void or_();
void and_();
void not_();
void compare_();
void mathExpression();
void term();
void factor();
void potens();

void execute();
void executionError(const char error[]);
int OI=0;

int stack[S_STACK];
int stackTop=-1;
void push(int i);
int  pop();

int intParse(const char s[W_MAX]);

int intPower(int x,int y);

void syntaxError(const char error[]);
void debug(char s[]);
bool DEBUG=false;
bool GETINPUT=true;

bool ERROR=false;

void clear(bool all);


//VIRITUELLA VARIABLER
int _vi=0; //variable index
unsigned int	VARIABLE_POINTERS[L_MAX];
char			VARIABLE_NAMES[L_MAX][W_MAX];

int  getVariableIndexByName	(const char n[W_MAX]);
int  getVariableValueByName	(const char n[W_MAX]);
void assignVariableByName	(const char n[W_MAX],const int v);

void assignVariableStringByName(const char n[W_MAX],const char s[W_MAX]);
void getVariableStringByName(const char n[W_MAX]);
char __varString[W_MAX];

//STRÄNGSTACK
#define SS_SIZE 10

char stringStack[SS_SIZE][W_MAX];
int StringStackTop=-1;

void stringStackPush(const char s[W_MAX]);
void stringStackPop();
char stringStackPopped[W_MAX]="";

int main(int argc,char*argv[]){

	char codeInput[W_MAX];
	
	bool noExe=false;
	for(int i=0;i<argc;i++){
		if(!strcmp(argv[i],"-d"))DEBUG=true;
		else if(!strcmp(argv[i],"-s"))noExe=true;
		else if(!strcmp(argv[i],"-f")){
			i++;
			GETINPUT=false;

			FILE *fp;
			fp=fopen(argv[i],"r");
			if(!fp){printf("File error.\n");return 1;}
			char s[W_MAX];
			//while(fgets(s,10,fp)!=NULL)strcat(codeInput,s);
		//	fscanf(fp,"%[^\n]",codeInput);
			char c=fgetc(fp);
			for(int i=0;c!=EOF&&i<W_MAX;i++){
				codeInput[i]=c;
				c=fgetc(fp);
			}
			fclose(fp);
		}
	}

	clear_MEMORY();
	clear(1);

	do
	{	
		if(GETINPUT)prompt('\n',"megumin.c",codeInput,W_MAX);

		lex(codeInput,tokens);

		parse(tokens);

		if(DEBUG){
			for(int i=0;strcmp(tokens[i],"");i++)printf("token[%d]: %s\n",i,tokens[i]);
			printf("\n");
			for(int i=0;strcmp(orders[i],"");i++)printf("order[%d]: %s\n",i,orders[i]);
			printf("\n");
		}

		if(ERROR||noExe)goto abort_execution;

		execute();

abort_execution:
		
		clear(0);
	}
	while(GETINPUT);

	return 0;
}

void clear(bool all){
	for(int y=0;y<L_MAX;y++){	
		if(all)VARIABLE_POINTERS[y]=0;
		for(int x=0;x<W_MAX;x++){
			tokens[y][x]='\0';
			orders[y][x]='\0';
			if(all)VARIABLE_NAMES[y][x]='\0';
		}
	}
	for(int i=0;i<S_STACK;i++)
		stack[i]=0;

	stackTop=-1;

	SW___=false;
	tokenIndex=0;
	orderIndex=0;
	ERROR=false;
	OI=0;
}

int getVariableIndexByName(const char n[]){
	for(int i=0;strcmp(VARIABLE_NAMES[i],"")&&i<L_MAX;i++){
		if(!strcmp(n,VARIABLE_NAMES[i]))return i;
	}return -1;
}
int getVariableValueByName(const char n[]){
	int index,pointer;
	if(stringIsIn(n,VARIABLE_NAMES)){
		index=getVariableIndexByName(n);
		pointer=VARIABLE_POINTERS[index];
		char value[_MEMORY_X_SIZE_]="____________________________";
		for(int i=0;i<_MEMORY_X_SIZE_&&getChar_MEMORY(pointer,i)!='\0';i++)value[i]=getChar_MEMORY(pointer,i);
		return intParse(value);
	}
	else{
		executionError("unknown symbol, expected variable");
	}
}
void assignVariableByName(const char n[],const int v){
	int index,pointer;
	if(stringIsIn(n,VARIABLE_NAMES)){
		index=getVariableIndexByName(n);
		pointer=VARIABLE_POINTERS[index];
		char value[_MEMORY_X_SIZE_]="___________________________";
		sprintf(value,"%d",v);
		putString_MEMORY(pointer,value);
	}
	else{
		index=_vi;_vi++;
		strcpy(VARIABLE_NAMES[index],n);
		char value[_MEMORY_X_SIZE_]="___________________________";
		sprintf(value,"%d",v);
		pointer=putString_RandomAccess_MEMORY(value);
		VARIABLE_POINTERS[index]=pointer;
	}
}
void assignVariableStringByName(const char n[],const char s[]){
	int index,pointer;
	if(stringIsIn(n,VARIABLE_NAMES)){
		index=getVariableIndexByName(n);
		pointer=VARIABLE_POINTERS[index];
		putString_MEMORY(pointer,s);
	}
	else{
		index=_vi;_vi++;
		strcpy(VARIABLE_NAMES[index],n);
		pointer=putString_RandomAccess_MEMORY(s);
		VARIABLE_POINTERS[index]=pointer;
	}
}
void getVariableStringByName(const char n[]){
	int index,pointer;
	if(stringIsIn(n,VARIABLE_NAMES)){
		index=getVariableIndexByName(n);
		pointer=VARIABLE_POINTERS[index];
		char string[_MEMORY_X_SIZE_]="";
		for(int i=0;i<_MEMORY_X_SIZE_&&getChar_MEMORY(pointer,i)!='\0';i++)string[i]=getChar_MEMORY(pointer,i);
		strcpy(__varString,string);
	}
	else{
		executionError("unknown symbol, expected variable");
	}
}

void execute(){
	bool stackmode=true; //true: int, false: str
	for(;orders[OI][0]!='\0'&&!ERROR&&OI<L_MAX;OI++){
		char o[W_MAX];
		strcpy(o,orders[OI]);

		if(DEBUG)printf("order: %s\n",o);




		if		(!strcmp(o,"__str_stack_mode__"))stackmode=false;
		else if	(!strcmp(o,"__int_stack_mode__"))stackmode=true;

		else if(isInteger(o))push(intParse(o));
		else if(o[0]=='"'){
			char s[W_MAX];
			for(int i=1;i<strlen(o);i++)s[i-1]=o[i];
			stringStackPush(s);
		}

		else if(!strcmp(o,"print"))printf("%s%s%d%s\n",style_bold,fg_yellow,pop(),style_reset);
		else if(!strcmp(o,"write"))
			stringStackPop(),
			printf("%s%s%s%s\n",style_bold,fg_yellow,stringStackPopped,style_reset);
		else if(!strcmp(o,"input")){
			char inp[W_MAX]="____________";
			prompt('\n',"PROGRAM INPUT",inp,W_MAX);
			push(intParse(inp));
		}
//		else if(!strcmp(o,"enter")) //string input

		else if(!strcmp(o,"free")){
			OI++;
			int index=getVariableIndexByName(orders[OI]);
			free_MEMORY(VARIABLE_POINTERS[index]);
			strcpy(VARIABLE_NAMES[index],"");
		}

		else if(!strcmp(o,"end"))return;
		else if(!strcmp(o,"yamete"))exit(0);

		else if(!strcmp(o,"__assign_int__")){
			OI++;
			assignVariableByName(orders[OI],pop());
		}
		else if(!strcmp(o,"__assign_str__")){
			OI++;
			stringStackPop();
			assignVariableStringByName(orders[OI],stringStackPopped);
		}
		else if(isSymbol(o)){
			if(stackmode)push(getVariableValueByName(o));
			else getVariableStringByName(o),stringStackPush(__varString);
		}

		else if(!strcmp(o,"__str_concat__")){
			char a[W_MAX];
			stringStackPop();
			strcpy(a,stringStackPopped);
			stringStackPop();
			strcat(stringStackPopped,a);
			stringStackPush(stringStackPopped);
		}

		else if(o[0]=='+')push(pop()+pop());
		else if(o[0]=='-'&&o[1]=='\0'){int a=pop();push(pop()-a);}
		else if(o[0]=='*')push(pop()*pop());
		else if(o[0]=='/'){
			int a=pop();
			int b=pop();
			if(!a)executionError("tried to divide by 0");goto nonono;
			push(b/a);
nonono:;
		}
		else if(o[0]=='^'){int a=pop();push(intPower(pop(),a));}

		else if(!strcmp(o,"not"))push(!pop());
		else if(o[0]=='=')push(pop()==pop());
		else if(o[0]=='<'){int a=pop();push(pop()<a);}
		else if(o[0]=='>'){int a=pop();push(pop()>a);}

		if(DEBUG){
			for(int s=0;s<stackTop+1;s++){
				printf("stack[%d] = %d",s,stack[s]);
				if(s==stackTop)printf(" <--");
				printf("\n");
			}
		}
	}
}
void executionError(const char error[]){
	printf("%sEXECUTION ERROR (orders[%d] = \"%s\"): %s%s\n",fg_red,OI,orders[OI],error,style_reset);
	ERROR=true;
}
void stringStackPush(const char s[]){
	if(StringStackTop>=SS_SIZE-1)
		executionError("string-stack overflow");
	else StringStackTop++,strcpy(stringStack[StringStackTop],s);;
}
void stringStackPop(){
	if(StringStackTop<=-1)
		executionError("string-stack underflow");
	else
		strcpy(stringStackPopped,stringStack[StringStackTop]),
		StringStackTop--;
}


void push(int i){
	if(stackTop>=S_STACK-1)
		executionError("stack overflow");
	else stackTop++,stack[stackTop]=i;
}
int pop(){
	if(stackTop<=-1){
		executionError("stack underflow");
		return 0;
	}else{
		stackTop--;
		return stack[stackTop+1];
	}
}

int intParse(const char s[]){
	int numb=0;
	bool d;
	const char digits[]="0123456789";
	for(int i=strlen(s)-1,pot10=0;i>=0;i--,pot10++){
		if (s[i]=='-'){
			numb=numb*-1;
		}else{
			d=0;
			for(int u=0;u<10;u++){
				if(digits[u]==s[i]){
					numb+=u*intPower(10,pot10);
					d=1;
				}
			}
			if(!d)pot10--;
		}
	}
	return numb;
}

int intPower(int x,int y){
	if(!y)return 1;
	if(y>0){
		int b=x;
		for(;y-1;y--)x=x*b;
		return x;
	}
	return 0;
}

void next(){
	tokenIndex++;
}
void place(const char t[]){
	if(SW___)orderIndex++;
	strcpy(orders[orderIndex],t);
	SW___=true;
}
bool check(const char t[]){
	return !strcmp(tokens[tokenIndex],t);
}
bool checkNext(const char t[]){
	return !strcmp(tokens[tokenIndex+1],t);
}
bool stringIsIn(const char s[],const char p[L_MAX][W_MAX]){
	for(int i=0;strcmp(p[i],"")&&i<L_MAX;i++){
		if(!strcmp(s,p[i]))return true;
	}return false;
}
bool stringContainsChar(const char s[],const char p[]){
	for(int i=0;i<strlen(s);i++){
		for(int u=0;u<strlen(p);u++){
			if(s[i]==p[u])return true;
		}
	}return false;
}
bool isInteger(const char s[]){
	if(!strcmp(s,"-"))return false;
	const char numbers[10]="0123456789";
	for(int i=0;s[i]!='\0'&&i<W_MAX;i++){
		for(int u=0;u<10;u++){
			if(s[i]==numbers[u]||(s[i]=='-'&&!i))goto cont;
		}return false;
cont:;
	}return true;
}
bool isSymbol(const char s[]){
	return !isInteger(s)&&!stringIsIn(s,RES_WORDS)&&!stringContainsChar(s,DIV_CHARS);
}
void parse(){
	code();
}
void code(){
	char bs[L_MAX][W_MAX]={"if","while","for","def"};
	while(!check("")){
		if(divChar(tokens[tokenIndex][0]))return; //end of block
		else if(stringIsIn(tokens[tokenIndex],bs))
			block();
		else expression();
		next();
	}
	return;
}
void block(){
}
void expression(){
	if(check("print")){
		next();
		numeric();
		place("print");
	}
	else if(check("write")){
		next();
		place("__str_stack_mode__");
		stringExpression();
		place("write");
		place("__int_stack_mode__");
	}
	/*else if(check("goto")){
		next()
		if(!isSymbol(tokens[tokenIndex]))
			syntaxError("expected flag");
		place("goto");
		place(tokens[tokenIndex]);
	}*/
	/*
	else if(check("int")){
		next();
		declareNumeric();
	}
	else if(check("str")){
		next();
		declareString();
	}*/
	else if(check("free")){
		place("free");
		next();
		if(!isSymbol(tokens[tokenIndex]))syntaxError("expected symbol");
		place(tokens[tokenIndex]);
	}
	else if(isSymbol(tokens[tokenIndex])){
		if(checkNext("=")&&tokens[tokenIndex+2][0]=='=')declareString();
		else if(checkNext("="))declareNumeric();
		else if(checkNext("+")||checkNext("-")){
			char v[W_MAX];
			strcpy(v,tokens[tokenIndex]);
			next();
			char o[W_MAX];
			strcpy(o,tokens[tokenIndex]);
			
			int i=1;for(;checkNext("+")||checkNext("-");i++){
				next();
				if(!checkNext(o))i--;
			}
			char n[W_MAX]="____________";
			sprintf(n,"%d",i);
			
			place(n);
			place(v);
			place(o);
			place("__assign_int__");
			place(v);
		}
		//else if(check(":")); //goto
		//else //kalla funktion
	}
	else if(check("end"))place("end");
	else if(check("yamete"))place("yamete");

	else syntaxError("unknown expression");
}
void declareNumeric(){
	char v[W_MAX]="____________";
	strcpy(v,tokens[tokenIndex]);
	next();
	next();
	numeric();
	place("__assign_int__");
	place(v);
}
void declareString(){
	place("__str_stack_mode__");
	char v[W_MAX]="____________";
	if(!isSymbol(tokens[tokenIndex]))syntaxError("expected symbol");
	strcpy(v,tokens[tokenIndex]);
	next();
	next();
	next();
	stringExpression();
	place("__assign_str__");
	place(v);
	place("__int_stack_mode__");
}
void stringExpression(){
	string();
	while(checkNext("+")){
		next();
		next();  // |o| (o) <o> |-o-| (-o-) <-o-> --o-O-o--
		string();
		place("__str_concat__");
	}
}
void string(){
	if(isSymbol(tokens[tokenIndex])){
		printf(">%s\n",tokens[tokenIndex]);place(tokens[tokenIndex]);
	}
	if(check("'")){
		next();
		char s[W_MAX]="\"";
		strcat(s,tokens[tokenIndex]);
		place(s);
		if(!checkNext("'"))syntaxError("expected end of string '''");
		next();
	}
}
void numeric(){
	or_();
}
void or_(){
	and_();
	while(checkNext("or")){
		next();
		next();
		and_();
		place("+");
	}
}
void and_(){
	not_();
	while(checkNext("and")){
		next();
		next();
		not_();
		place("*");
	}
}
void not_(){
	if(check("not")){
		next();
		not_();
		place("not");
	}
	else compare_();
}
void compare_(){
	mathExpression();
	while(checkNext("<")||checkNext(">")||checkNext("=")){
		next();
		char o[1];
		strcpy(o,tokens[tokenIndex]);
		next();
		mathExpression();
		if(o[0]=='=')place("_=");
		else place(o);
	}
}
void mathExpression(){
	term();
	while(checkNext("+")||checkNext("-")){
		next();
		char o[1];
		strcpy(o,tokens[tokenIndex]);
		next();
		term();
		place(o);
	}
}
void term(){
	factor();
	while(checkNext("*")||checkNext("/")){
		next();
		char o[1];
		strcpy(o,tokens[tokenIndex]);
		next();
		factor();
		place(o);
	}
}
void factor(){
	potens();
	while(checkNext("^")){
		next();
		next();
		potens();
		place("^");
	}
}
void potens(){
	if(check("(")){
		next();
		numeric();
		next();
		if(!check(")"))
			syntaxError("expected ')'");
	}
	else if(check("-")&&
	  (isInteger(tokens[tokenIndex+1])||
	    isSymbol(tokens[tokenIndex+1]))){
		next();
		char s[W_MAX]="-";
		strcpy(s,strcat(s,tokens[tokenIndex]));
		place(s);
	}
	else if(isInteger(tokens[tokenIndex])||
	    isSymbol(tokens[tokenIndex])){
		place(tokens[tokenIndex]);
	}
	else if(check("true"))	place("1");
	else if(check("false"))	place("0");
	else if(check("input"))	place("input");
	else if(isSymbol(tokens[tokenIndex]))place(tokens[tokenIndex]);

	else syntaxError("expected value");
}

void syntaxError(const char error[]){
	printf("%sSYNTAX ERROR (tokens[%d] = \"%s\"): %s%s\n",fg_red,tokenIndex,tokens[tokenIndex],error,style_reset);
	ERROR=true;
}

void debug(char s[]){
	if(DEBUG)printf("%s",s);

}
void lex(const char inp[],char x[L_MAX][W_MAX]){	
	int t=0;	
	int ti=0;	
	for(int i=0;i<W_MAX&&inp[i]!='\0';i++){	
		char c=inp[i];	
		if(deadChar(c)){if(x[t][0]!='\0')t++;ti=0;}
		else if(c=='\''){
			x[t][0]='\'';t++;ti=0;
			for(i++;i<W_MAX&&inp[i]!='\0'&&inp[i]!='\'';i++,ti++){
				if(inp[i]=='\\'){
					i++;
					if		(inp[i]=='n')x[t][ti]='\n';
					else if	(inp[i]=='t')x[t][ti]='\t';
					else goto cont;
					goto skip;
				}
cont:
				x[t][ti]=inp[i];
skip:;
			}t++;
			x[t][0]='\'';ti=0;t++;
		}
		else if(c=='#'&&inp[i+1]=='#'){for(i++;i<W_MAX&&inp[i]!='\0'&&!(inp[i]=='#'&&inp[i+1]=='#');i++);i++;}
		else if(c=='#'){for(i++;i<W_MAX&&inp[i]!='\0'&&inp[i]!='#'&&inp[i]!='\n';i++);}
		else if(divChar(c)){if(x[t][0]!='\0')t++;ti=0;x[t][ti]=c;t++;}	
		else x[t][ti]=c,ti++;	
	}	
}	
bool deadChar(char c){	
	for(int i=0;i<strlen(DEAD_CHARS);i++){	
		if(c==DEAD_CHARS[i])return true;	
	}return false;	
}	
bool divChar(char c){	
	for(int i=0;i<strlen(DIV_CHARS);i++){	
		if(c==DIV_CHARS[i])return true;	
	}return false;	
}	
void prompt(char esc,const char p[],char x[],int max){	
	printf("%s",p);	
	if(esc!='\n')printf(" (enter='%c')",esc);	
	printf("> ");	
	char r[max+1];char c;	
    char*pr=&r[0];	
	int i;	
    for(i=0;(c=getchar())!=esc&&i<max;i++)x[i]=c;	
    x[i]='\0';	
}

void prompt_MEMORY(char esc,int promptY,int destinationY,int max){	
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
void putString_MEMORY(int y,const char s[_MEMORY_X_SIZE_]){	
    int i=0;	
    for(;s[i]!='\0'&&i<_MEMORY_X_SIZE_;i++)	
        putChar_MEMORY(y,i,s[i]);	
    for(;i<_MEMORY_X_SIZE_;i++)	
        putChar_MEMORY(y,i,'\0');	
}	
int putString_RandomAccess_MEMORY(const char s[_MEMORY_X_SIZE_]){	
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

int appendCopyStringList_MEMORY(int l,int y){
	getStringInList_MEMORY(l,y);
	int i=y;
	for(;!compareStrings_PS_MEMORY(i,EMPTY_STRING_LIST);i++);
	if(compareStrings_PS_MEMORY(i,END_OF_STRING_LIST))error_S_SYSTEM("list range exeeded");

	copyStringIntoList_MEMORY(l,i,y);
}

int appendStringList_MEMORY(int l,char s[_MEMORY_X_SIZE_]){

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

