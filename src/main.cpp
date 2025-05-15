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
    Paras paras;
    for (int i {2}; i < argc; ++i) paras.push_back(argv[i]);
    const auto view = g_item | std::views::all;
    auto condition = [&argv](const auto& it) { return it.match_name.starts_with(argv[1]); };
    if (const auto res = std::ranges::find_if(view, condition); res != view.end()) {
        res->callback(*res, paras);
        return 0;
    }
    std::cout << "no match. input \"list\" to show all command." << std::endl;
    return 1;
}
