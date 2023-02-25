//Proj 2
//Nalby Kadkoui
#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::ifstream;
void parser(string input);
bool A();
bool E();
bool O();
bool P();
bool U();
bool I();
bool C();
bool L();
bool D();

string s ="";
int counter=0;
int main()
{
	string input;
	ifstream file;
	file.open("input.txt");
	while (file>>input)
	{
		parser(input);
	}
	file.close();
}

 
void parser(string input)
{
	s = input;
	counter = 0;
	if (A() && counter == s.length())
	{
		cout << s << " is in the language\n";
		return;
	}
	cout << s << " isn't in the language\n";
	return;

}
//A -> I = E
bool A()
{
	if (I())
	{
		if (s[counter] == '=')
		{
			counter++;
			if (E())
				return true;
		}
	}
	return false;
}
//E -> P O P | P 
bool E()
{
	if (P())
	{
		if (O())
		{
			if (P())
			{
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}
//O -> + | - | * | / | **
bool O()
{
	if ( s.substr(counter,2)=="**")
	{
		counter += 2;
		return true;
	}
	if (s[counter] == '+' || s[counter] == '-' || s[counter] == '*' || s[counter] == '/')
	{
		counter++;
		return true;
	}
	
	return false;
}

//P -> I | L | UI | UL | (E)
bool P()
{
	if (I())
	{
		return true;
	}
	if (L())
	{
		return true;
	}
	if (U())
	{
		if (I())
		{
			return true;
		}
		if (L())
		{
			return true;
		}
		counter--;
	}
	if (s[counter] == '(')
	{
		counter++;
		if (E())
		{
			if (s[counter] == ')')
			{
				counter++;
				return true;

			}
		}
	}
	return false;
}
//U -> + | - | !
bool U()
{
	if (s[counter] == '+' || s[counter] == '-' || s[counter] == '!')
	{
		counter++;
		return true;
	}
	return false;
}
//I -> C | CI
bool I()
{
	if (C())
	{
		if (I())
		{
			return true;
		}
		return true;
	}
	return false;
}
//C -> a | b | ... | y | z
bool C()
{
	if (s[counter] >= 'a' && s[counter] <= 'z')
	{
		counter++;
		return true;
	}
	return false;
}
//L -> D | DL
bool L()
{
	if (D())
	{
		if (L())
		{
			return true;
		}
		return true;
	}
	return false;
}
//D -> 0 | 1 | ... | 8 | 9
bool D()
{
	if (s[counter] >= '0' && s[counter]<='9')
	{
		counter++;
		return true;
	}
	return false;
}
