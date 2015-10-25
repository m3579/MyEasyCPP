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

#include <iostream>
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
createTokenType(TTYPE_KEYWORD_SET);
createTokenType(TTYPE_KEYWORD_OVERRIDE);
createTokenType(TTYPE_KEYWORD_FUNC);
createTokenType(TTYPE_KEYWORD_IF);
createTokenType(TTYPE_KEYWORD_ORIF);
createTokenType(TTYPE_KEYWORD_ELSE);
createTokenType(TTYPE_KEYWORD_FOR);
createTokenType(TTYPE_KEYWORD_FROM);
createTokenType(TTYPE_KEYWORD_IN);
createTokenType(TTYPE_KEYWORD_WHILE);
createTokenType(TTYPE_KEYWORD_BREAK);
createTokenType(TTYPE_KEYWORD_CONTINUE);
createTokenType(TTYPE_KEYWORD_GENERIC);
createTokenType(TTYPE_KEYWORD_IS_A_OR_AN);
createTokenType(TTYPE_KEYWORD_POINTER);
createTokenType(TTYPE_KEYWORD_WEAKSINGLE);
createTokenType(TTYPE_KEYWORD_SINGLE);
createTokenType(TTYPE_KEYWORD_REF);
createTokenType(TTYPE_KEYWORD_VISIBLE);
createTokenType(TTYPE_KEYWORD_HIDDEN);
createTokenType(TTYPE_KEYWORD_INHERITED);
createTokenType(TTYPE_KEYWORD_TRUE);
createTokenType(TTYPE_KEYWORD_FALSE);
createTokenType(TTYPE_KEYWORD_AS);
createTokenType(TTYPE_KEYWORD_START);
createTokenType(TTYPE_KEYWORD_END);

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

// operators
createTokenType(TTYPE_OPERATOR_AND);
createTokenType(TTYPE_OPERATOR_OR);
createTokenType(TTYPE_OPERATOR_NOT);

createTokenType(TTYPE_OPERATOR_IS);

createTokenType(TTYPE_OPERATOR_PLUS);
createTokenType(TTYPE_OPERATOR_MINUS);
createTokenType(TTYPE_OPERATOR_MULTIPLY);
createTokenType(TTYPE_OPERATOR_DIVIDE);
createTokenType(TTYPE_OPERATOR_MODULUS);
createTokenType(TTYPE_OPERATOR_EXPONENT);
createTokenType(TTYPE_OPERATOR_LESS_THAN);
createTokenType(TTYPE_OPERATOR_GREATER_THAN);
createTokenType(TTYPE_OPERATOR_EQUALS);
createTokenType(TTYPE_OPERATOR_COLON);
createTokenType(TTYPE_OPERATOR_LITERALIZER);
createTokenType(TTYPE_OPERATOR_EQUALS_SIGN);

createTokenType(TTYPE_OPERATOR_INCREMENT);
createTokenType(TTYPE_OPERATOR_DECREMENT);
createTokenType(TTYPE_OPERATOR_PLUS_EQUALS);
createTokenType(TTYPE_OPERATOR_MINUS_EQUALS);
createTokenType(TTYPE_OPERATOR_MULTIPLY_EQUALS);
createTokenType(TTYPE_OPERATOR_DIVIDE_EQUALS);
createTokenType(TTYPE_OPERATOR_MODULUS_EQUALS);
createTokenType(TTYPE_OPERATOR_EXPONENT_EQUALS);
createTokenType(TTYPE_OPERATOR_GREATER_THAN_OR_EQUAL_TO);
createTokenType(TTYPE_OPERATOR_LESS_THAN_OR_EQUAL_TO);
createTokenType(TTYPE_OPERATOR_RIGHT_ARROW);
createTokenType(TTYPE_OPERATOR_LEFT_ARROW);

// symbols
createTokenType(TTYPE_SYMBOL_LPAR);
createTokenType(TTYPE_SYMBOL_RPAR);
createTokenType(TTYPE_SYMBOL_LBRACKET);
createTokenType(TTYPE_SYMBOL_RBRACKET);
createTokenType(TTYPE_SYMBOL_LBRACE);
createTokenType(TTYPE_SYMBOL_RBRACE);
createTokenType(TTYPE_SYMBOL_COLON);
createTokenType(TTYPE_SYMBOL_COMMA);
createTokenType(TTYPE_SYMBOL_PERIOD);
createTokenType(TTYPE_SYMBOL_ARROW);

