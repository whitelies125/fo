#ifndef REGISTER_H
#define REGISTER_H

#include <map>

#include "implement.h"

using Func= void (*)(const Paras& paras);

struct Item {
    std::string match_name;
    Func callback;
    std::string windows_name;
};

const Item g_item [] = {
    // local folder
    {"code", implement_code, "Code"},
    {"markdown", implement_markdown, "my_markdown"},
    {"downloads", implement_downloads, "Downloads"},
    {"ygopro", implement_ygopro, "YGOPro"},

    // online website
    {"google", implement_google, ""},
    {"zhihu", implement_zhihu, ""},
    {"bilibili", implement_bilibili, ""},
    {"github", implement_github, ""},

    // help
    {"list", implement_list, ""},
};

#endif
