#ifndef __ELEMENT__ITEM__H__H__
#define __ELEMENT__ITEM__H__H__
#include "BaseObject.h"

// basic_button_index �� -1 ��ʱ���� LUCK
typedef struct  {
	int   basic_element_index;
	int   basic_button_index;   // ���� button �� index ��ȡ�� element ���ۺ��н�����
	float basic_grail_rate;     // ���̸��� �ȹ�һ�� ���̸���
	float basic_element_rate;   // Ԫ�ظ��� �ȹ�һ�� Ԫ�ظ���
	int   basic_level;          // Ԫ�ر���
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
public: // index ���
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




