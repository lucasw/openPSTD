#include "receiver.h"

/**
 * Constructor.
 * 
 * @param x  The x coordinate of the receiver
 * @param y  The y coordinate of the receiver
 * @param settings  A reference to the Settings instance
 */
Receiver::Receiver(int x, int y) {
	// Save position locally
	this->x = x;
	this->y = y;
	
	// Load the receiver image
	image = QImage(":/new/prefix1/icons/receiver.png");
}

/**
 * Draws the receiver.
 * 
 * @param pixels  The pixels array to draw to
 * @param zoom  The current zoom level (as in model)
 * @param offsetX  The current x offset of the scene (as in model)
 * @param offsetY  The current y offset of the scene (as in model)
 * @param selected  Whether or not the receiver is currently selected
 */
void Receiver::draw(QImage* pixels, int zoom, int offsetX, int offsetY, bool selected) {
	// Draw the receiver image
	QPainter p;
	p.begin(pixels);
	p.drawImage(
		zoom * x + offsetX - 5,
		zoom * y + offsetY - 5,
		image
	);
	p.end();
	
	// Check if this receiver is selected
	if (selected) {
		// Draw a square around the receiver
		int d = 8;
		for (int i = -d; i <= d; i++) {
			setPixel(
				zoom * x + i + offsetX,
				zoom * y + d + offsetY,
				qRgb(0, 255, 255),
				pixels
			);
			setPixel(
				zoom * x + i + offsetX,
				zoom * y - d + offsetY,
				qRgb(0, 255, 255),
				pixels
			);
			setPixel(
				zoom * x + d + offsetX,
				zoom * y + i + offsetY,
				qRgb(0, 255, 255),
				pixels
			);
			setPixel(
				zoom * x - d + offsetX,
				zoom * y + i + offsetY,
				qRgb(0, 255, 255),
				pixels
			);
		}
	}
}

/**
 * Sets a single pixel's color.
 * 
 * @param x  The x coordinate of the pixel
 * @param y  The y coordinate of the pixel
 * @param color  The color to give the pixel
 * @param pixels  A pixels array to draw to
 */
void Receiver::setPixel(int x, int y, QRgb color, QImage* pixels) {
	if (x < 0 || y < 0) return;
	if (x >= pixels->width() || y >= pixels->height()) return;
	pixels->setPixel(x, y, color);
}