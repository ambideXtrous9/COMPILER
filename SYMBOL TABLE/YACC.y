%{
#include"lex.yy.c"
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void yyerror(const char *);
int scope=0;
int ind1,ind2;

int check;

string s;
string val;

string tempo1;
string tempo2;


typedef struct Head
{
    string vname;
    string dtype;
    int Scope;
}head;


typedef struct Data
{
    string vname;
    int Scope;
}data;

data D;

vector<head> V[5];

void addNode(vector<head> V[],data H,string S)
{
    int u = H.vname[0];
    int t = u%5;
    head v;
    v.vname = H.vname;
    v.dtype = S;
    v.Scope = H.Scope;

    V[t].push_back(v);
    cout<<" ADDED"<<endl;
}

void display(vector<head> V[])
{

    cout<<"-------------------------SYMBOL TABLE-------------------"<<endl;
    cout<<"----------------------------------------------------------"<<endl;

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            cout<<" | "<<V[i][j].vname<<"-"<<V[i][j].Scope<<"-"<<V[i][j].dtype<<" | ";
            cout<<"-->";
        }
        cout<<endl;
    }
}

int search(vector<head> V[],data d)
{
    int u = d.vname[0];
    int t = u%5;
    int n = V[t].size();
    int i = 0;
    while(i<n)
    {
        if(V[t][i].vname==d.vname && V[t][i].Scope==d.Scope)
        {
            cout<<"Error: Same variable already present in current scope"<<endl;
            return 0;
        }
        i++;
    }

    return 1;
}

string search2(vector<head> V[],string vname)
{
    int u = vname[0];
    int t = u%5;
    string ss="miss";
    int n = V[t].size();
    int i = 0;
    while(i<n)
    {
        if(V[t][i].vname == vname)
        {
            return V[t][i].dtype;
        }
        
        i++;
    }

    return ss;
}

%}


%token LEFT_PAR
%token RIGHT_PAR
%token LEFT_BRACE
%token RIGHT_BRACE
%token GREATER
%token GREATER_EQ
%token LESS
%token LESS_EQ
%token SEMI_COL
%token PLUS
%token MINUS
%token MUL
%token DIV
%token BIT_OR
%token BIT_AND
%token BIT_XOR
%token OR
%token AND
%token INT_TOK
%token FLOAT_TOK
%token CHAR_TOK
%token RES_TOK
%token IDENTIFIER
%token NUMBER_TOK
%token DEC
%token DCR
%token INCR
%token MAIN_TOK
%token SPACE
%token COMMA_TOK
%token IF_TOK
%token ELSE_TOK
%token WHILE_TOK
%token FOR_TOK
%token ASSIGN
%token RELATION_TOK
%start S

%%


S :  datatype MAIN_TOK LEFT_PAR RIGHT_PAR BLOCK        {cout<<"MAIN FUNCTION"<<endl;}
      | FUNCTION_DEF S
      | global S
     ;
global: DECLARATION  SEMI_COL                         {cout<<"GLOBAL DECLARATION"<<endl;}
      ;
BLOCK: LEFT_BRACE {scope = scope+1;cout<<"Scope = "<<scope<<endl;} STATEMENTS  BLOCKS  RIGHT_BRACE     {scope = scope-1; cout<<"Scope = "<<scope<<endl;}
     ;

BLOCKS: BLOCK STATEMENTS BLOCKS                                {}
      |
      ;

STATEMENTS:STATEMENTS  stmt
          |
          ;

stmt      :DECLARATION  SEMI_COL    {cout<<"LOCAL DECLARATION"<<endl;}
          |If                       {cout<<"CONDITIONAL (IF) STATEMENT"<<endl;}
          |ELSE                     {cout<<"CONDITIONAL (ELSE) STATEMENT"<<endl;}
          |WHILE                    {cout<<"ITERATIVE (WHILE) STATEMENT"<<endl;}
          |FOR                      {cout<<"ITERATIVE (FOR) STATEMENT"<<endl;}
          |FUNCTION_CALL            {cout<<"FUNCTION CALL"<<endl;}
          |ASSINGMENT               {cout<<"ASSIGNMENT OPERATION"<<endl;}
          |ARITHMETIC               {cout<<"ARITHMETIC OPERATION"<<endl;}
          ;


