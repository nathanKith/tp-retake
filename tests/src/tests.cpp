#include "tests.h"
#include "LetterList.h"
#include <array>
#include <fstream>

const std::array<std::string, 3> RESULTS = {
        "those",
        "",
        "compare",
};

static std::string pathJoin(int i) {
    return std::string("../tests/data/case_" + std::to_string(i) + "/in.txt");
}

static std::string _integrationTest(int i) {
    std::ifstream file(pathJoin(i + 1));
    if (!file) {
        std::cout << "все плохо с файлом";
        return "";
    }
    int n = 0;
    std::cout << "input:" << std::endl;
    file >> n;
    std::cout << n << std::endl;
    LetterList list;
    for (int j = 0; j < n; ++j) {
        std::string sender, title, recipient, text, date;
        file >> sender >> recipient >> title >> text >> date;
        std::cout << sender << ' ' << recipient << ' ' << title << ' ' << text << ' ' << date << std::endl;
        list.Add(Letter(sender, recipient, title, text, date));
    }
    std::string lDate, rDate;
    file >> lDate >> rDate;
    std::cout << lDate  << ' ' << rDate << ' ' << std::endl << std::endl; 
    std::string result = list.GetMostActiveSender(lDate, rDate);
    file.close();
    return result;
}

bool integrationTest() {
    for (int i = 0; i < 3; ++i) {
        if (_integrationTest(i) == RESULTS[i]) {
            std::cout << std::endl << "output:" << RESULTS[i] << std::endl;
            std::cout << "CASE_" << i + 1 << "...OK!" << std::endl << std::endl;
        } else {
            std::cout << "CASE_" << i + 1 << "...BAD!" << std::endl << std::endl;
            return false;
        }
    }
    return true;
}
