#ifndef IMPLEMENT_H
#define IMPLEMENT_H

#include <string>
#include <vector>

using Paras = std::vector<std::string>;

// local folder
void implement_root(const int index, const Paras& paras);
void implement_code(const int index, const Paras& paras);
void implement_downloads(const int index, const Paras& paras);

// online website
void implement_google(const int index, const Paras& paras);
void implement_zhihu(const int index, const Paras& paras);
void implement_bilibili(const int index, const Paras& paras);
void implement_github(const int index, const Paras& paras);
void implement_leetcode(const int index, const Paras& paras);

// control
void implement_list(const int index, const Paras& paras);

#endif
