#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char style_reset[] = "\033[0m", style_bold[] = "\033[01m",
           style_disable[] = "\033[02m", style_underline[] = "\033[04m",
           style_reverse[] = "\033[07m", style_strikethrough[] = "\033[09m",
           style_invisible[] = "\033[08m", fg_black[] = "\033[30m",
           fg_red[] = "\033[31m", fg_green[] = "\033[32m",
           fg_orange[] = "\033[33m", fg_blue[] = "\033[34m",
           fg_purple[] = "\033[35m", fg_cyan[] = "\033[36m",
           fg_lightgrey[] = "\033[37m", fg_darkgrey[] = "\033[90m",
           fg_lightred[] = "\033[91m", fg_lightgreen[] = "\033[92m",
           fg_yellow[] = "\033[93m", fg_lightblue[] = "\033[94m",
           fg_pink[] = "\033[95m", fg_lightcyan[] = "\033[96m",
           bg_black[] = "\033[40m", bg_red[] = "\033[41m",
           bg_green[] = "\033[42m", bg_orange[] = "\033[43m",
           bg_blue[] = "\033[44m", bg_purple[] = "\033[45m",
           bg_cyan[] = "\033[46m", bg_lightgrey[] = "\033[47m";

// SYSTEM
void error_P_SYSTEM (int m); // SYSTEM ERROR MEDDELANDE
void error_S_SYSTEM (char m[]);

unsigned int alert_number_SYSTEM = 0;

// HEMMAGJORT MINNESSYSTEM + PEKARE
#define _MEMORY_X_SIZE_ 100 // STRÄNGSTORLEK
#define _MEMORY_Y_SIZE_ 100 // STRÄNGKAPACITET

char CHAR_MEMORY[_MEMORY_X_SIZE_ * _MEMORY_Y_SIZE_];
// char  INT_MEMORY[_MEMORY_X_SIZE_*_MEMORY_Y_SIZE_];

void clear_MEMORY ();

void debug_CHAR_MEMORY ();
// void debug_INT_MEMORY();

char getChar_MEMORY (int y, int x);
// int   getInt_MEMORY(int y,int x);

void putChar_MEMORY (int y, int x, char c);
void putString_MEMORY (int y, const char s[_MEMORY_X_SIZE_]);

int putString_RandomAccess_MEMORY (const char s[_MEMORY_X_SIZE_]);
int find_RandomAccess_MEMORY (int n);

void printChar_MEMORY (int y, int x);
void printString_MEMORY (int y, int endLine);

void free_MEMORY (int y);

// STRÄNG-MANIPULATIONSFUNKTIONER
void concatStrings_PP_MEMORY (int a, int b, int del);          // PEKARE, PEKARE
void concatStrings_PS_MEMORY (int a, char b[_MEMORY_X_SIZE_]); // PEKARE, STRÄNG

int compareStrings_PP_MEMORY (int a, int b);
int compareStrings_PS_MEMORY (int a, char b[_MEMORY_X_SIZE_]);

int stringLength_MEMORY (int y);

void copyString_MEMORY (int a, int b);

void prompt_MEMORY (char esc, int promptY, int destinationY, int max);

// FUNKTIONER HANTERANDE STRÄNGLISTOR M.M.
char EMPTY_STRING_LIST[] = "_empty_string_list_";
char END_OF_STRING_LIST[] = "_end_of_string_list_";

int createStringList_RandomAccess_MEMORY (int l);

int stringListLength_MEMORY (int y);

int getStringInList_MEMORY (int l, int y);
void copyStringIntoList_MEMORY (int l, int y, int p);
void copyStringFromList_MEMORY (int l, int y, int p);
void putStringIntoList_MEMORY (int l, int y, char s[_MEMORY_X_SIZE_]);
int appendCopyStringList_MEMORY (int l, int y);
int appendStringList_S_MEMORY (int l, char s[_MEMORY_X_SIZE_]);

void freeStringList_MEMORY (int y);

#define bool byte
#define true 1
#define false 0

// PROGRAMSTORLEK
#define L_MAX 500
#define W_MAX 100
#define S_STACK 100

#define DATA_MAX 10000 // INDATA

typedef unsigned char byte;

const char DEAD_CHARS[] = " \n\t";
const char DIV_CHARS[] = ".,:;+-*/?!\"\'=([{}])<>|&%%@£$¤#~^\\→↓↑←«»±";
const char RES_WORDS[L_MAX][W_MAX] = { "print",
                                       "input",
                                       "goto",
                                       "or",
                                       "and",
                                       "not",
                                       "if",
                                       "else",
                                       "while",
                                       "loop",
                                       "def",
                                       "true",
                                       "false",
                                       "yamete",
                                       "end",
                                       "int",
                                       "str",
                                       "__assign_int__",
                                       "__assign_str__",
                                       "__declare_int__",
                                       "__declare_str__",
                                       "__declare_or_assign_int__",
                                       "__declare_or_assign_str__",
                                       "__str_concat__",
                                       "__str_stack_mode__",
                                       "__int_stack_mode__",
                                       "free",
                                       "write",
                                       "__int_user_input__",
                                       "__str_user_input__",
                                       "__int_to_str_stack__",
                                       "__str_to_int_stack__",
                                       "__str_compare__",
                                       "__str_index__",
                                       "__str_check_inside__",
                                       "in",
                                       "exe",
                                       "return",
                                       "new",
                                       "xor",
                                       "nand",
                                       "xnor",
                                       "nor",
                                       "__push_function_stack__",
                                       "open_hood",
                                       "close_hood",
                                       "__clearup__" };

const char preOrders[W_MAX] = "n=='\\n'";

void prompt (char esc, const char p[], char x[], int max);

char tokens[L_MAX][W_MAX];
void lex (const char inp[DATA_MAX], char x[L_MAX][W_MAX]);
bool deadChar (char c);
bool divChar (char c);

char orders[L_MAX][W_MAX];
void next ();
void place (const char t[W_MAX]);
bool check (const char t[W_MAX]);
bool checkNext (const char t[W_MAX]);
bool stringIsIn (const char s[W_MAX], const char p[L_MAX][W_MAX]);
bool stringContainsChar (const char s[W_MAX], const char p[W_MAX]);
bool isInteger (const char s[W_MAX]);
bool isSymbol (const char s[W_MAX]);
void parse ();

bool SW___ = false;
int tokenIndex = 0;
int orderIndex = 0;

int blockNest[2] = { -1, 0 };
void placeFlag (bool type, bool type2, int na, int nb);
void placeBlock (char v[W_MAX], const char type[W_MAX]);
void code ();
void block ();
void expression ();

void function ();

void declareNewNumeric_SYNTAX ();
void declareNewString_SYNTAX ();
void declareOrAssignNumeric_SYNTAX ();
void declareOrAssignString_SYNTAX ();

void stringExpression ();
void stringConcation ();
void stringIndex ();
void string ();

