/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** systems - Function declarations for various game systems.
*/

#ifndef SYSTEMS_HPP_
    #define SYSTEMS_HPP_

    #include <ecs/Registry.hpp>
    #include "../components/Pipe.hpp"
    #include "../components/Player.hpp"
    #include "../components/Position.hpp"
    #include "../components/Velocity.hpp"
    #include "../components/Drawable.hpp"
    #include "../components/HitBox.hpp"
    #include "../components/Point.hpp"

    /**
     * @brief Spawns pipes at regular intervals.
     */
    void spawn_pipes_system(Registry &r);

    /**
     * @brief Moves the pipes to the left.
     */
    void pipes_mouvement_system(Registry &r, SparseArray<Pipe> &pipes, SparseArray<Position> &positions, SparseArray<Velocity> &velocities);

    /**
     * @brief Renders all drawable entities.
     */
    void pipes_render_system(Registry &r, SparseArray<Pipe> &pipes, SparseArray<Drawable> &drawables, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxes);

    /**
     * @brief Spawns the player entity.
     */
    void spawn_player_system(Registry &r);

    /**
     * @brief Moves the player entity based on user input.
     */
    void player_control_system(Registry &r, SparseArray<Player> &players, SparseArray<Position> &positions, SparseArray<Velocity> &velocities);

    /**
     * @brief Renders the player entity.
     */
    void player_render_system(Registry &r, SparseArray<Player> &players, SparseArray<Position> &positions, SparseArray<Drawable> &drawables);

    /**
     * @brief Clears the render window.
     */
    void clear_render_system(Registry &r);

    /**
     * @brief Displays the render window.
     */
    void display_render_system(Registry &r);

    /**
     * @brief Moves the player entity based on its velocity.
     */
    void player_mouvement_system(Registry &r, SparseArray<Player> &players, SparseArray<Position> &positions, SparseArray<Velocity> &velocities);

    /**
     * @brief Updates the player's score based on pipe positions.
     */
    void score_system(Registry &r, SparseArray<Pipe> &pipes, SparseArray<Position> &positions, SparseArray<Point> &points);

    /**
     * @brief Renders the player's score.
     */
    void score_render_system(Registry &r);

    /**
     * @brief Checks for collisions between the player and pipes.
     */
    void player_pipes_collision_system(Registry &r, SparseArray<Player> &players, SparseArray<Pipe> &pipes, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxes);

    /**
     * @brief Renders the background image.
     */
    void background_render_system(Registry &r);

#endif /* !SYSTEMS_HPP_ */
