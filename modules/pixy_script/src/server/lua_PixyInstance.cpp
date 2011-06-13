/*
** Lua binding: PixyInstance
** Generated automatically by tolua++-1.0.93 on Fri May 20 13:21:12 2011.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_PixyInstance_open (lua_State* tolua_S);

#include "required.h"
#include "EventManager.h"
#include "EventListener.h"
#include "Event.h"
#include "EntityEvent.h"
#include "Entity.h"
#include "Spell.h"
#include "SpellEffect.h"
#include "Deck.h"
#include "Unit.h"
#include "UnitFactory.h"
#include "Puppet.h"
#include "Unit.h"
#include "PuppetFactory.h"
#include "Player.h"
#include "Instance.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Pixy__Entity (lua_State* tolua_S)
{
 Pixy::Entity* self = (Pixy::Entity*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__Unit (lua_State* tolua_S)
{
 Pixy::Unit* self = (Pixy::Unit*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__Spell (lua_State* tolua_S)
{
 Pixy::Spell* self = (Pixy::Spell*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__Puppet (lua_State* tolua_S)
{
 Pixy::Puppet* self = (Pixy::Puppet*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__EventListener (lua_State* tolua_S)
{
 Pixy::EventListener* self = (Pixy::EventListener*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"EntityFactory");
 tolua_usertype(tolua_S,"Pixy::Spell");
 tolua_usertype(tolua_S,"Pixy::Event");
 tolua_usertype(tolua_S,"Pixy::Deck");
 tolua_usertype(tolua_S,"list<Pixy::Player*>");
 tolua_usertype(tolua_S,"Pixy::Player");
 tolua_usertype(tolua_S,"CEGUI::Window");
 tolua_usertype(tolua_S,"Pixy::UnitFactory");
 tolua_usertype(tolua_S,"Pixy::EventManager");
 tolua_usertype(tolua_S,"Pixy::Puppet");
 tolua_usertype(tolua_S,"Pixy::PuppetFactory");
 tolua_usertype(tolua_S,"Pixy::Entity");
 tolua_usertype(tolua_S,"Pixy::Instance");
 tolua_usertype(tolua_S,"Pixy::EventListener");
 tolua_usertype(tolua_S,"Pixy::Unit");
 tolua_usertype(tolua_S,"list<Pixy::Spell*>");
 tolua_usertype(tolua_S,"Pixy::EntityEvent");
 tolua_usertype(tolua_S,"vector<Pixy::Unit*>");
}

/* method: getSingletonPtr of class  Pixy::EventManager */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_EventManager_getSingletonPtr00
static int tolua_PixyInstance_Pixy_EventManager_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::EventManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::EventManager* tolua_ret = (Pixy::EventManager*)  Pixy::EventManager::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::EventManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingletonPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createEvt of class  Pixy::EventManager */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_EventManager_createEvt00
static int tolua_PixyInstance_Pixy_EventManager_createEvt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::EventManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::EventManager* self = (Pixy::EventManager*)  tolua_tousertype(tolua_S,1,0);
  std::string inName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createEvt'", NULL);
