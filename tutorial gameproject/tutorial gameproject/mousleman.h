#pragma once
#include"total head.h"

class mousleman
{
protected:
	string name;
	int hp;
	HBITMAP pick;
public:
    mousleman() :name("clear"), hp(0), pick(NULL) {};
	mousleman(string name, int hp, HBITMAP pick) :name(name), hp(hp), pick(pick) {};

	virtual ~mousleman() {  };
	virtual void onpaint(HDC hdc) const = 0;

};


class general : public mousleman
{
public:
	general() :mousleman() {};
	general(string name, int hp, HBITMAP pick) : mousleman(name, hp, pick) {};

	virtual ~general() {};

	void onpaint(HDC hdc);
};