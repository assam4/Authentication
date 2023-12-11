#include "FileDataManager.h"

// json formating methods

json Json_Formating::to_format(std::shared_ptr<User> user)
{
    json user_json;
    user_json["username"] = user->show_username(); 
    user_json["password"] = user->show_password();
    user_json["index"] = user->return_index();
    user_json["priority"] = user->priority_access();
    return user_json;
}
std::shared_ptr<User> Json_Formating::from_format(const json& user_state)
{
    auto username = Username::username_creater(user_state["username"]);
    auto password = Password::password_creater(user_state["password"]);
    int index = user_state["index"].get<int>();
    int priority = user_state["priority"].get<int>();
    char priority_char = static_cast<char>(priority);
    return std::make_shared<User>(username,password,index,priority_char);
}
