/*
 SE-10
 G-10
 23257

PROBLEM STATEMENT:- Implement stack as an ADT and use this stack to implement
1] infix to postfix conversion
2] infix to prefix conversion
3] evaluation of prefix and postfix expressions
*/

#include <iostream>
#include<stdlib.h>
#include<math.h>
#include<iomanip>
using namespace std;
#include "stackadt.h"
#include "stackadt.cpp"
#include <string.h>


int precedence(char c);
int associativity(char c);

class expression						//class declaration
{
		char infix[50],postfix[50],prefix[50];
public :
		int input();
		void display();
		void display1();
		void display2();
		void infix_to_postfix();
		void infix_to_prefix();
		void evaluate1();
		void evaluate2();
		int countbraces();
};

void reverse(char str1[50])
{
	int i=0,j;
	j=strlen(str1)-1;
	while(i<j)
	{
		char temp=str1[i];
		str1[i]=str1[j];
		str1[j]=temp;
		i++;
		j--;
	}

}
bool isalpha(char x)	//function for detecting operands
{
	if((x>=48 && x<=57)||(x>64 && x<91) || (x>96 && x<123))
		return true;
	else
		return false;
}
float operation(float op1,float op2,char x)		//function for performing operations on operands in stack
{
	float ans;				//ans=(stack[top]) operator (stack[top-1])
	if(x== '+')
		ans=op1 +op2;
	else if(x=='-')
		ans=op1-op2;
	else if(x=='*')
		ans=op1*op2;
	else if(x=='/')
		ans=op1/op2;
	else if(x=='%')
		ans=(int)op1%(int)op2;
	else if(x=='^')
		ans=pow(op1,op2);
	return ans;
}
int expression :: countbraces()//for counting the total no of braces
{
	int i=0,count=0;
	while(infix[i]!='\0')
	{
		if(infix[i]=='(' || infix[i]== ')')
			count+=1;
		i++;
	}
	return count;
}
int expression :: input()//for taking infix expression input
{
	char temp[50];
	char x;
	int i=0,count1=0,count2=0,count3=0;
	cin>>temp;
	while(temp[i]!='\0')
	{
		x=temp[i];
		if(x=='(')
		{
			count1++;
		}
		else if(x==')')
		{
			count1--;
		}
		else if(isalpha(x))
		{
			count2++;
		}
		else
		{
			count3++;
		}
		if(i!=0)
		{
			if(isalpha(x) && isalpha(temp[i-1]))	//NO CONSECUTIVE OPERANDS VALIDATION
			{
				cout<<"\nTWO OPERANDS CANNOT BE CONSECUTIVE.PLEASE ENTER A VALID EXPRESSION:- ";
				return 1;
			}
			else if((x== '+' || x=='-' || x== '*' || x== '/' || x=='%' || x=='^') && (temp[i-1]== '+' || temp[i-1]=='-' || temp[i-1]=='*' || temp[i-1]=='/' || temp[i-1]=='%' || temp[i-1]=='^') )
			{
				cout<<"\nTWO OPERATORS CANNOT BE CONSECUTIVE.PLEASE ENTER A VALID EXPRESSION:-";	//CONSECUTICE OPERATOR VALIDATION
				return 1;
			}
			else if((isalpha(temp[i-1]) && x=='(') || (isalpha(x) && temp[i-1]==')'))	//OPERAND CANNOT BE GIVEN BEFORE OR AFTER A BRACE
			{
				cout<<"\nOPERAND CANNOT BE GIVEN BEFORE OR AFTER A BRACE.PLEASE ENTER A VALID EXPRESSION:-";
				return 1;
			}
		}
		i++;
	}
	if(count1==0)	//to check opening braces = closing braces
	{
		if(count3==(count2-1))	//BINARY EXPRESSION VALIDATION- (OPERATOR=OPERAND-1)
		{
			strcpy(infix,temp);
			return 0;
		}
		else
		{
			cout<<"OPERATOR AND OPERAND RELATION(OPERATOR=OPERAND-1) IS  NOT MATCHING.PLEASE ENTER A VALID EXPRESSION:-";
			return 1;
		}
	}
	else
	{
		cout<<"\nOPENING AND CLOSING BRACES ARE NOT MATCHING.PLEASE ENTER A VALID EXPRESSION:-";
		return 1;
	}
}

void expression::display()//displaying infix expression
{
	cout<<"\nINFIX EXPRESSION:-\t"<<infix<<endl;
}
void expression :: display1()//displaying postfix expression
{
	cout<<"\nPOSTFIX EXPRESSION:-\t"<<postfix<<endl;
}
void expression :: display2()//displaying prefix expression
{
	cout<<"\nPREFIX EXPRESSION:-\t"<<prefix<<endl;
}
int precedence(char c)//determining precedence of operators
{
	if(c== '/' || c=='*' || c=='%')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
	else
		return 3;
}