void numeric ();
void weirdLogicGates ();
void or_ ();
void and_ ();
void not_ ();
void compare_ ();
void mathExpression ();
void term ();
void factor ();
void potens ();

void execute ();
void executionError (const char error[]);
int OI = 0;

void doPreOrders ();

int stack[S_STACK];
int stackTop = -1;
void push (int i);
int pop ();

int intParse (const char s[W_MAX]);

int intPower (int x, int y);

void syntaxError (const char error[]);
void debug (char s[]);
bool DEBUG = false;
bool GETINPUT = true;
bool DO_PREORDERS = true;

bool ERROR = false;

void clear (bool all);

// VIRITUELLA VARIABLER
int _vi = 0; // variable index
unsigned int VARIABLE_POINTERS[L_MAX];
char VARIABLE_NAMES[L_MAX][W_MAX];

int getVariableIndexByName (const char n[W_MAX]);
int getVariableValueByName (const char n[W_MAX]);
void declareOrAssignInteger (const char n[W_MAX], const int v);
void assignVariableByName (const char n[W_MAX], const int v);
void declareVariableByName (const char n[W_MAX], const int v);

void declareOrAssignString (const char n[W_MAX], const char s[W_MAX]);
void assignVariableStringByName (const char n[W_MAX], const char s[W_MAX]);
void declareVariableStringByName (const char n[W_MAX], const char s[W_MAX]);
void getVariableStringByName (const char n[W_MAX]);
char __varString[W_MAX];

// STRÄNGSTACK
#define SS_SIZE 10

char stringStack[SS_SIZE][W_MAX];
int StringStackTop = -1;

void stringStackPush (const char s[W_MAX]);
void stringStackPop ();
char stringStackPopped[W_MAX] = "";

char codeInput[DATA_MAX] = "";

// FUNKTIONER

char functionStack[S_STACK];
int functionStackTop = -1;

void functionStackPush (int orderIndex);
int functionStackPop ();

int
main (int argc, char *argv[])
{

  clear_MEMORY ();
  clear (1);

  bool noExe = false;
  for (int i = 0; i < argc; i++)
    {
      if (!strcmp (argv[i], "-d"))
        DEBUG = true;
      else if (!strcmp (argv[i], "-s"))
        noExe = true;
      else if (!strcmp (argv[i], "-p"))
        DO_PREORDERS = false;
      else if (!strcmp (argv[i], "-f"))
        {
          i++;
          GETINPUT = false;

          FILE *fp;
          fp = fopen (argv[i], "r");
          if (!fp)
            {
              printf ("File error.\n");
              return 1;
            }
          char c = fgetc (fp);
          for (int i = 0; c != EOF && i < DATA_MAX; i++)
            {
              codeInput[i] = c;
              c = fgetc (fp);
            }
          fclose (fp);
        }
    }

  if (DO_PREORDERS)
    doPreOrders ();

  do
    {
      if (GETINPUT)
        prompt ('\n', /*argv[0]*/ "megumin.c", codeInput, DATA_MAX);

      lex (codeInput, tokens);

      parse (tokens);

      if (DEBUG)
        {
          for (int i = 0; strcmp (tokens[i], ""); i++)
            printf ("token[%d]:\t%s\n", i, tokens[i]);
          printf ("\n");
          for (int i = 0; strcmp (orders[i], ""); i++)
            printf ("order[%d]:\t%s\n", i, orders[i]);
          printf ("\n");
        }

      if (ERROR || noExe)
        goto abort_execution;

      execute ();

    abort_execution:

      clear (0);
    }
  while (GETINPUT);

  return 0;
}

void
doPreOrders ()
{
  if (DEBUG)
    printf ("pre-procedure instructions begin\n");
  lex (preOrders, tokens);
  parse (tokens);
  execute ();
  clear (0);
  if (DEBUG)
    printf ("pre-procedure instructions end\n\n");
}

void
clear (bool all)
{
  for (int y = 0; y < L_MAX; y++)
    {
      if (all)
        VARIABLE_POINTERS[y] = 0;
      for (int x = 0; x < W_MAX; x++)
        {
          tokens[y][x] = '\0';
          orders[y][x] = '\0';
          if (all)
            VARIABLE_NAMES[y][x] = '\0';
        }
    }
  for (int i = 0; i < S_STACK; i++)
    stack[i] = 0;
  if (all)
    {
      for (int i = 0; i < DATA_MAX; i++)
        codeInput[i] = 0;
    }

  stackTop = -1;

  SW___ = false;
  tokenIndex = 0;
  orderIndex = 0;
  ERROR = false;
  OI = 0;
}
int
getVariableIndexByName (const char n[])
{
  int i = 0;
  for (; strcmp (VARIABLE_NAMES[i], "") && i < L_MAX; i++)
    ;
  for (; i >= 0; i--)
    if (!strcmp (n, VARIABLE_NAMES[i]))
      return i;
  printf ("Fatal error.\n");
  exit (1);
}
int
getVariableValueByName (const char n[])
{
  int index, pointer;
  if (stringIsIn (n, VARIABLE_NAMES))
    {
      index = getVariableIndexByName (n);
      pointer = VARIABLE_POINTERS[index];
      char value[_MEMORY_X_SIZE_] = "____________________________";
      for (int i = 0;
           i < _MEMORY_X_SIZE_ && getChar_MEMORY (pointer, i) != '\0'; i++)
        value[i] = getChar_MEMORY (pointer, i);
      return intParse (value);
    }
  else
    executionError ("unknown symbol, expected variable");
}
void
declareOrAssignInteger (const char n[], const int v)
{
  if (stringIsIn (n, VARIABLE_NAMES))
    assignVariableByName (n, v);
  else
    declareVariableByName (n, v);
}
void
assignVariableByName (const char n[], const int v)
{
  int index, pointer;
  if (stringIsIn (n, VARIABLE_NAMES))
    {
      index = getVariableIndexByName (n);
      pointer = VARIABLE_POINTERS[index];
      char value[_MEMORY_X_SIZE_] = "___________________________";
      sprintf (value, "%d", v);
      putString_MEMORY (pointer, value);
    }
  else
    executionError ("tried to assign a non-existing variable");
}
void
declareVariableByName (const char n[], const int v)
{
  int index, pointer;
  int i = 0;
  for (; strcmp (VARIABLE_NAMES[i], ""); i++)
    {
      if (i == L_MAX - 1)
        executionError ("out of variable space");
    }
  index = i;
  strcpy (VARIABLE_NAMES[index], n);
  char value[_MEMORY_X_SIZE_] = "___________________________";
  sprintf (value, "%d", v);
  pointer = putString_RandomAccess_MEMORY (value);
  VARIABLE_POINTERS[index] = pointer;
}
void
declareOrAssignString (const char n[], const char s[])
{
  if (stringIsIn (n, VARIABLE_NAMES))
    assignVariableStringByName (n, s);
  else
    declareVariableStringByName (n, s);
}
void
assignVariableStringByName (const char n[], const char s[])
{
  int index, pointer;
  if (stringIsIn (n, VARIABLE_NAMES))
    {
      index = getVariableIndexByName (n);
      pointer = VARIABLE_POINTERS[index];
      putString_MEMORY (pointer, s);
    }
  else
    executionError ("tried to assign a non-existing variable");
}
void
declareVariableStringByName (const char n[], const char s[])
{
  int index, pointer;
  int i = 0;
  for (; strcmp (VARIABLE_NAMES[i], ""); i++)
    {
      if (i == L_MAX - 1)
        executionError ("out of variable space");
    }
  index = i;
  strcpy (VARIABLE_NAMES[index], n);
  pointer = putString_RandomAccess_MEMORY (s);
  VARIABLE_POINTERS[index] = pointer;
}
void
getVariableStringByName (const char n[])
{
  int index, pointer;
  if (stringIsIn (n, VARIABLE_NAMES))
    {
      index = getVariableIndexByName (n);
      pointer = VARIABLE_POINTERS[index];
      char string[_MEMORY_X_SIZE_] = "";
      for (int i = 0;
           i < _MEMORY_X_SIZE_ && getChar_MEMORY (pointer, i) != '\0'; i++)
        string[i] = getChar_MEMORY (pointer, i);
      strcpy (__varString, string);
    }
  else
    executionError ("unknown symbol, expected variable");
}

