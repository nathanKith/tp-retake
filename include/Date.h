#pragma once

#include <iostream>


// дата передается в формате dd/mm/yyyy
class Date {
public:
    Date() = delete;
    explicit Date(const std::string&);
    Date(const Date&);
    ~Date() = default;

    bool operator<(const Date&) const;
    bool operator>=(const Date&) const;
    Date& operator=(const Date&);
private:
    size_t day, month, year;

    const size_t NUM_OF_SLASHS = 2;
    const size_t DATE_STR_SIZE = 10;

    bool parseDate(const std::string&);
    bool validation(size_t, size_t, size_t);
    size_t countDigits(const std::string&);
};
