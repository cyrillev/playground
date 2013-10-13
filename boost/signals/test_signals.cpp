#include "document.h"
#include "textview.h"
#include "hexview.h"

void test_signals()
{
    Document    doc;
    TextView    v1(doc);
    HexView     v2(doc);

    doc.append("Hello world!");
}