int associativity(char c)//FOR CHECKING ASSOCIATIVITY OF OPERANDS
{
	if(c== '^')
		return -1;	//for right to left associativity
	else
		return 1;	//for left to right associativity
}

void expression :: infix_to_postfix()	//INFIX TO POSTFIX
{
	stackadt<char> s;	//creating object of stack
	char x,y;
	int i=0,k=0;
	cout<<"\n"<<setw(10)<<setiosflags(ios::left)<<"|TOKEN"<<setw(20)<<setiosflags(ios::left)<<"|OUTPUT"<<setw(20)<<setiosflags(ios::left)<<"|STACK";
	while(infix[i]!='\0')	//while more input is available
	{
		x=infix[i];
		//	case 1: operand
					if(isalpha(x))
					{
						postfix[k++]=x;	//putting in postfix expression
					}
		// case 2:	opening brace
					else if(x=='(')
						s.push(x);	//push in stack
		// case 3:	closing brace
					else if(x==')')
					{
						while(s.peep()!='(')
						{
							postfix[k++]=s.pop();	//putting in postfix expression
						}
						y=s.pop();	//popping opening brace and discarding it

					}
		//case 4:	operator
					else
					{

						if(s.isEmpty() || s.peep()=='(')	//stack empty or opening brace
							s.push(x);
						else if(precedence(x) > precedence(s.peep()))	//precedence of incoming element is greater than the top
							{
								s.push(x);
							}
							else if(precedence(x) < precedence(s.peep()))	//precedence of incoming element is lesser than the top
							{
								while(!s.isEmpty() && precedence(x) < precedence(s.peep()) && s.peep()!='(')
									postfix[k++]=s.pop();					//pop till precedence is less than the top

								if(s.isEmpty() || precedence(x)!=precedence(s.peep()))
									s.push(x);						//when precedence becomes greater than TOP or stack becomes empty,push in stack
								else								//if precedence of both becomes equal
								{
									if(associativity(x)==1)			//left to right associativity
									{
										postfix[k++]=s.pop();
										s.push(x);
									}
									else							//right to left associativity
									{
										s.push(x);
									}
								}

							}
							else if(precedence(x) == precedence(s.peep()))	//if precedence of both becomes equal
							{
								if(associativity(x)==1)			//left to right associativity
								{
									postfix[k++]=s.pop();
									s.push(x);
								}
								else							//right to left associativity
									s.push(x);
							}
					}
		postfix[k]='\0';
		cout<<"\n "<<setw(10)<<setiosflags(ios::left)<<infix[i]<<setw(20)<<setiosflags(ios::left)<<postfix;
		s.display();
		i++;
		postfix[k]='0';
	}
	while(s.isEmpty()!=true)	//putting remaining characters of stack into postfix expression
	{
		postfix[k++]=s.pop();
	}
	postfix[k]='\0';
}

