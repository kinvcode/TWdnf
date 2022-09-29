// PAGE4.cpp: 实现文件
//

#include "pch.h"
#include "TWdnf.h"
#include "PAGE4.h"
#include "afxdialogex.h"
#include "dnfBase.h"


// PAGE4 对话框

IMPLEMENT_DYNAMIC(PAGE4, CDialogEx)

PAGE4::PAGE4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PAGE4, pParent)
{

}

PAGE4::~PAGE4()
{
}

void PAGE4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, _ctl_data_address);
	DDX_Control(pDX, IDC_EDIT3, _ctl_data_write);
	DDX_Control(pDX, IDC_EDIT4, _ctl_data_read);
}


BEGIN_MESSAGE_MAP(PAGE4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &PAGE4::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &PAGE4::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL PAGE4::OnInitDialog()
{
	CDialogEx::OnInitDialog();



	return TRUE;
}

// PAGE4 消息处理程序


void PAGE4::OnBnClickedButton1()
{
	// 获取数据地址与写入数值
	int data_address,data_write;
	CString string_address,string_write;
	_ctl_data_address.GetWindowText(string_address);
	_ctl_data_write.GetWindowText(string_write);
	data_address = _ttoi(string_address);
	data_write = _ttoi(string_write);

	// 加密写入数值
	encrypt(data_address,data_write);
}


void PAGE4::OnBnClickedButton2()
{
	// 获取数据地址
	int data_address;
	CString string_address;
	_ctl_data_address.GetWindowText(string_address);
	data_address = _ttoi(string_address);

	// 解密读取数值
	int value = decrypt(data_address);
	CString string_read;
	string_read.Format(L"%d", value);
	_ctl_data_read.SetWindowText(string_read);
}
