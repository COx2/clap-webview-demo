#include "clap-webview-demo-processor.h"

#include <iostream>

namespace clap_webview_demo::pluginentry
{

//==============================================================================
uint32_t clap_get_plugin_count(const clap_plugin_factory* factory)
{ 
    return 1;
}

const clap_plugin_descriptor* clap_get_plugin_descriptor(const clap_plugin_factory* factory, uint32_t w)
{
    return &ClapWebViewDemoProcessor::desc;
}

static const clap_plugin* clap_create_plugin(const clap_plugin_factory* factory, const clap_host* host, const char* plugin_id)
{
    if (strcmp(plugin_id, ClapWebViewDemoProcessor::desc.id))
    {
        return nullptr;
    }
    auto processor = new ClapWebViewDemoProcessor(host);
    return processor->clapPlugin();
}

const CLAP_EXPORT struct clap_plugin_factory clap_webview_demo_factory = {
    clap_webview_demo::pluginentry::clap_get_plugin_count,
    clap_webview_demo::pluginentry::clap_get_plugin_descriptor,
    clap_webview_demo::pluginentry::clap_create_plugin,
};

//==============================================================================
static const void* get_factory(const char* factory_id) 
{ 
    return (!strcmp(factory_id,CLAP_PLUGIN_FACTORY_ID)) ? &clap_webview_demo_factory : nullptr;
}

bool clap_init(const char* processor)
{
    return true;
}

void clap_deinit() 
{
}

} // namespace clap_webview_demo::pluginentry

extern "C"
{
const CLAP_EXPORT struct clap_plugin_entry clap_entry = {
    CLAP_VERSION,
    clap_webview_demo::pluginentry::clap_init,
    clap_webview_demo::pluginentry::clap_deinit,
    clap_webview_demo::pluginentry::get_factory
};
}
