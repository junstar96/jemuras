#include "stdafx.h"

CSceneMng::CSceneMng()
{
	m_pPrevScene = NULL;
	m_pCurrScene = NULL;
}

CSceneMng::~CSceneMng()
{
	for (map<string, CScene*>::iterator itr = m_pTable.begin(); itr != m_pTable.end(); itr++)
		SAFE_DELETE((*itr).second);
}

void CSceneMng::Entry(const string name, CScene* pScene)
{
	map<string, CScene*>::iterator itr = m_pTable.find(name);		//!< ³¡ ¾À¿¡ Ãß°¡

	if (itr == m_pTable.end())
		m_pTable[name] = pScene;
}

CScene* CSceneMng::Trans(const string name)
{
	map<string, CScene*>::iterator itr = m_pTable.find(name);

	if (itr == m_pTable.end())
		return NULL;

	if (m_pPrevScene != NULL)
		m_pPrevScene->Destroy();

	m_pPrevScene = m_pCurrScene;
	m_pCurrScene = itr->second;

	m_pCurrScene->Init();

	return itr->second;
}