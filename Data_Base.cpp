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

// class Json_User_Manager
bool Json_Data_Manager::Data_include(const std::string& filename)
{
	m_stream.open(filename, std::ios::in | std::ios::out | std::ios::app);
	return m_stream.is_open();
}

Json_Data_Manager::~Json_Data_Manager()
{
	if (m_stream.is_open()) m_stream.close();
}

std::shared_ptr<User> Json_Data_Manager::find(const std::string& name) {
    json another_user;
    m_stream.seekg(Start);

        while (m_stream >> another_user) 
        {
            m_stream.ignore(Ignore_size, Beginning_character);
            if (m_stream.eof())
                break;
            if (another_user.contains("username") && another_user["username"] == name) 
                return Json_Formating::from_format(another_user);
        }
 
    return nullptr;
}


void Json_Data_Manager::add_user(std::shared_ptr<User> new_user)
{
	m_stream.seekp(0, std::ios_base::end);
	m_stream << Json_Formating::to_format(new_user) << std::endl;
}

