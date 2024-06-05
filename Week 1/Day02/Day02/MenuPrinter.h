#pragma once
#include <vector>
#include <string>
#include <iostream>
class MenuPrinter
{
public:
    void NonConst() {}
    void PrintMenu(const std::vector<std::string>& menu,
        const std::vector<float>& prices) const;
private:
    float someData_;
};

