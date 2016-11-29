#ifndef  __BSAE__LAYER__H__H__
#define  __BSAE__LAYER__H__H__
#include "GameHelper.h"

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio::timeline;

class GameScene;
class BaseLayer :public cocos2d::Layer
{
protected:
	BaseLayer();
	~BaseLayer();
	virtual bool init();
	virtual void initWithGameScene(GameScene* scene);
	virtual void onEnter();
	virtual void onExit();
protected:
	std::function<void()>_doEvent;
	std::function<void()>_doUI;
	std::function<void()>_removeEvent;
protected:
	GameScene* _gameScene;
	std::string RESOURCE_NAME;

};


#endif // __BSAE__LAYER__H__H__ 

