#pragma once

#include <clap/helpers/plugin.hh>

namespace clap_webview_demo
{

class ClapWebViewDemoEditor;

//==============================================================================
class ClapWebViewDemoProcessor
    : public clap::helpers::Plugin<clap::helpers::MisbehaviourHandler::Terminate, clap::helpers::CheckingLevel::Maximal>
{
public:
    //==============================================================================
    explicit ClapWebViewDemoProcessor(const clap_host *host);
    ~ClapWebViewDemoProcessor() override;

    //==============================================================================
    static clap_plugin_descriptor desc;

    //==============================================================================
    bool activate(double sampleRate, uint32_t minFrameCount, uint32_t maxFrameCount) noexcept override
    {
        return true;
    }

private:
    //==============================================================================
    bool implementsGui() const noexcept override { return true; }
    bool guiIsApiSupported(const char *api, bool isFloating) noexcept override;

    bool guiCreate(const char *api, bool isFloating) noexcept override;
    void guiDestroy() noexcept override;
    bool guiSetParent(const clap_window *window) noexcept override;

    bool guiSetScale(double scale) noexcept override;
    bool guiCanResize() const noexcept override { return true; }
    bool guiAdjustSize(uint32_t *width, uint32_t *height) noexcept override;
    bool guiSetSize(uint32_t width, uint32_t height) noexcept override;
    bool guiGetSize(uint32_t *width, uint32_t *height) noexcept override;

    //==============================================================================
    std::unique_ptr<ClapWebViewDemoEditor> activeEditor{ nullptr };
};

} // namespace clap_webview_demo