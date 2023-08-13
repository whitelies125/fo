#include <Windows.h>

#include <codecvt>
#include <iostream>
#include <locale>

#include "register.h"

static bool isWindosExist(const std::string &windows_name)
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

static bool execute_cmd(const Paras &paras)
{
    if (paras.empty()) return false;

    for (const auto &[match_name, callback, windows_name] : g_item) {
        if (match_name.starts_with(paras[0]) && !isWindosExist(windows_name)) {
            callback(paras);
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    if (argc == 1) {
        std::cout << "no arguments. input \"list\" to show all command." << std::endl;
        return 0;
    }
    Paras paras;
    for (int i {1}; i < argc; ++i) paras.push_back(argv[i]);
    if (!execute_cmd(paras)) {
        std::cout << "no matched. input \"list\" to show all command." << std::endl;
    }
    return 0;
}
