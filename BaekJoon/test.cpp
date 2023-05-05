#pragma warning(disable : 4996)
#include<iostream>
#include<fstream>
#include <string>
using namespace std;
int charClass;
string lexeme;
char nextChar;
int nextToken;
ifstream in_fp;
void addChar();
void getChar();
void getNonBlank();
void checkKeyWord();
int lex();
enum Token
{
	LETTER = 0,
	DIGIT = 1,
	UNKNOWN = 99,

	INT_LIT = 10,
	IDENT = 11,
	ASSIGN_OP = 20,
	ADD_OP = 21,
	SUB_OP = 22,
	MULT_OP = 23,
	DIV_OP = 24,
	LEFT_PAREN = 25,
	RIGHT_PAREN = 26,

	FOR_CODE = 30,
	IF_CODE = 31,
	ELSE_CODE = 32,
	WHILE_CODE = 33,
	DO_CODE = 34,
	INT_CODE = 35,
	FLOAT_CODE = 36,
	SWITCH_CODE = 37
};
int main()
{
	in_fp.open("front.in");
	if (!in_fp.is_open())
	{
		printf("ERROR - cannot open front.in\n");
	}
	else
	{
		getChar();
		do
		{
			lex();
		} while (nextToken != EOF);
	}
}
int lookup(const char ch)
{
	switch (ch)
	{
	case '(':
		addChar();
		nextToken = LEFT_PAREN;
		break;
	case ')':
		addChar();
		nextToken = RIGHT_PAREN;
		break;
	case '+':
		addChar();
		nextToken = ADD_OP;
		break;
	case '-':
		addChar();
		nextToken = SUB_OP;
		break;
	case '*':
		addChar();
		nextToken = MULT_OP;
		break;
	case '/':
		addChar();
		nextToken = DIV_OP;
		break;
	default:
		addChar();
		nextToken = EOF;
	}
	return nextToken;
}
void addChar()
{
	if (lexeme.length() <= 98)
	{
		lexeme.push_back(nextChar);
	}
	else
	{
		printf("Error - lexeme is too long\n");
	}
}
void getChar()
{
	if ((nextChar = static_cast<char>(in_fp.get())) != EOF)
	{
		if (isalpha(nextChar))
		{
			charClass = LETTER;
		}
		else if (isdigit(nextChar))
		{
			charClass = DIGIT;
		}
		else
		{
			charClass = UNKNOWN;
		}
	}
	else
	{
		charClass = EOF;
	}
}
void getNonBlank()
{
	while (isspace(nextChar))
	{
		getChar();
	}
}

void checkKeyWord()
{
	if(lexeme == "for")
	{
		nextToken = FOR_CODE;
	}
	else if(lexeme=="if")
	{
		nextToken = IF_CODE;
	}
	else if (lexeme == "else")
	{
		nextToken = ELSE_CODE;
	}
	else if (lexeme == "while")
	{
		nextToken = WHILE_CODE;
	}
	else if (lexeme == "do")
	{
		nextToken = DO_CODE;
	}
	else if (lexeme == "float")
	{
		nextToken = FLOAT_CODE;
	}
	else if (lexeme == "switch")
	{
		nextToken = SWITCH_CODE;
	}

}

int lex()
{
	lexeme = "";
	getNonBlank();
	switch (charClass)
	{
	case LETTER:
		addChar();
		getChar();
		while (charClass == LETTER || charClass == DIGIT)
		{
			addChar();
			getChar();
		}
		nextToken = IDENT;
		checkKeyWord();
		break;
	case DIGIT:
		addChar();
		getChar();
		while (charClass == DIGIT)
		{
			addChar();
			getChar();
		}
		nextToken = INT_LIT;
		break;
	case UNKNOWN:
		lookup(nextChar);
		getChar();
		break;
	case EOF:
		nextToken = EOF;
		lexeme = "EOF";
		break;
	}
	printf("Next token is : %d, Next lexeme is %s\n", nextToken, lexeme.c_str());
	return nextToken;
}