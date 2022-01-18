#include <cstdlib>
#include <cctype>
#include <iostream>
#include <limits>
#include <cerrno>

/*
 *  Parsing Functions
 */
std::string const parseType(const char *rawArg);
/*
 *  Convert Functions
 */
void convertToChar(const char *arg, const std::string &type);
void convertToInt(const char *arg, const std::string &type);
void convertToFloat(const char *arg, const std::string &type);
void convertToDouble(const char *arg, const std::string &type);
/*
 *  Helper Functions
 */
bool securedIsSpace(char ch);
bool securedIsPrint(char ch);
bool securedIsDigit(char ch);
bool securedIsSign(char ch);
bool hasValidDoublePseudoLiterral(const std::string &str, std::string::size_type begin);
bool hasValidFloatPseudoLiterral(const std::string &str, std::string::size_type begin);
bool isInIntRange(double nbr);
bool isInFloatRange(double nbr);
void printConversionLine(const std::string &typeQualifier);
void printConversionImpossible(const std::string &typeQualifier);
void printConversionNonDisplayble(const std::string &typeQualifier);