// PAGE1.cpp: 实现文件
//

#include "pch.h"
#include "TWdnf.h"
#include "PAGE1.h"
#include "afxdialogex.h"


// PAGE1 对话框

IMPLEMENT_DYNAMIC(PAGE1, CDialogEx)

PAGE1::PAGE1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PAGE1, pParent)
{

}

PAGE1::~PAGE1()
{
}

void PAGE1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PAGE1, CDialogEx)
END_MESSAGE_MAP()


// PAGE1 消息处理程序
