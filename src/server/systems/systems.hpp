/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** systems - Function declarations for various game systems.
*/

#ifndef SYSTEMS_HPP_
    #define SYSTEMS_HPP_

    #include <ecs/Registry.hpp>
    #include "../components/Mob.hpp"
    #include "../components/Damage.hpp"
    #include "../components/HitBox.hpp"
    #include "../components/Position.hpp"
    #include "../components/Health.hpp"
    #include "../components/MobBullet.hpp"
    #include "../components/Player.hpp"
    #include "../components/PlayerBullet.hpp"
    #include "../components/Controllable.hpp"
    #include "../components/Drawable.hpp"
    #include "../components/Velocity.hpp"
    #include "../components/ShootCooldown.hpp"
    #include "../components/LocalPlayer.hpp"
    #include "../components/NetworkPlayer.hpp"
    #include "../components/Boulder.hpp"
    #include "../components/BasicCanon.hpp"
    #include "../components/LaserCanon.hpp"
    #include "../components/PlayerLaser.hpp"
    #include "../components/LaserCanonCollectable.hpp"
    #include "../components/HealthCollectable.hpp"
    #include "../components/TurretMob.hpp"
    #include "../components/TurretMobBullet.hpp"
    #include "../components/BossMob.hpp"
    #include "../components/BossMobBullet.hpp"

/**
 * @brief Handles collisions between player bullets and mobs.
 */
void players_bullets_mobs_collisions_system(Registry &r, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<Damage> &damages, SparseArray<Health> &healths, SparseArray<Mob> &mobs, SparseArray<PlayerBullet> &bullets);

/**
 * @brief Handles collisions between mob bullets and players.
 */
void mobs_bullets_players_collision_system(Registry &r, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<Damage> &damages, SparseArray<Health> &healths, SparseArray<MobBullet> &bullets, SparseArray<Player> &players);

/**
 * @brief Processes mob deaths based on their health.
 */
void deaths_mobs_system(Registry &r, SparseArray<Mob> &mobs, SparseArray<Health> &healths, SparseArray<Position> &positions);
/**
 * @brief Processes player deaths based on their health.
 */
void deaths_players_system(Registry &r, SparseArray<Player> &players, SparseArray<Health> &healths, SparseArray<Position> &positions);

/**
 * @brief Handles input for local players.
 */
void local_player_input_system(Registry &r, SparseArray<LocalPlayer> &local_players, SparseArray<Controllable> &controllables);

/**
 * @brief Updates movement for mob bullets.
 */
void mobs_bullets_mouvement_system(Registry &r, SparseArray<Position> &positions, SparseArray<Velocity> &velocities, SparseArray<MobBullet> &bullets);

/**
 * @brief Updates movement for player bullets.
 */
void players_bullets_mouvement_system(Registry &r, SparseArray<Position> &positions, SparseArray<Velocity> &velocities, SparseArray<PlayerBullet> &bullets);

/**
 * @brief Handles player movement based on input.
 */
void players_mouvement_system(Registry &r, SparseArray<Player> &players, SparseArray<Position> &positions, SparseArray<Velocity> &velocities, SparseArray<Controllable> &controllables);

/**
 * @brief Manages player shooting mechanics.
 */
void players_basic_canon_shooting_system(Registry &r, SparseArray<Player> &players, SparseArray<BasicCanon> &canons ,SparseArray<Position> &positions, SparseArray<Controllable> &controllables, SparseArray<ShootCooldown> &shoot_cooldowns);

/**
 * @brief Handles AI behavior for mobs, including shooting and movement.
 */
void mobs_ai_system(Registry &r, SparseArray<Position> &positions, SparseArray<Velocity> &velocities, SparseArray<Mob> &mobs, SparseArray<ShootCooldown> &shoot_cooldowns);

/**
 * @brief Checks if the boss is dead to trigger win conditions.
 */
void win_detection_system(Registry &r, SparseArray<BossMob> &bosses);

/**
 * @brief Checks if all players are dead to trigger lose conditions.
 */
void lose_detection_system(Registry &r, SparseArray<Player> &players);

/**
 * @brief Spawns players
 */
void spawn_players_system(Registry &r);

/**
 * @brief Processes input from networked players.
 */
void network_players_inputs_system(Registry &r, SparseArray<NetworkPlayer> &network_players, SparseArray<Controllable> &controllables);

/**
 * @brief Handles network packets, updating the game state for networked players and entities.
 */
void network_packet_system(Registry &r);

void clear_render_system(Registry &r);

void display_render_system(Registry &r);

