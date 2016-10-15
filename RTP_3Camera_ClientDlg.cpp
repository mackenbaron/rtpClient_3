
// RTP_3Camera_ClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RTP_3Camera_Client.h"
#include "RTP_3Camera_ClientDlg.h"
#include "afxdialogex.h"
#include "RtpTransport.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define DEST_IP  "211.211.211.37"
using namespace cv;
using namespace std;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

DWORD WINAPI DrawPicture(LPVOID lpparam)
{
	unsigned char ID = 0;
	CRTP_3Camera_ClientDlg* p = (CRTP_3Camera_ClientDlg*)lpparam;
	//IplImage* bgrImg = cvLoadImage("hello.jpg");

	p->OnInitDialog22();
	//p->OnOpen();
	//p->test(p->rtpTransport.m_uWidth, p->rtpTransport.m_uHeight, ID);
	while(1)
	{
		//p->DrawPicToHDC(bgrImg, IDC_ShowImg1);	
		
		p->rtpTransport.RecvRtpPacket( p->rtpTransport.m_uWidth, p->rtpTransport.m_uHeight, ID);
		if (p->rtpTransport.bgrImg->imageData == NULL)
			continue;
		//if( 0x01 == ID )
		//	p->DrawPicToHDC(p->rtpTransport.bgrImg, IDC_ShowImg);
		//if (0x02 == ID)
		//	/*if (p->rtpTransport.bgrImg)
		//	p->OnOpen(p->rtpTransport.bgrImg);*/
		//	p->DrawPicToHDC(p->rtpTransport.bgrImg, IDC_ShowImg1);
		//if( 0x03 == ID )
		//	p->DrawPicToHDC(p->rtpTransport.bgrImg, IDC_ShowImg2);
	}
	return 0x01;
}



void CRTP_3Camera_ClientDlg::OnOpen(IplImage * img)
{
	//IplImage * img = cvLoadImage("hello.jpg");//load image from file
	CvvImage cvvImg; //CvvImage��
	cvvImg.CopyOf(img);//����ͼ�񵽵�ǰ��CvvImage������  
	cvvImg.DrawToHDC(hDC, &rect); //����ͼ���ROI����DC��rect
}

void CRTP_3Camera_ClientDlg::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (1 == nIDEvent)
	{
		IplImage* img = 0;
		//img = cvQueryFrame(capture); //������ͷ�����ļ���ץȡ������һ֡
		//cvGrabFrame( capture ); //������ͷ������Ƶ�ļ���ץȡ֡
		//img=cvRetrieveFrame(capture); //ȡ���ɺ���cvGrabFrameץȡ��ͼ��
		CvvImage m_CvvImage;
		m_CvvImage.CopyOf(img, 1); //���Ƹ�֡ͼ��    
		m_CvvImage.DrawToHDC(hDC, &rect); //��ʾ���豸�ľ��ο���
	}
	CDialog::OnTimer(nIDEvent);
}


BOOL CRTP_3Camera_ClientDlg::OnInitDialog22()
{
	//������ɴ���.......

	pStc = (CStatic *)GetDlgItem(IDC_ShowImg);//IDC_VIEWΪPicture�ؼ�ID
	pStc->GetClientRect(&rect);//��CWind��ͻ���������㴫������
	pDC = pStc->GetDC(); //�õ�Picture�ؼ��豸������
	hDC = pDC->GetSafeHdc(); //�õ��ؼ��豸�����ĵľ�� 

	return   TRUE;
}

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRTP_3Camera_ClientDlg �Ի���



CRTP_3Camera_ClientDlg::CRTP_3Camera_ClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRTP_3Camera_ClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRTP_3Camera_ClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRTP_3Camera_ClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CRTP_3Camera_ClientDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CRTP_3Camera_ClientDlg ��Ϣ�������

BOOL CRTP_3Camera_ClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�
	
	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	rtpTransport.SetRtpInfo(DEST_IP,3000);
	rtpTransport.m_h264Coder.InitDecoder();

	DWORD dwthread;
	CreateThread(NULL, 0, DrawPicture, (LPVOID)this, 0, &dwthread);
	m_decoder = new Ffmpeg_Decoder;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CRTP_3Camera_ClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRTP_3Camera_ClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRTP_3Camera_ClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRTP_3Camera_ClientDlg::DrawPicToHDC(IplImage * img , UINT ID)
{
	CDC *pDC = GetDlgItem(ID)->GetDC();
	HDC hDC= pDC->GetSafeHdc();
	CRect rect;
	GetDlgItem(ID)->GetClientRect(&rect);
	CvvImage cimg;
	cimg.CopyOf( img ); // ����ͼƬ
	cimg.DrawToHDC( hDC, &rect ); // ��ͼƬ���Ƶ���ʾ�ؼ���ָ��������
	ReleaseDC( pDC );
}

