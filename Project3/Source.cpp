#include <iostream>
using namespace std;

class var
{
	char* c;
	int i;
	double d;
public:

	var();
	var(const char*);
	var(int);
	var(double);
	var(const char* C, int I, double D);
	~var();
	var& operator+(const var& a);
	var& operator-(const var& a);
	var& operator+=(const var& a);
	var& operator-=(const var& a);
	var operator*(const var& a);
	var& operator*=(const var& a);
	var operator/(const var& a);
	var& operator/=(const var& a);
	void operator()()
	{
		if (c != nullptr)
			cout << c << "\t";
		cout << i << "\t" << d;
	}
	bool operator>(const var& a);
	bool operator<(const var& a);
	bool operator<=(const var& a);
	bool operator>=(const var& a);
	bool operator==(const var& a);
	bool operator!=(const var& a);
};

var::var()
{
	c = nullptr;
	i = 0;
	d = 0.0;
}

var::var(const char* a)
{
	c = new char[strlen(a) + 1];
	strcpy_s(c, strlen(a) + 1, a);
	i = 0;
	d = 0.0;
}

var::var(int a)
{
	i = a;
	c = nullptr;
	d = 0.0;
}

var::var(double a)
{
	d = a;
	c = nullptr;
	i = 0;
}

var::var(const char* C, int I, double D)
{
	i = I;
	d = D;
	c = new char[strlen(C) + 1];
	strcpy_s(c, strlen(C) + 1, C);
}

var::~var()
{
	delete[]c;
}

var& var::operator+(const var& a)
{
	var buff;
	if (i != 0)
	{
		if (a.i != 0)
		{
			buff.i = i + a.i;
		}
		else if (a.d != 0)
		{
			buff.i = i + a.d;
		}
		else if (a.c != nullptr)
		{
			buff.i = i + atoi(a.c);
		}
		else
		{
			buff.i = i;
		}
	}
	else if (d != 0)
	{
		if (a.i != 0)
		{
			buff.d = d + a.i;
		}
		else if (a.d != 0)
		{
			buff.d = d + a.d;
		}
		else if (a.c != nullptr)
		{
			buff.d = d + atof(a.c);
		}
		else
		{
			buff.d = d;
		}
	}
	else if (c != nullptr)
	{
		if (a.i != 0)
		{
			char rez[20];
			_itoa_s(a.i, rez, 10);
			strcpy_s(rez, strlen(c) + strlen(rez) + 1, c);
			strcat_s(buff.c, strlen(c) + strlen(rez) + 1, rez);
		}
		else if (a.d != 0)
		{
			char rez[20];
			_itoa_s(a.d, rez, 10);
			strcpy_s(rez, strlen(c) + strlen(rez) + 1, c);
			strcat_s(buff.c, strlen(c) + strlen(rez) + 1, rez);
		}
		else
			buff.c = c;
	}
	return buff;
}
var& var::operator-(const var& a)
{
	var buff;
	if (i != 0)
	{
		if (a.i != 0)
		{
			buff.i = i - a.i;
		}
		else if (a.d)
		{
			buff.i = i - a.d;
		}
		else if (a.c != nullptr)
		{
			buff.i = i - atoi(a.c);
		}
		else
		{
			buff.i -= i;
		}
	}
	else if (d != 0)
	{
		if (a.i != 0)
		{
			buff.d = d - a.i;
		}
		else if (a.d)
		{
			buff.d = d - a.d;
		}
		else if (a.c != nullptr)
		{
			buff.d = d - atof(a.c);
		}
		else
		{
			buff.d -= d;
		}
	}
	else
		buff.c = c;
	return buff;
}

