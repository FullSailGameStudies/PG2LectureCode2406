#include "MenuPrinter.h"

void MenuPrinter::PrintMenu(const std::vector<std::string>& menu,
    const std::vector<float>& prices) const
{
    //NonConst();
    int localData;
    localData = 10;
    //someData_ = 109;
    std::cout << "\nGreedy's\n";
    for (size_t i = 0; i < menu.size(); i++)
    {
        std::cout << menu[i] << " " << prices[i] << "\n";
    }
}