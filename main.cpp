#include <iostream>
#include <chrono>
#include "Date.h"
#include <thread>
#include <LetterList.h>
#include "tests.h"

// В вашем распоряжении – данные о письмах пользователей
// (отправитель, список получателей, тема, тело письма, дата отправки).
// Суммарное количество пользователей – 10к, писем – 1 млн. Реализуйте
// последовательный и параллельный алгоритм поиска с использованием нескольких
// потоков отправителя, от которого пришло больше всех писем за определённый временной промежуток.

int main() {
//    size_t n = 0;
//    std::cin >> n;
//    LetterList list;
//    std::cout << "Введите отправителя, получателя, тему, тело письма и дату отправки(в формате dd/mm/yyyy)"
//              << std::endl;
//    for (size_t i = 0; i < n; ++i) {
//        std::string sender, title, recipient, text, date;
//        std::cin >> sender >> recipient >> title >> text >> date;
//        list.Add(Letter(sender, recipient, title, text, date));
//    }
//    std::string result = list.GetMostActiveSender("01/01/2007", "01/01/2009");
//    std::cout << result;
    integrationTest();
    std::cout << "я устал" << std::endl;
    return 0;
}
