#include "Application.h"
#include <iostream>

void authentication(Users_Manager* data_base)
{
	std::cout << "Please enter username: ";
	std::string name;
	std::cin >> name;
	auto user_state = data_base->find(name);
	if (user_state)
	{
		std::cout << "Please enter password: " ;
		std::string pword;
		std::cin >> pword;
	    int count = Start;

		while (user_state->show_password() != pword)
		{
			++count;
			if (count == max_try) break;
			std::cin.clear();
			std::cout << "Wrong password.Try again: " ;
			std::cin.get();
			std::cin >> pword;

		}
		if (count != max_try)
			std::cout << "Authentication passed . Thanks !" << std::endl;
		else std::cout << "Try letter !" << std::endl;
	}
	else
	{
		std::cout << "User not found may be you want to create new account ?: ";
		char answer{ Cancel };
		std::cin >> answer;
		if (answer == Cancel)
			std::cout << "You can create account whereever you want. Bye!" << std::endl;
		else
			std::cout << "Lets start creating account " << std::endl;
	}
}
/*
int main()
{
	try {
		Json_Data_Manager server;
		server.Data_include("New.txt");
		authentication(&server);
		return 0;
	}
	catch (...)
	{
		std::cerr << "Undefined Error!"; exit(1);
	}
	
}
*/