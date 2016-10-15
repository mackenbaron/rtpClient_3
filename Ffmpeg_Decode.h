#pragma once

#include <opencv2/core/core.hpp>//OpenCV����ͷ�ļ�  
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/opencv.hpp>  

using namespace cv;

#include <string.h>//�ַ�������ͷ�ļ�

#ifndef INT64_C 
#define INT64_C(c) (c ## LL) 
#define UINT64_C(c) (c ## ULL) 
#endif 

#ifdef __cplusplus 
extern "C" {
#endif 
	/*Include ffmpeg header file*/
#include <libavformat/avformat.h> 
#include <libavcodec/avcodec.h> 
#include <libswscale/swscale.h> 

#include <libavutil/imgutils.h>  
#include <libavutil/opt.h>     
#include <libavutil/mathematics.h>   
#include <libavutil/samplefmt.h>

//#pragma comment(lib,"avcodec.lib")
//#pragma comment(lib,"avutil.lib")
#ifdef __cplusplus 
}
#endif 



class Ffmpeg_Decoder
{
public:
	AVCodecParserContext *avParserContext;
	AVPacket avpkt;			//���ݰ��ṹ��
	AVFrame *m_pRGBFrame;	//֡����
	AVFrame *m_pYUVFrame;	//֡����
	AVCodec *pCodecH264;	//������
	AVCodecContext *c;		//���������ݽṹ����
	uint8_t *yuv_buff;      //yuvͼ��������
	uint8_t *rgb_buff;		//rgbͼ��������
	SwsContext *scxt;		//ͼ���ʽת������
	uint8_t *filebuf;		//�����ļ�����
	uint8_t *outbuf;		//���������Ƶ���ݻ���
	int nDataLen;			//rgbͼ������������

	IplImage* img;			//OpenCVͼ����ʾ����

	uint8_t *pbuf;			//���Դ��֡����
	int nOutSize;			//���Լ�¼֡���ݳ���
	int haveread;			//���Լ�¼�Ѷ�buf����
	int decodelen;			//���������س���
	int piclen;				//����������ͼƬ����
	int piccount;			//���ͼƬ����
	AVFrame *picture1;		  /* ������ͼ��*/


public:
	void Ffmpeg_Decoder_Init();//��ʼ��
	void Ffmpeg_Decoder_Show(AVFrame *pFrame, int width, int height);//��ʾͼƬ
	void m_decoder_show(unsigned char *nalBuf, int nBufLen, unsigned char &ID);
	void Ffmpeg_Decoder_Close();//�ر�
};

