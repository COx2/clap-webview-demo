#include "clap-webview-demo-editor.h"
#include <gui/choc_WebView.h>
#include <platform/choc_ObjectiveCHelpers.h>

namespace clap_webview_demo
{

//==============================================================================
ClapWebViewDemoEditor::ClapWebViewDemoEditor()
{
    cachedViewSize = ViewSize{ 960, 800 };

    chocWebView = std::make_unique<choc::ui::WebView>();
    chocWebView->navigate("https://u-he.com/community/clap/");
}

ClapWebViewDemoEditor::~ClapWebViewDemoEditor()
{
    chocWebView.reset();
}

//==============================================================================
bool ClapWebViewDemoEditor::setParentWindow(const clap_window* parent)
{
#if CLAP_MAC
    try
    {
        choc::objc::call<void>((id)parent->ptr, "addSubview:", (id)chocWebView->getViewHandle());
        return true;
    }
    catch (...) {}
    return false;
#elif CLAP_WINDOWS
    if (SetParent(static_cast<HWND> (chocWebView->getViewHandle()), static_cast<HWND> (parent->ptr)) == nullptr)
    {
        return false;
    }
    ShowWindow(static_cast<HWND> (chocWebView->getViewHandle()), SW_SHOWNA);
    return true;
#else
    (void)parent;
    return false;
#endif
    return false;
}

bool ClapWebViewDemoEditor::setViewSize(const ViewSize& viewSize)
{
    cachedViewSize = viewSize;

#if CLAP_MAC
    CHOC_AUTORELEASE_BEGIN
    auto frame = choc::objc::CGRect{ { 0, 0 }, { (choc::objc::CGFloat)viewSize.width, (choc::objc::CGFloat)viewSize.height } };
    choc::objc::call<void>((id)chocWebView->getViewHandle(), "setFrame:", frame);
    CHOC_AUTORELEASE_END
    return true;
#elif CLAP_WINDOWS
    return MoveWindow(static_cast<HWND> (chocWebView->getViewHandle()), 
    0, 0, static_cast<int> (viewSize.width), static_cast<int> (viewSize.height), 
    true);
#else
    return false;
#endif
    return false;
}

ViewSize ClapWebViewDemoEditor::getViewSize() const
{
    return cachedViewSize;
}

} // namespace clap_webview_demo