DECLARATION:datatype id_token {cout<<s<<endl;}
           ;
ASSINGMENT: DECLARATION ASSIGN VALUE SEMI_COL {if(s!=val){cout<<"TYPE MISMATCH ERROR-1...!"<<endl;exit(1);}}  
     
          | DECLARATION ASSIGN IDENTIFIER SEMI_COL {string vnam = flag;string temp = search2(V,vnam); if(temp=="miss"){cout<<"VARIABLE NOT DECLARED...!"<<endl;exit(1);}    else if(s!=temp){cout<<"TYPE MISMATCH ERROR-2...!"<<endl;exit(1);} }  

          | IDENTIFIER ASSIGN IDENTIFIER SEMI_COL     

          | IDENTIFIER ASSIGN VALUE SEMI_COL   {string vnam = flag;string temp = search2(V,vnam); if(temp=="miss"){cout<<"VARIABLE NOT DECLARED...!"<<endl;exit(1);}    else if(val!=temp){cout<<"TYPE MISMATCH ERROR-4...!"<<endl;exit(1);} }  
   
          | IDENTIFIER ASSIGN ARITHMETIC            {printf("Arithmetic\n");}
          ;


VALUE: NUMBER_TOK   {val = "int";}
      |DEC          {val = "float";}
      ;  

datatype: INT_TOK       {s = "int";}
        | FLOAT_TOK     {s = "float";}
        | CHAR_TOK      {s = "char";}
        ;

id_token: id_token COMMA_TOK IDENTIFIER      { cout<<flag ; D.vname = flag; D.Scope=scope; check = search(V,D);if(check){addNode(V,D,s);}else{exit(1);}}
        | IDENTIFIER                         { cout<<flag ; D.vname = flag; D.Scope=scope; check = search(V,D);if(check){addNode(V,D,s);}else{exit(1);}}

        ;

        ELSE : ELSE_TOK If
              | ELSE_TOK BLOCK
              ;


If : IF_TOK LEFT_PAR x RIGHT_PAR BLOCK
      ;


WHILE : WHILE_TOK LEFT_PAR x RIGHT_PAR BLOCK
      ;

FOR : FOR_TOK LEFT_PAR z RIGHT_PAR BLOCK
    ;

z: z1 SEMI_COL z2 SEMI_COL z3
  ;

z1 : IDENTIFIER ASSIGN NUMBER_TOK
  ;
z2 : IDENTIFIER LESS_EQ NUMBER_TOK
  ;
z3 : IDENTIFIER INCR
    | IDENTIFIER DCR
  ;

x: IDENTIFIER y NUMBER_TOK
    | IDENTIFIER y IDENTIFIER
    |IDENTIFIER
    ;
y: GREATER
  | GREATER_EQ
  | LESS
  | LESS_EQ
  | RELATION_TOK
  ;

FUNCTION_CALL: IDENTIFIER LEFT_PAR actual_parameter RIGHT_PAR SEMI_COL
        ;

actual_parameter: IDENTIFIER
          | IDENTIFIER COMMA_TOK actual_parameter
          ;
FUNCTION_DEF: datatype IDENTIFIER LEFT_PAR formal_parameter RIGHT_PAR BLOCK  {cout<<"FUNCTION DEFINITION"<<endl;}
            ;

formal_parameter :  datatype IDENTIFIER COMMA_TOK formal_parameter  {}
                  | datatype IDENTIFIER
                  | SPACE
                  ;

ARITHMETIC : IDENTIFIER OPS ARITHMETIC
          | VALUE OPS ARITHMETIC
          | IDENTIFIER OPS IDENTIFIER SEMI_COL     
          | IDENTIFIER OPS VALUE SEMI_COL
          | VALUE OPS IDENTIFIER SEMI_COL
          | VALUE OPS VALUE SEMI_COL
          ;
OPS: PLUS
    |MINUS
    |MUL
    |DIV
    ;
%%

int main()
{
   
   if (yyparse()==0)
   {
         
        
        display(V);

    cout<<endl<<"SUCCESSFULLY PARSED...OK"<<endl;

   
   }
   else cout<<"PARSING ERROR AT LINE NO = "<<yylineno<<endl;

   return(0);

}

void yyerror(const char *s)
{
	cout<<"yyerror:"<<s<<endl;
}
