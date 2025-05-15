#ifndef IMPLEMENT_H
#define IMPLEMENT_H

#include <string>
#include <vector>

using Paras = std::vector<std::string>;
struct Item;
using Func = void (*)(const Item &item, const Paras& paras);
struct Item {
    std::string_view match_name;
    Func callback;
    std::string_view windows_name;
};


// local folder
void implement_root(const Item &item, const Paras& paras);
void implement_code(const Item &item, const Paras& paras);
void implement_downloads(const Item &item, const Paras& paras);

// online website
void implement_google(const Item &item, const Paras& paras);
void implement_zhihu(const Item &item, const Paras& paras);
void implement_bilibili(const Item &item, const Paras& paras);
void implement_github(const Item &item, const Paras& paras);
void implement_leetcode(const Item &item, const Paras& paras);

// control
void implement_list(const Item &item, const Paras& paras);

#endif
