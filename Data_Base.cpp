#include "Data_Base.h"

// Container_Data methods

std::shared_ptr<User> Container_User_Manager::find(const std::string& username)
{
	for (auto& account : m_database)
		if (account->show_username() == username)
			return account;
	return nullptr;
}

bool Container_User_Manager::unique_username(const std::string& username)
{
	for (const auto& account : m_database)
		if (account->show_username() == username)
			return false;
	return true;
}

void Container_User_Manager::adding_user(const std::shared_ptr<User> new_user)
{
	m_database.push_back(new_user);
}

// File_Data_Base methods

Filestream_User_Manager::Filestream_User_Manager(std::ifstream& ifs, std::ofstream& ofs)
	: m_stream(ifs, ofs)
{ }

std::shared_ptr<User> Filestream_User_Manager::find(const std::string& username)
{
	std::string n;
	m_stream.ignoring();
	while (true)
	{
		n = m_stream.get_username();
		if (n == username) break;
		m_stream.ignoring();
		if (m_stream.Eofbit()) return nullptr;
	}
	auto name = Username::username_creater(n);
	auto password = Password::password_creater(m_stream.get_password());
	int index = m_stream.get_index();
	char pri = m_stream.get_prioritety();
	return  std::make_shared<User>(name, password, index, pri);
}

bool Filestream_User_Manager::unique_username(const std::string& name)
{
	std::string name_space;
	while (true)
	{
		name_space = m_stream.get_username();
		if (name == name_space) return false;
		m_stream.ignoring();
		if (m_stream.Eofbit()) return true;
	}
}
