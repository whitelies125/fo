#include "implement.h"

#include <iostream>

#include "register.h"

// local folder
bool implement_code(){
    system("explorer e:\\code");
    return true;
}
bool implement_markdown(){
    system("explorer e:\\my_markdown");
    return true;
}
bool implement_downloads(){
    system("explorer e:\\downloads");
    return true;
}
bool implement_ygopro(){
    system("explorer e:\\ygopro");
    return true;
}

// online website
bool implement_zhihu(){
    system("chrome https://www.zhihu.com/");
    return true;
}
bool implement_bilibili(){
    system("chrome https://www.bilibili.com/");
    return true;
}

// control
bool implement_quit(){
    return true;
}

bool implement_list(){
    std::cout << "all command:" << std::endl;
    for (const auto &[key, func] : g_cmd_register) {
        std::cout << key << std::endl;
    }
    return false;
}