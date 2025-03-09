/*
** EPITECH PROJECT, 2024
** bsrtype
** File description:
** Drawable - A class that represents drawable objects with an associated resource path.
*/

#ifndef DRAWABLE_HPP_
    #define DRAWABLE_HPP_

    #include <memory>
    #include <string>
    #include <SFML/Graphics.hpp>

/**
 * @class Drawable
 * @brief Represents a drawable object in the game with an associated resource path.
 *
 * The Drawable class is responsible for storing the path to a graphical resource (e.g., textures or sprites).
 * This path can be used to load and render the resource using graphical libraries like SFML.
 */
class Drawable {
    public:
        /**
         * @brief Constructs a Drawable object with the specified resource path.
         * @param path The file path to the drawable resource.
         */
        Drawable(std::string path);

        /**
         * @brief Retrieves the resource path associated with the drawable object.
         * @return A string representing the resource file path.
         */
        std::string getPath() const;

    private:
        std::string _path; /**< The file path to the graphical resource. */
};

#endif /* !DRAWABLE_HPP_ */
