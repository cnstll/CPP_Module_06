#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (EXIT_FAILURE);
    float f = atof(argv[1]);
    std::cout << f << std::endl; 
    return (EXIT_SUCCESS);
}