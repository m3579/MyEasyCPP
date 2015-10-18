#ifndef SMOOTH_HPP_INCLUDED
#define SMOOTH_HPP_INCLUDED

/*
 * Smooth.hpp
 *
 * /MyEasyCPP/Headers/include/Smooth.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Oct 18, 2015
 *
 *      Purpose: Contains functions to make programming in C+2
 *               simpler by creating wrapper types and functions for
 *               complicated C++ objects.
 *
 *        Usage: Will be used by C+2 programmer.
 *
 *        Notes:
 *
 */

#include <cmath>
#include <array>
#include <map>

#include "cplustwo.hpp"

namespace cpt::smooth
{

    // PYTHON FUNCTIONS

    // abs(x)
    // not implemented: defined in cmath

    // all(iterable)

    bool _SMOOTH_all(std::vector<bool> iterable)
    {
        for (auto it = iterable.begin(); it != iterable.end(); ++it) {
            if (*it == false) {
                return false;
            }
        }

        return true;
    }

    bool _SMOOTH_all(bool[] iterable)
    {
        for (int i = 0; i < sizeof(iterable) / sizeof(iterable[0]; i++) {
            if (iterable[i] == false) {
                return false;
            }
        }

        return true;
    }

    bool _SMOOTH_all(std::array iterable)
    {
        for (auto it = iterable.begin(); it != iterable.end(); ++it) {
            if (*it == false) {
                return false;
            }
        }

        return true;
    }

    // any

    bool _SMOOTH_any(std::vector<bool> iterable)
    {
        for (auto it = iterable.begin(); it != iterable.end(); ++it) {
            if (*it == true) {
                return true;
            }
        }
    }

    bool _SMOOTH_any(bool[] iterable)
    {
        for (int i = 0; i < sizeof(iterable) / sizeof(iterable[0]; i++) {
            if (iterable[i] == true) {
                return true;
            }
        }
    }

    bool _SMOOTH_any(std::array iterable)
    {
        for (auto it = iterable.begin(); it != iterable.end(); ++it) {
            if (*it == true) {
                return true;
            }
        }
    }

    // ascii()
    // not implemented: cannot do in C++

    // bin(x)
    // not implemented: no binary datatype in C++

    // bool([x])

    bool _SMOOTH_boolean()
    {
        return false;
    }

    bool _SMOOTH_boolean(void* x)
    {
        if (x == nullptr) {
            return false;
        }

        return true;
    }

    bool _SMOOTH_boolean(bool x)
    {
        return x;
    }


    bool _SMOOTH_boolean(double x)
    {
        if (x == 0.0) {
            return false;
        }

        return true;
    }

    // bool boolean(iterable)
    // not implemented: no need/too many types can be made
    // as a template argument for an iterable

    // bytearray([source[, encoding[, errors]]])
    // not implemented: too complicated/no need

    // bytes([source[, encoding[, errors]]])
    // not implemented: too complicated/no need

    // callable(object)
    // not implemented: no C++ equivalent

    // chr(i)
    // not implemented: different way to do this in C++

    // classmethod(function)
    // not implemented: no C++ equivalent

    // compile(source, filename, mode, flags=, dont_inherit=false, optimize=-1)
    // not implemented yet: this function will compile another C+2 program, but I
    // have not written the compiler yet

    // complex([real[, image]])
    // not implemented: no C++ equivalent

    // delattr(object, name)
    // not implemented yet: will be implemented once compiler is finished

    // dict()

}

#endif // SMOOTH_HPP_INCLUDED
