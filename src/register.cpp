#include "register.h"

const std::map<const std::string, Func> g_cmd {
    // local folder
    {"code", implement_code},
    {"markdown", implement_markdown},
    {"downloads", implement_downloads},
    {"ygopro", implement_ygopro},

    // online website
    {"google", implement_google},
    {"zhihu", implement_zhihu},
    {"bilibili", implement_bilibili},

    // help
    {"list", implement_list},
};