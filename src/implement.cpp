#include "implement.h"

#include <iostream>
#include <cstdlib>
#include <numeric>

#include "register.h"

// local folder
void implement_code(Paras& paras) {
    system("explorer e:\\code");
}
void implement_markdown(Paras& paras) {
    system("explorer e:\\my_markdown");
}
void implement_downloads(Paras& paras) {
    system("explorer e:\\downloads");
}
void implement_ygopro(Paras& paras) {
    system("explorer e:\\ygopro");
}

// online website
static void implement_online_website(const std::string& defalt, std::string& prefix,
                              Paras& paras) {
    if (paras.size() <= 1) {
        system(defalt.c_str());
        return;
    }

    std::string cmd = std::accumulate(std::next(paras.begin()), paras.end(), prefix,
        [](std::string prefix, std::string it) {
            return std::move(prefix) + it + " ";
        });
    *cmd.rbegin() = '\"';
    system(cmd.c_str());
}
void implement_google(Paras& paras) {
    std::string defalt {"chrome https://www.google.com/"};
    std::string prefix {"chrome \"https://www.google.com/search?q="};
    implement_online_website(defalt, prefix, paras);
}
void implement_zhihu(Paras &paras) {
    std::string defalt {"chrome https://www.zhihu.com/"};
    std::string prefix {"chrome \"https://www.zhihu.com/search?type=content&q="};
    implement_online_website(defalt, prefix, paras);
}
void implement_bilibili(Paras& paras) {
    std::string defalt {"chrome https://www.bilibili.com/"};
    std::string prefix {"chrome \"https://search.bilibili.com/all?keyword="};
    implement_online_website(defalt, prefix, paras);
}

// help
void implement_list(Paras& paras) {
    std::cout << "all command:" << std::endl;
    for (const auto& [key, func] : g_cmd) {
        std::cout << key << std::endl;
    }
}