# Installing wxWidgets 3.2.2.1 on WSL2 Ubuntu 22.04.2

## Prerequisites

Before you begin, ensure that you have the following prerequisites:

- A WSL2 installation running Ubuntu 22.04.2.
- Basic knowledge of working with the terminal.

## Steps

### 1. Update System Packages

```bash
sudo apt-get update
sudo apt-get upgrade
```

### 2. Install Build Tools and Dependencies

```bash
sudo apt-get install build-essential libgtk-3-dev libgl1-mesa-dev libglu1-mesa-dev libegl1-mesa-dev libcurl4-openssl-dev libwebkit2gtk-4.0-dev
```

### 3. Download wxWidgets 3.2.2.1 

https://www.wxwidgets.org/downloads/

### 4. Move the Archive
Move the archive to where you want it to be, i made a folder .local/bin where i put it.

```bash
mv path/to/wxWidgets-3.2.2.1.tar.bz2 .local/bin/
```

### 5. Ectract the Archive

```bash
tar -xvjf wxWidgets-3.2.2.1.tar.bz2
rm -rf wxWidgets-3.2.2.1.tar.bz2
```

### 6. Condigure and Build wxWidgets

```bash
cd wxWidgets-3.2.2.1 
../configure --with-gtk
make
sudo make install
```

### 7. Update Library Cache
```bash
sudo ldconfig
```
(if you get "ldconfig: command not found", try using /sbin/ldconfig)

### 8. Test installation

Make a main.cpp

```cpp
// main.cpp
#include <wx/wx.h>

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {}
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame* frame = new MyFrame("Hello, wxWidgets!");
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
```

Make a makefile

```makefile
app: main.cpp
    g++ main.cpp `wx-config --cxxflags --libs` -o app.out

clean: 
    rm -rf app.out
```

Compile and run the application

```bash
make app
./app.out
```

If you see a window with "Hello, wxWidgets!" displayed, then wxWidgets is successfully installed.

If you use Neovim or other editor that uses clang for compiling create a compile_commands.json with bear

```bash
sudo apt-get update
sudo apt-get install bear
bear -- make app
```

After that you shouldnt get file not found errors in you editor
