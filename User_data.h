#pragma once
#include <string>
#include <memory>
#include "Constants.h"

class User_data_type
{
public:
	inline bool data_match(const std::string& example) noexcept { return (m_data == example); }
	inline std::string show() const noexcept { return m_data; }
	virtual ~User_data_type() = default;
	bool change(const std::string&, int (*)(const std::string&));
public:
	User_data_type(const std::string& ud) noexcept: m_data(ud)
	{ }
private:
	std::string m_data;
};

class Password : public User_data_type
{
	public:
		static std::shared_ptr<Password> password_creater(const std::string&);
		static int condition_check(const std::string&)noexcept;
		~Password() override = default;
	private:
		Password(const std::string& pw) noexcept :User_data_type(pw)
		{ }
};

class Username : public User_data_type
{
	public:
		static std::shared_ptr<Username> username_creater(const std::string&) ;
		static int condition_check(const std::string&)noexcept;
		~Username() = default;
	private:
		Username(const std::string& un) noexcept :User_data_type(un)
		{ }
};