void expression :: infix_to_prefix()	//INFIX TO PREFIX
{
		stackadt<char> s;		//creating object of stack
		char x,y;
		int i=strlen(infix)-1;
		int k=0;
		cout<<"\n"<<setw(10)<<setiosflags(ios::left)<<"|TOKEN"<<setw(20)<<setiosflags(ios::left)<<"|OUTPUT"<<setw(20)<<setiosflags(ios::left)<<"|STACK";
		while(i>=0)			//while more input is available
		{

			x=infix[i];

			//	case 1: operand
						if(isalpha(x))
						{
							prefix[k++]=x;	//putting in postfix expression
						}
			// case 2:	opening brace
						else if(x==')')
							s.push(x);		//push in stack
			// case 3:	closing brace
						else if(x=='(')
						{
							while(s.peep()!=')')	//till stack is not empty
							{
								prefix[k++]=s.pop();	//pop the char and put in postfix expression
							}
							y=s.pop();	//pop the closing brace

						}
			//case 4:	operator
						else
						{

							if(s.isEmpty() || s.peep()==')')	//if stack is empty or there is a closing brace
								s.push(x);						//push in stack
							else if(precedence(x) > precedence(s.peep()))	//precedence of incoming element is greater than the top
								{
									s.push(x);
								}
								else if(precedence(x) < precedence(s.peep()))	//precedence of incoming element is lesser than the top
								{
									while(!s.isEmpty() && precedence(x) < precedence(s.peep()) && s.peep()!=')')	//pop till precedence is less than the top
										prefix[k++]=s.pop();

									if(s.isEmpty() || precedence(x)!=precedence(s.peep()))	//when precedence becomes greater than TOP or stack becomes empty,push in stack
										s.push(x);
									else			//if precedence of both becomes equal
									{
										if(associativity(x)==1)		//left to right associativity
										{
											s.push(x);
										}
										else						//right to left associativity
										{
											postfix[k++]=s.pop();
											s.push(x);
										}
									}

								}
								else if(precedence(x) == precedence(s.peep()))		//equal precedence
								{
									if(associativity(x)==1)			//left to right associativity
									{
										s.push(x);
									}
									else
									{
										prefix[k++]=s.pop();
										s.push(x);					//right to left associativity
									}
								}
						}
						prefix[k]='\0';
						cout<<"\n "<<setw(10)<<setiosflags(ios::left)<<infix[i]<<setw(20)<<setiosflags(ios::left)<<prefix;
						s.display();
						prefix[k]='0';
			i--;

		}
		while(s.isEmpty()!=true)	//putting remaining expressions of stack into postfix expression
		{
			prefix[k++]=s.pop();
		}
		prefix[k]='\0';
		reverse(prefix);
		prefix[k]='\0';
}
void expression :: evaluate1()		//for evaluating postfix expression
{
	stackadt<float>s;			//creating object of stack
	float z,operand1,operand2,ans;
	int i=0;
	char x;
	while(postfix[i]!='\0')
	{
		x=postfix[i];
		//case 1: operand
			if(isalpha(x))
			{
				if(x>47 && x<58)		//when operand is a constant
					s.push(x-48);
				else
				{
					cout<<"\nENTER THE VALUE OF '"<<x<<"':-\t";		//when operand is a variable
					cin>>z;											//getting the value of operand
					s.push(z);						//push the value entered in Stack
				}
			}
			else
			{
				operand2=s.pop();		//pop operand 2
				operand1=s.pop();		//pop operand 1
				s.push(operation(operand1,operand2,x));	//operating op1 and op2 and pushing the result in stack
			}
			cout<<"\n"<<setw(10)<<setiosflags(ios::left)<<"|TOKEN"
							<<setw(10)<<setiosflags(ios::left)<<"|STACK";
			cout<<"\n"<<"|"<<setw(10)<<setiosflags(ios::left)<<x<<"|"<<setw(10)<<setiosflags(ios::left);
			s.display();
			i++;
	}
	ans=s.pop();	//pop the last remaining element of the stack i.e. the answer
	cout<<"\nANSWER:-\t"<<ans;
}

void expression :: evaluate2()				//for evaluating prefix expression
{
	stackadt<float>s;						//creating object of stack
	float z,operand1,operand2,ans;
	int i=strlen(prefix)-1;
	char x;
	while(i>=0)
	{
		x=prefix[i];
		//case 1: operand
			if(isalpha(x))
			{
				if(x>47 && x<58)			//when operand is a constant
					s.push(x-48);
				else
				{
					cout<<"\nENTER THE VALUE OF '"<<x<<"':-\t";			//when operand is a variable
					cin>>z;												//getting the value of operand
					s.push(z);											//push the value entered in Stack
				}
			}
			else
			{
				operand1=s.pop();	//pop operand 2
				operand2=s.pop();	//pop operand 1
				s.push(operation(operand1,operand2,x));			//operating op1 and op2 and pushing the result in stack
			}
			cout<<"\n"<<setw(10)<<setiosflags(ios::left)<<"|TOKEN"
							<<setw(10)<<setiosflags(ios::left)<<"|STACK";
			cout<<"\n"<<"|"<<setw(10)<<setiosflags(ios::left)<<x<<"|"<<setw(10)<<setiosflags(ios::left);
						s.display();
			i--;
	}
	ans=s.pop();					//pop the last remaining element of the stack i.e. the answer
	cout<<"\nANSWER:-\t"<<ans;
}
int main()
{
	expression e;		//creating object of class expression
	int ch,i=1;

	do
	{
		cout<<"\nMENU\n1.INPUT INFIX EXPRESSION\n2.DISPLAY INFIX EXPRESSION\n3.INFIX TO POSTFIX\n4.INFIX TO PREFIX\n5.EVALUATE(POSTFIX)\n6.EVALUATE(PREFIX)\n7.EXIT\nENTER UR CHOICE:-";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nENTER THE EXPRESSION:-";
				i=e.input();		//scanning the infix expression
				while(i!=0)
				{
					i=e.input();
				}
				break;
			case 2:
				e.display();
				break;
			case 3:
				e.infix_to_postfix();
				e.display();
				e.display1();
				break;
			case 4:
				e.infix_to_prefix();
				e.display();
				e.display2();
				break;
			case 5:
				e.evaluate1();
				break;
			case 6:
				e.evaluate2();
				break;
		}

	}while(ch!=7);
