#include "convert.hpp"
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

bool hasValidDoublePseudoLiterral(const std::string &str, std::string::size_type begin){

    if (str.find("-inf", begin) == begin)
        return true;
    if (str.find("+inf", begin) == begin)
        return true;
    if (str.find("nan", begin) == begin)
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

bool isInIntRange(double nbr) {
    return (nbr <= static_cast<double>(std::numeric_limits<int>::max())
    && nbr >= static_cast<double>(std::numeric_limits<int>::min()));
}

bool isInFloatRange(double nbr) {
    return (nbr <= static_cast<double>(std::numeric_limits<float>::max())
    && nbr >= -static_cast<double>(std::numeric_limits<float>::max()));
}

void printConversionLine(const std::string &typeQualifier)
{
    std::cout << typeQualifier << ": ";
};

void printConversionImpossible(const std::string &typeQualifier) {
    std::cout << typeQualifier << ": impossible\n";
};

void printConversionNonDisplayble(const std::string &typeQualifier) {
    std::cout << typeQualifier << ": non displayable\n";
};

