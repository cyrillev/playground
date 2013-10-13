#include "textview.h"

TextView::TextView(Document& doc)
    : View(doc)
{

}

void TextView::refresh(bool bExtended) const
{
    std::cout << "TextView: " << m_document.getText() << std::endl;
}
