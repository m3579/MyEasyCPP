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

#include <memory>

#include "Lexer.hpp"
#include "TokenType.h"
#include "cleancode.h"
#include "error.h"

using namespace token;

// TOKENS
createTokenType(TTYPE_ENDCHAR);
createTokenType(TTYPE_WHITESPACE);
createTokenType(TTYPE_INTEGER_LITERAL);
createTokenType(TTYPE_DECIMAL_LITERAL);

// IDENTIFYING CHARACTERS
const std::string WHITESPACE_CHARS = " \t";
const std::string NUMBER_LITERAL_CHARS = "1234567890";

// FUNCTION DECLARATIONS
bool contains(std::string str, const char sub);

lexer::Lexer createLexer(const char* sourceCode)
{
    lexer::Lexer lexr(sourceCode);

    setLexer(lexr);

    // <ENDCHAR>
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

    // WHITESPACE
    makeTest(sc)
    {
        if (contains(WHITESPACE_CHARS, sc.getCurrentChar())) {
            std::string whitespace(1, sc.getCurrentChar());
            int lineNumber = sc.getLineNumber();
            int columnNumber = sc.getColumnNumber();

            while (contains(WHITESPACE_CHARS, sc.fetchNextChar())) {
                whitespace += sc.getCurrentChar();
            }

            return Token(lineNumber, columnNumber, whitespace, TTYPE_WHITESPACE);
        }

        return Token();
    }
    endTest

    // <NUMBER-LITERAL>
    makeTest(sc)
    {
        char currChar = sc.getCurrentChar();

        if (contains(NUMBER_LITERAL_CHARS, currChar)
            || currChar == '-') {
            std::string number(1, currChar);
            int lineNumber = sc.getLineNumber();
            int columnNumber = sc.getColumnNumber();

            int type = TTYPE_INTEGER_LITERAL;

            while (sc.hasMoreSource()) {
                char nextChar = sc.fetchNextChar();
                if (contains(NUMBER_LITERAL_CHARS, nextChar)) {
                    number += nextChar;
                    continue;
                }
                else if (nextChar == '.') {
                    number += nextChar;
                    type = TTYPE_DECIMAL_LITERAL;
                }
                else {
                    break;
                }

                sc.moveToNextChar();
            }

            if (sc.getCurrentChar() == '.') {
                error(number, lineNumber, columnNumber, "You cannot end a number with a decimal point (add a 0 to the end)", true);
                return Token();
            }

            return Token(lineNumber, columnNumber, number, type);
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
