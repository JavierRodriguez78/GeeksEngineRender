#include "Logger.h"
#include <vector>
#include <iostream>
#include <iomanip>

static std::string LOG_TYPE_NAME[] =
{
    "DEFAULT",
    "DEBUG",
    "INIT",
    "WARNING",
    "ERROR",
};

int nrLogTypes = LOG_ERROR - LOG_DEFAULT + 1;

std::vector<std::vector<std::string>> Logger::m_LogEntries = std::vector<std::vector<std::string>>(nrLogTypes);


unsigned int Logger::m_Filter = LOG_TYPE::LOG_DEFAULT |
LOG_TYPE::LOG_DEBUG |
LOG_TYPE::LOG_INIT |
LOG_TYPE::LOG_WARNING |
LOG_TYPE::LOG_ERROR;

void Logger::Message(const std::string& message, const LOG_TYPE type)
{
    // push message into proper log queue for later display and/or write-to-disk
    m_LogEntries[type].push_back(message);

    if (type == LOG_TYPE::LOG_DEFAULT && m_Filter & LOG_TYPE::LOG_DEFAULT ||
        type == LOG_TYPE::LOG_DEBUG && m_Filter & LOG_TYPE::LOG_DEBUG ||
        type == LOG_TYPE::LOG_INIT && m_Filter & LOG_TYPE::LOG_INIT ||
        type == LOG_TYPE::LOG_WARNING && m_Filter & LOG_TYPE::LOG_WARNING ||
        type == LOG_TYPE::LOG_ERROR && m_Filter & LOG_TYPE::LOG_ERROR)
    {
        Logger::printMessage(message, type);
    }
}

void Logger::printMessage(const std::string& message, const LOG_TYPE type)
{
    std::string typeName = "DEFAULT";
    // TODO(Joey): solve this w/ preprocessor magic
    if (type == LOG_TYPE::LOG_DEBUG)  typeName = "DEBUG";
    if (type == LOG_TYPE::LOG_INIT)   typeName = "INIT";
    if (type == LOG_TYPE::LOG_ERROR)  typeName = "ERROR";
    if (type == LOG_TYPE::LOG_WARNING) typeName = "WARNING";

    std::cout << std::setw(7) << typeName << ":  " << message << std::endl;
}