// miscellaneous
createTokenType(TTYPE_IDENTIFIER);
createTokenType(TTYPE_SMOOTH_IDENTIFIER);
createTokenType(TTYPE_SYNTAX_ERROR);
createTokenType(TTYPE_COMMENT);

// IDENTIFYING CHARACTERS
const std::string& WHITESPACE_CHARS = " \t";
const std::string& NUMBER_LITERAL_CHARS = "1234567890";
const std::string& WORD_START_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
const std::string& WORD_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789";
const std::string& FIRST_OPERATOR_CHARS = "+-*/%^><=:|";
const std::string& SECOND_OPERATOR_CHARS = "+-=";

// DECLARATIONS
bool contains(std::string str, const char sub);

// MAPS
void initTextToTTYPEMap();
void initTextToPPDMap();

std::map<std::string, TokenType> textToTTYPE;
std::map<std::string, TokenType> textToPPD;

lexer::Lexer createLexer(const char* sourceCode)
{
    lexer::Lexer lexr(sourceCode);

    initTextToTTYPEMap();
    initTextToPPDMap();

    setLexer(lexr);

    // ENDCHAR ENDCHAR ENDCHAR ENDCHAR ENDCHAR
    makeTest(sc)
    {
        char c = sc.getCurrentChar();
        if ((c == '\n')
            || (c == ';')
            || (c == '\0')) {

            if (c == '\0') sc.finished = true;

            return Token(sc.getLineNumber(), sc.getColumnNumber(), std::string(1, c), TTYPE_ENDCHAR);
        }

        return Token();
    }
    endTest

    // WHITESPACE WHITESPACE WHITESPACE WHITESPACE
    makeTest(sc)
    {
        char c = sc.getCurrentChar();
        if (contains(WHITESPACE_CHARS, c)) {
            std::string whitespace(1, c);
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

    // NUMBER LITERAL NUMBER LITERAL NUMBER LITERAL
    makeTest(sc)
    {
        char currChar = sc.getCurrentChar();

        if (contains(NUMBER_LITERAL_CHARS, currChar)) {
            std::string number(1, currChar);
            int lineNumber = sc.getLineNumber();
            int columnNumber = sc.getColumnNumber();

            TokenType type = TTYPE_INTEGER_LITERAL;

            while (sc.hasMoreSource()) {
                char nextChar = sc.fetchNextChar();
                if (contains(NUMBER_LITERAL_CHARS, nextChar)) {
                    number += nextChar;
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

    // STRING LITERAL STRING LITERAL STRING LITERAL
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

    // WORD WORD WORD WORD WORD
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

            if (word == "stoptesting") {
                sc.finished = true;
                return Token(lineNumber, columnNumber, word, TTYPE_ENDCHAR);
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

    // SMOOTH
    makeTest(sc)
    {
        char c = sc.getCurrentChar();
        if (c == '$') {
            int lineNumber = sc.getLineNumber();
            int columnNumber = sc.getColumnNumber();
            std::string smoothIdentifier(1, c);

            while (contains(WORD_CHARS, sc.fetchNextChar())) {
                smoothIdentifier += sc.moveToNextChar();
            }

            return Token(lineNumber, columnNumber, smoothIdentifier, TTYPE_SMOOTH_IDENTIFIER);
        }

        return Token();
    }
    endTest

    // MEMBER MEMBER MEMBER MEMBER MEMBER
    makeTest(sc)
    {
        char c = sc.getCurrentChar();
        if (c == '@') {
            int lineNumber = sc.getLineNumber();
            int columnNumber = sc.getColumnNumber();
            std::string member(1, c);

            while (contains(WORD_CHARS, sc.fetchNextChar())) {
                member += sc.moveToNextChar();
            }

            return Token(lineNumber, columnNumber, member, TTYPE_IDENTIFIER);
        }

        return Token();
    }
    endTest

    // OPERATORS OPERATORS OPERATORS OPERATORS OPERATORS
    makeTest(sc)
    {
        char c = sc.getCurrentChar();
        if (contains(FIRST_OPERATOR_CHARS, c)) {
            int lineNumber = sc.getLineNumber();
            int columnNumber = sc.getColumnNumber();
            std::string theOperator(1, c);

            char n = sc.fetchNextChar();

            if (contains(SECOND_OPERATOR_CHARS, n)) {
                switch(c)
                {
                    case '+': {
                        if (n == '+') {
                            theOperator += sc.moveToNextChar();
                            return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_INCREMENT);
                        }
                        else if (n == '=') {
                            theOperator += sc.moveToNextChar();
                            return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_DECREMENT);
                        }
                    }

                    case '-': {
                        if (n == '-') {
                            theOperator += sc.moveToNextChar();
                            if (sc.fetchNextChar() == '>') {
                                theOperator += sc.moveToNextChar();
                                return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_RIGHT_ARROW);
                            }
                            else {
                                return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_DECREMENT);
                            }
                        }
                        else if (n == '=') {
                            theOperator += sc.moveToNextChar();
                            return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_MINUS_EQUALS);
                        }
                    }

                    case '*': {
                        if (n == '=') {
                            theOperator += sc.moveToNextChar();
                            return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_MULTIPLY_EQUALS);
                        }
                    }

                    case '/': {
                        if (n == '=') {
                            theOperator += sc.moveToNextChar();
                            return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_DIVIDE_EQUALS);
                        }
                    }

                    case '%': {
                        if (n == '=') {
                            theOperator += sc.moveToNextChar();
                            return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_MODULUS_EQUALS);
                        }
                    }

                    case '^': {
                        if (n == '=') {
                            theOperator += sc.moveToNextChar();
                            return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_EXPONENT_EQUALS);
                        }
                    }

                    case '>': {
                        if (n == '=') {
                            theOperator += sc.moveToNextChar();
                            return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_GREATER_THAN_OR_EQUAL_TO);
                        }
                    }

                    case '<': {
                        if (n == '=') {
                            theOperator += sc.moveToNextChar();
                            return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_LESS_THAN_OR_EQUAL_TO);
                        }
                        else if (n == '-') {
                            theOperator += sc.moveToNextChar();
                            if (sc.fetchNextChar() == '-') {
                                theOperator += sc.moveToNextChar();
                                return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_LEFT_ARROW);
                            }
                        }
                    }

                    default: {
                        return Token(lineNumber, columnNumber, theOperator + sc.fetchNextChar(), TTYPE_SYNTAX_ERROR, "I cannot recognize this operator", false);
                    }
                }
            }
            else {
                switch(c)
                {
                    case '+': {
                        return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_PLUS);
                    }

                    case '-': {
                        return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_MINUS);
                    }

                    case '*': {
                        return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_MULTIPLY);
                    }

                    case '/': {
                        return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_DIVIDE);
                    }

                    case '%': {
                        return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_MODULUS);
                    }

                    case '^': {
                        return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_EXPONENT);
                    }

                    case '|': {
                        return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_LITERALIZER);
                    }

                    case '=': {
                        return Token(lineNumber, columnNumber, theOperator, TTYPE_OPERATOR_EQUALS_SIGN);
                    }
                }
            }
        }

        return Token();
    }
    endTest

    // SYMBOLS SYMBOLS SYMBOLS SYMBOLS SYMBOLS
    makeTest(sc)
    {
        char c = sc.getCurrentChar();
        int lineNumber = sc.getLineNumber();
        int columnNumber = sc.getColumnNumber();

        switch(c)
        {
            case '(': { return Token(lineNumber, columnNumber, std::string(1, c), TTYPE_SYMBOL_LPAR);         break; }
            case ')': { return Token(lineNumber, columnNumber, std::string(1, c), TTYPE_SYMBOL_RPAR);         break; }
            case '[': { return Token(lineNumber, columnNumber, std::string(1, c), TTYPE_SYMBOL_LBRACKET);     break; }
            case ']': { return Token(lineNumber, columnNumber, std::string(1, c), TTYPE_SYMBOL_RBRACKET);     break; }
            case '{': { return Token(lineNumber, columnNumber, std::string(1, c), TTYPE_SYMBOL_LBRACE);       break; }
            case '}': { return Token(lineNumber, columnNumber, std::string(1, c), TTYPE_SYMBOL_RBRACE);       break; }
            case ':': { return Token(lineNumber, columnNumber, std::string(1, c), TTYPE_SYMBOL_COLON);        break; }
            case ',': { return Token(lineNumber, columnNumber, std::string(1, c), TTYPE_SYMBOL_COMMA);        break; }
            case '.': { return Token(lineNumber, columnNumber, std::string(1, c), TTYPE_SYMBOL_PERIOD);       break; }

            default: {
                if (c == '-') {
                    if (sc.fetchNextChar() == '>') {
                        return Token(lineNumber, columnNumber, std::string(1, c) + std::string(1, sc.moveToNextChar()), TTYPE_SYMBOL_ARROW);
                    }
                    else {
                        return Token(lineNumber, columnNumber, std::string(1, c), TTYPE_OPERATOR_MINUS);
                    }
                }

                if (c == '#') {
                    int lineNumber = sc.getLineNumber();
                    int columnNumber = sc.getColumnNumber();
                    std::string comment(1, c);

                    if (sc.fetchNextChar() == '=') {
                        sc.moveToNextChar();
                        comment += sc.getCurrentChar();

                        while (sc.hasMoreSource()) {
                            sc.moveToNextChar();
                            comment += sc.getCurrentChar();
                            if (sc.getCurrentChar() == '=') {
                                sc.moveToNextChar();
                                comment += sc.getCurrentChar();
                                if (sc.getCurrentChar() == '#') {
                                    comment += sc.getCurrentChar();
                                    return Token(lineNumber, columnNumber, comment, TTYPE_COMMENT);
                                }
                            }
                        }

                        return Token(sc.getLineNumber(), sc.getColumnNumber(), comment, TTYPE_SYNTAX_ERROR, "You never finished this comment", true);

                    }
                    else {
                        while ((sc.fetchNextChar() != '\n')
                               && (sc.fetchNextChar() != '\0')) {
                            sc.moveToNextChar();
                            comment += sc.getCurrentChar();
                        }

                        return Token(lineNumber, columnNumber, comment, TTYPE_COMMENT);
                    }
                }
            }
        }

        return Token();
    }
    endTest

    // PREPROCESSOR DIRECTIVES PREPROCESSOR DIRECTIVES
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

