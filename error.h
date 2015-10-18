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

#include "quitexception.hpp"

void error(std::string type, std::string text, int lineNumber, int columnNumber, bool fatal);
void printErrorMessage(std::string type, std::string text, int lineNumber, int columnNumber, std::string message);

const std::string& ERRTYPE_SYNTAX_ERROR     = "SyntaxError";
const std::string& ERRTYPE_RUNTIME_ERROR    = "RuntimeError";

void error(std::string type, std::string text, int lineNumber, int columnNumber, std::string message, bool fatal)
{
    printErrorMessage(type, text, lineNumber, columnNumber, message);
    if (fatal) {
        throw quitexception("Sorry, I had to abort after this error.");
    }
}

void printErrorMessage(std::string type, std::string text, int lineNumber, int columnNumber, std::string message)
{
    std::cout << type << ": (" << lineNumber << ", " << columnNumber << ")\n"
              << "\tCode: " << text << "\n"
              << "\tError: " << message << "\n\n";
}

#endif // ERROR_H_INCLUDED