#endif
  {
   Pixy::Event* tolua_ret = (Pixy::Event*)  self->createEvt(inName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Event");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createEvt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createEntityEvt of class  Pixy::EventManager */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_EventManager_createEntityEvt00
static int tolua_PixyInstance_Pixy_EventManager_createEntityEvt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::EventManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::EventManager* self = (Pixy::EventManager*)  tolua_tousertype(tolua_S,1,0);
  std::string inName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createEntityEvt'", NULL);
#endif
  {
   Pixy::EntityEvent* tolua_ret = (Pixy::EntityEvent*)  self->createEntityEvt(inName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::EntityEvent");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createEntityEvt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hook of class  Pixy::EventManager */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_EventManager_hook00
static int tolua_PixyInstance_Pixy_EventManager_hook00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::EventManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::EventManager* self = (Pixy::EventManager*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Event* inEvt = ((Pixy::Event*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hook'", NULL);
#endif
  {
   self->hook(inEvt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hook'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Pixy::EventListener */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_EventListener_new00
static int tolua_PixyInstance_Pixy_EventListener_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::EventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::EventListener* tolua_ret = (Pixy::EventListener*)  Mtolua_new((Pixy::EventListener)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::EventListener");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Pixy::EventListener */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_EventListener_new00_local
static int tolua_PixyInstance_Pixy_EventListener_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::EventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::EventListener* tolua_ret = (Pixy::EventListener*)  Mtolua_new((Pixy::EventListener)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::EventListener");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Pixy::EventListener */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_EventListener_delete00
static int tolua_PixyInstance_Pixy_EventListener_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::EventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::EventListener* self = (Pixy::EventListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enqueue of class  Pixy::EventListener */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_EventListener_enqueue00
static int tolua_PixyInstance_Pixy_EventListener_enqueue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::EventListener",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::EventListener* self = (Pixy::EventListener*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Event* inEvt = ((Pixy::Event*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enqueue'", NULL);
#endif
  {
   self->enqueue(inEvt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enqueue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCategory of class  Pixy::Event */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Event_setCategory00
static int tolua_PixyInstance_Pixy_Event_setCategory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Event",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Event* self = (Pixy::Event*)  tolua_tousertype(tolua_S,1,0);
  const std::string inCategory = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCategory'", NULL);
#endif
  {
   self->setCategory(inCategory);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCategory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCategory of class  Pixy::Event */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Event_getCategory00
static int tolua_PixyInstance_Pixy_Event_getCategory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Event* self = (const Pixy::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCategory'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getCategory();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCategory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setName of class  Pixy::Event */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Event_setName00
static int tolua_PixyInstance_Pixy_Event_setName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Event",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Event* self = (Pixy::Event*)  tolua_tousertype(tolua_S,1,0);
  const std::string inName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setName'", NULL);
#endif
  {
   self->setName(inName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getName of class  Pixy::Event */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Event_getName00
static int tolua_PixyInstance_Pixy_Event_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Event* self = (const Pixy::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setType of class  Pixy::Event */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Event_setType00
static int tolua_PixyInstance_Pixy_Event_setType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Event",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Event* self = (Pixy::Event*)  tolua_tousertype(tolua_S,1,0);
  Pixy::EVENT_TYPE inType = ((Pixy::EVENT_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setType'", NULL);
#endif
  {
   self->setType(inType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getType of class  Pixy::Event */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Event_getType00
static int tolua_PixyInstance_Pixy_Event_getType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Event* self = (const Pixy::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getType'", NULL);
#endif
  {
   Pixy::EVENT_TYPE tolua_ret = (Pixy::EVENT_TYPE)  self->getType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFeedback of class  Pixy::Event */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Event_setFeedback00
static int tolua_PixyInstance_Pixy_Event_setFeedback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Event",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Event* self = (Pixy::Event*)  tolua_tousertype(tolua_S,1,0);
  Pixy::EVENT_FEEDBACK inMsg = ((Pixy::EVENT_FEEDBACK) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFeedback'", NULL);
#endif
  {
   self->setFeedback(inMsg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFeedback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFeedback of class  Pixy::Event */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Event_getFeedback00
static int tolua_PixyInstance_Pixy_Event_getFeedback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Event* self = (const Pixy::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFeedback'", NULL);
#endif
  {
   Pixy::EVENT_FEEDBACK tolua_ret = (Pixy::EVENT_FEEDBACK)  self->getFeedback();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFeedback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setProperty of class  Pixy::Event */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Event_setProperty00
static int tolua_PixyInstance_Pixy_Event_setProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Event",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Event* self = (Pixy::Event*)  tolua_tousertype(tolua_S,1,0);
  const std::string inName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string inValue = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProperty'", NULL);
#endif
  {
   self->setProperty(inName,inValue);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getProperty of class  Pixy::Event */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Event_getProperty00
static int tolua_PixyInstance_Pixy_Event_getProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Event",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Event* self = (const Pixy::Event*)  tolua_tousertype(tolua_S,1,0);
  std::string inName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProperty'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getProperty(inName);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: propertyExists of class  Pixy::Event */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Event_propertyExists00
static int tolua_PixyInstance_Pixy_Event_propertyExists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Event",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Event* self = (Pixy::Event*)  tolua_tousertype(tolua_S,1,0);
  const std::string inName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'propertyExists'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->propertyExists(inName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)inName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'propertyExists'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dump of class  Pixy::Event */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Event_dump00
static int tolua_PixyInstance_Pixy_Event_dump00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Event* self = (Pixy::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dump'", NULL);
#endif
  {
   self->dump();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dump'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setObjectId of class  Pixy::EntityEvent */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_EntityEvent_setObjectId00
static int tolua_PixyInstance_Pixy_EntityEvent_setObjectId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::EntityEvent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::EntityEvent* self = (Pixy::EntityEvent*)  tolua_tousertype(tolua_S,1,0);
  int inObjectId = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setObjectId'", NULL);
#endif
  {
   self->setObjectId(inObjectId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setObjectId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getObjectId of class  Pixy::EntityEvent */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_EntityEvent_getObjectId00
static int tolua_PixyInstance_Pixy_EntityEvent_getObjectId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::EntityEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::EntityEvent* self = (Pixy::EntityEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getObjectId'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getObjectId();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getObjectId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOwner of class  Pixy::EntityEvent */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_EntityEvent_setOwner00
static int tolua_PixyInstance_Pixy_EntityEvent_setOwner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::EntityEvent",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::EntityEvent* self = (Pixy::EntityEvent*)  tolua_tousertype(tolua_S,1,0);
  std::string inName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOwner'", NULL);
#endif
  {
   self->setOwner(inName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOwner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOwner of class  Pixy::EntityEvent */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_EntityEvent_getOwner00
static int tolua_PixyInstance_Pixy_EntityEvent_getOwner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::EntityEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::EntityEvent* self = (Pixy::EntityEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOwner'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getOwner();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOwner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_new00
static int tolua_PixyInstance_Pixy_Entity_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::Entity* tolua_ret = (Pixy::Entity*)  Mtolua_new((Pixy::Entity)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Entity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_new00_local
static int tolua_PixyInstance_Pixy_Entity_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::Entity* tolua_ret = (Pixy::Entity*)  Mtolua_new((Pixy::Entity)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Entity");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_delete00
static int tolua_PixyInstance_Pixy_Entity_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setObjectId of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_setObjectId00
static int tolua_PixyInstance_Pixy_Entity_setObjectId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
  const int inObjectId = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setObjectId'", NULL);
#endif
  {
   self->setObjectId(inObjectId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setObjectId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setName of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_setName00
static int tolua_PixyInstance_Pixy_Entity_setName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
  const std::string inName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setName'", NULL);
#endif
  {
   self->setName(inName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRace of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_setRace00
static int tolua_PixyInstance_Pixy_Entity_setRace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
  const Pixy::RACE inRace = ((const Pixy::RACE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRace'", NULL);
#endif
  {
   self->setRace(inRace);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRace'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHP of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_setHP00
static int tolua_PixyInstance_Pixy_Entity_setHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
  const int inHealth = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHP'", NULL);
#endif
  {
   self->setHP(inHealth);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRank of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_setRank00
static int tolua_PixyInstance_Pixy_Entity_setRank00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
  const Pixy::RANK inRank = ((const Pixy::RANK) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRank'", NULL);
#endif
  {
   self->setRank(inRank);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRank'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOwner of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_setOwner00
static int tolua_PixyInstance_Pixy_Entity_setOwner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
  const std::string inOwner = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOwner'", NULL);
#endif
  {
   self->setOwner(inOwner);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOwner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIsDead of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_setIsDead00
static int tolua_PixyInstance_Pixy_Entity_setIsDead00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
  const bool inIsDead = ((const bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIsDead'", NULL);
#endif
  {
   self->setIsDead(inIsDead);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIsDead'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getObjectId of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_getObjectId00
static int tolua_PixyInstance_Pixy_Entity_getObjectId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Entity* self = (const Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getObjectId'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getObjectId();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getObjectId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getName of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_getName00
static int tolua_PixyInstance_Pixy_Entity_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Entity* self = (const Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRace of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_getRace00
static int tolua_PixyInstance_Pixy_Entity_getRace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Entity* self = (const Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRace'", NULL);
#endif
  {
   Pixy::RACE tolua_ret = (Pixy::RACE)  self->getRace();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRace'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHP of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_getHP00
static int tolua_PixyInstance_Pixy_Entity_getHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Entity* self = (const Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHP'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getHP();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRank of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_getRank00
static int tolua_PixyInstance_Pixy_Entity_getRank00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Entity* self = (const Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRank'", NULL);
#endif
  {
   Pixy::RANK tolua_ret = (Pixy::RANK)  self->getRank();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRank'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOwner of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_getOwner00
static int tolua_PixyInstance_Pixy_Entity_getOwner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Entity* self = (const Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOwner'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getOwner();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOwner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDamage of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_getDamage00
static int tolua_PixyInstance_Pixy_Entity_getDamage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Entity* self = (const Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDamage'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getDamage();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDamage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDamage of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_setDamage00
static int tolua_PixyInstance_Pixy_Entity_setDamage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
  const int inDamage = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDamage'", NULL);
#endif
  {
   self->setDamage(inDamage);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDamage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isDead of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_isDead00
static int tolua_PixyInstance_Pixy_Entity_isDead00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Entity* self = (const Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDead'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isDead();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDead'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: printInfo of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_printInfo00
static int tolua_PixyInstance_Pixy_Entity_printInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'printInfo'", NULL);
#endif
  {
   self->printInfo();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'printInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: die of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_die00
static int tolua_PixyInstance_Pixy_Entity_die00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'die'", NULL);
#endif
  {
   self->die();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'die'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isValid of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_isValid00
static int tolua_PixyInstance_Pixy_Entity_isValid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isValid'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isValid();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isValid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMesh of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_setMesh00
static int tolua_PixyInstance_Pixy_Entity_setMesh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
  std::string inMesh = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMesh'", NULL);
#endif
  {
   self->setMesh(inMesh);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMesh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMesh of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_getMesh00
static int tolua_PixyInstance_Pixy_Entity_getMesh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMesh'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getMesh();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMesh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaterial of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_setMaterial00
static int tolua_PixyInstance_Pixy_Entity_setMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
  std::string inMaterial = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaterial'", NULL);
#endif
  {
   self->setMaterial(inMaterial);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaterial of class  Pixy::Entity */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Entity_getMaterial00
static int tolua_PixyInstance_Pixy_Entity_getMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* self = (Pixy::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaterial'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getMaterial();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_new00
static int tolua_PixyInstance_Pixy_Spell_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::Spell* tolua_ret = (Pixy::Spell*)  Mtolua_new((Pixy::Spell)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Spell");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_new00_local
static int tolua_PixyInstance_Pixy_Spell_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::Spell* tolua_ret = (Pixy::Spell*)  Mtolua_new((Pixy::Spell)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Spell");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_delete00
static int tolua_PixyInstance_Pixy_Spell_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setId of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_setId00
static int tolua_PixyInstance_Pixy_Spell_setId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
  int inId = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setId'", NULL);
#endif
  {
   self->setId(inId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setName of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_setName00
static int tolua_PixyInstance_Pixy_Spell_setName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
  string inName = ((string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setName'", NULL);
#endif
  {
   self->setName(inName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRace of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_setRace00
static int tolua_PixyInstance_Pixy_Spell_setRace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
  Pixy::RACE inFaction = ((Pixy::RACE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRace'", NULL);
#endif
  {
   self->setRace(inFaction);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRace'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCost of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_setCost00
static int tolua_PixyInstance_Pixy_Spell_setCost00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
  int inCost = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCost'", NULL);
#endif
  {
   self->setCost(inCost);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCost'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlignment of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_setAlignment00
static int tolua_PixyInstance_Pixy_Spell_setAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
  Pixy::SPELL_ALIGNMENT inAlignment = ((Pixy::SPELL_ALIGNMENT) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlignment'", NULL);
#endif
  {
   self->setAlignment(inAlignment);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAspect of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_setAspect00
static int tolua_PixyInstance_Pixy_Spell_setAspect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
  Pixy::SPELL_ASPECT inAspect = ((Pixy::SPELL_ASPECT) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAspect'", NULL);
#endif
  {
   self->setAspect(inAspect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAspect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPhase of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_setPhase00
static int tolua_PixyInstance_Pixy_Spell_setPhase00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
  Pixy::SPELL_PHASE inPhase = ((Pixy::SPELL_PHASE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPhase'", NULL);
#endif
  {
   self->setPhase(inPhase);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPhase'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRequiresTarget of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_setRequiresTarget00
static int tolua_PixyInstance_Pixy_Spell_setRequiresTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
  bool inValue = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRequiresTarget'", NULL);
#endif
  {
   self->setRequiresTarget(inValue);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRequiresTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDispellable of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_setDispellable00
static int tolua_PixyInstance_Pixy_Spell_setDispellable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
  bool inCBD = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDispellable'", NULL);
#endif
  {
   self->setDispellable(inCBD);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDispellable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setImageSet of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_setImageSet00
static int tolua_PixyInstance_Pixy_Spell_setImageSet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
  string inName = ((string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setImageSet'", NULL);
#endif
  {
   self->setImageSet(inName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setImageSet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setImageName of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_setImageName00
static int tolua_PixyInstance_Pixy_Spell_setImageName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
  string inName = ((string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setImageName'", NULL);
#endif
  {
   self->setImageName(inName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setImageName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTooltip of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_setTooltip00
static int tolua_PixyInstance_Pixy_Spell_setTooltip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
  string inTooltip = ((string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTooltip'", NULL);
#endif
  {
   self->setTooltip(inTooltip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTooltip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setButton of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_setButton00
static int tolua_PixyInstance_Pixy_Spell_setButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CEGUI::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
  CEGUI::Window* inButton = ((CEGUI::Window*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setButton'", NULL);
#endif
  {
   self->setButton(inButton);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getId of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_getId00
static int tolua_PixyInstance_Pixy_Spell_getId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getId'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getId();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getName of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_getName00
static int tolua_PixyInstance_Pixy_Spell_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'", NULL);
#endif
  {
   string tolua_ret = (string)  self->getName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRace of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_getRace00
static int tolua_PixyInstance_Pixy_Spell_getRace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRace'", NULL);
#endif
  {
   Pixy::RACE tolua_ret = (Pixy::RACE)  self->getRace();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRace'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCost of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_getCost00
static int tolua_PixyInstance_Pixy_Spell_getCost00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCost'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getCost();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCost'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAlignment of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_getAlignment00
static int tolua_PixyInstance_Pixy_Spell_getAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAlignment'", NULL);
#endif
  {
   Pixy::SPELL_ALIGNMENT tolua_ret = (Pixy::SPELL_ALIGNMENT)  self->getAlignment();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAspect of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_getAspect00
static int tolua_PixyInstance_Pixy_Spell_getAspect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAspect'", NULL);
#endif
  {
   Pixy::SPELL_ASPECT tolua_ret = (Pixy::SPELL_ASPECT)  self->getAspect();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAspect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPhase of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_getPhase00
static int tolua_PixyInstance_Pixy_Spell_getPhase00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPhase'", NULL);
#endif
  {
   Pixy::SPELL_PHASE tolua_ret = (Pixy::SPELL_PHASE)  self->getPhase();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPhase'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dispellable of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_dispellable00
static int tolua_PixyInstance_Pixy_Spell_dispellable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dispellable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->dispellable();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dispellable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: requiresTarget of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_requiresTarget00
static int tolua_PixyInstance_Pixy_Spell_requiresTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'requiresTarget'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->requiresTarget();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'requiresTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getImageSet of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_getImageSet00
static int tolua_PixyInstance_Pixy_Spell_getImageSet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getImageSet'", NULL);
#endif
  {
   string tolua_ret = (string)  self->getImageSet();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getImageSet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getImageName of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_getImageName00
static int tolua_PixyInstance_Pixy_Spell_getImageName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getImageName'", NULL);
#endif
  {
   string tolua_ret = (string)  self->getImageName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getImageName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getButton of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_getButton00
static int tolua_PixyInstance_Pixy_Spell_getButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getButton'", NULL);
#endif
  {
   CEGUI::Window* tolua_ret = (CEGUI::Window*)  self->getButton();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CEGUI::Window");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTooltip of class  Pixy::Spell */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Spell_getTooltip00
static int tolua_PixyInstance_Pixy_Spell_getTooltip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Spell* self = (Pixy::Spell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTooltip'", NULL);
#endif
  {
   string tolua_ret = (string)  self->getTooltip();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTooltip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: generate of class  Pixy::Deck */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Deck_generate00
static int tolua_PixyInstance_Pixy_Deck_generate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Deck",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Deck* self = (Pixy::Deck*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'generate'", NULL);
#endif
  {
   self->generate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'generate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: drawSpell of class  Pixy::Deck */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Deck_drawSpell00
static int tolua_PixyInstance_Pixy_Deck_drawSpell00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Deck",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Deck* self = (Pixy::Deck*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'drawSpell'", NULL);
#endif
  {
   Pixy::Spell* tolua_ret = (Pixy::Spell*)  self->drawSpell();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Spell");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'drawSpell'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSpell of class  Pixy::Deck */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Deck_getSpell00
static int tolua_PixyInstance_Pixy_Deck_getSpell00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Deck",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Deck* self = (Pixy::Deck*)  tolua_tousertype(tolua_S,1,0);
  std::string inName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpell'", NULL);
#endif
  {
   Pixy::Spell* tolua_ret = (Pixy::Spell*)  self->getSpell(inName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Spell");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSpell'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Pixy::Unit */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Unit_new00
static int tolua_PixyInstance_Pixy_Unit_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Unit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::Unit* tolua_ret = (Pixy::Unit*)  Mtolua_new((Pixy::Unit)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Unit");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Pixy::Unit */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Unit_new00_local
static int tolua_PixyInstance_Pixy_Unit_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Unit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::Unit* tolua_ret = (Pixy::Unit*)  Mtolua_new((Pixy::Unit)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Unit");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Pixy::Unit */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Unit_delete00
static int tolua_PixyInstance_Pixy_Unit_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Unit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Unit* self = (Pixy::Unit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingletonPtr of class  Pixy::UnitFactory */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_UnitFactory_getSingletonPtr00
static int tolua_PixyInstance_Pixy_UnitFactory_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::UnitFactory",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::UnitFactory* tolua_ret = (Pixy::UnitFactory*)  Pixy::UnitFactory::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::UnitFactory");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingletonPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createEntity of class  Pixy::UnitFactory */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_UnitFactory_createEntity00
static int tolua_PixyInstance_Pixy_UnitFactory_createEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::UnitFactory",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::UnitFactory* self = (Pixy::UnitFactory*)  tolua_tousertype(tolua_S,1,0);
  const int inObjectId = ((const int)  tolua_tonumber(tolua_S,2,0));
  const std::string inName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string inOwner = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const Pixy::RACE inRace = ((const Pixy::RACE) (int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createEntity'", NULL);
#endif
  {
   Pixy::Unit* tolua_ret = (Pixy::Unit*)  self->createEntity(inObjectId,inName,inOwner,inRace);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Unit");
   tolua_pushcppstring(tolua_S,(const char*)inName);
   tolua_pushcppstring(tolua_S,(const char*)inOwner);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createEntity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyEntity of class  Pixy::UnitFactory */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_UnitFactory_destroyEntity00
static int tolua_PixyInstance_Pixy_UnitFactory_destroyEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::UnitFactory",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::UnitFactory* self = (Pixy::UnitFactory*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Entity* inEntity = ((Pixy::Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyEntity'", NULL);
#endif
  {
   self->destroyEntity(inEntity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyEntity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_new00
static int tolua_PixyInstance_Pixy_Puppet_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::Puppet* tolua_ret = (Pixy::Puppet*)  Mtolua_new((Pixy::Puppet)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Puppet");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_new00_local
static int tolua_PixyInstance_Pixy_Puppet_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::Puppet* tolua_ret = (Pixy::Puppet*)  Mtolua_new((Pixy::Puppet)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Puppet");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_delete00
static int tolua_PixyInstance_Pixy_Puppet_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setExperience of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_setExperience00
static int tolua_PixyInstance_Pixy_Puppet_setExperience00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
  int inExperience = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setExperience'", NULL);
#endif
  {
   self->setExperience(inExperience);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setExperience'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLevel of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_setLevel00
static int tolua_PixyInstance_Pixy_Puppet_setLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
  int inLevel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLevel'", NULL);
#endif
  {
   self->setLevel(inLevel);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAlignment of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_setAlignment00
static int tolua_PixyInstance_Pixy_Puppet_setAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
  Pixy::PUPPET_ALIGNMENT inAlignment = ((Pixy::PUPPET_ALIGNMENT) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlignment'", NULL);
#endif
  {
   self->setAlignment(inAlignment);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIntelligence of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_setIntelligence00
static int tolua_PixyInstance_Pixy_Puppet_setIntelligence00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
  int inInt = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIntelligence'", NULL);
#endif
  {
   self->setIntelligence(inInt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIntelligence'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVitality of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_setVitality00
static int tolua_PixyInstance_Pixy_Puppet_setVitality00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
  int inVt = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVitality'", NULL);
#endif
  {
   self->setVitality(inVt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVitality'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWP of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_setWP00
static int tolua_PixyInstance_Pixy_Puppet_setWP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
  int inWP = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWP'", NULL);
#endif
  {
   self->setWP(inWP);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getExperience of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_getExperience00
static int tolua_PixyInstance_Pixy_Puppet_getExperience00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Puppet* self = (const Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getExperience'", NULL);
#endif
  {
   long tolua_ret = (long)  self->getExperience();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getExperience'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLevel of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_getLevel00
static int tolua_PixyInstance_Pixy_Puppet_getLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Puppet* self = (const Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLevel'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getLevel();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAlignment of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_getAlignment00
static int tolua_PixyInstance_Pixy_Puppet_getAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Puppet* self = (const Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAlignment'", NULL);
#endif
  {
   Pixy::PUPPET_ALIGNMENT tolua_ret = (Pixy::PUPPET_ALIGNMENT)  self->getAlignment();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIntelligence of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_getIntelligence00
static int tolua_PixyInstance_Pixy_Puppet_getIntelligence00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Puppet* self = (const Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIntelligence'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getIntelligence();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIntelligence'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVitality of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_getVitality00
static int tolua_PixyInstance_Pixy_Puppet_getVitality00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Puppet* self = (const Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVitality'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getVitality();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVitality'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWP of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_getWP00
static int tolua_PixyInstance_Pixy_Puppet_getWP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Puppet* self = (const Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWP'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getWP();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWins of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_getWins00
static int tolua_PixyInstance_Pixy_Puppet_getWins00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Puppet* self = (const Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWins'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getWins();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWins'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLosses of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_getLosses00
static int tolua_PixyInstance_Pixy_Puppet_getLosses00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Puppet* self = (const Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLosses'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getLosses();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLosses'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: printInfo of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_printInfo00
static int tolua_PixyInstance_Pixy_Puppet_printInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'printInfo'", NULL);
#endif
  {
   self->printInfo();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'printInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isValid of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_isValid00
static int tolua_PixyInstance_Pixy_Puppet_isValid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isValid'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isValid();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isValid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDeck of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_getDeck00
static int tolua_PixyInstance_Pixy_Puppet_getDeck00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDeck'", NULL);
#endif
  {
   Pixy::Deck* tolua_ret = (Pixy::Deck*)  self->getDeck();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Deck");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDeck'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHand of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_getHand00
static int tolua_PixyInstance_Pixy_Puppet_getHand00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHand'", NULL);
#endif
  {
    list<Pixy::Spell*>& tolua_ret = (  list<Pixy::Spell*>&)  self->getHand();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"list<Pixy::Spell*>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHand'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: nrSpellsInHand of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_nrSpellsInHand00
static int tolua_PixyInstance_Pixy_Puppet_nrSpellsInHand00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'nrSpellsInHand'", NULL);
#endif
  {
   int tolua_ret = (int)  self->nrSpellsInHand();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'nrSpellsInHand'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSpell of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_getSpell00
static int tolua_PixyInstance_Pixy_Puppet_getSpell00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
  const int inId = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpell'", NULL);
#endif
  {
   Pixy::Spell* tolua_ret = (Pixy::Spell*)  self->getSpell(inId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Spell");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSpell'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachSpell of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_attachSpell00
static int tolua_PixyInstance_Pixy_Puppet_attachSpell00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Spell* inSpell = ((Pixy::Spell*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachSpell'", NULL);
#endif
  {
   self->attachSpell(inSpell);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachSpell'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: detachSpell of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_detachSpell00
static int tolua_PixyInstance_Pixy_Puppet_detachSpell00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Spell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Spell* inSpell = ((Pixy::Spell*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detachSpell'", NULL);
#endif
  {
   self->detachSpell(inSpell);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'detachSpell'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachUnit of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_attachUnit00
static int tolua_PixyInstance_Pixy_Puppet_attachUnit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Unit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Unit* inUnit = ((Pixy::Unit*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachUnit'", NULL);
#endif
  {
   self->attachUnit(inUnit);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachUnit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: detachUnit of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_detachUnit00
static int tolua_PixyInstance_Pixy_Puppet_detachUnit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Unit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Unit* inUnit = ((Pixy::Unit*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detachUnit'", NULL);
#endif
  {
   self->detachUnit(inUnit);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'detachUnit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUnit of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_getUnit00
static int tolua_PixyInstance_Pixy_Puppet_getUnit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
  const int inId = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUnit'", NULL);
#endif
  {
   Pixy::Unit* tolua_ret = (Pixy::Unit*)  self->getUnit(inId);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Unit");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUnit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUnits of class  Pixy::Puppet */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Puppet_getUnits00
static int tolua_PixyInstance_Pixy_Puppet_getUnits00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Puppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Puppet* self = (Pixy::Puppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUnits'", NULL);
#endif
  {
    vector<Pixy::Unit*>& tolua_ret = (  vector<Pixy::Unit*>&)  self->getUnits();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"vector<Pixy::Unit*>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUnits'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingletonPtr of class  Pixy::PuppetFactory */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_PuppetFactory_getSingletonPtr00
static int tolua_PixyInstance_Pixy_PuppetFactory_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::PuppetFactory",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::PuppetFactory* tolua_ret = (Pixy::PuppetFactory*)  Pixy::PuppetFactory::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::PuppetFactory");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingletonPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createEntity of class  Pixy::PuppetFactory */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_PuppetFactory_createEntity00
static int tolua_PixyInstance_Pixy_PuppetFactory_createEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::PuppetFactory",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::PuppetFactory* self = (Pixy::PuppetFactory*)  tolua_tousertype(tolua_S,1,0);
  const int inObjectId = ((const int)  tolua_tonumber(tolua_S,2,0));
  const std::string inName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string inOwner = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const Pixy::RACE inRace = ((const Pixy::RACE) (int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createEntity'", NULL);
#endif
  {
   Pixy::Puppet* tolua_ret = (Pixy::Puppet*)  self->createEntity(inObjectId,inName,inOwner,inRace);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Puppet");
   tolua_pushcppstring(tolua_S,(const char*)inName);
   tolua_pushcppstring(tolua_S,(const char*)inOwner);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createEntity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyEntity of class  Pixy::PuppetFactory */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_PuppetFactory_destroyEntity00
static int tolua_PixyInstance_Pixy_PuppetFactory_destroyEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::PuppetFactory",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::PuppetFactory* self = (Pixy::PuppetFactory*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Entity* inEntity = ((Pixy::Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyEntity'", NULL);
#endif
  {
   self->destroyEntity(inEntity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyEntity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance::luaLog of class  Pixy::Instance */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Instance_Log00
static int tolua_PixyInstance_Pixy_Instance_Log00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Instance",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Instance* self = (Pixy::Instance*)  tolua_tousertype(tolua_S,1,0);
  std::string inMsg = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Instance::luaLog'", NULL);
#endif
  {
   self->Instance::luaLog(inMsg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Log'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getId of class  Pixy::Instance */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Instance_getId00
static int tolua_PixyInstance_Pixy_Instance_getId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Instance",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Instance* self = (Pixy::Instance*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getId'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getId();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPlayers of class  Pixy::Instance */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Instance_getPlayers00
static int tolua_PixyInstance_Pixy_Instance_getPlayers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Instance",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Instance* self = (Pixy::Instance*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPlayers'", NULL);
#endif
  {
    list<Pixy::Player*>& tolua_ret = (  list<Pixy::Player*>&)  self->getPlayers();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"list<Pixy::Player*>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPlayers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: broadcast of class  Pixy::Instance */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Instance_broadcast00
static int tolua_PixyInstance_Pixy_Instance_broadcast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Instance",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Event",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Instance* self = (Pixy::Instance*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Event* inEvt = ((Pixy::Event*)  tolua_tousertype(tolua_S,2,0));
  bool fForceResp = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'broadcast'", NULL);
#endif
  {
   self->broadcast(inEvt,fForceResp);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'broadcast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: generateUID of class  Pixy::Instance */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Instance_generateUID00
static int tolua_PixyInstance_Pixy_Instance_generateUID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Instance",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Instance* self = (Pixy::Instance*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'generateUID'", NULL);
#endif
  {
   const int tolua_ret = (const int)  self->generateUID();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'generateUID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSender of class  Pixy::Instance */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Instance_getSender00
static int tolua_PixyInstance_Pixy_Instance_getSender00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Instance",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Instance* self = (Pixy::Instance*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Event* inEvt = ((Pixy::Event*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSender'", NULL);
#endif
  {
   Pixy::Puppet* tolua_ret = (Pixy::Puppet*)  self->getSender(inEvt);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Puppet");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSender'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rejectRequest of class  Pixy::Instance */
#ifndef TOLUA_DISABLE_tolua_PixyInstance_Pixy_Instance_rejectRequest00
static int tolua_PixyInstance_Pixy_Instance_rejectRequest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Instance",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Instance* self = (Pixy::Instance*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Event* inEvt = ((Pixy::Event*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rejectRequest'", NULL);
#endif
  {
   self->rejectRequest(inEvt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rejectRequest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_PixyInstance_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"Pixy",0);
  tolua_beginmodule(tolua_S,"Pixy");
   tolua_cclass(tolua_S,"EventManager","Pixy::EventManager","",NULL);
   tolua_beginmodule(tolua_S,"EventManager");
    tolua_function(tolua_S,"getSingletonPtr",tolua_PixyInstance_Pixy_EventManager_getSingletonPtr00);
    tolua_function(tolua_S,"createEvt",tolua_PixyInstance_Pixy_EventManager_createEvt00);
    tolua_function(tolua_S,"createEntityEvt",tolua_PixyInstance_Pixy_EventManager_createEntityEvt00);
    tolua_function(tolua_S,"hook",tolua_PixyInstance_Pixy_EventManager_hook00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"EventListener","Pixy::EventListener","",tolua_collect_Pixy__EventListener);
   #else
   tolua_cclass(tolua_S,"EventListener","Pixy::EventListener","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"EventListener");
    tolua_function(tolua_S,"new",tolua_PixyInstance_Pixy_EventListener_new00);
    tolua_function(tolua_S,"new_local",tolua_PixyInstance_Pixy_EventListener_new00_local);
    tolua_function(tolua_S,".call",tolua_PixyInstance_Pixy_EventListener_new00_local);
    tolua_function(tolua_S,"delete",tolua_PixyInstance_Pixy_EventListener_delete00);
    tolua_function(tolua_S,"enqueue",tolua_PixyInstance_Pixy_EventListener_enqueue00);
   tolua_endmodule(tolua_S);
   tolua_constant(tolua_S,"ID_EVENT",Pixy::ID_EVENT);
   tolua_constant(tolua_S,"ID_ENTITY_EVENT",Pixy::ID_ENTITY_EVENT);
   tolua_constant(tolua_S,"EVT_REQ",Pixy::EVT_REQ);
   tolua_constant(tolua_S,"EVT_RESP",Pixy::EVT_RESP);
   tolua_constant(tolua_S,"EVT_OK",Pixy::EVT_OK);
   tolua_constant(tolua_S,"EVT_ERROR",Pixy::EVT_ERROR);
   tolua_constant(tolua_S,"EVT_INVALID_REQ",Pixy::EVT_INVALID_REQ);
   tolua_cclass(tolua_S,"Event","Pixy::Event","",NULL);
   tolua_beginmodule(tolua_S,"Event");
    tolua_function(tolua_S,"setCategory",tolua_PixyInstance_Pixy_Event_setCategory00);
    tolua_function(tolua_S,"getCategory",tolua_PixyInstance_Pixy_Event_getCategory00);
    tolua_function(tolua_S,"setName",tolua_PixyInstance_Pixy_Event_setName00);
    tolua_function(tolua_S,"getName",tolua_PixyInstance_Pixy_Event_getName00);
    tolua_function(tolua_S,"setType",tolua_PixyInstance_Pixy_Event_setType00);
    tolua_function(tolua_S,"getType",tolua_PixyInstance_Pixy_Event_getType00);
    tolua_function(tolua_S,"setFeedback",tolua_PixyInstance_Pixy_Event_setFeedback00);
    tolua_function(tolua_S,"getFeedback",tolua_PixyInstance_Pixy_Event_getFeedback00);
    tolua_function(tolua_S,"setProperty",tolua_PixyInstance_Pixy_Event_setProperty00);
    tolua_function(tolua_S,"getProperty",tolua_PixyInstance_Pixy_Event_getProperty00);
    tolua_function(tolua_S,"propertyExists",tolua_PixyInstance_Pixy_Event_propertyExists00);
    tolua_function(tolua_S,"dump",tolua_PixyInstance_Pixy_Event_dump00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"EntityEvent","Pixy::EntityEvent","Pixy::Event",NULL);
   tolua_beginmodule(tolua_S,"EntityEvent");
    tolua_function(tolua_S,"setObjectId",tolua_PixyInstance_Pixy_EntityEvent_setObjectId00);
    tolua_function(tolua_S,"getObjectId",tolua_PixyInstance_Pixy_EntityEvent_getObjectId00);
    tolua_function(tolua_S,"setOwner",tolua_PixyInstance_Pixy_EntityEvent_setOwner00);
    tolua_function(tolua_S,"getOwner",tolua_PixyInstance_Pixy_EntityEvent_getOwner00);
   tolua_endmodule(tolua_S);
   tolua_constant(tolua_S,"EARTH",Pixy::EARTH);
   tolua_constant(tolua_S,"AIR",Pixy::AIR);
   tolua_constant(tolua_S,"WATER",Pixy::WATER);
   tolua_constant(tolua_S,"FIRE",Pixy::FIRE);
   tolua_constant(tolua_S,"INVALID_RANK",Pixy::INVALID_RANK);
   tolua_constant(tolua_S,"UNIT_T1",Pixy::UNIT_T1);
   tolua_constant(tolua_S,"UNIT_T2",Pixy::UNIT_T2);
   tolua_constant(tolua_S,"UNIT_T3",Pixy::UNIT_T3);
   tolua_constant(tolua_S,"UNIT_T4",Pixy::UNIT_T4);
   tolua_constant(tolua_S,"UNIT_T5",Pixy::UNIT_T5);
   tolua_constant(tolua_S,"PUPPET",Pixy::PUPPET);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Entity","Pixy::Entity","",tolua_collect_Pixy__Entity);
   #else
   tolua_cclass(tolua_S,"Entity","Pixy::Entity","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Entity");
    tolua_function(tolua_S,"new",tolua_PixyInstance_Pixy_Entity_new00);
    tolua_function(tolua_S,"new_local",tolua_PixyInstance_Pixy_Entity_new00_local);
    tolua_function(tolua_S,".call",tolua_PixyInstance_Pixy_Entity_new00_local);
    tolua_function(tolua_S,"delete",tolua_PixyInstance_Pixy_Entity_delete00);
    tolua_function(tolua_S,"setObjectId",tolua_PixyInstance_Pixy_Entity_setObjectId00);
    tolua_function(tolua_S,"setName",tolua_PixyInstance_Pixy_Entity_setName00);
    tolua_function(tolua_S,"setRace",tolua_PixyInstance_Pixy_Entity_setRace00);
    tolua_function(tolua_S,"setHP",tolua_PixyInstance_Pixy_Entity_setHP00);
    tolua_function(tolua_S,"setRank",tolua_PixyInstance_Pixy_Entity_setRank00);
    tolua_function(tolua_S,"setOwner",tolua_PixyInstance_Pixy_Entity_setOwner00);
    tolua_function(tolua_S,"setIsDead",tolua_PixyInstance_Pixy_Entity_setIsDead00);
    tolua_function(tolua_S,"getObjectId",tolua_PixyInstance_Pixy_Entity_getObjectId00);
    tolua_function(tolua_S,"getName",tolua_PixyInstance_Pixy_Entity_getName00);
    tolua_function(tolua_S,"getRace",tolua_PixyInstance_Pixy_Entity_getRace00);
    tolua_function(tolua_S,"getHP",tolua_PixyInstance_Pixy_Entity_getHP00);
    tolua_function(tolua_S,"getRank",tolua_PixyInstance_Pixy_Entity_getRank00);
    tolua_function(tolua_S,"getOwner",tolua_PixyInstance_Pixy_Entity_getOwner00);
    tolua_function(tolua_S,"getDamage",tolua_PixyInstance_Pixy_Entity_getDamage00);
    tolua_function(tolua_S,"setDamage",tolua_PixyInstance_Pixy_Entity_setDamage00);
    tolua_function(tolua_S,"isDead",tolua_PixyInstance_Pixy_Entity_isDead00);
    tolua_function(tolua_S,"printInfo",tolua_PixyInstance_Pixy_Entity_printInfo00);
    tolua_function(tolua_S,"die",tolua_PixyInstance_Pixy_Entity_die00);
    tolua_function(tolua_S,"isValid",tolua_PixyInstance_Pixy_Entity_isValid00);
    tolua_function(tolua_S,"setMesh",tolua_PixyInstance_Pixy_Entity_setMesh00);
    tolua_function(tolua_S,"getMesh",tolua_PixyInstance_Pixy_Entity_getMesh00);
    tolua_function(tolua_S,"setMaterial",tolua_PixyInstance_Pixy_Entity_setMaterial00);
    tolua_function(tolua_S,"getMaterial",tolua_PixyInstance_Pixy_Entity_getMaterial00);
   tolua_endmodule(tolua_S);
   tolua_constant(tolua_S,"S_LAWFUL",Pixy::S_LAWFUL);
   tolua_constant(tolua_S,"S_NEUTRAL",Pixy::S_NEUTRAL);
   tolua_constant(tolua_S,"S_CHAOTIC",Pixy::S_CHAOTIC);
   tolua_constant(tolua_S,"MIND",Pixy::MIND);
   tolua_constant(tolua_S,"MATTER",Pixy::MATTER);
   tolua_constant(tolua_S,"CASTING",Pixy::CASTING);
   tolua_constant(tolua_S,"BLOCKING",Pixy::BLOCKING);
   tolua_constant(tolua_S,"ALL",Pixy::ALL);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Spell","Pixy::Spell","",tolua_collect_Pixy__Spell);
   #else
   tolua_cclass(tolua_S,"Spell","Pixy::Spell","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Spell");
    tolua_function(tolua_S,"new",tolua_PixyInstance_Pixy_Spell_new00);
    tolua_function(tolua_S,"new_local",tolua_PixyInstance_Pixy_Spell_new00_local);
    tolua_function(tolua_S,".call",tolua_PixyInstance_Pixy_Spell_new00_local);
    tolua_function(tolua_S,"delete",tolua_PixyInstance_Pixy_Spell_delete00);
    tolua_function(tolua_S,"setId",tolua_PixyInstance_Pixy_Spell_setId00);
    tolua_function(tolua_S,"setName",tolua_PixyInstance_Pixy_Spell_setName00);
    tolua_function(tolua_S,"setRace",tolua_PixyInstance_Pixy_Spell_setRace00);
    tolua_function(tolua_S,"setCost",tolua_PixyInstance_Pixy_Spell_setCost00);
    tolua_function(tolua_S,"setAlignment",tolua_PixyInstance_Pixy_Spell_setAlignment00);
    tolua_function(tolua_S,"setAspect",tolua_PixyInstance_Pixy_Spell_setAspect00);
    tolua_function(tolua_S,"setPhase",tolua_PixyInstance_Pixy_Spell_setPhase00);
    tolua_function(tolua_S,"setRequiresTarget",tolua_PixyInstance_Pixy_Spell_setRequiresTarget00);
    tolua_function(tolua_S,"setDispellable",tolua_PixyInstance_Pixy_Spell_setDispellable00);
    tolua_function(tolua_S,"setImageSet",tolua_PixyInstance_Pixy_Spell_setImageSet00);
    tolua_function(tolua_S,"setImageName",tolua_PixyInstance_Pixy_Spell_setImageName00);
    tolua_function(tolua_S,"setTooltip",tolua_PixyInstance_Pixy_Spell_setTooltip00);
    tolua_function(tolua_S,"setButton",tolua_PixyInstance_Pixy_Spell_setButton00);
    tolua_function(tolua_S,"getId",tolua_PixyInstance_Pixy_Spell_getId00);
    tolua_function(tolua_S,"getName",tolua_PixyInstance_Pixy_Spell_getName00);
    tolua_function(tolua_S,"getRace",tolua_PixyInstance_Pixy_Spell_getRace00);
    tolua_function(tolua_S,"getCost",tolua_PixyInstance_Pixy_Spell_getCost00);
    tolua_function(tolua_S,"getAlignment",tolua_PixyInstance_Pixy_Spell_getAlignment00);
    tolua_function(tolua_S,"getAspect",tolua_PixyInstance_Pixy_Spell_getAspect00);
    tolua_function(tolua_S,"getPhase",tolua_PixyInstance_Pixy_Spell_getPhase00);
    tolua_function(tolua_S,"dispellable",tolua_PixyInstance_Pixy_Spell_dispellable00);
    tolua_function(tolua_S,"requiresTarget",tolua_PixyInstance_Pixy_Spell_requiresTarget00);
    tolua_function(tolua_S,"getImageSet",tolua_PixyInstance_Pixy_Spell_getImageSet00);
    tolua_function(tolua_S,"getImageName",tolua_PixyInstance_Pixy_Spell_getImageName00);
    tolua_function(tolua_S,"getButton",tolua_PixyInstance_Pixy_Spell_getButton00);
    tolua_function(tolua_S,"getTooltip",tolua_PixyInstance_Pixy_Spell_getTooltip00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Deck","Pixy::Deck","",NULL);
   tolua_beginmodule(tolua_S,"Deck");
    tolua_function(tolua_S,"generate",tolua_PixyInstance_Pixy_Deck_generate00);
    tolua_function(tolua_S,"drawSpell",tolua_PixyInstance_Pixy_Deck_drawSpell00);
    tolua_function(tolua_S,"getSpell",tolua_PixyInstance_Pixy_Deck_getSpell00);
   tolua_endmodule(tolua_S);
   tolua_constant(tolua_S,"POS_PASSIVE",Pixy::POS_PASSIVE);
   tolua_constant(tolua_S,"POS_CHARGING",Pixy::POS_CHARGING);
   tolua_constant(tolua_S,"POS_DEFENCE",Pixy::POS_DEFENCE);
   tolua_constant(tolua_S,"POS_OFFENCE",Pixy::POS_OFFENCE);
   tolua_constant(tolua_S,"POS_ATTACK",Pixy::POS_ATTACK);
   tolua_constant(tolua_S,"UNIT_PASSIVE",Pixy::UNIT_PASSIVE);
   tolua_constant(tolua_S,"UNIT_CHARGING",Pixy::UNIT_CHARGING);
   tolua_constant(tolua_S,"UNIT_ATTACKING",Pixy::UNIT_ATTACKING);
   tolua_constant(tolua_S,"UNIT_BLOCKING",Pixy::UNIT_BLOCKING);
   tolua_constant(tolua_S,"UNIT_RESTING",Pixy::UNIT_RESTING);
   tolua_constant(tolua_S,"INVALID_RANK",Pixy::INVALID_RANK);
   tolua_constant(tolua_S,"UNIT_T1",Pixy::UNIT_T1);
   tolua_constant(tolua_S,"UNIT_T2",Pixy::UNIT_T2);
   tolua_constant(tolua_S,"UNIT_T3",Pixy::UNIT_T3);
   tolua_constant(tolua_S,"UNIT_T4",Pixy::UNIT_T4);
   tolua_constant(tolua_S,"UNIT_T5",Pixy::UNIT_T5);
   tolua_constant(tolua_S,"PUPPET",Pixy::PUPPET);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Unit","Pixy::Unit","Pixy::Entity",tolua_collect_Pixy__Unit);
   #else
   tolua_cclass(tolua_S,"Unit","Pixy::Unit","Pixy::Entity",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Unit");
    tolua_function(tolua_S,"new",tolua_PixyInstance_Pixy_Unit_new00);
    tolua_function(tolua_S,"new_local",tolua_PixyInstance_Pixy_Unit_new00_local);
    tolua_function(tolua_S,".call",tolua_PixyInstance_Pixy_Unit_new00_local);
    tolua_function(tolua_S,"delete",tolua_PixyInstance_Pixy_Unit_delete00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"UnitFactory","Pixy::UnitFactory","EntityFactory",NULL);
   tolua_beginmodule(tolua_S,"UnitFactory");
    tolua_function(tolua_S,"getSingletonPtr",tolua_PixyInstance_Pixy_UnitFactory_getSingletonPtr00);
    tolua_function(tolua_S,"createEntity",tolua_PixyInstance_Pixy_UnitFactory_createEntity00);
    tolua_function(tolua_S,"destroyEntity",tolua_PixyInstance_Pixy_UnitFactory_destroyEntity00);
   tolua_endmodule(tolua_S);
   tolua_constant(tolua_S,"H_GOOD",Pixy::H_GOOD);
   tolua_constant(tolua_S,"H_NEUTRAL",Pixy::H_NEUTRAL);
   tolua_constant(tolua_S,"H_EVIL",Pixy::H_EVIL);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Puppet","Pixy::Puppet","Pixy::Entity",tolua_collect_Pixy__Puppet);
   #else
   tolua_cclass(tolua_S,"Puppet","Pixy::Puppet","Pixy::Entity",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Puppet");
    tolua_function(tolua_S,"new",tolua_PixyInstance_Pixy_Puppet_new00);
    tolua_function(tolua_S,"new_local",tolua_PixyInstance_Pixy_Puppet_new00_local);
    tolua_function(tolua_S,".call",tolua_PixyInstance_Pixy_Puppet_new00_local);
    tolua_function(tolua_S,"delete",tolua_PixyInstance_Pixy_Puppet_delete00);
    tolua_function(tolua_S,"setExperience",tolua_PixyInstance_Pixy_Puppet_setExperience00);
    tolua_function(tolua_S,"setLevel",tolua_PixyInstance_Pixy_Puppet_setLevel00);
    tolua_function(tolua_S,"setAlignment",tolua_PixyInstance_Pixy_Puppet_setAlignment00);
    tolua_function(tolua_S,"setIntelligence",tolua_PixyInstance_Pixy_Puppet_setIntelligence00);
    tolua_function(tolua_S,"setVitality",tolua_PixyInstance_Pixy_Puppet_setVitality00);
    tolua_function(tolua_S,"setWP",tolua_PixyInstance_Pixy_Puppet_setWP00);
    tolua_function(tolua_S,"getExperience",tolua_PixyInstance_Pixy_Puppet_getExperience00);
    tolua_function(tolua_S,"getLevel",tolua_PixyInstance_Pixy_Puppet_getLevel00);
    tolua_function(tolua_S,"getAlignment",tolua_PixyInstance_Pixy_Puppet_getAlignment00);
    tolua_function(tolua_S,"getIntelligence",tolua_PixyInstance_Pixy_Puppet_getIntelligence00);
    tolua_function(tolua_S,"getVitality",tolua_PixyInstance_Pixy_Puppet_getVitality00);
    tolua_function(tolua_S,"getWP",tolua_PixyInstance_Pixy_Puppet_getWP00);
    tolua_function(tolua_S,"getWins",tolua_PixyInstance_Pixy_Puppet_getWins00);
    tolua_function(tolua_S,"getLosses",tolua_PixyInstance_Pixy_Puppet_getLosses00);
    tolua_function(tolua_S,"printInfo",tolua_PixyInstance_Pixy_Puppet_printInfo00);
    tolua_function(tolua_S,"isValid",tolua_PixyInstance_Pixy_Puppet_isValid00);
    tolua_function(tolua_S,"getDeck",tolua_PixyInstance_Pixy_Puppet_getDeck00);
    tolua_function(tolua_S,"getHand",tolua_PixyInstance_Pixy_Puppet_getHand00);
    tolua_function(tolua_S,"nrSpellsInHand",tolua_PixyInstance_Pixy_Puppet_nrSpellsInHand00);
    tolua_function(tolua_S,"getSpell",tolua_PixyInstance_Pixy_Puppet_getSpell00);
    tolua_function(tolua_S,"attachSpell",tolua_PixyInstance_Pixy_Puppet_attachSpell00);
    tolua_function(tolua_S,"detachSpell",tolua_PixyInstance_Pixy_Puppet_detachSpell00);
    tolua_function(tolua_S,"attachUnit",tolua_PixyInstance_Pixy_Puppet_attachUnit00);
    tolua_function(tolua_S,"detachUnit",tolua_PixyInstance_Pixy_Puppet_detachUnit00);
    tolua_function(tolua_S,"getUnit",tolua_PixyInstance_Pixy_Puppet_getUnit00);
    tolua_function(tolua_S,"getUnits",tolua_PixyInstance_Pixy_Puppet_getUnits00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"PuppetFactory","Pixy::PuppetFactory","EntityFactory",NULL);
   tolua_beginmodule(tolua_S,"PuppetFactory");
    tolua_function(tolua_S,"getSingletonPtr",tolua_PixyInstance_Pixy_PuppetFactory_getSingletonPtr00);
    tolua_function(tolua_S,"createEntity",tolua_PixyInstance_Pixy_PuppetFactory_createEntity00);
    tolua_function(tolua_S,"destroyEntity",tolua_PixyInstance_Pixy_PuppetFactory_destroyEntity00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Player","Pixy::Player","",NULL);
   tolua_beginmodule(tolua_S,"Player");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Instance","Pixy::Instance","Pixy::EventListener",NULL);
   tolua_beginmodule(tolua_S,"Instance");
    tolua_function(tolua_S,"Log",tolua_PixyInstance_Pixy_Instance_Log00);
    tolua_function(tolua_S,"getId",tolua_PixyInstance_Pixy_Instance_getId00);
    tolua_function(tolua_S,"getPlayers",tolua_PixyInstance_Pixy_Instance_getPlayers00);
    tolua_function(tolua_S,"broadcast",tolua_PixyInstance_Pixy_Instance_broadcast00);
    tolua_function(tolua_S,"generateUID",tolua_PixyInstance_Pixy_Instance_generateUID00);
    tolua_function(tolua_S,"getSender",tolua_PixyInstance_Pixy_Instance_getSender00);
    tolua_function(tolua_S,"rejectRequest",tolua_PixyInstance_Pixy_Instance_rejectRequest00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_PixyInstance (lua_State* tolua_S) {
 return tolua_PixyInstance_open(tolua_S);
};
#endif

