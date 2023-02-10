#include <iostream>
#include <string>
#include <cstdlib>

#include "register.h"

static bool find_and_execute_cmd(const std::string& input){
    if(input.empty()) return false;
    for(const auto& [cmd, func] : g_cmd_register){
        if(cmd.starts_with(input)){
            return func();
        }
    }
    return false;
}

int main(int argc, char* argv[]){
    // currently, I only implement argc == 2 case;
    std::string input {""};
    bool res {false};
    if(argc == 2){
        input = argv[1];
        res = find_and_execute_cmd(input);
    }
    while(!res){
        std::cout <<  "input again(\"list\" for all cmd): ";
        getline(std::cin, input);
        res = find_and_execute_cmd(input);
        std::cout << std::endl;
    }
    return 0;
}