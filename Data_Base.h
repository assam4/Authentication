#pragma once
#include <vector>
#include "FileDataManager.h"

class Users_Manager
{
public:
	Users_Manager() = default;
	virtual ~Users_Manager() = default;
public:
	virtual std::shared_ptr<User> find(const std::string&) = 0;
	virtual void add_user(std::shared_ptr<User>) = 0;
	
};

class Container_User_Manager : public Users_Manager
{
public:
	Container_User_Manager() = default;
	~Container_User_Manager() = default;
public:
	std::shared_ptr<User> find(const std::string&) override;
	void add_user(std::shared_ptr<User>) override;
private:
	std::vector<std::shared_ptr<User>> m_database;
};
