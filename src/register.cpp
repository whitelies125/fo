#include "register.h"

std::unordered_map<std::string, func_ptr> g_cmd_register{
    // local folder
    {"code", implement_code},
    {"markdown", implement_markdown},
    {"downloads", implement_downloads},
    {"ygopro", implement_ygopro},

    // online website
    {"zhihu", implement_zhihu},
    {"bilibili", implement_bilibili},

    // control
    {"quit", implement_quit},
    {"list", implement_list},
};