#ifndef LOGGER_H
#define LOGGER_H

#include <string>

// LOG_INFO("%s %d", arg1, arg2)
#define LOG_INFO(logmsgFormat, ...)                       \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::instance();              \
        logger.setLogLevel(INFO);                         \
        char buf[1024] = {0};                             \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.log(buf);                                  \
    } while (0)

#define LOG_ERROR(logmsgFormat, ...)                      \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::instance();              \
        logger.setLogLevel(ERR);                        \
        char buf[1024] = {0};                             \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
        logger.log(buf);                                  \
    } while (0)

// ������־�ļ��� INFO ERR FATAL DEBUG
enum LogLevel
{
    INFO,   // ��ͨ��Ϣ
    ERR,    // ������Ϣ
};

// ���һ����־��

class Logger
{
public:
    // ��ȡ��־Ψһ��ʵ������ ����
    static Logger& instance();
    // ������־����
    void setLogLevel(int level);
    // д��־
    void log(std::string msg);

private:
    int logLevel_;
};

#endif LOGGER_H