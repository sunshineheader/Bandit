#ifndef __BUTTOM__ITEM__H__H__
#define __BUTTOM__ITEM__H__H__
#include "BaseObject.h"
typedef struct  {
	int basic_index;
	int basic_grade;
}ButtonItemData;

class GameLayer;
class ButtonItem :public BaseObject
{
public:
	static ButtonItem* createItem(GameLayer* layer, int index, const ButtonItemData& data);
	void itemBtnCallBack(Ref* psender);
private:
	bool initItem(GameLayer* layer, int index, const ButtonItemData& data);
	void initObject();
	void destoryObject();
private:
	void setPositionByIndex(int index);
public:
	inline int getItemNum(){ return m_num; };
	inline int getItemSource(){ return (m_button_data.basic_grade * m_num); };
private:
	const static int MAX_NUM = 99;
	int m_num;
	int m_index;
	ButtonItemData m_button_data;
private:
	Text* itemText;
	Text* itemSourceText;
	GameLayer* gameLayer;
};


#endif




