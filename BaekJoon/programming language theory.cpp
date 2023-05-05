#pragma warning(disable : 4996)
#include<cstdio>
#include<cctype>
int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE* in_fp, * fopen();
void addChar();
void getChar();
void getNonBlank();
int lex();

#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

#define FOR_CODE 30
#define IF_CODE 31
#define ELSE_CODE 32
#define WHILE_OCDE 33
#define DO_CODE 34
#define INT_CODE 35
#define FLOAT_CODE 36
#define SWITCH_CODE 37
int main()
{
	if ((in_fp = fopen("front.in", "r")) == nullptr)
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
	if (lexLen <= 98)
	{
		lexeme[lexLen++] = nextChar;
		lexeme[lexLen] = 0;
	}
	else
	{
		printf("Error - lexeme is too long\n");
	}
}
void getChar()
{
	if ((nextChar = getc(in_fp)) != EOF)
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
int lex()
{
	lexLen = 0;
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
		lexeme[0] = 'E';
		lexeme[1] = 'O';
		lexeme[2] = 'F';
		lexeme[3] = '\0';
		break;
	}
	printf("Next token is : %d, Next lexeme is %s\n", nextToken, lexeme);
	return nextToken;
}



//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// ��ū ����
//enum Token {
//    // �����
//    FOR, IF, ELSE, WHILE, DO, INT, FLOAT, SWITCH,
//    // �ĺ���
//    IDENTIFIER,
//    // ����
//    NUMBER,
//    // ������
//    PLUS, MINUS, MULTIPLY, DIVIDE,
//    // ��ȣ
//    LEFT_PAREN, RIGHT_PAREN,
//    // �����ݷ�
//    SEMICOLON,
//    // ������ ��
//    END_OF_FILE
//};
//
//// ����� ����
//const string keywords[] = {
//    "for", "if", "else", "while", "do", "int", "float", "switch"
//};
//
//// ��ū Ÿ�԰� ������ ��� �Լ�
//void print_token(Token token, string lexeme) {
//    cout << "Next token is: " << token << ", Next lexeme is: " << lexeme << endl;
//}
//
//int main() {
//    // �Է� ���� ��
//    string input;
//    cout << "���� �Է��ϼ���: ";
//    getline(cin, input);
//
//    // ���� �м����� ��ġ
//    int pos = 0;
//
//    // �Է¹��� ���� �м�
//    while (pos < input.size()) {
//        if (isdigit(input[pos])) {
//            // ����
//            string number = "";
//            while (pos < input.size() && isdigit(input[pos])) {
//                number += input[pos];
//                ++pos;
//            }
//            print_token(NUMBER, number);
//        }
//        else if (isalpha(input[pos])) {
//            // �ĺ��� �Ǵ� �����
//            string identifier = "";
//            while (pos < input.size() && (isalnum(input[pos]) || input[pos] == '_')) {
//                identifier += input[pos];
//                ++pos;
//            }
//
//            // ����� ����
//            bool is_keyword = false;
//            for (int i = 0; i < 8; ++i) {
//                if (keywords[i] == identifier) {
//                    print_token((Token)(i + 1), identifier);
//                    is_keyword = true;
//                    break;
//                }
//            }
//
//            if (!is_keyword) {
//                // �ĺ���
//                print_token(IDENTIFIER, identifier);
//            }
//        }
//        else if (input[pos] == '+') {
//            // ���ϱ� ������
//            print_token(PLUS, "+");
//            ++pos;
//        }
//        else if (input[pos] == '-') {
//            // ���� ������
//            print_token(MINUS, "-");
//            ++pos;
//        }
//        else if (input[pos] == '*') {
//            // ���ϱ� ������
//            print_token(MULTIPLY, "*");
//            ++pos;
//        }
//        else if (input[pos] == '/') {
//            // ������ ������
//            print_token(DIVIDE, "/");
//            ++pos;
//        }
//        else if (input[pos] == ';') {
//            // �����ݷ�
//            print_token(SEMICOLON, ";");
//            ++pos;
//        }
//        else if (input[pos] == '(') {
//            // ���� ��ȣ
//            print_token(LEFT_PAREN, "(");
//            ++pos;
//        }
//        else if (input[pos] == ')') {
//            // ������ ��ȣ
//            print_token(RIGHT_PAREN, ")");
//            ++pos;
//        }
//        else if (input[pos] == ' ') {
//            // ������ ����
//            ++pos;
//        }
//        else {
//            // �� �� ���� ����
//            cout << "Unknown character: " << input[pos] << endl;
//            ++pos;
//        }
//    }
//
//    // ������ ��
//    print_token(END_OF_FILE, "EOF");
//
//    return 0;
//}