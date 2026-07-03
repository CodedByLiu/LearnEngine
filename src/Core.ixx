module;

#include <iostream>

export module Core;

export void printBanner()
{
    std::cout << "Hello, Engine! 这次是用 C++23 模块跑起来的。\n";
}