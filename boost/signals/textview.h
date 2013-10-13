#ifndef TEXTVIEW_H
#define TEXTVIEW_H

#include "view.h"
#include "document.h"

class TextView : public View
{
public:
    TextView(Document& doc);
    virtual void refresh(bool bExtended) const;
};

#endif // TEXTVIEW_H
