#include <cstdlib>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

/*
 * The behavior of std::isspace is undefined if the argument's value is neither representable as unsigned char nor equal to EOF. 
 * To use these functions safely with plain chars (or signed chars), the argument should first be converted to unsigned char.
 */
bool securedIsSpace(char ch)
{
    return std::isspace(static_cast<unsigned char>(ch));
};

bool securedIsPrint(char ch)
{
    return std::isprint(static_cast<unsigned char>(ch));
};

bool securedIsDigit(char ch)
{
    return std::isdigit(static_cast<unsigned char>(ch));
};

bool securedIsSign(char ch)
{
    return (static_cast<unsigned char>(ch) == '-' || static_cast<unsigned char>(ch) == '+');
};

std::string::size_type findFirstNonSpaceChar(const std::string &str){

    std::string::size_type pos = 0;
    for (std::string::size_type i = 0; i < str.size(); i++){
        if (!securedIsSpace(str[i])){
            pos = i;
            break;
        }
    }
    return (pos);
};

std::string::size_type findFirstPrintableChar(const std::string &str){

    std::string::size_type pos = 0;
    for (std::string::size_type i = 0; i < str.size(); i++){
        if (!securedIsPrint(str[i])){
            pos = i;
            break;
        }
    }
    return (pos);
};

bool hasDoublePseudoLiterrals(const std::string &str, std::string::size_type begin){

    if (str.find("-inf", begin) != std::string::npos)
        return true;
    if (str.find("+inf", begin) != std::string::npos)
        return true;
    if (str.find("nan", begin) != std::string::npos)
        return true;
    return false;
};

bool hasValidDoublePseudoLiterral(const std::string &str, std::string::size_type begin){

    if (str.find("-inf", begin) == begin)
        return true;
    if (str.find("+inf", begin) == begin)
        return true;
    if (str.find("nan", begin) == begin)
        return true;
    return false;
};

bool hasFloatPseudoLiterrals(const std::string &str, std::string::size_type begin){

    if (str.find("-inff", begin) != std::string::npos)
        return true;
    if (str.find("+inff", begin) != std::string::npos)
        return true;
    if (str.find("nanf", begin) != std::string::npos)
        return true;
    return false;
};

bool hasValidFloatPseudoLiterral(const std::string &str, std::string::size_type begin){

    if (str.find("-inff", begin) == begin)
        return true;
    if (str.find("+inff", begin) == begin)
        return true;
    if (str.find("nanf", begin) == begin)
        return true;
    return false;
};

bool hasPseudoLiterrals(const std::string &str, std::string::size_type begin){

    return (hasDoublePseudoLiterrals(str, begin) || hasFloatPseudoLiterrals(str, begin));
}

bool isInIntRange(double nbr) {
    return (nbr <= static_cast<double>(std::numeric_limits<int>::max())
    && nbr >= static_cast<double>(std::numeric_limits<int>::min()));
}

bool isInFloatRange(double nbr) {
    return (nbr <= static_cast<double>(std::numeric_limits<float>::max())
    && nbr >= -static_cast<double>(std::numeric_limits<float>::max()));
}
//bool isFloatNumber(const std::string &arg){
//
//    std::string::size_type firstCharPos;
//    firstCharPos = findFirstNonSpaceChar(arg);
//    std::string::size_type pointPos;
//    pointPos = arg.find(".", 0);
//    std::string::size_type fSymbolPos;
//    fSymbolPos = arg.find("f", 0);
//    std::string::size_type endFirstSerieOfNumbersPos;
//}

std::string const parseType(const char *rawArg)
{
    std::string arg = rawArg;
    std::string::size_type i = 0;
    std::string::size_type j = 0;

    if (arg.empty())
        return "empty";
    if (arg.size() == 1)
    {
        if (securedIsPrint(arg[0]))
            return "char";
        else
            return "non displayable";
    }
    while (securedIsSpace(arg[i]) && arg[i] != ' ')
        i++;
    if (hasValidFloatPseudoLiterral(arg, i))
        return "literal f";
    if (hasValidDoublePseudoLiterral(arg, i))
        return "literal d";
    while (securedIsSign(arg[i]))
        i++;
    if (!securedIsPrint(arg[i]) || !securedIsDigit(arg[i]))
    {
        std::cout << arg[i] << std::endl;
        return "impossible";
    }
    while (securedIsDigit(arg[i]))
        i++;
    if (arg[i] != '.')
        return "integer";
    j = i;
    i++;
    while (securedIsDigit(arg[i]))
        i++;
    if (j == i - 1)
        return "integer";
    if (arg[i] == 'f')
        return "float";
    else
        return "double";
};

void printConversionLine(const std::string &typeQualifier)
{
    std::cout << typeQualifier << ": ";
};

void printConversionImpossible(const std::string &typeQualifier) {
    std::cout << typeQualifier << ": impossible\n";
}

void  convertToChar(const char *arg, const std::string &type){

    char c;

    if (type.compare("char") != 0)
    {
        double converted;
        converted = strtod(arg, NULL);
        c = static_cast<unsigned char>(converted);
    }
    else
    {
        std::string findChar = arg;
        c = findChar[findFirstPrintableChar(findChar)];
    }
    if (securedIsPrint(c))
    {
        printConversionLine("char"); 
        std::cout << c << std::endl;
    }
    else
        printConversionImpossible("char");
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
        std::cout << f << std::endl;
        return ;
    }
    double converted;
    converted = strtod(arg, NULL);
    if (!isInFloatRange(converted) && type.compare("literal f") != 0 && type.compare("literal d") != 0)
        printConversionImpossible("float");
    else
    {
        f = static_cast<float>(converted);
        printConversionLine("float"); 
        if (f == 0)
            std::cout << f << ".0f" << std::endl;
        else
            std::cout << f << "f" << std::endl;
    }
};

void convertToDouble(const char *arg, const std::string &type){

    double d;
    std::string argStr = arg;
    if (type.compare("char") == 0 && argStr.size() == 1)
    {
        d = static_cast<double>(arg[0]);
        printConversionLine("double"); 
        std::cout << d << std::endl;
        return ;
    }
    double converted;
    converted = strtod(arg, NULL);
    if (errno == ERANGE)
        printConversionImpossible("double");
    else
    {
        d = static_cast<double>(converted);
        printConversionLine("double"); 
        if (d == 0)
            std::cout << d << ".0" << std::endl;
        else
            std::cout << d << std::endl;

    }
};

void doConversion(const char *arg, const std::string &type) {
    convertToChar(arg, type);
    convertToInt(arg, type);
    convertToFloat(arg, type);
    convertToDouble(arg, type);

}

int main(int argc, char *argv[]){

    const std::string::size_type nbAvailableTypes = 10;
    const std::string::size_type nbDisplayTypes = 5;
    const int indexErrors = 7;
    std::string argType;
    std::string availableTypes[nbAvailableTypes] = {"char", "integer", "float", "double", "literal f", "literal d", "non displayable", "empty", "impossible", ""};
    std::string displayTypes[nbDisplayTypes] = {"char", "integer", "float", "double", ""};

    if (argc != 2)
        return (EXIT_FAILURE);
    argType = parseType(argv[1]);
    std::cout << "Type detected: " << argType << std::endl;
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