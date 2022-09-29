#pragma once


// PAGE4 对话框

class PAGE4 : public CDialogEx
{
	DECLARE_DYNAMIC(PAGE4)

public:
	PAGE4(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PAGE4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_PAGE4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CEdit _ctl_data_address;
	CEdit _ctl_data_write;
	CEdit _ctl_data_read;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
