#include "implement.h"

#include <cstdlib>
#include <iostream>
#include <numeric>

#include "register.h"

// local folder
void implement_code(const Paras& paras) { system("explorer e:\\code"); }
void implement_markdown(const Paras& paras) { system("explorer e:\\my_markdown"); }
void implement_downloads(const Paras& paras) { system("explorer e:\\downloads"); }
void implement_ygopro(const Paras& paras) { system("explorer e:\\ygopro"); }

// online website
static void implement_online_website(const Paras& paras, const std::string& defalt,
                                     const std::string& prefix, const std::string& suffix = "\"")
{
    std::string cmd {""};
    std::string browser {"chrome"};
    if (paras.size() <= 1) {
        cmd = browser + " " + defalt;
        system(cmd.c_str());
        return;
    }

    cmd = browser + " " +
          std::accumulate(
              std::next(paras.begin()), paras.end(), prefix,
              [](std::string prefix, std::string it) { return std::move(prefix) + it + " "; });
    cmd += suffix;
    system(cmd.c_str());
}
void implement_google(const Paras& paras)
{
    std::string defalt {"https://www.google.com/"};
    std::string prefix {"\"https://www.google.com/search?q="};
    implement_online_website(paras, defalt, prefix);
}
void implement_zhihu(const Paras& paras)
{
    std::string defalt {"https://www.zhihu.com/"};
    std::string prefix {"\"https://www.zhihu.com/search?type=content&q="};
    implement_online_website(paras, defalt, prefix);
}
void implement_bilibili(const Paras& paras)
{
    std::string defalt {"https://www.bilibili.com/"};
    std::string prefix {"\"https://search.bilibili.com/all?keyword="};
    implement_online_website(paras, defalt, prefix);
}

void implement_github(const Paras& paras)
{
    std::string defalt {"https://github.com/whitelies125"};
    std::string prefix {"\"https://github.com/search?q="};
    std::string suffix {"&type=repositories\""};
    implement_online_website(paras, defalt, prefix, suffix);
}

// help
void implement_list(const Paras& paras)
{
    std::cout << "all command:" << std::endl;
    for (const auto& [match_name, callback, windows_name] : g_item) {
        std::cout << match_name << std::endl;
    }
}
