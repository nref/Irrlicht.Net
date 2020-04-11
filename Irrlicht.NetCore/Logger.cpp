#include "stdafx.h"
#include "Logger.h"
#include "ReferenceCounted.h"

using namespace irr;
using namespace System;
using namespace IrrlichtNetCore::Core;

namespace IrrlichtNetCore {

Logger^ Logger::Wrap(irr::ILogger* ref)
{
    if (ref == nullptr)
        return nullptr;

    return gcnew Logger(ref);
}

Logger::Logger(irr::ILogger* ref)
    : ReferenceCounted(ref)
{
    LIME_ASSERT(ref != nullptr);
    m_Logger = ref;
}

void Logger::Log(String^ text, String^ hint, IrrlichtNetCore::LogLevel level)
{
    m_Logger->log(
        LIME_SAFESTRINGTOSTRINGW_C_STR(text),
        LIME_SAFESTRINGTOSTRINGW_C_STR(hint),
        (irr::ELOG_LEVEL)level);
}

void Logger::Log(String^ text, IrrlichtNetCore::LogLevel level)
{
    m_Logger->log(
        LIME_SAFESTRINGTOSTRINGW_C_STR(text),
        (irr::ELOG_LEVEL)level);
}

void Logger::Log(String^ text)
{
    m_Logger->log(
        LIME_SAFESTRINGTOSTRINGW_C_STR(text));
}

IrrlichtNetCore::LogLevel Logger::LogLevel::get()
{
    return (IrrlichtNetCore::LogLevel)m_Logger->getLogLevel();
}

void Logger::LogLevel::set(IrrlichtNetCore::LogLevel value)
{
    m_Logger->setLogLevel((irr::ELOG_LEVEL)value);
}

String^ Logger::ToString()
{
    return String::Format("Logger: LogLevel={0}", LogLevel);
}

} // end namespace IrrlichtNetCore