void
functionStackPush (int orderIndex)
{
  if (functionStackTop >= S_STACK - 1)
    executionError ("function-stack overflow");
  else
    functionStackTop++, functionStack[functionStackTop] = orderIndex;
}
int
functionStackPop ()
{
  if (functionStackTop <= -1)
    executionError ("function-stack underflow");
  else
    {
      functionStackTop--;
      return functionStack[functionStackTop + 1];
    }
}

void
execute ()
{
  bool stackmode = true; // true: int, false: str
  for (; orders[OI][0] != '\0' && !ERROR && OI < L_MAX; OI++)
    {
      char o[W_MAX];
      strcpy (o, orders[OI]);

      if (DEBUG)
        {
          printf ("order[%d]: %s\n", OI, o);

          for (int i = 0; i < 5 /*strcmp(VARIABLE_NAMES[i],"")*/; i++)
            {
              char val[W_MAX] = "";
              int u;
              for (u = VARIABLE_POINTERS[i] * _MEMORY_X_SIZE_;
                   u < (VARIABLE_POINTERS[i] + 1) * _MEMORY_X_SIZE_; u++)
                val[u - VARIABLE_POINTERS[i] * _MEMORY_X_SIZE_]
                    = CHAR_MEMORY[u];
              val[u] = '\0';
              printf ("VARIABLE_NAME[%d]:\t%s (%d) = '%s'\n", i,
                      VARIABLE_NAMES[i], VARIABLE_POINTERS[i], val);
            } // printf("\n");

          printf ("\n");
        }

      if (!strcmp (o, "__str_stack_mode__"))
        stackmode = false;
      else if (!strcmp (o, "__int_stack_mode__"))
        stackmode = true;

      else if (isInteger (o) && stackmode)
        push (intParse (o));
      else if (!strcmp (o, "__int_to_str_stack__"))
        {
          char n[W_MAX] = "____________________________";
          sprintf (n, "%d", pop ());
          stringStackPush (n);
        }
      else if (!strcmp (o, "__str_to_int_stack__"))
        {
          stringStackPop ();
          push (intParse (stringStackPopped));
        }
      else if (o[0] == '"')
        {
          char s[W_MAX] = "";
          for (int i = 1; i < strlen (o); i++)
            s[i - 1] = o[i];
          stringStackPush (s);
        }

      else if (!strcmp (o, "__push_function_stack__"))
        {
          functionStackPush (OI + 2);
          if (DEBUG)
            printf ("(pushing %i to function stack)\n", OI + 2);
        }
      else if (!strcmp (o, "return"))
        {
          OI = functionStackPop ();
        }

      else if (!strcmp (o, "exe"))
        stringStackPop (), system (stringStackPopped);

      else if (!strcmp (o, "open_hood"))
        DEBUG = true;
      else if (!strcmp (o, "close_hood"))
        DEBUG = false;

      else if (!strcmp (o, "goto"))
        {
          OI++;
          if (DEBUG)
            printf ("(goto '%s')\n", orders[OI]);
          char mf[W_MAX] = ":";
          for (int i = 0; i < strlen (orders[OI]); i++)
            mf[i + 1] = orders[OI][i];
          int i = 0;
          for (; strcmp (mf, orders[i]); i++)
            {
              if (i == L_MAX - 1)
                {
                  executionError ("flag not found");
                  goto skip;
                }
            }
          OI = i;
        skip:;
        }
      else if (!strcmp (o, "if"))
        {
          OI++;
          if (!pop ())
            {
              if (DEBUG)
                printf ("(goto '%s')\n", orders[OI]);
              char mf[W_MAX] = ":";
              for (int i = 0; i < strlen (orders[OI]); i++)
                mf[i + 1] = orders[OI][i];
              int i = 0;
              for (; strcmp (mf, orders[i]); i++)
                {
                  if (i == L_MAX - 1)
                    {
                      executionError ("flag not found");
                      goto skip2;
                    }
                }
              OI = i;
            skip2:;
            }
        }

      //		else
      //if(!strcmp(o,"print"))printf("%s%s%d%s\n",style_bold,fg_yellow,pop(),style_reset);
      else if (!strcmp (o, "print"))
        stringStackPop (), printf ("%s%s%s%s", style_bold, fg_yellow,
                                   stringStackPopped, style_reset);
      else if (!strcmp (o, "__int_user_input__"))
        {
          char inp[W_MAX] = "____________";
          prompt ('\n', "PROGRAM INPUT: INTEGER", inp, W_MAX);
          push (intParse (inp));
        }
      else if (!strcmp (o, "__str_user_input__"))
        {
          char inp[W_MAX] = "";
          prompt ('\n', "PROGRAM INPUT: STRING", inp, W_MAX);
          stringStackPush (inp);
        }

      else if (!strcmp (o, "free"))
        {
          OI++;
          if (DEBUG)
            printf ("(free '%s')\n", orders[OI]);
          if (stringIsIn (orders[OI], VARIABLE_NAMES))
            {
              int index = getVariableIndexByName (orders[OI]);
              free_MEMORY (VARIABLE_POINTERS[index]);
              strcpy (VARIABLE_NAMES[index], "");
            }
          else
            executionError ("unknown symbol, expected variable");
        }

      else if (!strcmp (o, "__clearup__"))
        {
          OI++;
          if (DEBUG)
            printf ("(clearup '%s')\n", orders[OI]);
          char b[W_MAX] = "";
          strcpy (b, orders[OI]);
          int i = 0;
          for (; strcmp (VARIABLE_NAMES[i], b) && i < L_MAX; i++)
            ;
          for (; strcmp (VARIABLE_NAMES[i], ""); i++)
            strcpy (VARIABLE_NAMES[i], "");
        }

      else if (!strcmp (o, "end"))
        return;
      else if (!strcmp (o, "yamete"))
        exit (0);

      else if (!strcmp (o, "__declare_or_assign_int__"))
        {
          OI++;
          if (DEBUG)
            printf ("(declare or assign '%s')\n", orders[OI]);
          declareOrAssignInteger (orders[OI], pop ());
        }
      else if (!strcmp (o, "__declare_or_assign_str__"))
        {
          OI++;
          if (DEBUG)
            printf ("(declare or assign '%s')\n", orders[OI]);
          stringStackPop ();
          declareOrAssignString (orders[OI], stringStackPopped);
        }

      else if (!strcmp (o, "__declare_int__"))
        {
          OI++;
          if (DEBUG)
            printf ("(declare '%s')\n", orders[OI]);
          declareVariableByName (orders[OI], pop ());
        }
      else if (!strcmp (o, "__declare_str__"))
        {
          OI++;
          if (DEBUG)
            printf ("(declare '%s')\n", orders[OI]);
          stringStackPop ();
          declareVariableStringByName (orders[OI], stringStackPopped);
        }

      else if (!strcmp (o, "__assign_int__"))
        {
          OI++;
          if (DEBUG)
            printf ("(assign '%s')\n", orders[OI]);
          assignVariableByName (orders[OI], pop ());
        }
      else if (!strcmp (o, "__assign_str__"))
        {
          OI++;
          if (DEBUG)
            printf ("(assign '%s')\n", orders[OI]);
          stringStackPop ();
          assignVariableStringByName (orders[OI], stringStackPopped);
        }

      else if (isSymbol (o))
        {
          if (stackmode)
            push (getVariableValueByName (o));
          else
            getVariableStringByName (o), stringStackPush (__varString);
        }

      else if (!strcmp (o, "__str_concat__"))
        {
          char a[W_MAX];
          stringStackPop ();
          strcpy (a, stringStackPopped);
          stringStackPop ();
          strcat (stringStackPopped, a);
          stringStackPush (stringStackPopped);
        }
      else if (!strcmp (o, "__str_compare__"))
        {
          char a[W_MAX];
          stringStackPop ();
          strcpy (a, stringStackPopped);
          stringStackPop ();
          push (!strcmp (stringStackPopped, a));
        }
      else if (o[0] == '+')
        push (pop () + pop ());
      else if (o[0] == '-' && o[1] == '\0')
        {
          int a = pop ();
          push (pop () - a);
        }
      else if (o[0] == '*')
        push (pop () * pop ());
      else if (o[0] == '/')
        {
          int a = pop ();
          int b = pop ();
          if (!a)
            executionError ("tried to divide by 0");
          goto nonono;
          push (b / a);
        nonono:;
        }
      else if (!strcmp (o, "__str_index__"))
        {
          const int b = pop ();
          const int a = pop ();
          char r[W_MAX] = "";
          stringStackPop ();
          for (int i = a; i <= b && stringStackPopped[i] != '\0'; i++)
            r[i - a] = stringStackPopped[i];
          stringStackPush (r);
        }
      else if (!strcmp (o, "__str_check_inside__"))
        {
          stringStackPop ();
          char t[W_MAX] = "";
          strcpy (t, stringStackPopped);
          stringStackPop ();
          for (int i = 0; i < W_MAX; i++)
            {
              for (int u = i; u - i < strlen (stringStackPopped); u++)
                {
                  if (t[u] == '\0')
                    goto fals;
                  if (stringStackPopped[u - i] != t[u])
                    goto cont;
                }
              push (true);
              goto done;
            cont:;
            }
        fals:
          push (false);
        done:;
        }

      else if (o[0] == '^')
        {
          int a = pop ();
          push (intPower (pop (), a));
        }

      else if (!strcmp (o, "not"))
        push (!pop ());
      else if (o[0] == '=')
        push (pop () == pop ());
      else if (o[0] == '<')
        {
          int a = pop ();
          push (pop () < a);
        }
      else if (o[0] == '>')
        {
          int a = pop ();
          push (pop () > a);
        }

      if (DEBUG)
        {
          for (int s = 0; s < stackTop + 1; s++)
            {
              printf ("stack[%d] = %d", s, stack[s]);
              if (s == stackTop)
                printf (" <--");
              printf ("\n");
            }
        }
      if (DEBUG)
        {
          for (int s = 0; s < StringStackTop + 1; s++)
            {
              printf ("stringStack[%d] = \"%s\"", s, stringStack[s]);
              if (s == StringStackTop)
                printf (" <--");
              printf ("\n");
            }
        }
      if (DEBUG)
        {
          for (int s = 0; s < functionStackTop + 1; s++)
            {
              printf ("functionStack[%d] = %d", s, functionStack[s]);
              if (s == functionStackTop)
                printf (" <--");
              printf ("\n");
            }
        }
    }
}
void
executionError (const char error[])
{
  printf ("%sEXECUTION ERROR (orders[%d] = \"%s\"): %s%s\n", fg_red, OI,
          orders[OI], error, style_reset);
  ERROR = true;
}
void
stringStackPush (const char s[])
{
  if (StringStackTop >= SS_SIZE - 1)
    executionError ("string-stack overflow");
  else
    StringStackTop++, strcpy (stringStack[StringStackTop], s);
  ;
}
void
stringStackPop ()
{
  if (StringStackTop <= -1)
    executionError ("string-stack underflow");
  else
    strcpy (stringStackPopped, stringStack[StringStackTop]), StringStackTop--;
}

