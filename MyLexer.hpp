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
createTokenType(TTYPE_KEYWORD_STATIC);
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

// comments
createTokenType(TTYPE_MULTILINE_COMMENT);
createTokenType(TTYPE_INLINE_COMMENT);

// miscellaneous
createTokenType(TTYPE_IDENTIFIER);
createTokenType(TTYPE_SMOOTH_IDENTIFIER);
createTokenType(TTYPE_SYNTAX_ERROR);

// IDENTIFYING CHARACTERS
const std::string& WHITESPACE_CHARS = " \t";
const std::string& NUMBER_LITERAL_CHARS = "1234567890";
const std::string& WORD_START_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_$";
const std::string& WORD_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789";
const std::string& FIRST_OPERATOR_CHARS = "+-*/%^><=|";
const std::string& SECOND_OPERATOR_CHARS = "+-=";
const std::string& THIRD_OPERATOR_CHARS = "->";
const std::string& FIRST_SYMBOL_CHARS = "()[]{}:,.";
const std::string& SECOND_SYMBOL_CHARS = "->";

// DECLARATIONS
bool contains(std::string str, const char sub);

// MAPS
void initTextToTTYPEMaps();

std::map<std::string, TokenType> textToWord;
std::map<std::string, TokenType> textToPPD;
std::map<std::string, TokenType> textToSingleCharSymbol;
std::map<std::string, TokenType> textToMultiCharSymbol;
std::map<std::string, TokenType> textToSingleCharOperator;
std::map<std::string, TokenType> textToMultiCharOperator;

