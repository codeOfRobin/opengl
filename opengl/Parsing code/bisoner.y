%{
#include <stdio.h>
#include <string>
using namespace std;
extern int yylex();
extern void yyerror(char*);
void yyerror(const char *str)
{
        fprintf(stderr,"error: %s\n",str);
}
 


%}
%token LTOKEN INTEGER LOCATIONWORD WORD
 %option noyywrap

%union{
  std::string *str;
  int number;
}
%token <number> INTEGER
%token <str> WORD

%%
location_set:
			LOCATIONWORD LTOKEN INTEGER WORD
			{
			printf("%d  %s",$3,$4	);
			}

%%


int yywrap()
{
        return 1;
} 
  
int main()
{
        yyparse();
        return 1;
} 