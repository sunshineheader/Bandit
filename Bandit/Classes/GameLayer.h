#ifndef __GAME__LAYER__H__H__
#define __GAME__LAYER__H__H__
#include "BaseLayer.h"

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
	// ���沿�ֵķ���
	void doTopsLayout(Node* rootNode);
	// Item���ֵĲ���
	void doItemLayout(Node* rootNode);
	// �м�Ŀ�ʼ��ť
	void doMiddleBtns(Node* rootNode);
	// ����8����ť
	void doButtomBtns(Node* rootNode);
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
	Vector<ButtonItem*>buttonItemPool;
private:

};
#endif








