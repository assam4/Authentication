#pragma once
#include "User.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;


class Json_Formating
{
public:
	json to_format(std::shared_ptr<User>);
	std::shared_ptr<User> from_format(const json&);
};