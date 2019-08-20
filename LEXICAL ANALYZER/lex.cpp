#include<bits/stdc++.h>

using namespace std;

FILE *yyin;
char *yytext;
int token = -200;
int yylen;

map<string,string> STR;

bool is_alphanumeric(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    if (c >= 'a' && c <= 'z')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;

    return false;
}

void yylex()
{
  char c;
  while (true)
  {
      c = fgetc(yyin);
      if (c == EOF)
      {
          yylen = 0;
          yytext[0] = '\0';
          token = -1;
      }
      if (c != ' ' && c != '\n')
          break;
  }
  string tmp = "";
  switch (c)
  {
  case '{': case '}': case '(': case ')': case ';' :case '#': case '[': case ']': case ':':case '\"':case ',':case '%':case '\'':case '!':
        yylen = 1;
        yytext[0] = c;
        return;

  case '|':
      c = fgetc(yyin);
      if (c == '|')
      {
          yylen = 2;
          strcpy(yytext, "||");
          return;
      }
      else
      {
          yylen = 1;
          strcpy(yytext, "|");
          fseek(yyin, -1, SEEK_CUR);
          return;
      }

  case '&':
      c = fgetc(yyin);
      if (c == '&')
      {
          yylen = 2;
          strcpy(yytext, "&&");
          return;
      }
      else
      {
          yylen = 1;
          strcpy(yytext, "&");
          fseek(yyin, -1, SEEK_CUR);
          return;
      }
  case '<':
      c = fgetc(yyin);
      if (c == '=')
      {
          strcpy(yytext, "<=");
          yylen = 2;
          return;
      }
      else
      {
          fseek(yyin, -1, SEEK_CUR);
          yylen = 1;
          strcpy(yytext, "<");
          return;
      }
  case '>':
      c = fgetc(yyin);
      if (c == '=')
      {
          strcpy(yytext, ">=");
          yylen = 2;
          return;
      }
      else
      {
          fseek(yyin, -1, SEEK_CUR);
          yylen = 1;
          strcpy(yytext, ">");
          return;
      }
  case '=':
      c = fgetc(yyin);
      if (c == '=')
      {
          strcpy(yytext, "==");
          yylen = 2;
          return;
      }
      else
      {
          fseek(yyin, -1, SEEK_CUR);
          yylen = 1;
          strcpy(yytext, "=");
          return;
      }
  case '+':
      c = fgetc(yyin);
      if (c == '=')
      {
          strcpy(yytext, "+=");
          yylen = 2;
          return;
      }
      if (c == '+')
      {
          strcpy(yytext, "++");
          yylen = 2;
          return;
      }
      else
      {
          fseek(yyin, -1, SEEK_CUR);
          yylen = 1;
          strcpy(yytext, "+");
          return;
      }
  case '-':
      c = fgetc(yyin);
      if (c == '=')
      {
          strcpy(yytext, "-=");
          yylen = 2;
          return;
      }
      if (c == '-')
      {
          strcpy(yytext, "--");
          yylen = 2;
          return;
      }
      if (c >= '0' && c <= '9')
      {
          tmp = "-";
          while (c >= '0' && c <= '9')
          {
              tmp += c;
              c = fgetc(yyin);
          }
          fseek(yyin, -1, SEEK_CUR);

          strcpy(yytext, tmp.c_str());
          yylen = tmp.size();
          return;
      }
      else
      {
          fseek(yyin, -1, SEEK_CUR);
          yylen = 1;
          strcpy(yytext, "-");
          return;
      }

  case '*':
      c = fgetc(yyin);
      if (c == '=')
      {
          strcpy(yytext, "*=");
          yylen = 2;
          return;
      }
      else
      {
          fseek(yyin, -1, SEEK_CUR);
          yylen = 1;
          strcpy(yytext, "*");
          return;
      }

  case '/':
      c = fgetc(yyin);
      if (c == '=')
      {
          strcpy(yytext, "/=");
          yylen = 2;
          return;
      }
      else
      {
          fseek(yyin, -1, SEEK_CUR);
          yylen = 1;
          strcpy(yytext, "/");
          return;
      }

  default:
      if (c >= '0' && c <= '9')
      {
          while (c >= '0' && c <= '9')
          {
              tmp += c;
              c = fgetc(yyin);
          }
          fseek(yyin, -1, SEEK_CUR);
          strcpy(yytext, tmp.c_str());
          yylen = tmp.size();
          token = 1;
          return;
      }
      else if (is_alphanumeric(c) || (c == '_'))
      {
          tmp = "";
          while (is_alphanumeric(c) || (c == '_'))
          {
              tmp += c;
              c = fgetc(yyin);
          }
          fseek(yyin, -1, SEEK_CUR);
          strcpy(yytext, tmp.c_str());
          return;
      }
      else
      {
          yylen = 1;
          yytext[0] = '\0';
          yylen = 1;
          cout<<"NEW LINE";
          return;
      }
  }
}


