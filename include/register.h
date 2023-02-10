#ifndef REGISTER_H
#define REGISTER_H

#include <string>
#include <unordered_map>

#include "implement.h"

using func_ptr = bool (*)();

extern std::unordered_map<std::string, func_ptr> g_cmd_register;

#endif