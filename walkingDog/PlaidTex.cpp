
#include "PlaidTex.h"
#include <iostream>
#include <stdio.h>
#include <opencv2\opencv.hpp>

void PlaidTex::init(void)
{
	// 画層の読み込み
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
	/* アルファテスト開始 */
	glEnable(GL_ALPHA_TEST);
	/* テクスチャマッピング開始 */
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0 * map_size, -1.0 * map_size, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0 * map_size, 1.0 * map_size, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.0 * map_size, 1.0 * map_size, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0 * map_size, -1.0 * map_size, 0.0);
	glEnd();
	/* テクスチャマッピング終了 */
	glDisable(GL_TEXTURE_2D);
	/* アルファテスト終了 */
	glDisable(GL_ALPHA_TEST);
}

