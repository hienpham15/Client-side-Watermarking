// Spread Spectrum and LUT.cpp : Defines the entry point for the console application.
//
#include <opencv\cv.h>
#include <opencv\cv.hpp>
#include <opencv2\core.hpp>
#include "round.h"
#include "IndexGen.h"
#include "WatermarkEncryption.h"
#include "WatermarkVerification.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <gmp_util.h>
#include "Paillier.h"

using namespace cv;
using namespace std;

int main()
{
	
	int section_key = 15;
	//int Watermark_Size = 10000;
	Mat H = imread("lena3.tif");
	int rows = H.rows;
	int cols = H.cols;
	int Watermark_Size = rows * cols;

	Mat Watermarked_Image = WatermarkEncryption("lena3.tif", section_key, Watermark_Size);
	imwrite("Watermarked_Image.tif", Watermarked_Image);
	Mat I = WatermarkVerification("lena3.tif", "Watermarked_Image.tif", section_key, Watermark_Size);
	
	return 0;
}

