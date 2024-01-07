#include <cstdlib>
#include <exception>
#include <iostream>

void TestIoArHandler();
void TestScXml();

int main(int, const char**)
{
    try
    {
        TestIoArHandler();
        TestScXml();
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
