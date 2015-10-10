/*
 * Filename.cpp
 *
 * /Project/Sources/src/Filename.cpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Mon Da, Year
 *
 *      Purpose:
 *
 *        Usage:
 *
 *        Notes:
 *
 */

#include "MyLexer.h"

int main()
{
    try {
        lexer::Lexer lexr("hello");

        std::vector<Token> tokens(lexr.tokenizeSource());

        for (auto it = tokens.begin(); it != tokens.end(); it++) {
            std::cout << it->getText() << "\n";
        }
    }
    catch(quitexception& qex) {
        std::cout << qex.what() << "\n";
    }
    catch(std::exception& ex) {
        std::cout << "Something went terribly wrong:\n"
                  << "\t" << ex.what() << "\n";
    }
}
