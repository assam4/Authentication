#pragma once
#include "User.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;


class Json_Formating
{
public:
	static json to_format(std::shared_ptr<User>);
	static std::shared_ptr<User> from_format(const json&);
	Json_Formating() = delete;
};