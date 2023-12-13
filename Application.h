#pragma once
#include "Data_Base.h"

class Authorization
{
	public:
		bool authorization(const std::string&, Users_Manager*);
		bool check_password(const std::string&) const;
		inline bool check_index(int index) const noexcept { return (m_account->return_index() == index); }
		bool forgot_password(const std::string&);
		bool logout() noexcept;
	private:
		std::shared_ptr<User> m_account;
		
};

class Registration
{
public:
	Registration():m_name(" "),m_password(" "),m_index(-1) {}
	~Registration() = default;

public:
	bool username_check(const std::string&);
	bool password_check(const std::string&);
	std::shared_ptr<User> add_newuser() const;
	void set_index(Users_Manager*);
private:
	std::string m_name;
	std::string m_password;
	int m_index;
};

