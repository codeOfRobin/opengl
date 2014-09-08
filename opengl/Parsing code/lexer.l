%{
#include <stdio.h>
%}

%%
[\w]+					printf("my mom's a bitch");	
[0123456789]+           printf("NUMBER\n");
[a-zA-Z][a-zA-Z0-9]*    printf("WORD\n");
%%

