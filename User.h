#pragma once
#include "User_data.h"

class User
{
public:
	User(std::shared_ptr<Username>, std::shared_ptr<Password>, int, char pri);
	std::string show_username() const;
	std::string show_password() const;
	bool change_username(const std::string&);
	bool change_password(const std::string&);
	inline int return_index() const { return m_index; }
	inline bool on_off() noexcept { return (m_ison = !m_ison); }
	inline bool is_signed() noexcept { return m_ison; }
	inline char priority_access() const { return m_prioritety; }

private:
	std::shared_ptr<Username> m_username;
	std::shared_ptr<Password> m_password;
	const int m_index;
	char m_prioritety;
	bool m_ison;
};