#ifndef VIEW_H
#define VIEW_H

#include "document.h"

class View
{
public:
    View(Document& m);
    virtual ~View();

    virtual void refresh(bool bExtended) const = 0;

protected:
    Document& m_document;

private:
    Document::connection_t  m_connection;
};

#endif // VIEW_H
