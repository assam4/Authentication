#include "User.h"
#include <stdexcept>

User::User(std::shared_ptr<Username> name, std::shared_ptr<Password> password, int index, char pri = Guest)
	:m_username(name),m_password(password),m_index(index), m_prioritety(pri), m_ison(false)
{ }

std::string User::show_username() const
{
    if (m_username != nullptr)
        return m_username->show();
    else throw std::runtime_error("Uncorrect Data !.");
}

std::string User::show_password() const
{
    if (m_password != nullptr)
        return m_password->show();
    else throw std::runtime_error("Uncorrect Data !.");
}

bool User::change_username(const std::string& new_name)
{
    return	m_username->change(new_name, Username::condition_check) ? true : false;
}

bool User::change_password(const std::string& new_password)
{
    return	m_password->change(new_password, Password::condition_check) ? true : false;
}