void boulders_render_system(Registry &r, SparseArray<Boulder> &boulders, SparseArray<Position> &positions, SparseArray<Drawable> &drawables);

void players_render_system(Registry &r, SparseArray<Player> &players, SparseArray<Position> &positions, SparseArray<Drawable> &drawables);

void players_bullets_render_system(Registry &r, SparseArray<PlayerBullet> &bullets, SparseArray<Position> &positions, SparseArray<Drawable> &drawables);

void mobs_render_system(Registry &r, SparseArray<Mob> &mobs, SparseArray<Position> &positions, SparseArray<Drawable> &drawables);

void mobs_bullets_render_system(Registry &r, SparseArray<MobBullet> &bullets, SparseArray<Position> &positions, SparseArray<Drawable> &drawables);

void spawn_mobs_system(Registry &reg);

void spawn_boulders_system(Registry &r);

void boulders_mouvement_system(Registry &r, SparseArray<Boulder> &boulders, SparseArray<Position> &positions, SparseArray<Velocity> &velocities);

void boulders_players_collisions_system(Registry &r, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<Boulder> &boulders, SparseArray<Player> &players, SparseArray<Health> &healths, SparseArray<Damage> &damages);

void players_laser_canon_shooting_system(Registry &r, SparseArray<Player> &players, SparseArray<LaserCanon> &canons, SparseArray<Position> &positions, SparseArray<Controllable> &controllables, SparseArray<ShootCooldown> &shoot_cooldowns);

void players_lasers_mobs_collisions_system(Registry &r, SparseArray<PlayerLaser> &lasers, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<Mob> &mobs, SparseArray<Health> &healths, SparseArray<Damage> &damages);

void players_lasers_mouvement_system(Registry &r, SparseArray<PlayerLaser> &lasers, SparseArray<Position> &positions, SparseArray<Velocity> &velocities);

void players_lasers_render_system(Registry &r, SparseArray<PlayerLaser> &lasers, SparseArray<Position> &positions, SparseArray<Drawable> &drawables);

void spawn_laser_canons_collectables_system(Registry &r);

void laser_canons_collectables_render_system(Registry &r, SparseArray<LaserCanonCollectable> &laser_canons, SparseArray<Position> &positions, SparseArray<Drawable> &drawables);

void laser_canons_collectables_players_collisions_system(Registry &r, SparseArray<LaserCanonCollectable> &laser_canons, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<Player> &players);

void players_healths_render_system(Registry &r, SparseArray<Player> &players, SparseArray<Health> &healths, SparseArray<Position> &positions);

void health_collectables_players_collisions_system(Registry &r, SparseArray<HealthCollectable> &healths_collectables, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<Health> &healths, SparseArray<Player> &players);

void health_collectables_render_system(Registry &r, SparseArray<HealthCollectable> &healths_collectables, SparseArray<Position> &positions, SparseArray<Drawable> &drawables);

void spawn_health_collectables_system(Registry &r);

void turrets_mobs_ai_system(Registry &r, SparseArray<TurretMob> &turrets, SparseArray<Position> &positions, SparseArray<ShootCooldown> &shoot_cooldowns, SparseArray<Player> &players);

void turrets_mobs_bullets_players_collisions_system(Registry &r, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<Damage> &damages, SparseArray<Health> &healths, SparseArray<TurretMobBullet> &bullets, SparseArray<Player> &players);

void spawn_turrets_mobs_system(Registry &r);

void turrets_mobs_render_system(Registry &r, SparseArray<TurretMob> &turrets, SparseArray<Position> &positions, SparseArray<Drawable> &drawables);

void turrets_mobs_bullets_render_system(Registry &r, SparseArray<TurretMobBullet> &bullets, SparseArray<Position> &positions, SparseArray<Drawable> &drawables);

void turrets_mobs_bullets_mouvement_system(Registry &r, SparseArray<TurretMobBullet> &bullets, SparseArray<Position> &positions, SparseArray<Velocity> &velocities);

void spawn_boss_mob_system(Registry &r);

void boss_mob_render_system(Registry &r, SparseArray<BossMob> &bosses, SparseArray<Position> &positions, SparseArray<Drawable> &drawables);

void boss_mob_ai_system(Registry &r, SparseArray<BossMob> &bosses, SparseArray<Position> &positions, SparseArray<ShootCooldown> &shoot_cooldowns);

void death_boss_mob_system(Registry &r, SparseArray<BossMob> &bosses, SparseArray<Health> &healths, SparseArray<Position> &positions);

