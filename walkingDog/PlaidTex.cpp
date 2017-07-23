
#include "PlaidTex.h"
#include <iostream>
#include <stdio.h>
#include <opencv2\opencv.hpp>

void PlaidTex::init(void)
{
	// ��w�̓ǂݍ���
	cv::Mat im = cv::imread("C:\\Users\\nono\\Desktop\\final.png");
	if (!im.data) {
		std::cout << "Can not open tex file\n";
	}
	else {
		printf("R:%d G:%d B:%d \n", im.at<cv::Vec3b>(0, 0)[2], im.at<cv::Vec3b>(0, 0)[1], im.at<cv::Vec3b>(0, 0)[0]);

		for (int i = 0; i < TEX_HEIGHT; i++) {
			for (int j = 0; j < TEX_WIDTH; j++) {
				image[i][j][0] = im.at<cv::Vec3b>(i, j)[2];/* R */
				image[i][j][1] = im.at<cv::Vec3b>(i, j)[1];/* G */
				image[i][j][2] = im.at<cv::Vec3b>(i, j)[0]; /* B */
				image[i][j][3] = 255;
			}
		}
	}

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TEX_WIDTH, TEX_HEIGHT,
		0, GL_RGBA, GL_UNSIGNED_BYTE, image);
}


void PlaidTex::displayTexPolygon(void)
{
	double map_size = 100.0;
	/* �A���t�@�e�X�g�J�n */
	glEnable(GL_ALPHA_TEST);
	/* �e�N�X�`���}�b�s���O�J�n */
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0 * map_size, -1.0 * map_size, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0 * map_size, 1.0 * map_size, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.0 * map_size, 1.0 * map_size, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0 * map_size, -1.0 * map_size, 0.0);
	glEnd();
	/* �e�N�X�`���}�b�s���O�I�� */
	glDisable(GL_TEXTURE_2D);
	/* �A���t�@�e�X�g�I�� */
	glDisable(GL_ALPHA_TEST);
}

