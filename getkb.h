#ifndef iolib
#define iolib

int getkb();
int getkbe();

// Linux-compatible alternatives
#ifdef __linux__
int getch();
int getche();
#endif

#endif //iolib