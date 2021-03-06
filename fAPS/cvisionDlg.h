
#if !defined(AFX_TABEXAMPLE1_H__A4E4384B_0BB6_4FC2_A763_711C0F32B290__INCLUDED_)
#define AFX_TABEXAMPLE1_H__A4E4384B_0BB6_4FC2_A763_711C0F32B290__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbol

/*
* cvisionDlg.h : header file
*/


#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "OpenGLControl.h"
#include "MyTabOne.h"
#include "MyTabThree.h"
#include "MyTabTwo.h"
#include "MyFTabCtrl.h"

// CcvisionDlg dialog
class CcvisionDlg : public CDialogEx
{
	/*!
	 constructor
	\param a CDataExchangeCWnd argument.
	*/
public:
	CcvisionDlg(CWnd* pParent = NULL);	// standard constructor


	/*
	*Dialog Data
	*/
	enum { IDD = IDD_CVISION_DIALOG };  /*!< Enum value IDD. */

	MyTabOne*	m_pDlgPage1;		/*!< MyTabOne value m_pDlgPage1. */
	MyTabTwo*	m_pDlgPage2;		/*!< MyTabTwo value m_pDlgPage2. */
	MyTabThree*	m_pDlgPage3;		/*!< MyTabThree value m_pDlgPage3. */

protected:
	/*!
	 DDX/DDV support
	\param a CDataExchange argument.
	*/
	virtual void DoDataExchange(CDataExchange* pDX);	
	
	/*
	* Implementation
	*/
protected:
	HICON m_hIcon;		/*!< HICON value m_hIcon. */

	/* 
	*Generated message map functions
	*/


	/*!
	 init dialog to add whatever to main dialog
	*/
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CButton m_Button1; /*!< CButton value m_button1. */

private :
	COpenGLControl m_oglWindow;		/*!< COpenGLControl value m_oglWindow. */
	CBitmapButton btnBmpOK, btnBmpCancel, btnBmpHelp;		/*!< CBitmapButton value btnBmpOK. */


public:
	MyFTabCtrl m_TabCtrl;	/*!< MyFTabCtrl value m_TabCtrl. */
	CBitmap m_background;	/*!< CBitmap value m_background. */
	afx_msg void OnBnClickedButton1();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	bool SBitdraw(CDC *pDC, UINT nIDResource, int i);
	CSliderCtrl m_zoomSlider;	/*!< CSliderCtrl value m_zoomSlider. */
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
#endif