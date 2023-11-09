#include <iostream>
#include "../include/Logger.h"
#include "../include/Timestamp.h"

// ��ȡ��־Ψһ��ʵ������ ����
Logger& Logger::instance()
{
    static Logger logger;
    return logger;
}

// ������־����
void Logger::setLogLevel(int level)
{
    logLevel_ = level;
}

// д��־ [������Ϣ] time : msg
void Logger::log(std::string msg)
{
    std::string pre = "";
    switch (logLevel_)
    {
    case INFO:
        pre = "[INFO]";
        break;
    case ERR:
        pre = "[ERR]";
        break;
    default:
        break;
    }

    // ��ӡʱ���msg
    std::cout << pre + Timestamp::now().toString() << " : " << msg << std::endl;
}