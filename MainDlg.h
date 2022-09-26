#pragma once
#include "afxdialogex.h"

// MainDlg 对话框

class MainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MainDlg)

public:
	MainDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MainDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:

	// tab控件容器
	CDialog* m_tab_box[3];
	// tab控件当前索引
	int m_cur_tab_index;
	// 日志输出时间
	CTime m_log_time;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:

	// tab页面
	//PAGE1 page1;
	//PAGE2 page2;
	//PAGE3 page3;

	CEdit m_ctl_console;

	void MainDlg::Log(CString msg);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
