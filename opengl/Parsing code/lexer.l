%{
#include <stdio.h>
#include "bisoner.tab.h"
%}

%%
"location"				return LOCATIONWORD;
"@l"					return LTOKEN;
"@g"[0-9]+ 					printf("group");
"#"[a-zA-Z0-9.-_=]+			printf("comment ignored\n");
[0-9]+						yylval.number=atoi(yytext);return INTEGER;
[a-zA-Z]+					yylval=strdup(yytext);return WORD;

%%