void
push (int i)
{
  if (stackTop >= S_STACK - 1)
    executionError ("stack overflow");
  else
    stackTop++, stack[stackTop] = i;
}
int
pop ()
{
  if (stackTop <= -1)
    {
      executionError ("stack underflow");
      return 0;
    }
  else
    {
      stackTop--;
      return stack[stackTop + 1];
    }
}

int
intParse (const char s[])
{
  int numb = 0;
  bool d;
  const char digits[] = "0123456789";
  for (int i = strlen (s) - 1, pot10 = 0; i >= 0; i--, pot10++)
    {
      if (s[i] == '-')
        {
          numb = numb * -1;
        }
      else
        {
          d = 0;
          for (int u = 0; u < 10; u++)
            {
              if (digits[u] == s[i])
                {
                  numb += u * intPower (10, pot10);
                  d = 1;
                }
            }
          if (!d)
            pot10--;
        }
    }
  return numb;
}

int
intPower (int x, int y)
{
  if (!y)
    return 1;
  if (y > 0)
    {
      int b = x;
      for (; y - 1; y--)
        x = x * b;
      return x;
    }
  return 0;
}

void
next ()
{
  tokenIndex++;
}
void
place (const char t[])
{
  if (SW___)
    orderIndex++;
  strcpy (orders[orderIndex], t);
  SW___ = true;
}
bool
check (const char t[])
{
  return !strcmp (tokens[tokenIndex], t);
}
bool
checkNext (const char t[])
{
  return !strcmp (tokens[tokenIndex + 1], t);
}
bool
stringIsIn (const char s[], const char p[L_MAX][W_MAX])
{
  for (int i = 0; strcmp (p[i], "") && i < L_MAX; i++)
    {
      if (!strcmp (s, p[i]))
        return true;
    }
  return false;
}
bool
stringContainsChar (const char s[], const char p[])
{
  for (int i = 0; i < strlen (s); i++)
    {
      for (int u = 0; u < strlen (p); u++)
        {
          if (s[i] == p[u])
            return true;
        }
    }
  return false;
}
bool
isInteger (const char s[])
{
  if (!strcmp (s, "-"))
    return false;
  const char numbers[10] = "0123456789";
  for (int i = 0; s[i] != '\0' && i < W_MAX; i++)
    {
      for (int u = 0; u < 10; u++)
        {
          if (s[i] == numbers[u] || (s[i] == '-' && !i))
            goto cont;
        }
      return false;
    cont:;
    }
  return true;
}
bool
isSymbol (const char s[])
{
  return !isInteger (s) && !stringIsIn (s, RES_WORDS)
         && !stringContainsChar (s, DIV_CHARS);
}
void
parse ()
{
  code ();
}
void
code ()
{
  char bs[L_MAX][W_MAX] = { "if", "while", "loop", "def" };
  while (!check (""))
    {
      if (check ("."))
        return; // end of block
      else if (stringIsIn (tokens[tokenIndex], bs))
        block ();
      else
        expression ();
      next ();
    }
  return;
}
void
placeFlag (bool type, bool type2, int na, int nb)
{ // type: 0=start, 1=end; type2: 0=goto, 1=flag.
  char a[W_MAX] = "__________________________________";
  char b[W_MAX] = "__________________________________";
  sprintf (a, "%d", na);
  sprintf (b, "%d", nb);
  char f[W_MAX] = "";
  if (type2)
    strcat (f, ":");
  if (type)
    strcat (f, "end_");
  else
    strcat (f, "start_");
  strcat (f, a);
  strcat (f, "_");
  strcat (f, b);
  place (f);
}
void
placeBlock (char v[], const char type[])
{
  char a[W_MAX] = "__________________________________";
  char b[W_MAX] = "__________________________________";
  sprintf (a, "_%d_", blockNest[0]);
  sprintf (b, "%d", blockNest[1]);
  char f[W_MAX] = "";
  strcpy (f, type);
  strcat (f, a);
  strcat (f, b);
  place (f);

  strcpy (v, f);
}
bool inFunc = false;
void
block ()
{
  blockNest[0]++;
  int a = blockNest[0], b = blockNest[1];
  if (check ("if"))
    {
      place ("0");
      place ("__declare_int__");
      char bf[W_MAX] = "";
      placeBlock (bf, "if");

      next ();
      numeric ();
      place ("if");
      placeFlag (1, 0, a, b);
      next ();
      code ();
      if (!check ("."))
        syntaxError ("excpected end of block");
      placeFlag (1, 1, a, b);

      place ("__clearup__");
      place (bf);
    }
  else if (check ("while"))
    {
      place ("0");
      place ("__declare_int__");
      char bf[W_MAX] = "";
      placeBlock (bf, "while");

      next ();
      placeFlag (0, 1, a, b);
      numeric ();
      place ("if");
      placeFlag (1, 0, a, b);
      next ();
      code ();
      if (!check ("."))
        syntaxError ("excpected end of block");
      place ("goto");
      placeFlag (0, 0, a, b);
      placeFlag (1, 1, a, b);

      place ("__clearup__");
      place (bf);
    }
  else if (check ("loop"))
    {
      place ("0");
      place ("__declare_int__");
      char bf[W_MAX] = "";
      placeBlock (bf, "loop");

      next ();
      if (!isSymbol (tokens[tokenIndex]))
        syntaxError ("excpected variable");
      char v[W_MAX] = "";
      strcpy (v, tokens[tokenIndex]);
      next ();
      numeric ();
      place ("__declare_int__");
      place (v);
      next ();
      placeFlag (0, 1, a, b);
      numeric ();
      place (v);
      place ("=");
      place ("not");
      place ("if");
      placeFlag (1, 0, a, b);
      next ();
      code ();
      place ("1");
      place (v);
      place ("+");
      place ("__assign_int__");
      place (v);
      if (!check ("."))
        syntaxError ("excpected end of block");
      place ("goto");
      placeFlag (0, 0, a, b);
      placeFlag (1, 1, a, b);

      place ("__clearup__");
      place (bf);
      /*place("free");
      place(v);*/
    }
  else if (check ("def"))
    {
      if (inFunc)
        syntaxError ("declaration of function inside another function");
      inFunc = true;
      place ("goto");
      placeFlag (1, 0, a, b);

      next ();
      char bf[W_MAX] = "";
      strcpy (bf, tokens[tokenIndex]);

      char f[W_MAX] = ":";
      strcat (f, bf);
      place (f);

      place ("__int_stack_mode__");
      place ("0");
      place ("__declare_int__");
      if (!isSymbol (bf))
        syntaxError ("expected function name");
      place (bf);

      next ();
      if (!check ("("))
        syntaxError ("excpected '('");
      next ();
      while (isSymbol (tokens[tokenIndex]))
        place ("__declare_str__"), place (tokens[tokenIndex]), next ();
      if (!check (")"))
        syntaxError ("excpected ')'");
      next ();

      code ();

      if (!check ("."))
        syntaxError ("excpected end of block");

      place ("__clearup__");
      place (bf);
      place ("0");
      place ("return");

      placeFlag (1, 1, a, b);
      inFunc = false;
    }
  blockNest[0]--;
  blockNest[1]++;
}
void
expression ()
{
  if (check ("return"))
    {
      if (!inFunc)
        syntaxError ("return outside of function");
      next ();
      stringExpression ();
      place ("return");
      place ("__int_stack_mode__");
    }
  else if (check ("open_hood"))
    place ("open_hood");
  else if (check ("close_hood"))
    place ("close_hood");
  else if (check ("exe"))
    {
      next ();
      stringExpression ();
      place ("exe");
      place ("__int_stack_mode__");
    }
  else if (check ("print"))
    {
      next ();
      stringExpression ();
      place ("print");
      place ("__int_stack_mode__");
    }
  else if (check ("goto"))
    {
      next ();
      if (!isSymbol (tokens[tokenIndex]))
        syntaxError ("expected flag");
      place ("goto");
      place (tokens[tokenIndex]);
    }
  else if (check ("free"))
    {
      place ("free");
      next ();
      if (!isSymbol (tokens[tokenIndex]))
        syntaxError ("expected symbol");
      place (tokens[tokenIndex]);
    }
  else if (check ("new"))
    {
      next ();
      if (isSymbol (tokens[tokenIndex]))
        {
          if (checkNext ("=") && tokens[tokenIndex + 2][0] == '=')
            declareNewString_SYNTAX ();
          else if (checkNext ("="))
            declareNewNumeric_SYNTAX ();
          else
            syntaxError ("expected assignment");
        }
      else
        syntaxError ("expected symbol");
    }
  else if (isSymbol (tokens[tokenIndex]))
    {
      if (checkNext ("=") && tokens[tokenIndex + 2][0] == '=')
        declareOrAssignString_SYNTAX ();
      else if (checkNext ("="))
        declareOrAssignNumeric_SYNTAX ();
      else if (checkNext ("+") || checkNext ("-"))
        {
          char v[W_MAX];
          strcpy (v, tokens[tokenIndex]);
          next ();
          char o[W_MAX];
          strcpy (o, tokens[tokenIndex]);

          int i = 1;
          for (; checkNext (o); i++)
            next ();
          char n[W_MAX] = "____________";
          sprintf (n, "%d", i);

          place (v);
          place (n);
          place (o);
          place ("__assign_int__");
          place (v);
        }
      else if (checkNext (":"))
        {
          char f[W_MAX] = "";
          f[0] = ':';
          for (int i = 0; i < strlen (tokens[tokenIndex]); i++)
            f[i + 1] = tokens[tokenIndex][i];
          place (f);
          next ();
        }
      else if (checkNext ("("))
        {
          function ();
        }
      else
        syntaxError ("unknown expression");
    }
  else if (check ("end"))
    place ("end");
  else if (check ("yamete"))
    place ("yamete");

  else
    syntaxError ("unknown expression");
}
void
function ()
{
  char f[W_MAX] = "";
  strcpy (f, tokens[tokenIndex]);
  next ();
  next ();
  while (1)
    {
      if (check (")"))
        break;
      stringExpression ();
      next ();
    }
  place ("__push_function_stack__");
  place ("goto");
  place (f);
}
void
declareNewNumeric_SYNTAX ()
{
  char v[W_MAX] = "____________";
  strcpy (v, tokens[tokenIndex]);
  next ();
  next ();
  numeric ();
  place ("__declare_int__");
  place (v);
}
void
declareNewString_SYNTAX ()
{
  char v[W_MAX] = "____________";
  if (!isSymbol (tokens[tokenIndex]))
    syntaxError ("expected symbol");
  strcpy (v, tokens[tokenIndex]);
  next ();
  next ();
  next ();
  stringExpression ();
  place ("__declare_str__");
  place (v);
  place ("__int_stack_mode__");
}
void
declareOrAssignNumeric_SYNTAX ()
{
  char v[W_MAX] = "____________";
  strcpy (v, tokens[tokenIndex]);
  next ();
  next ();
  numeric ();
  place ("__declare_or_assign_int__");
  place (v);
}
void
declareOrAssignString_SYNTAX ()
{
  char v[W_MAX] = "____________";
  if (!isSymbol (tokens[tokenIndex]))
    syntaxError ("expected symbol");
  strcpy (v, tokens[tokenIndex]);
  next ();
  next ();
  next ();
  stringExpression ();
  place ("__declare_or_assign_str__");
  place (v);
  place ("__int_stack_mode__");
}
void
stringExpression ()
{
  place ("__str_stack_mode__");
  stringConcation ();
  if (checkNext ("="))
    {
      next ();
      next ();
      stringConcation ();
      place ("__str_compare__");
    }
  else if (checkNext ("in"))
    {
      next ();
      next ();
      stringConcation ();
      place ("__str_check_inside__");
    }
}
void
stringConcation ()
{
  stringIndex ();
  while (checkNext ("+"))
    {
      next ();
      next (); // |o| (o) <o> |-o-| (-o-) <-o-> --o-O-o--
      stringIndex ();
      place ("__str_concat__");
    }
}
void
stringIndex ()
{
  string ();
  if (checkNext ("-"))
    {
      next ();
      next ();
      place ("__int_stack_mode__");
      numeric ();
      next ();
      numeric ();
      place ("__str_index__");
      place ("__str_stack_mode__");
    }
}
void
string ()
{
  if (isSymbol (tokens[tokenIndex]) && checkNext ("("))
    {
      function ();
    }
  else if (isSymbol (tokens[tokenIndex]))
    {
      place (tokens[tokenIndex]);
    }
  else if (check ("input"))
    {
      place ("__str_user_input__");
    }
  else if (check ("'"))
    {
      next ();
      char s[W_MAX] = "\"";
      strcat (s, tokens[tokenIndex]);
      place (s);
      if (!checkNext ("'"))
        syntaxError ("expected end of string '''");
      next ();
    }
  else if (check ("("))
    {
      next ();
      place ("__int_stack_mode__");
      numeric ();
      next ();
      place ("__int_to_str_stack__");
      place ("__str_stack_mode__");
      if (!check (")"))
        syntaxError ("excpected end of numeric expression ')'");
    }
}
void
numeric ()
{
  /*weirdLogicGates();*/
  or_ ();
}
void
weirdLogicGates ()
{
  or_ ();
  while (checkNext ("xor") || checkNext ("nand") || checkNext ("xnor")
         || checkNext ("nor"))
    {
      char g[W_MAX] = "";
      strcpy (g, tokens[tokenIndex]);
      next ();
      next ();
      or_ ();
      place (g);
    }
}
void
or_ ()
{
  and_ ();
  while (checkNext ("or"))
    {
      next ();
      next ();
      and_ ();
      place ("+");
    }
}
void
and_ ()
{
  not_ ();
  while (checkNext ("and"))
    {
      next ();
      next ();
      not_ ();
      place ("*");
    }
}
void
not_ ()
{
  if (check ("not"))
    {
      next ();
      not_ ();
      place ("not");
    }
  else
    compare_ ();
}
void
compare_ ()
{
  mathExpression ();
  while (checkNext ("<") || checkNext (">") || checkNext ("="))
    {
      next ();
      if (check ("=") && checkNext ("="))
        {
          next ();
          next ();
        }
      else
        {
          char o[1];
          strcpy (o, tokens[tokenIndex]);
          next ();
          mathExpression ();
          if (o[0] == '=')
            place ("=");
          else
            place (o);
        }
    }
}
void
mathExpression ()
{
  term ();
  while (checkNext ("+") || checkNext ("-"))
    {
      next ();
      char o[1];
      strcpy (o, tokens[tokenIndex]);
      next ();
      term ();
      place (o);
    }
}
void
term ()
{
  factor ();
  while (checkNext ("*") || checkNext ("/"))
    {
      next ();
      char o[1];
      strcpy (o, tokens[tokenIndex]);
      next ();
      factor ();
      place (o);
    }
}
void
factor ()
{
  potens ();
  while (checkNext ("^"))
    {
      next ();
      next ();
      potens ();
      place ("^");
    }
}
void
potens ()
{
  if (check ("("))
    {
      next ();
      numeric ();
      next ();
      if (!check (")"))
        syntaxError ("expected end of expression ')'");
    }
  else if (isSymbol (tokens[tokenIndex]) && checkNext ("("))
    {
      place ("__str_stack_mode__");
      function ();
      place ("__int_to_str_stack__");
      place ("__int_stack_mode__");
    }
  else if (check ("-")
           && (isInteger (tokens[tokenIndex + 1])
               || isSymbol (tokens[tokenIndex + 1])))
    {
      next ();
      char s[W_MAX] = "-";
      strcpy (s, strcat (s, tokens[tokenIndex]));
      place (s);
    }
  else if (isInteger (tokens[tokenIndex]) || isSymbol (tokens[tokenIndex]))
    {
      place (tokens[tokenIndex]);
    }
  else if (check ("true"))
    place ("1");
  else if (check ("false"))
    place ("0");
  else if (check ("input"))
    place ("__int_user_input__");
  else if (isSymbol (tokens[tokenIndex]))
    place (tokens[tokenIndex]);

  else if (check ("["))
    { // string expression
      next ();
      stringExpression ();
      place ("__str_to_int_stack__");
      place ("__int_stack_mode__");
      next ();
      if (!check ("]"))
        syntaxError ("expected end of string-expression ']'");
    }

  else
    syntaxError ("expected value");
}