int main(int argc,char **argv)
{

STR.insert(pair<string,string>("(","LPAREN_TOK (SYMBOL)"));
STR.insert(pair<string,string>(")","RPAREN_TOK (SYMBOL)"));
STR.insert(pair<string,string>("{","LCURL_TOK (SYMBOL)"));
STR.insert(pair<string,string>("}","RCURL_TOK (SYMBOL)"));
STR.insert(pair<string,string>("+","ADD_TOK (SYMBOL)"));
STR.insert(pair<string,string>("-","MINUS_TOK (SYMBOL)"));
STR.insert(pair<string,string>("*","MULT_TOK (SYMBOL)"));
STR.insert(pair<string,string>("/","DIVIDE_TOK (SYMBOL)"));
STR.insert(pair<string,string>("=","ASSIGNMENT_TOK (SYMBOL)"));
STR.insert(pair<string,string>("!","NOT_TOK (SYMBOL)"));
STR.insert(pair<string,string>(",","COMMA_TOK (SYMBOL)"));
STR.insert(pair<string,string>(";","SEMICOLON_TOK (SYMBOL)"));
STR.insert(pair<string,string>(">","LESSER_TOK (SYMBOL)"));
STR.insert(pair<string,string>("<","GREATER_TOK (SYMBOL)"));
STR.insert(pair<string,string>("]","RSQBRAC_TOK (SYMBOL)"));
STR.insert(pair<string,string>("[","LSQRBRAC_TOK (SYMBOL)"));
STR.insert(pair<string,string>("==","EQUALITY_TOK (SYMBOL)"));
STR.insert(pair<string,string>("!=","NOTEQUAL_TOK (SYMBOL)"));
STR.insert(pair<string,string>("<=","LESSOREQUAL_TOK (SYMBOL)"));
STR.insert(pair<string,string>(">=","GREATEROREQUAL_TOK (SYMBOL)"));
STR.insert(pair<string,string>("++","INCREMENT_TOK (SYMBOL)"));
STR.insert(pair<string,string>("--","DECREMENT_TOK (SYMBOL)"));
STR.insert(pair<string,string>("&&","AND_TOK (SYMBOL)"));
STR.insert(pair<string,string>("||","OR_TOK (SYMBOL)"));
STR.insert(pair<string,string>("for","FOR_TOK (RESERVED KEYWORD)"));
STR.insert(pair<string,string>("while","WHILE_TOK (RESERVED KEYWORD)"));
STR.insert(pair<string,string>("switch","SWITCH_TOK (RESERVED KEYWORD)"));
STR.insert(pair<string,string>("case","CASE_TOK (RESERVED KEYWORD)"));
STR.insert(pair<string,string>("if","IF_TOK (RESERVED KEYWORD)"));
STR.insert(pair<string,string>("else","ELSE_TOK (RESERVED KEYWORD)"));
STR.insert(pair<string,string>("int","INT_TOK (RESERVED KEYWORD)"));
STR.insert(pair<string,string>("float","FLOAT_TOK (RESERVED KEYWORD)"));
STR.insert(pair<string,string>("char","CHAR_TOK (RESERVED KEYWORD)"));

  if(argc<2)
  {
    cout<<"INVALID INPUT"<<endl;
  }

  else
  {
    yytext = new char[100];
    yyin = fopen(argv[1], "r");
    while(!feof(yyin))
    {

      yylex();
      int len = strlen(yytext);

      string str(yytext);
      bool t = STR.count(str);
      if(t)
      {
        cout<<yytext<<" --> "<<STR.find(str)->second<<endl;
      }
      else
      {
        if(token == 1)
        {

            token = -200;
        }
        else if (strcmp(str.c_str(),"\0")==0)
        {
          cout<<" ------------------------ NEW LINE"<<endl;
        }
        else
        {
            int m = atoi(yytext);
            if(m>INT_MIN && m<0)
                cout<<yytext<<" --> "<<"INT_CONST_TOK"<<endl;
            else
                cout<<yytext<<" --> "<<"INDENTIFIER"<<endl;
        }
      }

      memset(yytext, 0, sizeof(*yytext) * len);

  	}
    fclose(yyin);
  }

}
