#include "Date.h"
#include <algorithm>
#include <stdexcept>


bool Date::operator<(const Date& rhs) const {
    if (year < rhs.year) {
        return true;
    } else if (year > rhs.year) {
        return false;
    }

    if (month < rhs.month) {
        return true;
    } else if (month > rhs.month) {
        return false;
    }

    return day < rhs.day;
}

bool Date::operator>=(const Date& rhs) const {
    return !(*this < rhs);
}

Date::Date(const std::string& _date) {
    if (!parseDate(_date)) {
        throw std::exception(); // for debug
    }
}

Date::Date(const Date& _date)
        : day(_date.day)
        , month(_date.month)
        , year(_date.year) {}

bool Date::parseDate(const std::string& _date) {
    if (_date.length() != DATE_STR_SIZE) {
        return false;
    }

    auto numberOfSlashes = std::count(_date.begin(), _date.end(), '/');
    if (numberOfSlashes != NUM_OF_SLASHS) {
        return false;
    }

    if (countDigits(_date) != DATE_STR_SIZE - NUM_OF_SLASHS) {
        return false;
    }

    try {
        const size_t DAY_MONTH_LEN = 2;
        size_t _day = std::stoi(_date.substr(0, DAY_MONTH_LEN));
        size_t _month = std::stoi(_date.substr(_date.find('/') + 1, DAY_MONTH_LEN));
        size_t _year = std::stoi(_date.substr(
                _date.find('/', _date.find('/') + 1) + 1));
        if (!validation(_day, _month, _year)) {
            return false;
        }
        day = _day;
        month = _month;
        year = _year;
        return true;
    } catch(const std::invalid_argument& ex) {
        std::cout << ex.what();
        return false;
    }
}

bool Date::validation(size_t _day, size_t _month, size_t _year) {
    bool isLeap = false;
    if ( _year % 4 == 0 ) {
        isLeap = true;
    }
    if ( _day < 1 || _day > 31 ) {
        return false;
    }
    if ( _month < 1 || _month > 12 ) {
        return false;
    }
    if ( _month == 2 && _day > 29 && isLeap) {
        return false;
    }
    if ( _month == 2 && _day > 28 && !isLeap) {
        return false;
    }
    if ( _month == 4 || _month == 6 || _month == 9 || _month == 11 ) {
        if ( _day > 30 ) {
            return false;
        }
    }

    return true;
}

size_t Date::countDigits(const std::string& s) {
    return std::count_if(
            s.begin(),
            s.end(),
            [](unsigned char c) {
                return std::isdigit(c);
            }
    );
}

Date& Date::operator=(const Date& rhs) {
    if (this == &rhs) {
        return *this;
    }
    day = rhs.day;
    month = rhs.month;
    year = rhs.year;
    return *this;
}
