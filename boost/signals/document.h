#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <boost/signals2.hpp>
#include <boost/signals2/connection.hpp>

class Document
{
public:
    typedef boost::signals2::signal<void (bool)>  signal_t;
    typedef boost::signals2::connection  connection_t;

public:
    Document();
    connection_t connect(signal_t::slot_function_type subscriber);
    void disconnect(connection_t subscriber);

    void append(const char* s);
    const std::string& getText() const;

private:
    signal_t    m_sig;
    std::string m_text;
};

#endif // DOCUMENT_H