void
syntaxError (const char error[])
{
  printf ("%sSYNTAX ERROR (tokens[%d] = \"%s\"): %s%s\n", fg_red, tokenIndex,
          tokens[tokenIndex], error, style_reset);
  ERROR = true;
}

void
debug (char s[])
{
  if (DEBUG)
    printf ("%s", s);
}

bool
isSpecialChar (const char c)
{
  const char s[] = "åäö";
  for (int i = 0; i < strlen (s); i++)
    if (c == s[i])
      return true;
  return false;
}

void
lex (const char inp[], char x[L_MAX][W_MAX])
{
  int t = 0;
  int ti = 0;
  for (int i = 0; i < DATA_MAX && inp[i] != '\0'; i++)
    {
      char c = inp[i];
      if (isSpecialChar (c))
        x[t][ti] = c, ti++;
      else if (deadChar (c))
        {
          if (x[t][0] != '\0')
            t++;
          ti = 0;
        }
      else if (c == '\'')
        {
          if (x[t][0] != '\0')
            t++;
          x[t][0] = '\'';
          t++;
          ti = 0;
          for (i++; i < DATA_MAX && inp[i] != '\0' && inp[i] != '\''; i++, ti++)
            {
              if (inp[i] == '\\')
                {
                  i++;
                  if (inp[i] == 'n')
                    x[t][ti] = '\n';
                  else if (inp[i] == 't')
                    x[t][ti] = '\t';
                  else
                    goto cont;
                  goto skip;
                }
            cont:
              x[t][ti] = inp[i];
            skip:;
            }
          t++;
          x[t][0] = '\'';
          ti = 0;
          t++;
        }
      else if (c == '#' && inp[i + 1] == '#')
        {
          for (i++; i < DATA_MAX && inp[i] != '\0'
                    && !(inp[i] == '#' && inp[i + 1] == '#');
               i++)
            ;
          i++;
        }
      else if (c == '#')
        {
          for (i++; i < DATA_MAX && inp[i] != '\0' && inp[i] != '#'
                    && inp[i] != '\n';
               i++)
            ;
        }
      else if (divChar (c))
        {
          if (x[t][0] != '\0')
            t++;
          ti = 0;
          x[t][ti] = c;
          t++;
        }
      else
        x[t][ti] = c, ti++;
    }
}
bool
deadChar (char c)
{
  for (int i = 0; i < strlen (DEAD_CHARS); i++)
    {
      if (c == DEAD_CHARS[i])
        return true;
    }
  return false;
}
bool
divChar (char c)
{
  for (int i = 0; i < strlen (DIV_CHARS); i++)
    {
      if (c == DIV_CHARS[i])
        return true;
    }
  return false;
}
void
prompt (char esc, const char p[], char x[], int max)
{
  printf ("%s", p);
  if (esc != '\n')
    printf (" (enter='%c')", esc);
  printf ("> ");
  char r[max + 1];
  char c;
  char *pr = &r[0];
  int i;
  for (i = 0; (c = getchar ()) != esc && i < max; i++)
    x[i] = c;
  x[i] = '\0';
}