void CRTP_3Camera_ClientDlg::testDecoder()
{
	Ffmpeg_Decoder ffmpegobj;
	ffmpegobj.Ffmpeg_Decoder_Init();//��ʼ��������
	FILE *pf = NULL;
	fopen_s(&pf, "myData2.h264", "rb");
	while (true)
	{
		ffmpegobj.nDataLen = fread(ffmpegobj.filebuf, 1, 1024 * 10, pf);//��ȡ�ļ�����
		if (ffmpegobj.nDataLen <= 0)
		{
			fclose(pf);
			break;
		}
		else
		{
			ffmpegobj.haveread = 0;
			while (ffmpegobj.nDataLen > 0)
			{
				int nLength = av_parser_parse2(ffmpegobj.avParserContext, ffmpegobj.c, &ffmpegobj.yuv_buff,
					&ffmpegobj.nOutSize, ffmpegobj.filebuf + ffmpegobj.haveread, ffmpegobj.nDataLen, 0, 0, 0);//����֡ͷ
				ffmpegobj.nDataLen -= nLength;//���ҹ���ָ����λ��־
				ffmpegobj.haveread += nLength;
				if (ffmpegobj.nOutSize <= 0)
				{
					continue;
				}
				ffmpegobj.avpkt.size = ffmpegobj.nOutSize;//��֡���ݷŽ�����
				ffmpegobj.avpkt.data = ffmpegobj.yuv_buff;
				while (ffmpegobj.avpkt.size > 0)
				{
					ffmpegobj.decodelen = avcodec_decode_video2(ffmpegobj.c, ffmpegobj.m_pYUVFrame, &ffmpegobj.piclen, &ffmpegobj.avpkt);//����
					if (ffmpegobj.decodelen < 0)
					{
						break;
					}
					if (ffmpegobj.piclen)
					{
						ffmpegobj.scxt = sws_getContext(ffmpegobj.c->width, ffmpegobj.c->height, ffmpegobj.c->pix_fmt, ffmpegobj.c->width, ffmpegobj.c->height, PIX_FMT_BGR24, SWS_POINT, NULL, NULL, NULL);//��ʼ����ʽת������
						if (ffmpegobj.scxt != NULL)
						{
							avpicture_fill((AVPicture*)ffmpegobj.m_pRGBFrame, (uint8_t*)ffmpegobj.rgb_buff, PIX_FMT_RGB24, ffmpegobj.c->width, ffmpegobj.c->height);//��rgb_buff��䵽m_pRGBFrame
							if (avpicture_alloc((AVPicture *)ffmpegobj.m_pRGBFrame, PIX_FMT_RGB24, ffmpegobj.c->width, ffmpegobj.c->height) >= 0)
							{
								sws_scale(ffmpegobj.scxt, ffmpegobj.m_pYUVFrame->data, ffmpegobj.m_pYUVFrame->linesize, 0,
									ffmpegobj.c->height, ffmpegobj.m_pRGBFrame->data, ffmpegobj.m_pRGBFrame->linesize);
								ffmpegobj.Ffmpeg_Decoder_Show(ffmpegobj.m_pRGBFrame, ffmpegobj.c->width, ffmpegobj.c->height);//����ͼ����ʾ
							}
							sws_freeContext(ffmpegobj.scxt);//�ͷŸ�ʽת������Դ
							avpicture_free((AVPicture *)ffmpegobj.m_pRGBFrame);//�ͷ�֡��Դ
							av_free_packet(&ffmpegobj.avpkt);//�ͷű��ζ�ȡ��֡�ڴ�
						}
					}
					ffmpegobj.avpkt.size -= ffmpegobj.decodelen;
					ffmpegobj.avpkt.data += ffmpegobj.decodelen;
				}
			}
		}
	}
	ffmpegobj.Ffmpeg_Decoder_Close();//�رս�����
}


void CRTP_3Camera_ClientDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
