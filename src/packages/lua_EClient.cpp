/*
** Lua binding: EClient
** Generated automatically by tolua++-1.0.92 on Sat Jun 25 01:52:06 2011.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_EClient_open (lua_State* tolua_S);

#include "required.h"
#include "Pixy.h"
#include "Renderable.h"
#include "Renderable.h"
#include "CPuppet.h"
#include "CDeck.h"
#include "CSpell.h"
#include "CDeck.h"
#include "Renderable.h"
#include "CUnit.h"
#include "CDeck.h"
#include "GameManager.h"
#include "GameState.h"
#include "Intro.h"
#include "Combat.h"
#include "Engine.h"
#include "UIEngine.h"
#include "GfxEngine.h"
#include "ScriptEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Pixy__CPuppet (lua_State* tolua_S)
{
 Pixy::CPuppet* self = (Pixy::CPuppet*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__GfxEngine (lua_State* tolua_S)
{
 Pixy::GfxEngine* self = (Pixy::GfxEngine*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__Renderable (lua_State* tolua_S)
{
 Pixy::Renderable* self = (Pixy::Renderable*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__CSpell (lua_State* tolua_S)
{
 Pixy::CSpell* self = (Pixy::CSpell*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__UIEngine (lua_State* tolua_S)
{
 Pixy::UIEngine* self = (Pixy::UIEngine*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__CUnit (lua_State* tolua_S)
{
 Pixy::CUnit* self = (Pixy::CUnit*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Pixy::Spell");
 tolua_usertype(tolua_S,"Ogre::Viewport");
 tolua_usertype(tolua_S,"Ogre::SceneManager");
 tolua_usertype(tolua_S,"Ogre::Root");
 tolua_usertype(tolua_S,"Pixy::Deck");
 tolua_usertype(tolua_S,"Pixy::CUnit");
 tolua_usertype(tolua_S,"CEGUI::Window");
 tolua_usertype(tolua_S,"Pixy::CSpell");
 tolua_usertype(tolua_S,"Pixy::GfxEngine");
 tolua_usertype(tolua_S,"Ogre::SceneNode");
 tolua_usertype(tolua_S,"Pixy::CPuppet");
 tolua_usertype(tolua_S,"Pixy::EventListener");
 tolua_usertype(tolua_S,"Pixy::Engine");
 tolua_usertype(tolua_S,"Pixy::Renderable");
 tolua_usertype(tolua_S,"Pixy::UIEngine");
 tolua_usertype(tolua_S,"const");
 tolua_usertype(tolua_S,"Pixy::Puppet");
 tolua_usertype(tolua_S,"Pixy::Intro");
 tolua_usertype(tolua_S,"Pixy::CDeck");
 tolua_usertype(tolua_S,"Pixy::Entity");
 tolua_usertype(tolua_S,"Pixy::Combat");
 tolua_usertype(tolua_S,"Pixy::GameState");
 tolua_usertype(tolua_S,"Pixy::Unit");
 tolua_usertype(tolua_S,"Ogre::MovableObject");
 tolua_usertype(tolua_S,"Pixy::GameManager");
 tolua_usertype(tolua_S,"Ogre::Camera");
}

/* method: new of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_Renderable_new00
static int tolua_EClient_Pixy_Renderable_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* inOwner = ((Pixy::Entity*)  tolua_tousertype(tolua_S,2,0));
  {
   Pixy::Renderable* tolua_ret = (Pixy::Renderable*)  Mtolua_new((Pixy::Renderable)(inOwner));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Renderable");
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

/* method: new_local of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_Renderable_new00_local
static int tolua_EClient_Pixy_Renderable_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Entity* inOwner = ((Pixy::Entity*)  tolua_tousertype(tolua_S,2,0));
  {
   Pixy::Renderable* tolua_ret = (Pixy::Renderable*)  Mtolua_new((Pixy::Renderable)(inOwner));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Renderable");
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

/* method: delete of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_Renderable_delete00
static int tolua_EClient_Pixy_Renderable_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Renderable* self = (Pixy::Renderable*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getEntity of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_Renderable_getEntity00
static int tolua_EClient_Pixy_Renderable_getEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Renderable* self = (Pixy::Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEntity'", NULL);
#endif
  {
   Pixy::Entity* tolua_ret = (Pixy::Entity*)  self->getEntity();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Entity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEntity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachSceneNode of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_Renderable_attachSceneNode00
static int tolua_EClient_Pixy_Renderable_attachSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Renderable* self = (Pixy::Renderable*)  tolua_tousertype(tolua_S,1,0);
  Ogre::SceneNode* inNode = ((Ogre::SceneNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachSceneNode'", NULL);
#endif
  {
   self->attachSceneNode(inNode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSceneNode of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_Renderable_getSceneNode00
static int tolua_EClient_Pixy_Renderable_getSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Renderable* self = (Pixy::Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneNode'", NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->getSceneNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachSceneObject of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_Renderable_attachSceneObject00
static int tolua_EClient_Pixy_Renderable_attachSceneObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Renderable* self = (Pixy::Renderable*)  tolua_tousertype(tolua_S,1,0);
  Ogre::MovableObject* inObject = ((Ogre::MovableObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachSceneObject'", NULL);
#endif
  {
   self->attachSceneObject(inObject);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachSceneObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSceneObject of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_Renderable_getSceneObject00
static int tolua_EClient_Pixy_Renderable_getSceneObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Renderable* self = (Pixy::Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneObject'", NULL);
#endif
  {
   Ogre::MovableObject* tolua_ret = (Ogre::MovableObject*)  self->getSceneObject();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::MovableObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSceneObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CPuppet_new00
static int tolua_EClient_Pixy_CPuppet_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::CPuppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::CPuppet* tolua_ret = (Pixy::CPuppet*)  Mtolua_new((Pixy::CPuppet)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::CPuppet");
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

/* method: new_local of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CPuppet_new00_local
static int tolua_EClient_Pixy_CPuppet_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::CPuppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::CPuppet* tolua_ret = (Pixy::CPuppet*)  Mtolua_new((Pixy::CPuppet)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::CPuppet");
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

/* method: delete of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CPuppet_delete00
static int tolua_EClient_Pixy_CPuppet_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CPuppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CPuppet* self = (Pixy::CPuppet*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getSpell of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CPuppet_getSpell00
static int tolua_EClient_Pixy_CPuppet_getSpell00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CPuppet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CPuppet* self = (Pixy::CPuppet*)  tolua_tousertype(tolua_S,1,0);
  int inUID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpell'", NULL);
#endif
  {
   Pixy::CSpell* tolua_ret = (Pixy::CSpell*)  self->getSpell(inUID);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::CSpell");
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

/* method: getRenderable of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CPuppet_getRenderable00
static int tolua_EClient_Pixy_CPuppet_getRenderable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CPuppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CPuppet* self = (Pixy::CPuppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRenderable'", NULL);
#endif
  {
   Pixy::Renderable& tolua_ret = (Pixy::Renderable&)  self->getRenderable();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Pixy::Renderable");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRenderable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CSpell_new00
static int tolua_EClient_Pixy_CSpell_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::CSpell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::CSpell* tolua_ret = (Pixy::CSpell*)  Mtolua_new((Pixy::CSpell)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::CSpell");
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

/* method: new_local of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CSpell_new00_local
static int tolua_EClient_Pixy_CSpell_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::CSpell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::CSpell* tolua_ret = (Pixy::CSpell*)  Mtolua_new((Pixy::CSpell)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::CSpell");
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

/* method: delete of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CSpell_delete00
static int tolua_EClient_Pixy_CSpell_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CSpell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CSpell* self = (Pixy::CSpell*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setImageSet of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CSpell_setImageSet00
static int tolua_EClient_Pixy_CSpell_setImageSet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CSpell",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CSpell* self = (Pixy::CSpell*)  tolua_tousertype(tolua_S,1,0);
  std::string inName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
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

/* method: setImageName of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CSpell_setImageName00
static int tolua_EClient_Pixy_CSpell_setImageName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CSpell",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CSpell* self = (Pixy::CSpell*)  tolua_tousertype(tolua_S,1,0);
  std::string inName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
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

/* method: setButton of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CSpell_setButton00
static int tolua_EClient_Pixy_CSpell_setButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CSpell",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CEGUI::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CSpell* self = (Pixy::CSpell*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getImageSet of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CSpell_getImageSet00
static int tolua_EClient_Pixy_CSpell_getImageSet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CSpell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CSpell* self = (Pixy::CSpell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getImageSet'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getImageSet();
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

/* method: getImageName of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CSpell_getImageName00
static int tolua_EClient_Pixy_CSpell_getImageName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CSpell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CSpell* self = (Pixy::CSpell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getImageName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getImageName();
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

/* method: getButton of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CSpell_getButton00
static int tolua_EClient_Pixy_CSpell_getButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CSpell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CSpell* self = (Pixy::CSpell*)  tolua_tousertype(tolua_S,1,0);
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

/* method: generate of class  Pixy::CDeck */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CDeck_generate00
static int tolua_EClient_Pixy_CDeck_generate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CDeck",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CDeck* self = (Pixy::CDeck*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getSpell of class  Pixy::CDeck */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CDeck_getSpell00
static int tolua_EClient_Pixy_CDeck_getSpell00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CDeck",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CDeck* self = (Pixy::CDeck*)  tolua_tousertype(tolua_S,1,0);
  std::string inName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpell'", NULL);
