#include "AudioHelper.h"

template <typename Type> Type* SingletonFactory<Type>::_instance = nullptr;
template <typename Type>  Type* SingletonFactory<Type>::getInstance()
{
	if (!_instance)
	{
		_instance = new SingletonFactory<Type>();
	}
	return _instance;
}

AudioHelper::AudioHelper()
{}

AudioHelper::~AudioHelper()
{}