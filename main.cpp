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

#include <fstream>

#include "MyLexer.hpp"
#include "Smooth.hpp"

void testLexer()
{
    std::ifstream input("test.txt");

    std::string sourceCode;

    std::string line;
    if (input.is_open()) {
        while (std::getline(input, line)) {
            sourceCode += line + "\n";
        }

        sourceCode += "\0";
    }
    else {
        std::cout << "Could not open file\n";
        return;
    }

    input.close();

    lexer::Lexer lexr(createLexer(sourceCode.c_str()));

    std::vector<Token> tokens(lexr.tokenizeSource());

    for (auto it = tokens.begin(); it != tokens.end(); it++) {
        std::cout << "Token:\n"
                  << "\t|" << it->getText() << "|\n"
                  << "\t" << it->getLineNumber() << " " << it->getColumnNumber() << "\n"
                  << "\t" << it->getType() << "\n";
    }
}

int main()
{
    try {
        testLexer();
    }
    catch(const char* message) {
        std::cout << "Error in compiler: " << message << "\n";
    }
    catch(std::exception& ex) {
        std::cout << "Error in compiler:" << ex.what() << "\n";
    }
}
