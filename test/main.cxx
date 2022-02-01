#include <cstdlib>
#include <exception>
#include <iostream>

void TestIoArHandler();

int main(int, const char**)
{
    try
    {
        TestIoArHandler();
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
