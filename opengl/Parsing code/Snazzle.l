%{
    #include <iostream>
    using namespace std;
    #define YY_DECL extern "C" int yylex()
%}
%%
[/t /n]		;
[0-9]+\.[0-9]+		{cout<<"float"<<endl;}
[0-9]+		{cout<<"integers"<<endl;}
[a-z A-Z 0-9]*	{cout<<"Old fashioned something"<<endl;}
%%
int main()
{
    FILE *myFile=fopen("a.snazzle.file","r");
    if(!myFile)
    {
        cout<<"a.snazzle.file File not openable";
        return -1;
        
    }
    else
    {
        yyin=myFile;
    
    }
	yylex();
	return 1;
}
