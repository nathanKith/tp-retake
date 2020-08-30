#pragma once

#include "Letter.h"
#include "Date.h"
#include <iostream>
#include <vector>
#include <unordered_map>

class LetterList {
public:
    LetterList() = default;
    ~LetterList() = default;
    void Add(const Letter&);
    std::string GetMostActiveSender(const std::string&, const std::string&);
private:
    std::vector<Letter> letters;

    std::vector<Letter> filterByDate(const Date&, const Date&);
    void getMostActiveSenderInternal(std::unordered_map<std::string, int>&,
                                                            size_t begin, size_t end,
                                                            const std::vector<Letter>&);
};