#ifndef MYLEXER_H_INCLUDED
#define MYLEXER_H_INCLUDED

/*
 * Filename.hpp
 *
 * /Project/Headers/include/Filename.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Sep 20, 2015
 *
 *      Purpose:
 *
 *        Usage:
 *
 *        Notes:
 *
 */

#include "Lexer.hpp"
#include "TokenType.h"
#include "cleancode.h"

using namespace token;

// TOKENS
createTokenType(TTYPE_ENDCHAR);
createTokenType(TTYPE_WHITESPACE);

// IDENTIFYING CHARACTERS
const std::string WHITESPACECHARS = " \t";

// FUNCTION DECLARATIONS
bool contains(std::string str, const char sub);

lexer::Lexer createLexer(const char* sourceCode)
{
    lexer::Lexer lexr(sourceCode);

    setLexer(lexr);

    makeTest(sc)
    {
        if ((sc.getCurrentChar() == '\n')
          | (sc.getCurrentChar() == ';')
          | (sc.getCurrentChar() == '\0')) {
            sc.finished = true;
            return Token(sc.getLineNumber(), sc.getColumnNumber(), std::string(1, sc.getCurrentChar()), TTYPE_ENDCHAR);
        }

        return Token();
    }
    endTest

    makeTest(sc)
    {
        if (contains(WHITESPACECHARS, sc.getCurrentChar())) {
            std::string whitespace(1, sc.getCurrentChar());
            int lineNumber = sc.getLineNumber();
            int columnNumber = sc.getColumnNumber();

            while (contains(WHITESPACECHARS, sc.fetchNextChar())) {
                whitespace += sc.getCurrentChar();
            }

            return Token(lineNumber, columnNumber, whitespace, TTYPE_WHITESPACE);
        }

        return Token();
    }
    endTest


    return lexr;
}

bool contains(std::string str, char sub)
{
    return (str.find(sub) != std::string::npos) ? true : false;
}

#endif // MYLEXER_H_INCLUDED
