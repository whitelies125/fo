#include "implement.h"

#include <Windows.h>

#include <codecvt>
#include <cstdlib>
#include <iostream>
#include <locale>
#include <numeric>

#include "register.h"

static void execute_cmd(const std::string& cmd)
{
    std::cout << cmd << std::endl;
    system(cmd.c_str());
}

static bool setWindosOnTop(const std::string& windows_name)
{
    if (windows_name == "") return false;
    // string 转换为 LPCWSTR
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wstr = converter.from_bytes(windows_name);
    LPCWSTR lpcwstr = wstr.c_str();

    HWND hWnd = FindWindowW(NULL, lpcwstr);
    if (hWnd != NULL) {
        SetForegroundWindow(hWnd);
        return true;
    }
    return false;
}

static void set_top_or_open_directory(const std::string str, const std::string windows_name = "")
{
    if (!setWindosOnTop(windows_name)) {
        execute_cmd("explorer " + str);
    }
}

// local folder
void implement_root(const Item &item, const Paras& paras)
{
    set_top_or_open_directory("C:\\Users\\whitelies125\\root", item.windows_name);
}
void implement_code(const Item &item, const Paras& paras)
{
    set_top_or_open_directory("C:\\Users\\whitelies125\\root\\program\\Code",
                              item.windows_name);
}
void implement_downloads(const Item &item, const Paras& paras)
{
    set_top_or_open_directory("C:\\Users\\whitelies125\\Downloads", item.windows_name);
}

// online website
static void implement_online_website(const Paras& paras, const std::string& defalt,
                                     const std::string& prefix, const std::string& suffix = "\"")
{
    std::string cmd {};
    std::string browser {"start chrome "};
    if (paras.empty()) {
        cmd = browser + defalt;
    } else {
        std::string str = std::accumulate(
            paras.begin(), paras.end(), prefix,
            [](std::string prefix, std::string it) { return std::move(prefix) + it + " "; });
        str.pop_back();
        cmd = browser + str + suffix;
    }
    execute_cmd(cmd);
}
void implement_google(const Item &item, const Paras& paras)
{
    std::string defalt {"https://www.google.com/"};
    std::string prefix {"\"https://www.google.com/search?q="};
    implement_online_website(paras, defalt, prefix);
}
void implement_zhihu(const Item &item, const Paras& paras)
{
    std::string defalt {"https://www.zhihu.com/"};
    std::string prefix {"\"https://www.zhihu.com/search?type=content&q="};
    implement_online_website(paras, defalt, prefix);
}
void implement_bilibili(const Item &item, const Paras& paras)
{
    std::string defalt {"https://www.bilibili.com/"};
    std::string prefix {"\"https://search.bilibili.com/all?keyword="};
    implement_online_website(paras, defalt, prefix);
}

void implement_github(const Item &item, const Paras& paras)
{
    std::string defalt {"https://github.com/whitelies125"};
    std::string prefix {"\"https://github.com/search?q="};
    std::string suffix {"&type=repositories\""};
    implement_online_website(paras, defalt, prefix, suffix);
}

void implement_leetcode(const Item &item, const Paras& paras)
{
    execute_cmd("start chrome https://leetcode.cn/");
}

// help
void implement_list(const Item &item, const Paras& paras)
{
    std::cout << "all command:" << std::endl;
    for (const auto& [match_name, callback, windows_name] : g_item) {
        std::cout << match_name << std::endl;
    }
    system("pause");
}
