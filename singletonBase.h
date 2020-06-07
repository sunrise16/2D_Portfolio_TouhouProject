#pragma once

template <class T>
class singletonBase
{
protected:
	// 教臂沛 按眉 急攫
	static T* singleton;
	
	singletonBase() {}
	~singletonBase() {}

public:
	// 教臂沛 按眉 啊廉坷扁
	static T* getSingleton();

	// 教臂沛 按眉 秦力窍扁
	void releaseSingleton();
};

// 教臂沛 按眉 檬扁拳
template<class T>
T* singletonBase<T>::singleton = nullptr;

// 教臂沛 按眉 啊廉坷扁
template<class T>
inline T * singletonBase<T>::getSingleton()
{
	// 教臂沛捞 绝阑 版快 货肺 积己
	if (!singleton) singleton = new T;
	return singleton;
}

// 教臂沛 按眉 秦力窍扁
template<class T>
inline void singletonBase<T>::releaseSingleton()
{
	// 教臂沛捞 乐阑 版快 皋葛府俊辑 秦力
	if (singleton)
	{
		delete singleton;
		singleton = nullptr;
	}
}