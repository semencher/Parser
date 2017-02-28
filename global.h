#pragma once

#include <QString>

class ErrorParser
{
    QString message_;
public:
    ErrorParser(QString message = "")
    {
        message_ = message;
    }
    void setMessage(const QString message)
    {
        message_ = message;
    }
    QString getError()
    {
        return message_;
    }
};
