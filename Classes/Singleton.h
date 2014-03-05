#pragma once

template <class T>

class CSingleton
{
private:
	static T* m_singleton;

public:
	static T* GetSingleton()
	{
		if(m_singleton == 0)
			m_singleton = new T();

		return m_singleton;
	}

	virtual ~CSingleton()
	{
		delete m_singleton;
	}

	CSingleton(){}

};

template <class T> T* CSingleton<T>::m_singleton = 0;