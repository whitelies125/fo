#ifndef REGISTER_H
#define REGISTER_H

#include "implement.h"

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
    {"leetcode", implement_leetcode, ""},

    // help
    {"list", implement_list, ""},
};

#endif
