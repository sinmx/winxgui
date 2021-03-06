////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2005 Sergey Solozhentsev
// Author: 	Sergey Solozhentsev e-mail: salos@mail.ru
// Product:	WTL Helper
// File:      	AddSpecFuncDlg.cpp
// Created:	09.06.2005 11:03
// 
//   Using this software in commercial applications requires an author
// permission. The permission will be granted to everyone excluding the cases
// when someone simply tries to resell the code.
//   This file may be redistributed by any means PROVIDING it is not sold for
// profit without the authors written consent, and providing that this notice
// and the authors name is included.
//   This file is provided "as is" with no expressed or implied warranty. The
// author accepts no liability if it causes any damage to you or your computer
// whatsoever.
//
////////////////////////////////////////////////////////////////////////////////

// This file was generated by WTL Dialog wizard 
// AddSpecFuncDlg.cpp : Implementation of CAddSpecFuncDlg

#include "stdafx.h"
#include "AddSpecFuncDlg.h"

// CAddSpecFuncDlg
CAddSpecFuncDlg::CAddSpecFuncDlg() : m_bCreate(true), m_bDestroy(true),
m_bEnableCreate(true), m_bEnableDestroy(true), m_bAddCreate(true), m_bRemoveDestroy(true),
m_bDialog(false)
{
}

CAddSpecFuncDlg::~CAddSpecFuncDlg()
{
}

LRESULT CAddSpecFuncDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	CenterWindow();
	SetWindowText(m_Title);
	CString Desc, Check1, Check2, strDesc, strCheck1, strCheck2;
	Desc.LoadString(IDS_STRING_SPEC_FUNC_DESC);
	Check1.LoadString(IDS_STRING_SPEC_CHECK_ADD_CREATE);
	Check2.LoadString(IDS_STRING_SPEC_CHECK_IN_CREATE);
	if (m_bDialog)
	{
		strDesc.Format(Desc, _T("WM_INITDIALOG"));
		strCheck1.Format(Check1, _T("WM_INITDIALOG"));
		strCheck2.Format(Check2, _T("WM_INITDIALOG"));
	}
	else
	{
		strDesc.Format(Desc, _T("WM_CREATE"));
		strCheck1.Format(Check1, _T("WM_CREATE"));
		strCheck2.Format(Check2, _T("WM_CREATE"));
	}
	GetDlgItem(IDC_STATIC_DESC).SetWindowText(strDesc);
	GetDlgItem(IDC_CHECK_CREATE).SetWindowText(strCheck1);
	GetDlgItem(IDC_CHECK_ADD_CREATE).SetWindowText(strCheck2);

	if (!m_bEnableCreate)
		GetDlgItem(IDC_CHECK_CREATE).EnableWindow(FALSE);
	if (!m_bEnableDestroy)
		GetDlgItem(IDC_CHECK_DESTROY).EnableWindow(FALSE);
	DoDataExchange();
	return 1;  // Let the system set the focus
}

LRESULT CAddSpecFuncDlg::OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	DoDataExchange(TRUE);
	EndDialog(wID);
	return 0;
}

LRESULT CAddSpecFuncDlg::OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	EndDialog(wID);
	return 0;
}
LRESULT CAddSpecFuncDlg::OnBnClickCreate(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	CButton wndCheck = GetDlgItem(IDC_CHECK_CREATE);
	CButton wndCheckAdd = GetDlgItem(IDC_CHECK_ADD_CREATE);
	bool bChecked = (wndCheck.GetCheck() == BST_CHECKED);

	if (!bChecked && m_bEnableCreate)
	{
		wndCheckAdd.SetCheck(BST_UNCHECKED);
		wndCheckAdd.EnableWindow(FALSE);
	}
	else
	{
		wndCheckAdd.EnableWindow();
	}
	return 0;
}

LRESULT CAddSpecFuncDlg::OnBnClickDestroy(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	CButton wndCheck = GetDlgItem(IDC_CHECK_DESTROY);
	CButton wndCheckAdd = GetDlgItem(IDC_CHECK_REMOVE_DESTROY);
	bool bChecked = (wndCheck.GetCheck() == BST_CHECKED);

	if (!bChecked && m_bEnableDestroy)
	{
		wndCheckAdd.SetCheck(BST_UNCHECKED);
		wndCheckAdd.EnableWindow(FALSE);
	}
	else
	{
		wndCheckAdd.EnableWindow();
	}
	return 0;
}