#include "FormattedListboxTextItem.h"

namespace CEGUI
{
  // allocates and returns a new ListboxTextItem
  FormattedListboxTextItem* ceguiLua_createFormattedListboxTextItem(
    const String& text,
    const HorizontalTextFormatting format,
    const uint item_id,
    void* const item_data,
    const bool disabled,
    const bool auto_delete)
  {
    return new FormattedListboxTextItem(text, format, item_id, item_data, disabled, auto_delete);
  }
}
