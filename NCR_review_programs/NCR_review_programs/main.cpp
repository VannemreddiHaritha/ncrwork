#include<stdio.h>
#include<iostream>
using namespace std;
#include<stack>
int add(int, int);
int sub(int, int);
int mul(int, int);
int divi(int, int);
int calculation(int a, int b, char oper)throw(int) {
	switch (oper) {
	case '+': return add(a, b); break;
	case '-': return sub(a, b); break;
	case '*': return mul(a, b); break;
	case '/': return divi(a, b); break;
	default:cout << "invalid operator\n";
	}
}
//to check prority 
int prority(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}


int evaluation(char *expression)
{
	stack<int> operand;
	stack<char> operators;
	int i;
	for (i = 0; expression[i] != '\0'; i++)//to take each value of expression
	{
		if (expression[i] == ' ')//if it is space ,ignore it
			continue;
		else if (expression[i] == '(')
			operators.push(expression[i]);// push '(' it in operators stack
		else if (isdigit(expression[i]))
		{
			int temp_var = 0;
			while (expression[i] != '\0' && isdigit(expression[i]))//if it is multiple digits
			{
				temp_var= temp_var * 10 + expression[i] - '0';
				i++;
			}
			i--;
			operand.push(temp_var);
	
		}
		else if (expression[i] == ')')
		{
			while ((!operators.empty()) && operators.top() != '(')//if it is closing paranthesis,pop out two operands and perform respective operation until you encounter '('
			{
				int op1 = operand.top();
				operand.pop();
				int op2 = operand.top();
				operand.pop();

				char op = operators.top();
				operators.pop();

				operand.push(calculation(op2, op1, op));
			}
			operators.pop();

		}
		else
		{
			while (!operators.empty() && prority(operators.top()) >= prority(expression[i]))
				//if precendence of top element in stack is less than the next character in string,just pop out the operands and perform operation
			    {
				int op1 = operand.top();
				operand.pop();
				int op2 = operand.top();
				operand.pop();

				char op = operators.top();
				operators.pop();
				operand.push(calculation(op2, op1, op));
							}
			operators.push(expression[i]);//it also pushs if operator stack is empty
		}
	}
	while (!operators.empty())//if the operators stack is not empty,repeat the operations till it becomes empty
	{
		int op1 = operand.top();
		operand.pop();
		int op2 = operand.top();
		operand.pop();

		char op = operators.top();
		operators.pop();
	
		operand.push(calculation(op2, op1, op));
	}
	return operand.top();
}
int main()
{
	char *expr = new char[1];
	
	expr = (char *)malloc( sizeof(char));
	printf("Enter expression to evaluate\n");
	cin >> expr;
	int i;
	for (i = 0;expr[i];i++)
	{
		if (expr[i] == '}' || expr[i] == '{' || isalpha(expr[i])||expr[i]==']'||expr[i]=='[')
			printf("invalid input");
    }
	try{
		printf("Result = %d\n", evaluation(expr));
	}
	catch (int err)
	{
		printf("divide by zero error");
	}
	
	system("pause");
	return 0;
}