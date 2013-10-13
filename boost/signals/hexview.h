#ifndef HEXVIEW_H
#define HEXVIEW_H

#include "view.h"
#include "document.h"

class HexView : public View
{
public:
    HexView(Document& doc);
    virtual void refresh(bool bExtended) const;
};

#endif // HEXVIEW_H
