#pragma once

class CSceneMng
{
private:
	CScene*					m_pPrevScene;
	CScene*					m_pCurrScene;

	map<string, CScene*>	m_pTable;

public:
	CSceneMng();
	~CSceneMng();

	void Entry(const string name, CScene* pScene);
	CScene* Trans(const string name);
};

