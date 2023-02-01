// gen-passwd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <cctype>
#include <iostream>
#include <random>
#include <string>
#include <unistd.h>

using std::cout;

const std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const std::string digits = "0123456789";
const std::string symbols = "!@#$%^&*()_+{}|:<>?`~-=[]\\;',./\"";

bool validate(std::string p, bool use_symbols)
{
	return std::any_of(p.begin(), p.end(), [](int i)
					   { return isupper(i); }) &&
		   std::any_of(p.begin(), p.end(), [](int i)
					   { return islower(i); }) &&
		   std::any_of(p.begin(), p.end(), [](int i)
					   { return isdigit(i); }) &&
		   !(use_symbols ^ std::any_of(p.begin(), p.end(), [](int i)
									   { return ispunct(i); }));
}

std::string gen_password(std::string &charset,
						 std::mt19937_64 &engine,
						 std::uniform_int_distribution<int> &dist,
						 int len,
						 bool use_symbols)
{
	std::string p(len, 0);
	const int max_attempt = 1024;
	for (int ct = 0; ct < max_attempt; ct++)
	{
		for (int i = 0; i < len; i++)
		{
			p[i] = charset[dist(engine)];
		}
		if (validate(p, use_symbols))
		{
			return p;
		}
	}
	cout << "Failed to generate password. max_attempt: " << max_attempt << '\n';
	return "";
}

void print_help()
{
	cout << "Usage: gen-passwd [options] [length] [count]\n"
		 << "Options:\n"
		 << "  -y  Use symbols. By default only letters and digits are included.\n"
		 << "  -h  Print this help message.\n";
}

int main(int argc, char **argv)
{
	int len = 20;
	int pw_count = 10;
	bool use_symbols = false;

	int opt;
	while ((opt = getopt(argc, argv, "yh")) != -1)
	{
		switch (opt)
		{
		case 'y':
			use_symbols = true;
			break;
		case 'h':
			print_help();
			return 0;
		case '?':
			print_help();
			return 1;
		}
	}
	for (int i = 0; optind < argc; optind++, i++)
	{
		switch (i)
		{
		case 0:
			len = atoi(argv[optind]);
			break;
		case 1:
			pw_count = atoi(argv[optind]);
			break;
		}
	}
	std::string charset;
	if (use_symbols)
	{
		charset = letters + digits + symbols;
	}
	else
	{
		charset = letters + digits;
	}
	std::random_device rd;
	std::mt19937_64 engine(rd());
	std::uniform_int_distribution<int> dist(0, charset.size() - 1);
	for (int i = 0; i < pw_count; i++)
	{
		cout << gen_password(charset, engine, dist, len, use_symbols) << '\n';
	}
	return 0;
}
