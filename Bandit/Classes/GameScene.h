#ifndef  __GAME__SCENE__H__H__
#define  __GAME__SCENE__H__H__

#include "cocos2d.h"

//������������ ���ǰ������ ������������
class GameLayer;
//������������ ���ǰ������ ������������

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

