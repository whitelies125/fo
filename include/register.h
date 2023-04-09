#ifndef REGISTER_H
#define REGISTER_H

#include <map>

#include "implement.h"

using Func= void (*)(Paras& paras);

extern std::map<std::string, Func> g_cmd;

#endif