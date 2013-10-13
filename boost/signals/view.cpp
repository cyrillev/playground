#include "view.h"

View::View(Document& m)
    : m_document(m)
{
    m_connection = m_document.connect(boost::bind(&View::refresh, this, _1));
}

View::~View()
{
    m_document.disconnect(m_connection);
}
