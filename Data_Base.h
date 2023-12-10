#pragma once
#include <vector>
#include "FileDataManager.h"

class User_Manager
{
public:
	User_Manager() = default;
	virtual ~User_Manager() = default;
public:
	virtual std::shared_ptr<User> find(const std::string&) = 0;
	virtual bool unique_username(const std::string&)  = 0 ;
	virtual void adding_user(const std::shared_ptr<User>) = 0;

};

class Container_User_Manager : public User_Manager
{
public: 
	Container_User_Manager() = default;
	~Container_User_Manager() = default;
public:
	std::shared_ptr<User> find(const std::string&) override;
	bool unique_username(const std::string&) override;
	void adding_user(const std::shared_ptr<User>) override;
private:
	std::vector<std::shared_ptr<User>> m_database;
};

class Filestream_User_Manager : public User_Manager
{
public:
	Filestream_User_Manager(std::ifstream& ,std::ofstream&);
	~Filestream_User_Manager() = default;
public:
	std::shared_ptr<User> find(const std::string&) override;
	bool unique_username(const std::string&)  override;
	void adding_user(const std::shared_ptr<User> new_user) override
	{
		m_stream.write_user_data(new_user);
	}
private:
	Stream_Data m_stream;
};
