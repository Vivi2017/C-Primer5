#include <string>
#include <iostream>

class screen {
public:
    typedef string:size_type pos;
    using content_type = char;
    screen() = default;
    screen(pos w, pos h):width(w),height(h), contents(w*h, " "){};
    screen(pos w, pos h, char c):width(w),height(h),contents(w*h, c){};
    char get(){ return contents[cursor];};
    char get(pos row, pos col){ return contents[row*width + col];};
    Screen & move(pos row, pos col);
    
private:
    pos cursor =  0;
    pos width = 0,height = 0;
    string contents;
};

inline
Screen &Screen::move(pos row, pos col) {
  cursor = row * width + col;
  return *this;
}

int main() {

  return 0;
}


//Yes, because all the data members of Screen are built-in types or string, which can rely on synthesized versions for //copy and assignment.