%{
#include <stdio.h>
#include <string>
#include "bisoner.tab.h"
using namespace std;
%}

%%
"route"						return RTOKEN;
"Currency"					return CURRENCYTOKEN;
"StartingMoney"				return STARTINGMONEYTOKEN;
"JailFine"					return JAILFINETOKEN;
"location"					return LOCATIONWORD;
"@l"						return LTOKEN;
"@g" 						return GTOKEN;
"#"[a-zA-Z0-9.-_=]+			printf("comment ignored\n");
[0-9]+						yylval.number=atoi(yytext);return INTEGER;
[a-zA-Z]+					yylval.str=new string(yytext);return WORD;

%%

