// MainDlg.cpp: 实现文件
//

#include "pch.h"
#include "TWdnf.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "dnfBase.h"
#include "memory.h"


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
	DDX_Control(pDX, IDC_TAB1, m_ctl_tab);
}


BEGIN_MESSAGE_MAP(MainDlg, CDialogEx)

	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &MainDlg::OnTcnSelchangeTab1)
	ON_WM_HOTKEY()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// MainDlg 消息处理程序

BOOL MainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	initTabCtl();

	// 初始化热键
	RegisterHotKey(GetSafeHwnd(), 1, NULL, VK_END); // 满血满蓝
	RegisterHotKey(GetSafeHwnd(), 2, NULL, VK_OEM_3); // 秒杀

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

void MainDlg::initTabCtl()
{
	// 初始化tab控件
	m_ctl_tab.InsertItem(0, L"主界面");
	m_ctl_tab.InsertItem(1, L"数据界面");
	m_ctl_tab.InsertItem(2, L"地图遍历");
	m_ctl_tab.InsertItem(3, L"加密解密");
	page1.Create(IDD_DIALOG_PAGE1, &m_ctl_tab);
	page2.Create(IDD_DIALOG_PAGE2, &m_ctl_tab);
	page3.Create(IDD_DIALOG_PAGE3, &m_ctl_tab);
	page4.Create(IDD_DIALOG_PAGE4, &m_ctl_tab);
	CRect rc;
	m_ctl_tab.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	page1.MoveWindow(&rc);
	page2.MoveWindow(&rc);
	page3.MoveWindow(&rc);
	page4.MoveWindow(&rc);
	page1.ShowWindow(SW_SHOW);
	page2.ShowWindow(SW_HIDE);
	page3.ShowWindow(SW_HIDE);
	page4.ShowWindow(SW_HIDE);
	m_tab_box[0] = &page1;
	m_tab_box[1] = &page2;
	m_tab_box[2] = &page3;
	m_tab_box[3] = &page4;
	m_cur_tab_index = 0;
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


void MainDlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	int index = m_ctl_tab.GetCurSel();
	int count = m_ctl_tab.GetItemCount();

	for (int i = 0; i < count; i++)
	{
		m_tab_box[i]->ShowWindow(SW_HIDE);
	}

	m_tab_box[index]->ShowWindow(SW_SHOW);

	*pResult = 0;
}


void MainDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	switch (nHotKeyId)
	{
	case 1:
		// 满血满蓝
		break;
	case 2:
	{
		//int res = readInt(0x1A5FB4C);
		int game_status = readInt(readInt(readInt(0x1A5FB4C) + 0x14) + 0x28);
		if (game_status != 3) {
			Log(L"请进入图内开启");
			break;
		}

		Log(L"开启秒杀");

		int begin = readInt(readInt(readInt(0x1AB7CDC) + 0xB8) + 0xB0);
		int end = readInt(readInt(readInt(0x1AB7CDC) + 0xB8) + 0xB4);

		int length = (end - begin) / 4;

		for (int i = 0; i < length; i++)
		{
			// 判断阵营和类型
			int monster_address = readInt(begin + i * 4);
			int monster_camp = readInt(monster_address + 0x644);
			int monster_type = readInt(monster_address + 0x90);
			if (monster_camp == 100) {
				if (monster_type == 529 || monster_type == 273)
				{
					encrypt(monster_address + 0x3088, 1);
				}
			}
		}

	}


	break;
	default:
		break;
	}

	CDialogEx::OnHotKey(nHotKeyId, nKey1, nKey2);
}