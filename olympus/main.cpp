#include <stdafx.h>

int main(int argc, char** argv)
{
    std::puts(oly::String{"olympus"}.data());

    oly::Array arr{ 1, 2, 3, 4, 5 };
    oly::Vector vec{ 1, 2, 3, 4, 5 };

    return 0;
}