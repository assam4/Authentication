#include "Data_Base.h"

// class Container_Data_Manager methods

std::shared_ptr<User> Container_User_Manager::find(const std::string& name)
{
	if (!m_database.empty())
	for (auto& another_user : m_database)
		if (another_user->show_username() == name) return another_user;
	return nullptr;
}
void Container_User_Manager::add_user(std::shared_ptr<User> new_user)
{
	m_database.push_back(new_user);
}
