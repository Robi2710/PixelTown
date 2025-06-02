#include <iostream>
#include "Classes/Application.h"
#include "Classes/Exceptions.h"

int main() {
    try {
        Application app;
        return app.run();
    }
    catch (const windowClosed& e) {
        std::cerr << e.what() << std::endl;
        return 0;
    }

    catch (const fontError& e) {
        std::cerr << "Font loading error: " << e.what() << std::endl;
        return 1;
    }

    catch (const std::exception& e) {
        std::cerr << "Unhandled error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
