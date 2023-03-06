#include "CppUTest/CommandLineTestRunner.h"

auto main(int ac, char** av) -> int
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
