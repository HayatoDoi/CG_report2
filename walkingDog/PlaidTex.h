#pragma once
#include <GL/glut.h>

#ifndef _PLAIDTEX_H_
#define _PLAIDTEX_H_

#define TEX_HEIGHT 2048
#define TEX_WIDTH  2048

class PlaidTex
{

public:
	void init(void);
	void displayTexPolygon(void);
	GLubyte image[TEX_HEIGHT][TEX_WIDTH][4];
};
#endif // _PLAIDTEX_H_