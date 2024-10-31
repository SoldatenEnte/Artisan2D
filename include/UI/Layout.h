#ifndef LAYOUT_H
#define LAYOUT_H

class Layout {
public:
    static void Draw();
    static void HandleResize(int width, int height);
private:
    static void DrawSection(int x, int y, int w, int h, float r, const char* text);
};

#endif