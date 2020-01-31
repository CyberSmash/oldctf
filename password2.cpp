#include <iostream>
#include <fstream>
#include <string>
#include <thread>
using std::cout;
using std::cin;
using std::endl;
using std::string;
#define SLEEP_TIME 200
#define FLAG_FILE "./flag"

/**
 * Check the password of the user.
 *
 * UPDATE: I got tired of people attempting to DOS the server 
 * so I added a delay to slow them down.
 *
 * @param password - The user supplied password.
 * @param flag - The flag. ;)
 * 
 * @return - True if the strings match. False otherwise.
 */
bool check_password(string password, string flag)
{
	if (password.length() == 0)
	{
		return false;
	}
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] != flag[i])
		{
			return false;
		}
		
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
	}
	if (password.length() != flag.length())
	{
		return false;
	}
	return true;
}

/**
 * Load up our flag.
 *
 * @return - The flag from our flag file.
 */
string read_flag()
{
	std::ifstream file(FLAG_FILE);
	string flag;
	std::getline(file, flag);
	return flag;
}

/**
 * Just main.
 */
int main()
{
	string flag = read_flag();
	cout << "Flag: " << flag << endl;
	cout << "What's the password?" << endl;
	cout << "> ";
	string user_guess;
	std::getline(cin, user_guess);
	if (check_password(user_guess, flag))
	{
		cout << "You have the password now. I don't need to tell it to you." << endl;
	}
	else
	{
		cout << "Keep Trying, fool." << endl;
	}

	return 0;
}
