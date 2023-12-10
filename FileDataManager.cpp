#include "FileDataManager.h"

// Abstract class File_Data_MGM
File_Data_MGM::File_Data_MGM(std::ifstream& ifs, std::ofstream& ofs)
	:m_input(ifs), m_output(ofs)
{ }

File_Data_MGM::~File_Data_MGM()
{
	if (m_input.is_open()) m_input.close();
	if (m_output.is_open()) m_output.close();
}

// class Jsone_File_Data
Stream_Data::Stream_Data(std::ifstream& ifs, std::ofstream& ofs)
	:File_Data_MGM(ifs, ofs)
{ }

std::string Stream_Data::get_username()
{
	m_input.ignore(Maximum_size, Separator_character);
	std::string username;
	m_input >> username;
	if (Username::condition_check(username) == Good)
	{
		return username;
	}
	else throw std::runtime_error("Uncorrect username!");
}

std::string Stream_Data::get_password()
{
	m_input.ignore(Maximum_size, Separator_character);
	std::string password;
	m_input >> password;
	if (Password::condition_check(password) == Good)
		return password;
	else throw std::runtime_error("Uncorrect password!");
}

int Stream_Data::get_index()
{
	m_input.ignore(Maximum_size, Separator_character);
	int index;
	m_input >> index;
	return index;
}

int Stream_Data::get_prioritety()
{
	m_input.ignore(Maximum_size, Separator_character);
	char prioritety;
	m_input >> prioritety;
		return prioritety;
	
}

bool Stream_Data::write_user_data(std::shared_ptr<User> user)
{
	m_output << Beginning_character <<" username" << Separator_character << ' ' << user->show_username() <<
		" password" << Separator_character << ' ' << user->show_password() <<
		" index" << Separator_character << ' ' << user->return_index() <<
		" prioritety" << Separator_character << ' ' << user->priority_access() << Ending_character << std::endl;

	return (m_output) ? true : false;
}

