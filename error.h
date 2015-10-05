#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

/*
 * error.h
 *
 * /MyEasyCPP/Headers/include/error.h
 *
 *       Author: Mihir Kasmalkar
 * Date created: Oct 04, 2015
 *
 *      Purpose: Contains functions for generating compiler warnings and
 *               errors.
 *
 *        Usage: Functions from this file will be called throughout the compiler.
 *
 *        Notes:
 *
 */

#include <iostream>

void error(std::string text, int lineNumber, int columnNumber, bool fatal);
void printErrorMessage(std::string text, int lineNumber, int columnNumber, std::string message);

void error(std::string text, int lineNumber, int columnNumber, std::string message, bool fatal)
{
    printErrorMessage(text, lineNumber, columnNumber, message);
    if (fatal) {
        std::cout << "Sorry, compilation had to abort after this error\n";
    }
}

void printErrorMessage(std::string text, int lineNumber, int columnNumber, std::string message)
{
    std::cout << "Error: (" << lineNumber << ", " << columnNumber << ")\n"
              << "\tCode: " << text << "\n"
              << "\tError: " << message << "\n\n";
}

#endif // ERROR_H_INCLUDED
