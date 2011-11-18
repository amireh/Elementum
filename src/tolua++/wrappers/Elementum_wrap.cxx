/*
** Lua binding: Elementum
** Generated automatically by tolua++-1.0.92 on Fri Nov 18 15:28:37 2011.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Elementum_open (lua_State* tolua_S);

#include "cegui/FormattedListboxTextItem.h"
#include "CEGUI/CEGUI.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CEGUI::ListboxTextItem");
 tolua_usertype(tolua_S,"CEGUI::FormattedListboxTextItem");
}

/* method: getFormatting of class  CEGUI::FormattedListboxTextItem */
#ifndef TOLUA_DISABLE_tolua_Elementum_CEGUI_FormattedListboxTextItem_getFormatting00
static int tolua_Elementum_CEGUI_FormattedListboxTextItem_getFormatting00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CEGUI::FormattedListboxTextItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CEGUI::FormattedListboxTextItem* self = (const CEGUI::FormattedListboxTextItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFormatting'", NULL);
#endif
  {
   CEGUI::HorizontalTextFormatting tolua_ret = (CEGUI::HorizontalTextFormatting)  self->getFormatting();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFormatting'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFormatting of class  CEGUI::FormattedListboxTextItem */
#ifndef TOLUA_DISABLE_tolua_Elementum_CEGUI_FormattedListboxTextItem_setFormatting00
static int tolua_Elementum_CEGUI_FormattedListboxTextItem_setFormatting00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CEGUI::FormattedListboxTextItem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CEGUI::FormattedListboxTextItem* self = (CEGUI::FormattedListboxTextItem*)  tolua_tousertype(tolua_S,1,0);
  const CEGUI::HorizontalTextFormatting fmt = ((const CEGUI::HorizontalTextFormatting) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFormatting'", NULL);
#endif
  {
   self->setFormatting(fmt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFormatting'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: CEGUI::ceguiLua_createFormattedListboxTextItem */
#ifndef TOLUA_DISABLE_tolua_Elementum_CEGUI_createFormattedListboxTextItem00
static int tolua_Elementum_CEGUI_createFormattedListboxTextItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_iscppstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isuserdata(tolua_S,4,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string text = ((std::string)  tolua_tocppstring(tolua_S,1,0));
  CEGUI::HorizontalTextFormatting format = ((CEGUI::HorizontalTextFormatting) (int)  tolua_tonumber(tolua_S,2,CEGUI::HTF_LEFT_ALIGNED));
  unsigned int item_id = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
  void* item_data = ((void*)  tolua_touserdata(tolua_S,4,0));
  bool disabled = ((bool)  tolua_toboolean(tolua_S,5,false));
  const bool auto_delete = ((const bool)  tolua_toboolean(tolua_S,6,true));
  {
   CEGUI::FormattedListboxTextItem* tolua_ret = (CEGUI::FormattedListboxTextItem*)  CEGUI::ceguiLua_createFormattedListboxTextItem(text,format,item_id,item_data,disabled,auto_delete);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CEGUI::FormattedListboxTextItem");
   tolua_pushcppstring(tolua_S,(const char*)text);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createFormattedListboxTextItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Elementum_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"CEGUI",0);
  tolua_beginmodule(tolua_S,"CEGUI");
   tolua_constant(tolua_S,"HF_LEFT_ALIGNED",CEGUI::HF_LEFT_ALIGNED);
   tolua_constant(tolua_S,"HF_CENTRE_ALIGNED",CEGUI::HF_CENTRE_ALIGNED);
   tolua_constant(tolua_S,"HF_RIGHT_ALIGNED",CEGUI::HF_RIGHT_ALIGNED);
   tolua_constant(tolua_S,"HF_STRETCHED",CEGUI::HF_STRETCHED);
   tolua_constant(tolua_S,"HF_TILED",CEGUI::HF_TILED);
   tolua_constant(tolua_S,"HTF_LEFT_ALIGNED",CEGUI::HTF_LEFT_ALIGNED);
   tolua_constant(tolua_S,"HTF_RIGHT_ALIGNED",CEGUI::HTF_RIGHT_ALIGNED);
   tolua_constant(tolua_S,"HTF_CENTRE_ALIGNED",CEGUI::HTF_CENTRE_ALIGNED);
   tolua_constant(tolua_S,"HTF_JUSTIFIED",CEGUI::HTF_JUSTIFIED);
   tolua_constant(tolua_S,"HTF_WORDWRAP_LEFT_ALIGNED",CEGUI::HTF_WORDWRAP_LEFT_ALIGNED);
   tolua_constant(tolua_S,"HTF_WORDWRAP_RIGHT_ALIGNED",CEGUI::HTF_WORDWRAP_RIGHT_ALIGNED);
   tolua_constant(tolua_S,"HTF_WORDWRAP_CENTRE_ALIGNED",CEGUI::HTF_WORDWRAP_CENTRE_ALIGNED);
   tolua_constant(tolua_S,"HTF_WORDWRAP_JUSTIFIED",CEGUI::HTF_WORDWRAP_JUSTIFIED);
   tolua_cclass(tolua_S,"FormattedListboxTextItem","CEGUI::FormattedListboxTextItem","CEGUI::ListboxTextItem",NULL);
   tolua_beginmodule(tolua_S,"FormattedListboxTextItem");
    tolua_function(tolua_S,"getFormatting",tolua_Elementum_CEGUI_FormattedListboxTextItem_getFormatting00);
    tolua_function(tolua_S,"setFormatting",tolua_Elementum_CEGUI_FormattedListboxTextItem_setFormatting00);
   tolua_endmodule(tolua_S);
   tolua_function(tolua_S,"createFormattedListboxTextItem",tolua_Elementum_CEGUI_createFormattedListboxTextItem00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Elementum (lua_State* tolua_S) {
 return tolua_Elementum_open(tolua_S);
};
#endif

