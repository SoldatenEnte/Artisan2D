#ifndef LAYOUT_H
#define LAYOUT_H

class Layout {
public:
    static void Draw();  // Draw the layout
    static void HandleResize(int width, int height);
private:
    static void DrawSection(int x, int y, int w, int h, const char* text);  // Draw a section with text
};

#endif // LAYOUT_H