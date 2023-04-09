#include <iostream>

#include "register.h"

static bool execute_cmd(Paras paras) {
    if (paras.empty()) return false;
    for (const auto& [cmd, func] : g_cmd) {
        if (cmd.starts_with(paras[0])) {
            func(paras);
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]){
    if (argc == 1) {
        std::cout << "no arguments." << std::endl;
        return 0;
    }
    Paras paras;
    for (int i {1}; i < argc; ++i) {
        paras.push_back(argv[i]);
    }
    if (!execute_cmd(paras)) {
        std::cout << "no matched, input \"list\" to show all command." << std::endl;
    }
    return 0;
}