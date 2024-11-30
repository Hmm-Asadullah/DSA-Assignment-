#include<iostream>
using namespace std;
#include<string>
template<typename T>
class Stack
{
	T* stack; // Dynamic array for stack elements
	int top;  // Index of the top element
	int size; // Current capacity of the stack
public:
	// Default constructor initializing a stack with capacity 1
	Stack()
	{
		size = 1;
		stack = new T[size];
		top = -1;
	}
	// Constructor with specified capacity
	Stack(int cap)
	{
		if (cap < 0)
		{
			exit(0); // Exit if capacity is invalid
		}
		else
		{
			stack = new T[cap];
			top = -1;
			size = cap;
		}
	}
	// Check if the stack is empty
	bool isEmpty()
	{
		return top == -1;
	}
	// Check if the stack is full
	bool isFull()
	{
		return top == size - 1;
	}
	// Push an element onto the stack
	void push(T item)
	{
		if (!isFull())
		{
			stack[++top] = item;
		}
		else
		{
			resize(size * 2); // Double the capacity if full
			stack[++top] = item;
		}
	}
	// Pop an element from the stack
	T pop()
	{
		if (!isEmpty())
		{
			return stack[top--];
		}
	}
	// Get the top element without removing it
	T peek()
	{
		if (!isEmpty())
		{
			return stack[top];
		}
	}
	// Get the current size (capacity) of the stack
	int getSize()
	{
		return size;
	}
	// Destructor to free the allocated memory
	~Stack()
	{
		if (!stack)
		{
			return;
		}
		delete[] stack;
		stack = nullptr;
		size = 0;
		top = -1;
	}
	// Resize the stack to a new capacity
	void resize(int newCap)
	{
		if (newCap <= 0)
		{
			return;
		}
		T* newStack = new T[newCap];
		for (int i = 0; i <= top; i++)
		{
			newStack[i] = stack[i];
		}
		delete[] stack;
		stack = newStack;
		size = newCap;
	}
	// Print all elements in the stack (from top to bottom)
	void print()
	{
		if (!isEmpty())
		{
			for (int i = top; i >= 0; i--)
			{
				cout << stack[i] << " ";
			}
		}
	}
};
//Function Prototypes
string prefixToPostfix(string prefix);
string postfixToPrefix(string postfix);
int evaluateExpression(string expression);
bool validateExpression(string expression, string notation);
string infixToPostfix(string infix);
bool isPrefix(string exp);
bool isPostfix(string exp);
string infixToPrefix(string infix);
string determineExpressionType(string expression);
string reverseExpression(string expression);
bool isOperator(char op);
bool isLogicalOp(char op);
bool isOperand(char op);
int calcPower(int base, int exp);
int getPrecedence(char op);
// Main Function for testing
int main()
{
	try // to catch any exception occured during the execution of the application
	{
		string exp;
		cout << "Enter Infix expression: ";
		getline(cin, exp);
		cout << "Initial Infix Expression: " << exp;
		string prefix= infixToPrefix(exp);
		string postfix= infixToPostfix(exp);
		cout << "\nPostfix Expression: " << postfix;
		cout << "\nPrefix Expression: " << prefix;
		cout << "\nPostfix Expression: " << prefixToPostfix(prefix);
		cout << "\nPrefix Expression: " << postfixToPrefix(postfix);
		cout << "\nEvaluated Expression: " << evaluateExpression(exp);
		cout << "\n" << boolalpha << validateExpression(prefix, "prefix");
		cout << "\n" << boolalpha << validateExpression(postfix, "postfix");
		cout << "\nExpression Type: " << determineExpressionType(exp);
	}
	catch (const char* except)
	{
		cout << except;   //exception caught and displayed
	}
	return 0;
}
// checks whether the expression is prefix or not 
bool isPrefix(string exp)
{
	int operators = 0, operands = 0;
	for (int i = exp.length(); i >= 0; i--)
	{
		if (isOperand(exp[i]))
		{
			do
			{
				i--;
			} while (i < exp.length() && isOperand(exp[i]));
			i++;
			operands++;
		}
		else if (isOperator(exp[i]) || isLogicalOp(exp[i]))
		{
			operators++;
		}
		if (operators >= operands)
		{
			return false;
		}
	}
	return operands == operators + 1;
}
// checks whether the expression is postfix or not
bool isPostfix(string exp)
{
	int operators = 0, operands = 0;
	for (int i = 0; i < exp.length(); i++)
	{
		if (isOperand(exp[i]))
		{
			do
			{
				i++;
			} while (i < exp.length() && isOperand(exp[i]));
			i--;
			operands++;
		}
		else if (isOperator(exp[i]) || isLogicalOp(exp[i]))
		{
			operators++;
		}
		if (operands <= operators)
		{
			return false;
		}
	}
	return operands == operators + 1;
}
//converts the expression from prefix to postfix
string prefixToPostfix(string prefix)
{
	if (!validateExpression(prefix, "prefix"))
	{
		throw "\nInvalid Expression";
	}
	Stack<string> s{ (int)prefix.length() };
	for (int i = prefix.length() - 1; i >= 0; i--)
	{
		if (isOperand(prefix[i]))
		{
			string op;
			do
			{
				op += (string{ prefix[i] });
				i--;
			} while (i >= 0 && isOperand(prefix[i]));
			i++;
			s.push(op);
		}
		else if (isOperator(prefix[i]) || isLogicalOp(prefix[i]))
		{
			string first = s.pop(), second = s.pop();
			s.push("(" + second + prefix[i] + first + ")");
		}
	}
	string infix = reverseExpression(s.pop());
	return infixToPostfix(infix);
}
//converts the expression from postfix to prefix 
string postfixToPrefix(string postfix)
{
	if (!validateExpression(postfix, "postfix"))
	{
		throw "\nInvalid Expression";
	}
	Stack<string> s{ (int)postfix.length() };
	for (int i = 0; i < postfix.length(); i++)
	{
		if (isOperand(postfix[i]))
		{
			string op;
			do
			{
				op += (string{ postfix[i] });
				i++;
			} while (i >= 0 && isOperand(postfix[i]));
			i--;
			s.push(op);
		}
		else if (isOperator(postfix[i]) || isLogicalOp(postfix[i]))
		{
			string first = s.pop(), second = s.pop();
			s.push("(" + second + postfix[i] + first + ")");
		}
	}
	return infixToPrefix(s.pop());
}
//evaluates the given expression
int evaluateExpression(string s)
{
	s = infixToPostfix(s); //converison from infix to postfix  
	Stack<int> exp{ (int)s.length() }; // A stack to store the operands 
	for (int i = 0; i < s.length(); i++)
	{
		int result = 0;
		if (isOperator(s[i]) || isLogicalOp(s[i])) //if the charachter is operator pop the first two charachter from stack
		{											//and push them back after performing the operation 
			if (!exp.isEmpty())
			{
				int first = exp.pop(), sec = exp.pop();
				if (s[i] == '+')
				{
					exp.push(sec + first);
				}
				else if (s[i] == '-')
				{
					exp.push(sec - first);
				}
				else if (s[i] == '*')
				{
					exp.push(sec * first);
				}
				else if (s[i] == '/')
				{
					if (!first)
						throw "\nInvalid division i.e by zero";
					exp.push(sec / first);
				}
				else if (s[i] == '^')
				{
					exp.push(calcPower(sec, first));
				}
				else if (s[i] == '%')
				{
					if (!first)
						throw "\nInvalid division i.e by zero"; // division by zero exception thrown
					exp.push(sec % first);
				}
				else if (s[i] == '&') //evaluates to true if both the operands are non zero
				{
					if (first != 0 && sec != 0)
					{
						exp.push(1);
					}
					else
					{
						exp.push(0);
					}
				}
				else if (s[i] == '|') //evaluates to false if any of the operand is non zero
				{
					if (first != 0 || sec != 0)
					{
						exp.push(1);
					}
					else
					{
						exp.push(0);
					}
				}
			}
		}
		else if (s[i] >= '0' && s[i] <= '9') // if the charachter is operand extract every digit of the number 
		{									// from the expression, convert it into a number and push it into the stack
			int num = 0;
			do
			{
				num = (num * 10) + (s[i] - '0');
				i++;
			} while (i < s.length() && isOperand(s[i]));
			i--;
			exp.push(num);
		}
	}
	return exp.pop(); // return the only number left in the stack
}
//validates the expression depend on its notation
bool validateExpression(string expression, string notation) // validates the expression 
{
	if (notation == "postfix")
	{
		int count = 0;
		for (int i = 0; i < expression.length(); i++)
		{
			if (isOperand(expression[i]))
			{
				do
				{
					i++;
				} while (i < expression.length() && isOperand(expression[i]));
				i--;
				count++;
			}
			else if (isOperator(expression[i]) || isLogicalOp(expression[i]))
			{
				if (count < 2)
				{
					return false;
				}
				count--;
			}
		}
		return count == 1 ? true : false;
	}
	else if (notation == "prefix")
	{
		int count = 0;
		for (int i = expression.length(); i >= 0; i--)
		{
			if (isOperand(expression[i]))
			{
				do
				{
					i--;
				} while (i < expression.length() && isOperand(expression[i]));
				i++;
				count++;
			}
			else if (isOperator(expression[i]) || isLogicalOp(expression[i]))
			{
				if (count < 2)
				{
					return false;
				}
				count--;
			}
		}
		return (count == 1) ? true : false;
	}
	throw "\nExpression Invalid:";
}
// converts from infx to prefix
string infixToPostfix(string expression)
{
	string postfix;
	Stack<char> stk{ (int)expression.length() };
	for (int i = 0; i < expression.length(); i++)
	{
		if (isOperand(expression[i]) || expression[i] == ',')
		{
			do
			{
				postfix += expression[i];
				i++;
			} while (i < expression.length() && isOperand(expression[i]));
			i--;
			postfix += ",";
		}
		else if (expression[i] == '(')
		{
			stk.push(expression[i]);
		}
		else if (expression[i] == ')')
		{
			while (stk.peek() != '(')
			{
				postfix += stk.pop();
			}
			stk.pop();
		}
		else if (isOperator(expression[i]) || isLogicalOp(expression[i]))
		{
			if ((!stk.isEmpty() && stk.peek() != '('))
			{
				while (!stk.isEmpty() && getPrecedence(stk.peek()) >= getPrecedence(expression[i]))
				{
					if (stk.peek() != '(')
						postfix += stk.pop();
					else
						stk.pop();
				}
			}
			stk.push(expression[i]);
		}
	}
	while (!stk.isEmpty())
	{
		if (stk.peek() != '(')
		{
			postfix += stk.pop();
		}
		else
		{
			stk.pop();
		}
	}
	return postfix;
}
// conversion from infx to postfix
string infixToPrefix(string expression)
{
	expression = reverseExpression(expression);
	string prefix;
	Stack<char> stk{ (int)expression.length() };
	for (int i = 0; i < expression.length(); i++)
	{
		if (isOperand(expression[i]) || expression[i] == ',')
		{
			do
			{
				prefix += expression[i];
				i++;
			} while (i < expression.length() && isOperand(expression[i]));
			i--;
			prefix += ",";
		}
		else if (expression[i] == ')')
		{
			while (!stk.isEmpty() && stk.peek() != '(')
			{
				prefix += stk.pop();
			}
			stk.pop();
		}
		else if (expression[i] == '(')
		{
			stk.push(expression[i]);
		}
		else if (isOperator(expression[i]) || isLogicalOp(expression[i]))
		{
			if ((!stk.isEmpty() && stk.peek() != '('))
			{
				while (!stk.isEmpty() && getPrecedence(stk.peek()) > getPrecedence(expression[i]))
				{
					if (stk.peek() != '(')
						prefix += stk.pop();
					else
						stk.pop();
				}
			}
			stk.push(expression[i]);
		}
	}
	while (!stk.isEmpty())
	{
		if (stk.peek() != '(')
		{
			prefix += stk.pop();
		}
		else
		{
			stk.pop();
		}
	}
	return reverseExpression(prefix);
}
// determines the expression's Type (Returns "Arithmetic", "Logical", or "Mixed")
string determineExpressionType(string exp)
{
	int ar, log; //counters to count logical and arithmetic expression 
	ar = log = 0;
	for (int i = 0; i < exp.length(); i++)
	{
		if (isOperator(exp[i]))
		{
			ar++; // if operator is arithmetic increase the count by one
		}
		else if (isLogicalOp(exp[i]))
		{
			log++; // if operator is logical increase the count by one
		}
	}
	if (ar && log) //if both counts are non zero expression is mixed 
	{
		return "Mixed";
	}
	else if (ar)
	{
		return "Arithmetic";
	}
	else if (log)
	{
		return "Logical";
	}
}
// check whether the current charachter of the expresssion is logical operator or not
bool isLogicalOp(char op)
{
	return (op == '&' || op == '|') ? true : false;
}
// check whether the current charachter of the expresssion is operand or not
bool isOperand(char op)
{
	return ((op >= '0' && op <= '9') || (op >= 'a' && op <= 'z') || (op >= 'A' && op <= 'Z')) ? true : false;
}
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
// check whether the current charachter of the expresssion is arithmetic operator or not
bool isOperator(char op)
{
	return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '%') ? true : false;
}
// gives the precedence of current operator
int getPrecedence(char op)
{
	switch (op)
	{
	case '-':
		return 1;
	case '+':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '%':
		return 2;
	case '^':
		return 3;
	case '|':
		return 4;
	case '&':
		return 5;
	default:
		return 0;
	}
}
// reverses the given Expression
string reverseExpression(string expression)
{
	int j = expression.length() - 1;
	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == '(')
		{
			expression[i] = ')';
		}
		else if (expression[i] == ')')
		{
			expression[i] = '(';
		}
	}
	for (int i = 0; i <= j; i++)
	{
		mySwap(expression[i], expression[j]);
		j--;
	}
	return expression;
}
// calculates the power used for exponential operator
int calcPower(int base, int exp)
{
	int res = 1;
	while (exp)
	{
		res = res * base;
		exp--;
	}
	return res;
}