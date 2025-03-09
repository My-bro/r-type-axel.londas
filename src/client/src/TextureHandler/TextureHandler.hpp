/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Dec, 2024                                                     *
 * Title           - B-CPP-500-PAR-5-2-rtype-axel.londas                                *
 * Description     -                                                                    *
 *     TextureHandler                                                                   *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_TEXTUREHANDLER_HPP
    #define INCLUDED_TEXTUREHANDLER_HPP

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

class TextureHandler {
public:
    // Add a texture to the map
    bool addTexture(const std::string& key, const std::string& filePath) {
        sf::Texture texture;
        if (!texture.loadFromFile(filePath)) {
            return false;
        }
        textures[key] = texture;
        return true;
    }

    // Get a texture from the map
    sf::Texture* getTexture(const std::string& key) {
        auto it = textures.find(key);
        if (it != textures.end()) {
            return &it->second;
        }
        return nullptr;
    }

private:
    std::map<std::string, sf::Texture> textures;
};

#endif
