# clap-webview-demo
The demo project for WebView integration with CLAP(CLever Audio Plugin) .

## Motivation

This project demonstrates a minimal implementation of embedding a WebView within a CLAP (CLever Audio Plugin) audio plugin. The primary goal is to provide developers with a streamlined example of how to integrate web technologies into audio plugin interfaces using CLAP.

Key motivations for this project include:

1. Bridging the gap between traditional audio plugin development and modern web technologies.
2. Enabling developers to leverage the power and flexibility of web-based user interfaces within the context of audio plugins.
3. Providing a starting point for creating more complex and feature-rich audio plugins with web-based GUIs.
4. Exploring the potential of CLAP as a forward-thinking audio plugin format that supports innovative interface designs.
5. Offering a learning resource for developers interested in combining audio programming with web development.

By focusing on a minimal implementation, this project aims to reduce complexity and highlight the core concepts and techniques required to successfully integrate a WebView into a CLAP plugin. This approach allows developers to easily understand the fundamental principles and build upon them for their own projects.

**Note on Linux Implementation**  
It's important to note that this project does not currently include a Linux implementation. The process of integrating WebView using Xembed in Linux environments proved to be significantly more complex than anticipated. Due to these challenges, the decision was made to focus on other platforms for the time being. Developers interested in Linux support may need to explore alternative solutions or contribute to expanding the project's capabilities in this area.

## How to build

### Prerequisites

In general, having a setup that allows building modern C++ should be sufficient.

+ Visual Studio: 2022 (Windows)
+ Xcode: 14.2 or later (macOS)
+ CMake: 3.25 or later
+ Git: 2.3 or later

### Windows - Visual Studio 2022

```sh
cmake --preset vs2022
cmake --build --preset vs2022-release
```

### macOS - Xcode

```sh
cmake --preset xcode
cmake --build --preset xcode-release
```

## Attention Regarding Licenses

If you are using this project to create and distribute software, please ensure compliance with the licenses of the following software libraries:

+ [clap](https://github.com/free-audio/clap)
+ [clap-helpers](https://github.com/free-audio/clap-helpers)  
+ [CHOC](https://github.com/Tracktion/choc)  
