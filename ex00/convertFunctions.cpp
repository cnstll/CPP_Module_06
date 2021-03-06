#include "convert.hpp"
#include <iomanip>

void  convertToChar(const char *arg, const std::string &type){

    char c;
    double converted;

    if (type.compare("non displayable") == 0)
    {
        printConversionNonDisplayble("char");
        return ;
    }
    else if (type.compare("impossible") == 0 || type.compare("literal f") == 0 || type.compare("literal d") == 0)
    {
        printConversionImpossible("char");
        return ;
    }
    else if (type.compare("char") == 0)
    {
        printConversionLine("char"); 
        std::cout << arg[0] << std::endl;
        return ;
    }
    else
    {
        converted = strtod(arg, NULL);
        c = static_cast<char>(converted);
    }
    if (securedIsPrint(c) && converted <= 127 && converted >= 0)
    {
        printConversionLine("char"); 
        std::cout << c << std::endl;
    }
    else if (converted > 127 || converted < 0)
        printConversionImpossible("char");
    else
        printConversionNonDisplayble("char");
};

void convertToInt(const char *arg, const std::string &type){

    int i;
    std::string argStr = arg;
    if (type.compare("char") == 0 && argStr.size() == 1)
    {
        i = static_cast<int>(arg[0]);
        printConversionLine("int"); 
        std::cout << i << std::endl;
        return ;
    }
    double converted;
    converted = strtod(arg, NULL);
    if (!isInIntRange(converted))
        printConversionImpossible("int");
    else if (type.compare("literal f") == 0 || type.compare("literal d") == 0)
        printConversionImpossible("int");
    else
    {
        i = static_cast<int>(converted);
        printConversionLine("int"); 
        std::cout << i << std::endl;
    }
};

void convertToFloat(const char *arg, const std::string &type){

    float f;
    std::string argStr = arg;
    if (type.compare("char") == 0 && argStr.size() == 1)
    {
        f = static_cast<float>(arg[0]);
        printConversionLine("float"); 
        std::cout << std::fixed << std::setprecision(2) << f << "f" << std::endl;
        return ;
    }
    double converted = strtod(arg, NULL);
    if (!isInFloatRange(converted) && type.compare("literal f") != 0 && type.compare("literal d") != 0)
        printConversionImpossible("float");
    else
    {
        f = static_cast<float>(converted);
        printConversionLine("float"); 
        std::cout << std::fixed << std::setprecision(2) << f << "f" << std::endl;
    }
};

void convertToDouble(const char *arg, const std::string &type){

    double d;
    std::string argStr = arg;
    if (type.compare("char") == 0 && argStr.size() == 1)
    {
        d = static_cast<double>(arg[0]);
        printConversionLine("double"); 
        std::cout << std::fixed << std::setprecision(2) << d << std::endl;
        return ;
    }
    double converted = strtod(arg, NULL);
    if (errno == ERANGE)
        printConversionImpossible("double");
    else
    {
        d = static_cast<double>(converted);
        printConversionLine("double"); 
        std::cout << std::fixed << std::setprecision(2) << d << std::endl;

    }
};