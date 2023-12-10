#pragma once
#include <fstream>
#include "User.h"

class File_Data_MGM
{
public:
	File_Data_MGM(std::ifstream& ifs, std::ofstream& ofs);
	virtual ~File_Data_MGM();
public:
	virtual std::string get_username() = 0;
	virtual std::string get_password() = 0;
	virtual int get_index() = 0;
	virtual int get_prioritety() = 0;
	virtual bool write_user_data(std::shared_ptr<User>) = 0 ;
	virtual void ignoring() = 0;
	bool Eofbit() const { return m_input.eof(); }
protected:
	std::ifstream& m_input;
	std::ofstream& m_output;
};

class Stream_Data :public File_Data_MGM
{
public:
	Stream_Data(std::ifstream& ifs, std::ofstream& ofs);
	~Stream_Data() = default;
public:
	std::string get_username() override;
	std::string get_password() override;
	int get_index() override;
	int get_prioritety() override;
	bool write_user_data(std::shared_ptr<User>) override;
	void ignoring() override { m_input.ignore(Ignore_size, Beginning_character); }
};