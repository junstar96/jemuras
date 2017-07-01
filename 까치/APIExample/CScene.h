#pragma once

class CScene
{
private:
	bool		m_bActive;

public:
	CScene(){};
	virtual ~CScene(){};

public:
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;
};