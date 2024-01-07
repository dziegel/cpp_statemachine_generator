#include <cstdlib>
#include <exception>
#include <iostream>

#include "ScXmlFsmImpl.hxx"
#include "XmiFsmImpl.hxx"

void TestIoArHandler();

int main(int, const char**)
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
        std::cout << ex.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
