#include "Application.h"

// Authorization 

bool Authorization::check_password(const std::string& password)const
{
	if (m_account == nullptr)  return false;
	return (m_account->show_password() == password) ? m_account->on_off() : false;
}

bool Authorization::forgot_password(const std::string& password)
{
	return m_account->change_password(password);
}

bool Authorization::logout() noexcept
{
	if (m_account == nullptr) 
		return false;
	else
	{
		m_account->on_off();
		m_account = nullptr;
		return true;
	}
}

bool Authorization::authorization(const std::string& username, Users_Manager* Server)
{
	m_account = Server->find(username);
	return (m_account != nullptr);
}

// Registration

bool Registration::username_check(const std::string& name)
{
	if (Username::condition_check(name))
	{
		m_name = name;
		return true;
	}
	else return false;
}

bool Registration::password_check(const std::string& password)
{
	if (Password::condition_check(password))
	{
		m_password = password;
		return true;
	}
	else return false;
}

std::shared_ptr<User> Registration::add_newuser() const
{
	return std::make_shared<User>(Username::username_creater(m_name), Password::password_creater(m_password), m_index,Simple_user);
}

void Registration::set_index(Users_Manager* server)
{
		auto last_user = server->get_last();
		if (last_user != nullptr)
			m_index = last_user->return_index() + 1;
		else 
			m_index = 1;
}


