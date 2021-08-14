#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <unordered_map>    //unordered_map
#include <SFML/Audio.hpp>

/**
 * @todo write docs
 */
template<typename RESOURCE, typename IDENTIFIER = int>
class ResourceManager {
public:
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager &operator=(const ResourceManager &) = delete;
    ResourceManager() = default;

    template<typename ... Args>
    void load(const IDENTIFIER &id, Args &&... args);

    RESOURCE &get(const IDENTIFIER &id)const;

private:
    std::unordered_map<IDENTIFIER, std::unique_ptr<RESOURCE>> map;
};

template<typename IDENTIFIER>
class ResourceManager<sf::Music, IDENTIFIER> {
public:
    ResourceManager(const ResourceManager &) = delete;
    ResourceManager &operator=(const ResourceManager &) = delete;
    ResourceManager() = default;

    template<typename ... Args>
    void load(const IDENTIFIER &id, Args &&... args);

    sf::Music &get(const IDENTIFIER &id)const;

private:
    std::unordered_map<IDENTIFIER, std::unique_ptr<sf::Music>> map;
};

#include "ResourceManager.tpl"

#endif // RESOURCEMANAGER_H
