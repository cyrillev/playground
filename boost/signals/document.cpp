#include "document.h"

Document::Document()
{}

Document::connection_t Document::connect(signal_t::slot_function_type subscriber)
{
    return m_sig.connect(subscriber);
}

void Document::disconnect(connection_t subscriber)
{
    subscriber.disconnect();
}

void Document::append(const char* s)
{
    m_text += s;
    m_sig(true);
}

const std::string& Document::getText() const
{
    return m_text;
}
