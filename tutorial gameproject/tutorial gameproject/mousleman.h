#ifndef mouslemen_H_
#define mouslemen_H_
#include"total head.h"

class mousleman
{
protected:
	string name;
	int hp;
	HBITMAP pick;
	CString imagename;
	CImage *image;
public:
    mousleman() :name("clear"), hp(0), pick(NULL) {};
	mousleman(string name, int hp, HBITMAP pick) :name(name), hp(hp), pick(pick) { image = new CImage; };

	virtual void get_image() {};


	virtual ~mousleman() { delete image; };
	virtual void onpaint(HDC hdc) {};

};


class general : public mousleman
{
public:
	general() :mousleman() { };
	general(string name, int hp, HBITMAP pick) : mousleman(name, hp, pick) {
		image = new CImage;
	};

	virtual ~general() { delete image; };

	virtual void get_image();


	virtual void onpaint(HDC hdc);
};



#endif