var& var::operator+=(const var& a)
{
	if (i != 0)
	{
		if (a.i != 0)
		{
			i += a.i;
		}
		else if (a.d != 0)
		{
			i += a.d;
		}
		else if (a.c != nullptr)
		{
			i += atoi(a.c);
		}
	}
	else if (d != 0)
	{
		if (a.i != 0)
		{
			d += a.i;
		}
		else if (a.d != 0)
		{
			d += a.d;
		}
		else if (a.c != nullptr)
		{
			d += atof(a.c);
		}
	}
	else if (c != nullptr)
	{
		if (a.i != 0)
		{
			char rez[20];
			_itoa_s(a.i, rez, 10);
			strcpy_s(rez, strlen(c) + strlen(rez) + 1, c);
			strcat_s(c, strlen(c) + strlen(rez) + 1, rez);
		}
		else if (a.d != 0)
		{
			char rez[20];
			_itoa_s(a.d, rez, 10);
			strcpy_s(rez, strlen(c) + strlen(rez) + 1, c);
			strcat_s(c, strlen(c) + strlen(rez) + 1, rez);
		}
	}
	return *this;
}
var& var::operator-=(const var& a)
{
	if (i != 0)
	{
		if (a.i != 0)
		{
			i -= a.i;
		}
		else if (a.d != 0)
		{
			i -= a.d;
		}
		else if (a.c != nullptr)
		{
			i -= atoi(a.c);
		}
	}
	else if (d != 0)
	{
		if (a.i != 0)
		{
			d -= a.i;
		}
		else if (a.d != 0)
		{
			d -= a.d;
		}
		else if (a.c != nullptr)
		{
			d -= atof(a.c);
		}
	}
	else if (c != nullptr)
	{

	}
	return *this;
}

var var::operator*(const var& a)
{
	var buff;
	if (i != 0)
	{
		if (a.i != 0)
		{
			buff.i = i * a.i;
		}
		else if (a.d != 0)
		{
			buff.i = i * a.d;
		}
		else if (a.c != nullptr)
		{
			buff.i = i * atoi(a.c);
		}
		else
		{
			buff.i = i;
		}
	}
	else if (d != 0)
	{
		if (a.i != 0)
		{
			buff.d = d * a.i;
		}
		else if (a.d != 0)
		{
			buff.d = d * a.d;
		}
		else if (a.c != nullptr)
		{
			buff.d = d * atof(a.c);
		}
		else
		{
			buff.d = d;
		}
	}
	buff.c = nullptr;
	if (a.c != nullptr && c != nullptr)
	{
		int count = 1;
		for (int j = 0; j < strlen(a.c); j++)
		{
			for (int j2 = 0; j2 < strlen(c); j2++)
			{
				if (c[j2] == a.c[j])
				{
					count++;
				}
			}
		}
		char* buff_c = new char[count];
		int cu_buff = 0;
		for (int j = 0; j < strlen(a.c); j++)
		{
			for (int j2 = 0; j2 < strlen(c); j2++)
			{
				if (c[j2] == a.c[j])
				{
					buff_c[cu_buff] = c[j2];
					cu_buff++;
				}
			}
		}
		buff_c[count - 1] = '\0';
		if (buff.c != nullptr)
			delete[]buff.c;
		buff.c = new char[count];
		strcpy_s(buff.c, count, buff_c);
	}
	return buff;
}
var& var::operator*=(const var& a)
{
	if (i != 0)
	{
		if (a.i != 0)
		{
			i *= a.i;
		}
		else if (a.d != 0)
		{
			i *= a.d;
		}
		else if (a.c != nullptr)
		{
			i *= atoi(a.c);
		}
	}
	else if (d != 0)
	{
		if (a.i != 0)
		{
			d *= a.i;
		}
		else if (a.d != 0)
		{
			d *= a.d;
		}
		else if (a.c != nullptr)
		{
			d *= atof(a.c);
		}
	}
	if (a.c != nullptr && c != nullptr)
	{
		int count = 1;
		for (int j = 0; j < strlen(a.c); j++)
		{
			for (int j2 = 0; j2 < strlen(c); j2++)
			{
				if (c[j2] == a.c[j])
				{
					count++;
				}
			}
		}
		char* buff_c = new char[count];
		int cu_buff = 0;
		for (int j = 0; j < strlen(a.c); j++)
		{
			for (int j2 = 0; j2 < strlen(c); j2++)
			{
				if (c[j2] == a.c[j])
				{
					buff_c[cu_buff] = c[j2];
					cu_buff++;
				}
			}
		}
		buff_c[count - 1] = '\0';
		if (c != nullptr)
			delete[]c;
		c = new char[count];
		strcpy_s(c, count, buff_c);
	}
	return *this;
}