void
prompt_MEMORY (char esc, int promptY, int destinationY, int max)
{
  printString_MEMORY (promptY, 0);
  if (esc != '\n')
    printf (" (enter='%c')", esc);
  printf ("> ");
  char c;
  int i = 0;
  for (; (c = getchar ()) != esc && i < max; i++)
    putChar_MEMORY (destinationY, i, c);
  putChar_MEMORY (destinationY, i + 1, '\0');
}
// HEMMAGJORT MINNESSYSTEM + PEKARE
void
clear_MEMORY ()
{
  for (int i = 0; i < _MEMORY_X_SIZE_ * _MEMORY_Y_SIZE_; i++)
    CHAR_MEMORY[i] = '\0'
        //,INT_MEMORY[i]=0
        ;
}
void
debug_CHAR_MEMORY ()
{
  int mem = 0;
  for (int i = 0; i < _MEMORY_X_SIZE_ * _MEMORY_Y_SIZE_; i++)
    {
      printf ("CHAR_MEMORY[%d]:", i);
      if (i < 10)
        printf (" ");
      printf (" %c", CHAR_MEMORY[i]);
      if (i % _MEMORY_X_SIZE_ == 0)
        printf ("\t(%d)\n", mem), mem++;
      else
        printf ("\n");
    }
}
/*void debug_INT_MEMORY(){
    for(int i=0;i<_MEMORY_X_SIZE_*_MEMORY_Y_SIZE_;i++)
        printf("INT_MEMORY[%d]:\t\t%d\n",i,INT_MEMORY[i]);
}*/
char
getChar_MEMORY (int y, int x)
{
  return CHAR_MEMORY[y * _MEMORY_X_SIZE_ + x];
}
void
putChar_MEMORY (int y, int x, char c)
{
  CHAR_MEMORY[y * _MEMORY_X_SIZE_ + x] = c;
}
void
putString_MEMORY (int y, const char s[_MEMORY_X_SIZE_])
{
  int i = 0;
  for (; s[i] != '\0' && i < _MEMORY_X_SIZE_; i++)
    putChar_MEMORY (y, i, s[i]);
  for (; i < _MEMORY_X_SIZE_; i++)
    putChar_MEMORY (y, i, '\0');
}
int
putString_RandomAccess_MEMORY (const char s[_MEMORY_X_SIZE_])
{
  int i = 0;
  for (; i < _MEMORY_Y_SIZE_; i++)
    {
      if (getChar_MEMORY (i, 0) == '\0')
        break;
    }
  putString_MEMORY (i, s);
  return i;
}
int
find_RandomAccess_MEMORY (int n)
{
  int m = n;
  for (int l = 0; l < _MEMORY_Y_SIZE_; l++)
    {
      for (int i = l; 1; i++)
        { // printf("i:%d, m:%d, n:%d\n",i,m,n);
          if (getChar_MEMORY (i, 0) == '\0')
            {
              m--;
            }
          else
            {
              m = n;
              l = i; /*printf("f\n")*/
              ;
              break;
            }
          if (!m)
            return l;
          if (i == _MEMORY_Y_SIZE_ - 1)
            goto end;
        }
    }
end:
  error_S_SYSTEM ("memory capacity exeeded");
}
void
printChar_MEMORY (int y, int x)
{
  printf ("%c", getChar_MEMORY (y, x));
}
void
printString_MEMORY (int y, int endLine)
{
  for (int i = 0; getChar_MEMORY (y, i) != '\0' && i < _MEMORY_X_SIZE_; i++)
    printf ("%c", getChar_MEMORY (y, i));
  if (endLine)
    printf ("\n");
}
void
free_MEMORY (int y)
{
  for (int i = 0; i < _MEMORY_X_SIZE_ && getChar_MEMORY (y, i) != '\0'; i++)
    putChar_MEMORY (y, i, '\0');
}
// STRÄNG-MANIPULATIONSFUNKTIONER
void
concatStrings_PP_MEMORY (int a, int b, int del)
{
  int i = 0;
  for (; getChar_MEMORY (a, i) != '\0' && i < _MEMORY_X_SIZE_; i++)
    ;
  for (int i2 = 0; getChar_MEMORY (b, i2) != '\0' && i < _MEMORY_X_SIZE_;
       i++, i2++)
    putChar_MEMORY (a, i, getChar_MEMORY (b, i2));
  if (del)
    free_MEMORY (b);
}
void
concatStrings_PS_MEMORY (int a, char b[_MEMORY_X_SIZE_])
{
  int i = 0;
  for (; getChar_MEMORY (a, i) != '\0' && i < _MEMORY_X_SIZE_; i++)
    ;
  for (int i2 = 0; b[i2] != '\0' && i < _MEMORY_X_SIZE_; i++, i2++)
    putChar_MEMORY (a, i, b[i2]);
}

