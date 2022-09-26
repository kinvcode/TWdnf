// PAGE2.cpp: 实现文件
//

#include "pch.h"
#include "TWdnf.h"
#include "PAGE2.h"
#include "afxdialogex.h"


// PAGE2 对话框

IMPLEMENT_DYNAMIC(PAGE2, CDialogEx)

PAGE2::PAGE2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PAGE2, pParent)
{

}

PAGE2::~PAGE2()
{
}

void PAGE2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PAGE2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &PAGE2::OnBnClickedButton1)
END_MESSAGE_MAP()


// PAGE2 消息处理程序


void PAGE2::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}
