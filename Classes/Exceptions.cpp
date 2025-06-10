#include "Exceptions.h"

fontError::fontError(const std::string &fontName)
    : gameException("Font error: " + fontName) {}

textureError::textureError(const std::string &path)
    : gameException("Texture error: " + path) {}

windowClosed::windowClosed() : gameException("Window closed") {}