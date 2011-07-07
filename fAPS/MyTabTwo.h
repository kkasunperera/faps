#pragma once
#include "Tdsloader.h"

// MyTabTwo dialog
#include "resource.h"
#include "afxwin.h"

class MyTabTwo : public CDialog
{
	DECLARE_DYNAMIC(MyTabTwo)

public:
	MyTabTwo(CWnd* pParent = NULL);   // standard constructor
	virtual ~MyTabTwo();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedLoadtexture();
	afx_msg void OnNMCustomdrawAgeprogress(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedSplit1();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox myCombo;
};
