#pragma once


template<typename T>
class CSingleton
{
public:
	CSingleton() {}
	~CSingleton() {}

	CSingleton(const CSingleton& s){}

	static T* GetInstance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = new T();
			atexit(DestroyInstance);
		}
		return m_pInstance;
	}

	static void DestroyInstance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}

private:
	static T*	m_pInstance;

};

template <typename T> T* CSingleton<T>::m_pInstance;