int
compareStrings_PP_MEMORY (int a, int b)
{
  for (int i = 0;
       i < _MEMORY_X_SIZE_
       && (getChar_MEMORY (a, i) != '\0' || getChar_MEMORY (b, i) != '\0');
       i++)
    if (getChar_MEMORY (a, i) != getChar_MEMORY (b, i))
      return 0;
  return 1;
}

int
compareStrings_PS_MEMORY (int a, char b[_MEMORY_X_SIZE_])
{
  for (int i = 0;
       i < _MEMORY_X_SIZE_ && (getChar_MEMORY (a, i) != '\0' || b[i] != '\0');
       i++)
    if (getChar_MEMORY (a, i) != b[i])
      return 0;
  return 1;
}

int
stringLength_MEMORY (int y)
{
  int i = 0;
  for (; getChar_MEMORY (y, i) != '\0' && i < _MEMORY_X_SIZE_; i++)
    ;
  return i;
}

void
copyString_MEMORY (int a, int b)
{
  free_MEMORY (b);
  for (int i = 0; i < _MEMORY_X_SIZE_ && getChar_MEMORY (a, i) != '\0'; i++)
    putChar_MEMORY (b, i, getChar_MEMORY (a, i));
}

// FUNKTIONER HANTERANDE STRÄNGLISTOR M.M.
int
createStringList_RandomAccess_MEMORY (int l)
{
  int p = find_RandomAccess_MEMORY (l + 1);
  for (int i = p; i < p + l; i++)
    putString_MEMORY (i, EMPTY_STRING_LIST);
  putString_MEMORY (p + l, END_OF_STRING_LIST);
  return p;
}