void players_bullets_boss_mob_collisions_system(Registry &r, SparseArray<PlayerBullet> &bullets, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<BossMob> &bosses, SparseArray<Health> &healths, SparseArray<Damage> &damages);

void players_lasers_boss_mob_collisions_system(Registry &r, SparseArray<PlayerLaser> &lasers, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<BossMob> &bosses, SparseArray<Health> &healths, SparseArray<Damage> &damages);

void boss_mob_bullets_mouvement_system(Registry &r, SparseArray<BossMobBullet> &bullets, SparseArray<Position> &positions, SparseArray<Velocity> &velocities, SparseArray<Player> &players);

void boss_mobs_bullets_render_system(Registry &r, SparseArray<BossMobBullet> &bullets, SparseArray<Position> &positions, SparseArray<Drawable> &drawables);

void death_boss_mob_bullets_system(Registry &r, SparseArray<BossMobBullet> &bullets, SparseArray<Health> &healths, SparseArray<Position> &positions);

void player_lasers_boss_mobs_bullets_collision_system(Registry &r, SparseArray<PlayerLaser> &player_lasers, SparseArray<Position> &player_positions, SparseArray<HitBox> &player_hitboxes, SparseArray<Damage> &player_damages, SparseArray<BossMobBullet> &boss_mob_bullets, SparseArray<Position> &boss_mob_positions, SparseArray<HitBox> &boss_mob_hitboxes, SparseArray<Health> &boss_mob_healths, SparseArray<Player> &players);

void players_bullets_boss_mob_bullets_collisions_system(Registry &r, SparseArray<PlayerBullet> &player_bullets, SparseArray<Position> &player_positions, SparseArray<HitBox> &player_hitboxes, SparseArray<Damage> &player_damages, SparseArray<BossMobBullet> &boss_mob_bullets, SparseArray<Position> &boss_mob_positions, SparseArray<HitBox> &boss_mob_hitboxes, SparseArray<Health> &boss_mob_healths, SparseArray<Player> &players);

void players_healths_render_system(Registry &r, SparseArray<Player> &players, SparseArray<Health> &healths, SparseArray<Position> &positions);;

void boss_mobs_bullets_players_collision_system(Registry &r, SparseArray<BossMobBullet> &bullets, SparseArray<Position> &positions, SparseArray<HitBox> &hitboxs, SparseArray<Player> &players, SparseArray<Health> &healths, SparseArray<Damage> &damages);

void spawn_mobs_level_1_system(Registry &reg);

void level_1_end_detection_system(Registry &r, SparseArray<Mob> &mobs);

void spawn_turrets_mobs_level_2_system(Registry &r);

void spawn_mobs_level_2_system(Registry &reg);

void level_2_end_detection_system(Registry &r, SparseArray<Mob> &mobs);

void spawn_mobs_level_3_system(Registry &reg);

void spawn_turrets_mobs_level_3_system(Registry &r);

void players_data_packet_system(Registry &r, SparseArray<NetworkPlayer> &players, SparseArray<Position> &positions, SparseArray<Health> &healths, SparseArray<BasicCanon> &basic_canons, SparseArray<LaserCanon> &laser_canons);

void players_bullets_data_packet_system(Registry &r, SparseArray<PlayerBullet> &bullets, SparseArray<Position> &positions);

void players_lasers_data_packet_system(Registry &r, SparseArray<PlayerLaser> &lasers, SparseArray<Position> &positions);

void mobs_data_packet_system(Registry &r, SparseArray<Mob> &mobs, SparseArray<Position> &positions, SparseArray<Health> &healths);

void mobs_bullets_data_packet_system(Registry &r, SparseArray<MobBullet> &bullets, SparseArray<Position> &positions);

void turrets_mobs_data_packet_system(Registry &r, SparseArray<TurretMob> &turrets, SparseArray<Position> &positions);

void turrets_mobs_bullets_data_package_system(Registry &r, SparseArray<TurretMobBullet> &bullets, SparseArray<Position> &positions);

void boulders_data_package_system(Registry &r, SparseArray<Boulder> &boulders, SparseArray<Position> &positions);

void collectables_data_packet_system(Registry &r,  SparseArray<HealthCollectable> &health_collectables, SparseArray<LaserCanonCollectable> &laser_canon_collectables, SparseArray<Position> &positions);

void boss_data_packages_system(Registry &r, SparseArray<BossMob> &bosses, SparseArray<Position> &positions, SparseArray<Health> &healths);

void boss_bullets_packet_system(Registry &r, SparseArray<BossMobBullet> &boss_bullets, SparseArray<Position> &positions);

#endif /* !SYSTEMS_HPP_ */
