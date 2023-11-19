#ifndef REGISTER_H
#define REGISTER_H

#include <map>

#include "implement.h"

using Func = void (*)(const int index, const Paras& paras);

struct Item {
    std::string match_name;
    Func callback;
    std::string windows_name;
};

const Item g_item[] = {
    // local folder
    {"root", implement_root, "root"},
    {"code", implement_code, "Code"},
    {"downloads", implement_downloads, "下载"},

    // online website
    {"google", implement_google, ""},
    {"zhihu", implement_zhihu, ""},
    {"bilibili", implement_bilibili, ""},
    {"github", implement_github, ""},

    // help
    {"list", implement_list, ""},
};

#endif
