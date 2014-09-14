%{
#include <stdio.h>
#include <string.h>
 
void yyerror(const char *str)
{
        fprintf(stderr,"error: %s\n",str);
}
 


%}
%token LTOKEN INTEGER LOCATIONWORD WORD

%union{
  char *str;
  int number;
}
%token <number> INTEGER
%token <string> WORD

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
  
main()
{
        yyparse();

} 