#ifndef QUITEXCEPTION_H_INCLUDED
#define QUITEXCEPTION_H_INCLUDED

/*
 * quitexception.hpp
 *
 * /MyEasyCPP/Headers/include/quitexception.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Oct 09, 2015
 *
 *      Purpose: An exception thrown when you want to exit the program. Meant to be a safe alternative to std::exit since
 *               there is a catch clause for this type of exception in main.
 *
 *        Usage: Will be thrown whenever the program needs to be exited.
 *
 *        Notes:
 *
 */

#include <exception>

class quitexception : public std::exception
{
    public:
        quitexception(const char* error) :
            error(error)
        {

        }

        virtual const char* what() const throw()
        {
            return error;
        }

    private:
        const char* error;
};

#endif // QUITEXCEPTION_H_INCLUDED
