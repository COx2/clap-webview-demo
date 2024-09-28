#include "clap-webview-demo-processor.h"
#include "clap-webview-demo-editor.h"

// Eject the core symbols for the plugin
#include <clap/helpers/plugin.hh>
#include <clap/helpers/plugin.hxx>
#include <clap/helpers/host-proxy.hh>
#include <clap/helpers/host-proxy.hxx>

namespace clap_webview_demo
{

//==============================================================================
const char* features[] = { CLAP_PLUGIN_FEATURE_AUDIO_EFFECT, CLAP_PLUGIN_FEATURE_COMPRESSOR, nullptr };
clap_plugin_descriptor ClapWebViewDemoProcessor::desc =
{ 
    CLAP_VERSION,
    "com.cox2.clap-webview-demo",
    "Clap WebView Demo",
    "COx2",
    "",
    "",
    "",
    "1.0.0",
    "A simple WebView integrate.",
    features 
};

//==============================================================================
ClapWebViewDemoProcessor::ClapWebViewDemoProcessor(const clap_host* host)
    : clap::helpers::Plugin<clap::helpers::MisbehaviourHandler::Terminate, clap::helpers::CheckingLevel::Maximal>(&desc, host)
{
}

ClapWebViewDemoProcessor::~ClapWebViewDemoProcessor()
{
    if (activeEditor != nullptr)
    {
        guiDestroy();
    }
}

//==============================================================================
bool ClapWebViewDemoProcessor::guiIsApiSupported(const char* api, bool isFloating) noexcept
{
    if (isFloating)
    {
        return false;
    }

#if CLAP_MAC
    if (strcmp(api, CLAP_WINDOW_API_COCOA) == 0)
    {
        return true;
    }
#endif

#if CLAP_WINDOWS
    if (strcmp(api, CLAP_WINDOW_API_WIN32) == 0)
    {
        return true;
    }
#endif

#if CLAP_LINUX
    if (strcmp(api, CLAP_WINDOW_API_X11) == 0)
    {
        return true;
    }
#endif

    return false;
}

bool ClapWebViewDemoProcessor::guiCreate(const char* api, bool isFloating) noexcept
{
    assert(!activeEditor.get());

    activeEditor = std::make_unique<ClapWebViewDemoEditor>();

    return activeEditor.get() != nullptr;
}

void ClapWebViewDemoProcessor::guiDestroy() noexcept
{
    assert(activeEditor.get());
    
    activeEditor.reset(nullptr);
}

bool ClapWebViewDemoProcessor::guiSetParent(const clap_window* window) noexcept
{
    assert(activeEditor.get());

    activeEditor->setParentWindow(window);

    return true;
}

bool ClapWebViewDemoProcessor::guiSetScale(double scale) noexcept
{
    return false;
}

bool ClapWebViewDemoProcessor::guiSetSize(uint32_t width, uint32_t height) noexcept
{
    assert(activeEditor.get());

    activeEditor->setViewSize(ViewSize{ width, height });

    return true;
}

bool ClapWebViewDemoProcessor::guiGetSize(uint32_t* width, uint32_t* height) noexcept
{
    const auto viewSize = activeEditor->getViewSize();

    *width = viewSize.width;
    *height = viewSize.height;

    return true;
}

bool ClapWebViewDemoProcessor::guiAdjustSize(uint32_t* width, uint32_t* height) noexcept
{
    return true;
}

}  // namespace clap_webview_demo

