#pragma once
#ifndef UTILITY_LOGGER_H
#define UTILITY_LOGGER_H

#include <vector>
#include <string>

enum LOG_TYPE
{
    LOG_DEFAULT = 0,
    LOG_DEBUG = 2,
    LOG_INIT = 4,
    LOG_WARNING = 8,
    LOG_ERROR = 16,
};

class Logger
{
private:
    static std::vector<std::vector<std::string>> m_LogEntries;
    static unsigned int m_Filter;
    static void printMessage(const std::string& message, const LOG_TYPE type);

public:
    static void Message(const std::string& message, const LOG_TYPE type = LOG_DEFAULT);




};

#endif
