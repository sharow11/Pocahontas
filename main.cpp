#include <stdio.h>
#include <gmpxx.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

std::string convertOutput(mpf_class x, int d)
{
	std::ostringstream ss;
    	ss << std::fixed;
	ss << std::setprecision(d);
	ss << x;
	std::string str = ss.str();
	std::string strFormat = str.substr(0, str.find_last_not_of('0') + 1);
	size_t dotPos = strFormat.find(".");
	if(dotPos == strFormat.length() - 1)
	{
		return strFormat.substr(0, dotPos);
	}
	else
	{
		return strFormat;
	}
	
}

int main(int argc, char **argv)
{

	int d, n, p;
	if(argc > 1)
	{
		d = atoi(argv[1]);
	}
	else
	{
		d = 20;
        }
	double bits_per_digit = 3.32192809488736234789;
	mpf_set_default_prec((100+d)*bits_per_digit + 1);
	mpf_class x;
	x = 0;
	mpf_class sum;	
	sum = 0;
	mpf_class sumPwr;
	sumPwr = 0;

	std::string strX;

	while(std::cin >> strX)
	{
		x = strX;
		sum += x;
		sumPwr += (x * x);
		n++;
	}
	std::cout << n << "\n";
	mpf_class avg;
	mpf_class var;
	avg = sum / n;
	std::cout << convertOutput(avg, d) << "\n";
	var = (sumPwr / n) - avg * avg;
	std::cout << convertOutput(var, d) << "\n";
	return 0;
}