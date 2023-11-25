#include <iostream>

#include "register.h"

int main(int argc, char *argv[])
{
    if (argc == 1) {
        std::cout << "no arguments. input \"list\" to show all command." << std::endl;
        return 1;
    }
    bool matched {false};
    for (int index = 0; index < sizeof(g_item) / sizeof(g_item[0]); ++index) {
        if (g_item[index].match_name.starts_with(argv[1])) {
            matched = true;
            Paras paras;
            for (int i {2}; i < argc; ++i) paras.push_back(argv[i]);
            g_item[index].callback(index, paras);
            return 0;
        }
    }
    if (!matched) {
        std::cout << "no match. input \"list\" to show all command." << std::endl;
        return 1;
    }
    return 0;
}
