#ifndef REGISTER_H
#define REGISTER_H

#include <map>

#include "implement.h"

using Func= void (*)(const Paras& paras);

extern const std::map<const std::string, Func> g_cmd;

#endif