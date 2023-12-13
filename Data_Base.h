#pragma once
#include <vector>
#include <fstream>
#include "FileDataManager.h"

class Users_Manager
{
public:
	Users_Manager() = default;
	virtual ~Users_Manager() = default;
public:
	virtual std::shared_ptr<User> find(const std::string&) = 0;
	virtual void add_user(std::shared_ptr<User>) = 0;
	virtual std::shared_ptr<User> get_last() = 0;
	
	
};

class Container_User_Manager : public Users_Manager
{
public:
	Container_User_Manager() = default;
	~Container_User_Manager() = default;
public:
	std::shared_ptr<User> find(const std::string&) override;
	void add_user(std::shared_ptr<User>) override;
	std::shared_ptr<User> get_last() override { return (!m_database.empty()) ? m_database[m_database.size() - 1] : nullptr; }
	
private:
	std::vector<std::shared_ptr<User>> m_database;
};

class Json_Data_Manager : public Users_Manager
{
public:
	Json_Data_Manager() = default;
	~Json_Data_Manager();
public:
	bool Data_include(const std::string&);
	std::shared_ptr<User> find(const std::string&) override;
	void add_user(std::shared_ptr<User>) override;
	std::shared_ptr<User> get_last() override;
private:
	std::fstream m_stream;
};