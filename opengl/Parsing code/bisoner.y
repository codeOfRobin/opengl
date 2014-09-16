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
%token LTOKEN INTEGER LOCATIONWORD WORD GTOKEN CURRENCYTOKEN JAILFINETOKEN STARTINGMONEYTOKEN RTOKEN

%union{
  std::string *str;
  int number;
}
%token <number> INTEGER
%token <str> WORD

%%
commands: /* empty */
        | command commands
        ;

command:
        currency_set
        |
        location_set
        |
        startingMoney_set
        |
        jailFine_set
        |
        route_add
        ;

currency_set:CURRENCYTOKEN WORD
			{
				printf("Currency set to %s",$2);
			}
			
location_set:
			LOCATIONWORD LTOKEN INTEGER WORD GTOKEN INTEGER
			{
			printf("location number %d  set to  %s in froup number %d",$3,$4,$6);
			}
startingMoney_set:
            STARTINGMONEYTOKEN INTEGER
            {
            printf("starting money set to %d \n",$2 );
            }
jailFine_set:
            JAILFINETOKEN INTEGER
            {
                printf("jailfine set to %d\n",$2);
            }

route_add:
            RTOKEN LTOKEN INTEGER LTOKEN INTEGER
            {
                printf("Route set up between location no %d and %d\n",$3,$5);
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