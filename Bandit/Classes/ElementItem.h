#ifndef __ELEMENT__ITEM__H__H__
#define __ELEMENT__ITEM__H__H__
#include "BaseObject.h"

// basic_button_index 是 -1 的时候是 LUCK
typedef struct  {
	int   basic_element_index;
	int   basic_button_index;   // 根据 button 的 index 获取到 element 的综合中奖概率
	float basic_grail_rate;     // 大盘概率 先过一遍 大盘概率
	float basic_element_rate;   // 元素概率 先过一遍 元素概率
	int   basic_level;          // 元素倍率
}ElementItemData;

class ElementItem :public BaseObject 
{
public:
	static ElementItem* createItem(int index, const ElementItemData& data);
private:
	bool initItem(int index, const ElementItemData& data);
	void initObject();
	void destoryObject();
public:
	void changeElementSeclted(bool seclted);
public: // index 相关
	inline ElementItemData getElementItemData(){ return m_element_data; }
	inline int getElementIndex(){ return m_index; }
	void setPositionByIndex(int index);
private:
	int m_index;
	ElementItemData m_element_data;
	const static int ELEMENT_WIDTH = 60;
private:// pointer
	ImageView* fruitImage;
	ImageView* blinkImage;
};


#endif




