#include "LetterList.h"
#include <algorithm>
#include <unordered_map>
#include <set>
#include <thread>

std::vector<Letter> LetterList::filterByDate(const Date& lhs, const Date& rhs) {
    std::vector<Letter> filtered;
    std::copy_if(letters.begin(), letters.end(), std::back_inserter(filtered),
            [&](const Letter& letter) { return letter.GetDate() < rhs && letter.GetDate() >= lhs; });
    return filtered;
}

void LetterList::Add(const Letter& letter) {
    letters.push_back(letter);
}

std::string LetterList::GetMostActiveSender(const std::string& lhs_date, const std::string& rhs_date) {
    std::vector<Letter> filtered = std::move(filterByDate(Date(lhs_date), Date(rhs_date)));

    std::unordered_map<std::string, int> senders;
    for (const auto& item : filtered) {
        senders.insert(std::make_pair(item.GetSender(), 0));
    }
    std::vector<std::thread> threads;
    if (std::thread::hardware_concurrency() < filtered.size()) {
        size_t n = std::thread::hardware_concurrency() / filtered.size();
        size_t i = std::thread::hardware_concurrency() - 1;
        std::thread lastThr(&LetterList::getMostActiveSenderInternal, this,
                std::ref(senders), i * n, filtered.size(), filtered);
        threads.push_back(std::move(lastThr));
        for (; i < std::thread::hardware_concurrency() - 1; ++i) {
            getMostActiveSenderInternal(senders, i * n, (i + 1) * n, filtered);
            std::thread thr(&LetterList::getMostActiveSenderInternal, this,
                    std::ref(senders), i * n, (i + 1) * n, filtered);
            threads.push_back(std::move(thr));
        }

    } else {
        for (size_t i = 0; i < filtered.size(); ++i) {
            std::thread thr(&LetterList::getMostActiveSenderInternal, this,
                    std::ref(senders), i, i + 1, filtered);
            threads.push_back(std::move(thr));
        }
    }

    for (auto&& thr : threads) {
        thr.join();
    }

    std::string sender;
    int max = -1;
    for (const auto& item : senders) {
        if (item.second > max) {
            max = item.second;
            sender = item.first;
        }
    }
    return sender;
}

void LetterList::getMostActiveSenderInternal(std::unordered_map<std::string, int>& senderData,
                                             size_t begin, size_t end,
                                             const std::vector<Letter>& data) {
    for (size_t i = begin; i < end; ++i) {
        senderData[data[i].GetSender()]++;
    }
}
