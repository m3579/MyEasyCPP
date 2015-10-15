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

// whitespace
createTokenType(TTYPE_ENDCHAR);
createTokenType(TTYPE_WHITESPACE);

// literals
createTokenType(TTYPE_INTEGER_LITERAL);
createTokenType(TTYPE_DECIMAL_LITERAL);
createTokenType(TTYPE_STRING_LITERAL);

// keywords
createTokenType(TTYPE_KEYWORD_NAMESPACE);
createTokenType(TTYPE_KEYWORD_USE);
createTokenType(TTYPE_KEYWORD_OF);
createTokenType(TTYPE_KEYWORD_DECLARE);
createTokenType(TTYPE_KEYWORD_INIT);
createTokenType(TTYPE_KEYWORD_OVERRIDE);
createTokenType(TTYPE_KEYWORD_FUNC);
createTokenType(TTYPE_KEYWORD_IF);
createTokenType(TTYPE_KEYWORD_ORIF);
createTokenType(TTYPE_KEYWORD_ELSE);
createTokenType(TTYPE_KEYWORD_FOR);
createTokenType(TTYPE_KEYWORD_FROM);
createTokenType(TTYPE_KEYWORD_TO);
createTokenType(TTYPE_KEYWORD_IN);
createTokenType(TTYPE_KEYWORD_WHILE);
createTokenType(TTYPE_KEYWORD_GENERIC);
createTokenType(TTYPE_KEYWORD_IS_A_OR_AN);
createTokenType(TTYPE_KEYWORD_POINTER);
createTokenType(TTYPE_KEYWORD_WEAKSINGLE);
createTokenType(TTYPE_KEYWORD_SINGLE);
createTokenType(TTYPE_KEYWORD_REF);
createTokenType(TTYPE_KEYWORD_VISIBLE);
createTokenType(TTYPE_KEYWORD_HIDDEN);
createTokenType(TTYPE_KEYWORD_INHERITED);

// preprocessor directives
createTokenType(TTYPE_PPD_MACRO);
createTokenType(TTYPE_PPD_ERROR);
createTokenType(TTYPE_PPD_IF);
createTokenType(TTYPE_PPD_IFDEF);
createTokenType(TTYPE_PPD_IFNDEF);
createTokenType(TTYPE_PPD_UNDEF);
createTokenType(TTYPE_PPD_ACCESS);
createTokenType(TTYPE_PPD_USE);
createTokenType(TTYPE_PPD_SETLINE);
createTokenType(TTYPE_PPD_EMPTY);

// operators
createTokenType(TTYPE_OPERATOR_AND);
createTokenType(TTYPE_OPERATOR_OR);
createTokenType(TTYPE_OPERATOR_NOT);

createTokenType(TTYPE_OPERATOR_IS);

// miscellaneous
createTokenType(TTYPE_IDENTIFIER);
createTokenType(TTYPE_SYNTAX_ERROR);

// IDENTIFYING CHARACTERS
const std::string& WHITESPACE_CHARS = " \t";
const std::string& NUMBER_LITERAL_CHARS = "1234567890";
const std::string& WORD_START_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
const std::string& WORD_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789";

// DECLARATIONS
bool contains(std::string str, const char sub);

// MAPS
void initTextToTTYPEMap();
void initTextToPPDMap();

std::map<std::string, int> textToTTYPE;
std::map<std::string, int> textToPPD;

