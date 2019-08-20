#include<bits/stdc++.h>

using namespace std;

vector<char> S; //stack
map<char,map<char,string>> table; //production rule table


void print_stack()
{
	for(int i=0;i<S.size();i++)
	{
		cout<<S[i];
	}
}

void print_ip_str(string a, int x)
{
	cout<<"\t";
	for(int i=x;a[i] != '\0';i++)
	{
		cout<<a[i];
	}
}

int main()
{
	string input;
	char curr_sym,s_top;
	char r,c;

	/*
	{          i   	 +     *     (      )    $

		E	  "TA", "$" , "$" , "TA" , "$", "$",

		A	  "$" ,"+TA", "$" , "$"  , "e", "e",

		T 	  "FB", "$" , "$" , "FB" , "$", "$",

		B	  "$" , "e" ,"*FB", "$"  , "e", "e",

		F 	  "i" , "$" , "$" , "(E)", "$", "$"
	}
	*/

	table['E']['i'] = "TA";
	table['E']['+'] = "$";
	table['E']['*'] = "$";
	table['E']['('] = "TA";
	table['E'][')'] = "$";
	table['E']['$'] = "$";

	table['A']['i'] = "$";
	table['A']['+'] = "+TA";
	table['A']['*'] = "$";
	table['A']['('] = "$";
	table['A'][')'] = "e";
	table['A']['$'] = "e";

	table['T']['i'] = "FB";
	table['T']['+'] = "$";
	table['T']['*'] = "$";
	table['T']['('] = "FB";
	table['T'][')'] = "$";
	table['T']['$'] = "$";

	table['B']['i'] = "$";
	table['B']['+'] = "e";
	table['B']['*'] = "*FB";
	table['B']['('] = "$";
	table['B'][')'] = "e";
	table['B']['$'] = "e";

	table['F']['i'] = "i";
	table['F']['+'] = "$";
	table['F']['*'] = "$";
	table['F']['('] = "(E)";
	table['F'][')'] = "$";
	table['F']['$'] = "$";



	cout<<"ENTER THE INPUT STRING : ";
	cin>>input;
	input.push_back('$');

    cout<<endl;
	cout<<"TABLE DRIVEN NON-RECURSIVE PREDICTIVE PARSER"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<endl;

	cout<<"STACK\tBUFFER\tACTION"<<endl;
	cout<<"=====\t=====\t======"<<endl;

	S.push_back('$');
    S.push_back('E');
  	print_stack();

	cout<<"\t"<<input<<"\t"<<"~"<<endl;

	int k = 0;

	while(input[k] != '\0')
    {
		if(S.back() == curr_sym)
        {
		    S.pop_back();
		    print_stack();
		    print_ip_str(input,k+1);
		    cout<<"\tPOP"<<endl;
	  	    k++;
    	}

    	curr_sym = input[k];
		s_top = S.back();

		if(s_top == 'E')
			r = 'E';
		else if(s_top == 'A')
			r = 'A';
		else if(s_top == 'T')
			r = 'T';
		else if(s_top == 'B')
			r = 'B';
		else if(s_top == 'F')
			r = 'F';
		else
		{
			cout<<"SYNTAX ERROR"<<endl;
			break;
		}

		if(curr_sym >= 'a' && curr_sym <='z')
		{
	        c = 'i';
	        curr_sym ='i';
	    }

	    else if(curr_sym >= 'A' && curr_sym <= 'Z')
		{
	    	cout<<"THERE IS A NON-TERMINAL"<<curr_sym<<endl;
	    	break;
	    }
		else if(curr_sym == '+')
			c = '+';
		else if(curr_sym == '*')
			c = '*';
		else if(curr_sym == '(')
			c = '(';
		else if(curr_sym == ')')
			c = ')';
		else if(curr_sym == '$')
			c = '$';

        int len = table[r][c].length();
        string st;

		st = table[r][c];

        reverse(st.begin(),st.end());

        S.pop_back();

        for(int i=0;i<len;i++)
		      S.push_back(st[i]);

		st.clear();

		if(S.back() == 'e')
        {
		    S.pop_back();
		    print_stack();
		    print_ip_str(input,k);
		    cout<<"\t"<<s_top<<"->"<<"e"<<endl;
	    }

        else
        {
	    	print_stack();
	      	print_ip_str(input,k);
	      	cout<<"\t"<<s_top<<"->"<<table[r][c]<<endl;
	    }

	    if(S.back() == '$' && curr_sym =='$')
	      	break;
	    if(S.back() == '$')
        {
			cout<<"SYNTAX ERROR"<<endl;
			break;
		}
	}

    string str(S.begin(),S.end());
	cout<<endl;

    if(strcmp(str.c_str(),"$")==0)
    	cout<<"CORRECT SYNTAX => STRING IS ACCEPTED"<<endl;
    else
    	cout<<"ERROR! STRING IS REJECTED"<<endl;

	return 0;
}
