#ifndef IMPLEMENT_H
#define IMPLEMENT_H

#include <string>
#include <vector>

using Paras = std::vector<std::string>;

// local folder
void implement_code(const Paras& paras);
void implement_markdown(const Paras& paras);
void implement_downloads(const Paras& paras);
void implement_ygopro(const Paras& paras);

// online website
void implement_google(const Paras& paras);
void implement_zhihu(const Paras& paras);
void implement_bilibili(const Paras& paras);

// control
void implement_quit(const Paras& paras);
void implement_list(const Paras& paras);

#endif