lexer::Lexer createLexer(const char* sourceCode)
{
    lexer::Lexer lexr(sourceCode);

    initTextToTTYPEMap();
    initTextToPPDMap();

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
                return Token(lineNumber, columnNumber, number, TTYPE_SYNTAX_ERROR, "You cannot end a number with a decimal point (add a 0 to the end)", false);
            }

            return Token(lineNumber, columnNumber, number, type);
        }

        return Token();
    }
    endTest

    makeTest(sc)
    {
        char c = sc.getCurrentChar();
        if (c == '"') {
            int lineNumber = sc.getLineNumber();
            int columnNumber = sc.getColumnNumber();

            std::string theString(1, c);

            while ((c=sc.fetchNextChar())) {

                if (c == '\0') {
                    return Token(lineNumber, columnNumber, theString, TTYPE_SYNTAX_ERROR, "You need to close this string", false);
                }

                theString += c;

                if (c == '"') {
                    if (!(sc.getCurrentChar() == '\\')) {
                        break;
                    }
                }
            }

            return Token(lineNumber, columnNumber, theString, TTYPE_STRING_LITERAL);
        }

        return Token();
    }
    endTest

    makeTest(sc)
    {
        char c = sc.getCurrentChar();
        if (contains(WORD_START_CHARS, c)) {
            int lineNumber = sc.getLineNumber();
            int columnNumber = sc.getColumnNumber();
            std::string word(1, c);

            while (contains(WORD_CHARS, sc.fetchNextChar())) {
                word += sc.moveToNextChar();
            }

            if (textToTTYPE.find(word) != textToTTYPE.end()) {
                return Token(lineNumber, columnNumber, word, textToTTYPE[word]);
            }
            else {
                return Token(lineNumber, columnNumber, word, TTYPE_IDENTIFIER);
            }
        }

        return Token();
    }
    endTest

    makeTest(sc)
    {
        char c = sc.getCurrentChar();
        if (c == '-') {
            int lineNumber = sc.getLineNumber();
            int columnNumber = sc.getColumnNumber();
            std::string ppd(1, c);

            sc.moveToNextChar();
            while (contains(WHITESPACE_CHARS, sc.getCurrentChar())) {
                sc.moveToNextChar();
            }

            c = sc.getCurrentChar();
            if (contains(WORD_START_CHARS, c)) {
                ppd += c;
                while (contains(WORD_CHARS, sc.fetchNextChar())) {
                    ppd += sc.moveToNextChar();
                }
            }

            if (textToPPD.find(ppd) != textToPPD.end()) {
                return Token(lineNumber, columnNumber, ppd, textToPPD[ppd]);
            }
            else {
                return Token(lineNumber, columnNumber, ppd, TTYPE_SYNTAX_ERROR, "I cannot recognize this preprocessor directive", false);
            }
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

void initTextToTTYPEMap()
{
    textToTTYPE["namespace"] = TTYPE_KEYWORD_NAMESPACE;
    textToTTYPE["use"]       = TTYPE_KEYWORD_USE;
    textToTTYPE["of"]        = TTYPE_KEYWORD_OF;
    textToTTYPE["declare"]   = TTYPE_KEYWORD_DECLARE;
    textToTTYPE["init"]      = TTYPE_KEYWORD_INIT;
    textToTTYPE["override"]  = TTYPE_KEYWORD_OVERRIDE;
    textToTTYPE["func"]      = TTYPE_KEYWORD_FUNC;
    textToTTYPE["if"]        = TTYPE_KEYWORD_IF;
    textToTTYPE["orif"]      = TTYPE_KEYWORD_ORIF;
    textToTTYPE["else"]      = TTYPE_KEYWORD_ELSE;
    textToTTYPE["for"]       = TTYPE_KEYWORD_FOR;
    textToTTYPE["from"]      = TTYPE_KEYWORD_FROM;
    textToTTYPE["to"]        = TTYPE_KEYWORD_TO;
    textToTTYPE["in"]        = TTYPE_KEYWORD_IN;
    textToTTYPE["while"]     = TTYPE_KEYWORD_WHILE;
    textToTTYPE["generic"]   = TTYPE_KEYWORD_GENERIC;
    textToTTYPE["is_a"]      = TTYPE_KEYWORD_IS_A_OR_AN;
    textToTTYPE["is_an"]     = TTYPE_KEYWORD_IS_A_OR_AN;
    textToTTYPE["Pointer"]   = TTYPE_KEYWORD_POINTER;
    textToTTYPE["WeakSingle"]= TTYPE_KEYWORD_WEAKSINGLE;
    textToTTYPE["Single"]    = TTYPE_KEYWORD_SINGLE;
    textToTTYPE["Ref"]       = TTYPE_KEYWORD_REF;
    textToTTYPE["visible"]   = TTYPE_KEYWORD_VISIBLE;
    textToTTYPE["hidden"]    = TTYPE_KEYWORD_HIDDEN;
    textToTTYPE["inherited"] = TTYPE_KEYWORD_INHERITED;

    textToTTYPE["and"]       = TTYPE_OPERATOR_AND;
    textToTTYPE["or"]        = TTYPE_OPERATOR_OR;
    textToTTYPE["not"]       = TTYPE_OPERATOR_NOT;

    textToTTYPE["is"]        = TTYPE_OPERATOR_IS;
}

void initTextToPPDMap()
{
    textToPPD["macro"]       = TTYPE_PPD_MACRO;
    textToPPD["error"]       = TTYPE_PPD_ERROR;
    textToPPD["if"]          = TTYPE_PPD_IF;
    textToPPD["ifdefined"]   = TTYPE_PPD_IFDEF;
    textToPPD["ifnotdefined"]= TTYPE_PPD_IFNDEF;
    textToPPD["undefine"]    = TTYPE_PPD_UNDEF;
    textToPPD["access"]      = TTYPE_PPD_ACCESS;
    textToPPD["use"]         = TTYPE_PPD_USE;
    textToPPD["setline"]     = TTYPE_PPD_SETLINE;
    textToPPD[""]            = TTYPE_PPD_EMPTY;
}

#endif // MYLEXER_H_INCLUDED
