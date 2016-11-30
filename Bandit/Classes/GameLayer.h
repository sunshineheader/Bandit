#ifndef __GAME__LAYER__H__H__
#define __GAME__LAYER__H__H__
#include "BaseLayer.h"

enum GameState
{
	START_GAME,
	START_ANIMATION,
};

static int GrailElement0 = 20;
static int GrailElement1 = 35;
static int GrailElement2 = 50;
static int GrailElement3 = 65;
static int GrailElement4 = 75;
static int GrailElement5 = 85;
static int GrailElement6 = 90;
static int GrailElement7 = 95;
static int GrailElement8 = 100;

class ElementItem;
class ButtonItem;
class GameLayer :public BaseLayer
{
public:
	static GameLayer* create(GameScene* scene);
private:
	bool init(GameScene* scene);
	void doEvent();
	void doUI();
	void removeEvent();
	// 上面部分的分数
	void doTopsLayout(Node* rootNode);
	// Item部分的布局
	void doItemLayout(Node* rootNode);
	// 中间的开始按钮
	void doMiddleBtns(Node* rootNode);
	// 底下8个按钮
	void doButtomBtns(Node* rootNode);
private:
	void reset();
	int  checkIndex(int index);
	void checkStepByStep();
	int  checkGrailElementStep();
	void checkElementStep(int grailelement);
	int  checkEndedElementIndex();
	bool checkButtonItemClick();
private:
	void startRun(float delta);
	void startAddSpeed(float delta);
private: // calbacks
	void goBtnCallBack(Ref* psender);
	void bigBtnCallBack(Ref* psender);
	void smallBtnCallBack(Ref* psender);
	void rightBtnCallBack(Ref* psender);
	void leftBtnCallBack(Ref* psender);
	void allBtnCallBack(Ref* psender);
public:
	void refreshUI();
private:
	Text* winText;
	Text* creditText;
	ElementItem* elements[24];
	ButtonItem * buttons[8];
	Vector<ElementItem*> elementHitPool;
private:
	GameState gameState;
	int currIndex;
	int repeatCount;
};
#endif