#endif
  {
   Pixy::CSpell* tolua_ret = (Pixy::CSpell*)  self->getSpell(inName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::CSpell");
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

/* method: new of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CUnit_new00
static int tolua_EClient_Pixy_CUnit_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::CUnit* tolua_ret = (Pixy::CUnit*)  Mtolua_new((Pixy::CUnit)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::CUnit");
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

/* method: new_local of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CUnit_new00_local
static int tolua_EClient_Pixy_CUnit_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::CUnit* tolua_ret = (Pixy::CUnit*)  Mtolua_new((Pixy::CUnit)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::CUnit");
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

/* method: delete of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CUnit_delete00
static int tolua_EClient_Pixy_CUnit_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CUnit* self = (Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getRenderable of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_CUnit_getRenderable00
static int tolua_EClient_Pixy_CUnit_getRenderable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CUnit* self = (Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRenderable'", NULL);
#endif
  {
   Pixy::Renderable& tolua_ret = (Pixy::Renderable&)  self->getRenderable();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Pixy::Renderable");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRenderable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: changeState of class  Pixy::GameManager */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GameManager_changeState00
static int tolua_EClient_Pixy_GameManager_changeState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GameManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::GameState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GameManager* self = (Pixy::GameManager*)  tolua_tousertype(tolua_S,1,0);
  Pixy::GameState* inState = ((Pixy::GameState*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeState'", NULL);
#endif
  {
   self->changeState(inState);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingleton of class  Pixy::GameManager */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GameManager_getSingleton00
static int tolua_EClient_Pixy_GameManager_getSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::GameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::GameManager& tolua_ret = (Pixy::GameManager&)  Pixy::GameManager::getSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Pixy::GameManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingleton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: requestShutdown of class  Pixy::GameManager */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GameManager_requestShutdown00
static int tolua_EClient_Pixy_GameManager_requestShutdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GameManager* self = (Pixy::GameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'requestShutdown'", NULL);
#endif
  {
   self->requestShutdown();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'requestShutdown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: changeState of class  Pixy::GameState */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GameState_changeState00
static int tolua_EClient_Pixy_GameState_changeState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GameState",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::GameState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GameState* self = (Pixy::GameState*)  tolua_tousertype(tolua_S,1,0);
  Pixy::GameState* state = ((Pixy::GameState*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeState'", NULL);
#endif
  {
   self->changeState(state);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: requestShutdown of class  Pixy::GameState */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GameState_requestShutdown00
static int tolua_EClient_Pixy_GameState_requestShutdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GameState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GameState* self = (Pixy::GameState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'requestShutdown'", NULL);
#endif
  {
   self->requestShutdown();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'requestShutdown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingleton of class  Pixy::Intro */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_Intro_getSingleton00
static int tolua_EClient_Pixy_Intro_getSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Intro",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::Intro& tolua_ret = (Pixy::Intro&)  Pixy::Intro::getSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Pixy::Intro");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingleton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingletonPtr of class  Pixy::Intro */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_Intro_getSingletonPtr00
static int tolua_EClient_Pixy_Intro_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Intro",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::Intro* tolua_ret = (Pixy::Intro*)  Pixy::Intro::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Intro");
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

/* method: getSingleton of class  Pixy::Combat */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_Combat_getSingleton00
static int tolua_EClient_Pixy_Combat_getSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Combat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::Combat& tolua_ret = (Pixy::Combat&)  Pixy::Combat::getSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Pixy::Combat");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSingleton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingletonPtr of class  Pixy::Combat */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_Combat_getSingletonPtr00
static int tolua_EClient_Pixy_Combat_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Combat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::Combat* tolua_ret = (Pixy::Combat*)  Pixy::Combat::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Combat");
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

/* method: getPuppets of class  Pixy::Combat */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_Combat_getPuppets00
static int tolua_EClient_Pixy_Combat_getPuppets00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Combat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Combat* self = (Pixy::Combat*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPuppets'", NULL);
#endif
  {
   std::list<Pixy::CPuppet*> const& tolua_ret = (std::list<Pixy::CPuppet*> const&)  self->getPuppets();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPuppets'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Pixy::UIEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_UIEngine_delete00
static int tolua_EClient_Pixy_UIEngine_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::UIEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::UIEngine* self = (Pixy::UIEngine*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getSingletonPtr of class  Pixy::UIEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_UIEngine_getSingletonPtr00
static int tolua_EClient_Pixy_UIEngine_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::UIEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::UIEngine* tolua_ret = (Pixy::UIEngine*)  Pixy::UIEngine::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::UIEngine");
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

/* method: setup of class  Pixy::UIEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_UIEngine_setup00
static int tolua_EClient_Pixy_UIEngine_setup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::UIEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::UIEngine* self = (Pixy::UIEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setup'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setup();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  Pixy::UIEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_UIEngine_update00
static int tolua_EClient_Pixy_UIEngine_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::UIEngine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::UIEngine* self = (Pixy::UIEngine*)  tolua_tousertype(tolua_S,1,0);
  unsigned long lTimeElapsed = ((unsigned long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(lTimeElapsed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cleanup of class  Pixy::UIEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_UIEngine_cleanup00
static int tolua_EClient_Pixy_UIEngine_cleanup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::UIEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::UIEngine* self = (Pixy::UIEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cleanup'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->cleanup();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cleanup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __Pixy of class  Pixy::UIEngine */
#ifndef TOLUA_DISABLE_tolua_get_Pixy__UIEngine___Pixy__EventListener__
static int tolua_get_Pixy__UIEngine___Pixy__EventListener__(lua_State* tolua_S)
{
  Pixy::UIEngine* self = (Pixy::UIEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__Pixy'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<Pixy::EventListener*>(self), "Pixy::EventListener");
#else
   tolua_pushusertype(tolua_S,(void*)((Pixy::EventListener*)self), "Pixy::EventListener");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GfxEngine_delete00
static int tolua_EClient_Pixy_GfxEngine_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getSingletonPtr of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GfxEngine_getSingletonPtr00
static int tolua_EClient_Pixy_GfxEngine_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::GfxEngine* tolua_ret = (Pixy::GfxEngine*)  Pixy::GfxEngine::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::GfxEngine");
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

/* method: attachToScene of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GfxEngine_attachToScene00
static int tolua_EClient_Pixy_GfxEngine_attachToScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Pixy::Renderable",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Renderable* inEntity = ((Pixy::Renderable*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachToScene'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->attachToScene(*inEntity);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachToScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: detachFromScene of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GfxEngine_detachFromScene00
static int tolua_EClient_Pixy_GfxEngine_detachFromScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Pixy::Renderable",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Renderable* inEntity = ((Pixy::Renderable*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detachFromScene'", NULL);
#endif
  {
   self->detachFromScene(*inEntity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'detachFromScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCamera of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GfxEngine_getCamera00
static int tolua_EClient_Pixy_GfxEngine_getCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCamera'", NULL);
#endif
  {
   Ogre::Camera* tolua_ret = (Ogre::Camera*)  self->getCamera();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Camera");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRoot of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GfxEngine_getRoot00
static int tolua_EClient_Pixy_GfxEngine_getRoot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRoot'", NULL);
#endif
  {
   Ogre::Root* tolua_ret = (Ogre::Root*)  self->getRoot();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Root");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRoot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSM of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GfxEngine_getSM00
static int tolua_EClient_Pixy_GfxEngine_getSM00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSM'", NULL);
#endif
  {
   Ogre::SceneManager* tolua_ret = (Ogre::SceneManager*)  self->getSM();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSM'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewport of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GfxEngine_getViewport00
static int tolua_EClient_Pixy_GfxEngine_getViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewport'", NULL);
#endif
  {
   Ogre::Viewport* tolua_ret = (Ogre::Viewport*)  self->getViewport();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Viewport");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setupSceneManager of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GfxEngine_setupSceneManager00
static int tolua_EClient_Pixy_GfxEngine_setupSceneManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupSceneManager'", NULL);
#endif
  {
   self->setupSceneManager();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setupSceneManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setupViewports of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GfxEngine_setupViewports00
static int tolua_EClient_Pixy_GfxEngine_setupViewports00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupViewports'", NULL);
#endif
  {
   self->setupViewports();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setupViewports'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setupCamera of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GfxEngine_setupCamera00
static int tolua_EClient_Pixy_GfxEngine_setupCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupCamera'", NULL);
#endif
  {
   self->setupCamera();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setupCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setupTerrain of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GfxEngine_setupTerrain00
static int tolua_EClient_Pixy_GfxEngine_setupTerrain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupTerrain'", NULL);
#endif
  {
   self->setupTerrain();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setupTerrain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setupLights of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GfxEngine_setupLights00
static int tolua_EClient_Pixy_GfxEngine_setupLights00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupLights'", NULL);
#endif
  {
   self->setupLights();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setupLights'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setupNodes of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GfxEngine_setupNodes00
static int tolua_EClient_Pixy_GfxEngine_setupNodes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupNodes'", NULL);
#endif
  {
   self->setupNodes();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setupNodes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setupWaypoints of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_GfxEngine_setupWaypoints00
static int tolua_EClient_Pixy_GfxEngine_setupWaypoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupWaypoints'", NULL);
#endif
  {
   self->setupWaypoints();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setupWaypoints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __Pixy of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Pixy__GfxEngine___Pixy__EventListener__
static int tolua_get_Pixy__GfxEngine___Pixy__EventListener__(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__Pixy'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<Pixy::EventListener*>(self), "Pixy::EventListener");
#else
   tolua_pushusertype(tolua_S,(void*)((Pixy::EventListener*)self), "Pixy::EventListener");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: Pixy::ScriptEngine::luaLog */
#ifndef TOLUA_DISABLE_tolua_EClient_Pixy_Log00
static int tolua_EClient_Pixy_Log00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_iscppstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string inMsg = ((std::string)  tolua_tocppstring(tolua_S,1,0));
  {
   Pixy::ScriptEngine::luaLog(inMsg);
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

/* Open function */
TOLUA_API int tolua_EClient_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"Pixy",0);
  tolua_beginmodule(tolua_S,"Pixy");
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
   tolua_cclass(tolua_S,"Renderable","Pixy::Renderable","",tolua_collect_Pixy__Renderable);
   #else
   tolua_cclass(tolua_S,"Renderable","Pixy::Renderable","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Renderable");
    tolua_function(tolua_S,"new",tolua_EClient_Pixy_Renderable_new00);
    tolua_function(tolua_S,"new_local",tolua_EClient_Pixy_Renderable_new00_local);
    tolua_function(tolua_S,".call",tolua_EClient_Pixy_Renderable_new00_local);
    tolua_function(tolua_S,"delete",tolua_EClient_Pixy_Renderable_delete00);
    tolua_function(tolua_S,"getEntity",tolua_EClient_Pixy_Renderable_getEntity00);
    tolua_function(tolua_S,"attachSceneNode",tolua_EClient_Pixy_Renderable_attachSceneNode00);
    tolua_function(tolua_S,"getSceneNode",tolua_EClient_Pixy_Renderable_getSceneNode00);
    tolua_function(tolua_S,"attachSceneObject",tolua_EClient_Pixy_Renderable_attachSceneObject00);
    tolua_function(tolua_S,"getSceneObject",tolua_EClient_Pixy_Renderable_getSceneObject00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CPuppet","Pixy::CPuppet","Pixy::Puppet",tolua_collect_Pixy__CPuppet);
   #else
   tolua_cclass(tolua_S,"CPuppet","Pixy::CPuppet","Pixy::Puppet",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CPuppet");
    tolua_function(tolua_S,"new",tolua_EClient_Pixy_CPuppet_new00);
    tolua_function(tolua_S,"new_local",tolua_EClient_Pixy_CPuppet_new00_local);
    tolua_function(tolua_S,".call",tolua_EClient_Pixy_CPuppet_new00_local);
    tolua_function(tolua_S,"delete",tolua_EClient_Pixy_CPuppet_delete00);
    tolua_function(tolua_S,"getSpell",tolua_EClient_Pixy_CPuppet_getSpell00);
    tolua_function(tolua_S,"getRenderable",tolua_EClient_Pixy_CPuppet_getRenderable00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CSpell","Pixy::CSpell","Pixy::Spell",tolua_collect_Pixy__CSpell);
   #else
   tolua_cclass(tolua_S,"CSpell","Pixy::CSpell","Pixy::Spell",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CSpell");
    tolua_function(tolua_S,"new",tolua_EClient_Pixy_CSpell_new00);
    tolua_function(tolua_S,"new_local",tolua_EClient_Pixy_CSpell_new00_local);
    tolua_function(tolua_S,".call",tolua_EClient_Pixy_CSpell_new00_local);
    tolua_function(tolua_S,"delete",tolua_EClient_Pixy_CSpell_delete00);
    tolua_function(tolua_S,"setImageSet",tolua_EClient_Pixy_CSpell_setImageSet00);
    tolua_function(tolua_S,"setImageName",tolua_EClient_Pixy_CSpell_setImageName00);
    tolua_function(tolua_S,"setButton",tolua_EClient_Pixy_CSpell_setButton00);
    tolua_function(tolua_S,"getImageSet",tolua_EClient_Pixy_CSpell_getImageSet00);
    tolua_function(tolua_S,"getImageName",tolua_EClient_Pixy_CSpell_getImageName00);
    tolua_function(tolua_S,"getButton",tolua_EClient_Pixy_CSpell_getButton00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"CDeck","Pixy::CDeck","Pixy::Deck",NULL);
   tolua_beginmodule(tolua_S,"CDeck");
    tolua_function(tolua_S,"generate",tolua_EClient_Pixy_CDeck_generate00);
    tolua_function(tolua_S,"getSpell",tolua_EClient_Pixy_CDeck_getSpell00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CUnit","Pixy::CUnit","Pixy::Unit",tolua_collect_Pixy__CUnit);
   #else
   tolua_cclass(tolua_S,"CUnit","Pixy::CUnit","Pixy::Unit",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CUnit");
    tolua_function(tolua_S,"new",tolua_EClient_Pixy_CUnit_new00);
    tolua_function(tolua_S,"new_local",tolua_EClient_Pixy_CUnit_new00_local);
    tolua_function(tolua_S,".call",tolua_EClient_Pixy_CUnit_new00_local);
    tolua_function(tolua_S,"delete",tolua_EClient_Pixy_CUnit_delete00);
    tolua_function(tolua_S,"getRenderable",tolua_EClient_Pixy_CUnit_getRenderable00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GameManager","Pixy::GameManager","",NULL);
   tolua_beginmodule(tolua_S,"GameManager");
    tolua_function(tolua_S,"changeState",tolua_EClient_Pixy_GameManager_changeState00);
    tolua_function(tolua_S,"getSingleton",tolua_EClient_Pixy_GameManager_getSingleton00);
    tolua_function(tolua_S,"requestShutdown",tolua_EClient_Pixy_GameManager_requestShutdown00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GameState","Pixy::GameState","",NULL);
   tolua_beginmodule(tolua_S,"GameState");
    tolua_function(tolua_S,"changeState",tolua_EClient_Pixy_GameState_changeState00);
    tolua_function(tolua_S,"requestShutdown",tolua_EClient_Pixy_GameState_requestShutdown00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Intro","Pixy::Intro","Pixy::GameState",NULL);
   tolua_beginmodule(tolua_S,"Intro");
    tolua_function(tolua_S,"getSingleton",tolua_EClient_Pixy_Intro_getSingleton00);
    tolua_function(tolua_S,"getSingletonPtr",tolua_EClient_Pixy_Intro_getSingletonPtr00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Combat","Pixy::Combat","Pixy::GameState",NULL);
   tolua_beginmodule(tolua_S,"Combat");
    tolua_function(tolua_S,"getSingleton",tolua_EClient_Pixy_Combat_getSingleton00);
    tolua_function(tolua_S,"getSingletonPtr",tolua_EClient_Pixy_Combat_getSingletonPtr00);
    tolua_function(tolua_S,"getPuppets",tolua_EClient_Pixy_Combat_getPuppets00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"UIEngine","Pixy::UIEngine","Pixy::Engine",tolua_collect_Pixy__UIEngine);
   #else
   tolua_cclass(tolua_S,"UIEngine","Pixy::UIEngine","Pixy::Engine",NULL);
   #endif
   tolua_beginmodule(tolua_S,"UIEngine");
    tolua_function(tolua_S,"delete",tolua_EClient_Pixy_UIEngine_delete00);
    tolua_function(tolua_S,"getSingletonPtr",tolua_EClient_Pixy_UIEngine_getSingletonPtr00);
    tolua_function(tolua_S,"setup",tolua_EClient_Pixy_UIEngine_setup00);
    tolua_function(tolua_S,"update",tolua_EClient_Pixy_UIEngine_update00);
    tolua_function(tolua_S,"cleanup",tolua_EClient_Pixy_UIEngine_cleanup00);
    tolua_variable(tolua_S,"__Pixy__EventListener__",tolua_get_Pixy__UIEngine___Pixy__EventListener__,NULL);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"GfxEngine","Pixy::GfxEngine","Pixy::Engine",tolua_collect_Pixy__GfxEngine);
   #else
   tolua_cclass(tolua_S,"GfxEngine","Pixy::GfxEngine","Pixy::Engine",NULL);
   #endif
   tolua_beginmodule(tolua_S,"GfxEngine");
    tolua_function(tolua_S,"delete",tolua_EClient_Pixy_GfxEngine_delete00);
    tolua_function(tolua_S,"getSingletonPtr",tolua_EClient_Pixy_GfxEngine_getSingletonPtr00);
    tolua_function(tolua_S,"attachToScene",tolua_EClient_Pixy_GfxEngine_attachToScene00);
    tolua_function(tolua_S,"detachFromScene",tolua_EClient_Pixy_GfxEngine_detachFromScene00);
    tolua_function(tolua_S,"getCamera",tolua_EClient_Pixy_GfxEngine_getCamera00);
    tolua_function(tolua_S,"getRoot",tolua_EClient_Pixy_GfxEngine_getRoot00);
    tolua_function(tolua_S,"getSM",tolua_EClient_Pixy_GfxEngine_getSM00);
    tolua_function(tolua_S,"getViewport",tolua_EClient_Pixy_GfxEngine_getViewport00);
    tolua_function(tolua_S,"setupSceneManager",tolua_EClient_Pixy_GfxEngine_setupSceneManager00);
    tolua_function(tolua_S,"setupViewports",tolua_EClient_Pixy_GfxEngine_setupViewports00);
    tolua_function(tolua_S,"setupCamera",tolua_EClient_Pixy_GfxEngine_setupCamera00);
    tolua_function(tolua_S,"setupTerrain",tolua_EClient_Pixy_GfxEngine_setupTerrain00);
    tolua_function(tolua_S,"setupLights",tolua_EClient_Pixy_GfxEngine_setupLights00);
    tolua_function(tolua_S,"setupNodes",tolua_EClient_Pixy_GfxEngine_setupNodes00);
    tolua_function(tolua_S,"setupWaypoints",tolua_EClient_Pixy_GfxEngine_setupWaypoints00);
    tolua_variable(tolua_S,"__Pixy__EventListener__",tolua_get_Pixy__GfxEngine___Pixy__EventListener__,NULL);
   tolua_endmodule(tolua_S);
   tolua_function(tolua_S,"Log",tolua_EClient_Pixy_Log00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_EClient (lua_State* tolua_S) {
 return tolua_EClient_open(tolua_S);
};
#endif

