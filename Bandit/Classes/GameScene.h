#ifndef  __GAME__SCENE__H__H__
#define  __GAME__SCENE__H__H__

#include "cocos2d.h"

//—————— 类的前置声明 ——————
class GameLayer;
//—————— 类的前置声明 ——————

class GameScene :public cocos2d::Scene 
{
public:
	CREATE_FUNC(GameScene);
private:
	virtual bool init();
	void update(float delta);
public:
	GameLayer* getGameLayer(){ return _gameLayer; };
private:
	GameLayer* _gameLayer;
};
#endif // __GAME__SCENE__H__H__ 

