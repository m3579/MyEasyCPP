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

#include "MyLexer.hpp"
#include "Smooth.hpp"

int main()
{
    try {

        lexer::Lexer lexr(createLexer("Hello World"));

        std::vector<Token> tokens(lexr.tokenizeSource());

        for (auto it = tokens.begin(); it != tokens.end(); it++) {
            std::cout << it->getText() << "\n";
        }
    }
    catch(const char* message) {
        std::cout << "Error in compiler: " << message << "\n";
    }
    catch(quitexception& qex) {
        std::cout << qex.what() << "\n";
    }
    catch(std::exception& ex) {
        std::cout << "Error in compiler:\n"
                  << "\t" << ex.what() << "\n";
    }
}
