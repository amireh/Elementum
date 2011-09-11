/*
 *  required.h
 *  Elementum
 *
 *  Created by Ahmad Amireh on 3/7/10.
 *  Copyright 2010 JU. All rights reserved.
 *
 */

#include "Pixy.h"
#include "cegui/FormattedListboxTextItem.h"

namespace CEGUI {
  FormattedListboxTextItem* ceguiLua_createFormattedListboxTextItem(
      const String& text,
      const HorizontalTextFormatting format,
      const uint item_id,
      void* const item_data,
      const bool disabled,
      const bool auto_delete);
}
