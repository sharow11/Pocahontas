#include <stdio.h>
#include <gmpxx.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string convertOutput(mpf_class x, int d)
{
	ostringstream ss;
    	ss << fixed;
	ss << setprecision(d);
	ss << x;
	string str = ss.str();
	string strFormat = str.substr(0, str.find_last_not_of('0') + 1);
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
	cout << "Precyzja \n";
	double bits_per_digit = 3.32192809488736234789;
	mpf_set_default_prec((100+d)*bits_per_digit + 1);
	mpz_class x;
	x = 0;
	mpf_class sum;	
	sum = 0;

	string strX;

	while(cin >> strX)
	{
		x = strX;
		sum += x;
		n++;
	}
	cout << n << "\n";
	mpf_class avg;
	avg = sum / n;
	cout.setf(std::ios_base::fixed);
	cout << convertOutput(avg, d) << "\n";
	return 0;
}