%{
#include <stdio.h>
#include <string>
#include "bisoner.tab.h"
using namespace std;
%}

%%
"location"				return LOCATIONWORD;
"@l"					return LTOKEN;
"@g"[0-9]+ 					printf("group");
"#"[a-zA-Z0-9.-_=]+			printf("comment ignored\n");
[0-9]+						yylval.number=atoi(yytext);return INTEGER;
[a-zA-Z]+					yylval.str=new string(yytext);return WORD;

%%

