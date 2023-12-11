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

