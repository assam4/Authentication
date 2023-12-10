#include "User_data.h"
#include <cctype>
#include <stdexcept>

// abstract User_data_type class methods
bool User_data_type::change(const std::string& new_data, int (*check)(const std::string&))
{
    if (!check(new_data) && m_data != new_data)
    {
        m_data = new_data;
        return true;
    }
    else return false;
}

// class Password  build function and checkings
int Password::condition_check(const std::string& example)noexcept
{
	if (Minimum_size > example.size() || example.size() > Maximum_size) 
        return Incorrect_size;
	else
	{
        bool conditions[Conditions_count]{};
        for (int index = 0; index < Conditions_count; ++index)
            conditions[index] = false;



        for (auto& letter : example)
        {
            if (islower(letter)) conditions[0] = true;
            else if (isupper(letter)) conditions[1] = true;
            else if (isdigit(letter)) conditions[2] = true;
            else conditions[3] = true;
        }

        for (int i = 0; i < Conditions_count; ++i)
            if (!conditions[i]) return Incorrect_char;
    return Good;
	}
}

std::shared_ptr<Password> Password::password_creater(const std::string& example)
{
    return (condition_check(example) == Good) ? std::shared_ptr<Password>(new Password(example)) : nullptr;
}

// class Username build function and checkings
int Username::condition_check(const std::string& example) noexcept
{
    if (example.size() > Maximum_size) 
        return Incorrect_size;
    else
    {
        bool condition = false;
        for (auto& letter : example)
        {
            if (isalpha(letter) || isdigit(letter)) condition = true;
            else return Incorrect_char;
        }
    }
    return Good;
}

std::shared_ptr<Username>  Username::username_creater(const std::string& example)
{
    return (condition_check(example) == Good) ? std::shared_ptr<Username>(new Username(example)) : nullptr;
}
