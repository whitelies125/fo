#include <algorithm>
#include <iostream>
#include <ranges>

#include "register.h"

int main(int argc, char* argv[])
{
    if (argc == 1) {
        std::cout << "no arguments. input \"list\" to show all command." << std::endl;
        return 1;
    }
    const auto argv_range = std::ranges::subrange(argv, argv + argc);
    const auto paras = argv_range | std::views::transform([](const char* arg) { return std::string(arg); })
                                  | std::ranges::to<Paras>();
    auto condition = [&argv](const auto& it) { return it.match_name.starts_with(argv[1]); };
    if (const auto res = std::ranges::find_if(g_item, condition); res != std::end(g_item)) {
        res->callback(*res, paras);
        return 0;
    }
    std::cout << "no match. input \"list\" to show all command." << std::endl;
    return 1;
}
