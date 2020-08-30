#include "Letter.h"

Letter::Letter(const std::string& _sender, const std::string& _recipient, const std::string& _title,
               const std::string& _content, const std::string& _date)
               : sender(_sender)
               , recipient(_recipient)
               , title(_title)
               , content(_content)
               , date(_date) {}

Letter::Letter(const Letter& letter)
    : sender(letter.sender)
    , recipient(letter.recipient)
    , title(letter.title)
    , content(letter.content)
    , date(letter.date) {}

Letter& Letter::operator=(const Letter& rhs) {
    if (this == &rhs) {
        return *this;
    }
    sender = rhs.sender;
    recipient = rhs.recipient;
    title = rhs.title;
    content = rhs.content;
    date = rhs.date;
    return *this;
}

Date Letter::GetDate() const {
    return date;
}

std::string Letter::GetSender() const {
    return sender;
}


