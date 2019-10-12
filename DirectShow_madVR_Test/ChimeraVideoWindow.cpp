#include "stdafx.h"
#include "ChimeraVideoWindow.h"

ChimeraVideoWindow::ChimeraVideoWindow(): m_bMsgHandled{0}
{
   CoInitialize(nullptr);
}

ChimeraVideoWindow::~ChimeraVideoWindow()
{
   CoUninitialize();
}

BOOL ChimeraVideoWindow::PreTranslateMessage(MSG* pMsg)
{
   return FALSE;
}

BOOL ChimeraVideoWindow::OnIdle()
{
   return FALSE;
}

void ChimeraVideoWindow::OnFinalMessage(HWND)
{
}

void ChimeraVideoWindow::onChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
}

void ChimeraVideoWindow::onPaint(CDCHandle dc)
{
}

void ChimeraVideoWindow::onSize(UINT nType, CSize size)
{
}

void ChimeraVideoWindow::onLButtonDown(UINT nFlags, CPoint point)
{
}

void ChimeraVideoWindow::onLButtonDblClk(UINT nFlags, CPoint point)
{
}

void ChimeraVideoWindow::onDestroy()
{
   PostQuitMessage(0);
}

int ChimeraVideoWindow::onCreate(LPCREATESTRUCT lpCreateStruct)
{
   auto pLoop = _Module.GetMessageLoop();
   pLoop->AddMessageFilter(this);
   pLoop->AddIdleHandler(this);
   return 0;
}

void ChimeraVideoWindow::onMouseMove(UINT nFlags, CPoint point)
{
}

void ChimeraVideoWindow::fullScreen()
{
   // ウィンドウスタイル変更(メニューバーなし、最前面)
   SetWindowLongPtr(GWL_STYLE, WS_POPUP);
   SetWindowLongPtr(GWL_EXSTYLE, WS_EX_TOPMOST);
   // 最大化する
   ShowWindow(SW_MAXIMIZE);
}

auto ChimeraVideoWindow::ready() noexcept(false) -> void
{
   this->readyVideo();
}

auto ChimeraVideoWindow::ready(const wchar_t* path) noexcept(false) -> void
{
   this->setVideoPath(path);
   this->ready();
}

auto ChimeraVideoWindow::play() const noexcept(false) -> void
{
   this->setVideoWindow();
   ChimeraPlayer::play();
}

auto ChimeraVideoWindow::setVideoWindow() const noexcept(false) -> void
{
   check(this->video_window_->put_Owner(reinterpret_cast<OAHWND>(this->m_hWnd)));
   check(this->video_window_->put_WindowStyle(WS_CHILD | WS_CLIPSIBLINGS));
   check(this->video_window_->put_MessageDrain(reinterpret_cast<OAHWND>(this->m_hWnd)));
   check(this->video_window_->SetWindowForeground(OATRUE));
   check(this->video_window_->put_Visible(OATRUE));
}
