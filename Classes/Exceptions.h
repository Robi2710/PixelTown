#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class gameException : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class fontError : public gameException {
public:
    explicit fontError(const std::string& fontName);
};

class textureError : public gameException {
public:
    explicit textureError(const std::string& textureName);
};

class windowClosed : public gameException {
public:
    explicit windowClosed();
};
#endif //EXCEPTIONS_H
