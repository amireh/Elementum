/*
** Lua binding: Elementum
** Generated automatically by tolua++-1.0.92 on Fri Oct 14 21:24:43 2011.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Elementum_open (lua_State* tolua_S);

#include "pixy/required.h"
#include "Pixy.h"
#include "Renderable.h"
#include "Renderable.h"
#include "CPuppet.h"
#include "CDeck.h"
#include "CSpell.h"
#include "CUnit.h"
#include "CSpell.h"
#include "CDeck.h"
#include "Renderable.h"
#include "CUnit.h"
#include "CDeck.h"
#include "FxEngine.h"
#include "GameManager.h"
#include "InputManager.h"
#include "GameState.h"
#include "Intro.h"
#include "Lobby.h"
#include "Combat.h"
#include "Engine.h"
#include "UIEngine.h"
#include "GfxEngine.h"
#include "ScriptEngine.h"
#include "NetworkManager.h"
#include "ScriptEngine.h"
#include <lua.h>
#include "LuaExporter.h"
#include "CPuppet.h"
#include "CUnit.h"
#include "CSpell.h"
#include "OgreRTT.h"
#include "Ogre.h"
#include "Ogre.h"
#include "ogre/SdkCameraMan.h"
#include "OIS.h"
#include "cegui/FormattedListboxTextItem.h"
#include "CEGUI/CEGUI.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Ogre__Vector2 (lua_State* tolua_S)
{
 Ogre::Vector2* self = (Ogre::Vector2*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__FxEngine (lua_State* tolua_S)
{
 Pixy::FxEngine* self = (Pixy::FxEngine*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__uint16 (lua_State* tolua_S)
{
 Ogre::uint16* self = (Ogre::uint16*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__Radian (lua_State* tolua_S)
{
 Ogre::Radian* self = (Ogre::Radian*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__RenderWindow (lua_State* tolua_S)
{
 Ogre::RenderWindow* self = (Ogre::RenderWindow*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__LuaExporter_CSpellList_ (lua_State* tolua_S)
{
 Pixy::LuaExporter<CSpellList>* self = (Pixy::LuaExporter<CSpellList>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__CSpell (lua_State* tolua_S)
{
 Pixy::CSpell* self = (Pixy::CSpell*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__AxisAlignedBox (lua_State* tolua_S)
{
 Ogre::AxisAlignedBox* self = (Ogre::AxisAlignedBox*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__Degree (lua_State* tolua_S)
{
 Ogre::Degree* self = (Ogre::Degree*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_size_t (lua_State* tolua_S)
{
 size_t* self = (size_t*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__OgreRTT (lua_State* tolua_S)
{
 Pixy::OgreRTT* self = (Pixy::OgreRTT*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__Any (lua_State* tolua_S)
{
 Ogre::Any* self = (Ogre::Any*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__BillboardSet (lua_State* tolua_S)
{
 Ogre::BillboardSet* self = (Ogre::BillboardSet*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__Plane (lua_State* tolua_S)
{
 Ogre::Plane* self = (Ogre::Plane*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ParticleUniverse__ParticleSystem (lua_State* tolua_S)
{
 ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_OgreBites__SdkCameraMan (lua_State* tolua_S)
{
 OgreBites::SdkCameraMan* self = (OgreBites::SdkCameraMan*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__LuaExporter_CSpellVec_ (lua_State* tolua_S)
{
 Pixy::LuaExporter<CSpellVec>* self = (Pixy::LuaExporter<CSpellVec>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__Light (lua_State* tolua_S)
{
 Ogre::Light* self = (Ogre::Light*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__CUnit (lua_State* tolua_S)
{
 Pixy::CUnit* self = (Pixy::CUnit*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__Quaternion (lua_State* tolua_S)
{
 Ogre::Quaternion* self = (Ogre::Quaternion*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__LuaExporter_CUnitList_ (lua_State* tolua_S)
{
 Pixy::LuaExporter<CUnitList>* self = (Pixy::LuaExporter<CUnitList>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__CPuppet (lua_State* tolua_S)
{
 Pixy::CPuppet* self = (Pixy::CPuppet*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__Renderable (lua_State* tolua_S)
{
 Pixy::Renderable* self = (Pixy::Renderable*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__ColourValue (lua_State* tolua_S)
{
 Ogre::ColourValue* self = (Ogre::ColourValue*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__LuaExporter_CPuppetList_ (lua_State* tolua_S)
{
 Pixy::LuaExporter<CPuppetList>* self = (Pixy::LuaExporter<CPuppetList>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__Billboard (lua_State* tolua_S)
{
 Ogre::Billboard* self = (Ogre::Billboard*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__MeshPtr (lua_State* tolua_S)
{
 Ogre::MeshPtr* self = (Ogre::MeshPtr*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__Angle (lua_State* tolua_S)
{
 Ogre::Angle* self = (Ogre::Angle*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__Vector3 (lua_State* tolua_S)
{
 Ogre::Vector3* self = (Ogre::Vector3*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__GfxEngine (lua_State* tolua_S)
{
 Pixy::GfxEngine* self = (Pixy::GfxEngine*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__SharedPtr_Ogre__Resource_ (lua_State* tolua_S)
{
 Ogre::SharedPtr<Ogre::Resource>* self = (Ogre::SharedPtr<Ogre::Resource>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__LuaExporter_CUnitVec_ (lua_State* tolua_S)
{
 Pixy::LuaExporter<CUnitVec>* self = (Pixy::LuaExporter<CUnitVec>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__LuaExporter_CPuppetVec_ (lua_State* tolua_S)
{
 Pixy::LuaExporter<CPuppetVec>* self = (Pixy::LuaExporter<CPuppetVec>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Pixy__UIEngine (lua_State* tolua_S)
{
 Pixy::UIEngine* self = (Pixy::UIEngine*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Ogre__Camera (lua_State* tolua_S)
{
 Ogre::Camera* self = (Ogre::Camera*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Ogre::RenderTarget");
 tolua_usertype(tolua_S,"Pixy::InputManager");
 tolua_usertype(tolua_S,"Ogre::Renderable");
 tolua_usertype(tolua_S,"Pixy::Spell");
 tolua_usertype(tolua_S,"Ogre::uint16");
 tolua_usertype(tolua_S,"Ogre::Radian");
 tolua_usertype(tolua_S,"Ogre::RenderWindow");
 tolua_usertype(tolua_S,"Pixy::GameManager");
 tolua_usertype(tolua_S,"const");
 tolua_usertype(tolua_S,"Ogre::Degree");
 tolua_usertype(tolua_S,"Pixy::GameState");
 tolua_usertype(tolua_S,"size_t");
 tolua_usertype(tolua_S,"Pixy::CDeck");
 tolua_usertype(tolua_S,"Ogre::SubEntity");
 tolua_usertype(tolua_S,"Pixy::NetworkManager");
 tolua_usertype(tolua_S,"OgreMax::OgreMaxScene");
 tolua_usertype(tolua_S,"CEGUI::UBox");
 tolua_usertype(tolua_S,"OgreBites::SdkCameraMan");
 tolua_usertype(tolua_S,"Ogre::Resource");
 tolua_usertype(tolua_S,"BaseLuaExporter");
 tolua_usertype(tolua_S,"Pixy::LuaExporter<CUnitList>");
 tolua_usertype(tolua_S,"Ogre::Root");
 tolua_usertype(tolua_S,"Pixy::CPuppet");
 tolua_usertype(tolua_S,"Pixy::EventListener");
 tolua_usertype(tolua_S,"Pixy::Puppet");
 tolua_usertype(tolua_S,"Ogre::MovableObject");
 tolua_usertype(tolua_S,"Pixy::Lobby");
 tolua_usertype(tolua_S,"Ogre::Vector2");
 tolua_usertype(tolua_S,"Ogre::CompositorManager");
 tolua_usertype(tolua_S,"Pixy::FxEngine");
 tolua_usertype(tolua_S,"ParticleUniverse::ParticleSystem");
 tolua_usertype(tolua_S,"ParticleUniverse::ParticleTechnique");
 tolua_usertype(tolua_S,"Pixy::Event");
 tolua_usertype(tolua_S,"Pixy::Deck");
 tolua_usertype(tolua_S,"Ogre::MeshManager");
 tolua_usertype(tolua_S,"Pixy::LuaExporter<CSpellList>");
 tolua_usertype(tolua_S,"Pixy::CSpell");
 tolua_usertype(tolua_S,"Ogre::AxisAlignedBox");
 tolua_usertype(tolua_S,"CEGUI::ListboxTextItem");
 tolua_usertype(tolua_S,"CEGUI::FormattedListboxTextItem");
 tolua_usertype(tolua_S,"OIS::Keyboard");
 tolua_usertype(tolua_S,"Ogre::MeshPtr");
 tolua_usertype(tolua_S,"OIS::KeyEvent");
 tolua_usertype(tolua_S,"Ogre::Camera");
 tolua_usertype(tolua_S,"Ogre::CompositorLogic");
 tolua_usertype(tolua_S,"Ogre::Any");
 tolua_usertype(tolua_S,"Ogre::Billboard");
 tolua_usertype(tolua_S,"Pixy::UIEngine");
 tolua_usertype(tolua_S,"Pixy::Entity");
 tolua_usertype(tolua_S,"Pixy::Combat");
 tolua_usertype(tolua_S,"Ogre::ManualResourceLoader");
 tolua_usertype(tolua_S,"Pixy::Unit");
 tolua_usertype(tolua_S,"Pixy::ScriptEngine");
 tolua_usertype(tolua_S,"Ogre::InstancedGeometry");
 tolua_usertype(tolua_S,"Ogre::Viewport");
 tolua_usertype(tolua_S,"Ogre::SharedPtr<Ogre::Resource>");
 tolua_usertype(tolua_S,"Ogre::SceneNode");
 tolua_usertype(tolua_S,"Ogre::BillboardSet");
 tolua_usertype(tolua_S,"Ogre::Plane");
 tolua_usertype(tolua_S,"Ogre::ResourceGroupManager");
 tolua_usertype(tolua_S,"Pixy::Intro");
 tolua_usertype(tolua_S,"ParticleUniverse::Particle");
 tolua_usertype(tolua_S,"Ogre::CompositorInstance");
 tolua_usertype(tolua_S,"Ogre::SceneManager");
 tolua_usertype(tolua_S,"Pixy::LuaExporter<CSpellVec>");
 tolua_usertype(tolua_S,"Ogre::Light");
 tolua_usertype(tolua_S,"Pixy::CUnit");
 tolua_usertype(tolua_S,"Pixy::LuaExporter<CUnitVec>");
 tolua_usertype(tolua_S,"Ogre::ResourceManager");
 tolua_usertype(tolua_S,"Ogre::RenderTarget::FrameStats");
 tolua_usertype(tolua_S,"CEGUI::Window");
 tolua_usertype(tolua_S,"Ogre::RibbonTrail");
 tolua_usertype(tolua_S,"Pixy::LuaExporter<CPuppetVec>");
 tolua_usertype(tolua_S,"std::type_info");
 tolua_usertype(tolua_S,"Pixy::Renderable");
 tolua_usertype(tolua_S,"Ogre::ColourValue");
 tolua_usertype(tolua_S,"Ogre::Entity");
 tolua_usertype(tolua_S,"Pixy::Engine");
 tolua_usertype(tolua_S,"Ogre::Node");
 tolua_usertype(tolua_S,"Ogre::Angle");
 tolua_usertype(tolua_S,"Ogre::Vector3");
 tolua_usertype(tolua_S,"Pixy::GfxEngine");
 tolua_usertype(tolua_S,"Pixy::LuaExporter<CPuppetList>");
 tolua_usertype(tolua_S,"Ogre::RenderTargetListener");
 tolua_usertype(tolua_S,"Ogre::Quaternion");
 tolua_usertype(tolua_S,"Pixy::OgreRTT");
 tolua_usertype(tolua_S,"Ogre::StaticGeometry");
}

/* method: new of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_new00
static int tolua_Elementum_Pixy_Renderable_new00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_new00_local
static int tolua_Elementum_Pixy_Renderable_new00_local(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_delete00
static int tolua_Elementum_Pixy_Renderable_delete00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_getEntity00
static int tolua_Elementum_Pixy_Renderable_getEntity00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEntity'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_attachSceneNode00
static int tolua_Elementum_Pixy_Renderable_attachSceneNode00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachSceneNode'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_getSceneNode00
static int tolua_Elementum_Pixy_Renderable_getSceneNode00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneNode'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_attachSceneObject00
static int tolua_Elementum_Pixy_Renderable_attachSceneObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Renderable* self = (Pixy::Renderable*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Entity* inObject = ((Ogre::Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachSceneObject'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_getSceneObject00
static int tolua_Elementum_Pixy_Renderable_getSceneObject00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneObject'",NULL);
#endif
  {
   Ogre::Entity* tolua_ret = (Ogre::Entity*)  self->getSceneObject();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Entity");
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

/* method: registerAnimationState of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_registerAnimationState00
static int tolua_Elementum_Pixy_Renderable_registerAnimationState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Renderable* self = (Pixy::Renderable*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Renderable::AnimID inId = ((Pixy::Renderable::AnimID) (int)  tolua_tonumber(tolua_S,2,0));
  std::string inState = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  bool doLoop = ((bool)  tolua_toboolean(tolua_S,4,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerAnimationState'",NULL);
#endif
  {
   self->registerAnimationState(inId,inState,doLoop);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerAnimationState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_setScale00
static int tolua_Elementum_Pixy_Renderable_setScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Renderable* self = (Pixy::Renderable*)  tolua_tousertype(tolua_S,1,0);
  float inScale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'",NULL);
#endif
  {
   self->setScale(inScale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimFadeSpeed of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_setAnimFadeSpeed00
static int tolua_Elementum_Pixy_Renderable_setAnimFadeSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float inSpeed = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   Pixy::Renderable::setAnimFadeSpeed(inSpeed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimFadeSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimFadeSpeed of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_getAnimFadeSpeed00
static int tolua_Elementum_Pixy_Renderable_getAnimFadeSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  Pixy::Renderable::getAnimFadeSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimFadeSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotationFactor of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_setRotationFactor00
static int tolua_Elementum_Pixy_Renderable_setRotationFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float inFactor = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   Pixy::Renderable::setRotationFactor(inFactor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotationFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateLive of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_animateLive00
static int tolua_Elementum_Pixy_Renderable_animateLive00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateLive'",NULL);
#endif
  {
   float tolua_ret = (float)  self->animateLive();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateLive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateDie of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_animateDie00
static int tolua_Elementum_Pixy_Renderable_animateDie00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateDie'",NULL);
#endif
  {
   float tolua_ret = (float)  self->animateDie();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateDie'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateIdle of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_animateIdle00
static int tolua_Elementum_Pixy_Renderable_animateIdle00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateIdle'",NULL);
#endif
  {
   float tolua_ret = (float)  self->animateIdle();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateIdle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateWalk of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_animateWalk00
static int tolua_Elementum_Pixy_Renderable_animateWalk00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateWalk'",NULL);
#endif
  {
   float tolua_ret = (float)  self->animateWalk();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateWalk'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateRun of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_animateRun00
static int tolua_Elementum_Pixy_Renderable_animateRun00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateRun'",NULL);
#endif
  {
   float tolua_ret = (float)  self->animateRun();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateRun'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateAttack of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_animateAttack00
static int tolua_Elementum_Pixy_Renderable_animateAttack00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateAttack'",NULL);
#endif
  {
   float tolua_ret = (float)  self->animateAttack();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateAttack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateHit of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_animateHit00
static int tolua_Elementum_Pixy_Renderable_animateHit00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateHit'",NULL);
#endif
  {
   float tolua_ret = (float)  self->animateHit();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateHit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateRest of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_animateRest00
static int tolua_Elementum_Pixy_Renderable_animateRest00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateRest'",NULL);
#endif
  {
   float tolua_ret = (float)  self->animateRest();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateRest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: animateGetUp of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_animateGetUp00
static int tolua_Elementum_Pixy_Renderable_animateGetUp00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'animateGetUp'",NULL);
#endif
  {
   float tolua_ret = (float)  self->animateGetUp();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'animateGetUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: _animate of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable__animate00
static int tolua_Elementum_Pixy_Renderable__animate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Renderable* self = (Pixy::Renderable*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Renderable::AnimID inId = ((Pixy::Renderable::AnimID) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '_animate'",NULL);
#endif
  {
   float tolua_ret = (float)  self->_animate(inId);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '_animate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setup of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_setup00
static int tolua_Elementum_Pixy_Renderable_setup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Renderable* self = (Pixy::Renderable*)  tolua_tousertype(tolua_S,1,0);
  Ogre::SceneManager* tolua_var_1 = ((Ogre::SceneManager*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setup'",NULL);
#endif
  {
   self->setup(tolua_var_1);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachExtension of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_attachExtension00
static int tolua_Elementum_Pixy_Renderable_attachExtension00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Renderable* self = (Pixy::Renderable*)  tolua_tousertype(tolua_S,1,0);
  std::string inMesh = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string inBone = ((std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachExtension'",NULL);
#endif
  {
   Ogre::Entity* tolua_ret = (Ogre::Entity*)  self->attachExtension(inMesh,inBone);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Entity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachExtension'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_hide00
static int tolua_Elementum_Pixy_Renderable_hide00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'",NULL);
#endif
  {
   self->hide();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Pixy::Renderable */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Renderable_show00
static int tolua_Elementum_Pixy_Renderable_show00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_new00
static int tolua_Elementum_Pixy_CPuppet_new00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_new00_local
static int tolua_Elementum_Pixy_CPuppet_new00_local(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_delete00
static int tolua_Elementum_Pixy_CPuppet_delete00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_getSpell00
static int tolua_Elementum_Pixy_CPuppet_getSpell00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpell'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_getRenderable00
static int tolua_Elementum_Pixy_CPuppet_getRenderable00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRenderable'",NULL);
#endif
  {
   Pixy::Renderable* tolua_ret = (Pixy::Renderable*)  self->getRenderable();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Renderable");
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

/* method: getHand of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_getHand00
static int tolua_Elementum_Pixy_CPuppet_getHand00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHand'",NULL);
#endif
  {
   Pixy::CPuppet::hand_t const& tolua_ret = (Pixy::CPuppet::hand_t const&)  self->getHand();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const");
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

/* method: nrSpellsInHand of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_nrSpellsInHand00
static int tolua_Elementum_Pixy_CPuppet_nrSpellsInHand00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'nrSpellsInHand'",NULL);
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

/* method: getSpell of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_getSpell01
static int tolua_Elementum_Pixy_CPuppet_getSpell01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CPuppet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Pixy::CPuppet* self = (Pixy::CPuppet*)  tolua_tousertype(tolua_S,1,0);
  int inUID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpell'",NULL);
#endif
  {
   Pixy::CSpell* tolua_ret = (Pixy::CSpell*)  self->getSpell(inUID);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::CSpell");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Pixy_CPuppet_getSpell00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachSpell of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_attachSpell00
static int tolua_Elementum_Pixy_CPuppet_attachSpell00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CPuppet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::CSpell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CPuppet* self = (Pixy::CPuppet*)  tolua_tousertype(tolua_S,1,0);
  Pixy::CSpell* inSpell = ((Pixy::CSpell*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachSpell'",NULL);
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

/* method: detachSpell of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_detachSpell00
static int tolua_Elementum_Pixy_CPuppet_detachSpell00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detachSpell'",NULL);
#endif
  {
   self->detachSpell(inUID);
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

/* method: attachUnit of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_attachUnit00
static int tolua_Elementum_Pixy_CPuppet_attachUnit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CPuppet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CPuppet* self = (Pixy::CPuppet*)  tolua_tousertype(tolua_S,1,0);
  Pixy::CUnit* inUnit = ((Pixy::CUnit*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachUnit'",NULL);
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

/* method: detachUnit of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_detachUnit00
static int tolua_Elementum_Pixy_CPuppet_detachUnit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CPuppet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CPuppet* self = (Pixy::CPuppet*)  tolua_tousertype(tolua_S,1,0);
  int inUID = ((int)  tolua_tonumber(tolua_S,2,0));
  bool tolua_var_2 = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detachUnit'",NULL);
#endif
  {
   self->detachUnit(inUID,tolua_var_2);
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

/* method: getUnit of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_getUnit00
static int tolua_Elementum_Pixy_CPuppet_getUnit00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUnit'",NULL);
#endif
  {
   Pixy::CUnit* tolua_ret = (Pixy::CUnit*)  self->getUnit(inUID);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::CUnit");
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

/* method: getUnits of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_getUnits00
static int tolua_Elementum_Pixy_CPuppet_getUnits00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUnits'",NULL);
#endif
  {
   Pixy::CPuppet::units_t const& tolua_ret = (Pixy::CPuppet::units_t const&)  self->getUnits();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const");
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

/* method: attachBuff of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_attachBuff00
static int tolua_Elementum_Pixy_CPuppet_attachBuff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CPuppet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::CSpell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CPuppet* self = (Pixy::CPuppet*)  tolua_tousertype(tolua_S,1,0);
  Pixy::CSpell* tolua_var_3 = ((Pixy::CSpell*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachBuff'",NULL);
#endif
  {
   self->attachBuff(tolua_var_3);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachBuff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: detachBuff of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_detachBuff00
static int tolua_Elementum_Pixy_CPuppet_detachBuff00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detachBuff'",NULL);
#endif
  {
   self->detachBuff(inUID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'detachBuff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasBuff of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_hasBuff00
static int tolua_Elementum_Pixy_CPuppet_hasBuff00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasBuff'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasBuff(inUID);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasBuff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBuffs of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_getBuffs00
static int tolua_Elementum_Pixy_CPuppet_getBuffs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::CPuppet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::CPuppet* self = (const Pixy::CPuppet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBuffs'",NULL);
#endif
  {
   Pixy::CPuppet::spells_t const& tolua_ret = (Pixy::CPuppet::spells_t const&)  self->getBuffs();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBuffs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateTextOverlay of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_updateTextOverlay00
static int tolua_Elementum_Pixy_CPuppet_updateTextOverlay00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateTextOverlay'",NULL);
#endif
  {
   self->updateTextOverlay();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateTextOverlay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHP of class  Pixy::CPuppet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppet_setHP00
static int tolua_Elementum_Pixy_CPuppet_setHP00(lua_State* tolua_S)
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
  int inHP = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHP'",NULL);
#endif
  {
   self->setHP(inHP);
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

/* method: new of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpell_new00
static int tolua_Elementum_Pixy_CSpell_new00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpell_new00_local
static int tolua_Elementum_Pixy_CSpell_new00_local(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpell_delete00
static int tolua_Elementum_Pixy_CSpell_delete00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpell_setImageSet00
static int tolua_Elementum_Pixy_CSpell_setImageSet00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setImageSet'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpell_setImageName00
static int tolua_Elementum_Pixy_CSpell_setImageName00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setImageName'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpell_setButton00
static int tolua_Elementum_Pixy_CSpell_setButton00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setButton'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpell_getImageSet00
static int tolua_Elementum_Pixy_CSpell_getImageSet00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getImageSet'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpell_getImageName00
static int tolua_Elementum_Pixy_CSpell_getImageName00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getImageName'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpell_getButton00
static int tolua_Elementum_Pixy_CSpell_getButton00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getButton'",NULL);
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

/* method: getTooltip of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpell_getTooltip00
static int tolua_Elementum_Pixy_CSpell_getTooltip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::CSpell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::CSpell* self = (const Pixy::CSpell*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTooltip'",NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getTooltip();
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

/* method: updateTooltip of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpell_updateTooltip00
static int tolua_Elementum_Pixy_CSpell_updateTooltip00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateTooltip'",NULL);
#endif
  {
   self->updateTooltip();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateTooltip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCaster of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpell_getCaster00
static int tolua_Elementum_Pixy_CSpell_getCaster00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCaster'",NULL);
#endif
  {
   Pixy::Renderable* tolua_ret = (Pixy::Renderable*)  self->getCaster();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Renderable");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCaster'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTarget of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpell_getTarget00
static int tolua_Elementum_Pixy_CSpell_getTarget00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTarget'",NULL);
#endif
  {
   Pixy::Renderable* tolua_ret = (Pixy::Renderable*)  self->getTarget();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Renderable");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCaster of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpell_setCaster00
static int tolua_Elementum_Pixy_CSpell_setCaster00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CSpell",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CSpell* self = (Pixy::CSpell*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Renderable* inCaster = ((Pixy::Renderable*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCaster'",NULL);
#endif
  {
   self->setCaster(inCaster);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCaster'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTarget of class  Pixy::CSpell */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpell_setTarget00
static int tolua_Elementum_Pixy_CSpell_setTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CSpell",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CSpell* self = (Pixy::CSpell*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Renderable* inTarget = ((Pixy::Renderable*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTarget'",NULL);
#endif
  {
   self->setTarget(inTarget);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: generate of class  Pixy::CDeck */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CDeck_generate00
static int tolua_Elementum_Pixy_CDeck_generate00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'generate'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CDeck_getSpell00
static int tolua_Elementum_Pixy_CDeck_getSpell00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpell'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_new00
static int tolua_Elementum_Pixy_CUnit_new00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_new00_local
static int tolua_Elementum_Pixy_CUnit_new00_local(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_delete00
static int tolua_Elementum_Pixy_CUnit_delete00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_getRenderable00
static int tolua_Elementum_Pixy_CUnit_getRenderable00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRenderable'",NULL);
#endif
  {
   Pixy::Renderable* tolua_ret = (Pixy::Renderable*)  self->getRenderable();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Renderable");
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

/* method: attachBuff of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_attachBuff00
static int tolua_Elementum_Pixy_CUnit_attachBuff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CUnit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::CSpell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CUnit* self = (Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
  Pixy::CSpell* tolua_var_4 = ((Pixy::CSpell*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachBuff'",NULL);
#endif
  {
   self->attachBuff(tolua_var_4);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachBuff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: detachBuff of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_detachBuff00
static int tolua_Elementum_Pixy_CUnit_detachBuff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CUnit* self = (Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
  int inUID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detachBuff'",NULL);
#endif
  {
   self->detachBuff(inUID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'detachBuff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasBuff of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_hasBuff00
static int tolua_Elementum_Pixy_CUnit_hasBuff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CUnit* self = (Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
  int inUID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasBuff'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasBuff(inUID);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasBuff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBuffs of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_getBuffs00
static int tolua_Elementum_Pixy_CUnit_getBuffs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::CUnit* self = (const Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBuffs'",NULL);
#endif
  {
   Pixy::CUnit::spells_t const& tolua_ret = (Pixy::CUnit::spells_t const&)  self->getBuffs();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBuffs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateTextOverlay of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_updateTextOverlay00
static int tolua_Elementum_Pixy_CUnit_updateTextOverlay00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateTextOverlay'",NULL);
#endif
  {
   self->updateTextOverlay();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateTextOverlay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fRequiresYawFix of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_get_Pixy__CUnit_fRequiresYawFix
static int tolua_get_Pixy__CUnit_fRequiresYawFix(lua_State* tolua_S)
{
  Pixy::CUnit* self = (Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fRequiresYawFix'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->fRequiresYawFix);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: fRequiresYawFix of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_set_Pixy__CUnit_fRequiresYawFix
static int tolua_set_Pixy__CUnit_fRequiresYawFix(lua_State* tolua_S)
{
  Pixy::CUnit* self = (Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fRequiresYawFix'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->fRequiresYawFix = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWalkSpeed of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_setWalkSpeed00
static int tolua_Elementum_Pixy_CUnit_setWalkSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CUnit* self = (Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
  const float inSpeed = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWalkSpeed'",NULL);
#endif
  {
   self->setWalkSpeed(inSpeed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWalkSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWalkSpeed of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_getWalkSpeed00
static int tolua_Elementum_Pixy_CUnit_getWalkSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::CUnit* self = (const Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWalkSpeed'",NULL);
#endif
  {
   float tolua_ret = (float)  self->getWalkSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWalkSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosition of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_getPosition00
static int tolua_Elementum_Pixy_CUnit_getPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::CUnit* self = (const Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosition'",NULL);
#endif
  {
   Pixy::UNIT_POS tolua_ret = (Pixy::UNIT_POS)  self->getPosition();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isDying of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_isDying00
static int tolua_Elementum_Pixy_CUnit_isDying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::CUnit* self = (const Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDying'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isDying();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isMoving of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_isMoving00
static int tolua_Elementum_Pixy_CUnit_isMoving00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::CUnit* self = (const Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isMoving'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isMoving();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isMoving'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEnemy of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_getEnemy00
static int tolua_Elementum_Pixy_CUnit_getEnemy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::CUnit* self = (const Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEnemy'",NULL);
#endif
  {
   Pixy::CPuppet* tolua_ret = (Pixy::CPuppet*)  self->getEnemy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::CPuppet");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEnemy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDefaultWalkSpeed of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_setDefaultWalkSpeed00
static int tolua_Elementum_Pixy_CUnit_setDefaultWalkSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float inSpeed = ((const float)  tolua_tonumber(tolua_S,2,0));
  {
   Pixy::CUnit::setDefaultWalkSpeed(inSpeed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDefaultWalkSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDefaultWalkSpeed of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_getDefaultWalkSpeed00
static int tolua_Elementum_Pixy_CUnit_getDefaultWalkSpeed00(lua_State* tolua_S)
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
   float tolua_ret = (float)  Pixy::CUnit::getDefaultWalkSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDefaultWalkSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEnemy of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_getEnemy01
static int tolua_Elementum_Pixy_CUnit_getEnemy01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Pixy::CUnit* self = (const Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEnemy'",NULL);
#endif
  {
   Pixy::CPuppet* tolua_ret = (Pixy::CPuppet*)  self->getEnemy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::CPuppet");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Pixy_CUnit_getEnemy00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBaseAP of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_setBaseAP00
static int tolua_Elementum_Pixy_CUnit_setBaseAP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CUnit* self = (Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
  int inHP = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBaseAP'",NULL);
#endif
  {
   self->setBaseAP(inHP);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBaseAP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAP of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_setAP00
static int tolua_Elementum_Pixy_CUnit_setAP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CUnit* self = (Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
  int inHP = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAP'",NULL);
#endif
  {
   self->setAP(inHP);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBaseHP of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_setBaseHP00
static int tolua_Elementum_Pixy_CUnit_setBaseHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CUnit* self = (Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
  int inHP = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBaseHP'",NULL);
#endif
  {
   self->setBaseHP(inHP);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBaseHP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHP of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_setHP00
static int tolua_Elementum_Pixy_CUnit_setHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::CUnit* self = (Pixy::CUnit*)  tolua_tousertype(tolua_S,1,0);
  int inHP = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHP'",NULL);
#endif
  {
   self->setHP(inHP);
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

/* method: live of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_live00
static int tolua_Elementum_Pixy_CUnit_live00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'live'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->live();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'live'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: die of class  Pixy::CUnit */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnit_die00
static int tolua_Elementum_Pixy_CUnit_die00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'die'",NULL);
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

/* method: delete of class  Pixy::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_FxEngine_delete00
static int tolua_Elementum_Pixy_FxEngine_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::FxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::FxEngine* self = (Pixy::FxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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

/* method: getSingletonPtr of class  Pixy::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_FxEngine_getSingletonPtr00
static int tolua_Elementum_Pixy_FxEngine_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::FxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::FxEngine* tolua_ret = (Pixy::FxEngine*)  Pixy::FxEngine::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::FxEngine");
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

/* method: getSingleton of class  Pixy::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_FxEngine_getSingleton00
static int tolua_Elementum_Pixy_FxEngine_getSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::FxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::FxEngine& tolua_ret = (Pixy::FxEngine&)  Pixy::FxEngine::getSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Pixy::FxEngine");
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

/* method: loadEffect of class  Pixy::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_FxEngine_loadEffect00
static int tolua_Elementum_Pixy_FxEngine_loadEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::FxEngine",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::FxEngine* self = (Pixy::FxEngine*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadEffect'",NULL);
#endif
  {
   ParticleUniverse::ParticleSystem* tolua_ret = (ParticleUniverse::ParticleSystem*)  self->loadEffect(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleUniverse::ParticleSystem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playEffect of class  Pixy::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_FxEngine_playEffect00
static int tolua_Elementum_Pixy_FxEngine_playEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::FxEngine",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::FxEngine* self = (Pixy::FxEngine*)  tolua_tousertype(tolua_S,1,0);
  std::string inEffect = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  Pixy::Renderable* inEntity = ((Pixy::Renderable*)  tolua_tousertype(tolua_S,3,0));
  bool newInstance = ((bool)  tolua_toboolean(tolua_S,4,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playEffect'",NULL);
#endif
  {
   ParticleUniverse::ParticleSystem* tolua_ret = (ParticleUniverse::ParticleSystem*)  self->playEffect(inEffect,inEntity,newInstance);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleUniverse::ParticleSystem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playEffect of class  Pixy::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_FxEngine_playEffect01
static int tolua_Elementum_Pixy_FxEngine_playEffect01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::FxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Pixy::FxEngine* self = (Pixy::FxEngine*)  tolua_tousertype(tolua_S,1,0);
  ParticleUniverse::ParticleSystem* tolua_var_5 = ((ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,2,0));
  Pixy::Renderable* inEntity = ((Pixy::Renderable*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playEffect'",NULL);
#endif
  {
   ParticleUniverse::ParticleSystem* tolua_ret = (ParticleUniverse::ParticleSystem*)  self->playEffect(tolua_var_5,inEntity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleUniverse::ParticleSystem");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Pixy_FxEngine_playEffect00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: playEffect of class  Pixy::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_FxEngine_playEffect02
static int tolua_Elementum_Pixy_FxEngine_playEffect02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::FxEngine",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Pixy::FxEngine* self = (Pixy::FxEngine*)  tolua_tousertype(tolua_S,1,0);
  std::string inEffect = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  const Ogre::Vector3 pos = *((const Ogre::Vector3*)  tolua_tousertype(tolua_S,3,0));
  bool newInstance = ((bool)  tolua_toboolean(tolua_S,4,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playEffect'",NULL);
#endif
  {
   ParticleUniverse::ParticleSystem* tolua_ret = (ParticleUniverse::ParticleSystem*)  self->playEffect(inEffect,pos,newInstance);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleUniverse::ParticleSystem");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Pixy_FxEngine_playEffect01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: highlight of class  Pixy::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_FxEngine_highlight00
static int tolua_Elementum_Pixy_FxEngine_highlight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::FxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::FxEngine* self = (Pixy::FxEngine*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Renderable* tolua_var_6 = ((Pixy::Renderable*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'highlight'",NULL);
#endif
  {
   self->highlight(tolua_var_6);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'highlight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dehighlight of class  Pixy::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_FxEngine_dehighlight00
static int tolua_Elementum_Pixy_FxEngine_dehighlight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::FxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::FxEngine* self = (Pixy::FxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dehighlight'",NULL);
#endif
  {
   self->dehighlight();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dehighlight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unloadAllEffects of class  Pixy::FxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_FxEngine_unloadAllEffects00
static int tolua_Elementum_Pixy_FxEngine_unloadAllEffects00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::FxEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::FxEngine* self = (Pixy::FxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unloadAllEffects'",NULL);
#endif
  {
   self->unloadAllEffects();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unloadAllEffects'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __Pixy of class  Pixy::FxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Pixy__FxEngine___Pixy__EventListener__
static int tolua_get_Pixy__FxEngine___Pixy__EventListener__(lua_State* tolua_S)
{
  Pixy::FxEngine* self = (Pixy::FxEngine*)  tolua_tousertype(tolua_S,1,0);
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

/* method: changeState of class  Pixy::GameManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GameManager_changeState00
static int tolua_Elementum_Pixy_GameManager_changeState00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeState'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GameManager_getSingleton00
static int tolua_Elementum_Pixy_GameManager_getSingleton00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GameManager_requestShutdown00
static int tolua_Elementum_Pixy_GameManager_requestShutdown00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'requestShutdown'",NULL);
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

/* method: getKeyboard of class  Pixy::InputManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_InputManager_getKeyboard00
static int tolua_Elementum_Pixy_InputManager_getKeyboard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::InputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::InputManager* self = (Pixy::InputManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getKeyboard'",NULL);
#endif
  {
   OIS::Keyboard* tolua_ret = (OIS::Keyboard*)  self->getKeyboard();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OIS::Keyboard");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getKeyboard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingletonPtr of class  Pixy::InputManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_InputManager_getSingletonPtr00
static int tolua_Elementum_Pixy_InputManager_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::InputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::InputManager* tolua_ret = (Pixy::InputManager*)  Pixy::InputManager::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::InputManager");
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

/* method: changeState of class  Pixy::GameState */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GameState_changeState00
static int tolua_Elementum_Pixy_GameState_changeState00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeState'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GameState_requestShutdown00
static int tolua_Elementum_Pixy_GameState_requestShutdown00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'requestShutdown'",NULL);
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

/* method: isCurrentState of class  Pixy::GameState */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GameState_isCurrentState00
static int tolua_Elementum_Pixy_GameState_isCurrentState00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isCurrentState'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isCurrentState();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isCurrentState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingleton of class  Pixy::Intro */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Intro_getSingleton00
static int tolua_Elementum_Pixy_Intro_getSingleton00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Intro_getSingletonPtr00
static int tolua_Elementum_Pixy_Intro_getSingletonPtr00(lua_State* tolua_S)
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

/* method: getPuppetName of class  Pixy::Intro */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Intro_getPuppetName00
static int tolua_Elementum_Pixy_Intro_getPuppetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Intro",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Intro* self = (const Pixy::Intro*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPuppetName'",NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getPuppetName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPuppetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPuppetName of class  Pixy::Intro */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Intro_setPuppetName00
static int tolua_Elementum_Pixy_Intro_setPuppetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Intro",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Intro* self = (Pixy::Intro*)  tolua_tousertype(tolua_S,1,0);
  std::string inName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPuppetName'",NULL);
#endif
  {
   self->setPuppetName(inName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPuppetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingletonPtr of class  Pixy::Lobby */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Lobby_getSingletonPtr00
static int tolua_Elementum_Pixy_Lobby_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::Lobby",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::Lobby* tolua_ret = (Pixy::Lobby*)  Pixy::Lobby::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Lobby");
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Combat_getSingleton00
static int tolua_Elementum_Pixy_Combat_getSingleton00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Combat_getSingletonPtr00
static int tolua_Elementum_Pixy_Combat_getSingletonPtr00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Combat_getPuppets00
static int tolua_Elementum_Pixy_Combat_getPuppets00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPuppets'",NULL);
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

/* method: getEnemy of class  Pixy::Combat */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Combat_getEnemy00
static int tolua_Elementum_Pixy_Combat_getEnemy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Combat",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Combat* self = (Pixy::Combat*)  tolua_tousertype(tolua_S,1,0);
  int inUID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEnemy'",NULL);
#endif
  {
   Pixy::CPuppet* tolua_ret = (Pixy::CPuppet*)  self->getEnemy(inUID);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::CPuppet");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEnemy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPuppet of class  Pixy::Combat */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Combat_getPuppet00
static int tolua_Elementum_Pixy_Combat_getPuppet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Combat",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Combat* self = (Pixy::Combat*)  tolua_tousertype(tolua_S,1,0);
  int inUID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPuppet'",NULL);
#endif
  {
   Pixy::CPuppet* tolua_ret = (Pixy::CPuppet*)  self->getPuppet(inUID);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::CPuppet");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPuppet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: __setIsDebugging of class  Pixy::Combat */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Combat_setIsDebugging00
static int tolua_Elementum_Pixy_Combat_setIsDebugging00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::Combat",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::Combat* self = (Pixy::Combat*)  tolua_tousertype(tolua_S,1,0);
  bool setting = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '__setIsDebugging'",NULL);
#endif
  {
   self->__setIsDebugging(setting);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIsDebugging'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: __isDebugging of class  Pixy::Combat */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Combat_isDebugging00
static int tolua_Elementum_Pixy_Combat_isDebugging00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::Combat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::Combat* self = (const Pixy::Combat*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '__isDebugging'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->__isDebugging();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDebugging'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Pixy::UIEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_UIEngine_delete00
static int tolua_Elementum_Pixy_UIEngine_delete00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_UIEngine_getSingletonPtr00
static int tolua_Elementum_Pixy_UIEngine_getSingletonPtr00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_UIEngine_setup00
static int tolua_Elementum_Pixy_UIEngine_setup00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setup'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_UIEngine_update00
static int tolua_Elementum_Pixy_UIEngine_update00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_UIEngine_cleanup00
static int tolua_Elementum_Pixy_UIEngine_cleanup00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cleanup'",NULL);
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

/* method: setMargin of class  Pixy::UIEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_UIEngine_setMargin00
static int tolua_Elementum_Pixy_UIEngine_setMargin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::UIEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CEGUI::Window",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CEGUI::UBox",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::UIEngine* self = (Pixy::UIEngine*)  tolua_tousertype(tolua_S,1,0);
  CEGUI::Window* tolua_var_7 = ((CEGUI::Window*)  tolua_tousertype(tolua_S,2,0));
  CEGUI::UBox tolua_var_8 = *((CEGUI::UBox*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMargin'",NULL);
#endif
  {
   self->setMargin(tolua_var_7,tolua_var_8);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMargin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: connectAnimation of class  Pixy::UIEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_UIEngine_connectAnimation00
static int tolua_Elementum_Pixy_UIEngine_connectAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::UIEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CEGUI::Window",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::UIEngine* self = (Pixy::UIEngine*)  tolua_tousertype(tolua_S,1,0);
  CEGUI::Window* tolua_var_9 = ((CEGUI::Window*)  tolua_tousertype(tolua_S,2,0));
  std::string tolua_var_10 = ((std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'connectAnimation'",NULL);
#endif
  {
   self->connectAnimation(tolua_var_9,tolua_var_10);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'connectAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: refreshTooltipSize of class  Pixy::UIEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_UIEngine_refreshTooltipSize00
static int tolua_Elementum_Pixy_UIEngine_refreshTooltipSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::UIEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CEGUI::Window",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Pixy::CSpell",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::UIEngine* self = (Pixy::UIEngine*)  tolua_tousertype(tolua_S,1,0);
  CEGUI::Window* inWindow = ((CEGUI::Window*)  tolua_tousertype(tolua_S,2,0));
  Pixy::CSpell* inSpell = ((Pixy::CSpell*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'refreshTooltipSize'",NULL);
#endif
  {
   self->refreshTooltipSize(inWindow,inSpell);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'refreshTooltipSize'.",&tolua_err);
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

/* get function: mPuppetPos of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Elementum_Pixy_GfxEngine_mPuppetPos
static int tolua_get_Elementum_Pixy_GfxEngine_mPuppetPos(lua_State* tolua_S)
{
 int tolua_index;
  Pixy::GfxEngine* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (Pixy::GfxEngine*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=2)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->mPuppetPos[tolua_index],"Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mPuppetPos of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_set_Elementum_Pixy_GfxEngine_mPuppetPos
static int tolua_set_Elementum_Pixy_GfxEngine_mPuppetPos(lua_State* tolua_S)
{
 int tolua_index;
  Pixy::GfxEngine* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (Pixy::GfxEngine*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=2)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->mPuppetPos[tolua_index] = *((Ogre::Vector3*)  tolua_tousertype(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mPuppetScale of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Pixy__GfxEngine_mPuppetScale
static int tolua_get_Pixy__GfxEngine_mPuppetScale(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mPuppetScale'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mPuppetScale,"Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mPuppetScale of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_set_Pixy__GfxEngine_mPuppetScale
static int tolua_set_Pixy__GfxEngine_mPuppetScale(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mPuppetScale'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mPuppetScale = *((Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mUnitScale of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Pixy__GfxEngine_mUnitScale
static int tolua_get_Pixy__GfxEngine_mUnitScale(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mUnitScale'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mUnitScale,"Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mUnitScale of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_set_Pixy__GfxEngine_mUnitScale
static int tolua_set_Pixy__GfxEngine_mUnitScale(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mUnitScale'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mUnitScale = *((Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mMTOFontColor of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Pixy__GfxEngine_mMTOFontColor
static int tolua_get_Pixy__GfxEngine_mMTOFontColor(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOFontColor'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mMTOFontColor,"Ogre::ColourValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mMTOFontColor of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_set_Pixy__GfxEngine_mMTOFontColor
static int tolua_set_Pixy__GfxEngine_mMTOFontColor(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOFontColor'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::ColourValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mMTOFontColor = *((Ogre::ColourValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mMTOFontName of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Pixy__GfxEngine_mMTOFontName
static int tolua_get_Pixy__GfxEngine_mMTOFontName(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOFontName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->mMTOFontName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mMTOFontName of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_set_Pixy__GfxEngine_mMTOFontName
static int tolua_set_Pixy__GfxEngine_mMTOFontName(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOFontName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mMTOFontName = ((Ogre::String)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mMTOFontSize of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Pixy__GfxEngine_mMTOFontSize
static int tolua_get_Pixy__GfxEngine_mMTOFontSize(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOFontSize'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mMTOFontSize);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mMTOFontSize of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_set_Pixy__GfxEngine_mMTOFontSize
static int tolua_set_Pixy__GfxEngine_mMTOFontSize(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOFontSize'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mMTOFontSize = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mMTOMaterialName of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Pixy__GfxEngine_mMTOMaterialName
static int tolua_get_Pixy__GfxEngine_mMTOMaterialName(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOMaterialName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->mMTOMaterialName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mMTOMaterialName of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_set_Pixy__GfxEngine_mMTOMaterialName
static int tolua_set_Pixy__GfxEngine_mMTOMaterialName(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMTOMaterialName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mMTOMaterialName = ((Ogre::String)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mUnitMargin of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Pixy__GfxEngine_mUnitMargin
static int tolua_get_Pixy__GfxEngine_mUnitMargin(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mUnitMargin'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mUnitMargin,"Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mUnitMargin of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_set_Pixy__GfxEngine_mUnitMargin
static int tolua_set_Pixy__GfxEngine_mUnitMargin(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mUnitMargin'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mUnitMargin = *((Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mPuppetMargin of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Pixy__GfxEngine_mPuppetMargin
static int tolua_get_Pixy__GfxEngine_mPuppetMargin(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mPuppetMargin'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mPuppetMargin,"Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mPuppetMargin of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_set_Pixy__GfxEngine_mPuppetMargin
static int tolua_set_Pixy__GfxEngine_mPuppetMargin(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mPuppetMargin'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mPuppetMargin = *((Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mCameraYawPitchDist of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Pixy__GfxEngine_mCameraYawPitchDist
static int tolua_get_Pixy__GfxEngine_mCameraYawPitchDist(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mCameraYawPitchDist'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mCameraYawPitchDist,"Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mCameraYawPitchDist of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_set_Pixy__GfxEngine_mCameraYawPitchDist
static int tolua_set_Pixy__GfxEngine_mCameraYawPitchDist(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mCameraYawPitchDist'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mCameraYawPitchDist = *((Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mPackSpacing of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_get_Pixy__GfxEngine_mPackSpacing
static int tolua_get_Pixy__GfxEngine_mPackSpacing(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mPackSpacing'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mPackSpacing);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mPackSpacing of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_set_Pixy__GfxEngine_mPackSpacing
static int tolua_set_Pixy__GfxEngine_mPackSpacing(lua_State* tolua_S)
{
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mPackSpacing'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mPackSpacing = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_delete00
static int tolua_Elementum_Pixy_GfxEngine_delete00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_getSingletonPtr00
static int tolua_Elementum_Pixy_GfxEngine_getSingletonPtr00(lua_State* tolua_S)
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

/* method: disableMouseCaptureOverUIElement of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_disableMouseCaptureOverUIElement00
static int tolua_Elementum_Pixy_GfxEngine_disableMouseCaptureOverUIElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  std::string inElementName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disableMouseCaptureOverUIElement'",NULL);
#endif
  {
   self->disableMouseCaptureOverUIElement(inElementName);
   tolua_pushcppstring(tolua_S,(const char*)inElementName);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'disableMouseCaptureOverUIElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enableMouseCaptureOverUIElement of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_enableMouseCaptureOverUIElement00
static int tolua_Elementum_Pixy_GfxEngine_enableMouseCaptureOverUIElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  std::string inElementName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enableMouseCaptureOverUIElement'",NULL);
#endif
  {
   self->enableMouseCaptureOverUIElement(inElementName);
   tolua_pushcppstring(tolua_S,(const char*)inElementName);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enableMouseCaptureOverUIElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setupMovableTextOverlays of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_setupMovableTextOverlays00
static int tolua_Elementum_Pixy_GfxEngine_setupMovableTextOverlays00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupMovableTextOverlays'",NULL);
#endif
  {
   self->setupMovableTextOverlays();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setupMovableTextOverlays'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachToScene of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_attachToScene00
static int tolua_Elementum_Pixy_GfxEngine_attachToScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Renderable* inEntity = ((Pixy::Renderable*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachToScene'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->attachToScene(inEntity);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_detachFromScene00
static int tolua_Elementum_Pixy_GfxEngine_detachFromScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Pixy::Renderable* inEntity = ((Pixy::Renderable*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detachFromScene'",NULL);
#endif
  {
   self->detachFromScene(inEntity);
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

/* method: getSelected of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_getSelected00
static int tolua_Elementum_Pixy_GfxEngine_getSelected00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSelected'",NULL);
#endif
  {
   Pixy::Renderable* tolua_ret = (Pixy::Renderable*)  self->getSelected();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::Renderable");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCamera of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_getCamera00
static int tolua_Elementum_Pixy_GfxEngine_getCamera00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCamera'",NULL);
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

/* method: getCameraMan of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_getCameraMan00
static int tolua_Elementum_Pixy_GfxEngine_getCameraMan00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCameraMan'",NULL);
#endif
  {
   OgreBites::SdkCameraMan* tolua_ret = (OgreBites::SdkCameraMan*)  self->getCameraMan();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OgreBites::SdkCameraMan");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCameraMan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRoot of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_getRoot00
static int tolua_Elementum_Pixy_GfxEngine_getRoot00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRoot'",NULL);
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

/* method: getSceneMgr of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_getSceneMgr00
static int tolua_Elementum_Pixy_GfxEngine_getSceneMgr00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneMgr'",NULL);
#endif
  {
   Ogre::SceneManager* tolua_ret = (Ogre::SceneManager*)  self->getSceneMgr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSceneMgr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewport of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_getViewport00
static int tolua_Elementum_Pixy_GfxEngine_getViewport00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewport'",NULL);
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

/* method: getWindow of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_getWindow00
static int tolua_Elementum_Pixy_GfxEngine_getWindow00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWindow'",NULL);
#endif
  {
   Ogre::RenderWindow* tolua_ret = (Ogre::RenderWindow*)  self->getWindow();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::RenderWindow");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setupSceneManager of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_setupSceneManager00
static int tolua_Elementum_Pixy_GfxEngine_setupSceneManager00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupSceneManager'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_setupViewports00
static int tolua_Elementum_Pixy_GfxEngine_setupViewports00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupViewports'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_setupCamera00
static int tolua_Elementum_Pixy_GfxEngine_setupCamera00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupCamera'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_setupTerrain00
static int tolua_Elementum_Pixy_GfxEngine_setupTerrain00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupTerrain'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_setupLights00
static int tolua_Elementum_Pixy_GfxEngine_setupLights00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupLights'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_setupNodes00
static int tolua_Elementum_Pixy_GfxEngine_setupNodes00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupNodes'",NULL);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_setupWaypoints00
static int tolua_Elementum_Pixy_GfxEngine_setupWaypoints00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setupWaypoints'",NULL);
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

/* method: changeOwnership of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_changeOwnership00
static int tolua_Elementum_Pixy_GfxEngine_changeOwnership00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::CUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Pixy::CUnit* inUnit = ((Pixy::CUnit*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeOwnership'",NULL);
#endif
  {
   self->changeOwnership(inUnit);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeOwnership'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadScene of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_loadScene00
static int tolua_Elementum_Pixy_GfxEngine_loadScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  std::string inOgreMaxScene = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadScene'",NULL);
#endif
  {
   OgreMax::OgreMaxScene* tolua_ret = (OgreMax::OgreMaxScene*)  self->loadScene(inOgreMaxScene);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OgreMax::OgreMaxScene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unloadScene of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_unloadScene00
static int tolua_Elementum_Pixy_GfxEngine_unloadScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"OgreMax::OgreMaxScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  OgreMax::OgreMaxScene* inScene = ((OgreMax::OgreMaxScene*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unloadScene'",NULL);
#endif
  {
   self->unloadScene(inScene);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unloadScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enableCompositorEffect of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_enableCompositorEffect00
static int tolua_Elementum_Pixy_GfxEngine_enableCompositorEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  std::string inEffect = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enableCompositorEffect'",NULL);
#endif
  {
   self->enableCompositorEffect(inEffect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enableCompositorEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadDotScene of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_loadDotScene00
static int tolua_Elementum_Pixy_GfxEngine_loadDotScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  std::string inFile = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string inName = ((std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadDotScene'",NULL);
#endif
  {
   self->loadDotScene(inFile,inName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadDotScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createSphere of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_createSphere00
static int tolua_Elementum_Pixy_GfxEngine_createSphere00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  const std::string strName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const float r = ((const float)  tolua_tonumber(tolua_S,3,0));
  const int nRings = ((const int)  tolua_tonumber(tolua_S,4,16));
  const int nSegments = ((const int)  tolua_tonumber(tolua_S,5,16));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createSphere'",NULL);
#endif
  {
   self->createSphere(strName,r,nRings,nSegments);
   tolua_pushcppstring(tolua_S,(const char*)strName);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createSphere'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScreenCoords of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_getScreenCoords00
static int tolua_Elementum_Pixy_GfxEngine_getScreenCoords00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Ogre::MovableObject* inObject = ((Ogre::MovableObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScreenCoords'",NULL);
#endif
  {
   Ogre::Vector2 tolua_ret = (Ogre::Vector2)  self->getScreenCoords(inObject);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Ogre::Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ogre::Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScreenCoords'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setYawPitchDist of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_setYawPitchDist00
static int tolua_Elementum_Pixy_GfxEngine_setYawPitchDist00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Vector3 inVec = *((Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setYawPitchDist'",NULL);
#endif
  {
   self->setYawPitchDist(inVec);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setYawPitchDist'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: trackNode of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_trackNode00
static int tolua_Elementum_Pixy_GfxEngine_trackNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Ogre::SceneNode* inNode = ((Ogre::SceneNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'trackNode'",NULL);
#endif
  {
   self->trackNode(inNode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'trackNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: _setUserAny of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine__setUserAny00
static int tolua_Elementum_Pixy_GfxEngine__setUserAny00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Ogre::MovableObject* inObj = ((Ogre::MovableObject*)  tolua_tousertype(tolua_S,2,0));
  void* any = ((void*)  tolua_touserdata(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '_setUserAny'",NULL);
#endif
  {
   self->_setUserAny(inObj,any);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '_setUserAny'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachRTT of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_attachRTT00
static int tolua_Elementum_Pixy_GfxEngine_attachRTT00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::OgreRTT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Pixy::OgreRTT* tolua_var_11 = ((Pixy::OgreRTT*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachRTT'",NULL);
#endif
  {
   self->attachRTT(tolua_var_11);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachRTT'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: detachRTT of class  Pixy::GfxEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_GfxEngine_detachRTT00
static int tolua_Elementum_Pixy_GfxEngine_detachRTT00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::GfxEngine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Pixy::OgreRTT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::GfxEngine* self = (Pixy::GfxEngine*)  tolua_tousertype(tolua_S,1,0);
  Pixy::OgreRTT* tolua_var_12 = ((Pixy::OgreRTT*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detachRTT'",NULL);
#endif
  {
   self->detachRTT(tolua_var_12);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'detachRTT'.",&tolua_err);
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
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_Log00
static int tolua_Elementum_Pixy_Log00(lua_State* tolua_S)
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

/* method: getSingleton of class  Pixy::NetworkManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_NetworkManager_getSingleton00
static int tolua_Elementum_Pixy_NetworkManager_getSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::NetworkManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::NetworkManager& tolua_ret = (Pixy::NetworkManager&)  Pixy::NetworkManager::getSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Pixy::NetworkManager");
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

/* method: connect of class  Pixy::NetworkManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_NetworkManager_connect00
static int tolua_Elementum_Pixy_NetworkManager_connect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::NetworkManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::NetworkManager* self = (Pixy::NetworkManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'connect'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->connect();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'connect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: disconnect of class  Pixy::NetworkManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_NetworkManager_disconnect00
static int tolua_Elementum_Pixy_NetworkManager_disconnect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::NetworkManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::NetworkManager* self = (Pixy::NetworkManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disconnect'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->disconnect();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'disconnect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send of class  Pixy::NetworkManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_NetworkManager_send00
static int tolua_Elementum_Pixy_NetworkManager_send00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::NetworkManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Pixy::Event",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::NetworkManager* self = (Pixy::NetworkManager*)  tolua_tousertype(tolua_S,1,0);
  const Pixy::Event* tolua_var_13 = ((const Pixy::Event*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send'",NULL);
#endif
  {
   self->send(*tolua_var_13);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isConnected of class  Pixy::NetworkManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_NetworkManager_isConnected00
static int tolua_Elementum_Pixy_NetworkManager_isConnected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::NetworkManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::NetworkManager* self = (const Pixy::NetworkManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isConnected'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isConnected();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isConnected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingletonPtr of class  Pixy::ScriptEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_ScriptEngine_getSingletonPtr00
static int tolua_Elementum_Pixy_ScriptEngine_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::ScriptEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::ScriptEngine* tolua_ret = (Pixy::ScriptEngine*)  Pixy::ScriptEngine::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::ScriptEngine");
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

/* method: getScriptPathPrefix of class  Pixy::ScriptEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_ScriptEngine_getScriptPathPrefix00
static int tolua_Elementum_Pixy_ScriptEngine_getScriptPathPrefix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::ScriptEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::ScriptEngine* self = (const Pixy::ScriptEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScriptPathPrefix'",NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getScriptPathPrefix();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScriptPathPrefix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getModulePathPrefix of class  Pixy::ScriptEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_ScriptEngine_getModulePathPrefix00
static int tolua_Elementum_Pixy_ScriptEngine_getModulePathPrefix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::ScriptEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::ScriptEngine* self = (const Pixy::ScriptEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getModulePathPrefix'",NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getModulePathPrefix();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getModulePathPrefix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: callMeAfter of class  Pixy::ScriptEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_ScriptEngine_callMeAfter00
static int tolua_Elementum_Pixy_ScriptEngine_callMeAfter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::ScriptEngine",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::ScriptEngine* self = (Pixy::ScriptEngine*)  tolua_tousertype(tolua_S,1,0);
  int inSeconds = ((int)  tolua_tonumber(tolua_S,2,0));
  std::string inFunc = ((std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'callMeAfter'",NULL);
#endif
  {
   self->callMeAfter(inSeconds,inFunc);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'callMeAfter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: _passGameData of class  Pixy::ScriptEngine */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_ScriptEngine__passGameData00
static int tolua_Elementum_Pixy_ScriptEngine__passGameData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::ScriptEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::ScriptEngine* self = (Pixy::ScriptEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '_passGameData'",NULL);
#endif
  {
   int tolua_ret = (int)  self->_passGameData();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '_passGameData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __Pixy of class  Pixy::ScriptEngine */
#ifndef TOLUA_DISABLE_tolua_get_Pixy__ScriptEngine___Pixy__EventListener__
static int tolua_get_Pixy__ScriptEngine___Pixy__EventListener__(lua_State* tolua_S)
{
  Pixy::ScriptEngine* self = (Pixy::ScriptEngine*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  Pixy::LuaExporter<CUnitVec> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnitVecExporter_new00
static int tolua_Elementum_Pixy_CUnitVecExporter_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::LuaExporter<CUnitVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::LuaExporter<CUnitVec>* tolua_ret = (Pixy::LuaExporter<CUnitVec>*)  Mtolua_new((Pixy::LuaExporter<CUnitVec>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::LuaExporter<CUnitVec>");
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

/* method: new_local of class  Pixy::LuaExporter<CUnitVec> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnitVecExporter_new00_local
static int tolua_Elementum_Pixy_CUnitVecExporter_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::LuaExporter<CUnitVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::LuaExporter<CUnitVec>* tolua_ret = (Pixy::LuaExporter<CUnitVec>*)  Mtolua_new((Pixy::LuaExporter<CUnitVec>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::LuaExporter<CUnitVec>");
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

/* method: delete of class  Pixy::LuaExporter<CUnitVec> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnitVecExporter_delete00
static int tolua_Elementum_Pixy_CUnitVecExporter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::LuaExporter<CUnitVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::LuaExporter<CUnitVec>* self = (Pixy::LuaExporter<CUnitVec>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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

/* method: __export of class  Pixy::LuaExporter<CUnitVec> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnitVecExporter_export00
static int tolua_Elementum_Pixy_CUnitVecExporter_export00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::LuaExporter<CUnitVec>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::LuaExporter<CUnitVec>* self = (Pixy::LuaExporter<CUnitVec>*)  tolua_tousertype(tolua_S,1,0);
  CUnitVec const* container = ((CUnitVec const*)  tolua_tousertype(tolua_S,2,0));
  const char* data_type = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* out_table = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '__export'",NULL);
#endif
  {
   self->__export(*container,data_type,out_table);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'export'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Pixy::LuaExporter<CSpellVec> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpellVecExporter_new00
static int tolua_Elementum_Pixy_CSpellVecExporter_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::LuaExporter<CSpellVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::LuaExporter<CSpellVec>* tolua_ret = (Pixy::LuaExporter<CSpellVec>*)  Mtolua_new((Pixy::LuaExporter<CSpellVec>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::LuaExporter<CSpellVec>");
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

/* method: new_local of class  Pixy::LuaExporter<CSpellVec> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpellVecExporter_new00_local
static int tolua_Elementum_Pixy_CSpellVecExporter_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::LuaExporter<CSpellVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::LuaExporter<CSpellVec>* tolua_ret = (Pixy::LuaExporter<CSpellVec>*)  Mtolua_new((Pixy::LuaExporter<CSpellVec>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::LuaExporter<CSpellVec>");
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

/* method: delete of class  Pixy::LuaExporter<CSpellVec> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpellVecExporter_delete00
static int tolua_Elementum_Pixy_CSpellVecExporter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::LuaExporter<CSpellVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::LuaExporter<CSpellVec>* self = (Pixy::LuaExporter<CSpellVec>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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

/* method: __export of class  Pixy::LuaExporter<CSpellVec> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpellVecExporter_export00
static int tolua_Elementum_Pixy_CSpellVecExporter_export00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::LuaExporter<CSpellVec>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::LuaExporter<CSpellVec>* self = (Pixy::LuaExporter<CSpellVec>*)  tolua_tousertype(tolua_S,1,0);
  CSpellVec const* container = ((CSpellVec const*)  tolua_tousertype(tolua_S,2,0));
  const char* data_type = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* out_table = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '__export'",NULL);
#endif
  {
   self->__export(*container,data_type,out_table);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'export'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Pixy::LuaExporter<CPuppetVec> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppetVecExporter_new00
static int tolua_Elementum_Pixy_CPuppetVecExporter_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::LuaExporter<CPuppetVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::LuaExporter<CPuppetVec>* tolua_ret = (Pixy::LuaExporter<CPuppetVec>*)  Mtolua_new((Pixy::LuaExporter<CPuppetVec>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::LuaExporter<CPuppetVec>");
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

/* method: new_local of class  Pixy::LuaExporter<CPuppetVec> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppetVecExporter_new00_local
static int tolua_Elementum_Pixy_CPuppetVecExporter_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::LuaExporter<CPuppetVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::LuaExporter<CPuppetVec>* tolua_ret = (Pixy::LuaExporter<CPuppetVec>*)  Mtolua_new((Pixy::LuaExporter<CPuppetVec>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::LuaExporter<CPuppetVec>");
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

/* method: delete of class  Pixy::LuaExporter<CPuppetVec> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppetVecExporter_delete00
static int tolua_Elementum_Pixy_CPuppetVecExporter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::LuaExporter<CPuppetVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::LuaExporter<CPuppetVec>* self = (Pixy::LuaExporter<CPuppetVec>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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

/* method: __export of class  Pixy::LuaExporter<CPuppetVec> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppetVecExporter_export00
static int tolua_Elementum_Pixy_CPuppetVecExporter_export00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::LuaExporter<CPuppetVec>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::LuaExporter<CPuppetVec>* self = (Pixy::LuaExporter<CPuppetVec>*)  tolua_tousertype(tolua_S,1,0);
  CPuppetVec const* container = ((CPuppetVec const*)  tolua_tousertype(tolua_S,2,0));
  const char* data_type = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* out_table = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '__export'",NULL);
#endif
  {
   self->__export(*container,data_type,out_table);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'export'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Pixy::LuaExporter<CUnitList> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnitListExporter_new00
static int tolua_Elementum_Pixy_CUnitListExporter_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::LuaExporter<CUnitList>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::LuaExporter<CUnitList>* tolua_ret = (Pixy::LuaExporter<CUnitList>*)  Mtolua_new((Pixy::LuaExporter<CUnitList>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::LuaExporter<CUnitList>");
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

/* method: new_local of class  Pixy::LuaExporter<CUnitList> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnitListExporter_new00_local
static int tolua_Elementum_Pixy_CUnitListExporter_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::LuaExporter<CUnitList>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::LuaExporter<CUnitList>* tolua_ret = (Pixy::LuaExporter<CUnitList>*)  Mtolua_new((Pixy::LuaExporter<CUnitList>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::LuaExporter<CUnitList>");
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

/* method: delete of class  Pixy::LuaExporter<CUnitList> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnitListExporter_delete00
static int tolua_Elementum_Pixy_CUnitListExporter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::LuaExporter<CUnitList>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::LuaExporter<CUnitList>* self = (Pixy::LuaExporter<CUnitList>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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

/* method: __export of class  Pixy::LuaExporter<CUnitList> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CUnitListExporter_export00
static int tolua_Elementum_Pixy_CUnitListExporter_export00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::LuaExporter<CUnitList>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::LuaExporter<CUnitList>* self = (Pixy::LuaExporter<CUnitList>*)  tolua_tousertype(tolua_S,1,0);
  CUnitList const* container = ((CUnitList const*)  tolua_tousertype(tolua_S,2,0));
  const char* data_type = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* out_table = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '__export'",NULL);
#endif
  {
   self->__export(*container,data_type,out_table);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'export'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Pixy::LuaExporter<CSpellList> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpellListExporter_new00
static int tolua_Elementum_Pixy_CSpellListExporter_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::LuaExporter<CSpellList>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::LuaExporter<CSpellList>* tolua_ret = (Pixy::LuaExporter<CSpellList>*)  Mtolua_new((Pixy::LuaExporter<CSpellList>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::LuaExporter<CSpellList>");
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

/* method: new_local of class  Pixy::LuaExporter<CSpellList> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpellListExporter_new00_local
static int tolua_Elementum_Pixy_CSpellListExporter_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::LuaExporter<CSpellList>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::LuaExporter<CSpellList>* tolua_ret = (Pixy::LuaExporter<CSpellList>*)  Mtolua_new((Pixy::LuaExporter<CSpellList>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::LuaExporter<CSpellList>");
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

/* method: delete of class  Pixy::LuaExporter<CSpellList> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpellListExporter_delete00
static int tolua_Elementum_Pixy_CSpellListExporter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::LuaExporter<CSpellList>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::LuaExporter<CSpellList>* self = (Pixy::LuaExporter<CSpellList>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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

/* method: __export of class  Pixy::LuaExporter<CSpellList> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CSpellListExporter_export00
static int tolua_Elementum_Pixy_CSpellListExporter_export00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::LuaExporter<CSpellList>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::LuaExporter<CSpellList>* self = (Pixy::LuaExporter<CSpellList>*)  tolua_tousertype(tolua_S,1,0);
  CSpellList const* container = ((CSpellList const*)  tolua_tousertype(tolua_S,2,0));
  const char* data_type = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* out_table = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '__export'",NULL);
#endif
  {
   self->__export(*container,data_type,out_table);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'export'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Pixy::LuaExporter<CPuppetList> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppetListExporter_new00
static int tolua_Elementum_Pixy_CPuppetListExporter_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::LuaExporter<CPuppetList>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::LuaExporter<CPuppetList>* tolua_ret = (Pixy::LuaExporter<CPuppetList>*)  Mtolua_new((Pixy::LuaExporter<CPuppetList>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::LuaExporter<CPuppetList>");
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

/* method: new_local of class  Pixy::LuaExporter<CPuppetList> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppetListExporter_new00_local
static int tolua_Elementum_Pixy_CPuppetListExporter_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::LuaExporter<CPuppetList>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::LuaExporter<CPuppetList>* tolua_ret = (Pixy::LuaExporter<CPuppetList>*)  Mtolua_new((Pixy::LuaExporter<CPuppetList>)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::LuaExporter<CPuppetList>");
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

/* method: delete of class  Pixy::LuaExporter<CPuppetList> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppetListExporter_delete00
static int tolua_Elementum_Pixy_CPuppetListExporter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::LuaExporter<CPuppetList>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::LuaExporter<CPuppetList>* self = (Pixy::LuaExporter<CPuppetList>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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

/* method: __export of class  Pixy::LuaExporter<CPuppetList> */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_CPuppetListExporter_export00
static int tolua_Elementum_Pixy_CPuppetListExporter_export00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::LuaExporter<CPuppetList>",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::LuaExporter<CPuppetList>* self = (Pixy::LuaExporter<CPuppetList>*)  tolua_tousertype(tolua_S,1,0);
  CPuppetList const* container = ((CPuppetList const*)  tolua_tousertype(tolua_S,2,0));
  const char* data_type = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* out_table = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '__export'",NULL);
#endif
  {
   self->__export(*container,data_type,out_table);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'export'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Pixy::OgreRTT */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_OgreRTT_new00
static int tolua_Elementum_Pixy_OgreRTT_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::OgreRTT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::OgreRTT* tolua_ret = (Pixy::OgreRTT*)  Mtolua_new((Pixy::OgreRTT)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::OgreRTT");
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

/* method: new_local of class  Pixy::OgreRTT */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_OgreRTT_new00_local
static int tolua_Elementum_Pixy_OgreRTT_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Pixy::OgreRTT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Pixy::OgreRTT* tolua_ret = (Pixy::OgreRTT*)  Mtolua_new((Pixy::OgreRTT)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Pixy::OgreRTT");
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

/* method: delete of class  Pixy::OgreRTT */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_OgreRTT_delete00
static int tolua_Elementum_Pixy_OgreRTT_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::OgreRTT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::OgreRTT* self = (Pixy::OgreRTT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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

/* method: setup of class  Pixy::OgreRTT */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_OgreRTT_setup00
static int tolua_Elementum_Pixy_OgreRTT_setup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::OgreRTT",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::OgreRTT* self = (Pixy::OgreRTT*)  tolua_tousertype(tolua_S,1,0);
  Ogre::SceneManager* mSceneMgr = ((Ogre::SceneManager*)  tolua_tousertype(tolua_S,2,0));
  Ogre::RenderWindow* inWindow = ((Ogre::RenderWindow*)  tolua_tousertype(tolua_S,3,0));
  Ogre::Camera* inCamera = ((Ogre::Camera*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setup'",NULL);
#endif
  {
   self->setup(mSceneMgr,inWindow,inCamera);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCorners of class  Pixy::OgreRTT */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_OgreRTT_setCorners00
static int tolua_Elementum_Pixy_OgreRTT_setCorners00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::OgreRTT",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::OgreRTT* self = (Pixy::OgreRTT*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Real left = ((Ogre::Real)  tolua_tonumber(tolua_S,2,0));
  Ogre::Real right = ((Ogre::Real)  tolua_tonumber(tolua_S,3,0));
  Ogre::Real top = ((Ogre::Real)  tolua_tonumber(tolua_S,4,0));
  Ogre::Real bot = ((Ogre::Real)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCorners'",NULL);
#endif
  {
   self->setCorners(left,right,top,bot);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCorners'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enable of class  Pixy::OgreRTT */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_OgreRTT_enable00
static int tolua_Elementum_Pixy_OgreRTT_enable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::OgreRTT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::OgreRTT* self = (Pixy::OgreRTT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enable'",NULL);
#endif
  {
   self->enable();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: disable of class  Pixy::OgreRTT */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_OgreRTT_disable00
static int tolua_Elementum_Pixy_OgreRTT_disable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::OgreRTT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::OgreRTT* self = (Pixy::OgreRTT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disable'",NULL);
#endif
  {
   self->disable();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'disable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isEnabled of class  Pixy::OgreRTT */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_OgreRTT_isEnabled00
static int tolua_Elementum_Pixy_OgreRTT_isEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Pixy::OgreRTT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Pixy::OgreRTT* self = (const Pixy::OgreRTT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isEnabled'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Pixy::OgreRTT */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_OgreRTT_hide00
static int tolua_Elementum_Pixy_OgreRTT_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::OgreRTT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::OgreRTT* self = (Pixy::OgreRTT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'",NULL);
#endif
  {
   self->hide();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Pixy::OgreRTT */
#ifndef TOLUA_DISABLE_tolua_Elementum_Pixy_OgreRTT_show00
static int tolua_Elementum_Pixy_OgreRTT_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Pixy::OgreRTT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Pixy::OgreRTT* self = (Pixy::OgreRTT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Ogre::Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Vector2_x
static int tolua_get_Ogre__Vector2_x(lua_State* tolua_S)
{
  Ogre::Vector2* self = (Ogre::Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Ogre::Vector2 */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__Vector2_x
static int tolua_set_Ogre__Vector2_x(lua_State* tolua_S)
{
  Ogre::Vector2* self = (Ogre::Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((  float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  Ogre::Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Vector2_y
static int tolua_get_Ogre__Vector2_y(lua_State* tolua_S)
{
  Ogre::Vector2* self = (Ogre::Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Ogre::Vector2 */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__Vector2_y
static int tolua_set_Ogre__Vector2_y(lua_State* tolua_S)
{
  Ogre::Vector2* self = (Ogre::Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((  float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Vector2_new00
static int tolua_Elementum_Ogre_Vector2_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float fX = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float fY = ((const float)  tolua_tonumber(tolua_S,3,0));
  {
   Ogre::Vector2* tolua_ret = (Ogre::Vector2*)  Mtolua_new((Ogre::Vector2)(fX,fY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Vector2");
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

/* method: new_local of class  Ogre::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Vector2_new00_local
static int tolua_Elementum_Ogre_Vector2_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float fX = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float fY = ((const float)  tolua_tonumber(tolua_S,3,0));
  {
   Ogre::Vector2* tolua_ret = (Ogre::Vector2*)  Mtolua_new((Ogre::Vector2)(fX,fY));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Vector2");
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

/* method: new of class  Ogre::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Vector2_new01
static int tolua_Elementum_Ogre_Vector2_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const float scalar = ((const float)  tolua_tonumber(tolua_S,2,0));
  {
   Ogre::Vector2* tolua_ret = (Ogre::Vector2*)  Mtolua_new((Ogre::Vector2)(scalar));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Vector2");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Vector2_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ogre::Vector2 */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Vector2_new01_local
static int tolua_Elementum_Ogre_Vector2_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const float scalar = ((const float)  tolua_tonumber(tolua_S,2,0));
  {
   Ogre::Vector2* tolua_ret = (Ogre::Vector2*)  Mtolua_new((Ogre::Vector2)(scalar));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Vector2_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Vector3_x
static int tolua_get_Ogre__Vector3_x(lua_State* tolua_S)
{
  Ogre::Vector3* self = (Ogre::Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__Vector3_x
static int tolua_set_Ogre__Vector3_x(lua_State* tolua_S)
{
  Ogre::Vector3* self = (Ogre::Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((  float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Vector3_y
static int tolua_get_Ogre__Vector3_y(lua_State* tolua_S)
{
  Ogre::Vector3* self = (Ogre::Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__Vector3_y
static int tolua_set_Ogre__Vector3_y(lua_State* tolua_S)
{
  Ogre::Vector3* self = (Ogre::Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((  float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: z of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Vector3_z
static int tolua_get_Ogre__Vector3_z(lua_State* tolua_S)
{
  Ogre::Vector3* self = (Ogre::Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__Vector3_z
static int tolua_set_Ogre__Vector3_z(lua_State* tolua_S)
{
  Ogre::Vector3* self = (Ogre::Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((  float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Vector3_ZERO
static int tolua_get_Ogre__Vector3_ZERO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Ogre::Vector3::ZERO,"const Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UNIT_X of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Vector3_UNIT_X
static int tolua_get_Ogre__Vector3_UNIT_X(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Ogre::Vector3::UNIT_X,"const Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UNIT_Y of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Vector3_UNIT_Y
static int tolua_get_Ogre__Vector3_UNIT_Y(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Ogre::Vector3::UNIT_Y,"const Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UNIT_Z of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Vector3_UNIT_Z
static int tolua_get_Ogre__Vector3_UNIT_Z(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Ogre::Vector3::UNIT_Z,"const Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: NEGATIVE_UNIT_X of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Vector3_NEGATIVE_UNIT_X
static int tolua_get_Ogre__Vector3_NEGATIVE_UNIT_X(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Ogre::Vector3::NEGATIVE_UNIT_X,"const Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: NEGATIVE_UNIT_Y of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Vector3_NEGATIVE_UNIT_Y
static int tolua_get_Ogre__Vector3_NEGATIVE_UNIT_Y(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Ogre::Vector3::NEGATIVE_UNIT_Y,"const Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: NEGATIVE_UNIT_Z of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Vector3_NEGATIVE_UNIT_Z
static int tolua_get_Ogre__Vector3_NEGATIVE_UNIT_Z(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Ogre::Vector3::NEGATIVE_UNIT_Z,"const Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UNIT_SCALE of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Vector3_UNIT_SCALE
static int tolua_get_Ogre__Vector3_UNIT_SCALE(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Ogre::Vector3::UNIT_SCALE,"const Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Vector3_new00
static int tolua_Elementum_Ogre_Vector3_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float fX = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float fY = ((const float)  tolua_tonumber(tolua_S,3,0));
  const float fZ = ((const float)  tolua_tonumber(tolua_S,4,0));
  {
   Ogre::Vector3* tolua_ret = (Ogre::Vector3*)  Mtolua_new((Ogre::Vector3)(fX,fY,fZ));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Vector3");
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

/* method: new_local of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Vector3_new00_local
static int tolua_Elementum_Ogre_Vector3_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float fX = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float fY = ((const float)  tolua_tonumber(tolua_S,3,0));
  const float fZ = ((const float)  tolua_tonumber(tolua_S,4,0));
  {
   Ogre::Vector3* tolua_ret = (Ogre::Vector3*)  Mtolua_new((Ogre::Vector3)(fX,fY,fZ));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Vector3");
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

/* method: new of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Vector3_new01
static int tolua_Elementum_Ogre_Vector3_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const float scalar = ((const float)  tolua_tonumber(tolua_S,2,0));
  {
   Ogre::Vector3* tolua_ret = (Ogre::Vector3*)  Mtolua_new((Ogre::Vector3)(scalar));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Vector3");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Vector3_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ogre::Vector3 */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Vector3_new01_local
static int tolua_Elementum_Ogre_Vector3_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const float scalar = ((const float)  tolua_tonumber(tolua_S,2,0));
  {
   Ogre::Vector3* tolua_ret = (Ogre::Vector3*)  Mtolua_new((Ogre::Vector3)(scalar));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Vector3_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::Degree */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Degree_new00
static int tolua_Elementum_Ogre_Degree_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Degree",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float f = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   Ogre::Degree* tolua_ret = (Ogre::Degree*)  Mtolua_new((Ogre::Degree)(f));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Degree");
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

/* method: new_local of class  Ogre::Degree */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Degree_new00_local
static int tolua_Elementum_Ogre_Degree_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Degree",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float f = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   Ogre::Degree* tolua_ret = (Ogre::Degree*)  Mtolua_new((Ogre::Degree)(f));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Degree");
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

/* method: valueDegrees of class  Ogre::Degree */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Degree_valueDegrees00
static int tolua_Elementum_Ogre_Degree_valueDegrees00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Degree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Degree* self = (const Ogre::Degree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'valueDegrees'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->valueDegrees();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'valueDegrees'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: valueRadians of class  Ogre::Degree */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Degree_valueRadians00
static int tolua_Elementum_Ogre_Degree_valueRadians00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Degree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Degree* self = (const Ogre::Degree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'valueRadians'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->valueRadians();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'valueRadians'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: valueAngleUnits of class  Ogre::Degree */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Degree_valueAngleUnits00
static int tolua_Elementum_Ogre_Degree_valueAngleUnits00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Degree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Degree* self = (const Ogre::Degree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'valueAngleUnits'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->valueAngleUnits();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'valueAngleUnits'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::Radian */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Radian_new00
static int tolua_Elementum_Ogre_Radian_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Radian",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
   float r = ((  float)  tolua_tonumber(tolua_S,2,0));
  {
   Ogre::Radian* tolua_ret = (Ogre::Radian*)  Mtolua_new((Ogre::Radian)(r));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Radian");
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

/* method: new_local of class  Ogre::Radian */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Radian_new00_local
static int tolua_Elementum_Ogre_Radian_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Radian",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
   float r = ((  float)  tolua_tonumber(tolua_S,2,0));
  {
   Ogre::Radian* tolua_ret = (Ogre::Radian*)  Mtolua_new((Ogre::Radian)(r));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Radian");
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

/* method: new of class  Ogre::Radian */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Radian_new01
static int tolua_Elementum_Ogre_Radian_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Radian",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Degree",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::Degree* d = ((const Ogre::Degree*)  tolua_tousertype(tolua_S,2,0));
  {
   Ogre::Radian* tolua_ret = (Ogre::Radian*)  Mtolua_new((Ogre::Radian)(*d));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Radian");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Radian_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ogre::Radian */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Radian_new01_local
static int tolua_Elementum_Ogre_Radian_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Radian",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Degree",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::Degree* d = ((const Ogre::Degree*)  tolua_tousertype(tolua_S,2,0));
  {
   Ogre::Radian* tolua_ret = (Ogre::Radian*)  Mtolua_new((Ogre::Radian)(*d));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Radian");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Radian_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: valueDegrees of class  Ogre::Radian */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Radian_valueDegrees00
static int tolua_Elementum_Ogre_Radian_valueDegrees00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Radian",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Radian* self = (const Ogre::Radian*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'valueDegrees'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->valueDegrees();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'valueDegrees'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: valueRadians of class  Ogre::Radian */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Radian_valueRadians00
static int tolua_Elementum_Ogre_Radian_valueRadians00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Radian",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Radian* self = (const Ogre::Radian*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'valueRadians'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->valueRadians();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'valueRadians'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: valueAngleUnits of class  Ogre::Radian */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Radian_valueAngleUnits00
static int tolua_Elementum_Ogre_Radian_valueAngleUnits00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Radian",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Radian* self = (const Ogre::Radian*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'valueAngleUnits'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->valueAngleUnits();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'valueAngleUnits'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::Angle */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Angle_new00
static int tolua_Elementum_Ogre_Angle_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Angle",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
   float angle = ((  float)  tolua_tonumber(tolua_S,2,0));
  {
   Ogre::Angle* tolua_ret = (Ogre::Angle*)  Mtolua_new((Ogre::Angle)(angle));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Angle");
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

/* method: new_local of class  Ogre::Angle */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Angle_new00_local
static int tolua_Elementum_Ogre_Angle_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Angle",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
   float angle = ((  float)  tolua_tonumber(tolua_S,2,0));
  {
   Ogre::Angle* tolua_ret = (Ogre::Angle*)  Mtolua_new((Ogre::Angle)(angle));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Angle");
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

/* method: operatorRadian of class  Ogre::Angle */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Angle__Radian00
static int tolua_Elementum_Ogre_Angle__Radian00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Angle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Angle* self = (const Ogre::Angle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operatorRadian'",NULL);
#endif
  {
   Ogre::Radian tolua_ret = (Ogre::Radian)  self->operator  Ogre::Radian();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Ogre::Radian)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Radian");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ogre::Radian));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Radian");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.Radian'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operatorDegree of class  Ogre::Angle */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Angle__Degree00
static int tolua_Elementum_Ogre_Angle__Degree00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Angle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Angle* self = (const Ogre::Angle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operatorDegree'",NULL);
#endif
  {
   Ogre::Degree tolua_ret = (Ogre::Degree)  self->operator  Ogre::Degree();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Ogre::Degree)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Degree");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ogre::Degree));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Degree");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.Degree'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::Quaternion */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Quaternion_new00
static int tolua_Elementum_Ogre_Quaternion_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Ogre::Quaternion* tolua_ret = (Ogre::Quaternion*)  Mtolua_new((Ogre::Quaternion)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Quaternion");
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

/* method: new_local of class  Ogre::Quaternion */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Quaternion_new00_local
static int tolua_Elementum_Ogre_Quaternion_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Ogre::Quaternion* tolua_ret = (Ogre::Quaternion*)  Mtolua_new((Ogre::Quaternion)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Quaternion");
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

/* method: new of class  Ogre::Quaternion */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Quaternion_new01
static int tolua_Elementum_Ogre_Quaternion_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Quaternion",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
   float fW = ((  float)  tolua_tonumber(tolua_S,2,0));
   float fX = ((  float)  tolua_tonumber(tolua_S,3,0));
   float fY = ((  float)  tolua_tonumber(tolua_S,4,0));
   float fZ = ((  float)  tolua_tonumber(tolua_S,5,0));
  {
   Ogre::Quaternion* tolua_ret = (Ogre::Quaternion*)  Mtolua_new((Ogre::Quaternion)(fW,fX,fY,fZ));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Quaternion");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Quaternion_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ogre::Quaternion */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Quaternion_new01_local
static int tolua_Elementum_Ogre_Quaternion_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Quaternion",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
   float fW = ((  float)  tolua_tonumber(tolua_S,2,0));
   float fX = ((  float)  tolua_tonumber(tolua_S,3,0));
   float fY = ((  float)  tolua_tonumber(tolua_S,4,0));
   float fZ = ((  float)  tolua_tonumber(tolua_S,5,0));
  {
   Ogre::Quaternion* tolua_ret = (Ogre::Quaternion*)  Mtolua_new((Ogre::Quaternion)(fW,fX,fY,fZ));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Quaternion_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::Quaternion */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Quaternion_new02
static int tolua_Elementum_Ogre_Quaternion_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Radian",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::Radian* rfAngle = ((const Ogre::Radian*)  tolua_tousertype(tolua_S,2,0));
  const Ogre::Vector3* rkAxis = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,3,0));
  {
   Ogre::Quaternion* tolua_ret = (Ogre::Quaternion*)  Mtolua_new((Ogre::Quaternion)(*rfAngle,*rkAxis));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Quaternion");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Quaternion_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ogre::Quaternion */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Quaternion_new02_local
static int tolua_Elementum_Ogre_Quaternion_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Radian",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::Radian* rfAngle = ((const Ogre::Radian*)  tolua_tousertype(tolua_S,2,0));
  const Ogre::Vector3* rkAxis = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,3,0));
  {
   Ogre::Quaternion* tolua_ret = (Ogre::Quaternion*)  Mtolua_new((Ogre::Quaternion)(*rfAngle,*rkAxis));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Quaternion_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::Quaternion */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Quaternion_new03
static int tolua_Elementum_Ogre_Quaternion_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::Vector3* xaxis = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Ogre::Vector3* yaxis = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Ogre::Vector3* zaxis = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,4,0));
  {
   Ogre::Quaternion* tolua_ret = (Ogre::Quaternion*)  Mtolua_new((Ogre::Quaternion)(*xaxis,*yaxis,*zaxis));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Quaternion");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Quaternion_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ogre::Quaternion */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Quaternion_new03_local
static int tolua_Elementum_Ogre_Quaternion_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::Vector3* xaxis = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Ogre::Vector3* yaxis = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Ogre::Vector3* zaxis = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,4,0));
  {
   Ogre::Quaternion* tolua_ret = (Ogre::Quaternion*)  Mtolua_new((Ogre::Quaternion)(*xaxis,*yaxis,*zaxis));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Quaternion_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::Quaternion */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Quaternion_new04
static int tolua_Elementum_Ogre_Quaternion_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::Vector3* akAxis = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  {
   Ogre::Quaternion* tolua_ret = (Ogre::Quaternion*)  Mtolua_new((Ogre::Quaternion)(akAxis));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Quaternion");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Quaternion_new03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ogre::Quaternion */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Quaternion_new04_local
static int tolua_Elementum_Ogre_Quaternion_new04_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Quaternion",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::Vector3* akAxis = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  {
   Ogre::Quaternion* tolua_ret = (Ogre::Quaternion*)  Mtolua_new((Ogre::Quaternion)(akAxis));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Quaternion_new03_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  Ogre::ColourValue */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__ColourValue_ZERO
static int tolua_get_Ogre__ColourValue_ZERO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Ogre::ColourValue::ZERO,"const Ogre::ColourValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Black of class  Ogre::ColourValue */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__ColourValue_Black
static int tolua_get_Ogre__ColourValue_Black(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Ogre::ColourValue::Black,"const Ogre::ColourValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: White of class  Ogre::ColourValue */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__ColourValue_White
static int tolua_get_Ogre__ColourValue_White(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Ogre::ColourValue::White,"const Ogre::ColourValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Red of class  Ogre::ColourValue */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__ColourValue_Red
static int tolua_get_Ogre__ColourValue_Red(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Ogre::ColourValue::Red,"const Ogre::ColourValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Green of class  Ogre::ColourValue */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__ColourValue_Green
static int tolua_get_Ogre__ColourValue_Green(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Ogre::ColourValue::Green,"const Ogre::ColourValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Blue of class  Ogre::ColourValue */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__ColourValue_Blue
static int tolua_get_Ogre__ColourValue_Blue(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Ogre::ColourValue::Blue,"const Ogre::ColourValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::ColourValue */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_ColourValue_new00
static int tolua_Elementum_Ogre_ColourValue_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::ColourValue",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float red = ((float)  tolua_tonumber(tolua_S,2,1.0f));
  float green = ((float)  tolua_tonumber(tolua_S,3,1.0f));
  float blue = ((float)  tolua_tonumber(tolua_S,4,1.0f));
  float alpha = ((float)  tolua_tonumber(tolua_S,5,1.0f));
  {
   Ogre::ColourValue* tolua_ret = (Ogre::ColourValue*)  Mtolua_new((Ogre::ColourValue)(red,green,blue,alpha));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::ColourValue");
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

/* method: new_local of class  Ogre::ColourValue */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_ColourValue_new00_local
static int tolua_Elementum_Ogre_ColourValue_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::ColourValue",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float red = ((float)  tolua_tonumber(tolua_S,2,1.0f));
  float green = ((float)  tolua_tonumber(tolua_S,3,1.0f));
  float blue = ((float)  tolua_tonumber(tolua_S,4,1.0f));
  float alpha = ((float)  tolua_tonumber(tolua_S,5,1.0f));
  {
   Ogre::ColourValue* tolua_ret = (Ogre::ColourValue*)  Mtolua_new((Ogre::ColourValue)(red,green,blue,alpha));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::ColourValue");
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

/* method: new of class  Ogre::Plane */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Plane_new00
static int tolua_Elementum_Ogre_Plane_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Plane",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Vector3* rkNormal = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
   float fConstant = ((  float)  tolua_tonumber(tolua_S,3,0));
  {
   Ogre::Plane* tolua_ret = (Ogre::Plane*)  Mtolua_new((Ogre::Plane)(*rkNormal,fConstant));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Plane");
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

/* method: new_local of class  Ogre::Plane */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Plane_new00_local
static int tolua_Elementum_Ogre_Plane_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Plane",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Vector3* rkNormal = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
   float fConstant = ((  float)  tolua_tonumber(tolua_S,3,0));
  {
   Ogre::Plane* tolua_ret = (Ogre::Plane*)  Mtolua_new((Ogre::Plane)(*rkNormal,fConstant));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Plane");
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

/* method: new of class  Ogre::Plane */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Plane_new01
static int tolua_Elementum_Ogre_Plane_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Plane",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
   float a = ((  float)  tolua_tonumber(tolua_S,2,0));
   float b = ((  float)  tolua_tonumber(tolua_S,3,0));
   float c = ((  float)  tolua_tonumber(tolua_S,4,0));
   float d = ((  float)  tolua_tonumber(tolua_S,5,0));
  {
   Ogre::Plane* tolua_ret = (Ogre::Plane*)  Mtolua_new((Ogre::Plane)(a,b,c,d));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Plane");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Plane_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ogre::Plane */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Plane_new01_local
static int tolua_Elementum_Ogre_Plane_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Plane",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
   float a = ((  float)  tolua_tonumber(tolua_S,2,0));
   float b = ((  float)  tolua_tonumber(tolua_S,3,0));
   float c = ((  float)  tolua_tonumber(tolua_S,4,0));
   float d = ((  float)  tolua_tonumber(tolua_S,5,0));
  {
   Ogre::Plane* tolua_ret = (Ogre::Plane*)  Mtolua_new((Ogre::Plane)(a,b,c,d));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Plane");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Plane_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::AxisAlignedBox */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_AxisAlignedBox_new00
static int tolua_Elementum_Ogre_AxisAlignedBox_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::AxisAlignedBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Ogre::AxisAlignedBox* tolua_ret = (Ogre::AxisAlignedBox*)  Mtolua_new((Ogre::AxisAlignedBox)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::AxisAlignedBox");
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

/* method: new_local of class  Ogre::AxisAlignedBox */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_AxisAlignedBox_new00_local
static int tolua_Elementum_Ogre_AxisAlignedBox_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::AxisAlignedBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Ogre::AxisAlignedBox* tolua_ret = (Ogre::AxisAlignedBox*)  Mtolua_new((Ogre::AxisAlignedBox)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::AxisAlignedBox");
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

/* method: getSize of class  Ogre::AxisAlignedBox */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_AxisAlignedBox_getSize00
static int tolua_Elementum_Ogre_AxisAlignedBox_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::AxisAlignedBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::AxisAlignedBox* self = (const Ogre::AxisAlignedBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSize'",NULL);
#endif
  {
   Ogre::Vector3 tolua_ret = (Ogre::Vector3)  self->getSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Ogre::Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ogre::Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaximum of class  Ogre::AxisAlignedBox */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_AxisAlignedBox_getMaximum00
static int tolua_Elementum_Ogre_AxisAlignedBox_getMaximum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::AxisAlignedBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::AxisAlignedBox* self = (const Ogre::AxisAlignedBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaximum'",NULL);
#endif
  {
   Ogre::Vector3& tolua_ret = (Ogre::Vector3&)  self->getMaximum();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaximum'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMinimum of class  Ogre::AxisAlignedBox */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_AxisAlignedBox_getMinimum00
static int tolua_Elementum_Ogre_AxisAlignedBox_getMinimum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::AxisAlignedBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::AxisAlignedBox* self = (const Ogre::AxisAlignedBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMinimum'",NULL);
#endif
  {
   Ogre::Vector3& tolua_ret = (Ogre::Vector3&)  self->getMinimum();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMinimum'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCenter of class  Ogre::AxisAlignedBox */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_AxisAlignedBox_getCenter00
static int tolua_Elementum_Ogre_AxisAlignedBox_getCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::AxisAlignedBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::AxisAlignedBox* self = (const Ogre::AxisAlignedBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCenter'",NULL);
#endif
  {
   Ogre::Vector3 tolua_ret = (Ogre::Vector3)  self->getCenter();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Ogre::Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ogre::Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRenderQueueGroup of class  Ogre::MovableObject */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_MovableObject_setRenderQueueGroup00
static int tolua_Elementum_Ogre_MovableObject_setRenderQueueGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::MovableObject* self = (Ogre::MovableObject*)  tolua_tousertype(tolua_S,1,0);
   int queueID = ((  int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRenderQueueGroup'",NULL);
#endif
  {
   self->setRenderQueueGroup(queueID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRenderQueueGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRenderQueueGroupAndPriority of class  Ogre::MovableObject */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_MovableObject_setRenderQueueGroupAndPriority00
static int tolua_Elementum_Ogre_MovableObject_setRenderQueueGroupAndPriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::MovableObject* self = (Ogre::MovableObject*)  tolua_tousertype(tolua_S,1,0);
   int queueID = ((  int)  tolua_tonumber(tolua_S,2,0));
  unsigned short priority = (( unsigned short)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRenderQueueGroupAndPriority'",NULL);
#endif
  {
   self->setRenderQueueGroupAndPriority(queueID,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRenderQueueGroupAndPriority'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBoundingBox of class  Ogre::MovableObject */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_MovableObject_getBoundingBox00
static int tolua_Elementum_Ogre_MovableObject_getBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::MovableObject* self = (const Ogre::MovableObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBoundingBox'",NULL);
#endif
  {
   Ogre::AxisAlignedBox& tolua_ret = (Ogre::AxisAlignedBox&)  self->getBoundingBox();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Ogre::AxisAlignedBox");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWorldBoundingBox of class  Ogre::MovableObject */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_MovableObject_getWorldBoundingBox00
static int tolua_Elementum_Ogre_MovableObject_getWorldBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::MovableObject* self = (const Ogre::MovableObject*)  tolua_tousertype(tolua_S,1,0);
  bool derive = ((bool)  tolua_toboolean(tolua_S,2,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWorldBoundingBox'",NULL);
#endif
  {
   Ogre::AxisAlignedBox tolua_ret = (Ogre::AxisAlignedBox)  self->getWorldBoundingBox(derive);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Ogre::AxisAlignedBox)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::AxisAlignedBox");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ogre::AxisAlignedBox));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::AxisAlignedBox");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWorldBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMovableType of class  Ogre::MovableObject */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_MovableObject_getMovableType00
static int tolua_Elementum_Ogre_MovableObject_getMovableType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::MovableObject* self = (const Ogre::MovableObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMovableType'",NULL);
#endif
  {
    const std::string& tolua_ret = (  const std::string&)  self->getMovableType();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMovableType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setQueryFlags of class  Ogre::MovableObject */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_MovableObject_setQueryFlags00
static int tolua_Elementum_Ogre_MovableObject_setQueryFlags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::MovableObject* self = (Ogre::MovableObject*)  tolua_tousertype(tolua_S,1,0);
  int flags = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setQueryFlags'",NULL);
#endif
  {
   self->setQueryFlags(flags);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setQueryFlags'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisibilityFlags of class  Ogre::MovableObject */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_MovableObject_setVisibilityFlags00
static int tolua_Elementum_Ogre_MovableObject_setVisibilityFlags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::MovableObject* self = (Ogre::MovableObject*)  tolua_tousertype(tolua_S,1,0);
  int flags = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisibilityFlags'",NULL);
#endif
  {
   self->setVisibilityFlags(flags);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisibilityFlags'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUserAny of class  Ogre::MovableObject */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_MovableObject_setUserAny00
static int tolua_Elementum_Ogre_MovableObject_setUserAny00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::MovableObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Any",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::MovableObject* self = (Ogre::MovableObject*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Any* anything = ((const Ogre::Any*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUserAny'",NULL);
#endif
  {
   self->setUserAny(*anything);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUserAny'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUserAny of class  Ogre::MovableObject */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_MovableObject_getUserAny00
static int tolua_Elementum_Ogre_MovableObject_getUserAny00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::MovableObject* self = (const Ogre::MovableObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUserAny'",NULL);
#endif
  {
   const Ogre::Any& tolua_ret = (const Ogre::Any&)  self->getUserAny();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Any");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUserAny'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCastShadows of class  Ogre::MovableObject */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_MovableObject_setCastShadows00
static int tolua_Elementum_Ogre_MovableObject_setCastShadows00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::MovableObject* self = (Ogre::MovableObject*)  tolua_tousertype(tolua_S,1,0);
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCastShadows'",NULL);
#endif
  {
   self->setCastShadows(enabled);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCastShadows'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCastShadows of class  Ogre::MovableObject */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_MovableObject_getCastShadows00
static int tolua_Elementum_Ogre_MovableObject_getCastShadows00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::MovableObject* self = (Ogre::MovableObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCastShadows'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getCastShadows();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCastShadows'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getName of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_getName00
static int tolua_Elementum_Ogre_Node_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Node* self = (const Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'",NULL);
#endif
  {
    const std::string& tolua_ret = (  const std::string&)  self->getName();
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

/* method: getParent of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_getParent00
static int tolua_Elementum_Ogre_Node_getParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Node* self = (const Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParent'",NULL);
#endif
  {
   Ogre::Node* tolua_ret = (Ogre::Node*)  self->getParent();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_setPosition00
static int tolua_Elementum_Ogre_Node_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Node* self = (Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* pos = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'",NULL);
#endif
  {
   self->setPosition(*pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosition of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_getPosition00
static int tolua_Elementum_Ogre_Node_getPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Node* self = (const Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosition'",NULL);
#endif
  {
   Ogre::Vector3& tolua_ret = (Ogre::Vector3&)  self->getPosition();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_setScale00
static int tolua_Elementum_Ogre_Node_setScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Node* self = (Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* scale = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'",NULL);
#endif
  {
   self->setScale(*scale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_setScale01
static int tolua_Elementum_Ogre_Node_setScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Node",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Node* self = (Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'",NULL);
#endif
  {
   self->setScale(x,y,z);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_Node_setScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScale of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_getScale00
static int tolua_Elementum_Ogre_Node_getScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Node* self = (const Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScale'",NULL);
#endif
  {
   const Ogre::Vector3& tolua_ret = (const Ogre::Vector3&)  self->getScale();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createChild of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_createChild00
static int tolua_Elementum_Ogre_Node_createChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Node* self = (Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createChild'",NULL);
#endif
  {
   Ogre::Node* tolua_ret = (Ogre::Node*)  self->createChild();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createChild of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_createChild01
static int tolua_Elementum_Ogre_Node_createChild01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Node* self = (Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* translate = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createChild'",NULL);
#endif
  {
   Ogre::Node* tolua_ret = (Ogre::Node*)  self->createChild(*translate);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Node");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Node_createChild00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createChild of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_createChild02
static int tolua_Elementum_Ogre_Node_createChild02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Node* self = (Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* translate = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Ogre::Quaternion* rotate = ((const Ogre::Quaternion*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createChild'",NULL);
#endif
  {
   Ogre::Node* tolua_ret = (Ogre::Node*)  self->createChild(*translate,*rotate);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Node");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Node_createChild01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createChild of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_createChild03
static int tolua_Elementum_Ogre_Node_createChild03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Node",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Node* self = (Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createChild'",NULL);
#endif
  {
   Ogre::Node* tolua_ret = (Ogre::Node*)  self->createChild(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Node");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Node_createChild02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createChild of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_createChild04
static int tolua_Elementum_Ogre_Node_createChild04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Node",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Node* self = (Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const Ogre::Vector3* translate = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createChild'",NULL);
#endif
  {
   Ogre::Node* tolua_ret = (Ogre::Node*)  self->createChild(name,*translate);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Node");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Node_createChild03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createChild of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_createChild05
static int tolua_Elementum_Ogre_Node_createChild05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Node",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Ogre::Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Node* self = (Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const Ogre::Vector3* translate = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Ogre::Quaternion* rotate = ((const Ogre::Quaternion*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createChild'",NULL);
#endif
  {
   Ogre::Node* tolua_ret = (Ogre::Node*)  self->createChild(name,*translate,*rotate);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Node");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Node_createChild04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: addChild of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_addChild00
static int tolua_Elementum_Ogre_Node_addChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Node* self = (Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Node* child = ((Ogre::Node*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addChild'",NULL);
#endif
  {
   self->addChild(child);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getChild of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_getChildAt00
static int tolua_Elementum_Ogre_Node_getChildAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Node",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Node* self = (const Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getChild'",NULL);
#endif
  {
   Ogre::Node* tolua_ret = (Ogre::Node*)  self->getChild(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getChildAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: numChildren of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_numChildren00
static int tolua_Elementum_Ogre_Node_numChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Node* self = (const Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'numChildren'",NULL);
#endif
  {
   int tolua_ret = (int)  self->numChildren();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'numChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getChild of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_getChild00
static int tolua_Elementum_Ogre_Node_getChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Node",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Node* self = (const Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getChild'",NULL);
#endif
  {
   Ogre::Node* tolua_ret = (Ogre::Node*)  self->getChild(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeChild of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_removeChild00
static int tolua_Elementum_Ogre_Node_removeChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Node",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Node* self = (Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
  unsigned short index = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeChild'",NULL);
#endif
  {
   Ogre::Node* tolua_ret = (Ogre::Node*)  self->removeChild(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeChild of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_removeChild01
static int tolua_Elementum_Ogre_Node_removeChild01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Node",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Node* self = (Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Node* child = ((Ogre::Node*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeChild'",NULL);
#endif
  {
   Ogre::Node* tolua_ret = (Ogre::Node*)  self->removeChild(child);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Node");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Node_removeChild00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeChild of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_removeChild02
static int tolua_Elementum_Ogre_Node_removeChild02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Node",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Node* self = (Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeChild'",NULL);
#endif
  {
   Ogre::Node* tolua_ret = (Ogre::Node*)  self->removeChild(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Node");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Node_removeChild01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAllChildren of class  Ogre::Node */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Node_removeAllChildren00
static int tolua_Elementum_Ogre_Node_removeAllChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Node* self = (Ogre::Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllChildren'",NULL);
#endif
  {
   self->removeAllChildren();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSubEntity of class  Ogre::Entity */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Entity_getSubEntity00
static int tolua_Elementum_Ogre_Entity_getSubEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Entity* self = (const Ogre::Entity*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSubEntity'",NULL);
#endif
  {
   Ogre::SubEntity* tolua_ret = (Ogre::SubEntity*)  self->getSubEntity(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SubEntity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSubEntity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSubEntity of class  Ogre::Entity */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Entity_getSubEntity01
static int tolua_Elementum_Ogre_Entity_getSubEntity01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Entity",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::Entity* self = (const Ogre::Entity*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSubEntity'",NULL);
#endif
  {
   Ogre::SubEntity* tolua_ret = (Ogre::SubEntity*)  self->getSubEntity(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SubEntity");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Entity_getSubEntity00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNumSubEntities of class  Ogre::Entity */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Entity_getNumSubEntities00
static int tolua_Elementum_Ogre_Entity_getNumSubEntities00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Entity* self = (const Ogre::Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNumSubEntities'",NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->getNumSubEntities();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNumSubEntities'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDisplaySkeleton of class  Ogre::Entity */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Entity_setDisplaySkeleton00
static int tolua_Elementum_Ogre_Entity_setDisplaySkeleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Entity",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Entity* self = (Ogre::Entity*)  tolua_tousertype(tolua_S,1,0);
  bool display = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDisplaySkeleton'",NULL);
#endif
  {
   self->setDisplaySkeleton(display);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDisplaySkeleton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaterialName of class  Ogre::Entity */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Entity_setMaterialName00
static int tolua_Elementum_Ogre_Entity_setMaterialName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Entity",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Entity* self = (Ogre::Entity*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaterialName'",NULL);
#endif
  {
   self->setMaterialName(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaterialName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaterialName of class  Ogre::Entity */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Entity_setMaterialName01
static int tolua_Elementum_Ogre_Entity_setMaterialName01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Entity",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Entity* self = (Ogre::Entity*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string groupName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaterialName'",NULL);
#endif
  {
   self->setMaterialName(name,groupName);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_Entity_setMaterialName00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: yaw of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_yaw00
static int tolua_Elementum_Ogre_SceneNode_yaw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Degree",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Degree tolua_var_14 = *((const Ogre::Degree*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'yaw'",NULL);
#endif
  {
   self->yaw(tolua_var_14);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'yaw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pitch of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_pitch00
static int tolua_Elementum_Ogre_SceneNode_pitch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Degree",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Degree tolua_var_15 = *((const Ogre::Degree*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pitch'",NULL);
#endif
  {
   self->pitch(tolua_var_15);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pitch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: roll of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_roll00
static int tolua_Elementum_Ogre_SceneNode_roll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Degree",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Degree tolua_var_16 = *((const Ogre::Degree*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'roll'",NULL);
#endif
  {
   self->roll(tolua_var_16);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'roll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachObject of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_attachObject00
static int tolua_Elementum_Ogre_SceneNode_attachObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  Ogre::MovableObject* obj = ((Ogre::MovableObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachObject'",NULL);
#endif
  {
   self->attachObject(obj);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: numAttachedObjects of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_numAttachedObjects00
static int tolua_Elementum_Ogre_SceneNode_numAttachedObjects00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneNode* self = (const Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'numAttachedObjects'",NULL);
#endif
  {
   unsigned short tolua_ret = (unsigned short)  self->numAttachedObjects();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'numAttachedObjects'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAttachedObject of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_getAttachedObjectAt00
static int tolua_Elementum_Ogre_SceneNode_getAttachedObjectAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  unsigned short index = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttachedObject'",NULL);
#endif
  {
   Ogre::MovableObject* tolua_ret = (Ogre::MovableObject*)  self->getAttachedObject(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::MovableObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttachedObjectAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAttachedObject of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_getAttachedObject00
static int tolua_Elementum_Ogre_SceneNode_getAttachedObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttachedObject'",NULL);
#endif
  {
   Ogre::MovableObject* tolua_ret = (Ogre::MovableObject*)  self->getAttachedObject(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::MovableObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttachedObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: detachObject of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_detachObject00
static int tolua_Elementum_Ogre_SceneNode_detachObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  unsigned short index = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detachObject'",NULL);
#endif
  {
   Ogre::MovableObject* tolua_ret = (Ogre::MovableObject*)  self->detachObject(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::MovableObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'detachObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: detachObject of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_detachObject01
static int tolua_Elementum_Ogre_SceneNode_detachObject01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::MovableObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  Ogre::MovableObject* obj = ((Ogre::MovableObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detachObject'",NULL);
#endif
  {
   self->detachObject(obj);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneNode_detachObject00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: detachObject of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_detachObject02
static int tolua_Elementum_Ogre_SceneNode_detachObject02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detachObject'",NULL);
#endif
  {
   Ogre::MovableObject* tolua_ret = (Ogre::MovableObject*)  self->detachObject(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::MovableObject");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneNode_detachObject01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: detachAllObjects of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_detachAllObjects00
static int tolua_Elementum_Ogre_SceneNode_detachAllObjects00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detachAllObjects'",NULL);
#endif
  {
   self->detachAllObjects();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'detachAllObjects'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCreator of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_getCreator00
static int tolua_Elementum_Ogre_SceneNode_getCreator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneNode* self = (const Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCreator'",NULL);
#endif
  {
   Ogre::SceneManager* tolua_ret = (Ogre::SceneManager*)  self->getCreator();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCreator'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createChildSceneNode of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_createChildSceneNode00
static int tolua_Elementum_Ogre_SceneNode_createChildSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createChildSceneNode'",NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->createChildSceneNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createChildSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createChildSceneNode of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_createChildSceneNode01
static int tolua_Elementum_Ogre_SceneNode_createChildSceneNode01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* translate = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createChildSceneNode'",NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->createChildSceneNode(*translate);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneNode_createChildSceneNode00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createChildSceneNode of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_createChildSceneNode02
static int tolua_Elementum_Ogre_SceneNode_createChildSceneNode02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* translate = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Ogre::Quaternion* rotate = ((const Ogre::Quaternion*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createChildSceneNode'",NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->createChildSceneNode(*translate,*rotate);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneNode_createChildSceneNode01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createChildSceneNode of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_createChildSceneNode03
static int tolua_Elementum_Ogre_SceneNode_createChildSceneNode03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createChildSceneNode'",NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->createChildSceneNode(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneNode_createChildSceneNode02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createChildSceneNode of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_createChildSceneNode04
static int tolua_Elementum_Ogre_SceneNode_createChildSceneNode04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const Ogre::Vector3* translate = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createChildSceneNode'",NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->createChildSceneNode(name,*translate);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneNode_createChildSceneNode03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createChildSceneNode of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_createChildSceneNode05
static int tolua_Elementum_Ogre_SceneNode_createChildSceneNode05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Ogre::Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const Ogre::Vector3* translate = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Ogre::Quaternion* rotate = ((const Ogre::Quaternion*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createChildSceneNode'",NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->createChildSceneNode(name,*translate,*rotate);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneNode_createChildSceneNode04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAndDestroyChild of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_removeAndDestroyChild00
static int tolua_Elementum_Ogre_SceneNode_removeAndDestroyChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAndDestroyChild'",NULL);
#endif
  {
   self->removeAndDestroyChild(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAndDestroyChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAndDestroyChild of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_removeAndDestroyChild01
static int tolua_Elementum_Ogre_SceneNode_removeAndDestroyChild01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  unsigned short index = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAndDestroyChild'",NULL);
#endif
  {
   self->removeAndDestroyChild(index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneNode_removeAndDestroyChild00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAndDestroyAllChildren of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_removeAndDestroyAllChildren00
static int tolua_Elementum_Ogre_SceneNode_removeAndDestroyAllChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAndDestroyAllChildren'",NULL);
#endif
  {
   self->removeAndDestroyAllChildren();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAndDestroyAllChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showBoundingBox of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_showBoundingBox00
static int tolua_Elementum_Ogre_SceneNode_showBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  bool bShow = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'showBoundingBox'",NULL);
#endif
  {
   self->showBoundingBox(bShow);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hideBoundingBox of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_hideBoundingBox00
static int tolua_Elementum_Ogre_SceneNode_hideBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  bool bHide = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hideBoundingBox'",NULL);
#endif
  {
   self->hideBoundingBox(bHide);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hideBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDirection of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_setDirection00
static int tolua_Elementum_Ogre_SceneNode_setDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
  Ogre::Node::TransformSpace relativeTo = ((Ogre::Node::TransformSpace) (int)  tolua_tonumber(tolua_S,5,Ogre::Node::TS_LOCAL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDirection'",NULL);
#endif
  {
   self->setDirection(x,y,z,relativeTo);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDirection of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_setDirection01
static int tolua_Elementum_Ogre_SceneNode_setDirection01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
  Ogre::Node::TransformSpace relativeTo = ((Ogre::Node::TransformSpace) (int)  tolua_tonumber(tolua_S,5,0));
  const Ogre::Vector3* localDirectionVector = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDirection'",NULL);
#endif
  {
   self->setDirection(x,y,z,relativeTo,*localDirectionVector);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneNode_setDirection00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDirection of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_setDirection02
static int tolua_Elementum_Ogre_SceneNode_setDirection02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* vec = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  Ogre::Node::TransformSpace relativeTo = ((Ogre::Node::TransformSpace) (int)  tolua_tonumber(tolua_S,3,Ogre::Node::TS_LOCAL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDirection'",NULL);
#endif
  {
   self->setDirection(*vec,relativeTo);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneNode_setDirection01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDirection of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_setDirection03
static int tolua_Elementum_Ogre_SceneNode_setDirection03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* vec = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  Ogre::Node::TransformSpace relativeTo = ((Ogre::Node::TransformSpace) (int)  tolua_tonumber(tolua_S,3,0));
  const Ogre::Vector3* localDirectionVector = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDirection'",NULL);
#endif
  {
   self->setDirection(*vec,relativeTo,*localDirectionVector);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneNode_setDirection02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: lookAt of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_lookAt00
static int tolua_Elementum_Ogre_SceneNode_lookAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* targetPoint = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  Ogre::Node::TransformSpace relativeTo = ((Ogre::Node::TransformSpace) (int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lookAt'",NULL);
#endif
  {
   self->lookAt(*targetPoint,relativeTo);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lookAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lookAt of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_lookAt01
static int tolua_Elementum_Ogre_SceneNode_lookAt01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* targetPoint = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  Ogre::Node::TransformSpace relativeTo = ((Ogre::Node::TransformSpace) (int)  tolua_tonumber(tolua_S,3,0));
  const Ogre::Vector3* localDirectionVector = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lookAt'",NULL);
#endif
  {
   self->lookAt(*targetPoint,relativeTo,*localDirectionVector);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneNode_lookAt00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAutoTracking of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_setAutoTracking00
static int tolua_Elementum_Ogre_SceneNode_setAutoTracking00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Ogre::SceneNode",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
  Ogre::SceneNode* target = ((Ogre::SceneNode*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoTracking'",NULL);
#endif
  {
   self->setAutoTracking(enabled,target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAutoTracking'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAutoTracking of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_setAutoTracking01
static int tolua_Elementum_Ogre_SceneNode_setAutoTracking01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Ogre::SceneNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
  Ogre::SceneNode* target = ((Ogre::SceneNode*)  tolua_tousertype(tolua_S,3,0));
  const Ogre::Vector3* localDirectionVector = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoTracking'",NULL);
#endif
  {
   self->setAutoTracking(enabled,target,*localDirectionVector);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneNode_setAutoTracking00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAutoTracking of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_setAutoTracking02
static int tolua_Elementum_Ogre_SceneNode_setAutoTracking02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Ogre::SceneNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Ogre::Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
  Ogre::SceneNode* target = ((Ogre::SceneNode*)  tolua_tousertype(tolua_S,3,0));
  const Ogre::Vector3* localDirectionVector = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,4,0));
  const Ogre::Vector3* offset = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoTracking'",NULL);
#endif
  {
   self->setAutoTracking(enabled,target,*localDirectionVector,*offset);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneNode_setAutoTracking01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAutoTrackTarget of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_getAutoTrackTarget00
static int tolua_Elementum_Ogre_SceneNode_getAutoTrackTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAutoTrackTarget'",NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->getAutoTrackTarget();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAutoTrackTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAutoTrackOffset of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_getAutoTrackOffset00
static int tolua_Elementum_Ogre_SceneNode_getAutoTrackOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAutoTrackOffset'",NULL);
#endif
  {
   const Ogre::Vector3& tolua_ret = (const Ogre::Vector3&)  self->getAutoTrackOffset();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAutoTrackOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAutoTrackLocalDirection of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_getAutoTrackLocalDirection00
static int tolua_Elementum_Ogre_SceneNode_getAutoTrackLocalDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAutoTrackLocalDirection'",NULL);
#endif
  {
   const Ogre::Vector3& tolua_ret = (const Ogre::Vector3&)  self->getAutoTrackLocalDirection();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAutoTrackLocalDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParentSceneNode of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_getParentSceneNode00
static int tolua_Elementum_Ogre_SceneNode_getParentSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneNode* self = (const Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParentSceneNode'",NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->getParentSceneNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParentSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisible of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_setVisible00
static int tolua_Elementum_Ogre_SceneNode_setVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  bool visible = ((bool)  tolua_toboolean(tolua_S,2,0));
  bool cascade = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisible'",NULL);
#endif
  {
   self->setVisible(visible,cascade);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: flipVisibility of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_flipVisibility00
static int tolua_Elementum_Ogre_SceneNode_flipVisibility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  bool cascade = ((bool)  tolua_toboolean(tolua_S,2,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'flipVisibility'",NULL);
#endif
  {
   self->flipVisibility(cascade);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'flipVisibility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOrientation of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_setOrientation00
static int tolua_Elementum_Ogre_SceneNode_setOrientation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Quaternion* q = ((const Ogre::Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOrientation'",NULL);
#endif
  {
   self->setOrientation(*q);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOrientation of class  Ogre::SceneNode */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneNode_setOrientation01
static int tolua_Elementum_Ogre_SceneNode_setOrientation01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneNode* self = (Ogre::SceneNode*)  tolua_tousertype(tolua_S,1,0);
   float w = ((  float)  tolua_tonumber(tolua_S,2,0));
   float x = ((  float)  tolua_tonumber(tolua_S,3,0));
   float y = ((  float)  tolua_tonumber(tolua_S,4,0));
   float z = ((  float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOrientation'",NULL);
#endif
  {
   self->setOrientation(w,x,y,z);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneNode_setOrientation00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_new00
static int tolua_Elementum_Ogre_Light_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Ogre::Light* tolua_ret = (Ogre::Light*)  Mtolua_new((Ogre::Light)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Light");
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

/* method: new_local of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_new00_local
static int tolua_Elementum_Ogre_Light_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Ogre::Light* tolua_ret = (Ogre::Light*)  Mtolua_new((Ogre::Light)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Light");
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

/* method: new of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_new01
static int tolua_Elementum_Ogre_Light_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   Ogre::Light* tolua_ret = (Ogre::Light*)  Mtolua_new((Ogre::Light)(name));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Light");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Light_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_new01_local
static int tolua_Elementum_Ogre_Light_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   Ogre::Light* tolua_ret = (Ogre::Light*)  Mtolua_new((Ogre::Light)(name));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Light");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Light_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_delete00
static int tolua_Elementum_Ogre_Light_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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

/* method: setType of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setType00
static int tolua_Elementum_Ogre_Light_setType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Light::LightTypes type = ((Ogre::Light::LightTypes) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setType'",NULL);
#endif
  {
   self->setType(type);
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

/* method: getType of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getType00
static int tolua_Elementum_Ogre_Light_getType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getType'",NULL);
#endif
  {
   Ogre::Light::LightTypes tolua_ret = (Ogre::Light::LightTypes)  self->getType();
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

/* method: setDiffuseColour of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setDiffuseColour00
static int tolua_Elementum_Ogre_Light_setDiffuseColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
   float red = ((  float)  tolua_tonumber(tolua_S,2,0));
   float green = ((  float)  tolua_tonumber(tolua_S,3,0));
   float blue = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDiffuseColour'",NULL);
#endif
  {
   self->setDiffuseColour(red,green,blue);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDiffuseColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDiffuseColour of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setDiffuseColour01
static int tolua_Elementum_Ogre_Light_setDiffuseColour01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::ColourValue",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::ColourValue* colour = ((const Ogre::ColourValue*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDiffuseColour'",NULL);
#endif
  {
   self->setDiffuseColour(*colour);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_Light_setDiffuseColour00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDiffuseColour of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getDiffuseColour00
static int tolua_Elementum_Ogre_Light_getDiffuseColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDiffuseColour'",NULL);
#endif
  {
   const Ogre::ColourValue& tolua_ret = (const Ogre::ColourValue&)  self->getDiffuseColour();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::ColourValue");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDiffuseColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSpecularColour of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setSpecularColour00
static int tolua_Elementum_Ogre_Light_setSpecularColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
   float red = ((  float)  tolua_tonumber(tolua_S,2,0));
   float green = ((  float)  tolua_tonumber(tolua_S,3,0));
   float blue = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpecularColour'",NULL);
#endif
  {
   self->setSpecularColour(red,green,blue);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSpecularColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSpecularColour of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setSpecularColour01
static int tolua_Elementum_Ogre_Light_setSpecularColour01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::ColourValue",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::ColourValue* colour = ((const Ogre::ColourValue*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpecularColour'",NULL);
#endif
  {
   self->setSpecularColour(*colour);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_Light_setSpecularColour00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSpecularColour of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getSpecularColour00
static int tolua_Elementum_Ogre_Light_getSpecularColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpecularColour'",NULL);
#endif
  {
   const Ogre::ColourValue& tolua_ret = (const Ogre::ColourValue&)  self->getSpecularColour();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::ColourValue");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSpecularColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAttenuation of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setAttenuation00
static int tolua_Elementum_Ogre_Light_setAttenuation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
   float range = ((  float)  tolua_tonumber(tolua_S,2,0));
   float constant = ((  float)  tolua_tonumber(tolua_S,3,0));
   float linear = ((  float)  tolua_tonumber(tolua_S,4,0));
   float quadratic = ((  float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAttenuation'",NULL);
#endif
  {
   self->setAttenuation(range,constant,linear,quadratic);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAttenuation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAttenuationRange of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getAttenuationRange00
static int tolua_Elementum_Ogre_Light_getAttenuationRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttenuationRange'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getAttenuationRange();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttenuationRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAttenuationConstant of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getAttenuationConstant00
static int tolua_Elementum_Ogre_Light_getAttenuationConstant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttenuationConstant'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getAttenuationConstant();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttenuationConstant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAttenuationLinear of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getAttenuationLinear00
static int tolua_Elementum_Ogre_Light_getAttenuationLinear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttenuationLinear'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getAttenuationLinear();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttenuationLinear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAttenuationQuadric of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getAttenuationQuadric00
static int tolua_Elementum_Ogre_Light_getAttenuationQuadric00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttenuationQuadric'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getAttenuationQuadric();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttenuationQuadric'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setPosition00
static int tolua_Elementum_Ogre_Light_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'",NULL);
#endif
  {
   self->setPosition(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setPosition01
static int tolua_Elementum_Ogre_Light_setPosition01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* vec = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'",NULL);
#endif
  {
   self->setPosition(*vec);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_Light_setPosition00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosition of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getPosition00
static int tolua_Elementum_Ogre_Light_getPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosition'",NULL);
#endif
  {
   const Ogre::Vector3& tolua_ret = (const Ogre::Vector3&)  self->getPosition();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDirection of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setDirection00
static int tolua_Elementum_Ogre_Light_setDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDirection'",NULL);
#endif
  {
   self->setDirection(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDirection of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setDirection01
static int tolua_Elementum_Ogre_Light_setDirection01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* vec = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDirection'",NULL);
#endif
  {
   self->setDirection(*vec);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_Light_setDirection00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDirection of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getDirection00
static int tolua_Elementum_Ogre_Light_getDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDirection'",NULL);
#endif
  {
   const Ogre::Vector3& tolua_ret = (const Ogre::Vector3&)  self->getDirection();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSpotlightRange of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setSpotlightRange00
static int tolua_Elementum_Ogre_Light_setSpotlightRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Radian",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Radian",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Radian* innerAngle = ((const Ogre::Radian*)  tolua_tousertype(tolua_S,2,0));
  const Ogre::Radian* outerAngle = ((const Ogre::Radian*)  tolua_tousertype(tolua_S,3,0));
   float falloff = ((  float)  tolua_tonumber(tolua_S,4,1.0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpotlightRange'",NULL);
#endif
  {
   self->setSpotlightRange(*innerAngle,*outerAngle,falloff);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSpotlightRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSpotlightInnerAngle of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getSpotlightInnerAngle00
static int tolua_Elementum_Ogre_Light_getSpotlightInnerAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpotlightInnerAngle'",NULL);
#endif
  {
   const Ogre::Radian& tolua_ret = (const Ogre::Radian&)  self->getSpotlightInnerAngle();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Radian");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSpotlightInnerAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSpotlightOuterAngle of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getSpotlightOuterAngle00
static int tolua_Elementum_Ogre_Light_getSpotlightOuterAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpotlightOuterAngle'",NULL);
#endif
  {
   const Ogre::Radian& tolua_ret = (const Ogre::Radian&)  self->getSpotlightOuterAngle();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Radian");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSpotlightOuterAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSpotlightFalloff of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getSpotlightFalloff00
static int tolua_Elementum_Ogre_Light_getSpotlightFalloff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpotlightFalloff'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getSpotlightFalloff();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSpotlightFalloff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSpotlightInnerAngle of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setSpotlightInnerAngle00
static int tolua_Elementum_Ogre_Light_setSpotlightInnerAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Radian",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Radian* val = ((const Ogre::Radian*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpotlightInnerAngle'",NULL);
#endif
  {
   self->setSpotlightInnerAngle(*val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSpotlightInnerAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSpotlightOuterAngle of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setSpotlightOuterAngle00
static int tolua_Elementum_Ogre_Light_setSpotlightOuterAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Radian",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Radian* val = ((const Ogre::Radian*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpotlightOuterAngle'",NULL);
#endif
  {
   self->setSpotlightOuterAngle(*val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSpotlightOuterAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSpotlightFalloff of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setSpotlightFalloff00
static int tolua_Elementum_Ogre_Light_setSpotlightFalloff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
   float val = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpotlightFalloff'",NULL);
#endif
  {
   self->setSpotlightFalloff(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSpotlightFalloff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPowerScale of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setPowerScale00
static int tolua_Elementum_Ogre_Light_setPowerScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
   float power = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPowerScale'",NULL);
#endif
  {
   self->setPowerScale(power);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPowerScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPowerScale of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getPowerScale00
static int tolua_Elementum_Ogre_Light_getPowerScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPowerScale'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getPowerScale();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPowerScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBoundingBox of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getBoundingBox00
static int tolua_Elementum_Ogre_Light_getBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBoundingBox'",NULL);
#endif
  {
   const Ogre::AxisAlignedBox& tolua_ret = (const Ogre::AxisAlignedBox&)  self->getBoundingBox();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::AxisAlignedBox");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMovableType of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getMovableType00
static int tolua_Elementum_Ogre_Light_getMovableType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMovableType'",NULL);
#endif
  {
    const std::string& tolua_ret = (  const std::string&)  self->getMovableType();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMovableType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDerivedPosition of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getDerivedPosition00
static int tolua_Elementum_Ogre_Light_getDerivedPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
  bool cameraRelativeIfSet = ((bool)  tolua_toboolean(tolua_S,2,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDerivedPosition'",NULL);
#endif
  {
   const Ogre::Vector3& tolua_ret = (const Ogre::Vector3&)  self->getDerivedPosition(cameraRelativeIfSet);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDerivedPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDerivedDirection of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_getDerivedDirection00
static int tolua_Elementum_Ogre_Light_getDerivedDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Light* self = (const Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDerivedDirection'",NULL);
#endif
  {
   const Ogre::Vector3& tolua_ret = (const Ogre::Vector3&)  self->getDerivedDirection();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDerivedDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisible of class  Ogre::Light */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Light_setVisible00
static int tolua_Elementum_Ogre_Light_setVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Light",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Light* self = (Ogre::Light*)  tolua_tousertype(tolua_S,1,0);
  bool visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisible'",NULL);
#endif
  {
   self->setVisible(visible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_new00
static int tolua_Elementum_Ogre_Camera_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  Ogre::SceneManager* sm = ((Ogre::SceneManager*)  tolua_tousertype(tolua_S,3,0));
  {
   Ogre::Camera* tolua_ret = (Ogre::Camera*)  Mtolua_new((Ogre::Camera)(name,sm));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Camera");
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_new00_local
static int tolua_Elementum_Ogre_Camera_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  Ogre::SceneManager* sm = ((Ogre::SceneManager*)  tolua_tousertype(tolua_S,3,0));
  {
   Ogre::Camera* tolua_ret = (Ogre::Camera*)  Mtolua_new((Ogre::Camera)(name,sm));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Camera");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_delete00
static int tolua_Elementum_Ogre_Camera_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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

/* method: getSceneManager of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_getSceneManager00
static int tolua_Elementum_Ogre_Camera_getSceneManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Camera* self = (const Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneManager'",NULL);
#endif
  {
   Ogre::SceneManager* tolua_ret = (Ogre::SceneManager*)  self->getSceneManager();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSceneManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAspectRatio of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_setAspectRatio00
static int tolua_Elementum_Ogre_Camera_setAspectRatio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
   float ratio = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAspectRatio'",NULL);
#endif
  {
   self->setAspectRatio(ratio);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAspectRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setNearClipDistance of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_setNearClipDistance00
static int tolua_Elementum_Ogre_Camera_setNearClipDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
   float nearDist = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setNearClipDistance'",NULL);
#endif
  {
   self->setNearClipDistance(nearDist);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNearClipDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNearClipDistance of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_getNearClipDistance00
static int tolua_Elementum_Ogre_Camera_getNearClipDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Camera* self = (const Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNearClipDistance'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getNearClipDistance();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNearClipDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFarClipDistance of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_setFarClipDistance00
static int tolua_Elementum_Ogre_Camera_setFarClipDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
   float farDist = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFarClipDistance'",NULL);
#endif
  {
   self->setFarClipDistance(farDist);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFarClipDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFarClipDistance of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_getFarClipDistance00
static int tolua_Elementum_Ogre_Camera_getFarClipDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Camera* self = (const Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFarClipDistance'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getFarClipDistance();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFarClipDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPolygonMode of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_setPolygonMode00
static int tolua_Elementum_Ogre_Camera_setPolygonMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
  Ogre::PolygonMode sd = ((Ogre::PolygonMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPolygonMode'",NULL);
#endif
  {
   self->setPolygonMode(sd);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPolygonMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPolygonMode of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_getPolygonMode00
static int tolua_Elementum_Ogre_Camera_getPolygonMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Camera* self = (const Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPolygonMode'",NULL);
#endif
  {
   Ogre::PolygonMode tolua_ret = (Ogre::PolygonMode)  self->getPolygonMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPolygonMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_setPosition00
static int tolua_Elementum_Ogre_Camera_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'",NULL);
#endif
  {
   self->setPosition(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_setPosition01
static int tolua_Elementum_Ogre_Camera_setPosition01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* vec = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'",NULL);
#endif
  {
   self->setPosition(*vec);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_Camera_setPosition00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosition of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_getPosition00
static int tolua_Elementum_Ogre_Camera_getPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Camera* self = (const Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosition'",NULL);
#endif
  {
   const Ogre::Vector3& tolua_ret = (const Ogre::Vector3&)  self->getPosition();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: move of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_move00
static int tolua_Elementum_Ogre_Camera_move00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* vec = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'move'",NULL);
#endif
  {
   self->move(*vec);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'move'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveRelative of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_moveRelative00
static int tolua_Elementum_Ogre_Camera_moveRelative00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* vec = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveRelative'",NULL);
#endif
  {
   self->moveRelative(*vec);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveRelative'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDirection of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_setDirection00
static int tolua_Elementum_Ogre_Camera_setDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDirection'",NULL);
#endif
  {
   self->setDirection(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDirection of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_setDirection01
static int tolua_Elementum_Ogre_Camera_setDirection01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* vec = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDirection'",NULL);
#endif
  {
   self->setDirection(*vec);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_Camera_setDirection00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDirection of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_getDirection00
static int tolua_Elementum_Ogre_Camera_getDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Camera* self = (const Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDirection'",NULL);
#endif
  {
   Ogre::Vector3 tolua_ret = (Ogre::Vector3)  self->getDirection();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Ogre::Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ogre::Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUp of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_getUp00
static int tolua_Elementum_Ogre_Camera_getUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Camera* self = (const Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUp'",NULL);
#endif
  {
   Ogre::Vector3 tolua_ret = (Ogre::Vector3)  self->getUp();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Ogre::Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ogre::Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRight of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_getRight00
static int tolua_Elementum_Ogre_Camera_getRight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Camera* self = (const Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRight'",NULL);
#endif
  {
   Ogre::Vector3 tolua_ret = (Ogre::Vector3)  self->getRight();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Ogre::Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ogre::Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lookAt of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_lookAt00
static int tolua_Elementum_Ogre_Camera_lookAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* targetPoint = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lookAt'",NULL);
#endif
  {
   self->lookAt(*targetPoint);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lookAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lookAt of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_lookAt01
static int tolua_Elementum_Ogre_Camera_lookAt01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lookAt'",NULL);
#endif
  {
   self->lookAt(x,y,z);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_Camera_lookAt00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: roll of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_roll00
static int tolua_Elementum_Ogre_Camera_roll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Radian",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Radian* angle = ((const Ogre::Radian*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'roll'",NULL);
#endif
  {
   self->roll(*angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'roll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: yaw of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_yaw00
static int tolua_Elementum_Ogre_Camera_yaw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Radian",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Radian* angle = ((const Ogre::Radian*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'yaw'",NULL);
#endif
  {
   self->yaw(*angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'yaw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pitch of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_pitch00
static int tolua_Elementum_Ogre_Camera_pitch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Radian",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Radian* angle = ((const Ogre::Radian*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pitch'",NULL);
#endif
  {
   self->pitch(*angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pitch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_rotate00
static int tolua_Elementum_Ogre_Camera_rotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Radian",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* axis = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Ogre::Radian* angle = ((const Ogre::Radian*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotate'",NULL);
#endif
  {
   self->rotate(*axis,*angle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_rotate01
static int tolua_Elementum_Ogre_Camera_rotate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Quaternion* q = ((const Ogre::Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotate'",NULL);
#endif
  {
   self->rotate(*q);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_Camera_rotate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFixedYawAxis of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_setFixedYawAxis00
static int tolua_Elementum_Ogre_Camera_setFixedYawAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
  bool useFixed = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFixedYawAxis'",NULL);
#endif
  {
   self->setFixedYawAxis(useFixed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFixedYawAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFixedYawAxis of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_setFixedYawAxis01
static int tolua_Elementum_Ogre_Camera_setFixedYawAxis01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
  bool useFixed = ((bool)  tolua_toboolean(tolua_S,2,0));
  const Ogre::Vector3* fixedAxis = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFixedYawAxis'",NULL);
#endif
  {
   self->setFixedYawAxis(useFixed,*fixedAxis);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_Camera_setFixedYawAxis00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOrientation of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_getOrientation00
static int tolua_Elementum_Ogre_Camera_getOrientation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Camera* self = (const Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOrientation'",NULL);
#endif
  {
   const Ogre::Quaternion& tolua_ret = (const Ogre::Quaternion&)  self->getOrientation();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Quaternion");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOrientation of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_setOrientation00
static int tolua_Elementum_Ogre_Camera_setOrientation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* self = (Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Quaternion* q = ((const Ogre::Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOrientation'",NULL);
#endif
  {
   self->setOrientation(*q);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewport of class  Ogre::Camera */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Camera_getViewport00
static int tolua_Elementum_Ogre_Camera_getViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Camera* self = (const Ogre::Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewport'",NULL);
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

/* get function: lastFPS of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__RenderTarget__FrameStats_lastFPS
static int tolua_get_Ogre__RenderTarget__FrameStats_lastFPS(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lastFPS'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->lastFPS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: lastFPS of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__RenderTarget__FrameStats_lastFPS
static int tolua_set_Ogre__RenderTarget__FrameStats_lastFPS(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lastFPS'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->lastFPS = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: avgFPS of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__RenderTarget__FrameStats_avgFPS
static int tolua_get_Ogre__RenderTarget__FrameStats_avgFPS(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'avgFPS'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->avgFPS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: avgFPS of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__RenderTarget__FrameStats_avgFPS
static int tolua_set_Ogre__RenderTarget__FrameStats_avgFPS(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'avgFPS'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->avgFPS = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bestFPS of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__RenderTarget__FrameStats_bestFPS
static int tolua_get_Ogre__RenderTarget__FrameStats_bestFPS(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bestFPS'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bestFPS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bestFPS of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__RenderTarget__FrameStats_bestFPS
static int tolua_set_Ogre__RenderTarget__FrameStats_bestFPS(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bestFPS'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bestFPS = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: worstFPS of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__RenderTarget__FrameStats_worstFPS
static int tolua_get_Ogre__RenderTarget__FrameStats_worstFPS(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worstFPS'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->worstFPS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: worstFPS of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__RenderTarget__FrameStats_worstFPS
static int tolua_set_Ogre__RenderTarget__FrameStats_worstFPS(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worstFPS'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->worstFPS = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bestFrameTime of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__RenderTarget__FrameStats_unsigned_bestFrameTime
static int tolua_get_Ogre__RenderTarget__FrameStats_unsigned_bestFrameTime(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bestFrameTime'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->bestFrameTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bestFrameTime of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__RenderTarget__FrameStats_unsigned_bestFrameTime
static int tolua_set_Ogre__RenderTarget__FrameStats_unsigned_bestFrameTime(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bestFrameTime'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bestFrameTime = ((unsigned long)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: worstFrameTime of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__RenderTarget__FrameStats_unsigned_worstFrameTime
static int tolua_get_Ogre__RenderTarget__FrameStats_unsigned_worstFrameTime(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worstFrameTime'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->worstFrameTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: worstFrameTime of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__RenderTarget__FrameStats_unsigned_worstFrameTime
static int tolua_set_Ogre__RenderTarget__FrameStats_unsigned_worstFrameTime(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worstFrameTime'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->worstFrameTime = ((unsigned long)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: triangleCount of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__RenderTarget__FrameStats_triangleCount
static int tolua_get_Ogre__RenderTarget__FrameStats_triangleCount(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'triangleCount'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->triangleCount,"size_t");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: triangleCount of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__RenderTarget__FrameStats_triangleCount
static int tolua_set_Ogre__RenderTarget__FrameStats_triangleCount(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'triangleCount'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"size_t",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->triangleCount = *((size_t*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: batchCount of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__RenderTarget__FrameStats_batchCount
static int tolua_get_Ogre__RenderTarget__FrameStats_batchCount(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'batchCount'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->batchCount,"size_t");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: batchCount of class  FrameStats */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__RenderTarget__FrameStats_batchCount
static int tolua_set_Ogre__RenderTarget__FrameStats_batchCount(lua_State* tolua_S)
{
  Ogre::RenderTarget::FrameStats* self = (Ogre::RenderTarget::FrameStats*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'batchCount'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"size_t",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->batchCount = *((size_t*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getName of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getName00
static int tolua_Elementum_Ogre_RenderTarget_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderTarget* self = (const Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'",NULL);
#endif
  {
    const std::string& tolua_ret = (  const std::string&)  self->getName();
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

/* method: getMetrics of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getMetrics00
static int tolua_Elementum_Ogre_RenderTarget_getMetrics00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderTarget* self = (Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
  unsigned int width = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int height = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int colourDepth = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMetrics'",NULL);
#endif
  {
   self->getMetrics(width,height,colourDepth);
   tolua_pushnumber(tolua_S,(lua_Number)width);
   tolua_pushnumber(tolua_S,(lua_Number)height);
   tolua_pushnumber(tolua_S,(lua_Number)colourDepth);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMetrics'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWidth of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getWidth00
static int tolua_Elementum_Ogre_RenderTarget_getWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderTarget* self = (const Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidth'",NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->getWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeight of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getHeight00
static int tolua_Elementum_Ogre_RenderTarget_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderTarget* self = (const Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'",NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->getHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColourDepth of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getColourDepth00
static int tolua_Elementum_Ogre_RenderTarget_getColourDepth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderTarget* self = (const Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColourDepth'",NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->getColourDepth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColourDepth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeContentsToFile of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_writeContentsToFile00
static int tolua_Elementum_Ogre_RenderTarget_writeContentsToFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderTarget* self = (Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeContentsToFile'",NULL);
#endif
  {
   self->writeContentsToFile(filename);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeContentsToFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeContentsToTimestampedFile of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_writeContentsToTimestampedFile00
static int tolua_Elementum_Ogre_RenderTarget_writeContentsToTimestampedFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderTarget* self = (Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
  const std::string filenamePrefix = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string filenameSuffix = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeContentsToTimestampedFile'",NULL);
#endif
  {
    std::string tolua_ret = (  std::string)  self->writeContentsToTimestampedFile(filenamePrefix,filenameSuffix);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeContentsToTimestampedFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addViewport of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_addViewport00
static int tolua_Elementum_Ogre_RenderTarget_addViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderTarget* self = (Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Camera* cam = ((Ogre::Camera*)  tolua_tousertype(tolua_S,2,0));
  int ZOrder = ((int)  tolua_tonumber(tolua_S,3,0));
  float left = ((float)  tolua_tonumber(tolua_S,4,0.0f));
  float top = ((float)  tolua_tonumber(tolua_S,5,0.0f));
  float width = ((float)  tolua_tonumber(tolua_S,6,1.0f));
  float height = ((float)  tolua_tonumber(tolua_S,7,1.0f));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addViewport'",NULL);
#endif
  {
   Ogre::Viewport* tolua_ret = (Ogre::Viewport*)  self->addViewport(cam,ZOrder,left,top,width,height);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Viewport");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addViewport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNumViewports of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getNumViewports00
static int tolua_Elementum_Ogre_RenderTarget_getNumViewports00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderTarget* self = (const Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNumViewports'",NULL);
#endif
  {
   unsigned short tolua_ret = (unsigned short)  self->getNumViewports();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNumViewports'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewport of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getViewport00
static int tolua_Elementum_Ogre_RenderTarget_getViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderTarget* self = (Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
  unsigned short index = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewport'",NULL);
#endif
  {
   Ogre::Viewport* tolua_ret = (Ogre::Viewport*)  self->getViewport(index);
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

/* method: getViewportByZOrder of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getViewportByZOrder00
static int tolua_Elementum_Ogre_RenderTarget_getViewportByZOrder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderTarget* self = (Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
  int ZOrder = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewportByZOrder'",NULL);
#endif
  {
   Ogre::Viewport* tolua_ret = (Ogre::Viewport*)  self->getViewportByZOrder(ZOrder);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Viewport");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewportByZOrder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasViewportWithZOrder of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_hasViewportWithZOrder00
static int tolua_Elementum_Ogre_RenderTarget_hasViewportWithZOrder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderTarget* self = (Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
  int ZOrder = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasViewportWithZOrder'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasViewportWithZOrder(ZOrder);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasViewportWithZOrder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeViewport of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_removeViewport00
static int tolua_Elementum_Ogre_RenderTarget_removeViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderTarget* self = (Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
  int ZOrder = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeViewport'",NULL);
#endif
  {
   self->removeViewport(ZOrder);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeViewport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAllViewports of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_removeAllViewports00
static int tolua_Elementum_Ogre_RenderTarget_removeAllViewports00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderTarget* self = (Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllViewports'",NULL);
#endif
  {
   self->removeAllViewports();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllViewports'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStatistics of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getStatistics00
static int tolua_Elementum_Ogre_RenderTarget_getStatistics00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderTarget* self = (const Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
  float lastFPS = ((float)  tolua_tonumber(tolua_S,2,0));
  float avgFPS = ((float)  tolua_tonumber(tolua_S,3,0));
  float bestFPS = ((float)  tolua_tonumber(tolua_S,4,0));
  float worstFPS = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStatistics'",NULL);
#endif
  {
   self->getStatistics(lastFPS,avgFPS,bestFPS,worstFPS);
   tolua_pushnumber(tolua_S,(lua_Number)lastFPS);
   tolua_pushnumber(tolua_S,(lua_Number)avgFPS);
   tolua_pushnumber(tolua_S,(lua_Number)bestFPS);
   tolua_pushnumber(tolua_S,(lua_Number)worstFPS);
  }
 }
 return 4;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStatistics'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStatistics of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getStatistics01
static int tolua_Elementum_Ogre_RenderTarget_getStatistics01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::RenderTarget* self = (const Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStatistics'",NULL);
#endif
  {
   const Ogre::RenderTarget::FrameStats& tolua_ret = (const Ogre::RenderTarget::FrameStats&)  self->getStatistics();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::RenderTarget::FrameStats");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_RenderTarget_getStatistics00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLastFPS of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getLastFPS00
static int tolua_Elementum_Ogre_RenderTarget_getLastFPS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderTarget* self = (const Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLastFPS'",NULL);
#endif
  {
   float tolua_ret = (float)  self->getLastFPS();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLastFPS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAverageFPS of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getAverageFPS00
static int tolua_Elementum_Ogre_RenderTarget_getAverageFPS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderTarget* self = (const Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAverageFPS'",NULL);
#endif
  {
   float tolua_ret = (float)  self->getAverageFPS();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAverageFPS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBestFPS of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getBestFPS00
static int tolua_Elementum_Ogre_RenderTarget_getBestFPS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderTarget* self = (const Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBestFPS'",NULL);
#endif
  {
   float tolua_ret = (float)  self->getBestFPS();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBestFPS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWorstFPS of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getWorstFPS00
static int tolua_Elementum_Ogre_RenderTarget_getWorstFPS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderTarget* self = (const Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWorstFPS'",NULL);
#endif
  {
   float tolua_ret = (float)  self->getWorstFPS();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWorstFPS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBestFrameTime of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getBestFrameTime00
static int tolua_Elementum_Ogre_RenderTarget_getBestFrameTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderTarget* self = (const Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBestFrameTime'",NULL);
#endif
  {
   float tolua_ret = (float)  self->getBestFrameTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBestFrameTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWorstFrameTime of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_getWorstFrameTime00
static int tolua_Elementum_Ogre_RenderTarget_getWorstFrameTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderTarget* self = (const Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWorstFrameTime'",NULL);
#endif
  {
   float tolua_ret = (float)  self->getWorstFrameTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWorstFrameTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetStatistics of class  Ogre::RenderTarget */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderTarget_resetStatistics00
static int tolua_Elementum_Ogre_RenderTarget_resetStatistics00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderTarget* self = (Ogre::RenderTarget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetStatistics'",NULL);
#endif
  {
   self->resetStatistics();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetStatistics'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFullscreen of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_setFullscreen00
static int tolua_Elementum_Ogre_RenderWindow_setFullscreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderWindow* self = (Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
  bool fullScreen = ((bool)  tolua_toboolean(tolua_S,2,0));
  unsigned int width = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int height = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFullscreen'",NULL);
#endif
  {
   self->setFullscreen(fullScreen,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFullscreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroy of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_destroy00
static int tolua_Elementum_Ogre_RenderWindow_destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderWindow* self = (Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroy'",NULL);
#endif
  {
   self->destroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resize of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_resize00
static int tolua_Elementum_Ogre_RenderWindow_resize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderWindow* self = (Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
  unsigned int width = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int height = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resize'",NULL);
#endif
  {
   self->resize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: windowMovedOrResized of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_windowMovedOrResized00
static int tolua_Elementum_Ogre_RenderWindow_windowMovedOrResized00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderWindow* self = (Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'windowMovedOrResized'",NULL);
#endif
  {
   self->windowMovedOrResized();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'windowMovedOrResized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reposition of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_reposition00
static int tolua_Elementum_Ogre_RenderWindow_reposition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderWindow* self = (Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reposition'",NULL);
#endif
  {
   self->reposition(left,top);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reposition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isVisible of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_isVisible00
static int tolua_Elementum_Ogre_RenderWindow_isVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderWindow* self = (const Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isVisible'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisible of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_setVisible00
static int tolua_Elementum_Ogre_RenderWindow_setVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderWindow* self = (Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
  bool visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisible'",NULL);
#endif
  {
   self->setVisible(visible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isHidden of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_isHidden00
static int tolua_Elementum_Ogre_RenderWindow_isHidden00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderWindow* self = (const Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isHidden'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isHidden();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isHidden'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHidden of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_setHidden00
static int tolua_Elementum_Ogre_RenderWindow_setHidden00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderWindow* self = (Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
  bool hidden = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHidden'",NULL);
#endif
  {
   self->setHidden(hidden);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHidden'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVSyncEnabled of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_setVSyncEnabled00
static int tolua_Elementum_Ogre_RenderWindow_setVSyncEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderWindow* self = (Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
  bool vsync = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVSyncEnabled'",NULL);
#endif
  {
   self->setVSyncEnabled(vsync);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVSyncEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isVSyncEnabled of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_isVSyncEnabled00
static int tolua_Elementum_Ogre_RenderWindow_isVSyncEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderWindow* self = (const Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isVSyncEnabled'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isVSyncEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isVSyncEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVSyncInterval of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_setVSyncInterval00
static int tolua_Elementum_Ogre_RenderWindow_setVSyncInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderWindow* self = (Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
  unsigned int interval = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVSyncInterval'",NULL);
#endif
  {
   self->setVSyncInterval(interval);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVSyncInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVSyncInterval of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_getVSyncInterval00
static int tolua_Elementum_Ogre_RenderWindow_getVSyncInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderWindow* self = (const Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVSyncInterval'",NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->getVSyncInterval();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVSyncInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isActive of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_isActive00
static int tolua_Elementum_Ogre_RenderWindow_isActive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderWindow* self = (const Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isActive'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isActive();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isActive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isClosed of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_isClosed00
static int tolua_Elementum_Ogre_RenderWindow_isClosed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderWindow* self = (const Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isClosed'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isClosed();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isClosed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isPrimary of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_isPrimary00
static int tolua_Elementum_Ogre_RenderWindow_isPrimary00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderWindow* self = (const Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isPrimary'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isPrimary();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isPrimary'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isFullScreen of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_isFullScreen00
static int tolua_Elementum_Ogre_RenderWindow_isFullScreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderWindow* self = (const Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isFullScreen'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isFullScreen();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isFullScreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMetrics of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_getMetrics00
static int tolua_Elementum_Ogre_RenderWindow_getMetrics00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderWindow* self = (Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
  unsigned int width = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int height = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int colourDepth = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  int left = ((int)  tolua_tonumber(tolua_S,5,0));
  int top = ((int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMetrics'",NULL);
#endif
  {
   self->getMetrics(width,height,colourDepth,left,top);
   tolua_pushnumber(tolua_S,(lua_Number)width);
   tolua_pushnumber(tolua_S,(lua_Number)height);
   tolua_pushnumber(tolua_S,(lua_Number)colourDepth);
   tolua_pushnumber(tolua_S,(lua_Number)left);
   tolua_pushnumber(tolua_S,(lua_Number)top);
  }
 }
 return 5;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMetrics'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: suggestPixelFormat of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_suggestPixelFormat00
static int tolua_Elementum_Ogre_RenderWindow_suggestPixelFormat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderWindow* self = (const Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'suggestPixelFormat'",NULL);
#endif
  {
   Ogre::PixelFormat tolua_ret = (Ogre::PixelFormat)  self->suggestPixelFormat();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'suggestPixelFormat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isDeactivatedOnFocusChange of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_isDeactivatedOnFocusChange00
static int tolua_Elementum_Ogre_RenderWindow_isDeactivatedOnFocusChange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::RenderWindow* self = (const Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDeactivatedOnFocusChange'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isDeactivatedOnFocusChange();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDeactivatedOnFocusChange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDeactivateOnFocusChange of class  Ogre::RenderWindow */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_RenderWindow_setDeactivateOnFocusChange00
static int tolua_Elementum_Ogre_RenderWindow_setDeactivateOnFocusChange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::RenderWindow",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::RenderWindow* self = (Ogre::RenderWindow*)  tolua_tousertype(tolua_S,1,0);
  bool deactivate = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDeactivateOnFocusChange'",NULL);
#endif
  {
   self->setDeactivateOnFocusChange(deactivate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDeactivateOnFocusChange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createCamera of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_createCamera00
static int tolua_Elementum_Ogre_SceneManager_createCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createCamera'",NULL);
#endif
  {
   Ogre::Camera* tolua_ret = (Ogre::Camera*)  self->createCamera(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Camera");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCamera of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getCamera00
static int tolua_Elementum_Ogre_SceneManager_getCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCamera'",NULL);
#endif
  {
   Ogre::Camera* tolua_ret = (Ogre::Camera*)  self->getCamera(name);
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

/* method: hasCamera of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_hasCamera00
static int tolua_Elementum_Ogre_SceneManager_hasCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasCamera'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasCamera(name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyAllCameras of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyAllCameras00
static int tolua_Elementum_Ogre_SceneManager_destroyAllCameras00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyAllCameras'",NULL);
#endif
  {
   self->destroyAllCameras();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyAllCameras'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyCamera of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyCamera00
static int tolua_Elementum_Ogre_SceneManager_destroyCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Camera* tolua_var_17 = ((Ogre::Camera*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyCamera'",NULL);
#endif
  {
   self->destroyCamera(tolua_var_17);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createLight of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_createLight00
static int tolua_Elementum_Ogre_SceneManager_createLight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createLight'",NULL);
#endif
  {
   Ogre::Light* tolua_ret = (Ogre::Light*)  self->createLight(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Light");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createLight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createLight of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_createLight01
static int tolua_Elementum_Ogre_SceneManager_createLight01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createLight'",NULL);
#endif
  {
   Ogre::Light* tolua_ret = (Ogre::Light*)  self->createLight();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Light");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_createLight00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLight of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getLight00
static int tolua_Elementum_Ogre_SceneManager_getLight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLight'",NULL);
#endif
  {
   Ogre::Light* tolua_ret = (Ogre::Light*)  self->getLight(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Light");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasLight of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_hasLight00
static int tolua_Elementum_Ogre_SceneManager_hasLight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasLight'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasLight(name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasLight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyLight of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyLight00
static int tolua_Elementum_Ogre_SceneManager_destroyLight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyLight'",NULL);
#endif
  {
   self->destroyLight(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyLight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyLight of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyLight01
static int tolua_Elementum_Ogre_SceneManager_destroyLight01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Light* tolua_var_18 = ((Ogre::Light*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyLight'",NULL);
#endif
  {
   self->destroyLight(tolua_var_18);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_destroyLight00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyAllLights of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyAllLights00
static int tolua_Elementum_Ogre_SceneManager_destroyAllLights00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyAllLights'",NULL);
#endif
  {
   self->destroyAllLights();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyAllLights'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAmbientLight of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setAmbientLight00
static int tolua_Elementum_Ogre_SceneManager_setAmbientLight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::ColourValue",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::ColourValue* colour = ((const Ogre::ColourValue*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAmbientLight'",NULL);
#endif
  {
   self->setAmbientLight(*colour);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAmbientLight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAmbientLight of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getAmbientLight00
static int tolua_Elementum_Ogre_SceneManager_getAmbientLight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAmbientLight'",NULL);
#endif
  {
   const Ogre::ColourValue& tolua_ret = (const Ogre::ColourValue&)  self->getAmbientLight();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::ColourValue");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAmbientLight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWorldGeometry of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setWorldGeometry00
static int tolua_Elementum_Ogre_SceneManager_setWorldGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWorldGeometry'",NULL);
#endif
  {
   self->setWorldGeometry(filename);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWorldGeometry'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearScene of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_clearScene00
static int tolua_Elementum_Ogre_SceneManager_clearScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearScene'",NULL);
#endif
  {
   self->clearScene();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createSceneNode of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_createSceneNode00
static int tolua_Elementum_Ogre_SceneManager_createSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createSceneNode'",NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->createSceneNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createSceneNode of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_createSceneNode01
static int tolua_Elementum_Ogre_SceneManager_createSceneNode01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createSceneNode'",NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->createSceneNode(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_createSceneNode00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroySceneNode of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroySceneNode00
static int tolua_Elementum_Ogre_SceneManager_destroySceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroySceneNode'",NULL);
#endif
  {
   self->destroySceneNode(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroySceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroySceneNode of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroySceneNode01
static int tolua_Elementum_Ogre_SceneManager_destroySceneNode01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  Ogre::SceneNode* sn = ((Ogre::SceneNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroySceneNode'",NULL);
#endif
  {
   self->destroySceneNode(sn);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_destroySceneNode00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRootSceneNode of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getRootSceneNode00
static int tolua_Elementum_Ogre_SceneManager_getRootSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRootSceneNode'",NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->getRootSceneNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRootSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSceneNode of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getSceneNode00
static int tolua_Elementum_Ogre_SceneManager_getSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneNode'",NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->getSceneNode(name);
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

/* method: hasSceneNode of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_hasSceneNode00
static int tolua_Elementum_Ogre_SceneManager_hasSceneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasSceneNode'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasSceneNode(name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasSceneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createEntity of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_createEntity00
static int tolua_Elementum_Ogre_SceneManager_createEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string entityName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string meshName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createEntity'",NULL);
#endif
  {
   Ogre::Entity* tolua_ret = (Ogre::Entity*)  self->createEntity(entityName,meshName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Entity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createEntity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createEntity of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_createEntity01
static int tolua_Elementum_Ogre_SceneManager_createEntity01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string entityName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string meshName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string groupName = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createEntity'",NULL);
#endif
  {
   Ogre::Entity* tolua_ret = (Ogre::Entity*)  self->createEntity(entityName,meshName,groupName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Entity");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_createEntity00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createEntity of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_createEntity02
static int tolua_Elementum_Ogre_SceneManager_createEntity02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string meshName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createEntity'",NULL);
#endif
  {
   Ogre::Entity* tolua_ret = (Ogre::Entity*)  self->createEntity(meshName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Entity");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_createEntity01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getEntity of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getEntity00
static int tolua_Elementum_Ogre_SceneManager_getEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEntity'",NULL);
#endif
  {
   Ogre::Entity* tolua_ret = (Ogre::Entity*)  self->getEntity(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Entity");
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

/* method: hasEntity of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_hasEntity00
static int tolua_Elementum_Ogre_SceneManager_hasEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasEntity'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasEntity(name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasEntity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyEntity of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyEntity00
static int tolua_Elementum_Ogre_SceneManager_destroyEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Entity* ent = ((Ogre::Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyEntity'",NULL);
#endif
  {
   self->destroyEntity(ent);
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

/* method: destroyEntity of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyEntity01
static int tolua_Elementum_Ogre_SceneManager_destroyEntity01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyEntity'",NULL);
#endif
  {
   self->destroyEntity(name);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_destroyEntity00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyAllEntities of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyAllEntities00
static int tolua_Elementum_Ogre_SceneManager_destroyAllEntities00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyAllEntities'",NULL);
#endif
  {
   self->destroyAllEntities();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyAllEntities'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkyPlane of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setSkyPlane00
static int tolua_Elementum_Ogre_SceneManager_setSkyPlane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Plane",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,11,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
  const Ogre::Plane* plane = ((const Ogre::Plane*)  tolua_tousertype(tolua_S,3,0));
  const std::string materialName = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
   float scale = ((  float)  tolua_tonumber(tolua_S,5,1000));
   float tiling = ((  float)  tolua_tonumber(tolua_S,6,10));
  bool drawFirst = ((bool)  tolua_toboolean(tolua_S,7,true));
   float bow = ((  float)  tolua_tonumber(tolua_S,8,0));
  int xsegments = ((int)  tolua_tonumber(tolua_S,9,1));
  int ysegments = ((int)  tolua_tonumber(tolua_S,10,1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkyPlane'",NULL);
#endif
  {
   self->setSkyPlane(enable,*plane,materialName,scale,tiling,drawFirst,bow,xsegments,ysegments);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSkyPlane'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkyPlane of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setSkyPlane01
static int tolua_Elementum_Ogre_SceneManager_setSkyPlane01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::Plane",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,11,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
  const Ogre::Plane* plane = ((const Ogre::Plane*)  tolua_tousertype(tolua_S,3,0));
  const std::string materialName = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
   float scale = ((  float)  tolua_tonumber(tolua_S,5,0));
   float tiling = ((  float)  tolua_tonumber(tolua_S,6,0));
  bool drawFirst = ((bool)  tolua_toboolean(tolua_S,7,0));
   float bow = ((  float)  tolua_tonumber(tolua_S,8,0));
  int xsegments = ((int)  tolua_tonumber(tolua_S,9,0));
  int ysegments = ((int)  tolua_tonumber(tolua_S,10,0));
  const std::string groupName = ((const std::string)  tolua_tocppstring(tolua_S,11,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkyPlane'",NULL);
#endif
  {
   self->setSkyPlane(enable,*plane,materialName,scale,tiling,drawFirst,bow,xsegments,ysegments,groupName);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_setSkyPlane00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkyPlaneEnabled of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setSkyPlaneEnabled00
static int tolua_Elementum_Ogre_SceneManager_setSkyPlaneEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkyPlaneEnabled'",NULL);
#endif
  {
   self->setSkyPlaneEnabled(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSkyPlaneEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isSkyPlaneEnabled of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_isSkyPlaneEnabled00
static int tolua_Elementum_Ogre_SceneManager_isSkyPlaneEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isSkyPlaneEnabled'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isSkyPlaneEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isSkyPlaneEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSkyPlaneNode of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getSkyPlaneNode00
static int tolua_Elementum_Ogre_SceneManager_getSkyPlaneNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSkyPlaneNode'",NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->getSkyPlaneNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSkyPlaneNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkyBox of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setSkyBox00
static int tolua_Elementum_Ogre_SceneManager_setSkyBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
  const std::string materialName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
   float distance = ((  float)  tolua_tonumber(tolua_S,4,5000));
  bool drawFirst = ((bool)  tolua_toboolean(tolua_S,5,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkyBox'",NULL);
#endif
  {
   self->setSkyBox(enable,materialName,distance,drawFirst);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSkyBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkyBox of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setSkyBox01
static int tolua_Elementum_Ogre_SceneManager_setSkyBox01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const Ogre::Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
  const std::string materialName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
   float distance = ((  float)  tolua_tonumber(tolua_S,4,0));
  bool drawFirst = ((bool)  tolua_toboolean(tolua_S,5,0));
  const Ogre::Quaternion* orientation = ((const Ogre::Quaternion*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkyBox'",NULL);
#endif
  {
   self->setSkyBox(enable,materialName,distance,drawFirst,*orientation);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_setSkyBox00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkyBox of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setSkyBox02
static int tolua_Elementum_Ogre_SceneManager_setSkyBox02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const Ogre::Quaternion",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
  const std::string materialName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
   float distance = ((  float)  tolua_tonumber(tolua_S,4,0));
  bool drawFirst = ((bool)  tolua_toboolean(tolua_S,5,0));
  const Ogre::Quaternion* orientation = ((const Ogre::Quaternion*)  tolua_tousertype(tolua_S,6,0));
  const std::string groupName = ((const std::string)  tolua_tocppstring(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkyBox'",NULL);
#endif
  {
   self->setSkyBox(enable,materialName,distance,drawFirst,*orientation,groupName);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_setSkyBox01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkyBoxEnabled of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setSkyBoxEnabled00
static int tolua_Elementum_Ogre_SceneManager_setSkyBoxEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkyBoxEnabled'",NULL);
#endif
  {
   self->setSkyBoxEnabled(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSkyBoxEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isSkyBoxEnabled of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_isSkyBoxEnabled00
static int tolua_Elementum_Ogre_SceneManager_isSkyBoxEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isSkyBoxEnabled'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isSkyBoxEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isSkyBoxEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSkyBoxNode of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getSkyBoxNode00
static int tolua_Elementum_Ogre_SceneManager_getSkyBoxNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSkyBoxNode'",NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->getSkyBoxNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSkyBoxNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkyDome of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setSkyDome00
static int tolua_Elementum_Ogre_SceneManager_setSkyDome00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
  const std::string materialName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
   float curvature = ((  float)  tolua_tonumber(tolua_S,4,10));
   float tiling = ((  float)  tolua_tonumber(tolua_S,5,8));
   float distance = ((  float)  tolua_tonumber(tolua_S,6,4000));
  bool drawFirst = ((bool)  tolua_toboolean(tolua_S,7,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkyDome'",NULL);
#endif
  {
   self->setSkyDome(enable,materialName,curvature,tiling,distance,drawFirst);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSkyDome'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkyDome of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setSkyDome01
static int tolua_Elementum_Ogre_SceneManager_setSkyDome01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isusertype(tolua_S,8,"const Ogre::Quaternion",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,9,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
  const std::string materialName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
   float curvature = ((  float)  tolua_tonumber(tolua_S,4,0));
   float tiling = ((  float)  tolua_tonumber(tolua_S,5,0));
   float distance = ((  float)  tolua_tonumber(tolua_S,6,0));
  bool drawFirst = ((bool)  tolua_toboolean(tolua_S,7,0));
  const Ogre::Quaternion* orientation = ((const Ogre::Quaternion*)  tolua_tousertype(tolua_S,8,0));
  int xsegments = ((int)  tolua_tonumber(tolua_S,9,16));
  int ysegments = ((int)  tolua_tonumber(tolua_S,10,16));
  int ysegments_keep = ((int)  tolua_tonumber(tolua_S,11,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkyDome'",NULL);
#endif
  {
   self->setSkyDome(enable,materialName,curvature,tiling,distance,drawFirst,*orientation,xsegments,ysegments,ysegments_keep);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_setSkyDome00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkyDome of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setSkyDome02
static int tolua_Elementum_Ogre_SceneManager_setSkyDome02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isusertype(tolua_S,8,"const Ogre::Quaternion",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,12,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,13,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
  const std::string materialName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
   float curvature = ((  float)  tolua_tonumber(tolua_S,4,0));
   float tiling = ((  float)  tolua_tonumber(tolua_S,5,0));
   float distance = ((  float)  tolua_tonumber(tolua_S,6,0));
  bool drawFirst = ((bool)  tolua_toboolean(tolua_S,7,0));
  const Ogre::Quaternion* orientation = ((const Ogre::Quaternion*)  tolua_tousertype(tolua_S,8,0));
  int xsegments = ((int)  tolua_tonumber(tolua_S,9,0));
  int ysegments = ((int)  tolua_tonumber(tolua_S,10,0));
  int ysegments_keep = ((int)  tolua_tonumber(tolua_S,11,0));
  const std::string groupName = ((const std::string)  tolua_tocppstring(tolua_S,12,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkyDome'",NULL);
#endif
  {
   self->setSkyDome(enable,materialName,curvature,tiling,distance,drawFirst,*orientation,xsegments,ysegments,ysegments_keep,groupName);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_setSkyDome01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFog of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setFog00
static int tolua_Elementum_Ogre_SceneManager_setFog00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  Ogre::FogMode mode = ((Ogre::FogMode) (int)  tolua_tonumber(tolua_S,2,Ogre::FOG_NONE));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFog'",NULL);
#endif
  {
   self->setFog(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFog of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setFog01
static int tolua_Elementum_Ogre_SceneManager_setFog01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::ColourValue",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  Ogre::FogMode mode = ((Ogre::FogMode) (int)  tolua_tonumber(tolua_S,2,0));
  const Ogre::ColourValue* colour = ((const Ogre::ColourValue*)  tolua_tousertype(tolua_S,3,0));
   float expDensity = ((  float)  tolua_tonumber(tolua_S,4,0.001));
   float linearStart = ((  float)  tolua_tonumber(tolua_S,5,0.0));
   float linearEnd = ((  float)  tolua_tonumber(tolua_S,6,1.0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFog'",NULL);
#endif
  {
   self->setFog(mode,*colour,expDensity,linearStart,linearEnd);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_setFog00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFogMode of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getFogMode00
static int tolua_Elementum_Ogre_SceneManager_getFogMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFogMode'",NULL);
#endif
  {
   Ogre::FogMode tolua_ret = (Ogre::FogMode)  self->getFogMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFogMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFogColour of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getFogColour00
static int tolua_Elementum_Ogre_SceneManager_getFogColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFogColour'",NULL);
#endif
  {
   const Ogre::ColourValue& tolua_ret = (const Ogre::ColourValue&)  self->getFogColour();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::ColourValue");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFogColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFogStart of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getFogStart00
static int tolua_Elementum_Ogre_SceneManager_getFogStart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFogStart'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getFogStart();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFogStart'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFogEnd of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getFogEnd00
static int tolua_Elementum_Ogre_SceneManager_getFogEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFogEnd'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getFogEnd();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFogEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFogDensity of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getFogDensity00
static int tolua_Elementum_Ogre_SceneManager_getFogDensity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFogDensity'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getFogDensity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFogDensity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setShadowTechnique of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setShadowTechnique00
static int tolua_Elementum_Ogre_SceneManager_setShadowTechnique00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  Ogre::ShadowTechnique technique = ((Ogre::ShadowTechnique) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setShadowTechnique'",NULL);
#endif
  {
   self->setShadowTechnique(technique);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setShadowTechnique'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getShadowTechnique of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getShadowTechnique00
static int tolua_Elementum_Ogre_SceneManager_getShadowTechnique00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getShadowTechnique'",NULL);
#endif
  {
   Ogre::ShadowTechnique tolua_ret = (Ogre::ShadowTechnique)  self->getShadowTechnique();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getShadowTechnique'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setShadowColour of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_setShadowColour00
static int tolua_Elementum_Ogre_SceneManager_setShadowColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::ColourValue",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::ColourValue* colour = ((const Ogre::ColourValue*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setShadowColour'",NULL);
#endif
  {
   self->setShadowColour(*colour);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setShadowColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getShadowColour of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getShadowColour00
static int tolua_Elementum_Ogre_SceneManager_getShadowColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getShadowColour'",NULL);
#endif
  {
   const Ogre::ColourValue& tolua_ret = (const Ogre::ColourValue&)  self->getShadowColour();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::ColourValue");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getShadowColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createStaticGeometry of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_createStaticGeometry00
static int tolua_Elementum_Ogre_SceneManager_createStaticGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createStaticGeometry'",NULL);
#endif
  {
   Ogre::StaticGeometry* tolua_ret = (Ogre::StaticGeometry*)  self->createStaticGeometry(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::StaticGeometry");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createStaticGeometry'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStaticGeometry of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getStaticGeometry00
static int tolua_Elementum_Ogre_SceneManager_getStaticGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStaticGeometry'",NULL);
#endif
  {
   Ogre::StaticGeometry* tolua_ret = (Ogre::StaticGeometry*)  self->getStaticGeometry(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::StaticGeometry");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStaticGeometry'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasStaticGeometry of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_hasStaticGeometry00
static int tolua_Elementum_Ogre_SceneManager_hasStaticGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasStaticGeometry'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasStaticGeometry(name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasStaticGeometry'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyStaticGeometry of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyStaticGeometry00
static int tolua_Elementum_Ogre_SceneManager_destroyStaticGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::StaticGeometry",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  Ogre::StaticGeometry* geom = ((Ogre::StaticGeometry*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyStaticGeometry'",NULL);
#endif
  {
   self->destroyStaticGeometry(geom);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyStaticGeometry'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyStaticGeometry of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyStaticGeometry01
static int tolua_Elementum_Ogre_SceneManager_destroyStaticGeometry01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyStaticGeometry'",NULL);
#endif
  {
   self->destroyStaticGeometry(name);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_destroyStaticGeometry00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyAllStaticGeometry of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyAllStaticGeometry00
static int tolua_Elementum_Ogre_SceneManager_destroyAllStaticGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyAllStaticGeometry'",NULL);
#endif
  {
   self->destroyAllStaticGeometry();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyAllStaticGeometry'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createInstancedGeometry of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_createInstancedGeometry00
static int tolua_Elementum_Ogre_SceneManager_createInstancedGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createInstancedGeometry'",NULL);
#endif
  {
   Ogre::InstancedGeometry* tolua_ret = (Ogre::InstancedGeometry*)  self->createInstancedGeometry(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::InstancedGeometry");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createInstancedGeometry'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstancedGeometry of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getInstancedGeometry00
static int tolua_Elementum_Ogre_SceneManager_getInstancedGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInstancedGeometry'",NULL);
#endif
  {
   Ogre::InstancedGeometry* tolua_ret = (Ogre::InstancedGeometry*)  self->getInstancedGeometry(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::InstancedGeometry");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstancedGeometry'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyInstancedGeometry of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyInstancedGeometry00
static int tolua_Elementum_Ogre_SceneManager_destroyInstancedGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::InstancedGeometry",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  Ogre::InstancedGeometry* geom = ((Ogre::InstancedGeometry*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyInstancedGeometry'",NULL);
#endif
  {
   self->destroyInstancedGeometry(geom);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyInstancedGeometry'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyInstancedGeometry of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyInstancedGeometry01
static int tolua_Elementum_Ogre_SceneManager_destroyInstancedGeometry01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyInstancedGeometry'",NULL);
#endif
  {
   self->destroyInstancedGeometry(name);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_destroyInstancedGeometry00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyAllInstancedGeometry of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyAllInstancedGeometry00
static int tolua_Elementum_Ogre_SceneManager_destroyAllInstancedGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyAllInstancedGeometry'",NULL);
#endif
  {
   self->destroyAllInstancedGeometry();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyAllInstancedGeometry'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createRibbonTrail of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_createRibbonTrail00
static int tolua_Elementum_Ogre_SceneManager_createRibbonTrail00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createRibbonTrail'",NULL);
#endif
  {
   Ogre::RibbonTrail* tolua_ret = (Ogre::RibbonTrail*)  self->createRibbonTrail(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::RibbonTrail");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createRibbonTrail'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createRibbonTrail of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_createRibbonTrail01
static int tolua_Elementum_Ogre_SceneManager_createRibbonTrail01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createRibbonTrail'",NULL);
#endif
  {
   Ogre::RibbonTrail* tolua_ret = (Ogre::RibbonTrail*)  self->createRibbonTrail();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::RibbonTrail");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_createRibbonTrail00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRibbonTrail of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getRibbonTrail00
static int tolua_Elementum_Ogre_SceneManager_getRibbonTrail00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRibbonTrail'",NULL);
#endif
  {
   Ogre::RibbonTrail* tolua_ret = (Ogre::RibbonTrail*)  self->getRibbonTrail(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::RibbonTrail");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRibbonTrail'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasRibbonTrail of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_hasRibbonTrail00
static int tolua_Elementum_Ogre_SceneManager_hasRibbonTrail00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasRibbonTrail'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasRibbonTrail(name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasRibbonTrail'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyRibbonTrail of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyRibbonTrail00
static int tolua_Elementum_Ogre_SceneManager_destroyRibbonTrail00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::RibbonTrail",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  Ogre::RibbonTrail* obj = ((Ogre::RibbonTrail*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyRibbonTrail'",NULL);
#endif
  {
   self->destroyRibbonTrail(obj);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyRibbonTrail'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyRibbonTrail of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyRibbonTrail01
static int tolua_Elementum_Ogre_SceneManager_destroyRibbonTrail01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyRibbonTrail'",NULL);
#endif
  {
   self->destroyRibbonTrail(name);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_destroyRibbonTrail00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyAllRibbonTrails of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyAllRibbonTrails00
static int tolua_Elementum_Ogre_SceneManager_destroyAllRibbonTrails00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyAllRibbonTrails'",NULL);
#endif
  {
   self->destroyAllRibbonTrails();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyAllRibbonTrails'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createBillboardSet of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_createBillboardSet00
static int tolua_Elementum_Ogre_SceneManager_createBillboardSet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  unsigned int poolSize = ((unsigned int)  tolua_tonumber(tolua_S,3,20));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createBillboardSet'",NULL);
#endif
  {
   Ogre::BillboardSet* tolua_ret = (Ogre::BillboardSet*)  self->createBillboardSet(name,poolSize);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::BillboardSet");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createBillboardSet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createBillboardSet of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_createBillboardSet01
static int tolua_Elementum_Ogre_SceneManager_createBillboardSet01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned int poolSize = ((unsigned int)  tolua_tonumber(tolua_S,2,20));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createBillboardSet'",NULL);
#endif
  {
   Ogre::BillboardSet* tolua_ret = (Ogre::BillboardSet*)  self->createBillboardSet(poolSize);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::BillboardSet");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_createBillboardSet00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBillboardSet of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_getBillboardSet00
static int tolua_Elementum_Ogre_SceneManager_getBillboardSet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBillboardSet'",NULL);
#endif
  {
   Ogre::BillboardSet* tolua_ret = (Ogre::BillboardSet*)  self->getBillboardSet(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::BillboardSet");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBillboardSet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasBillboardSet of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_hasBillboardSet00
static int tolua_Elementum_Ogre_SceneManager_hasBillboardSet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::SceneManager* self = (const Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasBillboardSet'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasBillboardSet(name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasBillboardSet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyBillboardSet of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyBillboardSet00
static int tolua_Elementum_Ogre_SceneManager_destroyBillboardSet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  Ogre::BillboardSet* set = ((Ogre::BillboardSet*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyBillboardSet'",NULL);
#endif
  {
   self->destroyBillboardSet(set);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyBillboardSet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyBillboardSet of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyBillboardSet01
static int tolua_Elementum_Ogre_SceneManager_destroyBillboardSet01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyBillboardSet'",NULL);
#endif
  {
   self->destroyBillboardSet(name);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_SceneManager_destroyBillboardSet00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyAllBillboardSets of class  Ogre::SceneManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_SceneManager_destroyAllBillboardSets00
static int tolua_Elementum_Ogre_SceneManager_destroyAllBillboardSets00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::SceneManager* self = (Ogre::SceneManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyAllBillboardSets'",NULL);
#endif
  {
   self->destroyAllBillboardSets();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyAllBillboardSets'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getActualDimensions of class  Ogre::Viewport */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Viewport_getActualDimensions00
static int tolua_Elementum_Ogre_Viewport_getActualDimensions00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Viewport",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Viewport* self = (const Ogre::Viewport*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActualDimensions'",NULL);
#endif
  {
   self->getActualDimensions(left,top,width,height);
   tolua_pushnumber(tolua_S,(lua_Number)left);
   tolua_pushnumber(tolua_S,(lua_Number)top);
   tolua_pushnumber(tolua_S,(lua_Number)width);
   tolua_pushnumber(tolua_S,(lua_Number)height);
  }
 }
 return 4;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActualDimensions'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCamera of class  Ogre::Viewport */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Viewport_getCamera00
static int tolua_Elementum_Ogre_Viewport_getCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Viewport",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Viewport* self = (const Ogre::Viewport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCamera'",NULL);
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

/* method: setCamera of class  Ogre::Viewport */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Viewport_setCamera00
static int tolua_Elementum_Ogre_Viewport_setCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Viewport",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Viewport* self = (Ogre::Viewport*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Camera* cam = ((Ogre::Camera*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCamera'",NULL);
#endif
  {
   self->setCamera(cam);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLeft of class  Ogre::Viewport */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Viewport_getLeft00
static int tolua_Elementum_Ogre_Viewport_getLeft00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Viewport",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Viewport* self = (const Ogre::Viewport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLeft'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getLeft();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLeft'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTop of class  Ogre::Viewport */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Viewport_getTop00
static int tolua_Elementum_Ogre_Viewport_getTop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Viewport",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Viewport* self = (const Ogre::Viewport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTop'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getTop();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWidth of class  Ogre::Viewport */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Viewport_getWidth00
static int tolua_Elementum_Ogre_Viewport_getWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Viewport",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Viewport* self = (const Ogre::Viewport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidth'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeight of class  Ogre::Viewport */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Viewport_getHeight00
static int tolua_Elementum_Ogre_Viewport_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Viewport",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Viewport* self = (const Ogre::Viewport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getActualLeft of class  Ogre::Viewport */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Viewport_getActualLeft00
static int tolua_Elementum_Ogre_Viewport_getActualLeft00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Viewport",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Viewport* self = (const Ogre::Viewport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActualLeft'",NULL);
#endif
  {
   int tolua_ret = (int)  self->getActualLeft();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActualLeft'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getActualTop of class  Ogre::Viewport */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Viewport_getActualTop00
static int tolua_Elementum_Ogre_Viewport_getActualTop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Viewport",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Viewport* self = (const Ogre::Viewport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActualTop'",NULL);
#endif
  {
   int tolua_ret = (int)  self->getActualTop();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActualTop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getActualWidth of class  Ogre::Viewport */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Viewport_getActualWidth00
static int tolua_Elementum_Ogre_Viewport_getActualWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Viewport",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Viewport* self = (const Ogre::Viewport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActualWidth'",NULL);
#endif
  {
   int tolua_ret = (int)  self->getActualWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActualWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getActualHeight of class  Ogre::Viewport */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Viewport_getActualHeight00
static int tolua_Elementum_Ogre_Viewport_getActualHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Viewport",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Viewport* self = (const Ogre::Viewport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActualHeight'",NULL);
#endif
  {
   int tolua_ret = (int)  self->getActualHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActualHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBackgroundColour of class  Ogre::Viewport */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Viewport_setBackgroundColour00
static int tolua_Elementum_Ogre_Viewport_setBackgroundColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Viewport",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::ColourValue",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Viewport* self = (Ogre::Viewport*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::ColourValue* colour = ((const Ogre::ColourValue*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBackgroundColour'",NULL);
#endif
  {
   self->setBackgroundColour(*colour);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBackgroundColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBackgroundColour of class  Ogre::Viewport */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Viewport_getBackgroundColour00
static int tolua_Elementum_Ogre_Viewport_getBackgroundColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Viewport",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Viewport* self = (const Ogre::Viewport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBackgroundColour'",NULL);
#endif
  {
   const Ogre::ColourValue& tolua_ret = (const Ogre::ColourValue&)  self->getBackgroundColour();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::ColourValue");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBackgroundColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingleton of class  Ogre::MeshManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_MeshManager_getSingleton00
static int tolua_Elementum_Ogre_MeshManager_getSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::MeshManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Ogre::MeshManager& tolua_ret = (Ogre::MeshManager&)  Ogre::MeshManager::getSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Ogre::MeshManager");
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

/* method: createPlane of class  Ogre::MeshManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_MeshManager_createPlane00
static int tolua_Elementum_Ogre_MeshManager_createPlane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::MeshManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Ogre::Plane",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,9,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,12,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,13,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::MeshManager* self = (Ogre::MeshManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string groupName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const Ogre::Plane* plane = ((const Ogre::Plane*)  tolua_tousertype(tolua_S,4,0));
   float width = ((  float)  tolua_tonumber(tolua_S,5,0));
   float height = ((  float)  tolua_tonumber(tolua_S,6,0));
  int xsegments = ((int)  tolua_tonumber(tolua_S,7,1));
  int ysegments = ((int)  tolua_tonumber(tolua_S,8,1));
  bool normals = ((bool)  tolua_toboolean(tolua_S,9,true));
  unsigned short numTexCoordSets = ((unsigned short)  tolua_tonumber(tolua_S,10,1));
   float uTile = ((  float)  tolua_tonumber(tolua_S,11,1.0f));
   float vTile = ((  float)  tolua_tonumber(tolua_S,12,1.0f));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createPlane'",NULL);
#endif
  {
   Ogre::MeshPtr tolua_ret = (Ogre::MeshPtr)  self->createPlane(name,groupName,*plane,width,height,xsegments,ysegments,normals,numTexCoordSets,uTile,vTile);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Ogre::MeshPtr)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::MeshPtr");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ogre::MeshPtr));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::MeshPtr");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createPlane'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createPlane of class  Ogre::MeshManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_MeshManager_createPlane01
static int tolua_Elementum_Ogre_MeshManager_createPlane01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::MeshManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Ogre::Plane",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,13,&tolua_err) || !tolua_isusertype(tolua_S,13,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,14,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::MeshManager* self = (Ogre::MeshManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string groupName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const Ogre::Plane* plane = ((const Ogre::Plane*)  tolua_tousertype(tolua_S,4,0));
   float width = ((  float)  tolua_tonumber(tolua_S,5,0));
   float height = ((  float)  tolua_tonumber(tolua_S,6,0));
  int xsegments = ((int)  tolua_tonumber(tolua_S,7,0));
  int ysegments = ((int)  tolua_tonumber(tolua_S,8,0));
  bool normals = ((bool)  tolua_toboolean(tolua_S,9,0));
  unsigned short numTexCoordSets = ((unsigned short)  tolua_tonumber(tolua_S,10,0));
   float uTile = ((  float)  tolua_tonumber(tolua_S,11,0));
   float vTile = ((  float)  tolua_tonumber(tolua_S,12,0));
  const Ogre::Vector3* upVector = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,13,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createPlane'",NULL);
#endif
  {
   Ogre::MeshPtr tolua_ret = (Ogre::MeshPtr)  self->createPlane(name,groupName,*plane,width,height,xsegments,ysegments,normals,numTexCoordSets,uTile,vTile,*upVector);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Ogre::MeshPtr)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::MeshPtr");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ogre::MeshPtr));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::MeshPtr");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_MeshManager_createPlane00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingleton of class  Ogre::ResourceGroupManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_ResourceGroupManager_getSingleton00
static int tolua_Elementum_Ogre_ResourceGroupManager_getSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::ResourceGroupManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Ogre::ResourceGroupManager& tolua_ret = (Ogre::ResourceGroupManager&)  Ogre::ResourceGroupManager::getSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Ogre::ResourceGroupManager");
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

/* get function: DEFAULT_RESOURCE_GROUP_NAME of class  Ogre::ResourceGroupManager */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__ResourceGroupManager_DEFAULT_RESOURCE_GROUP_NAME
static int tolua_get_Ogre__ResourceGroupManager_DEFAULT_RESOURCE_GROUP_NAME(lua_State* tolua_S)
{
  tolua_pushcppstring(tolua_S,(const char*)Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: DEFAULT_RESOURCE_GROUP_NAME of class  Ogre::ResourceGroupManager */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__ResourceGroupManager_DEFAULT_RESOURCE_GROUP_NAME
static int tolua_set_Ogre__ResourceGroupManager_DEFAULT_RESOURCE_GROUP_NAME(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: INTERNAL_RESOURCE_GROUP_NAME of class  Ogre::ResourceGroupManager */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__ResourceGroupManager_INTERNAL_RESOURCE_GROUP_NAME
static int tolua_get_Ogre__ResourceGroupManager_INTERNAL_RESOURCE_GROUP_NAME(lua_State* tolua_S)
{
  tolua_pushcppstring(tolua_S,(const char*)Ogre::ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: INTERNAL_RESOURCE_GROUP_NAME of class  Ogre::ResourceGroupManager */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__ResourceGroupManager_INTERNAL_RESOURCE_GROUP_NAME
static int tolua_set_Ogre__ResourceGroupManager_INTERNAL_RESOURCE_GROUP_NAME(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Ogre::ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: AUTODETECT_RESOURCE_GROUP_NAME of class  Ogre::ResourceGroupManager */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__ResourceGroupManager_AUTODETECT_RESOURCE_GROUP_NAME
static int tolua_get_Ogre__ResourceGroupManager_AUTODETECT_RESOURCE_GROUP_NAME(lua_State* tolua_S)
{
  tolua_pushcppstring(tolua_S,(const char*)Ogre::ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: AUTODETECT_RESOURCE_GROUP_NAME of class  Ogre::ResourceGroupManager */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__ResourceGroupManager_AUTODETECT_RESOURCE_GROUP_NAME
static int tolua_set_Ogre__ResourceGroupManager_AUTODETECT_RESOURCE_GROUP_NAME(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Ogre::ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS of class  Ogre::ResourceGroupManager */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__ResourceGroupManager_RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS
static int tolua_get_Ogre__ResourceGroupManager_RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Ogre::ResourceGroupManager::RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS,"size_t");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS of class  Ogre::ResourceGroupManager */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__ResourceGroupManager_RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS
static int tolua_set_Ogre__ResourceGroupManager_RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"size_t",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Ogre::ResourceGroupManager::RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS = *((size_t*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  Ogre::ResourceManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_ResourceManager_remove00
static int tolua_Elementum_Ogre_ResourceManager_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::ResourceManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::ResourceManager* self = (Ogre::ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'",NULL);
#endif
  {
   self->remove(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resourceExists of class  Ogre::ResourceManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_ResourceManager_resourceExists00
static int tolua_Elementum_Ogre_ResourceManager_resourceExists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::ResourceManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::ResourceManager* self = (Ogre::ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resourceExists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->resourceExists(name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resourceExists'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: prepare of class  Ogre::ResourceManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_ResourceManager_prepare00
static int tolua_Elementum_Ogre_ResourceManager_prepare00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::ResourceManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::ResourceManager* self = (Ogre::ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string group = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'prepare'",NULL);
#endif
  {
    Ogre::SharedPtr<Ogre::Resource> tolua_ret = (  Ogre::SharedPtr<Ogre::Resource>)  self->prepare(name,group);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Ogre::SharedPtr<Ogre::Resource>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::SharedPtr<Ogre::Resource>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ogre::SharedPtr<Ogre::Resource>));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::SharedPtr<Ogre::Resource>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'prepare'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: load of class  Ogre::ResourceManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_ResourceManager_load00
static int tolua_Elementum_Ogre_ResourceManager_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::ResourceManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::ResourceManager* self = (Ogre::ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string group = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'load'",NULL);
#endif
  {
    Ogre::SharedPtr<Ogre::Resource> tolua_ret = (  Ogre::SharedPtr<Ogre::Resource>)  self->load(name,group);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Ogre::SharedPtr<Ogre::Resource>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::SharedPtr<Ogre::Resource>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ogre::SharedPtr<Ogre::Resource>));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::SharedPtr<Ogre::Resource>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initialise of class  Ogre::CompositorManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_CompositorManager_initialise00
static int tolua_Elementum_Ogre_CompositorManager_initialise00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::CompositorManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::CompositorManager* self = (Ogre::CompositorManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initialise'",NULL);
#endif
  {
   self->initialise();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initialise'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addCompositor of class  Ogre::CompositorManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_CompositorManager_addCompositor00
static int tolua_Elementum_Ogre_CompositorManager_addCompositor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::CompositorManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Viewport",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::CompositorManager* self = (Ogre::CompositorManager*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Viewport* vp = ((Ogre::Viewport*)  tolua_tousertype(tolua_S,2,0));
  const std::string compositor = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  int addPosition = ((int)  tolua_tonumber(tolua_S,4,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addCompositor'",NULL);
#endif
  {
   Ogre::CompositorInstance* tolua_ret = (Ogre::CompositorInstance*)  self->addCompositor(vp,compositor,addPosition);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::CompositorInstance");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addCompositor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeCompositor of class  Ogre::CompositorManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_CompositorManager_removeCompositor00
static int tolua_Elementum_Ogre_CompositorManager_removeCompositor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::CompositorManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Viewport",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::CompositorManager* self = (Ogre::CompositorManager*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Viewport* vp = ((Ogre::Viewport*)  tolua_tousertype(tolua_S,2,0));
  const std::string compositor = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeCompositor'",NULL);
#endif
  {
   self->removeCompositor(vp,compositor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeCompositor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCompositorEnabled of class  Ogre::CompositorManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_CompositorManager_setCompositorEnabled00
static int tolua_Elementum_Ogre_CompositorManager_setCompositorEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::CompositorManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Viewport",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::CompositorManager* self = (Ogre::CompositorManager*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Viewport* vp = ((Ogre::Viewport*)  tolua_tousertype(tolua_S,2,0));
  const std::string compositor = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  bool value = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCompositorEnabled'",NULL);
#endif
  {
   self->setCompositorEnabled(vp,compositor,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCompositorEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: freePooledTextures of class  Ogre::CompositorManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_CompositorManager_freePooledTextures00
static int tolua_Elementum_Ogre_CompositorManager_freePooledTextures00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::CompositorManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::CompositorManager* self = (Ogre::CompositorManager*)  tolua_tousertype(tolua_S,1,0);
  bool onlyIfUnreferenced = ((bool)  tolua_toboolean(tolua_S,2,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'freePooledTextures'",NULL);
#endif
  {
   self->freePooledTextures(onlyIfUnreferenced);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'freePooledTextures'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerCompositorLogic of class  Ogre::CompositorManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_CompositorManager_registerCompositorLogic00
static int tolua_Elementum_Ogre_CompositorManager_registerCompositorLogic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::CompositorManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Ogre::CompositorLogic",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::CompositorManager* self = (Ogre::CompositorManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  Ogre::CompositorLogic* logic = ((Ogre::CompositorLogic*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerCompositorLogic'",NULL);
#endif
  {
   self->registerCompositorLogic(name,logic);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerCompositorLogic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterCompositorLogic of class  Ogre::CompositorManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_CompositorManager_unregisterCompositorLogic00
static int tolua_Elementum_Ogre_CompositorManager_unregisterCompositorLogic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::CompositorManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::CompositorManager* self = (Ogre::CompositorManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterCompositorLogic'",NULL);
#endif
  {
   self->unregisterCompositorLogic(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unregisterCompositorLogic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCompositorLogic of class  Ogre::CompositorManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_CompositorManager_getCompositorLogic00
static int tolua_Elementum_Ogre_CompositorManager_getCompositorLogic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::CompositorManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::CompositorManager* self = (Ogre::CompositorManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCompositorLogic'",NULL);
#endif
  {
   Ogre::CompositorLogic* tolua_ret = (Ogre::CompositorLogic*)  self->getCompositorLogic(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::CompositorLogic");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCompositorLogic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSingleton of class  Ogre::CompositorManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_CompositorManager_getSingleton00
static int tolua_Elementum_Ogre_CompositorManager_getSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::CompositorManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Ogre::CompositorManager& tolua_ret = (Ogre::CompositorManager&)  Ogre::CompositorManager::getSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Ogre::CompositorManager");
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

/* method: getSingletonPtr of class  Ogre::CompositorManager */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_CompositorManager_getSingletonPtr00
static int tolua_Elementum_Ogre_CompositorManager_getSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::CompositorManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Ogre::CompositorManager* tolua_ret = (Ogre::CompositorManager*)  Ogre::CompositorManager::getSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::CompositorManager");
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

/* method: new of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_new00
static int tolua_Elementum_Ogre_BillboardSet_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  unsigned int poolSize = ((unsigned int)  tolua_tonumber(tolua_S,3,20));
  bool externalDataSource = ((bool)  tolua_toboolean(tolua_S,4,false));
  {
   Ogre::BillboardSet* tolua_ret = (Ogre::BillboardSet*)  Mtolua_new((Ogre::BillboardSet)(name,poolSize,externalDataSource));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::BillboardSet");
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

/* method: new_local of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_new00_local
static int tolua_Elementum_Ogre_BillboardSet_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  unsigned int poolSize = ((unsigned int)  tolua_tonumber(tolua_S,3,20));
  bool externalDataSource = ((bool)  tolua_toboolean(tolua_S,4,false));
  {
   Ogre::BillboardSet* tolua_ret = (Ogre::BillboardSet*)  Mtolua_new((Ogre::BillboardSet)(name,poolSize,externalDataSource));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::BillboardSet");
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

/* method: delete of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_delete00
static int tolua_Elementum_Ogre_BillboardSet_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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

/* method: createBillboard of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_createBillboard00
static int tolua_Elementum_Ogre_BillboardSet_createBillboard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* position = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createBillboard'",NULL);
#endif
  {
   Ogre::Billboard* tolua_ret = (Ogre::Billboard*)  self->createBillboard(*position);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Billboard");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createBillboard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createBillboard of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_createBillboard01
static int tolua_Elementum_Ogre_BillboardSet_createBillboard01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Ogre::ColourValue",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* position = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Ogre::ColourValue* colour = ((const Ogre::ColourValue*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createBillboard'",NULL);
#endif
  {
   Ogre::Billboard* tolua_ret = (Ogre::Billboard*)  self->createBillboard(*position,*colour);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Billboard");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_BillboardSet_createBillboard00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createBillboard of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_createBillboard02
static int tolua_Elementum_Ogre_BillboardSet_createBillboard02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createBillboard'",NULL);
#endif
  {
   Ogre::Billboard* tolua_ret = (Ogre::Billboard*)  self->createBillboard(x,y,z);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Billboard");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_BillboardSet_createBillboard01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createBillboard of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_createBillboard03
static int tolua_Elementum_Ogre_BillboardSet_createBillboard03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Ogre::ColourValue",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
  const Ogre::ColourValue* colour = ((const Ogre::ColourValue*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createBillboard'",NULL);
#endif
  {
   Ogre::Billboard* tolua_ret = (Ogre::Billboard*)  self->createBillboard(x,y,z,*colour);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Billboard");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_BillboardSet_createBillboard02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNumBillboards of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_getNumBillboards00
static int tolua_Elementum_Ogre_BillboardSet_getNumBillboards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::BillboardSet* self = (const Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNumBillboards'",NULL);
#endif
  {
   int tolua_ret = (int)  self->getNumBillboards();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNumBillboards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAutoextend of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_setAutoextend00
static int tolua_Elementum_Ogre_BillboardSet_setAutoextend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  bool autoextend = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAutoextend'",NULL);
#endif
  {
   self->setAutoextend(autoextend);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAutoextend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAutoextend of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_getAutoextend00
static int tolua_Elementum_Ogre_BillboardSet_getAutoextend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::BillboardSet* self = (const Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAutoextend'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getAutoextend();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAutoextend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSortingEnabled of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_setSortingEnabled00
static int tolua_Elementum_Ogre_BillboardSet_setSortingEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  bool sortenable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSortingEnabled'",NULL);
#endif
  {
   self->setSortingEnabled(sortenable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSortingEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSortingEnabled of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_getSortingEnabled00
static int tolua_Elementum_Ogre_BillboardSet_getSortingEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::BillboardSet* self = (const Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSortingEnabled'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getSortingEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSortingEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPoolSize of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_setPoolSize00
static int tolua_Elementum_Ogre_BillboardSet_setPoolSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"size_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  size_t size = *((size_t*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPoolSize'",NULL);
#endif
  {
   self->setPoolSize(size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPoolSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPoolSize of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_getPoolSize00
static int tolua_Elementum_Ogre_BillboardSet_getPoolSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::BillboardSet* self = (const Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPoolSize'",NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->getPoolSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPoolSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_clear00
static int tolua_Elementum_Ogre_BillboardSet_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'",NULL);
#endif
  {
   self->clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBillboard of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_getBillboard00
static int tolua_Elementum_Ogre_BillboardSet_getBillboard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::BillboardSet* self = (const Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBillboard'",NULL);
#endif
  {
   Ogre::Billboard* tolua_ret = (Ogre::Billboard*)  self->getBillboard(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Billboard");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBillboard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeBillboard of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_removeBillboard00
static int tolua_Elementum_Ogre_BillboardSet_removeBillboard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeBillboard'",NULL);
#endif
  {
   self->removeBillboard(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeBillboard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeBillboard of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_removeBillboard01
static int tolua_Elementum_Ogre_BillboardSet_removeBillboard01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Billboard* pBill = ((Ogre::Billboard*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeBillboard'",NULL);
#endif
  {
   self->removeBillboard(pBill);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_BillboardSet_removeBillboard00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBillboardOrigin of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_setBillboardOrigin00
static int tolua_Elementum_Ogre_BillboardSet_setBillboardOrigin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  Ogre::BillboardOrigin origin = ((Ogre::BillboardOrigin) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBillboardOrigin'",NULL);
#endif
  {
   self->setBillboardOrigin(origin);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBillboardOrigin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBillboardOrigin of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_getBillboardOrigin00
static int tolua_Elementum_Ogre_BillboardSet_getBillboardOrigin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::BillboardSet* self = (const Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBillboardOrigin'",NULL);
#endif
  {
   Ogre::BillboardOrigin tolua_ret = (Ogre::BillboardOrigin)  self->getBillboardOrigin();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBillboardOrigin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBillboardRotationType of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_setBillboardRotationType00
static int tolua_Elementum_Ogre_BillboardSet_setBillboardRotationType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  Ogre::BillboardRotationType rotationType = ((Ogre::BillboardRotationType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBillboardRotationType'",NULL);
#endif
  {
   self->setBillboardRotationType(rotationType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBillboardRotationType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBillboardRotationType of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_getBillboardRotationType00
static int tolua_Elementum_Ogre_BillboardSet_getBillboardRotationType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::BillboardSet* self = (const Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBillboardRotationType'",NULL);
#endif
  {
   Ogre::BillboardRotationType tolua_ret = (Ogre::BillboardRotationType)  self->getBillboardRotationType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBillboardRotationType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDefaultDimensions of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_setDefaultDimensions00
static int tolua_Elementum_Ogre_BillboardSet_setDefaultDimensions00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
   float width = ((  float)  tolua_tonumber(tolua_S,2,0));
   float height = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDefaultDimensions'",NULL);
#endif
  {
   self->setDefaultDimensions(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDefaultDimensions'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDefaultWidth of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_setDefaultWidth00
static int tolua_Elementum_Ogre_BillboardSet_setDefaultWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
   float width = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDefaultWidth'",NULL);
#endif
  {
   self->setDefaultWidth(width);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDefaultWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDefaultWidth of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_getDefaultWidth00
static int tolua_Elementum_Ogre_BillboardSet_getDefaultWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::BillboardSet* self = (const Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDefaultWidth'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getDefaultWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDefaultWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDefaultHeight of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_setDefaultHeight00
static int tolua_Elementum_Ogre_BillboardSet_setDefaultHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
   float height = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDefaultHeight'",NULL);
#endif
  {
   self->setDefaultHeight(height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDefaultHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDefaultHeight of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_getDefaultHeight00
static int tolua_Elementum_Ogre_BillboardSet_getDefaultHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::BillboardSet* self = (const Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDefaultHeight'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getDefaultHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDefaultHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaterialName of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_setMaterialName00
static int tolua_Elementum_Ogre_BillboardSet_setMaterialName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaterialName'",NULL);
#endif
  {
   self->setMaterialName(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaterialName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaterialName of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_setMaterialName01
static int tolua_Elementum_Ogre_BillboardSet_setMaterialName01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string groupName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaterialName'",NULL);
#endif
  {
   self->setMaterialName(name,groupName);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_BillboardSet_setMaterialName00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaterialName of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_getMaterialName00
static int tolua_Elementum_Ogre_BillboardSet_getMaterialName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::BillboardSet* self = (const Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaterialName'",NULL);
#endif
  {
    const std::string& tolua_ret = (  const std::string&)  self->getMaterialName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaterialName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCullIndividually of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_getCullIndividually00
static int tolua_Elementum_Ogre_BillboardSet_getCullIndividually00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::BillboardSet* self = (const Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCullIndividually'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getCullIndividually();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCullIndividually'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCullIndividually of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_setCullIndividually00
static int tolua_Elementum_Ogre_BillboardSet_setCullIndividually00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  bool cullIndividual = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCullIndividually'",NULL);
#endif
  {
   self->setCullIndividually(cullIndividual);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCullIndividually'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBillboardType of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_setBillboardType00
static int tolua_Elementum_Ogre_BillboardSet_setBillboardType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  Ogre::BillboardType bbt = ((Ogre::BillboardType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBillboardType'",NULL);
#endif
  {
   self->setBillboardType(bbt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBillboardType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBillboardType of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_getBillboardType00
static int tolua_Elementum_Ogre_BillboardSet_getBillboardType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::BillboardSet* self = (const Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBillboardType'",NULL);
#endif
  {
   Ogre::BillboardType tolua_ret = (Ogre::BillboardType)  self->getBillboardType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBillboardType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCommonDirection of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_setCommonDirection00
static int tolua_Elementum_Ogre_BillboardSet_setCommonDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* vec = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCommonDirection'",NULL);
#endif
  {
   self->setCommonDirection(*vec);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCommonDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCommonDirection of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_getCommonDirection00
static int tolua_Elementum_Ogre_BillboardSet_getCommonDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::BillboardSet* self = (const Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCommonDirection'",NULL);
#endif
  {
   const Ogre::Vector3& tolua_ret = (const Ogre::Vector3&)  self->getCommonDirection();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCommonDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCommonUpVector of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_setCommonUpVector00
static int tolua_Elementum_Ogre_BillboardSet_setCommonUpVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::BillboardSet",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* vec = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCommonUpVector'",NULL);
#endif
  {
   self->setCommonUpVector(*vec);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCommonUpVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCommonUpVector of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_BillboardSet_getCommonUpVector00
static int tolua_Elementum_Ogre_BillboardSet_getCommonUpVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::BillboardSet* self = (const Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCommonUpVector'",NULL);
#endif
  {
   const Ogre::Vector3& tolua_ret = (const Ogre::Vector3&)  self->getCommonUpVector();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCommonUpVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __Renderable__ of class  Ogre::BillboardSet */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__BillboardSet___Renderable__
static int tolua_get_Ogre__BillboardSet___Renderable__(lua_State* tolua_S)
{
  Ogre::BillboardSet* self = (Ogre::BillboardSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__Renderable__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<Ogre::Renderable*>(self), "Ogre::Renderable");
#else
   tolua_pushusertype(tolua_S,(void*)((Ogre::Renderable*)self), "Ogre::Renderable");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mPosition of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Billboard_mPosition
static int tolua_get_Ogre__Billboard_mPosition(lua_State* tolua_S)
{
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mPosition'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mPosition,"Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mPosition of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__Billboard_mPosition
static int tolua_set_Ogre__Billboard_mPosition(lua_State* tolua_S)
{
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mPosition'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mPosition = *((Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mDirection of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Billboard_mDirection
static int tolua_get_Ogre__Billboard_mDirection(lua_State* tolua_S)
{
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mDirection'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mDirection,"Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mDirection of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__Billboard_mDirection
static int tolua_set_Ogre__Billboard_mDirection(lua_State* tolua_S)
{
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mDirection'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mDirection = *((Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mParentSet of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Billboard_mParentSet_ptr
static int tolua_get_Ogre__Billboard_mParentSet_ptr(lua_State* tolua_S)
{
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mParentSet'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->mParentSet,"Ogre::BillboardSet");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mParentSet of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__Billboard_mParentSet_ptr
static int tolua_set_Ogre__Billboard_mParentSet_ptr(lua_State* tolua_S)
{
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mParentSet'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Ogre::BillboardSet",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mParentSet = ((Ogre::BillboardSet*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mColour of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Billboard_mColour
static int tolua_get_Ogre__Billboard_mColour(lua_State* tolua_S)
{
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mColour'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mColour,"Ogre::ColourValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mColour of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__Billboard_mColour
static int tolua_set_Ogre__Billboard_mColour(lua_State* tolua_S)
{
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mColour'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::ColourValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mColour = *((Ogre::ColourValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mRotation of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_get_Ogre__Billboard_mRotation
static int tolua_get_Ogre__Billboard_mRotation(lua_State* tolua_S)
{
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mRotation'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mRotation,"Ogre::Radian");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mRotation of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_set_Ogre__Billboard_mRotation
static int tolua_set_Ogre__Billboard_mRotation(lua_State* tolua_S)
{
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mRotation'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::Radian",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mRotation = *((Ogre::Radian*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_new00
static int tolua_Elementum_Ogre_Billboard_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Ogre::Billboard* tolua_ret = (Ogre::Billboard*)  Mtolua_new((Ogre::Billboard)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Billboard");
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

/* method: new_local of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_new00_local
static int tolua_Elementum_Ogre_Billboard_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Ogre::Billboard* tolua_ret = (Ogre::Billboard*)  Mtolua_new((Ogre::Billboard)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Billboard");
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

/* method: delete of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_delete00
static int tolua_Elementum_Ogre_Billboard_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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

/* method: new of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_new01
static int tolua_Elementum_Ogre_Billboard_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::Vector3* position = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  Ogre::BillboardSet* owner = ((Ogre::BillboardSet*)  tolua_tousertype(tolua_S,3,0));
  {
   Ogre::Billboard* tolua_ret = (Ogre::Billboard*)  Mtolua_new((Ogre::Billboard)(*position,owner));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Billboard");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Billboard_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_new01_local
static int tolua_Elementum_Ogre_Billboard_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::Vector3* position = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  Ogre::BillboardSet* owner = ((Ogre::BillboardSet*)  tolua_tousertype(tolua_S,3,0));
  {
   Ogre::Billboard* tolua_ret = (Ogre::Billboard*)  Mtolua_new((Ogre::Billboard)(*position,owner));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Billboard");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Billboard_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_new02
static int tolua_Elementum_Ogre_Billboard_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"Ogre::BillboardSet",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Ogre::ColourValue",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::Vector3* position = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  Ogre::BillboardSet* owner = ((Ogre::BillboardSet*)  tolua_tousertype(tolua_S,3,0));
  const Ogre::ColourValue* colour = ((const Ogre::ColourValue*)  tolua_tousertype(tolua_S,4,0));
  {
   Ogre::Billboard* tolua_ret = (Ogre::Billboard*)  Mtolua_new((Ogre::Billboard)(*position,owner,*colour));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Billboard");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Billboard_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_new02_local
static int tolua_Elementum_Ogre_Billboard_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"Ogre::BillboardSet",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Ogre::ColourValue",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::Vector3* position = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
  Ogre::BillboardSet* owner = ((Ogre::BillboardSet*)  tolua_tousertype(tolua_S,3,0));
  const Ogre::ColourValue* colour = ((const Ogre::ColourValue*)  tolua_tousertype(tolua_S,4,0));
  {
   Ogre::Billboard* tolua_ret = (Ogre::Billboard*)  Mtolua_new((Ogre::Billboard)(*position,owner,*colour));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Billboard");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Billboard_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRotation of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_getRotation00
static int tolua_Elementum_Ogre_Billboard_getRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Billboard* self = (const Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRotation'",NULL);
#endif
  {
   const Ogre::Radian& tolua_ret = (const Ogre::Radian&)  self->getRotation();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Radian");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotation of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_setRotation00
static int tolua_Elementum_Ogre_Billboard_setRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Radian",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Radian* rotation = ((const Ogre::Radian*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotation'",NULL);
#endif
  {
   self->setRotation(*rotation);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_setPosition00
static int tolua_Elementum_Ogre_Billboard_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* position = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'",NULL);
#endif
  {
   self->setPosition(*position);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_setPosition01
static int tolua_Elementum_Ogre_Billboard_setPosition01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'",NULL);
#endif
  {
   self->setPosition(x,y,z);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_Ogre_Billboard_setPosition00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosition of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_getPosition00
static int tolua_Elementum_Ogre_Billboard_getPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Billboard* self = (const Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosition'",NULL);
#endif
  {
   const Ogre::Vector3& tolua_ret = (const Ogre::Vector3&)  self->getPosition();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDimensions of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_setDimensions00
static int tolua_Elementum_Ogre_Billboard_setDimensions00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
   float width = ((  float)  tolua_tonumber(tolua_S,2,0));
   float height = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDimensions'",NULL);
#endif
  {
   self->setDimensions(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDimensions'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetDimensions of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_resetDimensions00
static int tolua_Elementum_Ogre_Billboard_resetDimensions00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetDimensions'",NULL);
#endif
  {
   self->resetDimensions();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetDimensions'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColour of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_setColour00
static int tolua_Elementum_Ogre_Billboard_setColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::ColourValue",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::ColourValue* colour = ((const Ogre::ColourValue*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColour'",NULL);
#endif
  {
   self->setColour(*colour);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColour of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_getColour00
static int tolua_Elementum_Ogre_Billboard_getColour00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Billboard* self = (const Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColour'",NULL);
#endif
  {
   const Ogre::ColourValue& tolua_ret = (const Ogre::ColourValue&)  self->getColour();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::ColourValue");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColour'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasOwnDimensions of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_hasOwnDimensions00
static int tolua_Elementum_Ogre_Billboard_hasOwnDimensions00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Billboard* self = (const Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasOwnDimensions'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasOwnDimensions();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasOwnDimensions'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOwnWidth of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_getOwnWidth00
static int tolua_Elementum_Ogre_Billboard_getOwnWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Billboard* self = (const Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOwnWidth'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getOwnWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOwnWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOwnHeight of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_getOwnHeight00
static int tolua_Elementum_Ogre_Billboard_getOwnHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Billboard* self = (const Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOwnHeight'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getOwnHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOwnHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: _notifyOwner of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard__notifyOwner00
static int tolua_Elementum_Ogre_Billboard__notifyOwner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::BillboardSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
  Ogre::BillboardSet* owner = ((Ogre::BillboardSet*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '_notifyOwner'",NULL);
#endif
  {
   self->_notifyOwner(owner);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '_notifyOwner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isUseTexcoordRect of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_isUseTexcoordRect00
static int tolua_Elementum_Ogre_Billboard_isUseTexcoordRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Billboard* self = (const Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isUseTexcoordRect'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isUseTexcoordRect();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isUseTexcoordRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTexcoordIndex of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_setTexcoordIndex00
static int tolua_Elementum_Ogre_Billboard_setTexcoordIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::uint16",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
  Ogre::uint16 texcoordIndex = *((Ogre::uint16*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexcoordIndex'",NULL);
#endif
  {
   self->setTexcoordIndex(texcoordIndex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTexcoordIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTexcoordIndex of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_getTexcoordIndex00
static int tolua_Elementum_Ogre_Billboard_getTexcoordIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Billboard* self = (const Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTexcoordIndex'",NULL);
#endif
  {
   Ogre::uint16 tolua_ret = (Ogre::uint16)  self->getTexcoordIndex();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Ogre::uint16)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::uint16");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Ogre::uint16));
     tolua_pushusertype(tolua_S,tolua_obj,"Ogre::uint16");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTexcoordIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTexcoordRect of class  Ogre::Billboard */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Billboard_setTexcoordRect00
static int tolua_Elementum_Ogre_Billboard_setTexcoordRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Billboard",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Billboard* self = (Ogre::Billboard*)  tolua_tousertype(tolua_S,1,0);
   float u0 = ((  float)  tolua_tonumber(tolua_S,2,0));
   float v0 = ((  float)  tolua_tonumber(tolua_S,3,0));
   float u1 = ((  float)  tolua_tonumber(tolua_S,4,0));
   float v1 = ((  float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexcoordRect'",NULL);
#endif
  {
   self->setTexcoordRect(u0,v0,u1,v1);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTexcoordRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  OgreBites::SdkCameraMan */
#ifndef TOLUA_DISABLE_tolua_Elementum_OgreBites_SdkCameraMan_new00
static int tolua_Elementum_OgreBites_SdkCameraMan_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"OgreBites::SdkCameraMan",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* cam = ((Ogre::Camera*)  tolua_tousertype(tolua_S,2,0));
  {
   OgreBites::SdkCameraMan* tolua_ret = (OgreBites::SdkCameraMan*)  Mtolua_new((OgreBites::SdkCameraMan)(cam));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OgreBites::SdkCameraMan");
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

/* method: new_local of class  OgreBites::SdkCameraMan */
#ifndef TOLUA_DISABLE_tolua_Elementum_OgreBites_SdkCameraMan_new00_local
static int tolua_Elementum_OgreBites_SdkCameraMan_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"OgreBites::SdkCameraMan",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Camera* cam = ((Ogre::Camera*)  tolua_tousertype(tolua_S,2,0));
  {
   OgreBites::SdkCameraMan* tolua_ret = (OgreBites::SdkCameraMan*)  Mtolua_new((OgreBites::SdkCameraMan)(cam));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OgreBites::SdkCameraMan");
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

/* method: setCamera of class  OgreBites::SdkCameraMan */
#ifndef TOLUA_DISABLE_tolua_Elementum_OgreBites_SdkCameraMan_setCamera00
static int tolua_Elementum_OgreBites_SdkCameraMan_setCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OgreBites::SdkCameraMan",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OgreBites::SdkCameraMan* self = (OgreBites::SdkCameraMan*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Camera* cam = ((Ogre::Camera*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCamera'",NULL);
#endif
  {
   self->setCamera(cam);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCamera of class  OgreBites::SdkCameraMan */
#ifndef TOLUA_DISABLE_tolua_Elementum_OgreBites_SdkCameraMan_getCamera00
static int tolua_Elementum_OgreBites_SdkCameraMan_getCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OgreBites::SdkCameraMan",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OgreBites::SdkCameraMan* self = (OgreBites::SdkCameraMan*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCamera'",NULL);
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

/* method: setTarget of class  OgreBites::SdkCameraMan */
#ifndef TOLUA_DISABLE_tolua_Elementum_OgreBites_SdkCameraMan_setTarget00
static int tolua_Elementum_OgreBites_SdkCameraMan_setTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OgreBites::SdkCameraMan",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::SceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OgreBites::SdkCameraMan* self = (OgreBites::SdkCameraMan*)  tolua_tousertype(tolua_S,1,0);
  Ogre::SceneNode* target = ((Ogre::SceneNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTarget'",NULL);
#endif
  {
   self->setTarget(target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTarget of class  OgreBites::SdkCameraMan */
#ifndef TOLUA_DISABLE_tolua_Elementum_OgreBites_SdkCameraMan_getTarget00
static int tolua_Elementum_OgreBites_SdkCameraMan_getTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OgreBites::SdkCameraMan",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OgreBites::SdkCameraMan* self = (OgreBites::SdkCameraMan*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTarget'",NULL);
#endif
  {
   Ogre::SceneNode* tolua_ret = (Ogre::SceneNode*)  self->getTarget();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setYawPitchDist of class  OgreBites::SdkCameraMan */
#ifndef TOLUA_DISABLE_tolua_Elementum_OgreBites_SdkCameraMan_setYawPitchDist00
static int tolua_Elementum_OgreBites_SdkCameraMan_setYawPitchDist00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OgreBites::SdkCameraMan",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::Radian",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Ogre::Radian",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OgreBites::SdkCameraMan* self = (OgreBites::SdkCameraMan*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Radian yaw = *((Ogre::Radian*)  tolua_tousertype(tolua_S,2,0));
  Ogre::Radian pitch = *((Ogre::Radian*)  tolua_tousertype(tolua_S,3,0));
   float dist = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setYawPitchDist'",NULL);
#endif
  {
   self->setYawPitchDist(yaw,pitch,dist);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setYawPitchDist'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setYawPitchDist of class  OgreBites::SdkCameraMan */
#ifndef TOLUA_DISABLE_tolua_Elementum_OgreBites_SdkCameraMan_setYawPitchDist01
static int tolua_Elementum_OgreBites_SdkCameraMan_setYawPitchDist01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OgreBites::SdkCameraMan",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::Degree",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Ogre::Degree",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  OgreBites::SdkCameraMan* self = (OgreBites::SdkCameraMan*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Degree yaw = *((Ogre::Degree*)  tolua_tousertype(tolua_S,2,0));
  Ogre::Degree pitch = *((Ogre::Degree*)  tolua_tousertype(tolua_S,3,0));
   float dist = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setYawPitchDist'",NULL);
#endif
  {
   self->setYawPitchDist(yaw,pitch,dist);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_OgreBites_SdkCameraMan_setYawPitchDist00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTopSpeed of class  OgreBites::SdkCameraMan */
#ifndef TOLUA_DISABLE_tolua_Elementum_OgreBites_SdkCameraMan_setTopSpeed00
static int tolua_Elementum_OgreBites_SdkCameraMan_setTopSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OgreBites::SdkCameraMan",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OgreBites::SdkCameraMan* self = (OgreBites::SdkCameraMan*)  tolua_tousertype(tolua_S,1,0);
   float topSpeed = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTopSpeed'",NULL);
#endif
  {
   self->setTopSpeed(topSpeed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTopSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTopSpeed of class  OgreBites::SdkCameraMan */
#ifndef TOLUA_DISABLE_tolua_Elementum_OgreBites_SdkCameraMan_getTopSpeed00
static int tolua_Elementum_OgreBites_SdkCameraMan_getTopSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OgreBites::SdkCameraMan",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OgreBites::SdkCameraMan* self = (OgreBites::SdkCameraMan*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTopSpeed'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getTopSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTopSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setStyle of class  OgreBites::SdkCameraMan */
#ifndef TOLUA_DISABLE_tolua_Elementum_OgreBites_SdkCameraMan_setStyle00
static int tolua_Elementum_OgreBites_SdkCameraMan_setStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OgreBites::SdkCameraMan",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OgreBites::SdkCameraMan* self = (OgreBites::SdkCameraMan*)  tolua_tousertype(tolua_S,1,0);
  OgreBites::CameraStyle style = ((OgreBites::CameraStyle) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStyle'",NULL);
#endif
  {
   self->setStyle(style);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStyle of class  OgreBites::SdkCameraMan */
#ifndef TOLUA_DISABLE_tolua_Elementum_OgreBites_SdkCameraMan_getStyle00
static int tolua_Elementum_OgreBites_SdkCameraMan_getStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OgreBites::SdkCameraMan",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OgreBites::SdkCameraMan* self = (OgreBites::SdkCameraMan*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStyle'",NULL);
#endif
  {
   OgreBites::CameraStyle tolua_ret = (OgreBites::CameraStyle)  self->getStyle();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: manualStop of class  OgreBites::SdkCameraMan */
#ifndef TOLUA_DISABLE_tolua_Elementum_OgreBites_SdkCameraMan_manualStop00
static int tolua_Elementum_OgreBites_SdkCameraMan_manualStop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"OgreBites::SdkCameraMan",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  OgreBites::SdkCameraMan* self = (OgreBites::SdkCameraMan*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'manualStop'",NULL);
#endif
  {
   self->manualStop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'manualStop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Ogre::Any */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Any_new00
static int tolua_Elementum_Ogre_Any_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Any",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Ogre::Any* tolua_ret = (Ogre::Any*)  Mtolua_new((Ogre::Any)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Any");
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

/* method: new_local of class  Ogre::Any */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Any_new00_local
static int tolua_Elementum_Ogre_Any_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Any",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Ogre::Any* tolua_ret = (Ogre::Any*)  Mtolua_new((Ogre::Any)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Any");
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

/* method: new of class  Ogre::Any */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Any_new01
static int tolua_Elementum_Ogre_Any_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Any",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Any",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::Any* other = ((const Ogre::Any*)  tolua_tousertype(tolua_S,2,0));
  {
   Ogre::Any* tolua_ret = (Ogre::Any*)  Mtolua_new((Ogre::Any)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Any");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Any_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Ogre::Any */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Any_new01_local
static int tolua_Elementum_Ogre_Any_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Ogre::Any",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Any",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Ogre::Any* other = ((const Ogre::Any*)  tolua_tousertype(tolua_S,2,0));
  {
   Ogre::Any* tolua_ret = (Ogre::Any*)  Mtolua_new((Ogre::Any)(*other));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Any");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_Ogre_Any_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Ogre::Any */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Any_delete00
static int tolua_Elementum_Ogre_Any_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Any",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Any* self = (Ogre::Any*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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

/* method: isEmpty of class  Ogre::Any */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Any_isEmpty00
static int tolua_Elementum_Ogre_Any_isEmpty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Any",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Any* self = (const Ogre::Any*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isEmpty'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isEmpty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isEmpty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getType of class  Ogre::Any */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Any_getType00
static int tolua_Elementum_Ogre_Any_getType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Ogre::Any",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Ogre::Any* self = (const Ogre::Any*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getType'",NULL);
#endif
  {
   const std::type_info& tolua_ret = (const std::type_info&)  self->getType();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::type_info");
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

/* method: destroy of class  Ogre::Any */
#ifndef TOLUA_DISABLE_tolua_Elementum_Ogre_Any_destroy00
static int tolua_Elementum_Ogre_Any_destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Ogre::Any",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Ogre::Any* self = (Ogre::Any*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroy'",NULL);
#endif
  {
   self->destroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: key of class  OIS::KeyEvent */
#ifndef TOLUA_DISABLE_tolua_get_OIS__KeyEvent_key
static int tolua_get_OIS__KeyEvent_key(lua_State* tolua_S)
{
  OIS::KeyEvent* self = (OIS::KeyEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'key'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->key);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: text of class  OIS::KeyEvent */
#ifndef TOLUA_DISABLE_tolua_get_OIS__KeyEvent_unsigned_text
static int tolua_get_OIS__KeyEvent_unsigned_text(lua_State* tolua_S)
{
  OIS::KeyEvent* self = (OIS::KeyEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'text'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->text);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: text of class  OIS::KeyEvent */
#ifndef TOLUA_DISABLE_tolua_set_OIS__KeyEvent_unsigned_text
static int tolua_set_OIS__KeyEvent_unsigned_text(lua_State* tolua_S)
{
  OIS::KeyEvent* self = (OIS::KeyEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'text'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->text = ((unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFormatting'",NULL);
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFormatting'",NULL);
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

/* get function: DEFAULT_KEEP_LOCAL of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_KEEP_LOCAL
static int tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_KEEP_LOCAL(lua_State* tolua_S)
{
  tolua_pushboolean(tolua_S,(bool)ParticleUniverse::ParticleSystem::DEFAULT_KEEP_LOCAL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_ITERATION_INTERVAL of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_ITERATION_INTERVAL
static int tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_ITERATION_INTERVAL(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)ParticleUniverse::ParticleSystem::DEFAULT_ITERATION_INTERVAL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_FIXED_TIMEOUT of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_FIXED_TIMEOUT
static int tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_FIXED_TIMEOUT(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)ParticleUniverse::ParticleSystem::DEFAULT_FIXED_TIMEOUT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_NON_VISIBLE_UPDATE_TIMEOUT of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_NON_VISIBLE_UPDATE_TIMEOUT
static int tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_NON_VISIBLE_UPDATE_TIMEOUT(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)ParticleUniverse::ParticleSystem::DEFAULT_NON_VISIBLE_UPDATE_TIMEOUT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_SMOOTH_LOD of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_SMOOTH_LOD
static int tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_SMOOTH_LOD(lua_State* tolua_S)
{
  tolua_pushboolean(tolua_S,(bool)ParticleUniverse::ParticleSystem::DEFAULT_SMOOTH_LOD);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_FAST_FORWARD_TIME of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_FAST_FORWARD_TIME
static int tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_FAST_FORWARD_TIME(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)ParticleUniverse::ParticleSystem::DEFAULT_FAST_FORWARD_TIME);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_MAIN_CAMERA_NAME of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_MAIN_CAMERA_NAME
static int tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_MAIN_CAMERA_NAME(lua_State* tolua_S)
{
  tolua_pushstring(tolua_S,(const char*)ParticleUniverse::ParticleSystem::DEFAULT_MAIN_CAMERA_NAME);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_SCALE_VELOCITY of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_SCALE_VELOCITY
static int tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_SCALE_VELOCITY(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)ParticleUniverse::ParticleSystem::DEFAULT_SCALE_VELOCITY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_SCALE_TIME of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_SCALE_TIME
static int tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_SCALE_TIME(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)ParticleUniverse::ParticleSystem::DEFAULT_SCALE_TIME);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_SCALE of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_SCALE
static int tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_SCALE(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ParticleUniverse::ParticleSystem::DEFAULT_SCALE,"const Ogre::Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_TIGHT_BOUNDINGBOX of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_TIGHT_BOUNDINGBOX
static int tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_TIGHT_BOUNDINGBOX(lua_State* tolua_S)
{
  tolua_pushboolean(tolua_S,(bool)ParticleUniverse::ParticleSystem::DEFAULT_TIGHT_BOUNDINGBOX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_new00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   ParticleUniverse::ParticleSystem* tolua_ret = (ParticleUniverse::ParticleSystem*)  Mtolua_new((ParticleUniverse::ParticleSystem)(name));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleUniverse::ParticleSystem");
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

/* method: new_local of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_new00_local
static int tolua_Elementum_ParticleUniverse_ParticleSystem_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   ParticleUniverse::ParticleSystem* tolua_ret = (ParticleUniverse::ParticleSystem*)  Mtolua_new((ParticleUniverse::ParticleSystem)(name));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleUniverse::ParticleSystem");
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

/* method: new of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_new01
static int tolua_Elementum_ParticleUniverse_ParticleSystem_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string resourceGroupName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  {
   ParticleUniverse::ParticleSystem* tolua_ret = (ParticleUniverse::ParticleSystem*)  Mtolua_new((ParticleUniverse::ParticleSystem)(name,resourceGroupName));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleUniverse::ParticleSystem");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_ParticleUniverse_ParticleSystem_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_new01_local
static int tolua_Elementum_ParticleUniverse_ParticleSystem_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string resourceGroupName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  {
   ParticleUniverse::ParticleSystem* tolua_ret = (ParticleUniverse::ParticleSystem*)  Mtolua_new((ParticleUniverse::ParticleSystem)(name,resourceGroupName));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleUniverse::ParticleSystem");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Elementum_ParticleUniverse_ParticleSystem_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_delete00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
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

/* method: getDerivedPosition of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getDerivedPosition00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getDerivedPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDerivedPosition'",NULL);
#endif
  {
   const Ogre::Vector3& tolua_ret = (const Ogre::Vector3&)  self->getDerivedPosition();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDerivedPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDerivedOrientation of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getDerivedOrientation00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getDerivedOrientation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDerivedOrientation'",NULL);
#endif
  {
   const Ogre::Quaternion& tolua_ret = (const Ogre::Quaternion&)  self->getDerivedOrientation();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Quaternion");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDerivedOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLatestOrientation of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getLatestOrientation00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getLatestOrientation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLatestOrientation'",NULL);
#endif
  {
   const Ogre::Quaternion& tolua_ret = (const Ogre::Quaternion&)  self->getLatestOrientation();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Quaternion");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLatestOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasRotatedBetweenUpdates of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_hasRotatedBetweenUpdates00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_hasRotatedBetweenUpdates00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasRotatedBetweenUpdates'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasRotatedBetweenUpdates();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasRotatedBetweenUpdates'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotationOffset of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_rotationOffset00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_rotationOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Vector3* pos = ((Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotationOffset'",NULL);
#endif
  {
   self->rotationOffset(*pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotationOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isSmoothLod of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_isSmoothLod00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_isSmoothLod00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isSmoothLod'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isSmoothLod();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isSmoothLod'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSmoothLod of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setSmoothLod00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setSmoothLod00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  bool smoothLod = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSmoothLod'",NULL);
#endif
  {
   self->setSmoothLod(smoothLod);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSmoothLod'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTimeElapsedSinceStart of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getTimeElapsedSinceStart00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getTimeElapsedSinceStart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTimeElapsedSinceStart'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getTimeElapsedSinceStart();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTimeElapsedSinceStart'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResourceGroupName of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getResourceGroupName00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getResourceGroupName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getResourceGroupName'",NULL);
#endif
  {
    const std::string tolua_ret = (  const std::string)  self->getResourceGroupName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResourceGroupName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setResourceGroupName of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setResourceGroupName00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setResourceGroupName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  const std::string resourceGroupName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setResourceGroupName'",NULL);
#endif
  {
   self->setResourceGroupName(resourceGroupName);
   tolua_pushcppstring(tolua_S,(const char*)resourceGroupName);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setResourceGroupName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createTechnique of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_createTechnique00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_createTechnique00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createTechnique'",NULL);
#endif
  {
   ParticleUniverse::ParticleTechnique* tolua_ret = (ParticleUniverse::ParticleTechnique*)  self->createTechnique();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleUniverse::ParticleTechnique");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createTechnique'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addTechnique of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_addTechnique00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_addTechnique00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ParticleUniverse::ParticleTechnique",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  ParticleUniverse::ParticleTechnique* technique = ((ParticleUniverse::ParticleTechnique*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addTechnique'",NULL);
#endif
  {
   self->addTechnique(technique);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addTechnique'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeTechnique of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_removeTechnique00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_removeTechnique00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ParticleUniverse::ParticleTechnique",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  ParticleUniverse::ParticleTechnique* technique = ((ParticleUniverse::ParticleTechnique*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeTechnique'",NULL);
#endif
  {
   self->removeTechnique(technique);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeTechnique'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTechnique of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getTechnique00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getTechnique00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"size_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  size_t index = *((size_t*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTechnique'",NULL);
#endif
  {
   ParticleUniverse::ParticleTechnique* tolua_ret = (ParticleUniverse::ParticleTechnique*)  self->getTechnique(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleUniverse::ParticleTechnique");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTechnique'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTechnique of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getTechnique01
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getTechnique01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTechnique'",NULL);
#endif
  {
   ParticleUniverse::ParticleTechnique* tolua_ret = (ParticleUniverse::ParticleTechnique*)  self->getTechnique(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleUniverse::ParticleTechnique");
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 2;
tolua_lerror:
 return tolua_Elementum_ParticleUniverse_ParticleSystem_getTechnique00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNumTechniques of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getNumTechniques00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getNumTechniques00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNumTechniques'",NULL);
#endif
  {
   size_t tolua_ret = (size_t)  self->getNumTechniques();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((size_t)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"size_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(size_t));
     tolua_pushusertype(tolua_S,tolua_obj,"size_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNumTechniques'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyTechnique of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_destroyTechnique00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_destroyTechnique00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ParticleUniverse::ParticleTechnique",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  ParticleUniverse::ParticleTechnique* particleTechnique = ((ParticleUniverse::ParticleTechnique*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyTechnique'",NULL);
#endif
  {
   self->destroyTechnique(particleTechnique);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyTechnique'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyTechnique of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_destroyTechnique01
static int tolua_Elementum_ParticleUniverse_ParticleSystem_destroyTechnique01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"size_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  size_t index = *((size_t*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyTechnique'",NULL);
#endif
  {
   self->destroyTechnique(index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_ParticleUniverse_ParticleSystem_destroyTechnique00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroyAllTechniques of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_destroyAllTechniques00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_destroyAllTechniques00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroyAllTechniques'",NULL);
#endif
  {
   self->destroyAllTechniques();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroyAllTechniques'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRenderQueueGroup of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setRenderQueueGroup00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setRenderQueueGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
   int queueId = ((  int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRenderQueueGroup'",NULL);
#endif
  {
   self->setRenderQueueGroup(queueId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRenderQueueGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNonVisibleUpdateTimeout of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getNonVisibleUpdateTimeout00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getNonVisibleUpdateTimeout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNonVisibleUpdateTimeout'",NULL);
#endif
  {
    const float tolua_ret = (  const float)  self->getNonVisibleUpdateTimeout();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNonVisibleUpdateTimeout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setNonVisibleUpdateTimeout of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setNonVisibleUpdateTimeout00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setNonVisibleUpdateTimeout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
   float timeout = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setNonVisibleUpdateTimeout'",NULL);
#endif
  {
   self->setNonVisibleUpdateTimeout(timeout);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNonVisibleUpdateTimeout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: prepare of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_prepare00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_prepare00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'prepare'",NULL);
#endif
  {
   self->prepare();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'prepare'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_start00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'",NULL);
#endif
  {
   self->start();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_start01
static int tolua_Elementum_ParticleUniverse_ParticleSystem_start01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
   float stopTime = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'",NULL);
#endif
  {
   self->start(stopTime);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_ParticleUniverse_ParticleSystem_start00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: startAndStopFade of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_startAndStopFade00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_startAndStopFade00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
   float stopTime = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'startAndStopFade'",NULL);
#endif
  {
   self->startAndStopFade(stopTime);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'startAndStopFade'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_stop00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'",NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_stop01
static int tolua_Elementum_ParticleUniverse_ParticleSystem_stop01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
   float stopTime = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'",NULL);
#endif
  {
   self->stop(stopTime);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_ParticleUniverse_ParticleSystem_stop00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopFade of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_stopFade00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_stopFade00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopFade'",NULL);
#endif
  {
   self->stopFade();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopFade'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopFade of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_stopFade01
static int tolua_Elementum_ParticleUniverse_ParticleSystem_stopFade01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
   float stopTime = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopFade'",NULL);
#endif
  {
   self->stopFade(stopTime);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_ParticleUniverse_ParticleSystem_stopFade00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: pause of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_pause00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_pause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pause'",NULL);
#endif
  {
   self->pause();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pause of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_pause01
static int tolua_Elementum_ParticleUniverse_ParticleSystem_pause01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
   float pauseTime = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pause'",NULL);
#endif
  {
   self->pause(pauseTime);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Elementum_ParticleUniverse_ParticleSystem_pause00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: resume of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_resume00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_resume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resume'",NULL);
#endif
  {
   self->resume();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getState of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getState00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getState'",NULL);
#endif
  {
   ParticleUniverse::ParticleSystem::ParticleSystemState tolua_ret = (ParticleUniverse::ParticleSystem::ParticleSystemState)  self->getState();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFastForwardTime of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getFastForwardTime00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getFastForwardTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFastForwardTime'",NULL);
#endif
  {
    const float tolua_ret = (  const float)  self->getFastForwardTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFastForwardTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFastForwardInterval of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getFastForwardInterval00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getFastForwardInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFastForwardInterval'",NULL);
#endif
  {
    const float tolua_ret = (  const float)  self->getFastForwardInterval();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFastForwardInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFastForward of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setFastForward00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setFastForward00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
   float time = ((  float)  tolua_tonumber(tolua_S,2,0));
   float interval = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFastForward'",NULL);
#endif
  {
   self->setFastForward(time,interval);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFastForward'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMainCameraName of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getMainCameraName00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getMainCameraName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMainCameraName'",NULL);
#endif
  {
    const std::string tolua_ret = (  const std::string)  self->getMainCameraName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMainCameraName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMainCamera of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getMainCamera00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getMainCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMainCamera'",NULL);
#endif
  {
   Ogre::Camera* tolua_ret = (Ogre::Camera*)  self->getMainCamera();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Camera");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMainCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasMainCamera of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_hasMainCamera00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_hasMainCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasMainCamera'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasMainCamera();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasMainCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMainCameraName of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setMainCameraName00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setMainCameraName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
   std::string cameraName = ((  std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMainCameraName'",NULL);
#endif
  {
   self->setMainCameraName(cameraName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMainCameraName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMainCamera of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setMainCamera00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setMainCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  Ogre::Camera* camera = ((Ogre::Camera*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMainCamera'",NULL);
#endif
  {
   self->setMainCamera(camera);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMainCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentCamera of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getCurrentCamera00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getCurrentCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentCamera'",NULL);
#endif
  {
   Ogre::Camera* tolua_ret = (Ogre::Camera*)  self->getCurrentCamera();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::Camera");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fastForward of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_fastForward00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_fastForward00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fastForward'",NULL);
#endif
  {
   self->fastForward();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fastForward'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNumEmittedTechniques of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getNumEmittedTechniques00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getNumEmittedTechniques00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNumEmittedTechniques'",NULL);
#endif
  {
   size_t tolua_ret = (size_t)  self->getNumEmittedTechniques();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((size_t)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"size_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(size_t));
     tolua_pushusertype(tolua_S,tolua_obj,"size_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNumEmittedTechniques'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: _markForEmission of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem__markForEmission00
static int tolua_Elementum_ParticleUniverse_ParticleSystem__markForEmission00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '_markForEmission'",NULL);
#endif
  {
   self->_markForEmission();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '_markForEmission'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: _resetMarkForEmission of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem__resetMarkForEmission00
static int tolua_Elementum_ParticleUniverse_ParticleSystem__resetMarkForEmission00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '_resetMarkForEmission'",NULL);
#endif
  {
   self->_resetMarkForEmission();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '_resetMarkForEmission'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: suppressNotifyEmissionChange of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_suppressNotifyEmissionChange00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_suppressNotifyEmissionChange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  bool suppress = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'suppressNotifyEmissionChange'",NULL);
#endif
  {
   self->suppressNotifyEmissionChange(suppress);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'suppressNotifyEmissionChange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: _notifyEmissionChange of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem__notifyEmissionChange00
static int tolua_Elementum_ParticleUniverse_ParticleSystem__notifyEmissionChange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '_notifyEmissionChange'",NULL);
#endif
  {
   self->_notifyEmissionChange();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '_notifyEmissionChange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIterationInterval of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getIterationInterval00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getIterationInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIterationInterval'",NULL);
#endif
  {
    const float tolua_ret = (  const float)  self->getIterationInterval();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIterationInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIterationInterval of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setIterationInterval00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setIterationInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  const float iterationInterval = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIterationInterval'",NULL);
#endif
  {
   self->setIterationInterval(iterationInterval);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIterationInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFixedTimeout of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getFixedTimeout00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getFixedTimeout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFixedTimeout'",NULL);
#endif
  {
    const float tolua_ret = (  const float)  self->getFixedTimeout();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFixedTimeout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFixedTimeout of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setFixedTimeout00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setFixedTimeout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  const float fixedTimeout = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFixedTimeout'",NULL);
#endif
  {
   self->setFixedTimeout(fixedTimeout);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFixedTimeout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBoundsAutoUpdated of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setBoundsAutoUpdated00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setBoundsAutoUpdated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  bool autoUpdate = ((bool)  tolua_toboolean(tolua_S,2,0));
   float stopIn = ((  float)  tolua_tonumber(tolua_S,3,0.0f));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBoundsAutoUpdated'",NULL);
#endif
  {
   self->setBoundsAutoUpdated(autoUpdate,stopIn);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBoundsAutoUpdated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: _resetBounds of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem__resetBounds00
static int tolua_Elementum_ParticleUniverse_ParticleSystem__resetBounds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function '_resetBounds'",NULL);
#endif
  {
   self->_resetBounds();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '_resetBounds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScale of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getScale00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScale'",NULL);
#endif
  {
   const Ogre::Vector3& tolua_ret = (const Ogre::Vector3&)  self->getScale();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Ogre::Vector3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setScale00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::Vector3* scale = ((const Ogre::Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'",NULL);
#endif
  {
   self->setScale(*scale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScaleVelocity of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getScaleVelocity00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getScaleVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScaleVelocity'",NULL);
#endif
  {
    const float tolua_ret = (  const float)  self->getScaleVelocity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScaleVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScaleVelocity of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setScaleVelocity00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setScaleVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  const float scaleVelocity = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScaleVelocity'",NULL);
#endif
  {
   self->setScaleVelocity(scaleVelocity);
   tolua_pushnumber(tolua_S,(lua_Number)scaleVelocity);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScaleVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScaleTime of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getScaleTime00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getScaleTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScaleTime'",NULL);
#endif
  {
    const float tolua_ret = (  const float)  self->getScaleTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScaleTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScaleTime of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setScaleTime00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setScaleTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  const float scaleTime = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScaleTime'",NULL);
#endif
  {
   self->setScaleTime(scaleTime);
   tolua_pushnumber(tolua_S,(lua_Number)scaleTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScaleTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isKeepLocal of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_isKeepLocal00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_isKeepLocal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isKeepLocal'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isKeepLocal();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isKeepLocal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setKeepLocal of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setKeepLocal00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setKeepLocal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  bool keepLocal = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setKeepLocal'",NULL);
#endif
  {
   self->setKeepLocal(keepLocal);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setKeepLocal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasTightBoundingBox of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_hasTightBoundingBox00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_hasTightBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasTightBoundingBox'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasTightBoundingBox();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasTightBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTightBoundingBox of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setTightBoundingBox00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setTightBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  bool tightBoundingBox = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTightBoundingBox'",NULL);
#endif
  {
   self->setTightBoundingBox(tightBoundingBox);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTightBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPauseTime of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getPauseTime00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getPauseTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPauseTime'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->getPauseTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPauseTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPauseTime of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setPauseTime00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setPauseTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
   float pauseTime = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPauseTime'",NULL);
#endif
  {
   self->setPauseTime(pauseTime);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPauseTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEnabled of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setEnabled00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEnabled'",NULL);
#endif
  {
   self->setEnabled(enabled);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSceneManager of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getSceneManager00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getSceneManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSceneManager'",NULL);
#endif
  {
   Ogre::SceneManager* tolua_ret = (Ogre::SceneManager*)  self->getSceneManager();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ogre::SceneManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSceneManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSceneManager of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setSceneManager00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setSceneManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ogre::SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  Ogre::SceneManager* sceneManager = ((Ogre::SceneManager*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSceneManager'",NULL);
#endif
  {
   self->setSceneManager(sceneManager);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSceneManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setUseController of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setUseController00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setUseController00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  bool useController = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setUseController'",NULL);
#endif
  {
   self->setUseController(useController);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setUseController'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasExternType of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_hasExternType00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_hasExternType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  const std::string externType = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasExternType'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasExternType(externType);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)externType);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasExternType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCategory of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_getCategory00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_getCategory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleUniverse::ParticleSystem* self = (const ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCategory'",NULL);
#endif
  {
    const std::string tolua_ret = (  const std::string)  self->getCategory();
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

/* method: setCategory of class  ParticleUniverse::ParticleSystem */
#ifndef TOLUA_DISABLE_tolua_Elementum_ParticleUniverse_ParticleSystem_setCategory00
static int tolua_Elementum_ParticleUniverse_ParticleSystem_setCategory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleUniverse::ParticleSystem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleUniverse::ParticleSystem* self = (ParticleUniverse::ParticleSystem*)  tolua_tousertype(tolua_S,1,0);
  const std::string category = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCategory'",NULL);
#endif
  {
   self->setCategory(category);
   tolua_pushcppstring(tolua_S,(const char*)category);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCategory'.",&tolua_err);
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
   tolua_constant(tolua_S,"POS_READY",Pixy::POS_READY);
   tolua_constant(tolua_S,"POS_CHARGING",Pixy::POS_CHARGING);
   tolua_constant(tolua_S,"POS_DEFENCE",Pixy::POS_DEFENCE);
   tolua_constant(tolua_S,"POS_OFFENCE",Pixy::POS_OFFENCE);
   tolua_constant(tolua_S,"POS_ATTACK",Pixy::POS_ATTACK);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Renderable","Pixy::Renderable","",tolua_collect_Pixy__Renderable);
   #else
   tolua_cclass(tolua_S,"Renderable","Pixy::Renderable","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Renderable");
    tolua_constant(tolua_S,"ANIM_NONE",Pixy::Renderable::ANIM_NONE);
    tolua_constant(tolua_S,"ANIM_LIVE",Pixy::Renderable::ANIM_LIVE);
    tolua_constant(tolua_S,"ANIM_IDLE",Pixy::Renderable::ANIM_IDLE);
    tolua_constant(tolua_S,"ANIM_WALK",Pixy::Renderable::ANIM_WALK);
    tolua_constant(tolua_S,"ANIM_RUN",Pixy::Renderable::ANIM_RUN);
    tolua_constant(tolua_S,"ANIM_ATTACK",Pixy::Renderable::ANIM_ATTACK);
    tolua_constant(tolua_S,"ANIM_HIT",Pixy::Renderable::ANIM_HIT);
    tolua_constant(tolua_S,"ANIM_REST",Pixy::Renderable::ANIM_REST);
    tolua_constant(tolua_S,"ANIM_GETUP",Pixy::Renderable::ANIM_GETUP);
    tolua_constant(tolua_S,"ANIM_DIE",Pixy::Renderable::ANIM_DIE);
    tolua_function(tolua_S,"new",tolua_Elementum_Pixy_Renderable_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Pixy_Renderable_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Pixy_Renderable_new00_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Pixy_Renderable_delete00);
    tolua_function(tolua_S,"getEntity",tolua_Elementum_Pixy_Renderable_getEntity00);
    tolua_function(tolua_S,"attachSceneNode",tolua_Elementum_Pixy_Renderable_attachSceneNode00);
    tolua_function(tolua_S,"getSceneNode",tolua_Elementum_Pixy_Renderable_getSceneNode00);
    tolua_function(tolua_S,"attachSceneObject",tolua_Elementum_Pixy_Renderable_attachSceneObject00);
    tolua_function(tolua_S,"getSceneObject",tolua_Elementum_Pixy_Renderable_getSceneObject00);
    tolua_function(tolua_S,"registerAnimationState",tolua_Elementum_Pixy_Renderable_registerAnimationState00);
    tolua_function(tolua_S,"setScale",tolua_Elementum_Pixy_Renderable_setScale00);
    tolua_function(tolua_S,"setAnimFadeSpeed",tolua_Elementum_Pixy_Renderable_setAnimFadeSpeed00);
    tolua_function(tolua_S,"getAnimFadeSpeed",tolua_Elementum_Pixy_Renderable_getAnimFadeSpeed00);
    tolua_function(tolua_S,"setRotationFactor",tolua_Elementum_Pixy_Renderable_setRotationFactor00);
    tolua_function(tolua_S,"animateLive",tolua_Elementum_Pixy_Renderable_animateLive00);
    tolua_function(tolua_S,"animateDie",tolua_Elementum_Pixy_Renderable_animateDie00);
    tolua_function(tolua_S,"animateIdle",tolua_Elementum_Pixy_Renderable_animateIdle00);
    tolua_function(tolua_S,"animateWalk",tolua_Elementum_Pixy_Renderable_animateWalk00);
    tolua_function(tolua_S,"animateRun",tolua_Elementum_Pixy_Renderable_animateRun00);
    tolua_function(tolua_S,"animateAttack",tolua_Elementum_Pixy_Renderable_animateAttack00);
    tolua_function(tolua_S,"animateHit",tolua_Elementum_Pixy_Renderable_animateHit00);
    tolua_function(tolua_S,"animateRest",tolua_Elementum_Pixy_Renderable_animateRest00);
    tolua_function(tolua_S,"animateGetUp",tolua_Elementum_Pixy_Renderable_animateGetUp00);
    tolua_function(tolua_S,"_animate",tolua_Elementum_Pixy_Renderable__animate00);
    tolua_function(tolua_S,"setup",tolua_Elementum_Pixy_Renderable_setup00);
    tolua_function(tolua_S,"attachExtension",tolua_Elementum_Pixy_Renderable_attachExtension00);
    tolua_function(tolua_S,"hide",tolua_Elementum_Pixy_Renderable_hide00);
    tolua_function(tolua_S,"show",tolua_Elementum_Pixy_Renderable_show00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CPuppet","Pixy::CPuppet","Pixy::Puppet",tolua_collect_Pixy__CPuppet);
   #else
   tolua_cclass(tolua_S,"CPuppet","Pixy::CPuppet","Pixy::Puppet",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CPuppet");
    tolua_function(tolua_S,"new",tolua_Elementum_Pixy_CPuppet_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Pixy_CPuppet_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Pixy_CPuppet_new00_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Pixy_CPuppet_delete00);
    tolua_function(tolua_S,"getSpell",tolua_Elementum_Pixy_CPuppet_getSpell00);
    tolua_function(tolua_S,"getRenderable",tolua_Elementum_Pixy_CPuppet_getRenderable00);
    tolua_function(tolua_S,"getHand",tolua_Elementum_Pixy_CPuppet_getHand00);
    tolua_function(tolua_S,"nrSpellsInHand",tolua_Elementum_Pixy_CPuppet_nrSpellsInHand00);
    tolua_function(tolua_S,"getSpell",tolua_Elementum_Pixy_CPuppet_getSpell01);
    tolua_function(tolua_S,"attachSpell",tolua_Elementum_Pixy_CPuppet_attachSpell00);
    tolua_function(tolua_S,"detachSpell",tolua_Elementum_Pixy_CPuppet_detachSpell00);
    tolua_function(tolua_S,"attachUnit",tolua_Elementum_Pixy_CPuppet_attachUnit00);
    tolua_function(tolua_S,"detachUnit",tolua_Elementum_Pixy_CPuppet_detachUnit00);
    tolua_function(tolua_S,"getUnit",tolua_Elementum_Pixy_CPuppet_getUnit00);
    tolua_function(tolua_S,"getUnits",tolua_Elementum_Pixy_CPuppet_getUnits00);
    tolua_function(tolua_S,"attachBuff",tolua_Elementum_Pixy_CPuppet_attachBuff00);
    tolua_function(tolua_S,"detachBuff",tolua_Elementum_Pixy_CPuppet_detachBuff00);
    tolua_function(tolua_S,"hasBuff",tolua_Elementum_Pixy_CPuppet_hasBuff00);
    tolua_function(tolua_S,"getBuffs",tolua_Elementum_Pixy_CPuppet_getBuffs00);
    tolua_function(tolua_S,"updateTextOverlay",tolua_Elementum_Pixy_CPuppet_updateTextOverlay00);
    tolua_function(tolua_S,"setHP",tolua_Elementum_Pixy_CPuppet_setHP00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CSpell","Pixy::CSpell","Pixy::Spell",tolua_collect_Pixy__CSpell);
   #else
   tolua_cclass(tolua_S,"CSpell","Pixy::CSpell","Pixy::Spell",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CSpell");
    tolua_function(tolua_S,"new",tolua_Elementum_Pixy_CSpell_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Pixy_CSpell_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Pixy_CSpell_new00_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Pixy_CSpell_delete00);
    tolua_function(tolua_S,"setImageSet",tolua_Elementum_Pixy_CSpell_setImageSet00);
    tolua_function(tolua_S,"setImageName",tolua_Elementum_Pixy_CSpell_setImageName00);
    tolua_function(tolua_S,"setButton",tolua_Elementum_Pixy_CSpell_setButton00);
    tolua_function(tolua_S,"getImageSet",tolua_Elementum_Pixy_CSpell_getImageSet00);
    tolua_function(tolua_S,"getImageName",tolua_Elementum_Pixy_CSpell_getImageName00);
    tolua_function(tolua_S,"getButton",tolua_Elementum_Pixy_CSpell_getButton00);
    tolua_function(tolua_S,"getTooltip",tolua_Elementum_Pixy_CSpell_getTooltip00);
    tolua_function(tolua_S,"updateTooltip",tolua_Elementum_Pixy_CSpell_updateTooltip00);
    tolua_function(tolua_S,"getCaster",tolua_Elementum_Pixy_CSpell_getCaster00);
    tolua_function(tolua_S,"getTarget",tolua_Elementum_Pixy_CSpell_getTarget00);
    tolua_function(tolua_S,"setCaster",tolua_Elementum_Pixy_CSpell_setCaster00);
    tolua_function(tolua_S,"setTarget",tolua_Elementum_Pixy_CSpell_setTarget00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"CDeck","Pixy::CDeck","Pixy::Deck",NULL);
   tolua_beginmodule(tolua_S,"CDeck");
    tolua_function(tolua_S,"generate",tolua_Elementum_Pixy_CDeck_generate00);
    tolua_function(tolua_S,"getSpell",tolua_Elementum_Pixy_CDeck_getSpell00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CUnit","Pixy::CUnit","Pixy::Unit",tolua_collect_Pixy__CUnit);
   #else
   tolua_cclass(tolua_S,"CUnit","Pixy::CUnit","Pixy::Unit",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CUnit");
    tolua_function(tolua_S,"new",tolua_Elementum_Pixy_CUnit_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Pixy_CUnit_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Pixy_CUnit_new00_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Pixy_CUnit_delete00);
    tolua_function(tolua_S,"getRenderable",tolua_Elementum_Pixy_CUnit_getRenderable00);
    tolua_function(tolua_S,"attachBuff",tolua_Elementum_Pixy_CUnit_attachBuff00);
    tolua_function(tolua_S,"detachBuff",tolua_Elementum_Pixy_CUnit_detachBuff00);
    tolua_function(tolua_S,"hasBuff",tolua_Elementum_Pixy_CUnit_hasBuff00);
    tolua_function(tolua_S,"getBuffs",tolua_Elementum_Pixy_CUnit_getBuffs00);
    tolua_function(tolua_S,"updateTextOverlay",tolua_Elementum_Pixy_CUnit_updateTextOverlay00);
    tolua_variable(tolua_S,"fRequiresYawFix",tolua_get_Pixy__CUnit_fRequiresYawFix,tolua_set_Pixy__CUnit_fRequiresYawFix);
    tolua_function(tolua_S,"setWalkSpeed",tolua_Elementum_Pixy_CUnit_setWalkSpeed00);
    tolua_function(tolua_S,"getWalkSpeed",tolua_Elementum_Pixy_CUnit_getWalkSpeed00);
    tolua_function(tolua_S,"getPosition",tolua_Elementum_Pixy_CUnit_getPosition00);
    tolua_function(tolua_S,"isDying",tolua_Elementum_Pixy_CUnit_isDying00);
    tolua_function(tolua_S,"isMoving",tolua_Elementum_Pixy_CUnit_isMoving00);
    tolua_function(tolua_S,"getEnemy",tolua_Elementum_Pixy_CUnit_getEnemy00);
    tolua_function(tolua_S,"setDefaultWalkSpeed",tolua_Elementum_Pixy_CUnit_setDefaultWalkSpeed00);
    tolua_function(tolua_S,"getDefaultWalkSpeed",tolua_Elementum_Pixy_CUnit_getDefaultWalkSpeed00);
    tolua_function(tolua_S,"getEnemy",tolua_Elementum_Pixy_CUnit_getEnemy01);
    tolua_function(tolua_S,"setBaseAP",tolua_Elementum_Pixy_CUnit_setBaseAP00);
    tolua_function(tolua_S,"setAP",tolua_Elementum_Pixy_CUnit_setAP00);
    tolua_function(tolua_S,"setBaseHP",tolua_Elementum_Pixy_CUnit_setBaseHP00);
    tolua_function(tolua_S,"setHP",tolua_Elementum_Pixy_CUnit_setHP00);
    tolua_function(tolua_S,"live",tolua_Elementum_Pixy_CUnit_live00);
    tolua_function(tolua_S,"die",tolua_Elementum_Pixy_CUnit_die00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"FxEngine","Pixy::FxEngine","Pixy::Engine",tolua_collect_Pixy__FxEngine);
   #else
   tolua_cclass(tolua_S,"FxEngine","Pixy::FxEngine","Pixy::Engine",NULL);
   #endif
   tolua_beginmodule(tolua_S,"FxEngine");
    tolua_function(tolua_S,"delete",tolua_Elementum_Pixy_FxEngine_delete00);
    tolua_function(tolua_S,"getSingletonPtr",tolua_Elementum_Pixy_FxEngine_getSingletonPtr00);
    tolua_function(tolua_S,"getSingleton",tolua_Elementum_Pixy_FxEngine_getSingleton00);
    tolua_function(tolua_S,"loadEffect",tolua_Elementum_Pixy_FxEngine_loadEffect00);
    tolua_function(tolua_S,"playEffect",tolua_Elementum_Pixy_FxEngine_playEffect00);
    tolua_function(tolua_S,"playEffect",tolua_Elementum_Pixy_FxEngine_playEffect01);
    tolua_function(tolua_S,"playEffect",tolua_Elementum_Pixy_FxEngine_playEffect02);
    tolua_function(tolua_S,"highlight",tolua_Elementum_Pixy_FxEngine_highlight00);
    tolua_function(tolua_S,"dehighlight",tolua_Elementum_Pixy_FxEngine_dehighlight00);
    tolua_function(tolua_S,"unloadAllEffects",tolua_Elementum_Pixy_FxEngine_unloadAllEffects00);
    tolua_variable(tolua_S,"__Pixy__EventListener__",tolua_get_Pixy__FxEngine___Pixy__EventListener__,NULL);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GameManager","Pixy::GameManager","",NULL);
   tolua_beginmodule(tolua_S,"GameManager");
    tolua_function(tolua_S,"changeState",tolua_Elementum_Pixy_GameManager_changeState00);
    tolua_function(tolua_S,"getSingleton",tolua_Elementum_Pixy_GameManager_getSingleton00);
    tolua_function(tolua_S,"requestShutdown",tolua_Elementum_Pixy_GameManager_requestShutdown00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"InputManager","Pixy::InputManager","",NULL);
   tolua_beginmodule(tolua_S,"InputManager");
    tolua_function(tolua_S,"getKeyboard",tolua_Elementum_Pixy_InputManager_getKeyboard00);
    tolua_function(tolua_S,"getSingletonPtr",tolua_Elementum_Pixy_InputManager_getSingletonPtr00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"GameState","Pixy::GameState","",NULL);
   tolua_beginmodule(tolua_S,"GameState");
    tolua_function(tolua_S,"changeState",tolua_Elementum_Pixy_GameState_changeState00);
    tolua_function(tolua_S,"requestShutdown",tolua_Elementum_Pixy_GameState_requestShutdown00);
    tolua_function(tolua_S,"isCurrentState",tolua_Elementum_Pixy_GameState_isCurrentState00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Intro","Pixy::Intro","Pixy::GameState",NULL);
   tolua_beginmodule(tolua_S,"Intro");
    tolua_function(tolua_S,"getSingleton",tolua_Elementum_Pixy_Intro_getSingleton00);
    tolua_function(tolua_S,"getSingletonPtr",tolua_Elementum_Pixy_Intro_getSingletonPtr00);
    tolua_function(tolua_S,"getPuppetName",tolua_Elementum_Pixy_Intro_getPuppetName00);
    tolua_function(tolua_S,"setPuppetName",tolua_Elementum_Pixy_Intro_setPuppetName00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Lobby","Pixy::Lobby","Pixy::GameState",NULL);
   tolua_beginmodule(tolua_S,"Lobby");
    tolua_function(tolua_S,"getSingletonPtr",tolua_Elementum_Pixy_Lobby_getSingletonPtr00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Combat","Pixy::Combat","Pixy::GameState",NULL);
   tolua_beginmodule(tolua_S,"Combat");
    tolua_function(tolua_S,"getSingleton",tolua_Elementum_Pixy_Combat_getSingleton00);
    tolua_function(tolua_S,"getSingletonPtr",tolua_Elementum_Pixy_Combat_getSingletonPtr00);
    tolua_function(tolua_S,"getPuppets",tolua_Elementum_Pixy_Combat_getPuppets00);
    tolua_function(tolua_S,"getEnemy",tolua_Elementum_Pixy_Combat_getEnemy00);
    tolua_function(tolua_S,"getPuppet",tolua_Elementum_Pixy_Combat_getPuppet00);
    tolua_function(tolua_S,"setIsDebugging",tolua_Elementum_Pixy_Combat_setIsDebugging00);
    tolua_function(tolua_S,"isDebugging",tolua_Elementum_Pixy_Combat_isDebugging00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"UIEngine","Pixy::UIEngine","Pixy::Engine",tolua_collect_Pixy__UIEngine);
   #else
   tolua_cclass(tolua_S,"UIEngine","Pixy::UIEngine","Pixy::Engine",NULL);
   #endif
   tolua_beginmodule(tolua_S,"UIEngine");
    tolua_function(tolua_S,"delete",tolua_Elementum_Pixy_UIEngine_delete00);
    tolua_function(tolua_S,"getSingletonPtr",tolua_Elementum_Pixy_UIEngine_getSingletonPtr00);
    tolua_function(tolua_S,"setup",tolua_Elementum_Pixy_UIEngine_setup00);
    tolua_function(tolua_S,"update",tolua_Elementum_Pixy_UIEngine_update00);
    tolua_function(tolua_S,"cleanup",tolua_Elementum_Pixy_UIEngine_cleanup00);
    tolua_function(tolua_S,"setMargin",tolua_Elementum_Pixy_UIEngine_setMargin00);
    tolua_function(tolua_S,"connectAnimation",tolua_Elementum_Pixy_UIEngine_connectAnimation00);
    tolua_function(tolua_S,"refreshTooltipSize",tolua_Elementum_Pixy_UIEngine_refreshTooltipSize00);
    tolua_variable(tolua_S,"__Pixy__EventListener__",tolua_get_Pixy__UIEngine___Pixy__EventListener__,NULL);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"GfxEngine","Pixy::GfxEngine","Pixy::Engine",tolua_collect_Pixy__GfxEngine);
   #else
   tolua_cclass(tolua_S,"GfxEngine","Pixy::GfxEngine","Pixy::Engine",NULL);
   #endif
   tolua_beginmodule(tolua_S,"GfxEngine");
    tolua_constant(tolua_S,"ENTITY_MASK",Pixy::GfxEngine::ENTITY_MASK);
    tolua_constant(tolua_S,"TERRAIN_MASK",Pixy::GfxEngine::TERRAIN_MASK);
    tolua_array(tolua_S,"mPuppetPos",tolua_get_Elementum_Pixy_GfxEngine_mPuppetPos,tolua_set_Elementum_Pixy_GfxEngine_mPuppetPos);
    tolua_variable(tolua_S,"mPuppetScale",tolua_get_Pixy__GfxEngine_mPuppetScale,tolua_set_Pixy__GfxEngine_mPuppetScale);
    tolua_variable(tolua_S,"mUnitScale",tolua_get_Pixy__GfxEngine_mUnitScale,tolua_set_Pixy__GfxEngine_mUnitScale);
    tolua_variable(tolua_S,"mMTOFontColor",tolua_get_Pixy__GfxEngine_mMTOFontColor,tolua_set_Pixy__GfxEngine_mMTOFontColor);
    tolua_variable(tolua_S,"mMTOFontName",tolua_get_Pixy__GfxEngine_mMTOFontName,tolua_set_Pixy__GfxEngine_mMTOFontName);
    tolua_variable(tolua_S,"mMTOFontSize",tolua_get_Pixy__GfxEngine_mMTOFontSize,tolua_set_Pixy__GfxEngine_mMTOFontSize);
    tolua_variable(tolua_S,"mMTOMaterialName",tolua_get_Pixy__GfxEngine_mMTOMaterialName,tolua_set_Pixy__GfxEngine_mMTOMaterialName);
    tolua_variable(tolua_S,"mUnitMargin",tolua_get_Pixy__GfxEngine_mUnitMargin,tolua_set_Pixy__GfxEngine_mUnitMargin);
    tolua_variable(tolua_S,"mPuppetMargin",tolua_get_Pixy__GfxEngine_mPuppetMargin,tolua_set_Pixy__GfxEngine_mPuppetMargin);
    tolua_variable(tolua_S,"mCameraYawPitchDist",tolua_get_Pixy__GfxEngine_mCameraYawPitchDist,tolua_set_Pixy__GfxEngine_mCameraYawPitchDist);
    tolua_variable(tolua_S,"mPackSpacing",tolua_get_Pixy__GfxEngine_mPackSpacing,tolua_set_Pixy__GfxEngine_mPackSpacing);
    tolua_function(tolua_S,"delete",tolua_Elementum_Pixy_GfxEngine_delete00);
    tolua_function(tolua_S,"getSingletonPtr",tolua_Elementum_Pixy_GfxEngine_getSingletonPtr00);
    tolua_function(tolua_S,"disableMouseCaptureOverUIElement",tolua_Elementum_Pixy_GfxEngine_disableMouseCaptureOverUIElement00);
    tolua_function(tolua_S,"enableMouseCaptureOverUIElement",tolua_Elementum_Pixy_GfxEngine_enableMouseCaptureOverUIElement00);
    tolua_function(tolua_S,"setupMovableTextOverlays",tolua_Elementum_Pixy_GfxEngine_setupMovableTextOverlays00);
    tolua_function(tolua_S,"attachToScene",tolua_Elementum_Pixy_GfxEngine_attachToScene00);
    tolua_function(tolua_S,"detachFromScene",tolua_Elementum_Pixy_GfxEngine_detachFromScene00);
    tolua_function(tolua_S,"getSelected",tolua_Elementum_Pixy_GfxEngine_getSelected00);
    tolua_function(tolua_S,"getCamera",tolua_Elementum_Pixy_GfxEngine_getCamera00);
    tolua_function(tolua_S,"getCameraMan",tolua_Elementum_Pixy_GfxEngine_getCameraMan00);
    tolua_function(tolua_S,"getRoot",tolua_Elementum_Pixy_GfxEngine_getRoot00);
    tolua_function(tolua_S,"getSceneMgr",tolua_Elementum_Pixy_GfxEngine_getSceneMgr00);
    tolua_function(tolua_S,"getViewport",tolua_Elementum_Pixy_GfxEngine_getViewport00);
    tolua_function(tolua_S,"getWindow",tolua_Elementum_Pixy_GfxEngine_getWindow00);
    tolua_function(tolua_S,"setupSceneManager",tolua_Elementum_Pixy_GfxEngine_setupSceneManager00);
    tolua_function(tolua_S,"setupViewports",tolua_Elementum_Pixy_GfxEngine_setupViewports00);
    tolua_function(tolua_S,"setupCamera",tolua_Elementum_Pixy_GfxEngine_setupCamera00);
    tolua_function(tolua_S,"setupTerrain",tolua_Elementum_Pixy_GfxEngine_setupTerrain00);
    tolua_function(tolua_S,"setupLights",tolua_Elementum_Pixy_GfxEngine_setupLights00);
    tolua_function(tolua_S,"setupNodes",tolua_Elementum_Pixy_GfxEngine_setupNodes00);
    tolua_function(tolua_S,"setupWaypoints",tolua_Elementum_Pixy_GfxEngine_setupWaypoints00);
    tolua_function(tolua_S,"changeOwnership",tolua_Elementum_Pixy_GfxEngine_changeOwnership00);
    tolua_function(tolua_S,"loadScene",tolua_Elementum_Pixy_GfxEngine_loadScene00);
    tolua_function(tolua_S,"unloadScene",tolua_Elementum_Pixy_GfxEngine_unloadScene00);
    tolua_function(tolua_S,"enableCompositorEffect",tolua_Elementum_Pixy_GfxEngine_enableCompositorEffect00);
    tolua_function(tolua_S,"loadDotScene",tolua_Elementum_Pixy_GfxEngine_loadDotScene00);
    tolua_function(tolua_S,"createSphere",tolua_Elementum_Pixy_GfxEngine_createSphere00);
    tolua_function(tolua_S,"getScreenCoords",tolua_Elementum_Pixy_GfxEngine_getScreenCoords00);
    tolua_function(tolua_S,"setYawPitchDist",tolua_Elementum_Pixy_GfxEngine_setYawPitchDist00);
    tolua_function(tolua_S,"trackNode",tolua_Elementum_Pixy_GfxEngine_trackNode00);
    tolua_function(tolua_S,"_setUserAny",tolua_Elementum_Pixy_GfxEngine__setUserAny00);
    tolua_function(tolua_S,"attachRTT",tolua_Elementum_Pixy_GfxEngine_attachRTT00);
    tolua_function(tolua_S,"detachRTT",tolua_Elementum_Pixy_GfxEngine_detachRTT00);
    tolua_variable(tolua_S,"__Pixy__EventListener__",tolua_get_Pixy__GfxEngine___Pixy__EventListener__,NULL);
   tolua_endmodule(tolua_S);
   tolua_function(tolua_S,"Log",tolua_Elementum_Pixy_Log00);
   tolua_cclass(tolua_S,"NetworkManager","Pixy::NetworkManager","",NULL);
   tolua_beginmodule(tolua_S,"NetworkManager");
    tolua_function(tolua_S,"getSingleton",tolua_Elementum_Pixy_NetworkManager_getSingleton00);
    tolua_function(tolua_S,"connect",tolua_Elementum_Pixy_NetworkManager_connect00);
    tolua_function(tolua_S,"disconnect",tolua_Elementum_Pixy_NetworkManager_disconnect00);
    tolua_function(tolua_S,"send",tolua_Elementum_Pixy_NetworkManager_send00);
    tolua_function(tolua_S,"isConnected",tolua_Elementum_Pixy_NetworkManager_isConnected00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"ScriptEngine","Pixy::ScriptEngine","Pixy::Engine",NULL);
   tolua_beginmodule(tolua_S,"ScriptEngine");
    tolua_function(tolua_S,"getSingletonPtr",tolua_Elementum_Pixy_ScriptEngine_getSingletonPtr00);
    tolua_function(tolua_S,"getScriptPathPrefix",tolua_Elementum_Pixy_ScriptEngine_getScriptPathPrefix00);
    tolua_function(tolua_S,"getModulePathPrefix",tolua_Elementum_Pixy_ScriptEngine_getModulePathPrefix00);
    tolua_function(tolua_S,"callMeAfter",tolua_Elementum_Pixy_ScriptEngine_callMeAfter00);
    tolua_function(tolua_S,"_passGameData",tolua_Elementum_Pixy_ScriptEngine__passGameData00);
    tolua_variable(tolua_S,"__Pixy__EventListener__",tolua_get_Pixy__ScriptEngine___Pixy__EventListener__,NULL);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CUnitVecExporter","Pixy::LuaExporter<CUnitVec>","BaseLuaExporter",tolua_collect_Pixy__LuaExporter_CUnitVec_);
   #else
   tolua_cclass(tolua_S,"CUnitVecExporter","Pixy::LuaExporter<CUnitVec>","BaseLuaExporter",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CUnitVecExporter");
    tolua_function(tolua_S,"new",tolua_Elementum_Pixy_CUnitVecExporter_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Pixy_CUnitVecExporter_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Pixy_CUnitVecExporter_new00_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Pixy_CUnitVecExporter_delete00);
    tolua_function(tolua_S,"export",tolua_Elementum_Pixy_CUnitVecExporter_export00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CSpellVecExporter","Pixy::LuaExporter<CSpellVec>","BaseLuaExporter",tolua_collect_Pixy__LuaExporter_CSpellVec_);
   #else
   tolua_cclass(tolua_S,"CSpellVecExporter","Pixy::LuaExporter<CSpellVec>","BaseLuaExporter",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CSpellVecExporter");
    tolua_function(tolua_S,"new",tolua_Elementum_Pixy_CSpellVecExporter_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Pixy_CSpellVecExporter_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Pixy_CSpellVecExporter_new00_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Pixy_CSpellVecExporter_delete00);
    tolua_function(tolua_S,"export",tolua_Elementum_Pixy_CSpellVecExporter_export00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CPuppetVecExporter","Pixy::LuaExporter<CPuppetVec>","BaseLuaExporter",tolua_collect_Pixy__LuaExporter_CPuppetVec_);
   #else
   tolua_cclass(tolua_S,"CPuppetVecExporter","Pixy::LuaExporter<CPuppetVec>","BaseLuaExporter",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CPuppetVecExporter");
    tolua_function(tolua_S,"new",tolua_Elementum_Pixy_CPuppetVecExporter_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Pixy_CPuppetVecExporter_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Pixy_CPuppetVecExporter_new00_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Pixy_CPuppetVecExporter_delete00);
    tolua_function(tolua_S,"export",tolua_Elementum_Pixy_CPuppetVecExporter_export00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CUnitListExporter","Pixy::LuaExporter<CUnitList>","BaseLuaExporter",tolua_collect_Pixy__LuaExporter_CUnitList_);
   #else
   tolua_cclass(tolua_S,"CUnitListExporter","Pixy::LuaExporter<CUnitList>","BaseLuaExporter",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CUnitListExporter");
    tolua_function(tolua_S,"new",tolua_Elementum_Pixy_CUnitListExporter_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Pixy_CUnitListExporter_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Pixy_CUnitListExporter_new00_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Pixy_CUnitListExporter_delete00);
    tolua_function(tolua_S,"export",tolua_Elementum_Pixy_CUnitListExporter_export00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CSpellListExporter","Pixy::LuaExporter<CSpellList>","BaseLuaExporter",tolua_collect_Pixy__LuaExporter_CSpellList_);
   #else
   tolua_cclass(tolua_S,"CSpellListExporter","Pixy::LuaExporter<CSpellList>","BaseLuaExporter",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CSpellListExporter");
    tolua_function(tolua_S,"new",tolua_Elementum_Pixy_CSpellListExporter_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Pixy_CSpellListExporter_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Pixy_CSpellListExporter_new00_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Pixy_CSpellListExporter_delete00);
    tolua_function(tolua_S,"export",tolua_Elementum_Pixy_CSpellListExporter_export00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CPuppetListExporter","Pixy::LuaExporter<CPuppetList>","BaseLuaExporter",tolua_collect_Pixy__LuaExporter_CPuppetList_);
   #else
   tolua_cclass(tolua_S,"CPuppetListExporter","Pixy::LuaExporter<CPuppetList>","BaseLuaExporter",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CPuppetListExporter");
    tolua_function(tolua_S,"new",tolua_Elementum_Pixy_CPuppetListExporter_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Pixy_CPuppetListExporter_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Pixy_CPuppetListExporter_new00_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Pixy_CPuppetListExporter_delete00);
    tolua_function(tolua_S,"export",tolua_Elementum_Pixy_CPuppetListExporter_export00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"OgreRTT","Pixy::OgreRTT","Ogre::RenderTargetListener",tolua_collect_Pixy__OgreRTT);
   #else
   tolua_cclass(tolua_S,"OgreRTT","Pixy::OgreRTT","Ogre::RenderTargetListener",NULL);
   #endif
   tolua_beginmodule(tolua_S,"OgreRTT");
    tolua_function(tolua_S,"new",tolua_Elementum_Pixy_OgreRTT_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Pixy_OgreRTT_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Pixy_OgreRTT_new00_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Pixy_OgreRTT_delete00);
    tolua_function(tolua_S,"setup",tolua_Elementum_Pixy_OgreRTT_setup00);
    tolua_function(tolua_S,"setCorners",tolua_Elementum_Pixy_OgreRTT_setCorners00);
    tolua_function(tolua_S,"enable",tolua_Elementum_Pixy_OgreRTT_enable00);
    tolua_function(tolua_S,"disable",tolua_Elementum_Pixy_OgreRTT_disable00);
    tolua_function(tolua_S,"isEnabled",tolua_Elementum_Pixy_OgreRTT_isEnabled00);
    tolua_function(tolua_S,"hide",tolua_Elementum_Pixy_OgreRTT_hide00);
    tolua_function(tolua_S,"show",tolua_Elementum_Pixy_OgreRTT_show00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Ogre",0);
  tolua_beginmodule(tolua_S,"Ogre");
   tolua_constant(tolua_S,"PF_UNKNOWN",Ogre::PF_UNKNOWN);
   tolua_constant(tolua_S,"PF_L8",Ogre::PF_L8);
   tolua_constant(tolua_S,"PF_BYTE_L",Ogre::PF_BYTE_L);
   tolua_constant(tolua_S,"PF_L16",Ogre::PF_L16);
   tolua_constant(tolua_S,"PF_SHORT_L",Ogre::PF_SHORT_L);
   tolua_constant(tolua_S,"PF_A8",Ogre::PF_A8);
   tolua_constant(tolua_S,"PF_BYTE_A",Ogre::PF_BYTE_A);
   tolua_constant(tolua_S,"PF_A4L4",Ogre::PF_A4L4);
   tolua_constant(tolua_S,"PF_BYTE_LA",Ogre::PF_BYTE_LA);
   tolua_constant(tolua_S,"PF_R5G6B5",Ogre::PF_R5G6B5);
   tolua_constant(tolua_S,"PF_B5G6R5",Ogre::PF_B5G6R5);
   tolua_constant(tolua_S,"PF_R3G3B2",Ogre::PF_R3G3B2);
   tolua_constant(tolua_S,"PF_A4R4G4B4",Ogre::PF_A4R4G4B4);
   tolua_constant(tolua_S,"PF_A1R5G5B5",Ogre::PF_A1R5G5B5);
   tolua_constant(tolua_S,"PF_R8G8B8",Ogre::PF_R8G8B8);
   tolua_constant(tolua_S,"PF_B8G8R8",Ogre::PF_B8G8R8);
   tolua_constant(tolua_S,"PF_A8R8G8B8",Ogre::PF_A8R8G8B8);
   tolua_constant(tolua_S,"PF_A8B8G8R8",Ogre::PF_A8B8G8R8);
   tolua_constant(tolua_S,"PF_B8G8R8A8",Ogre::PF_B8G8R8A8);
   tolua_constant(tolua_S,"PF_R8G8B8A8",Ogre::PF_R8G8B8A8);
   tolua_constant(tolua_S,"PF_X8R8G8B8",Ogre::PF_X8R8G8B8);
   tolua_constant(tolua_S,"PF_X8B8G8R8",Ogre::PF_X8B8G8R8);
   tolua_constant(tolua_S,"PF_BYTE_RGB",Ogre::PF_BYTE_RGB);
   tolua_constant(tolua_S,"PF_BYTE_BGR",Ogre::PF_BYTE_BGR);
   tolua_constant(tolua_S,"PF_BYTE_BGRA",Ogre::PF_BYTE_BGRA);
   tolua_constant(tolua_S,"PF_BYTE_RGBA",Ogre::PF_BYTE_RGBA);
   tolua_constant(tolua_S,"PF_BYTE_RGB",Ogre::PF_BYTE_RGB);
   tolua_constant(tolua_S,"PF_BYTE_BGR",Ogre::PF_BYTE_BGR);
   tolua_constant(tolua_S,"PF_BYTE_BGRA",Ogre::PF_BYTE_BGRA);
   tolua_constant(tolua_S,"PF_BYTE_RGBA",Ogre::PF_BYTE_RGBA);
   tolua_constant(tolua_S,"PF_A2R10G10B10",Ogre::PF_A2R10G10B10);
   tolua_constant(tolua_S,"PF_A2B10G10R10",Ogre::PF_A2B10G10R10);
   tolua_constant(tolua_S,"PF_DXT1",Ogre::PF_DXT1);
   tolua_constant(tolua_S,"PF_DXT2",Ogre::PF_DXT2);
   tolua_constant(tolua_S,"PF_DXT3",Ogre::PF_DXT3);
   tolua_constant(tolua_S,"PF_DXT4",Ogre::PF_DXT4);
   tolua_constant(tolua_S,"PF_DXT5",Ogre::PF_DXT5);
   tolua_constant(tolua_S,"PF_FLOAT16_R",Ogre::PF_FLOAT16_R);
   tolua_constant(tolua_S,"PF_FLOAT16_RGB",Ogre::PF_FLOAT16_RGB);
   tolua_constant(tolua_S,"PF_FLOAT16_RGBA",Ogre::PF_FLOAT16_RGBA);
   tolua_constant(tolua_S,"PF_FLOAT32_R",Ogre::PF_FLOAT32_R);
   tolua_constant(tolua_S,"PF_FLOAT32_RGB",Ogre::PF_FLOAT32_RGB);
   tolua_constant(tolua_S,"PF_FLOAT32_RGBA",Ogre::PF_FLOAT32_RGBA);
   tolua_constant(tolua_S,"PF_FLOAT16_GR",Ogre::PF_FLOAT16_GR);
   tolua_constant(tolua_S,"PF_FLOAT32_GR",Ogre::PF_FLOAT32_GR);
   tolua_constant(tolua_S,"PF_DEPTH",Ogre::PF_DEPTH);
   tolua_constant(tolua_S,"PF_SHORT_RGBA",Ogre::PF_SHORT_RGBA);
   tolua_constant(tolua_S,"PF_SHORT_GR",Ogre::PF_SHORT_GR);
   tolua_constant(tolua_S,"PF_SHORT_RGB",Ogre::PF_SHORT_RGB);
   tolua_constant(tolua_S,"PF_PVRTC_RGB2",Ogre::PF_PVRTC_RGB2);
   tolua_constant(tolua_S,"PF_PVRTC_RGBA2",Ogre::PF_PVRTC_RGBA2);
   tolua_constant(tolua_S,"PF_PVRTC_RGB4",Ogre::PF_PVRTC_RGB4);
   tolua_constant(tolua_S,"PF_PVRTC_RGBA4",Ogre::PF_PVRTC_RGBA4);
   tolua_constant(tolua_S,"PF_COUNT",Ogre::PF_COUNT);
   tolua_constant(tolua_S,"PFF_HASALPHA",Ogre::PFF_HASALPHA);
   tolua_constant(tolua_S,"PFF_COMPRESSED",Ogre::PFF_COMPRESSED);
   tolua_constant(tolua_S,"PFF_FLOAT",Ogre::PFF_FLOAT);
   tolua_constant(tolua_S,"PFF_DEPTH",Ogre::PFF_DEPTH);
   tolua_constant(tolua_S,"PFF_NATIVEENDIAN",Ogre::PFF_NATIVEENDIAN);
   tolua_constant(tolua_S,"PFF_LUMINANCE",Ogre::PFF_LUMINANCE);
   tolua_constant(tolua_S,"PCT_BYTE",Ogre::PCT_BYTE);
   tolua_constant(tolua_S,"PCT_SHORT",Ogre::PCT_SHORT);
   tolua_constant(tolua_S,"PCT_FLOAT16",Ogre::PCT_FLOAT16);
   tolua_constant(tolua_S,"PCT_FLOAT32",Ogre::PCT_FLOAT32);
   tolua_constant(tolua_S,"PCT_COUNT",Ogre::PCT_COUNT);
   tolua_constant(tolua_S,"FOG_NONE",Ogre::FOG_NONE);
   tolua_constant(tolua_S,"FOG_EXP",Ogre::FOG_EXP);
   tolua_constant(tolua_S,"FOG_EXP2",Ogre::FOG_EXP2);
   tolua_constant(tolua_S,"FOG_LINEAR",Ogre::FOG_LINEAR);
   tolua_constant(tolua_S,"CULL_NONE",Ogre::CULL_NONE);
   tolua_constant(tolua_S,"CULL_CLOCKWISE",Ogre::CULL_CLOCKWISE);
   tolua_constant(tolua_S,"CULL_ANTICLOCKWISE",Ogre::CULL_ANTICLOCKWISE);
   tolua_constant(tolua_S,"MANUAL_CULL_NONE",Ogre::MANUAL_CULL_NONE);
   tolua_constant(tolua_S,"MANUAL_CULL_BACK",Ogre::MANUAL_CULL_BACK);
   tolua_constant(tolua_S,"MANUAL_CULL_FRONT",Ogre::MANUAL_CULL_FRONT);
   tolua_constant(tolua_S,"SHADOWTYPE_NONE",Ogre::SHADOWTYPE_NONE);
   tolua_constant(tolua_S,"SHADOWDETAILTYPE_ADDITIVE",Ogre::SHADOWDETAILTYPE_ADDITIVE);
   tolua_constant(tolua_S,"SHADOWDETAILTYPE_MODULATIVE",Ogre::SHADOWDETAILTYPE_MODULATIVE);
   tolua_constant(tolua_S,"SHADOWDETAILTYPE_INTEGRATED",Ogre::SHADOWDETAILTYPE_INTEGRATED);
   tolua_constant(tolua_S,"SHADOWDETAILTYPE_STENCIL",Ogre::SHADOWDETAILTYPE_STENCIL);
   tolua_constant(tolua_S,"SHADOWDETAILTYPE_TEXTURE",Ogre::SHADOWDETAILTYPE_TEXTURE);
   tolua_constant(tolua_S,"SHADOWTYPE_STENCIL_MODULATIVE",Ogre::SHADOWTYPE_STENCIL_MODULATIVE);
   tolua_constant(tolua_S,"SHADOWTYPE_STENCIL_ADDITIVE",Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
   tolua_constant(tolua_S,"SHADOWTYPE_TEXTURE_MODULATIVE",Ogre::SHADOWTYPE_TEXTURE_MODULATIVE);
   tolua_constant(tolua_S,"SHADOWTYPE_TEXTURE_ADDITIVE",Ogre::SHADOWTYPE_TEXTURE_ADDITIVE);
   tolua_constant(tolua_S,"SHADOWTYPE_TEXTURE_ADDITIVE_INTEGRATED",Ogre::SHADOWTYPE_TEXTURE_ADDITIVE_INTEGRATED);
   tolua_constant(tolua_S,"SHADOWTYPE_TEXTURE_MODULATIVE_INTEGRATED",Ogre::SHADOWTYPE_TEXTURE_MODULATIVE_INTEGRATED);
   tolua_constant(tolua_S,"PM_POINTS",Ogre::PM_POINTS);
   tolua_constant(tolua_S,"PM_WIREFRAME",Ogre::PM_WIREFRAME);
   tolua_constant(tolua_S,"PM_SOLID",Ogre::PM_SOLID);
   tolua_constant(tolua_S,"RENDER_QUEUE_BACKGROUND",Ogre::RENDER_QUEUE_BACKGROUND);
   tolua_constant(tolua_S,"RENDER_QUEUE_SKIES_EARLY",Ogre::RENDER_QUEUE_SKIES_EARLY);
   tolua_constant(tolua_S,"RENDER_QUEUE_1",Ogre::RENDER_QUEUE_1);
   tolua_constant(tolua_S,"RENDER_QUEUE_2",Ogre::RENDER_QUEUE_2);
   tolua_constant(tolua_S,"RENDER_QUEUE_WORLD_GEOMETRY_1",Ogre::RENDER_QUEUE_WORLD_GEOMETRY_1);
   tolua_constant(tolua_S,"RENDER_QUEUE_3",Ogre::RENDER_QUEUE_3);
   tolua_constant(tolua_S,"RENDER_QUEUE_4",Ogre::RENDER_QUEUE_4);
   tolua_constant(tolua_S,"RENDER_QUEUE_MAIN",Ogre::RENDER_QUEUE_MAIN);
   tolua_constant(tolua_S,"RENDER_QUEUE_6",Ogre::RENDER_QUEUE_6);
   tolua_constant(tolua_S,"RENDER_QUEUE_7",Ogre::RENDER_QUEUE_7);
   tolua_constant(tolua_S,"RENDER_QUEUE_WORLD_GEOMETRY_2",Ogre::RENDER_QUEUE_WORLD_GEOMETRY_2);
   tolua_constant(tolua_S,"RENDER_QUEUE_8",Ogre::RENDER_QUEUE_8);
   tolua_constant(tolua_S,"RENDER_QUEUE_9",Ogre::RENDER_QUEUE_9);
   tolua_constant(tolua_S,"RENDER_QUEUE_SKIES_LATE",Ogre::RENDER_QUEUE_SKIES_LATE);
   tolua_constant(tolua_S,"RENDER_QUEUE_OVERLAY",Ogre::RENDER_QUEUE_OVERLAY);
   tolua_constant(tolua_S,"RENDER_QUEUE_MAX",Ogre::RENDER_QUEUE_MAX);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Vector2","Ogre::Vector2","",tolua_collect_Ogre__Vector2);
   #else
   tolua_cclass(tolua_S,"Vector2","Ogre::Vector2","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Vector2");
    tolua_variable(tolua_S,"x",tolua_get_Ogre__Vector2_x,tolua_set_Ogre__Vector2_x);
    tolua_variable(tolua_S,"y",tolua_get_Ogre__Vector2_y,tolua_set_Ogre__Vector2_y);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Vector2_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Vector2_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Vector2_new00_local);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Vector2_new01);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Vector2_new01_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Vector2_new01_local);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Vector3","Ogre::Vector3","",tolua_collect_Ogre__Vector3);
   #else
   tolua_cclass(tolua_S,"Vector3","Ogre::Vector3","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Vector3");
    tolua_variable(tolua_S,"x",tolua_get_Ogre__Vector3_x,tolua_set_Ogre__Vector3_x);
    tolua_variable(tolua_S,"y",tolua_get_Ogre__Vector3_y,tolua_set_Ogre__Vector3_y);
    tolua_variable(tolua_S,"z",tolua_get_Ogre__Vector3_z,tolua_set_Ogre__Vector3_z);
    tolua_variable(tolua_S,"ZERO",tolua_get_Ogre__Vector3_ZERO,NULL);
    tolua_variable(tolua_S,"UNIT_X",tolua_get_Ogre__Vector3_UNIT_X,NULL);
    tolua_variable(tolua_S,"UNIT_Y",tolua_get_Ogre__Vector3_UNIT_Y,NULL);
    tolua_variable(tolua_S,"UNIT_Z",tolua_get_Ogre__Vector3_UNIT_Z,NULL);
    tolua_variable(tolua_S,"NEGATIVE_UNIT_X",tolua_get_Ogre__Vector3_NEGATIVE_UNIT_X,NULL);
    tolua_variable(tolua_S,"NEGATIVE_UNIT_Y",tolua_get_Ogre__Vector3_NEGATIVE_UNIT_Y,NULL);
    tolua_variable(tolua_S,"NEGATIVE_UNIT_Z",tolua_get_Ogre__Vector3_NEGATIVE_UNIT_Z,NULL);
    tolua_variable(tolua_S,"UNIT_SCALE",tolua_get_Ogre__Vector3_UNIT_SCALE,NULL);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Vector3_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Vector3_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Vector3_new00_local);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Vector3_new01);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Vector3_new01_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Vector3_new01_local);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Degree","Ogre::Degree","",tolua_collect_Ogre__Degree);
   #else
   tolua_cclass(tolua_S,"Degree","Ogre::Degree","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Degree");
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Degree_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Degree_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Degree_new00_local);
    tolua_function(tolua_S,"valueDegrees",tolua_Elementum_Ogre_Degree_valueDegrees00);
    tolua_function(tolua_S,"valueRadians",tolua_Elementum_Ogre_Degree_valueRadians00);
    tolua_function(tolua_S,"valueAngleUnits",tolua_Elementum_Ogre_Degree_valueAngleUnits00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Radian","Ogre::Radian","",tolua_collect_Ogre__Radian);
   #else
   tolua_cclass(tolua_S,"Radian","Ogre::Radian","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Radian");
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Radian_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Radian_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Radian_new00_local);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Radian_new01);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Radian_new01_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Radian_new01_local);
    tolua_function(tolua_S,"valueDegrees",tolua_Elementum_Ogre_Radian_valueDegrees00);
    tolua_function(tolua_S,"valueRadians",tolua_Elementum_Ogre_Radian_valueRadians00);
    tolua_function(tolua_S,"valueAngleUnits",tolua_Elementum_Ogre_Radian_valueAngleUnits00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Angle","Ogre::Angle","",tolua_collect_Ogre__Angle);
   #else
   tolua_cclass(tolua_S,"Angle","Ogre::Angle","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Angle");
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Angle_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Angle_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Angle_new00_local);
    tolua_function(tolua_S,".Radian",tolua_Elementum_Ogre_Angle__Radian00);
    tolua_function(tolua_S,".Degree",tolua_Elementum_Ogre_Angle__Degree00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Quaternion","Ogre::Quaternion","",tolua_collect_Ogre__Quaternion);
   #else
   tolua_cclass(tolua_S,"Quaternion","Ogre::Quaternion","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Quaternion");
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Quaternion_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Quaternion_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Quaternion_new00_local);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Quaternion_new01);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Quaternion_new01_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Quaternion_new01_local);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Quaternion_new02);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Quaternion_new02_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Quaternion_new02_local);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Quaternion_new03);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Quaternion_new03_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Quaternion_new03_local);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Quaternion_new04);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Quaternion_new04_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Quaternion_new04_local);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"ColourValue","Ogre::ColourValue","",tolua_collect_Ogre__ColourValue);
   #else
   tolua_cclass(tolua_S,"ColourValue","Ogre::ColourValue","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"ColourValue");
    tolua_variable(tolua_S,"ZERO",tolua_get_Ogre__ColourValue_ZERO,NULL);
    tolua_variable(tolua_S,"Black",tolua_get_Ogre__ColourValue_Black,NULL);
    tolua_variable(tolua_S,"White",tolua_get_Ogre__ColourValue_White,NULL);
    tolua_variable(tolua_S,"Red",tolua_get_Ogre__ColourValue_Red,NULL);
    tolua_variable(tolua_S,"Green",tolua_get_Ogre__ColourValue_Green,NULL);
    tolua_variable(tolua_S,"Blue",tolua_get_Ogre__ColourValue_Blue,NULL);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_ColourValue_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_ColourValue_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_ColourValue_new00_local);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Plane","Ogre::Plane","",tolua_collect_Ogre__Plane);
   #else
   tolua_cclass(tolua_S,"Plane","Ogre::Plane","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Plane");
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Plane_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Plane_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Plane_new00_local);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Plane_new01);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Plane_new01_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Plane_new01_local);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"AxisAlignedBox","Ogre::AxisAlignedBox","",tolua_collect_Ogre__AxisAlignedBox);
   #else
   tolua_cclass(tolua_S,"AxisAlignedBox","Ogre::AxisAlignedBox","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"AxisAlignedBox");
    tolua_constant(tolua_S,"EXTENT_NULL",Ogre::AxisAlignedBox::EXTENT_NULL);
    tolua_constant(tolua_S,"EXTENT_FINITE",Ogre::AxisAlignedBox::EXTENT_FINITE);
    tolua_constant(tolua_S,"EXTENT_INFINITE",Ogre::AxisAlignedBox::EXTENT_INFINITE);
    tolua_constant(tolua_S,"FAR_LEFT_BOTTOM",Ogre::AxisAlignedBox::FAR_LEFT_BOTTOM);
    tolua_constant(tolua_S,"FAR_LEFT_TOP",Ogre::AxisAlignedBox::FAR_LEFT_TOP);
    tolua_constant(tolua_S,"FAR_RIGHT_TOP",Ogre::AxisAlignedBox::FAR_RIGHT_TOP);
    tolua_constant(tolua_S,"FAR_RIGHT_BOTTOM",Ogre::AxisAlignedBox::FAR_RIGHT_BOTTOM);
    tolua_constant(tolua_S,"NEAR_RIGHT_BOTTOM",Ogre::AxisAlignedBox::NEAR_RIGHT_BOTTOM);
    tolua_constant(tolua_S,"NEAR_LEFT_BOTTOM",Ogre::AxisAlignedBox::NEAR_LEFT_BOTTOM);
    tolua_constant(tolua_S,"NEAR_LEFT_TOP",Ogre::AxisAlignedBox::NEAR_LEFT_TOP);
    tolua_constant(tolua_S,"NEAR_RIGHT_TOP",Ogre::AxisAlignedBox::NEAR_RIGHT_TOP);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_AxisAlignedBox_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_AxisAlignedBox_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_AxisAlignedBox_new00_local);
    tolua_function(tolua_S,"getSize",tolua_Elementum_Ogre_AxisAlignedBox_getSize00);
    tolua_function(tolua_S,"getMaximum",tolua_Elementum_Ogre_AxisAlignedBox_getMaximum00);
    tolua_function(tolua_S,"getMinimum",tolua_Elementum_Ogre_AxisAlignedBox_getMinimum00);
    tolua_function(tolua_S,"getCenter",tolua_Elementum_Ogre_AxisAlignedBox_getCenter00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"SubEntity","Ogre::SubEntity","",NULL);
   tolua_beginmodule(tolua_S,"SubEntity");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"MovableObject","Ogre::MovableObject","",NULL);
   tolua_beginmodule(tolua_S,"MovableObject");
    tolua_function(tolua_S,"setRenderQueueGroup",tolua_Elementum_Ogre_MovableObject_setRenderQueueGroup00);
    tolua_function(tolua_S,"setRenderQueueGroupAndPriority",tolua_Elementum_Ogre_MovableObject_setRenderQueueGroupAndPriority00);
    tolua_function(tolua_S,"getBoundingBox",tolua_Elementum_Ogre_MovableObject_getBoundingBox00);
    tolua_function(tolua_S,"getWorldBoundingBox",tolua_Elementum_Ogre_MovableObject_getWorldBoundingBox00);
    tolua_function(tolua_S,"getMovableType",tolua_Elementum_Ogre_MovableObject_getMovableType00);
    tolua_function(tolua_S,"setQueryFlags",tolua_Elementum_Ogre_MovableObject_setQueryFlags00);
    tolua_function(tolua_S,"setVisibilityFlags",tolua_Elementum_Ogre_MovableObject_setVisibilityFlags00);
    tolua_function(tolua_S,"setUserAny",tolua_Elementum_Ogre_MovableObject_setUserAny00);
    tolua_function(tolua_S,"getUserAny",tolua_Elementum_Ogre_MovableObject_getUserAny00);
    tolua_function(tolua_S,"setCastShadows",tolua_Elementum_Ogre_MovableObject_setCastShadows00);
    tolua_function(tolua_S,"getCastShadows",tolua_Elementum_Ogre_MovableObject_getCastShadows00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Node","Ogre::Node","",NULL);
   tolua_beginmodule(tolua_S,"Node");
    tolua_constant(tolua_S,"TS_LOCAL",Ogre::Node::TS_LOCAL);
    tolua_constant(tolua_S,"TS_PARENT",Ogre::Node::TS_PARENT);
    tolua_constant(tolua_S,"TS_WORLD",Ogre::Node::TS_WORLD);
    tolua_function(tolua_S,"getName",tolua_Elementum_Ogre_Node_getName00);
    tolua_function(tolua_S,"getParent",tolua_Elementum_Ogre_Node_getParent00);
    tolua_function(tolua_S,"setPosition",tolua_Elementum_Ogre_Node_setPosition00);
    tolua_function(tolua_S,"getPosition",tolua_Elementum_Ogre_Node_getPosition00);
    tolua_function(tolua_S,"setScale",tolua_Elementum_Ogre_Node_setScale00);
    tolua_function(tolua_S,"setScale",tolua_Elementum_Ogre_Node_setScale01);
    tolua_function(tolua_S,"getScale",tolua_Elementum_Ogre_Node_getScale00);
    tolua_function(tolua_S,"createChild",tolua_Elementum_Ogre_Node_createChild00);
    tolua_function(tolua_S,"createChild",tolua_Elementum_Ogre_Node_createChild01);
    tolua_function(tolua_S,"createChild",tolua_Elementum_Ogre_Node_createChild02);
    tolua_function(tolua_S,"createChild",tolua_Elementum_Ogre_Node_createChild03);
    tolua_function(tolua_S,"createChild",tolua_Elementum_Ogre_Node_createChild04);
    tolua_function(tolua_S,"createChild",tolua_Elementum_Ogre_Node_createChild05);
    tolua_function(tolua_S,"addChild",tolua_Elementum_Ogre_Node_addChild00);
    tolua_function(tolua_S,"getChildAt",tolua_Elementum_Ogre_Node_getChildAt00);
    tolua_function(tolua_S,"numChildren",tolua_Elementum_Ogre_Node_numChildren00);
    tolua_function(tolua_S,"getChild",tolua_Elementum_Ogre_Node_getChild00);
    tolua_function(tolua_S,"removeChild",tolua_Elementum_Ogre_Node_removeChild00);
    tolua_function(tolua_S,"removeChild",tolua_Elementum_Ogre_Node_removeChild01);
    tolua_function(tolua_S,"removeChild",tolua_Elementum_Ogre_Node_removeChild02);
    tolua_function(tolua_S,"removeAllChildren",tolua_Elementum_Ogre_Node_removeAllChildren00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Entity","Ogre::Entity","Ogre::MovableObject",NULL);
   tolua_beginmodule(tolua_S,"Entity");
    tolua_function(tolua_S,"getSubEntity",tolua_Elementum_Ogre_Entity_getSubEntity00);
    tolua_function(tolua_S,"getSubEntity",tolua_Elementum_Ogre_Entity_getSubEntity01);
    tolua_function(tolua_S,"getNumSubEntities",tolua_Elementum_Ogre_Entity_getNumSubEntities00);
    tolua_function(tolua_S,"setDisplaySkeleton",tolua_Elementum_Ogre_Entity_setDisplaySkeleton00);
    tolua_function(tolua_S,"setMaterialName",tolua_Elementum_Ogre_Entity_setMaterialName00);
    tolua_function(tolua_S,"setMaterialName",tolua_Elementum_Ogre_Entity_setMaterialName01);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"SceneNode","Ogre::SceneNode","Ogre::Node",NULL);
   tolua_beginmodule(tolua_S,"SceneNode");
    tolua_function(tolua_S,"yaw",tolua_Elementum_Ogre_SceneNode_yaw00);
    tolua_function(tolua_S,"pitch",tolua_Elementum_Ogre_SceneNode_pitch00);
    tolua_function(tolua_S,"roll",tolua_Elementum_Ogre_SceneNode_roll00);
    tolua_function(tolua_S,"attachObject",tolua_Elementum_Ogre_SceneNode_attachObject00);
    tolua_function(tolua_S,"numAttachedObjects",tolua_Elementum_Ogre_SceneNode_numAttachedObjects00);
    tolua_function(tolua_S,"getAttachedObjectAt",tolua_Elementum_Ogre_SceneNode_getAttachedObjectAt00);
    tolua_function(tolua_S,"getAttachedObject",tolua_Elementum_Ogre_SceneNode_getAttachedObject00);
    tolua_function(tolua_S,"detachObject",tolua_Elementum_Ogre_SceneNode_detachObject00);
    tolua_function(tolua_S,"detachObject",tolua_Elementum_Ogre_SceneNode_detachObject01);
    tolua_function(tolua_S,"detachObject",tolua_Elementum_Ogre_SceneNode_detachObject02);
    tolua_function(tolua_S,"detachAllObjects",tolua_Elementum_Ogre_SceneNode_detachAllObjects00);
    tolua_function(tolua_S,"getCreator",tolua_Elementum_Ogre_SceneNode_getCreator00);
    tolua_function(tolua_S,"createChildSceneNode",tolua_Elementum_Ogre_SceneNode_createChildSceneNode00);
    tolua_function(tolua_S,"createChildSceneNode",tolua_Elementum_Ogre_SceneNode_createChildSceneNode01);
    tolua_function(tolua_S,"createChildSceneNode",tolua_Elementum_Ogre_SceneNode_createChildSceneNode02);
    tolua_function(tolua_S,"createChildSceneNode",tolua_Elementum_Ogre_SceneNode_createChildSceneNode03);
    tolua_function(tolua_S,"createChildSceneNode",tolua_Elementum_Ogre_SceneNode_createChildSceneNode04);
    tolua_function(tolua_S,"createChildSceneNode",tolua_Elementum_Ogre_SceneNode_createChildSceneNode05);
    tolua_function(tolua_S,"removeAndDestroyChild",tolua_Elementum_Ogre_SceneNode_removeAndDestroyChild00);
    tolua_function(tolua_S,"removeAndDestroyChild",tolua_Elementum_Ogre_SceneNode_removeAndDestroyChild01);
    tolua_function(tolua_S,"removeAndDestroyAllChildren",tolua_Elementum_Ogre_SceneNode_removeAndDestroyAllChildren00);
    tolua_function(tolua_S,"showBoundingBox",tolua_Elementum_Ogre_SceneNode_showBoundingBox00);
    tolua_function(tolua_S,"hideBoundingBox",tolua_Elementum_Ogre_SceneNode_hideBoundingBox00);
    tolua_function(tolua_S,"setDirection",tolua_Elementum_Ogre_SceneNode_setDirection00);
    tolua_function(tolua_S,"setDirection",tolua_Elementum_Ogre_SceneNode_setDirection01);
    tolua_function(tolua_S,"setDirection",tolua_Elementum_Ogre_SceneNode_setDirection02);
    tolua_function(tolua_S,"setDirection",tolua_Elementum_Ogre_SceneNode_setDirection03);
    tolua_function(tolua_S,"lookAt",tolua_Elementum_Ogre_SceneNode_lookAt00);
    tolua_function(tolua_S,"lookAt",tolua_Elementum_Ogre_SceneNode_lookAt01);
    tolua_function(tolua_S,"setAutoTracking",tolua_Elementum_Ogre_SceneNode_setAutoTracking00);
    tolua_function(tolua_S,"setAutoTracking",tolua_Elementum_Ogre_SceneNode_setAutoTracking01);
    tolua_function(tolua_S,"setAutoTracking",tolua_Elementum_Ogre_SceneNode_setAutoTracking02);
    tolua_function(tolua_S,"getAutoTrackTarget",tolua_Elementum_Ogre_SceneNode_getAutoTrackTarget00);
    tolua_function(tolua_S,"getAutoTrackOffset",tolua_Elementum_Ogre_SceneNode_getAutoTrackOffset00);
    tolua_function(tolua_S,"getAutoTrackLocalDirection",tolua_Elementum_Ogre_SceneNode_getAutoTrackLocalDirection00);
    tolua_function(tolua_S,"getParentSceneNode",tolua_Elementum_Ogre_SceneNode_getParentSceneNode00);
    tolua_function(tolua_S,"setVisible",tolua_Elementum_Ogre_SceneNode_setVisible00);
    tolua_function(tolua_S,"flipVisibility",tolua_Elementum_Ogre_SceneNode_flipVisibility00);
    tolua_function(tolua_S,"setOrientation",tolua_Elementum_Ogre_SceneNode_setOrientation00);
    tolua_function(tolua_S,"setOrientation",tolua_Elementum_Ogre_SceneNode_setOrientation01);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Light","Ogre::Light","Ogre::MovableObject",tolua_collect_Ogre__Light);
   #else
   tolua_cclass(tolua_S,"Light","Ogre::Light","Ogre::MovableObject",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Light");
    tolua_constant(tolua_S,"LT_POINT",Ogre::Light::LT_POINT);
    tolua_constant(tolua_S,"LT_DIRECTIONAL",Ogre::Light::LT_DIRECTIONAL);
    tolua_constant(tolua_S,"LT_SPOTLIGHT",Ogre::Light::LT_SPOTLIGHT);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Light_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Light_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Light_new00_local);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Light_new01);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Light_new01_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Light_new01_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Ogre_Light_delete00);
    tolua_function(tolua_S,"setType",tolua_Elementum_Ogre_Light_setType00);
    tolua_function(tolua_S,"getType",tolua_Elementum_Ogre_Light_getType00);
    tolua_function(tolua_S,"setDiffuseColour",tolua_Elementum_Ogre_Light_setDiffuseColour00);
    tolua_function(tolua_S,"setDiffuseColour",tolua_Elementum_Ogre_Light_setDiffuseColour01);
    tolua_function(tolua_S,"getDiffuseColour",tolua_Elementum_Ogre_Light_getDiffuseColour00);
    tolua_function(tolua_S,"setSpecularColour",tolua_Elementum_Ogre_Light_setSpecularColour00);
    tolua_function(tolua_S,"setSpecularColour",tolua_Elementum_Ogre_Light_setSpecularColour01);
    tolua_function(tolua_S,"getSpecularColour",tolua_Elementum_Ogre_Light_getSpecularColour00);
    tolua_function(tolua_S,"setAttenuation",tolua_Elementum_Ogre_Light_setAttenuation00);
    tolua_function(tolua_S,"getAttenuationRange",tolua_Elementum_Ogre_Light_getAttenuationRange00);
    tolua_function(tolua_S,"getAttenuationConstant",tolua_Elementum_Ogre_Light_getAttenuationConstant00);
    tolua_function(tolua_S,"getAttenuationLinear",tolua_Elementum_Ogre_Light_getAttenuationLinear00);
    tolua_function(tolua_S,"getAttenuationQuadric",tolua_Elementum_Ogre_Light_getAttenuationQuadric00);
    tolua_function(tolua_S,"setPosition",tolua_Elementum_Ogre_Light_setPosition00);
    tolua_function(tolua_S,"setPosition",tolua_Elementum_Ogre_Light_setPosition01);
    tolua_function(tolua_S,"getPosition",tolua_Elementum_Ogre_Light_getPosition00);
    tolua_function(tolua_S,"setDirection",tolua_Elementum_Ogre_Light_setDirection00);
    tolua_function(tolua_S,"setDirection",tolua_Elementum_Ogre_Light_setDirection01);
    tolua_function(tolua_S,"getDirection",tolua_Elementum_Ogre_Light_getDirection00);
    tolua_function(tolua_S,"setSpotlightRange",tolua_Elementum_Ogre_Light_setSpotlightRange00);
    tolua_function(tolua_S,"getSpotlightInnerAngle",tolua_Elementum_Ogre_Light_getSpotlightInnerAngle00);
    tolua_function(tolua_S,"getSpotlightOuterAngle",tolua_Elementum_Ogre_Light_getSpotlightOuterAngle00);
    tolua_function(tolua_S,"getSpotlightFalloff",tolua_Elementum_Ogre_Light_getSpotlightFalloff00);
    tolua_function(tolua_S,"setSpotlightInnerAngle",tolua_Elementum_Ogre_Light_setSpotlightInnerAngle00);
    tolua_function(tolua_S,"setSpotlightOuterAngle",tolua_Elementum_Ogre_Light_setSpotlightOuterAngle00);
    tolua_function(tolua_S,"setSpotlightFalloff",tolua_Elementum_Ogre_Light_setSpotlightFalloff00);
    tolua_function(tolua_S,"setPowerScale",tolua_Elementum_Ogre_Light_setPowerScale00);
    tolua_function(tolua_S,"getPowerScale",tolua_Elementum_Ogre_Light_getPowerScale00);
    tolua_function(tolua_S,"getBoundingBox",tolua_Elementum_Ogre_Light_getBoundingBox00);
    tolua_function(tolua_S,"getMovableType",tolua_Elementum_Ogre_Light_getMovableType00);
    tolua_function(tolua_S,"getDerivedPosition",tolua_Elementum_Ogre_Light_getDerivedPosition00);
    tolua_function(tolua_S,"getDerivedDirection",tolua_Elementum_Ogre_Light_getDerivedDirection00);
    tolua_function(tolua_S,"setVisible",tolua_Elementum_Ogre_Light_setVisible00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Camera","Ogre::Camera","",tolua_collect_Ogre__Camera);
   #else
   tolua_cclass(tolua_S,"Camera","Ogre::Camera","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Camera");
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Camera_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Camera_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Camera_new00_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Ogre_Camera_delete00);
    tolua_function(tolua_S,"getSceneManager",tolua_Elementum_Ogre_Camera_getSceneManager00);
    tolua_function(tolua_S,"setAspectRatio",tolua_Elementum_Ogre_Camera_setAspectRatio00);
    tolua_function(tolua_S,"setNearClipDistance",tolua_Elementum_Ogre_Camera_setNearClipDistance00);
    tolua_function(tolua_S,"getNearClipDistance",tolua_Elementum_Ogre_Camera_getNearClipDistance00);
    tolua_function(tolua_S,"setFarClipDistance",tolua_Elementum_Ogre_Camera_setFarClipDistance00);
    tolua_function(tolua_S,"getFarClipDistance",tolua_Elementum_Ogre_Camera_getFarClipDistance00);
    tolua_function(tolua_S,"setPolygonMode",tolua_Elementum_Ogre_Camera_setPolygonMode00);
    tolua_function(tolua_S,"getPolygonMode",tolua_Elementum_Ogre_Camera_getPolygonMode00);
    tolua_function(tolua_S,"setPosition",tolua_Elementum_Ogre_Camera_setPosition00);
    tolua_function(tolua_S,"setPosition",tolua_Elementum_Ogre_Camera_setPosition01);
    tolua_function(tolua_S,"getPosition",tolua_Elementum_Ogre_Camera_getPosition00);
    tolua_function(tolua_S,"move",tolua_Elementum_Ogre_Camera_move00);
    tolua_function(tolua_S,"moveRelative",tolua_Elementum_Ogre_Camera_moveRelative00);
    tolua_function(tolua_S,"setDirection",tolua_Elementum_Ogre_Camera_setDirection00);
    tolua_function(tolua_S,"setDirection",tolua_Elementum_Ogre_Camera_setDirection01);
    tolua_function(tolua_S,"getDirection",tolua_Elementum_Ogre_Camera_getDirection00);
    tolua_function(tolua_S,"getUp",tolua_Elementum_Ogre_Camera_getUp00);
    tolua_function(tolua_S,"getRight",tolua_Elementum_Ogre_Camera_getRight00);
    tolua_function(tolua_S,"lookAt",tolua_Elementum_Ogre_Camera_lookAt00);
    tolua_function(tolua_S,"lookAt",tolua_Elementum_Ogre_Camera_lookAt01);
    tolua_function(tolua_S,"roll",tolua_Elementum_Ogre_Camera_roll00);
    tolua_function(tolua_S,"yaw",tolua_Elementum_Ogre_Camera_yaw00);
    tolua_function(tolua_S,"pitch",tolua_Elementum_Ogre_Camera_pitch00);
    tolua_function(tolua_S,"rotate",tolua_Elementum_Ogre_Camera_rotate00);
    tolua_function(tolua_S,"rotate",tolua_Elementum_Ogre_Camera_rotate01);
    tolua_function(tolua_S,"setFixedYawAxis",tolua_Elementum_Ogre_Camera_setFixedYawAxis00);
    tolua_function(tolua_S,"setFixedYawAxis",tolua_Elementum_Ogre_Camera_setFixedYawAxis01);
    tolua_function(tolua_S,"getOrientation",tolua_Elementum_Ogre_Camera_getOrientation00);
    tolua_function(tolua_S,"setOrientation",tolua_Elementum_Ogre_Camera_setOrientation00);
    tolua_function(tolua_S,"getViewport",tolua_Elementum_Ogre_Camera_getViewport00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"StaticGeometry","Ogre::StaticGeometry","",NULL);
   tolua_beginmodule(tolua_S,"StaticGeometry");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"InstancedGeometry","Ogre::InstancedGeometry","",NULL);
   tolua_beginmodule(tolua_S,"InstancedGeometry");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Renderable","Ogre::Renderable","",NULL);
   tolua_beginmodule(tolua_S,"Renderable");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"RibbonTrail","Ogre::RibbonTrail","",NULL);
   tolua_beginmodule(tolua_S,"RibbonTrail");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"RenderTarget","Ogre::RenderTarget","",NULL);
   tolua_beginmodule(tolua_S,"RenderTarget");
    tolua_cclass(tolua_S,"FrameStats","Ogre::RenderTarget::FrameStats","",NULL);
    tolua_beginmodule(tolua_S,"FrameStats");
     tolua_variable(tolua_S,"lastFPS",tolua_get_Ogre__RenderTarget__FrameStats_lastFPS,tolua_set_Ogre__RenderTarget__FrameStats_lastFPS);
     tolua_variable(tolua_S,"avgFPS",tolua_get_Ogre__RenderTarget__FrameStats_avgFPS,tolua_set_Ogre__RenderTarget__FrameStats_avgFPS);
     tolua_variable(tolua_S,"bestFPS",tolua_get_Ogre__RenderTarget__FrameStats_bestFPS,tolua_set_Ogre__RenderTarget__FrameStats_bestFPS);
     tolua_variable(tolua_S,"worstFPS",tolua_get_Ogre__RenderTarget__FrameStats_worstFPS,tolua_set_Ogre__RenderTarget__FrameStats_worstFPS);
     tolua_variable(tolua_S,"bestFrameTime",tolua_get_Ogre__RenderTarget__FrameStats_unsigned_bestFrameTime,tolua_set_Ogre__RenderTarget__FrameStats_unsigned_bestFrameTime);
     tolua_variable(tolua_S,"worstFrameTime",tolua_get_Ogre__RenderTarget__FrameStats_unsigned_worstFrameTime,tolua_set_Ogre__RenderTarget__FrameStats_unsigned_worstFrameTime);
     tolua_variable(tolua_S,"triangleCount",tolua_get_Ogre__RenderTarget__FrameStats_triangleCount,tolua_set_Ogre__RenderTarget__FrameStats_triangleCount);
     tolua_variable(tolua_S,"batchCount",tolua_get_Ogre__RenderTarget__FrameStats_batchCount,tolua_set_Ogre__RenderTarget__FrameStats_batchCount);
    tolua_endmodule(tolua_S);
    tolua_function(tolua_S,"getName",tolua_Elementum_Ogre_RenderTarget_getName00);
    tolua_function(tolua_S,"getMetrics",tolua_Elementum_Ogre_RenderTarget_getMetrics00);
    tolua_function(tolua_S,"getWidth",tolua_Elementum_Ogre_RenderTarget_getWidth00);
    tolua_function(tolua_S,"getHeight",tolua_Elementum_Ogre_RenderTarget_getHeight00);
    tolua_function(tolua_S,"getColourDepth",tolua_Elementum_Ogre_RenderTarget_getColourDepth00);
    tolua_function(tolua_S,"writeContentsToFile",tolua_Elementum_Ogre_RenderTarget_writeContentsToFile00);
    tolua_function(tolua_S,"writeContentsToTimestampedFile",tolua_Elementum_Ogre_RenderTarget_writeContentsToTimestampedFile00);
    tolua_function(tolua_S,"addViewport",tolua_Elementum_Ogre_RenderTarget_addViewport00);
    tolua_function(tolua_S,"getNumViewports",tolua_Elementum_Ogre_RenderTarget_getNumViewports00);
    tolua_function(tolua_S,"getViewport",tolua_Elementum_Ogre_RenderTarget_getViewport00);
    tolua_function(tolua_S,"getViewportByZOrder",tolua_Elementum_Ogre_RenderTarget_getViewportByZOrder00);
    tolua_function(tolua_S,"hasViewportWithZOrder",tolua_Elementum_Ogre_RenderTarget_hasViewportWithZOrder00);
    tolua_function(tolua_S,"removeViewport",tolua_Elementum_Ogre_RenderTarget_removeViewport00);
    tolua_function(tolua_S,"removeAllViewports",tolua_Elementum_Ogre_RenderTarget_removeAllViewports00);
    tolua_function(tolua_S,"getStatistics",tolua_Elementum_Ogre_RenderTarget_getStatistics00);
    tolua_function(tolua_S,"getStatistics",tolua_Elementum_Ogre_RenderTarget_getStatistics01);
    tolua_function(tolua_S,"getLastFPS",tolua_Elementum_Ogre_RenderTarget_getLastFPS00);
    tolua_function(tolua_S,"getAverageFPS",tolua_Elementum_Ogre_RenderTarget_getAverageFPS00);
    tolua_function(tolua_S,"getBestFPS",tolua_Elementum_Ogre_RenderTarget_getBestFPS00);
    tolua_function(tolua_S,"getWorstFPS",tolua_Elementum_Ogre_RenderTarget_getWorstFPS00);
    tolua_function(tolua_S,"getBestFrameTime",tolua_Elementum_Ogre_RenderTarget_getBestFrameTime00);
    tolua_function(tolua_S,"getWorstFrameTime",tolua_Elementum_Ogre_RenderTarget_getWorstFrameTime00);
    tolua_function(tolua_S,"resetStatistics",tolua_Elementum_Ogre_RenderTarget_resetStatistics00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"RenderWindow","Ogre::RenderWindow","Ogre::RenderTarget",tolua_collect_Ogre__RenderWindow);
   #else
   tolua_cclass(tolua_S,"RenderWindow","Ogre::RenderWindow","Ogre::RenderTarget",NULL);
   #endif
   tolua_beginmodule(tolua_S,"RenderWindow");
    tolua_function(tolua_S,"setFullscreen",tolua_Elementum_Ogre_RenderWindow_setFullscreen00);
    tolua_function(tolua_S,"destroy",tolua_Elementum_Ogre_RenderWindow_destroy00);
    tolua_function(tolua_S,"resize",tolua_Elementum_Ogre_RenderWindow_resize00);
    tolua_function(tolua_S,"windowMovedOrResized",tolua_Elementum_Ogre_RenderWindow_windowMovedOrResized00);
    tolua_function(tolua_S,"reposition",tolua_Elementum_Ogre_RenderWindow_reposition00);
    tolua_function(tolua_S,"isVisible",tolua_Elementum_Ogre_RenderWindow_isVisible00);
    tolua_function(tolua_S,"setVisible",tolua_Elementum_Ogre_RenderWindow_setVisible00);
    tolua_function(tolua_S,"isHidden",tolua_Elementum_Ogre_RenderWindow_isHidden00);
    tolua_function(tolua_S,"setHidden",tolua_Elementum_Ogre_RenderWindow_setHidden00);
    tolua_function(tolua_S,"setVSyncEnabled",tolua_Elementum_Ogre_RenderWindow_setVSyncEnabled00);
    tolua_function(tolua_S,"isVSyncEnabled",tolua_Elementum_Ogre_RenderWindow_isVSyncEnabled00);
    tolua_function(tolua_S,"setVSyncInterval",tolua_Elementum_Ogre_RenderWindow_setVSyncInterval00);
    tolua_function(tolua_S,"getVSyncInterval",tolua_Elementum_Ogre_RenderWindow_getVSyncInterval00);
    tolua_function(tolua_S,"isActive",tolua_Elementum_Ogre_RenderWindow_isActive00);
    tolua_function(tolua_S,"isClosed",tolua_Elementum_Ogre_RenderWindow_isClosed00);
    tolua_function(tolua_S,"isPrimary",tolua_Elementum_Ogre_RenderWindow_isPrimary00);
    tolua_function(tolua_S,"isFullScreen",tolua_Elementum_Ogre_RenderWindow_isFullScreen00);
    tolua_function(tolua_S,"getMetrics",tolua_Elementum_Ogre_RenderWindow_getMetrics00);
    tolua_function(tolua_S,"suggestPixelFormat",tolua_Elementum_Ogre_RenderWindow_suggestPixelFormat00);
    tolua_function(tolua_S,"isDeactivatedOnFocusChange",tolua_Elementum_Ogre_RenderWindow_isDeactivatedOnFocusChange00);
    tolua_function(tolua_S,"setDeactivateOnFocusChange",tolua_Elementum_Ogre_RenderWindow_setDeactivateOnFocusChange00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"SceneManager","Ogre::SceneManager","",NULL);
   tolua_beginmodule(tolua_S,"SceneManager");
    tolua_function(tolua_S,"createCamera",tolua_Elementum_Ogre_SceneManager_createCamera00);
    tolua_function(tolua_S,"getCamera",tolua_Elementum_Ogre_SceneManager_getCamera00);
    tolua_function(tolua_S,"hasCamera",tolua_Elementum_Ogre_SceneManager_hasCamera00);
    tolua_function(tolua_S,"destroyAllCameras",tolua_Elementum_Ogre_SceneManager_destroyAllCameras00);
    tolua_function(tolua_S,"destroyCamera",tolua_Elementum_Ogre_SceneManager_destroyCamera00);
    tolua_function(tolua_S,"createLight",tolua_Elementum_Ogre_SceneManager_createLight00);
    tolua_function(tolua_S,"createLight",tolua_Elementum_Ogre_SceneManager_createLight01);
    tolua_function(tolua_S,"getLight",tolua_Elementum_Ogre_SceneManager_getLight00);
    tolua_function(tolua_S,"hasLight",tolua_Elementum_Ogre_SceneManager_hasLight00);
    tolua_function(tolua_S,"destroyLight",tolua_Elementum_Ogre_SceneManager_destroyLight00);
    tolua_function(tolua_S,"destroyLight",tolua_Elementum_Ogre_SceneManager_destroyLight01);
    tolua_function(tolua_S,"destroyAllLights",tolua_Elementum_Ogre_SceneManager_destroyAllLights00);
    tolua_function(tolua_S,"setAmbientLight",tolua_Elementum_Ogre_SceneManager_setAmbientLight00);
    tolua_function(tolua_S,"getAmbientLight",tolua_Elementum_Ogre_SceneManager_getAmbientLight00);
    tolua_function(tolua_S,"setWorldGeometry",tolua_Elementum_Ogre_SceneManager_setWorldGeometry00);
    tolua_function(tolua_S,"clearScene",tolua_Elementum_Ogre_SceneManager_clearScene00);
    tolua_function(tolua_S,"createSceneNode",tolua_Elementum_Ogre_SceneManager_createSceneNode00);
    tolua_function(tolua_S,"createSceneNode",tolua_Elementum_Ogre_SceneManager_createSceneNode01);
    tolua_function(tolua_S,"destroySceneNode",tolua_Elementum_Ogre_SceneManager_destroySceneNode00);
    tolua_function(tolua_S,"destroySceneNode",tolua_Elementum_Ogre_SceneManager_destroySceneNode01);
    tolua_function(tolua_S,"getRootSceneNode",tolua_Elementum_Ogre_SceneManager_getRootSceneNode00);
    tolua_function(tolua_S,"getSceneNode",tolua_Elementum_Ogre_SceneManager_getSceneNode00);
    tolua_function(tolua_S,"hasSceneNode",tolua_Elementum_Ogre_SceneManager_hasSceneNode00);
    tolua_function(tolua_S,"createEntity",tolua_Elementum_Ogre_SceneManager_createEntity00);
    tolua_function(tolua_S,"createEntity",tolua_Elementum_Ogre_SceneManager_createEntity01);
    tolua_function(tolua_S,"createEntity",tolua_Elementum_Ogre_SceneManager_createEntity02);
    tolua_function(tolua_S,"getEntity",tolua_Elementum_Ogre_SceneManager_getEntity00);
    tolua_function(tolua_S,"hasEntity",tolua_Elementum_Ogre_SceneManager_hasEntity00);
    tolua_function(tolua_S,"destroyEntity",tolua_Elementum_Ogre_SceneManager_destroyEntity00);
    tolua_function(tolua_S,"destroyEntity",tolua_Elementum_Ogre_SceneManager_destroyEntity01);
    tolua_function(tolua_S,"destroyAllEntities",tolua_Elementum_Ogre_SceneManager_destroyAllEntities00);
    tolua_function(tolua_S,"setSkyPlane",tolua_Elementum_Ogre_SceneManager_setSkyPlane00);
    tolua_function(tolua_S,"setSkyPlane",tolua_Elementum_Ogre_SceneManager_setSkyPlane01);
    tolua_function(tolua_S,"setSkyPlaneEnabled",tolua_Elementum_Ogre_SceneManager_setSkyPlaneEnabled00);
    tolua_function(tolua_S,"isSkyPlaneEnabled",tolua_Elementum_Ogre_SceneManager_isSkyPlaneEnabled00);
    tolua_function(tolua_S,"getSkyPlaneNode",tolua_Elementum_Ogre_SceneManager_getSkyPlaneNode00);
    tolua_function(tolua_S,"setSkyBox",tolua_Elementum_Ogre_SceneManager_setSkyBox00);
    tolua_function(tolua_S,"setSkyBox",tolua_Elementum_Ogre_SceneManager_setSkyBox01);
    tolua_function(tolua_S,"setSkyBox",tolua_Elementum_Ogre_SceneManager_setSkyBox02);
    tolua_function(tolua_S,"setSkyBoxEnabled",tolua_Elementum_Ogre_SceneManager_setSkyBoxEnabled00);
    tolua_function(tolua_S,"isSkyBoxEnabled",tolua_Elementum_Ogre_SceneManager_isSkyBoxEnabled00);
    tolua_function(tolua_S,"getSkyBoxNode",tolua_Elementum_Ogre_SceneManager_getSkyBoxNode00);
    tolua_function(tolua_S,"setSkyDome",tolua_Elementum_Ogre_SceneManager_setSkyDome00);
    tolua_function(tolua_S,"setSkyDome",tolua_Elementum_Ogre_SceneManager_setSkyDome01);
    tolua_function(tolua_S,"setSkyDome",tolua_Elementum_Ogre_SceneManager_setSkyDome02);
    tolua_function(tolua_S,"setFog",tolua_Elementum_Ogre_SceneManager_setFog00);
    tolua_function(tolua_S,"setFog",tolua_Elementum_Ogre_SceneManager_setFog01);
    tolua_function(tolua_S,"getFogMode",tolua_Elementum_Ogre_SceneManager_getFogMode00);
    tolua_function(tolua_S,"getFogColour",tolua_Elementum_Ogre_SceneManager_getFogColour00);
    tolua_function(tolua_S,"getFogStart",tolua_Elementum_Ogre_SceneManager_getFogStart00);
    tolua_function(tolua_S,"getFogEnd",tolua_Elementum_Ogre_SceneManager_getFogEnd00);
    tolua_function(tolua_S,"getFogDensity",tolua_Elementum_Ogre_SceneManager_getFogDensity00);
    tolua_function(tolua_S,"setShadowTechnique",tolua_Elementum_Ogre_SceneManager_setShadowTechnique00);
    tolua_function(tolua_S,"getShadowTechnique",tolua_Elementum_Ogre_SceneManager_getShadowTechnique00);
    tolua_function(tolua_S,"setShadowColour",tolua_Elementum_Ogre_SceneManager_setShadowColour00);
    tolua_function(tolua_S,"getShadowColour",tolua_Elementum_Ogre_SceneManager_getShadowColour00);
    tolua_function(tolua_S,"createStaticGeometry",tolua_Elementum_Ogre_SceneManager_createStaticGeometry00);
    tolua_function(tolua_S,"getStaticGeometry",tolua_Elementum_Ogre_SceneManager_getStaticGeometry00);
    tolua_function(tolua_S,"hasStaticGeometry",tolua_Elementum_Ogre_SceneManager_hasStaticGeometry00);
    tolua_function(tolua_S,"destroyStaticGeometry",tolua_Elementum_Ogre_SceneManager_destroyStaticGeometry00);
    tolua_function(tolua_S,"destroyStaticGeometry",tolua_Elementum_Ogre_SceneManager_destroyStaticGeometry01);
    tolua_function(tolua_S,"destroyAllStaticGeometry",tolua_Elementum_Ogre_SceneManager_destroyAllStaticGeometry00);
    tolua_function(tolua_S,"createInstancedGeometry",tolua_Elementum_Ogre_SceneManager_createInstancedGeometry00);
    tolua_function(tolua_S,"getInstancedGeometry",tolua_Elementum_Ogre_SceneManager_getInstancedGeometry00);
    tolua_function(tolua_S,"destroyInstancedGeometry",tolua_Elementum_Ogre_SceneManager_destroyInstancedGeometry00);
    tolua_function(tolua_S,"destroyInstancedGeometry",tolua_Elementum_Ogre_SceneManager_destroyInstancedGeometry01);
    tolua_function(tolua_S,"destroyAllInstancedGeometry",tolua_Elementum_Ogre_SceneManager_destroyAllInstancedGeometry00);
    tolua_function(tolua_S,"createRibbonTrail",tolua_Elementum_Ogre_SceneManager_createRibbonTrail00);
    tolua_function(tolua_S,"createRibbonTrail",tolua_Elementum_Ogre_SceneManager_createRibbonTrail01);
    tolua_function(tolua_S,"getRibbonTrail",tolua_Elementum_Ogre_SceneManager_getRibbonTrail00);
    tolua_function(tolua_S,"hasRibbonTrail",tolua_Elementum_Ogre_SceneManager_hasRibbonTrail00);
    tolua_function(tolua_S,"destroyRibbonTrail",tolua_Elementum_Ogre_SceneManager_destroyRibbonTrail00);
    tolua_function(tolua_S,"destroyRibbonTrail",tolua_Elementum_Ogre_SceneManager_destroyRibbonTrail01);
    tolua_function(tolua_S,"destroyAllRibbonTrails",tolua_Elementum_Ogre_SceneManager_destroyAllRibbonTrails00);
    tolua_function(tolua_S,"createBillboardSet",tolua_Elementum_Ogre_SceneManager_createBillboardSet00);
    tolua_function(tolua_S,"createBillboardSet",tolua_Elementum_Ogre_SceneManager_createBillboardSet01);
    tolua_function(tolua_S,"getBillboardSet",tolua_Elementum_Ogre_SceneManager_getBillboardSet00);
    tolua_function(tolua_S,"hasBillboardSet",tolua_Elementum_Ogre_SceneManager_hasBillboardSet00);
    tolua_function(tolua_S,"destroyBillboardSet",tolua_Elementum_Ogre_SceneManager_destroyBillboardSet00);
    tolua_function(tolua_S,"destroyBillboardSet",tolua_Elementum_Ogre_SceneManager_destroyBillboardSet01);
    tolua_function(tolua_S,"destroyAllBillboardSets",tolua_Elementum_Ogre_SceneManager_destroyAllBillboardSets00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Viewport","Ogre::Viewport","",NULL);
   tolua_beginmodule(tolua_S,"Viewport");
    tolua_function(tolua_S,"getActualDimensions",tolua_Elementum_Ogre_Viewport_getActualDimensions00);
    tolua_function(tolua_S,"getCamera",tolua_Elementum_Ogre_Viewport_getCamera00);
    tolua_function(tolua_S,"setCamera",tolua_Elementum_Ogre_Viewport_setCamera00);
    tolua_function(tolua_S,"getLeft",tolua_Elementum_Ogre_Viewport_getLeft00);
    tolua_function(tolua_S,"getTop",tolua_Elementum_Ogre_Viewport_getTop00);
    tolua_function(tolua_S,"getWidth",tolua_Elementum_Ogre_Viewport_getWidth00);
    tolua_function(tolua_S,"getHeight",tolua_Elementum_Ogre_Viewport_getHeight00);
    tolua_function(tolua_S,"getActualLeft",tolua_Elementum_Ogre_Viewport_getActualLeft00);
    tolua_function(tolua_S,"getActualTop",tolua_Elementum_Ogre_Viewport_getActualTop00);
    tolua_function(tolua_S,"getActualWidth",tolua_Elementum_Ogre_Viewport_getActualWidth00);
    tolua_function(tolua_S,"getActualHeight",tolua_Elementum_Ogre_Viewport_getActualHeight00);
    tolua_function(tolua_S,"setBackgroundColour",tolua_Elementum_Ogre_Viewport_setBackgroundColour00);
    tolua_function(tolua_S,"getBackgroundColour",tolua_Elementum_Ogre_Viewport_getBackgroundColour00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"MeshPtr","Ogre::MeshPtr","",tolua_collect_Ogre__MeshPtr);
   #else
   tolua_cclass(tolua_S,"MeshPtr","Ogre::MeshPtr","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"MeshPtr");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"MeshManager","Ogre::MeshManager","",NULL);
   tolua_beginmodule(tolua_S,"MeshManager");
    tolua_function(tolua_S,"getSingleton",tolua_Elementum_Ogre_MeshManager_getSingleton00);
    tolua_function(tolua_S,"createPlane",tolua_Elementum_Ogre_MeshManager_createPlane00);
    tolua_function(tolua_S,"createPlane",tolua_Elementum_Ogre_MeshManager_createPlane01);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"ResourceGroupManager","Ogre::ResourceGroupManager","",NULL);
   tolua_beginmodule(tolua_S,"ResourceGroupManager");
    tolua_function(tolua_S,"getSingleton",tolua_Elementum_Ogre_ResourceGroupManager_getSingleton00);
    tolua_variable(tolua_S,"DEFAULT_RESOURCE_GROUP_NAME",tolua_get_Ogre__ResourceGroupManager_DEFAULT_RESOURCE_GROUP_NAME,tolua_set_Ogre__ResourceGroupManager_DEFAULT_RESOURCE_GROUP_NAME);
    tolua_variable(tolua_S,"INTERNAL_RESOURCE_GROUP_NAME",tolua_get_Ogre__ResourceGroupManager_INTERNAL_RESOURCE_GROUP_NAME,tolua_set_Ogre__ResourceGroupManager_INTERNAL_RESOURCE_GROUP_NAME);
    tolua_variable(tolua_S,"AUTODETECT_RESOURCE_GROUP_NAME",tolua_get_Ogre__ResourceGroupManager_AUTODETECT_RESOURCE_GROUP_NAME,tolua_set_Ogre__ResourceGroupManager_AUTODETECT_RESOURCE_GROUP_NAME);
    tolua_variable(tolua_S,"RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS",tolua_get_Ogre__ResourceGroupManager_RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS,tolua_set_Ogre__ResourceGroupManager_RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"ManualResourceLoader","Ogre::ManualResourceLoader","",NULL);
   tolua_beginmodule(tolua_S,"ManualResourceLoader");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Resource","Ogre::Resource","",NULL);
   tolua_beginmodule(tolua_S,"Resource");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"ResourceManager","Ogre::ResourceManager","",NULL);
   tolua_beginmodule(tolua_S,"ResourceManager");
    tolua_function(tolua_S,"remove",tolua_Elementum_Ogre_ResourceManager_remove00);
    tolua_function(tolua_S,"resourceExists",tolua_Elementum_Ogre_ResourceManager_resourceExists00);
    tolua_function(tolua_S,"prepare",tolua_Elementum_Ogre_ResourceManager_prepare00);
    tolua_function(tolua_S,"load",tolua_Elementum_Ogre_ResourceManager_load00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"CompositorInstance","Ogre::CompositorInstance","",NULL);
   tolua_beginmodule(tolua_S,"CompositorInstance");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"CompositorLogic","Ogre::CompositorLogic","",NULL);
   tolua_beginmodule(tolua_S,"CompositorLogic");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"CompositorManager","Ogre::CompositorManager","",NULL);
   tolua_beginmodule(tolua_S,"CompositorManager");
    tolua_function(tolua_S,"initialise",tolua_Elementum_Ogre_CompositorManager_initialise00);
    tolua_function(tolua_S,"addCompositor",tolua_Elementum_Ogre_CompositorManager_addCompositor00);
    tolua_function(tolua_S,"removeCompositor",tolua_Elementum_Ogre_CompositorManager_removeCompositor00);
    tolua_function(tolua_S,"setCompositorEnabled",tolua_Elementum_Ogre_CompositorManager_setCompositorEnabled00);
    tolua_function(tolua_S,"freePooledTextures",tolua_Elementum_Ogre_CompositorManager_freePooledTextures00);
    tolua_function(tolua_S,"registerCompositorLogic",tolua_Elementum_Ogre_CompositorManager_registerCompositorLogic00);
    tolua_function(tolua_S,"unregisterCompositorLogic",tolua_Elementum_Ogre_CompositorManager_unregisterCompositorLogic00);
    tolua_function(tolua_S,"getCompositorLogic",tolua_Elementum_Ogre_CompositorManager_getCompositorLogic00);
    tolua_function(tolua_S,"getSingleton",tolua_Elementum_Ogre_CompositorManager_getSingleton00);
    tolua_function(tolua_S,"getSingletonPtr",tolua_Elementum_Ogre_CompositorManager_getSingletonPtr00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Ogre",0);
  tolua_beginmodule(tolua_S,"Ogre");
   tolua_constant(tolua_S,"BBO_TOP_LEFT",Ogre::BBO_TOP_LEFT);
   tolua_constant(tolua_S,"BBO_TOP_CENTER",Ogre::BBO_TOP_CENTER);
   tolua_constant(tolua_S,"BBO_TOP_RIGHT",Ogre::BBO_TOP_RIGHT);
   tolua_constant(tolua_S,"BBO_CENTER_LEFT",Ogre::BBO_CENTER_LEFT);
   tolua_constant(tolua_S,"BBO_CENTER",Ogre::BBO_CENTER);
   tolua_constant(tolua_S,"BBO_CENTER_RIGHT",Ogre::BBO_CENTER_RIGHT);
   tolua_constant(tolua_S,"BBO_BOTTOM_LEFT",Ogre::BBO_BOTTOM_LEFT);
   tolua_constant(tolua_S,"BBO_BOTTOM_CENTER",Ogre::BBO_BOTTOM_CENTER);
   tolua_constant(tolua_S,"BBO_BOTTOM_RIGHT",Ogre::BBO_BOTTOM_RIGHT);
   tolua_constant(tolua_S,"BBR_VERTEX",Ogre::BBR_VERTEX);
   tolua_constant(tolua_S,"BBR_TEXCOORD",Ogre::BBR_TEXCOORD);
   tolua_constant(tolua_S,"BBT_POINT",Ogre::BBT_POINT);
   tolua_constant(tolua_S,"BBT_ORIENTED_COMMON",Ogre::BBT_ORIENTED_COMMON);
   tolua_constant(tolua_S,"BBT_ORIENTED_SELF",Ogre::BBT_ORIENTED_SELF);
   tolua_constant(tolua_S,"BBT_PERPENDICULAR_COMMON",Ogre::BBT_PERPENDICULAR_COMMON);
   tolua_constant(tolua_S,"BBT_PERPENDICULAR_SELF",Ogre::BBT_PERPENDICULAR_SELF);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"BillboardSet","Ogre::BillboardSet","Ogre::MovableObject",tolua_collect_Ogre__BillboardSet);
   #else
   tolua_cclass(tolua_S,"BillboardSet","Ogre::BillboardSet","Ogre::MovableObject",NULL);
   #endif
   tolua_beginmodule(tolua_S,"BillboardSet");
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_BillboardSet_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_BillboardSet_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_BillboardSet_new00_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Ogre_BillboardSet_delete00);
    tolua_function(tolua_S,"createBillboard",tolua_Elementum_Ogre_BillboardSet_createBillboard00);
    tolua_function(tolua_S,"createBillboard",tolua_Elementum_Ogre_BillboardSet_createBillboard01);
    tolua_function(tolua_S,"createBillboard",tolua_Elementum_Ogre_BillboardSet_createBillboard02);
    tolua_function(tolua_S,"createBillboard",tolua_Elementum_Ogre_BillboardSet_createBillboard03);
    tolua_function(tolua_S,"getNumBillboards",tolua_Elementum_Ogre_BillboardSet_getNumBillboards00);
    tolua_function(tolua_S,"setAutoextend",tolua_Elementum_Ogre_BillboardSet_setAutoextend00);
    tolua_function(tolua_S,"getAutoextend",tolua_Elementum_Ogre_BillboardSet_getAutoextend00);
    tolua_function(tolua_S,"setSortingEnabled",tolua_Elementum_Ogre_BillboardSet_setSortingEnabled00);
    tolua_function(tolua_S,"getSortingEnabled",tolua_Elementum_Ogre_BillboardSet_getSortingEnabled00);
    tolua_function(tolua_S,"setPoolSize",tolua_Elementum_Ogre_BillboardSet_setPoolSize00);
    tolua_function(tolua_S,"getPoolSize",tolua_Elementum_Ogre_BillboardSet_getPoolSize00);
    tolua_function(tolua_S,"clear",tolua_Elementum_Ogre_BillboardSet_clear00);
    tolua_function(tolua_S,"getBillboard",tolua_Elementum_Ogre_BillboardSet_getBillboard00);
    tolua_function(tolua_S,"removeBillboard",tolua_Elementum_Ogre_BillboardSet_removeBillboard00);
    tolua_function(tolua_S,"removeBillboard",tolua_Elementum_Ogre_BillboardSet_removeBillboard01);
    tolua_function(tolua_S,"setBillboardOrigin",tolua_Elementum_Ogre_BillboardSet_setBillboardOrigin00);
    tolua_function(tolua_S,"getBillboardOrigin",tolua_Elementum_Ogre_BillboardSet_getBillboardOrigin00);
    tolua_function(tolua_S,"setBillboardRotationType",tolua_Elementum_Ogre_BillboardSet_setBillboardRotationType00);
    tolua_function(tolua_S,"getBillboardRotationType",tolua_Elementum_Ogre_BillboardSet_getBillboardRotationType00);
    tolua_function(tolua_S,"setDefaultDimensions",tolua_Elementum_Ogre_BillboardSet_setDefaultDimensions00);
    tolua_function(tolua_S,"setDefaultWidth",tolua_Elementum_Ogre_BillboardSet_setDefaultWidth00);
    tolua_function(tolua_S,"getDefaultWidth",tolua_Elementum_Ogre_BillboardSet_getDefaultWidth00);
    tolua_function(tolua_S,"setDefaultHeight",tolua_Elementum_Ogre_BillboardSet_setDefaultHeight00);
    tolua_function(tolua_S,"getDefaultHeight",tolua_Elementum_Ogre_BillboardSet_getDefaultHeight00);
    tolua_function(tolua_S,"setMaterialName",tolua_Elementum_Ogre_BillboardSet_setMaterialName00);
    tolua_function(tolua_S,"setMaterialName",tolua_Elementum_Ogre_BillboardSet_setMaterialName01);
    tolua_function(tolua_S,"getMaterialName",tolua_Elementum_Ogre_BillboardSet_getMaterialName00);
    tolua_function(tolua_S,"getCullIndividually",tolua_Elementum_Ogre_BillboardSet_getCullIndividually00);
    tolua_function(tolua_S,"setCullIndividually",tolua_Elementum_Ogre_BillboardSet_setCullIndividually00);
    tolua_function(tolua_S,"setBillboardType",tolua_Elementum_Ogre_BillboardSet_setBillboardType00);
    tolua_function(tolua_S,"getBillboardType",tolua_Elementum_Ogre_BillboardSet_getBillboardType00);
    tolua_function(tolua_S,"setCommonDirection",tolua_Elementum_Ogre_BillboardSet_setCommonDirection00);
    tolua_function(tolua_S,"getCommonDirection",tolua_Elementum_Ogre_BillboardSet_getCommonDirection00);
    tolua_function(tolua_S,"setCommonUpVector",tolua_Elementum_Ogre_BillboardSet_setCommonUpVector00);
    tolua_function(tolua_S,"getCommonUpVector",tolua_Elementum_Ogre_BillboardSet_getCommonUpVector00);
    tolua_variable(tolua_S,"__Renderable__",tolua_get_Ogre__BillboardSet___Renderable__,NULL);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Billboard","Ogre::Billboard","",tolua_collect_Ogre__Billboard);
   #else
   tolua_cclass(tolua_S,"Billboard","Ogre::Billboard","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Billboard");
    tolua_variable(tolua_S,"mPosition",tolua_get_Ogre__Billboard_mPosition,tolua_set_Ogre__Billboard_mPosition);
    tolua_variable(tolua_S,"mDirection",tolua_get_Ogre__Billboard_mDirection,tolua_set_Ogre__Billboard_mDirection);
    tolua_variable(tolua_S,"mParentSet",tolua_get_Ogre__Billboard_mParentSet_ptr,tolua_set_Ogre__Billboard_mParentSet_ptr);
    tolua_variable(tolua_S,"mColour",tolua_get_Ogre__Billboard_mColour,tolua_set_Ogre__Billboard_mColour);
    tolua_variable(tolua_S,"mRotation",tolua_get_Ogre__Billboard_mRotation,tolua_set_Ogre__Billboard_mRotation);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Billboard_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Billboard_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Billboard_new00_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Ogre_Billboard_delete00);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Billboard_new01);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Billboard_new01_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Billboard_new01_local);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Billboard_new02);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Billboard_new02_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Billboard_new02_local);
    tolua_function(tolua_S,"getRotation",tolua_Elementum_Ogre_Billboard_getRotation00);
    tolua_function(tolua_S,"setRotation",tolua_Elementum_Ogre_Billboard_setRotation00);
    tolua_function(tolua_S,"setPosition",tolua_Elementum_Ogre_Billboard_setPosition00);
    tolua_function(tolua_S,"setPosition",tolua_Elementum_Ogre_Billboard_setPosition01);
    tolua_function(tolua_S,"getPosition",tolua_Elementum_Ogre_Billboard_getPosition00);
    tolua_function(tolua_S,"setDimensions",tolua_Elementum_Ogre_Billboard_setDimensions00);
    tolua_function(tolua_S,"resetDimensions",tolua_Elementum_Ogre_Billboard_resetDimensions00);
    tolua_function(tolua_S,"setColour",tolua_Elementum_Ogre_Billboard_setColour00);
    tolua_function(tolua_S,"getColour",tolua_Elementum_Ogre_Billboard_getColour00);
    tolua_function(tolua_S,"hasOwnDimensions",tolua_Elementum_Ogre_Billboard_hasOwnDimensions00);
    tolua_function(tolua_S,"getOwnWidth",tolua_Elementum_Ogre_Billboard_getOwnWidth00);
    tolua_function(tolua_S,"getOwnHeight",tolua_Elementum_Ogre_Billboard_getOwnHeight00);
    tolua_function(tolua_S,"_notifyOwner",tolua_Elementum_Ogre_Billboard__notifyOwner00);
    tolua_function(tolua_S,"isUseTexcoordRect",tolua_Elementum_Ogre_Billboard_isUseTexcoordRect00);
    tolua_function(tolua_S,"setTexcoordIndex",tolua_Elementum_Ogre_Billboard_setTexcoordIndex00);
    tolua_function(tolua_S,"getTexcoordIndex",tolua_Elementum_Ogre_Billboard_getTexcoordIndex00);
    tolua_function(tolua_S,"setTexcoordRect",tolua_Elementum_Ogre_Billboard_setTexcoordRect00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"OgreBites",0);
  tolua_beginmodule(tolua_S,"OgreBites");
   tolua_constant(tolua_S,"CS_FREELOOK",OgreBites::CS_FREELOOK);
   tolua_constant(tolua_S,"CS_ORBIT",OgreBites::CS_ORBIT);
   tolua_constant(tolua_S,"CS_MANUAL",OgreBites::CS_MANUAL);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"SdkCameraMan","OgreBites::SdkCameraMan","",tolua_collect_OgreBites__SdkCameraMan);
   #else
   tolua_cclass(tolua_S,"SdkCameraMan","OgreBites::SdkCameraMan","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"SdkCameraMan");
    tolua_function(tolua_S,"new",tolua_Elementum_OgreBites_SdkCameraMan_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_OgreBites_SdkCameraMan_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_OgreBites_SdkCameraMan_new00_local);
    tolua_function(tolua_S,"setCamera",tolua_Elementum_OgreBites_SdkCameraMan_setCamera00);
    tolua_function(tolua_S,"getCamera",tolua_Elementum_OgreBites_SdkCameraMan_getCamera00);
    tolua_function(tolua_S,"setTarget",tolua_Elementum_OgreBites_SdkCameraMan_setTarget00);
    tolua_function(tolua_S,"getTarget",tolua_Elementum_OgreBites_SdkCameraMan_getTarget00);
    tolua_function(tolua_S,"setYawPitchDist",tolua_Elementum_OgreBites_SdkCameraMan_setYawPitchDist00);
    tolua_function(tolua_S,"setYawPitchDist",tolua_Elementum_OgreBites_SdkCameraMan_setYawPitchDist01);
    tolua_function(tolua_S,"setTopSpeed",tolua_Elementum_OgreBites_SdkCameraMan_setTopSpeed00);
    tolua_function(tolua_S,"getTopSpeed",tolua_Elementum_OgreBites_SdkCameraMan_getTopSpeed00);
    tolua_function(tolua_S,"setStyle",tolua_Elementum_OgreBites_SdkCameraMan_setStyle00);
    tolua_function(tolua_S,"getStyle",tolua_Elementum_OgreBites_SdkCameraMan_getStyle00);
    tolua_function(tolua_S,"manualStop",tolua_Elementum_OgreBites_SdkCameraMan_manualStop00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Ogre",0);
  tolua_beginmodule(tolua_S,"Ogre");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Any","Ogre::Any","",tolua_collect_Ogre__Any);
   #else
   tolua_cclass(tolua_S,"Any","Ogre::Any","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Any");
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Any_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Any_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Any_new00_local);
    tolua_function(tolua_S,"new",tolua_Elementum_Ogre_Any_new01);
    tolua_function(tolua_S,"new_local",tolua_Elementum_Ogre_Any_new01_local);
    tolua_function(tolua_S,".call",tolua_Elementum_Ogre_Any_new01_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_Ogre_Any_delete00);
    tolua_function(tolua_S,"isEmpty",tolua_Elementum_Ogre_Any_isEmpty00);
    tolua_function(tolua_S,"getType",tolua_Elementum_Ogre_Any_getType00);
    tolua_function(tolua_S,"destroy",tolua_Elementum_Ogre_Any_destroy00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"OIS",0);
  tolua_beginmodule(tolua_S,"OIS");
   tolua_constant(tolua_S,"KC_UNASSIGNED",OIS::KC_UNASSIGNED);
   tolua_constant(tolua_S,"KC_ESCAPE",OIS::KC_ESCAPE);
   tolua_constant(tolua_S,"KC_1",OIS::KC_1);
   tolua_constant(tolua_S,"KC_2",OIS::KC_2);
   tolua_constant(tolua_S,"KC_3",OIS::KC_3);
   tolua_constant(tolua_S,"KC_4",OIS::KC_4);
   tolua_constant(tolua_S,"KC_5",OIS::KC_5);
   tolua_constant(tolua_S,"KC_6",OIS::KC_6);
   tolua_constant(tolua_S,"KC_7",OIS::KC_7);
   tolua_constant(tolua_S,"KC_8",OIS::KC_8);
   tolua_constant(tolua_S,"KC_9",OIS::KC_9);
   tolua_constant(tolua_S,"KC_0",OIS::KC_0);
   tolua_constant(tolua_S,"KC_MINUS",OIS::KC_MINUS);
   tolua_constant(tolua_S,"KC_EQUALS",OIS::KC_EQUALS);
   tolua_constant(tolua_S,"KC_BACK",OIS::KC_BACK);
   tolua_constant(tolua_S,"KC_TAB",OIS::KC_TAB);
   tolua_constant(tolua_S,"KC_Q",OIS::KC_Q);
   tolua_constant(tolua_S,"KC_W",OIS::KC_W);
   tolua_constant(tolua_S,"KC_E",OIS::KC_E);
   tolua_constant(tolua_S,"KC_R",OIS::KC_R);
   tolua_constant(tolua_S,"KC_T",OIS::KC_T);
   tolua_constant(tolua_S,"KC_Y",OIS::KC_Y);
   tolua_constant(tolua_S,"KC_U",OIS::KC_U);
   tolua_constant(tolua_S,"KC_I",OIS::KC_I);
   tolua_constant(tolua_S,"KC_O",OIS::KC_O);
   tolua_constant(tolua_S,"KC_P",OIS::KC_P);
   tolua_constant(tolua_S,"KC_LBRACKET",OIS::KC_LBRACKET);
   tolua_constant(tolua_S,"KC_RBRACKET",OIS::KC_RBRACKET);
   tolua_constant(tolua_S,"KC_RETURN",OIS::KC_RETURN);
   tolua_constant(tolua_S,"KC_LCONTROL",OIS::KC_LCONTROL);
   tolua_constant(tolua_S,"KC_A",OIS::KC_A);
   tolua_constant(tolua_S,"KC_S",OIS::KC_S);
   tolua_constant(tolua_S,"KC_D",OIS::KC_D);
   tolua_constant(tolua_S,"KC_F",OIS::KC_F);
   tolua_constant(tolua_S,"KC_G",OIS::KC_G);
   tolua_constant(tolua_S,"KC_H",OIS::KC_H);
   tolua_constant(tolua_S,"KC_J",OIS::KC_J);
   tolua_constant(tolua_S,"KC_K",OIS::KC_K);
   tolua_constant(tolua_S,"KC_L",OIS::KC_L);
   tolua_constant(tolua_S,"KC_SEMICOLON",OIS::KC_SEMICOLON);
   tolua_constant(tolua_S,"KC_APOSTROPHE",OIS::KC_APOSTROPHE);
   tolua_constant(tolua_S,"KC_GRAVE",OIS::KC_GRAVE);
   tolua_constant(tolua_S,"KC_LSHIFT",OIS::KC_LSHIFT);
   tolua_constant(tolua_S,"KC_BACKSLASH",OIS::KC_BACKSLASH);
   tolua_constant(tolua_S,"KC_Z",OIS::KC_Z);
   tolua_constant(tolua_S,"KC_X",OIS::KC_X);
   tolua_constant(tolua_S,"KC_C",OIS::KC_C);
   tolua_constant(tolua_S,"KC_V",OIS::KC_V);
   tolua_constant(tolua_S,"KC_B",OIS::KC_B);
   tolua_constant(tolua_S,"KC_N",OIS::KC_N);
   tolua_constant(tolua_S,"KC_M",OIS::KC_M);
   tolua_constant(tolua_S,"KC_COMMA",OIS::KC_COMMA);
   tolua_constant(tolua_S,"KC_PERIOD",OIS::KC_PERIOD);
   tolua_constant(tolua_S,"KC_SLASH",OIS::KC_SLASH);
   tolua_constant(tolua_S,"KC_RSHIFT",OIS::KC_RSHIFT);
   tolua_constant(tolua_S,"KC_MULTIPLY",OIS::KC_MULTIPLY);
   tolua_constant(tolua_S,"KC_LMENU",OIS::KC_LMENU);
   tolua_constant(tolua_S,"KC_SPACE",OIS::KC_SPACE);
   tolua_constant(tolua_S,"KC_CAPITAL",OIS::KC_CAPITAL);
   tolua_constant(tolua_S,"KC_F1",OIS::KC_F1);
   tolua_constant(tolua_S,"KC_F2",OIS::KC_F2);
   tolua_constant(tolua_S,"KC_F3",OIS::KC_F3);
   tolua_constant(tolua_S,"KC_F4",OIS::KC_F4);
   tolua_constant(tolua_S,"KC_F5",OIS::KC_F5);
   tolua_constant(tolua_S,"KC_F6",OIS::KC_F6);
   tolua_constant(tolua_S,"KC_F7",OIS::KC_F7);
   tolua_constant(tolua_S,"KC_F8",OIS::KC_F8);
   tolua_constant(tolua_S,"KC_F9",OIS::KC_F9);
   tolua_constant(tolua_S,"KC_F10",OIS::KC_F10);
   tolua_constant(tolua_S,"KC_NUMLOCK",OIS::KC_NUMLOCK);
   tolua_constant(tolua_S,"KC_SCROLL",OIS::KC_SCROLL);
   tolua_constant(tolua_S,"KC_NUMPAD7",OIS::KC_NUMPAD7);
   tolua_constant(tolua_S,"KC_NUMPAD8",OIS::KC_NUMPAD8);
   tolua_constant(tolua_S,"KC_NUMPAD9",OIS::KC_NUMPAD9);
   tolua_constant(tolua_S,"KC_SUBTRACT",OIS::KC_SUBTRACT);
   tolua_constant(tolua_S,"KC_NUMPAD4",OIS::KC_NUMPAD4);
   tolua_constant(tolua_S,"KC_NUMPAD5",OIS::KC_NUMPAD5);
   tolua_constant(tolua_S,"KC_NUMPAD6",OIS::KC_NUMPAD6);
   tolua_constant(tolua_S,"KC_ADD",OIS::KC_ADD);
   tolua_constant(tolua_S,"KC_NUMPAD1",OIS::KC_NUMPAD1);
   tolua_constant(tolua_S,"KC_NUMPAD2",OIS::KC_NUMPAD2);
   tolua_constant(tolua_S,"KC_NUMPAD3",OIS::KC_NUMPAD3);
   tolua_constant(tolua_S,"KC_NUMPAD0",OIS::KC_NUMPAD0);
   tolua_constant(tolua_S,"KC_DECIMAL",OIS::KC_DECIMAL);
   tolua_constant(tolua_S,"KC_OEM_102",OIS::KC_OEM_102);
   tolua_constant(tolua_S,"KC_F11",OIS::KC_F11);
   tolua_constant(tolua_S,"KC_F12",OIS::KC_F12);
   tolua_constant(tolua_S,"KC_F13",OIS::KC_F13);
   tolua_constant(tolua_S,"KC_F14",OIS::KC_F14);
   tolua_constant(tolua_S,"KC_F15",OIS::KC_F15);
   tolua_constant(tolua_S,"KC_KANA",OIS::KC_KANA);
   tolua_constant(tolua_S,"KC_ABNT_C1",OIS::KC_ABNT_C1);
   tolua_constant(tolua_S,"KC_CONVERT",OIS::KC_CONVERT);
   tolua_constant(tolua_S,"KC_NOCONVERT",OIS::KC_NOCONVERT);
   tolua_constant(tolua_S,"KC_YEN",OIS::KC_YEN);
   tolua_constant(tolua_S,"KC_ABNT_C2",OIS::KC_ABNT_C2);
   tolua_constant(tolua_S,"KC_NUMPADEQUALS",OIS::KC_NUMPADEQUALS);
   tolua_constant(tolua_S,"KC_PREVTRACK",OIS::KC_PREVTRACK);
   tolua_constant(tolua_S,"KC_AT",OIS::KC_AT);
   tolua_constant(tolua_S,"KC_COLON",OIS::KC_COLON);
   tolua_constant(tolua_S,"KC_UNDERLINE",OIS::KC_UNDERLINE);
   tolua_constant(tolua_S,"KC_KANJI",OIS::KC_KANJI);
   tolua_constant(tolua_S,"KC_STOP",OIS::KC_STOP);
   tolua_constant(tolua_S,"KC_AX",OIS::KC_AX);
   tolua_constant(tolua_S,"KC_UNLABELED",OIS::KC_UNLABELED);
   tolua_constant(tolua_S,"KC_NEXTTRACK",OIS::KC_NEXTTRACK);
   tolua_constant(tolua_S,"KC_NUMPADENTER",OIS::KC_NUMPADENTER);
   tolua_constant(tolua_S,"KC_RCONTROL",OIS::KC_RCONTROL);
   tolua_constant(tolua_S,"KC_MUTE",OIS::KC_MUTE);
   tolua_constant(tolua_S,"KC_CALCULATOR",OIS::KC_CALCULATOR);
   tolua_constant(tolua_S,"KC_PLAYPAUSE",OIS::KC_PLAYPAUSE);
   tolua_constant(tolua_S,"KC_MEDIASTOP",OIS::KC_MEDIASTOP);
   tolua_constant(tolua_S,"KC_VOLUMEDOWN",OIS::KC_VOLUMEDOWN);
   tolua_constant(tolua_S,"KC_VOLUMEUP",OIS::KC_VOLUMEUP);
   tolua_constant(tolua_S,"KC_WEBHOME",OIS::KC_WEBHOME);
   tolua_constant(tolua_S,"KC_NUMPADCOMMA",OIS::KC_NUMPADCOMMA);
   tolua_constant(tolua_S,"KC_DIVIDE",OIS::KC_DIVIDE);
   tolua_constant(tolua_S,"KC_SYSRQ",OIS::KC_SYSRQ);
   tolua_constant(tolua_S,"KC_RMENU",OIS::KC_RMENU);
   tolua_constant(tolua_S,"KC_PAUSE",OIS::KC_PAUSE);
   tolua_constant(tolua_S,"KC_HOME",OIS::KC_HOME);
   tolua_constant(tolua_S,"KC_UP",OIS::KC_UP);
   tolua_constant(tolua_S,"KC_PGUP",OIS::KC_PGUP);
   tolua_constant(tolua_S,"KC_LEFT",OIS::KC_LEFT);
   tolua_constant(tolua_S,"KC_RIGHT",OIS::KC_RIGHT);
   tolua_constant(tolua_S,"KC_END",OIS::KC_END);
   tolua_constant(tolua_S,"KC_DOWN",OIS::KC_DOWN);
   tolua_constant(tolua_S,"KC_PGDOWN",OIS::KC_PGDOWN);
   tolua_constant(tolua_S,"KC_INSERT",OIS::KC_INSERT);
   tolua_constant(tolua_S,"KC_DELETE",OIS::KC_DELETE);
   tolua_constant(tolua_S,"KC_LWIN",OIS::KC_LWIN);
   tolua_constant(tolua_S,"KC_RWIN",OIS::KC_RWIN);
   tolua_constant(tolua_S,"KC_APPS",OIS::KC_APPS);
   tolua_constant(tolua_S,"KC_POWER",OIS::KC_POWER);
   tolua_constant(tolua_S,"KC_SLEEP",OIS::KC_SLEEP);
   tolua_constant(tolua_S,"KC_WAKE",OIS::KC_WAKE);
   tolua_constant(tolua_S,"KC_WEBSEARCH",OIS::KC_WEBSEARCH);
   tolua_constant(tolua_S,"KC_WEBFAVORITES",OIS::KC_WEBFAVORITES);
   tolua_constant(tolua_S,"KC_WEBREFRESH",OIS::KC_WEBREFRESH);
   tolua_constant(tolua_S,"KC_WEBSTOP",OIS::KC_WEBSTOP);
   tolua_constant(tolua_S,"KC_WEBFORWARD",OIS::KC_WEBFORWARD);
   tolua_constant(tolua_S,"KC_WEBBACK",OIS::KC_WEBBACK);
   tolua_constant(tolua_S,"KC_MYCOMPUTER",OIS::KC_MYCOMPUTER);
   tolua_constant(tolua_S,"KC_MAIL",OIS::KC_MAIL);
   tolua_constant(tolua_S,"KC_MEDIASELECT",OIS::KC_MEDIASELECT);
   tolua_cclass(tolua_S,"KeyEvent","OIS::KeyEvent","",NULL);
   tolua_beginmodule(tolua_S,"KeyEvent");
    tolua_variable(tolua_S,"key",tolua_get_OIS__KeyEvent_key,NULL);
    tolua_variable(tolua_S,"text",tolua_get_OIS__KeyEvent_unsigned_text,tolua_set_OIS__KeyEvent_unsigned_text);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Keyboard","OIS::Keyboard","",NULL);
   tolua_beginmodule(tolua_S,"Keyboard");
    tolua_constant(tolua_S,"Shift",OIS::Keyboard::Shift);
    tolua_constant(tolua_S,"Ctrl",OIS::Keyboard::Ctrl);
    tolua_constant(tolua_S,"Alt",OIS::Keyboard::Alt);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
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
  tolua_module(tolua_S,"ParticleUniverse",0);
  tolua_beginmodule(tolua_S,"ParticleUniverse");
   tolua_cclass(tolua_S,"Particle","ParticleUniverse::Particle","",NULL);
   tolua_beginmodule(tolua_S,"Particle");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"ParticleTechnique","ParticleUniverse::ParticleTechnique","",NULL);
   tolua_beginmodule(tolua_S,"ParticleTechnique");
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"ParticleSystem","ParticleUniverse::ParticleSystem","Ogre::MovableObject",tolua_collect_ParticleUniverse__ParticleSystem);
   #else
   tolua_cclass(tolua_S,"ParticleSystem","ParticleUniverse::ParticleSystem","Ogre::MovableObject",NULL);
   #endif
   tolua_beginmodule(tolua_S,"ParticleSystem");
    tolua_variable(tolua_S,"DEFAULT_KEEP_LOCAL",tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_KEEP_LOCAL,NULL);
    tolua_variable(tolua_S,"DEFAULT_ITERATION_INTERVAL",tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_ITERATION_INTERVAL,NULL);
    tolua_variable(tolua_S,"DEFAULT_FIXED_TIMEOUT",tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_FIXED_TIMEOUT,NULL);
    tolua_variable(tolua_S,"DEFAULT_NON_VISIBLE_UPDATE_TIMEOUT",tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_NON_VISIBLE_UPDATE_TIMEOUT,NULL);
    tolua_variable(tolua_S,"DEFAULT_SMOOTH_LOD",tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_SMOOTH_LOD,NULL);
    tolua_variable(tolua_S,"DEFAULT_FAST_FORWARD_TIME",tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_FAST_FORWARD_TIME,NULL);
    tolua_variable(tolua_S,"DEFAULT_MAIN_CAMERA_NAME",tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_MAIN_CAMERA_NAME,NULL);
    tolua_variable(tolua_S,"DEFAULT_SCALE_VELOCITY",tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_SCALE_VELOCITY,NULL);
    tolua_variable(tolua_S,"DEFAULT_SCALE_TIME",tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_SCALE_TIME,NULL);
    tolua_variable(tolua_S,"DEFAULT_SCALE",tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_SCALE,NULL);
    tolua_variable(tolua_S,"DEFAULT_TIGHT_BOUNDINGBOX",tolua_get_ParticleUniverse__ParticleSystem_DEFAULT_TIGHT_BOUNDINGBOX,NULL);
    tolua_constant(tolua_S,"PSS_PREPARED",ParticleUniverse::ParticleSystem::PSS_PREPARED);
    tolua_constant(tolua_S,"PSS_STARTED",ParticleUniverse::ParticleSystem::PSS_STARTED);
    tolua_constant(tolua_S,"PSS_STOPPED",ParticleUniverse::ParticleSystem::PSS_STOPPED);
    tolua_constant(tolua_S,"PSS_PAUSED",ParticleUniverse::ParticleSystem::PSS_PAUSED);
    tolua_function(tolua_S,"new",tolua_Elementum_ParticleUniverse_ParticleSystem_new00);
    tolua_function(tolua_S,"new_local",tolua_Elementum_ParticleUniverse_ParticleSystem_new00_local);
    tolua_function(tolua_S,".call",tolua_Elementum_ParticleUniverse_ParticleSystem_new00_local);
    tolua_function(tolua_S,"new",tolua_Elementum_ParticleUniverse_ParticleSystem_new01);
    tolua_function(tolua_S,"new_local",tolua_Elementum_ParticleUniverse_ParticleSystem_new01_local);
    tolua_function(tolua_S,".call",tolua_Elementum_ParticleUniverse_ParticleSystem_new01_local);
    tolua_function(tolua_S,"delete",tolua_Elementum_ParticleUniverse_ParticleSystem_delete00);
    tolua_function(tolua_S,"getDerivedPosition",tolua_Elementum_ParticleUniverse_ParticleSystem_getDerivedPosition00);
    tolua_function(tolua_S,"getDerivedOrientation",tolua_Elementum_ParticleUniverse_ParticleSystem_getDerivedOrientation00);
    tolua_function(tolua_S,"getLatestOrientation",tolua_Elementum_ParticleUniverse_ParticleSystem_getLatestOrientation00);
    tolua_function(tolua_S,"hasRotatedBetweenUpdates",tolua_Elementum_ParticleUniverse_ParticleSystem_hasRotatedBetweenUpdates00);
    tolua_function(tolua_S,"rotationOffset",tolua_Elementum_ParticleUniverse_ParticleSystem_rotationOffset00);
    tolua_function(tolua_S,"isSmoothLod",tolua_Elementum_ParticleUniverse_ParticleSystem_isSmoothLod00);
    tolua_function(tolua_S,"setSmoothLod",tolua_Elementum_ParticleUniverse_ParticleSystem_setSmoothLod00);
    tolua_function(tolua_S,"getTimeElapsedSinceStart",tolua_Elementum_ParticleUniverse_ParticleSystem_getTimeElapsedSinceStart00);
    tolua_function(tolua_S,"getResourceGroupName",tolua_Elementum_ParticleUniverse_ParticleSystem_getResourceGroupName00);
    tolua_function(tolua_S,"setResourceGroupName",tolua_Elementum_ParticleUniverse_ParticleSystem_setResourceGroupName00);
    tolua_function(tolua_S,"createTechnique",tolua_Elementum_ParticleUniverse_ParticleSystem_createTechnique00);
    tolua_function(tolua_S,"addTechnique",tolua_Elementum_ParticleUniverse_ParticleSystem_addTechnique00);
    tolua_function(tolua_S,"removeTechnique",tolua_Elementum_ParticleUniverse_ParticleSystem_removeTechnique00);
    tolua_function(tolua_S,"getTechnique",tolua_Elementum_ParticleUniverse_ParticleSystem_getTechnique00);
    tolua_function(tolua_S,"getTechnique",tolua_Elementum_ParticleUniverse_ParticleSystem_getTechnique01);
    tolua_function(tolua_S,"getNumTechniques",tolua_Elementum_ParticleUniverse_ParticleSystem_getNumTechniques00);
    tolua_function(tolua_S,"destroyTechnique",tolua_Elementum_ParticleUniverse_ParticleSystem_destroyTechnique00);
    tolua_function(tolua_S,"destroyTechnique",tolua_Elementum_ParticleUniverse_ParticleSystem_destroyTechnique01);
    tolua_function(tolua_S,"destroyAllTechniques",tolua_Elementum_ParticleUniverse_ParticleSystem_destroyAllTechniques00);
    tolua_function(tolua_S,"setRenderQueueGroup",tolua_Elementum_ParticleUniverse_ParticleSystem_setRenderQueueGroup00);
    tolua_function(tolua_S,"getNonVisibleUpdateTimeout",tolua_Elementum_ParticleUniverse_ParticleSystem_getNonVisibleUpdateTimeout00);
    tolua_function(tolua_S,"setNonVisibleUpdateTimeout",tolua_Elementum_ParticleUniverse_ParticleSystem_setNonVisibleUpdateTimeout00);
    tolua_function(tolua_S,"prepare",tolua_Elementum_ParticleUniverse_ParticleSystem_prepare00);
    tolua_function(tolua_S,"start",tolua_Elementum_ParticleUniverse_ParticleSystem_start00);
    tolua_function(tolua_S,"start",tolua_Elementum_ParticleUniverse_ParticleSystem_start01);
    tolua_function(tolua_S,"startAndStopFade",tolua_Elementum_ParticleUniverse_ParticleSystem_startAndStopFade00);
    tolua_function(tolua_S,"stop",tolua_Elementum_ParticleUniverse_ParticleSystem_stop00);
    tolua_function(tolua_S,"stop",tolua_Elementum_ParticleUniverse_ParticleSystem_stop01);
    tolua_function(tolua_S,"stopFade",tolua_Elementum_ParticleUniverse_ParticleSystem_stopFade00);
    tolua_function(tolua_S,"stopFade",tolua_Elementum_ParticleUniverse_ParticleSystem_stopFade01);
    tolua_function(tolua_S,"pause",tolua_Elementum_ParticleUniverse_ParticleSystem_pause00);
    tolua_function(tolua_S,"pause",tolua_Elementum_ParticleUniverse_ParticleSystem_pause01);
    tolua_function(tolua_S,"resume",tolua_Elementum_ParticleUniverse_ParticleSystem_resume00);
    tolua_function(tolua_S,"getState",tolua_Elementum_ParticleUniverse_ParticleSystem_getState00);
    tolua_function(tolua_S,"getFastForwardTime",tolua_Elementum_ParticleUniverse_ParticleSystem_getFastForwardTime00);
    tolua_function(tolua_S,"getFastForwardInterval",tolua_Elementum_ParticleUniverse_ParticleSystem_getFastForwardInterval00);
    tolua_function(tolua_S,"setFastForward",tolua_Elementum_ParticleUniverse_ParticleSystem_setFastForward00);
    tolua_function(tolua_S,"getMainCameraName",tolua_Elementum_ParticleUniverse_ParticleSystem_getMainCameraName00);
    tolua_function(tolua_S,"getMainCamera",tolua_Elementum_ParticleUniverse_ParticleSystem_getMainCamera00);
    tolua_function(tolua_S,"hasMainCamera",tolua_Elementum_ParticleUniverse_ParticleSystem_hasMainCamera00);
    tolua_function(tolua_S,"setMainCameraName",tolua_Elementum_ParticleUniverse_ParticleSystem_setMainCameraName00);
    tolua_function(tolua_S,"setMainCamera",tolua_Elementum_ParticleUniverse_ParticleSystem_setMainCamera00);
    tolua_function(tolua_S,"getCurrentCamera",tolua_Elementum_ParticleUniverse_ParticleSystem_getCurrentCamera00);
    tolua_function(tolua_S,"fastForward",tolua_Elementum_ParticleUniverse_ParticleSystem_fastForward00);
    tolua_function(tolua_S,"getNumEmittedTechniques",tolua_Elementum_ParticleUniverse_ParticleSystem_getNumEmittedTechniques00);
    tolua_function(tolua_S,"_markForEmission",tolua_Elementum_ParticleUniverse_ParticleSystem__markForEmission00);
    tolua_function(tolua_S,"_resetMarkForEmission",tolua_Elementum_ParticleUniverse_ParticleSystem__resetMarkForEmission00);
    tolua_function(tolua_S,"suppressNotifyEmissionChange",tolua_Elementum_ParticleUniverse_ParticleSystem_suppressNotifyEmissionChange00);
    tolua_function(tolua_S,"_notifyEmissionChange",tolua_Elementum_ParticleUniverse_ParticleSystem__notifyEmissionChange00);
    tolua_function(tolua_S,"getIterationInterval",tolua_Elementum_ParticleUniverse_ParticleSystem_getIterationInterval00);
    tolua_function(tolua_S,"setIterationInterval",tolua_Elementum_ParticleUniverse_ParticleSystem_setIterationInterval00);
    tolua_function(tolua_S,"getFixedTimeout",tolua_Elementum_ParticleUniverse_ParticleSystem_getFixedTimeout00);
    tolua_function(tolua_S,"setFixedTimeout",tolua_Elementum_ParticleUniverse_ParticleSystem_setFixedTimeout00);
    tolua_function(tolua_S,"setBoundsAutoUpdated",tolua_Elementum_ParticleUniverse_ParticleSystem_setBoundsAutoUpdated00);
    tolua_function(tolua_S,"_resetBounds",tolua_Elementum_ParticleUniverse_ParticleSystem__resetBounds00);
    tolua_function(tolua_S,"getScale",tolua_Elementum_ParticleUniverse_ParticleSystem_getScale00);
    tolua_function(tolua_S,"setScale",tolua_Elementum_ParticleUniverse_ParticleSystem_setScale00);
    tolua_function(tolua_S,"getScaleVelocity",tolua_Elementum_ParticleUniverse_ParticleSystem_getScaleVelocity00);
    tolua_function(tolua_S,"setScaleVelocity",tolua_Elementum_ParticleUniverse_ParticleSystem_setScaleVelocity00);
    tolua_function(tolua_S,"getScaleTime",tolua_Elementum_ParticleUniverse_ParticleSystem_getScaleTime00);
    tolua_function(tolua_S,"setScaleTime",tolua_Elementum_ParticleUniverse_ParticleSystem_setScaleTime00);
    tolua_function(tolua_S,"isKeepLocal",tolua_Elementum_ParticleUniverse_ParticleSystem_isKeepLocal00);
    tolua_function(tolua_S,"setKeepLocal",tolua_Elementum_ParticleUniverse_ParticleSystem_setKeepLocal00);
    tolua_function(tolua_S,"hasTightBoundingBox",tolua_Elementum_ParticleUniverse_ParticleSystem_hasTightBoundingBox00);
    tolua_function(tolua_S,"setTightBoundingBox",tolua_Elementum_ParticleUniverse_ParticleSystem_setTightBoundingBox00);
    tolua_function(tolua_S,"getPauseTime",tolua_Elementum_ParticleUniverse_ParticleSystem_getPauseTime00);
    tolua_function(tolua_S,"setPauseTime",tolua_Elementum_ParticleUniverse_ParticleSystem_setPauseTime00);
    tolua_function(tolua_S,"setEnabled",tolua_Elementum_ParticleUniverse_ParticleSystem_setEnabled00);
    tolua_function(tolua_S,"getSceneManager",tolua_Elementum_ParticleUniverse_ParticleSystem_getSceneManager00);
    tolua_function(tolua_S,"setSceneManager",tolua_Elementum_ParticleUniverse_ParticleSystem_setSceneManager00);
    tolua_function(tolua_S,"setUseController",tolua_Elementum_ParticleUniverse_ParticleSystem_setUseController00);
    tolua_function(tolua_S,"hasExternType",tolua_Elementum_ParticleUniverse_ParticleSystem_hasExternType00);
    tolua_function(tolua_S,"getCategory",tolua_Elementum_ParticleUniverse_ParticleSystem_getCategory00);
    tolua_function(tolua_S,"setCategory",tolua_Elementum_ParticleUniverse_ParticleSystem_setCategory00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Elementum (lua_State* tolua_S) {
 return tolua_Elementum_open(tolua_S);
};
#endif

