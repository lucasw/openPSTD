#ifndef SETTINGS_H
#define SETTINGS_H

#include <QColor>

class Settings {
public:
    inline static Settings* getInstance() {
        if (!instance) {
            instance = new Settings();
        }
        return instance;
    }
    
    inline void destruct() {
        delete instance;
    }
    
    // Color of the background grid
    QRgb gridColor = qRgb(127, 180, 196);
    
    // Color of the window background
    QRgb bgColor = qRgb(255, 255, 255);
    
    // Color of the zoom level reference
    QRgb zoomColor = qRgb(0, 0, 0);
    
    // Clamping distance for the cursor
    int clampDist = 10;
    
    // Color of the fps counter
    QRgb fpsColor = qRgb(0, 0, 255);
    
    // Color of a source
    QRgb sourceColor = qRgb(255, 0, 0);
    
    // Color of a receiver
    QRgb receiverColor = qRgb(0, 255, 0);
    
    // Color of a wall depending on its absorption
    QRgb wallColor0 = qRgb(0, 0, 0);
    QRgb wallColor1 = qRgb(0, 255, 0);
    
    // GUI grid size
    int guiGridSize = 16;
    
    // PSTD settings
    double pstdGridSize = 0.2;
    int windowSize = 32;
    double renderTime = 1;
    double airDensity = 1.2;
    int soundSpeed = 340;
private:
    static Settings* instance;
    
    inline Settings() {}
};

#endif