#pragma once
#include <iostream>
#include <queue>

class Mediator
{
private:
    std::queue<std::string>* pQueueStrings;

public:
    Mediator() { pQueueStrings = nullptr; }
    ~Mediator() { pQueueStrings = nullptr; }
    void SetQueue(std::queue<std::string>* pQueueStrings);
    void PutInTheQueue(const std::string& str) const;
    std::string TakeFromTheQueue() const;
};
