%{
#include <stdio.h>
%}

%%
"#"[a-zA-Z0-9.-_=]+			printf("comment ignored\n");
"Currency" 					return CURRENCYTOKEN;
"STartingMoney"				return STARTINGMONEYTOKEN;
"JailFine"					return JAILFINETOKEN;
"Tax"						return TAXTOKEN;
"location"					return LOCATIONTOKEN;
"@"							return ATSIGNTOKEN;
[0-9][0-9]* 				return INTEGER;
[a-zA-Z0-9.-_=]+			return WORD;
"route"						return ROUTETOKEN;
"@l"[0-9][0-9]*				return LOCATIONNUMBER;
"@g"[0-9][0-9]* 			return GROUPNUMBER;
"cost"						return COSTTOKEN;
"rent"						return RENTTOKEN;

%%

