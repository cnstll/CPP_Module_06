#include "convert.hpp"

std::string const parseType(const char *rawArg)
{
    std::string arg = rawArg;
    std::string::size_type i = 0;
    std::string::size_type j = 0;

    if (arg.empty())
        return "empty";
    if (arg.size() == 1 && !securedIsDigit(arg[i]))
    {
        if (securedIsPrint(arg[i]))
            return "char";
        else
            return "non displayble";
    }
    if (hasValidFloatPseudoLiterral(arg, i))
        return "literal f";
    if (hasValidDoublePseudoLiterral(arg, i))
        return "literal d";
    if (securedIsSign(arg[i]))
        i++;
    if (!securedIsDigit(arg[i]))
        return "impossible";
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
