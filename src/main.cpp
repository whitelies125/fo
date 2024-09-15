#include <iostream>

#include "register.h"

int main(int argc, char *argv[])
{
    if (argc == 1) {
        std::cout << "no arguments. input \"list\" to show all command." << std::endl;
        return 1;
    }
    Paras paras;
    for (int i {2}; i < argc; ++i) paras.push_back(argv[i]);
    bool matched {false};
    for (const auto& item : g_item) {
        if (item.match_name.starts_with(argv[1])) {
            matched = true;
            item.callback(item, paras);
            return 0;
        }
    }
    if (!matched) {
        std::cout << "no match. input \"list\" to show all command." << std::endl;
        return 1;
    }
    return 0;
}
