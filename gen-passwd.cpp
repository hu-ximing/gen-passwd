// gen-passwd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <cctype>
#include <iostream>
#include <random>
#include <string>

using namespace std;

std::random_device rd;
std::mt19937_64 mt(rd());
std::uniform_int_distribution<int> dist(33, 126);

bool validate(string p)
{
	return any_of(p.begin(), p.end(), [](int i)
				  { return isupper(i); }) &&
		   any_of(p.begin(), p.end(), [](int i)
				  { return islower(i); }) &&
		   any_of(p.begin(), p.end(), [](int i)
				  { return isdigit(i); }) &&
		   any_of(p.begin(), p.end(), [](int i)
				  { return ispunct(i); });
}

string gen_password(int len)
{
	string p(len, 0);
	int max_attempt = 1024;
	for (int ct = 0; ct < max_attempt; ct++)
	{
		generate(p.begin(), p.end(), []()
				 { return dist(mt); });
		if (validate(p))
		{
			return p;
		}
	}
	return "Failed to generate password. max_attempt: " + to_string(max_attempt);
}

int main(int argc, char **argv)
{
	int len;
	len = (argc == 1) ? 18 : atoi(argv[1]);

	cout << gen_password(len) << '\n';
}