return 0;

}


/*OUTPUT:-


MENU
1.INPUT INFIX EXPRESSION
2.DISPLAY INFIX EXPRESSION
3.INFIX TO POSTFIX
4.INFIX TO PREFIX	postfix[k++]=s.pop();
											s.push(x);
5.EVALUATE(POSTFIX)
6.EVALUATE(PREFIX)
7.EXIT
ENTER UR CHOICE:-1

ENTER THE EXPRESSION:-(a+b)*c-d*(e+f)

MENU
1.INPUT INFIX EXPRESSION
2.DISPLAY INFIX EXPRESSION
3.INFIX TO POSTFIX
4.INFIX TO PREFIX
5.EVALUATE(POSTFIX)
6.EVALUATE(PREFIX)
7.EXIT
ENTER UR CHOICE:-2

INFIX EXPRESSION:-	(a+b)*c-d*(e+f)

MENU
1.INPUT INFIX EXPRESSION
2.DISPLAY INFIX EXPRESSION
3.INFIX TO POSTFIX
4.INFIX TO PREFIX
5.EVALUATE(POSTFIX)
6.EVALUATE(PREFIX)
7.EXIT
ENTER UR CHOICE:-3

|TOKEN    |OUTPUT             |STACK
 (                              (
 a          a                   (
 +          a                   +(
 b          ab                  +(
 )          ab+                 EMPTY
 *          ab+                 *
 c          ab+c                *
 -          ab+c*               -
 d          ab+c*d              -
 *          ab+c*d              *-
 (          ab+c*d              (*-
 e          ab+c*de             (*-
 +          ab+c*de             +(*-
 f          ab+c*def            +(*-
 )          ab+c*def+           *-
INFIX EXPRESSION:-	(a+b)*c-d*(e+f)

POSTFIX EXPRESSION:-	ab+c*def+*-

MENU
1.INPUT INFIX EXPRESSION
2.DISPLAY INFIX EXPRESSION
3.INFIX TO POSTFIX
4.INFIX TO PREFIX
5.EVALUATE(POSTFIX)
6.EVALUATE(PREFIX)
7.EXIT
ENTER UR CHOICE:-4

|TOKEN    |OUTPUT             |STACK
 )                               )
 f          f                    )
 +          f                    +)
 e          fe                   +)
 (          fe+                  EMPTY
 *          fe+                  *
 d          fe+d                 *
 -          fe+d*                -
 c          fe+d*c               -
 *          fe+d*c               *-
 )          fe+d*c               )*-
 b          fe+d*cb              )*-
 +          fe+d*cb              +)*-
 a          fe+d*cba             +)*-
 (          fe+d*cba+            *-
INFIX EXPRESSION:-	(a+b)*c-d*(e+f)

PREFIX EXPRESSION:-	-*+abc*d+ef

MENU
1.INPUT INFIX EXPRESSION
2.DISPLAY INFIX EXPRESSION
3.INFIX TO POSTFIX
4.INFIX TO PREFIX
5.EVALUATE(POSTFIX)
6.EVALUATE(PREFIX)
7.EXIT
ENTER UR CHOICE:-5

ENTER THE VALUE OF 'a':-	1

ENTER THE VALUE OF 'b':-	2

ENTER THE VALUE OF 'c':-	3

ENTER THE VALUE OF 'd':-	4

ENTER THE VALUE OF 'e':-	5

ENTER THE VALUE OF 'f':-	6

ANSWER:-	-35
MENU
1.INPUT INFIX EXPRESSION
2.DISPLAY INFIX EXPRESSION
3.INFIX TO POSTFIX
4.INFIX TO PREFIX
5.EVALUATE(POSTFIX)
6.EVALUATE(PREFIX)
7.EXIT
ENTER UR CHOICE:-6

ENTER THE VALUE OF 'f':-	6

ENTER THE VALUE OF 'e':-	5

ENTER THE VALUE OF 'd':-	4

ENTER THE VALUE OF 'c':-	3

ENTER THE VALUE OF 'b':-	2

ENTER THE VALUE OF 'a':-	1

ANSWER:-	-35
MENU
1.INPUT INFIX EXPRESSION
2.DISPLAY INFIX EXPRESSION
3.INFIX TO POSTFIX
4.INFIX TO PREFIX
5.EVALUATE(POSTFIX)
6.EVALUATE(PREFIX)
7.EXIT
ENTER UR CHOICE:-7

*/
