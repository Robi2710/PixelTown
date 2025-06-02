#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

template<typename T>
class ResourceManager {
private:
    std::map<std::string, std::unique_ptr<T>> resources;

public:
    T& getResource(const std::string& id) {
        auto it = resources.find(id);
        if (it != resources.end()) {
            return *it->second;
        }
        throw std::runtime_error("Resource not found: " + id);
    }

    template<typename... Args>
    T& getResource(const std::string& id, const std::string& filename, Args&&... args) {
        auto it = resources.find(id);
        if (it != resources.end()) {
            return *it->second;
        }

        auto resource = std::make_unique<T>();
        if constexpr (std::is_same_v<T, sf::SoundBuffer> ||
                      std::is_same_v<T, sf::Texture> ||
                      std::is_same_v<T, sf::Font>) {
            if (!resource->loadFromFile(filename, std::forward<Args>(args)...)) {
                throw std::runtime_error("Failed to load resource: " + filename);
            }
                      } else {
                          resource = std::make_unique<T>(filename, std::forward<Args>(args)...);
                      }

        auto [it_inserted, success] = resources.insert({id, std::move(resource)});
        return *it_inserted->second;
    }

    void clear() {
        resources.clear();
    }
};

#endif // RESOURCE_MANAGER_H