int
stringListLength_MEMORY (int y)
{
  int i = y;
  for (; !compareStrings_PS_MEMORY (i, END_OF_STRING_LIST); i++)
    {
      if (i == _MEMORY_Y_SIZE_ - 1)
        error_S_SYSTEM ("faulty list pointing pointer");
    }
  return i - y;
}

int
getStringInList_MEMORY (int l, int y)
{
  if (y > stringListLength_MEMORY (l))
    error_S_SYSTEM ("list index out of range");
  return l + y;
}

void
copyStringIntoList_MEMORY (int l, int y, int p)
{
  copyString_MEMORY (p, l + y);
}

void
copyStringFromList_MEMORY (int l, int y, int p)
{
  copyString_MEMORY (l + y, p);
}

void
putStringIntoList_MEMORY (int l, int y, char s[_MEMORY_X_SIZE_])
{
  putString_MEMORY (l + y, s);
}

int
appendCopyStringList_MEMORY (int l, int y)
{
  getStringInList_MEMORY (l, y);
  int i = y;
  for (; !compareStrings_PS_MEMORY (i, EMPTY_STRING_LIST); i++)
    ;
  if (compareStrings_PS_MEMORY (i, END_OF_STRING_LIST))
    error_S_SYSTEM ("list range exeeded");

  copyStringIntoList_MEMORY (l, i, y);
}

int
appendStringList_MEMORY (int l, char s[_MEMORY_X_SIZE_])
{
}

void
freeStringList_MEMORY (int y)
{
  for (int i = y; 1; i++)
    {
      // printf("i:%d - ",i);
      // printString_MEMORY(i,1);
      if (compareStrings_PS_MEMORY (i, END_OF_STRING_LIST))
        {
          free_MEMORY (i);
          return;
        }
      free_MEMORY (i);
      if (i == _MEMORY_Y_SIZE_ - 1)
        error_S_SYSTEM ("unknown");
    }
}

// SYSTEM
void
error_P_SYSTEM (int m)
{
  printf ("\n%s%s_SYSTEM_BEGIN_ {\"system "
          "alert\":{\"number\":%d,\"type\":\"error\",\"message\":\"",
          bg_red, fg_black, alert_number_SYSTEM);
  printString_MEMORY (m, 0);
  printf ("\"}} _SYSTEM_END_%s\n", style_reset);
  alert_number_SYSTEM++;

  exit (0);
}

void
error_S_SYSTEM (char m[])
{
  printf ("\n%s%s_SYSTEM_BEGIN_ {\"system "
          "alert\":{\"number\":%d,\"type\":\"error\",\"message\":\"%s\"}} "
          "_SYSTEM_END_%s\n",
          bg_red, fg_black, alert_number_SYSTEM, m, style_reset);
  alert_number_SYSTEM++;

  exit (0);
}
