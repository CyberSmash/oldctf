#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <cstdlib>
#include <cstdint>
#include <unistd.h>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
#define SLEEP_TIME 200
#define FLAG_FILE "./flag2"

/**
 * Load up our flag.
 *
 * @return - The flag from our flag file.
 */
string read_flag()
{
	std::ifstream file(FLAG_FILE);
	assert(file.is_open());
	string flag;
	std::getline(file, flag);
	return flag;
}

/**
 * Randomly generate a password.
 *
 * Print a user-friendly message as well.
 *
 */
uint64_t generate_password(int length, int random_seed)
{
	srand(random_seed);
	int val = 0;
	uint64_t password = 1;

	for (int i = 0; i < length; i++)
	{
		char val = (rand() % 26) + 'a';
		password *= val;
	}
	
	return password;
}

uint64_t calc_password(string password)
{
	uint64_t val = 1;
	for (int i = 0; i < password.length(); i++)
	{
		val *= password[i];
	}
	return val;

}

/**
 * Just main.
 */
int main()
{

	alarm(30);
	uint64_t password;
	string user_guess;
	string user_name;
	int seed = time(NULL);
	
	printf("What is your name?\n> ");
	std::getline(cin, user_name);

	printf("OK %s Calculating a random password. Please be patient.\n", user_name.c_str());
	password = generate_password(12, seed);
	
	printf("Encrypted Password: %llu password\n", password);
	printf(user_name.c_str(), 12);
	printf("Enter the password \n> ");
	std::getline(cin, user_guess);

	uint64_t guess = calc_password(user_guess);

	if (guess == password)
	{
		string flag = read_flag();
		printf("Success!\n");
		printf("Flag: %s\n", flag.c_str());
	}
	else
	{
		printf("Failure!\n");
	}

	return 0;
}