lexer::Lexer createLexer(const char* sourceCode)
{
    lexer::Lexer lexr(sourceCode);

    initTextToTTYPEMaps();

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
                whitespace += sc.moveToNextChar();
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
                return Token(lineNumber, columnNumber, number, TTYPE_SYNTAX_ERROR, "You cannot end a number with a decimal point (add a 0 to the end)");
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
                    return Token(lineNumber, columnNumber, theString, TTYPE_SYNTAX_ERROR, "You need to close this string");
                }

                theString += sc.moveToNextChar();

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

            if (textToWord.find(word) != textToWord.end()) {
                return Token(lineNumber, columnNumber, word, textToWord[word]);
            }
            else {
                return Token(lineNumber, columnNumber, word, TTYPE_IDENTIFIER);
            }
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

            if (contains(SECOND_OPERATOR_CHARS, sc.fetchNextChar())) {
                theOperator += std::string(1, sc.moveToNextChar());

                if (contains(THIRD_OPERATOR_CHARS, sc.fetchNextChar())) {
                    theOperator += std::string(1, sc.moveToNextChar());
                }

                if (textToMultiCharOperator.find(theOperator)
                    != textToMultiCharOperator.end()) {
                    return Token(lineNumber, columnNumber, theOperator, textToMultiCharOperator[theOperator]);
                }
                else {
                    return Token(lineNumber, columnNumber, theOperator, TTYPE_SYNTAX_ERROR, "I cannot recognize this operator");
                }
            }
            else {
                if (textToSingleCharOperator.find(theOperator)
                    != textToSingleCharOperator.end()) {
                    return Token(lineNumber, columnNumber, theOperator, textToSingleCharOperator[theOperator]);
                }
                else {
                    return Token(lineNumber, columnNumber, theOperator, TTYPE_SYNTAX_ERROR, "I cannot recognize this operator");
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
        if (contains(FIRST_SYMBOL_CHARS, c)) {
            int lineNumber = sc.getLineNumber();
            int columnNumber = sc.getColumnNumber();
            std::string symbol(1, c);

            if (contains(SECOND_SYMBOL_CHARS, sc.fetchNextChar())) {
                symbol += sc.moveToNextChar();

                if (textToMultiCharSymbol.find(symbol)
                    != textToMultiCharOperator.end()) {
                    return Token(lineNumber, columnNumber, symbol, textToMultiCharSymbol[symbol]);
                }
                else {
                    return Token(lineNumber, columnNumber, symbol, TTYPE_SYNTAX_ERROR, "I cannot recognize this symbol");
                }
            }
            else {
                if (textToSingleCharSymbol.find(symbol)
                    != textToSingleCharSymbol.end()) {
                    return Token(lineNumber, columnNumber, symbol, textToSingleCharSymbol[symbol]);
                }
                else {
                    return Token(lineNumber, columnNumber, symbol, TTYPE_SYNTAX_ERROR, "I cannot recognize this symbol");
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
                return Token(lineNumber, columnNumber, ppd, TTYPE_SYNTAX_ERROR, "I cannot recognize this preprocessor directive");
            }
        }

        return Token();
    }
    endTest

    makeTest(sc)
    {
        char c = sc.getCurrentChar();
        if (c == '#') {
            int lineNumber = sc.getLineNumber();
            int columnNumber = sc.getColumnNumber();
            std::string comment(1, c);

            if (sc.fetchNextChar() == '=') {
                comment += sc.moveToNextChar();

                char current;
                // not actually meant to loop through rest of code
                // return statements will exit loop
                while (sc.hasMoreSource()) {
                    current = sc.moveToNextChar();

                    if (current == '\0') {
                        sc.finished = true;
                        return Token(lineNumber, columnNumber, comment, TTYPE_SYNTAX_ERROR, "This comment was not closed by a \"=#\"");
                    }
                    else if (current == '='
                             && sc.fetchNextChar() == '#') {
                        comment += current;
                        comment += sc.moveToNextChar();

                        return Token(lineNumber, columnNumber, comment, TTYPE_MULTILINE_COMMENT);

                    }

                    comment += current;
                }
            }

            else {
                char current;
                while (sc.hasMoreSource()) {
                    current = sc.moveToNextChar();

                    if (current == '\0'
                        || current == '\n') {
                        return Token(lineNumber, columnNumber, comment, TTYPE_INLINE_COMMENT);
                    }

                    comment += current;
                }
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
void initTextToTTYPEMaps()
{
    textToWord["namespace"] = TTYPE_KEYWORD_NAMESPACE;
    textToWord["use"]       = TTYPE_KEYWORD_USE;
    textToWord["of"]        = TTYPE_KEYWORD_OF;
    textToWord["declare"]   = TTYPE_KEYWORD_DECLARE;
    textToWord["init"]      = TTYPE_KEYWORD_INIT;
    textToWord["set"]       = TTYPE_KEYWORD_SET;
    textToWord["override"]  = TTYPE_KEYWORD_OVERRIDE;
    textToWord["func"]      = TTYPE_KEYWORD_FUNC;
    textToWord["if"]        = TTYPE_KEYWORD_IF;
    textToWord["orif"]      = TTYPE_KEYWORD_ORIF;
    textToWord["else"]      = TTYPE_KEYWORD_ELSE;
    textToWord["for"]       = TTYPE_KEYWORD_FOR;
    textToWord["from"]      = TTYPE_KEYWORD_FROM;
    textToWord["in"]        = TTYPE_KEYWORD_IN;
    textToWord["while"]     = TTYPE_KEYWORD_WHILE;
    textToWord["break"]     = TTYPE_KEYWORD_BREAK;
    textToWord["continue"]  = TTYPE_KEYWORD_CONTINUE;
    textToWord["generic"]   = TTYPE_KEYWORD_GENERIC;
    textToWord["is_a"]      = TTYPE_KEYWORD_IS_A_OR_AN;
    textToWord["is_an"]     = TTYPE_KEYWORD_IS_A_OR_AN;
    textToWord["Pointer"]   = TTYPE_KEYWORD_POINTER;
    textToWord["WeakSingle"]= TTYPE_KEYWORD_WEAKSINGLE;
    textToWord["Single"]    = TTYPE_KEYWORD_SINGLE;
    textToWord["Ref"]       = TTYPE_KEYWORD_REF;
    textToWord["visible"]   = TTYPE_KEYWORD_VISIBLE;
    textToWord["hidden"]    = TTYPE_KEYWORD_HIDDEN;
    textToWord["inherited"] = TTYPE_KEYWORD_INHERITED;
    textToWord["static"]    = TTYPE_KEYWORD_STATIC;
    textToWord["true"]      = TTYPE_KEYWORD_TRUE;
    textToWord["false"]     = TTYPE_KEYWORD_FALSE;
    textToWord["as"]        = TTYPE_KEYWORD_AS;
    textToWord["start"]     = TTYPE_KEYWORD_START;
    textToWord["end"]       = TTYPE_KEYWORD_END;

    textToWord["and"]       = TTYPE_OPERATOR_AND;
    textToWord["or"]        = TTYPE_OPERATOR_OR;
    textToWord["not"]       = TTYPE_OPERATOR_NOT;

    textToWord["is"]        = TTYPE_OPERATOR_IS;


    textToPPD["Macro"]    = TTYPE_PPD_MACRO;
    textToPPD["Raise"]     = TTYPE_PPD_ERROR;
    textToPPD["If"]             = TTYPE_PPD_IF;
    textToPPD["IfDefined"]      = TTYPE_PPD_IFDEF;
    textToPPD["IfNotDefined"]   = TTYPE_PPD_IFNDEF;
    textToPPD["Undefine"]       = TTYPE_PPD_UNDEF;
    textToPPD["Access"]     = TTYPE_PPD_ACCESS;
    textToPPD["CPP"]     = TTYPE_PPD_USE;
    textToPPD["Line"]        = TTYPE_PPD_SETLINE;


    textToSingleCharSymbol["("] = TTYPE_SYMBOL_LPAR;
    textToSingleCharSymbol[")"] = TTYPE_SYMBOL_RPAR;
    textToSingleCharSymbol["["] = TTYPE_SYMBOL_LBRACKET;
    textToSingleCharSymbol["]"] = TTYPE_SYMBOL_RBRACKET;
    textToSingleCharSymbol["{"] = TTYPE_SYMBOL_LBRACE;
    textToSingleCharSymbol["}"] = TTYPE_SYMBOL_RBRACE;
    textToSingleCharSymbol[":"] = TTYPE_SYMBOL_COLON;
    textToSingleCharSymbol[","] = TTYPE_SYMBOL_COMMA;
    textToSingleCharSymbol["."] = TTYPE_SYMBOL_PERIOD;

    textToMultiCharSymbol["->"] = TTYPE_SYMBOL_ARROW;


    textToMultiCharOperator["++"]       = TTYPE_OPERATOR_INCREMENT;
    textToMultiCharOperator["+="]       = TTYPE_OPERATOR_PLUS_EQUALS;
    textToMultiCharOperator["--"]       = TTYPE_OPERATOR_DECREMENT;
    textToMultiCharOperator["-="]       = TTYPE_OPERATOR_MINUS_EQUALS;
    textToMultiCharOperator["*="]       = TTYPE_OPERATOR_MULTIPLY_EQUALS;
    textToMultiCharOperator["/="]       = TTYPE_OPERATOR_DIVIDE_EQUALS;
    textToMultiCharOperator["%="]       = TTYPE_OPERATOR_MODULUS_EQUALS;
    textToMultiCharOperator["^="]       = TTYPE_OPERATOR_EXPONENT_EQUALS;
    textToMultiCharOperator[">="]       = TTYPE_OPERATOR_GREATER_THAN_OR_EQUAL_TO;
    textToMultiCharOperator["<="]       = TTYPE_OPERATOR_LESS_THAN_OR_EQUAL_TO;
    textToMultiCharOperator["<--"]      = TTYPE_OPERATOR_LEFT_ARROW;
    textToMultiCharOperator["-->"]      = TTYPE_OPERATOR_RIGHT_ARROW;


    textToSingleCharOperator["+"]       = TTYPE_OPERATOR_PLUS;
    textToSingleCharOperator["-"]       = TTYPE_OPERATOR_MINUS;
    textToSingleCharOperator["*"]       = TTYPE_OPERATOR_MULTIPLY;
    textToSingleCharOperator["/"]       = TTYPE_OPERATOR_DIVIDE;
    textToSingleCharOperator["%"]       = TTYPE_OPERATOR_MODULUS;
    textToSingleCharOperator["^"]       = TTYPE_OPERATOR_EXPONENT;
    textToSingleCharOperator["|"]       = TTYPE_OPERATOR_LITERALIZER;
    textToSingleCharOperator["="]       = TTYPE_OPERATOR_EQUALS;
    textToSingleCharOperator[">"]       = TTYPE_OPERATOR_GREATER_THAN;
    textToSingleCharOperator["<"]       = TTYPE_OPERATOR_LESS_THAN;

}

#endif // MYLEXER_H_INCLUDED
