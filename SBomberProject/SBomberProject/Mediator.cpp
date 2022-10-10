#include "Mediator.h"

void Mediator::SetQueue(std::queue<std::string>* pQueueString)
{
    pQueueStrings = pQueueString;
}
void Mediator::PutInTheQueue(const std::string& str) const
{
    pQueueStrings->push(str);
}
std::string Mediator::TakeFromTheQueue() const
{
    std::string s = pQueueStrings->front();
    pQueueStrings->pop();
    return s;
}