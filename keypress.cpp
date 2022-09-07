#include <termios.h>
#include <stdio.h>
#include <iostream>

int scanKeyboard() {
  int in;
  struct termios new_settings;
  struct termios stored_settings;
  tcgetattr(0, &stored_settings);
  new_settings = stored_settings;
  new_settings.c_lflag &= (~ICANON);
  new_settings.c_cc[VTIME] = 0;
  tcgetattr(0, &stored_settings);
  new_settings.c_cc[VMIN] = 1;
  tcsetattr(0, TCSANOW, &new_settings);
  in = getchar();
  tcsetattr(0, TCSANOW, &stored_settings);
  return in;
  
}

int main(int argc, char const *argv[])
{
  while(1) {
    std::cout << scanKeyboard() << std::endl;
  }
  return 0;
}
