// MainDlg.cpp: 实现文件
//

#include "pch.h"
#include "TWdnf.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "dnfBase.h"


// MainDlg 对话框

IMPLEMENT_DYNAMIC(MainDlg, CDialogEx)

MainDlg::MainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MainDlg::~MainDlg()
{
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ctl_console);
}


BEGIN_MESSAGE_MAP(MainDlg, CDialogEx)

END_MESSAGE_MAP()


// MainDlg 消息处理程序

BOOL MainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: 在此添加额外的初始化代码
	this->Log(L"辅助工具已加载");

	return TRUE;
}

HBRUSH MainDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_EDIT1)
	{
		pDC->SetTextColor(RGB(171, 192, 35));//设置编辑框字体的颜色
		pDC->SetBkColor(RGB(43, 43, 43));//设置字体背景颜色
		return CreateSolidBrush(RGB(43, 43, 43));
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

// 日志输出
void MainDlg::Log(CString msg)
{
	m_log_time = CTime::GetCurrentTime();
	CString time = m_log_time.Format("%H:%M:%S");
	msg = time + L" " + msg;
	m_ctl_console.SetSel(-1);
	m_ctl_console.ReplaceSel(msg);
	m_ctl_console.SetSel(-1);
	m_ctl_console.ReplaceSel(L"\r\n");
}
