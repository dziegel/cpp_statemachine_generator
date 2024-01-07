#include <exception>
#include <iostream>

#include "ScXmlFsmImpl.hxx"
#include "XmiFsmImpl.hxx"

int main(int /*unused*/, const char** /*unused*/)
{
    try
    {
        XmiFsmImpl xmi;
        xmi.Test();

        ScXmlFsmImpl scxml;
        scxml.Test();
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
