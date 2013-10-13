#include "hexview.h"

HexView::HexView(Document& doc)
    : View(doc)
{
}

void HexView::refresh(bool bExtended) const
{
    const std::string&  s = m_document.getText();

    std::cout << "HexView:";

    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
        std::cout << ' ' << std::hex << static_cast<int>(*it);

    std::cout << std::endl;
}
