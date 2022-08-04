#include "helpers.h"

// image[height][] is the row
// image[][width] is the column

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Calculate the average of brightness for every pixel and equal all 3 values to the same to create grey

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // sepiaRed   = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    // sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    // sepiaBlue  = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Invert rows
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Using box blur, averaging 3x3 grid for each pixel
    return;
}
