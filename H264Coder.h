#pragma once
#include <opencv\cv.h>
#include <opencv\highgui.h>

extern "C"
{

#include "libavcodec\avcodec.h"
#include "libavutil\avutil.h"
#include "libswscale\swscale.h"

#pragma comment(lib,"avcodec.lib")
#pragma comment(lib,"avutil.lib")
//#pragma comment(lib,"swscale.lib")

}



class CH264Coder
{
public:
	CH264Coder(void);
	~CH264Coder(void);
	bool InitDecoder();
	bool InputFilePath(char *path);
	//void RecvNalBuffer(unsigned char *nalBuf,int nBufLen);
	IplImage* RecvNalBuffer( unsigned char *nalBuf, int nBufLen, unsigned char &ID );
	void YUV2BGR( IplImage* bgrImg, int nWidth, int nHeight, AVFrame* pic );
	
private:
	
	
	
   
private:
	AVCodec *codec;			  /* �����CODEC*/
	AVCodecContext *c1;		  /* �����CODEC context*/
	AVCodecContext *c2;		  /* �����CODEC context*/
	AVCodecContext *c3;		  /* �����CODEC context*/
	AVFrame *picture1;		  /* ������ͼ��*/	
	AVFrame *picture2;		  /* ������ͼ��*/	
	AVFrame *picture3;		  /* ������ͼ��*/	

	FILE *m_inFile;
	FILE * m_outFile;

public:

};
