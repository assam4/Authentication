#include "Application.h"

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