// IMPLEMENTATIONS
bool contains(std::string str, char sub)
{
    return (str.find(sub) != std::string::npos) ? true : false;
}

// MAP IMPLEMTATIONS
void initTextToTTYPEMap()
{
    textToTTYPE["namespace"] = TTYPE_KEYWORD_NAMESPACE;
    textToTTYPE["use"]       = TTYPE_KEYWORD_USE;
    textToTTYPE["of"]        = TTYPE_KEYWORD_OF;
    textToTTYPE["declare"]   = TTYPE_KEYWORD_DECLARE;
    textToTTYPE["init"]      = TTYPE_KEYWORD_INIT;
    textToTTYPE["set"]       = TTYPE_KEYWORD_SET;
    textToTTYPE["override"]  = TTYPE_KEYWORD_OVERRIDE;
    textToTTYPE["func"]      = TTYPE_KEYWORD_FUNC;
    textToTTYPE["if"]        = TTYPE_KEYWORD_IF;
    textToTTYPE["orif"]      = TTYPE_KEYWORD_ORIF;
    textToTTYPE["else"]      = TTYPE_KEYWORD_ELSE;
    textToTTYPE["for"]       = TTYPE_KEYWORD_FOR;
    textToTTYPE["from"]      = TTYPE_KEYWORD_FROM;
    textToTTYPE["in"]        = TTYPE_KEYWORD_IN;
    textToTTYPE["while"]     = TTYPE_KEYWORD_WHILE;
    textToTTYPE["break"]     = TTYPE_KEYWORD_BREAK;
    textToTTYPE["continue"]  = TTYPE_KEYWORD_CONTINUE;
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
    textToTTYPE["true"]      = TTYPE_KEYWORD_TRUE;
    textToTTYPE["false"]     = TTYPE_KEYWORD_FALSE;
    textToTTYPE["as"]        = TTYPE_KEYWORD_AS;
    textToTTYPE["start"]     = TTYPE_KEYWORD_START;
    textToTTYPE["end"]       = TTYPE_KEYWORD_END;

    textToTTYPE["and"]       = TTYPE_OPERATOR_AND;
    textToTTYPE["or"]        = TTYPE_OPERATOR_OR;
    textToTTYPE["not"]       = TTYPE_OPERATOR_NOT;

    textToTTYPE["is"]        = TTYPE_OPERATOR_IS;
}

void initTextToPPDMap()
{
    textToPPD["DefineMacro"]    = TTYPE_PPD_MACRO;
    textToPPD["RaiseError"]     = TTYPE_PPD_ERROR;
    textToPPD["If"]             = TTYPE_PPD_IF;
    textToPPD["IfDefined"]      = TTYPE_PPD_IFDEF;
    textToPPD["IfNotDefined"]   = TTYPE_PPD_IFNDEF;
    textToPPD["Undefine"]       = TTYPE_PPD_UNDEF;
    textToPPD["AccessFile"]     = TTYPE_PPD_ACCESS;
    textToPPD["UseCPPCode"]     = TTYPE_PPD_USE;
    textToPPD["SetLine"]        = TTYPE_PPD_SETLINE;
}

#endif // MYLEXER_H_INCLUDED
