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
#include <string>
#include <cstdlib>
#include <limits>

#include "cplustwo.hpp"

namespace cpt
{
    namespace smooth
    {
        // PYTHON FUNCTIONS

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

        bool _SMOOTH_all(bool iterable[])
        {

            for (int i = 0; i < ((signed) sizeof(iterable) / (signed) sizeof(iterable[0])); i++) {
                if (iterable[i] == true) {
                    return true;
                }
            }

            return false;
        }

        // any

        bool _SMOOTH_any(std::vector<bool> iterable)
        {
            for (auto it = iterable.begin(); it != iterable.end(); ++it) {
                if (*it == true) {
                    return true;
                }
            }

            return false;
        }

        bool _SMOOTH_any(bool iterable[])
        {
            for (int i = 0; i < ((signed) sizeof(iterable) / (signed) sizeof(iterable[0])); i++) {
                if (iterable[i] == true) {
                    return true;
                }
            }

            return false;
        }

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

        // dict()
        template<typename key, typename value>
        std::map<key, value> _SMOOTH_dict()
        {
            return std::map<key, value> {};
        }

        // divmod(a, b)
        std::array<int, 2> _SMOOTH_divmod(int a, int b)
        {
            return std::array<int, 2> { a / b, a % b };
        }

        std::array<unsigned, 2> _SMOOTH_divmod(unsigned a, unsigned b)
        {
            return std::array<unsigned, 2> { a / b, a % b };
        }

        std::array<long, 2> _SMOOTH_divmod(long a, long b)
        {
            return std::array<long, 2> { a / b, a % b };
        }

        std::string _SMOOTH_input(std::string prompt = "")
        {
            std::string text;
            std::cout << prompt;
            std::cin >> text;
            return text;
        }

        int _SMOOTH_int(std::string text)
        {
            char* endPtr;
            return std::strtol(text.c_str(), &endPtr, 10);
        }

        int _SMOOTH_len(std::string s)
        {
            return s.length();
        }

        template<typename T>
        std::vector<T> _SMOOTH_createList()
        {
            return std::vector<T> { };
        }

        int _SMOOTH_max(std::vector<int> iterable)
        {
            if (iterable.size() < 1) {
                return std::numeric_limits<int>::quiet_NaN();
            }

            int maximum = iterable.at(0);
            for (auto it = iterable.begin(); it != iterable.end(); ++it) {
                if (*it > maximum) {
                    maximum = *it;
                }
            }

            return maximum;
        }

        long _SMOOTH_max(std::vector<long> iterable)
        {
            if (iterable.size() < 1) {
                return std::numeric_limits<int>::quiet_NaN();
            }

            long maximum = iterable.at(0);
            for (auto it = iterable.begin(); it != iterable.end(); ++it) {
                if (*it > maximum) {
                    maximum = *it;
                }
            }

            return maximum;
        }

        int _SMOOTH_min(std::vector<int> iterable)
        {
            if (iterable.size() < 1) {
                return std::numeric_limits<int>::quiet_NaN();
            }

            int minimum = iterable.at(0);
            for (auto it = iterable.begin(); it != iterable.end(); ++it) {
                if (*it < minimum) {
                    minimum = *it;
                }
            }

            return minimum;
        }

        long _SMOOTH_min(std::vector<long> iterable)
        {
            if (iterable.size() < 1) {
                return std::numeric_limits<int>::quiet_NaN();
            }

            long minimum = iterable.at(0);
            for (auto it = iterable.begin(); it != iterable.end(); ++it) {
                if (*it < minimum) {
                    minimum = *it;
                }
            }

            return minimum;
        }
    }
}

#endif // SMOOTH_HPP_INCLUDED
