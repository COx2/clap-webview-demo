#pragma once

#include "clap-webview-demo-processor.h"

//==============================================================================
namespace choc::ui
{
    class WebView;
    class DesktopWindow;
}

namespace clap_webview_demo
{

//==============================================================================
struct ViewSize
{
    uint32_t width;
    uint32_t height;
};

//==============================================================================
class ClapWebViewDemoEditor
{
public:
    //==============================================================================
    ClapWebViewDemoEditor();
    ~ClapWebViewDemoEditor();

    //==============================================================================
    bool setParentWindow(const clap_window* window);
    bool setViewSize(const ViewSize& viewSize);
    ViewSize getViewSize() const;

private:
    //==============================================================================
    std::unique_ptr<choc::ui::WebView> chocWebView;
    ViewSize cachedViewSize;
};

} // namespace clap_webview_demo
