#ifndef  __BSAE__OBJECTS__H__H__
#define  __BSAE__OBJECTS__H__H__

#include "GameHelper.h"

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio::timeline;


class BaseObject :public cocos2d::Node
{
protected:
	BaseObject();
	~BaseObject();
protected:
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
protected:
	std::function<void()>_initObject;
	std::function<void()>_destoryObject;
protected:
	std::string RESOURCE_NAME;
};



#endif // __BSAE__OBJECTS__H__H__ 