var var::operator/(const var& a)
{
	var buff;
	if (i != 0)
	{
		if (a.i != 0)
		{
			buff.i = i / a.i;
		}
		else if (a.d != 0)
		{
			buff.i = i / a.d;
		}
		else if (a.c != nullptr)
		{
			buff.i = i / atoi(a.c);
		}
		else
		{
			buff.i = i;
		}
	}
	else if (d != 0)
	{
		if (a.i != 0)
		{
			buff.d = d / a.i;
		}
		else if (a.d != 0)
		{
			buff.d = d / a.d;
		}
		else if (a.c != nullptr)
		{
			buff.d = d / atof(a.c);
		}
		else
		{
			buff.d = d;
		}
	}
	buff.c = nullptr;
	if (a.c != nullptr && c != nullptr)
	{
		int count = 1, count_check = 0;
		for (int j = 0; j < strlen(a.c); j++)
		{
			for (int j2 = 0; j2 < strlen(c); j2++)
			{
				if (c[j2] != a.c[j])
				{
					count_check++;
				}
				if (count_check == strlen(c))
				{
					count++;
				}
			}
			count_check = 0;
		}
		char* buff_c = new char[count];
		int cu_buff = 0;
		for (int j = 0; j < strlen(a.c); j++)
		{
			for (int j2 = 0; j2 < strlen(c); j2++)
			{
				if (c[j2] != a.c[j])
				{
					count_check++;
				}
				if (count_check == strlen(c))
				{
					buff_c[cu_buff] = c[j2];
					cu_buff++;
				}
			}
			count_check = 0;
		}
		buff_c[count - 1] = '\0';
		if (buff.c != nullptr)
			delete[]buff.c;
		buff.c = new char[count];
		strcpy_s(buff.c, count, buff_c);
	}
	return buff;
}
var& var::operator/=(const var& a)
{
	if (i != 0)
	{
		if (a.i != 0)
		{
			i /= a.i;
		}
		else if (a.d != 0)
		{
			i /= a.d;
		}
		else if (a.c != nullptr)
		{
			i /= atoi(a.c);
		}
	}
	else if (d != 0)
	{
		if (a.i != 0)
		{
			d /= a.i;
		}
		else if (a.d != 0)
		{
			d /= a.d;
		}
		else if (a.c != nullptr)
		{
			d /= atof(a.c);
		}
	}
	if (a.c != nullptr && c != nullptr)
	{
		int count = 1, count_check = 0;
		for (int j = 0; j < strlen(a.c); j++)
		{
			for (int j2 = 0; j2 < strlen(c); j2++)
			{
				if (c[j2] != a.c[j])
				{
					count_check++;
				}
				if (count_check == strlen(c))
				{
					count++;
				}
			}
			count_check = 0;
		}
		char* buff_c = new char[count];
		int cu_buff = 0;
		for (int j = 0; j < strlen(a.c); j++)
		{
			for (int j2 = 0; j2 < strlen(c); j2++)
			{
				if (c[j2] != a.c[j])
				{
					count_check++;
				}
				if (count_check == strlen(c))
				{
					buff_c[cu_buff] = c[j2];
					cu_buff++;
				}
			}
			count_check = 0;
		}
		buff_c[count - 1] = '\0';
		if (c != nullptr)
			delete[]c;
		c = new char[count];
		strcpy_s(c, count, buff_c);
	}
	return *this;
}

