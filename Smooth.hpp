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
#include <fstream>
#include <numeric>
#include <algorithm>
#include <sstream>

#include "cplustwo.hpp"

namespace cpt
{
    namespace smooth
    {

        void generateError(std::string message)
        {
            throw std::runtime_error(message);
        }

        // PYTHON FUNCTIONS PYTHON FUNCTIONS PYTHON FUNCTIONS PYTHON FUNCTIONS PYTHON FUNCTIONS

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

        bool _SMOOTH_bool(void* x)
        {
            if (x == nullptr) {
                return false;
            }

            return true;
        }

        bool _SMOOTH_bool(double x)
        {
            if (x == 0.0) {
                return false;
            }

            return true;
        }

        bool _SMOOTH_bool(std::string x)
        {
            if (x == "true") {
                return true;
            }
            else {
                return false;
            }
        }

        // dict()
        template<typename key, typename value>
        std::map<key, value> _SMOOTH_dict()
        {
            return std::map<key, value> {};
        }

        std::array<long, 2> _SMOOTH_divmod(long a, long b)
        {
            return std::array<long, 2> { a / b, a % b };
        }

        std::array<int, 2> _SMOOTH_divmod(int a, int b)
        {
            return std::array<int, 2> { a / b, a % b };
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

        int _SMOOTH_int(char c)
        {
            return static_cast<int>(c);
        }

        int _SMOOTH_len(std::string s)
        {
            return s.length();
        }

        template<typename T>
        std::vector<T> _SMOOTH_list()
        {
            return std::vector<T> { };
        }

        double _SMOOTH_max(std::vector<double> iterable)
        {
            if (iterable.size() < 1) {
                return std::numeric_limits<int>::quiet_NaN();
            }

            double maximum = iterable.at(0);
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

        double _SMOOTH_min(std::vector<double> iterable)
        {
            if (iterable.size() < 1) {
                return std::numeric_limits<int>::quiet_NaN();
            }

            double minimum = iterable.at(0);
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

        // print()

        void _SMOOTH_write(std::string text)
        {
            std::cout << text << "\n";
        }

        // range()

        std::vector<int> _SMOOTH_range(int start, int stop, int step=1)
        {
            std::vector<int> rangeVector(stop - start + 1);
            std::iota(rangeVector.begin(), rangeVector.end(), start);
            return rangeVector;
        }

        std::vector<int> _SMOOTH_range(int stop, int step=1)
        {
            return _SMOOTH_range(1, stop, step);
        }

        // sort()

        std::vector<int> _SMOOTH_sort(std::vector<int> iterable, bool reversed = false)
        {
            std::vector<int> copyVector(iterable);
            std::sort(copyVector.begin(), copyVector.end());
            return copyVector;
        }

        std::string _SMOOTH_string(int i)
        {
            std::ostringstream os;
            os << i;
            return os.str();
        }

        int _SMOOTH_sum(std::vector<int> iterable)
        {
            int sum = 0;
            for (auto it = iterable.begin(); it != iterable.end(); ++it) {
                sum += *it;
            }

            return sum;
        }

        float _SMOOTH_sum(std::vector<float> iterable)
        {
            float sum = 0;
            for (auto it = iterable.begin(); it != iterable.end(); ++it) {
                sum += *it;
            }

            return sum;
        }

        // SMOOTH FUNCTIONS
        template <typename T>
        void _SMOOTH_append(std::vector<T>& container, T item)
        {
            container.push_back(item);
        }

    }
}

#endif // SMOOTH_HPP_INCLUDED
