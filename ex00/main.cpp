#include "convert.hpp"

void doConversion(const char *arg, const std::string &type) {
    convertToChar(arg, type);
    convertToInt(arg, type);
    convertToFloat(arg, type);
    convertToDouble(arg, type);

}

bool isValidInput(const int &nbArgs, char **argList)
{
    if (nbArgs > 2)
    {
        std::cerr << "Error: too many arguments\n";
        return (false);
    }
    else if (nbArgs <= 1)
    {
        std::cerr << "Error: too few arguments\n";
        return (false);
    }
    else if (argList[1][0] == '\0')
    {
        std::cerr << "Error: input is empty\n";
        return (false);
    }
    else
        return (true);
}

int main(int argc, char *argv[]){

    const std::string::size_type nbAvailableTypes = 10;
    const std::string::size_type nbDisplayTypes = 5;
    const int indexErrors = 7;
    std::string argType;
    std::string availableTypes[nbAvailableTypes] = {"char", "integer", "float", "double", "literal f", "literal d", "non displayable", "empty", "impossible", ""};
    std::string displayTypes[nbDisplayTypes] = {"char", "integer", "float", "double", ""};

    if (!isValidInput(argc, argv))
        return (EXIT_FAILURE);
    argType = parseType(argv[1]);
    int i = 0;
    while (!availableTypes[i].empty() && availableTypes[i].compare(argType) != 0)
        i++;
    if (i == nbAvailableTypes - 1)
    {
        std::cerr << "ERROR: type not found" << std::endl;
        return (EXIT_FAILURE);
    }
    else if (i >= indexErrors) 
    {
        for (std::string::size_type i = 0; i < nbDisplayTypes - 1; i++)
            printConversionImpossible(displayTypes[i]);
    }
    else
        doConversion(argv[1], argType);
    return (EXIT_SUCCESS);
}