bool var::operator<(const var& a)
{
	if (i != 0)
	{
		if (a.i != 0)
		{
			if (i < a.i)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			if (i < a.d)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (i < atoi(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
	else if (d != 0)
	{
		if (a.i != 0)
		{
			if (d < a.i)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			if (d < a.d)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (d < atof(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
	else if (c != nullptr)
	{
		if (a.i != 0)
		{
			char buff[20];
			itoa(a.i, buff, 10);
			if (strlen(c) < strlen(buff))
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			char buff[20];
			itoa(a.d, buff, 10);
			if (strlen(c) < strlen(buff))
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (strlen(c) < strlen(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
}

bool var::operator<=(const var& a)
{
	if (i != 0)
	{
		if (a.i != 0)
		{
			if (i <= a.i)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			if (i <= a.d)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (i <= atoi(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
	else if (d != 0)
	{
		if (a.i != 0)
		{
			if (d <= a.i)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			if (d <= a.d)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (d <= atof(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
	else if (c != nullptr)
	{
		if (a.i != 0)
		{
			char buff[20];
			itoa(a.i, buff, 10);
			if (strlen(c) <= strlen(buff))
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			char buff[20];
			itoa(a.d, buff, 10);
			if (strlen(c) <= strlen(buff))
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (strlen(c) <= strlen(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
}

bool var::operator>(const var& a)
{
	if (i != 0)
	{
		if (a.i != 0)
		{
			if (i > a.i)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			if (i > a.d)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (i > atoi(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
	else if (d != 0)
	{
		if (a.i != 0)
		{
			if (d > a.i)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			if (d > a.d)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (d > atof(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
	else if (c != nullptr)
	{
		if (a.i != 0)
		{
			char buff[20];
			itoa(a.i, buff, 10);
			if (strlen(c) > strlen(buff))
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			char buff[20];
			itoa(a.d, buff, 10);
			if (strlen(c) > strlen(buff))
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (strlen(c) > strlen(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
}

bool var::operator>=(const var& a)
{
	if (i != 0)
	{
		if (a.i != 0)
		{
			if (i >= a.i)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			if (i >= a.d)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (i >= atoi(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
	else if (d != 0)
	{
		if (a.i != 0)
		{
			if (d >= a.i)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			if (d >= a.d)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (d >= atof(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
	else if (c != nullptr)
	{
		if (a.i != 0)
		{
			char buff[20];
			itoa(a.i, buff, 10);
			if (strlen(c) >= strlen(buff))
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			char buff[20];
			itoa(a.d, buff, 10);
			if (strlen(c) >= strlen(buff))
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (strlen(c) >= strlen(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
}

bool var::operator==(const var& a)
{
	if (i != 0)
	{
		if (a.i != 0)
		{
			if (i == a.i)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			if (i == a.d)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (i == atoi(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
	else if (d != 0)
	{
		if (a.i != 0)
		{
			if (d == a.i)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			if (d == a.d)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (d == atof(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
	else if (c != nullptr)
	{
		if (a.i != 0)
		{
			char buff[20];
			itoa(a.i, buff, 10);
			if (strlen(c) == strlen(buff))
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			char buff[20];
			itoa(a.d, buff, 10);
			if (strlen(c) == strlen(buff))
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (strlen(c) == strlen(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
}

bool var::operator!=(const var& a)
{
	if (i != 0)
	{
		if (a.i != 0)
		{
			if (i != a.i)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			if (i != a.d)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (i != atoi(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
	else if (d != 0)
	{
		if (a.i != 0)
		{
			if (d != a.i)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			if (d != a.d)
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (d != atof(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
	else if (c != nullptr)
	{
		if (a.i != 0)
		{
			char buff[20];
			itoa(a.i, buff, 10);
			if (strlen(c) != strlen(buff))
			{
				return true;
			}
			else
				return false;
		}
		else if (a.d != 0)
		{
			char buff[20];
			itoa(a.d, buff, 10);
			if (strlen(c) != strlen(buff))
			{
				return true;
			}
			else
				return false;
		}
		else if (a.c != nullptr)
		{
			if (strlen(c) != strlen(a.c))
			{
				return true;
			}
			else
				return false;
		}
	}
}

int main()
{

}