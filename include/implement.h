#ifndef IMPLEMENT_H
#define IMPLEMENT_H

#include <string>
#include <vector>

using Paras = std::vector<std::string>;

// local folder
void implement_code(Paras& paras);
void implement_markdown(Paras& paras);
void implement_downloads(Paras& paras);
void implement_ygopro(Paras& paras);

// online website
void implement_google(Paras& paras);
void implement_zhihu(Paras& paras);
void implement_bilibili(Paras& paras);

// control
void implement_quit(Paras& paras);
void implement_list(Paras& paras);

#endif