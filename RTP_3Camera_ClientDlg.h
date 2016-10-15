
// RTP_3Camera_ClientDlg.h : ͷ�ļ�
//

#pragma once
#include "RtpTransport.h"
#include "cv.h"
#include "highgui.h"
#include "CvvImage.h"
#include "Ffmpeg_Decode.h"


// CRTP_3Camera_ClientDlg �Ի���
class CRTP_3Camera_ClientDlg : public CDialogEx
{
// ����
public:
	CRTP_3Camera_ClientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_RTP_3CAMERA_CLIENT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	CRect rect;
	HICON m_hIcon;
	CStatic* pStc; //��ʶͼ����ʾ��Picture�ؼ�
	CDC* pDC; //��Ƶ��ʾ�ؼ��豸������
	HDC hDC; //��Ƶ��ʾ�ؼ��豸���
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	Ffmpeg_Decoder *m_decoder;
	
	DECLARE_MESSAGE_MAP()
public:
	CRtpTransport rtpTransport;
	void DrawPicToHDC(IplImage * img , UINT ID);
	afx_msg void OnBnClickedOk();

	void OnOpen(IplImage * img);//test
	void OnTimer(UINT nIDEvent);//test
	BOOL OnInitDialog22();//test
	void testDecoder();
};
