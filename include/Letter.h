#pragma once

#include <iostream>
#include <vector>
#include "Date.h"

// (отправитель, список получателей, тема, тело письма, дата отправки).

class Letter {
public:
    Letter() = delete;
    Letter(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
    Letter(const Letter&);
    ~Letter() = default;
    Letter& operator=(const Letter&);
    Date GetDate() const;
    std::string GetSender() const;
private:
    std::string sender;
    std::string recipient;
    std::string title;
    std::string content;
    Date date;
};