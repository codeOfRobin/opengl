%{
#include <stdio.h>
#include <string.h>
 
void yyerror(const char *str)
{
        fprintf(stderr,"error: %s\n",str);
}
 
int yywrap()
{
        return 1;
} 
  
main()
{
        yyparse();

} 

%}

%token LOCATIONNUMBER GROUPNUMBER CURRENCYTOKEN STARTINGMONEYTOKEN JAILFINETOKEN TAXTOKEN LOCATIONTOKEN ATSIGNTOKEN INTEGER WORD ROUTETOKEN COSTTOKEN RENTTOKEN

%%
location_set:
			LOCATIONTOKEN LOCATIONNUMBER WORD GROUPNUMBER
			{
				printf("location %s",$3);
			}
at_sign	:
			LOCATIONTOKEN
			{
				printf("dascl\n");
			}

%%