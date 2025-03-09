/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** Server
*/

#include "Server.hpp"

Server::Server(bool windows) : _windows(windows) {}

Server::~Server()
{
    this->_running = false;
    for (auto &thread : this->_threads) {
        if (thread.second.joinable()) {
            thread.second.join();
        }
    }
}

void Server::createLobby(unsigned short port)
{
    this->_threads[port] = std::thread(&Server::startGame, this, port, this->_windows);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Lobby created on port " << port << std::endl;
}

std::vector<unsigned short> Server::getLobbiesPorts() const
{
    std::vector<unsigned short> ports;
    for (auto &thread : this->_threads) {
        ports.push_back(thread.first);
    }
    return ports;
}

bool Server::isRunning() const
{
    return this->_running;
}

void Server::startGame(unsigned short port, bool window_flag)
{
    Registry reg;
    const float FRAME_DURATION = 1.0f / 20.0f;

    reg.register_class<NetworkServer>(port);

    reg.get_class_instance<NetworkServer>().start();

    while (this->_running) {
        if (reg.get_class_instance<NetworkServer>().getNumberOfClients() == 2) {
            break;
        }
    }

    reg.register_class<GameState>();
    reg.register_class<PacketRepresentation>();
    if (window_flag) {
        reg.register_class<sf::RenderWindow>(sf::VideoMode(1920, 1080), "R-Type");
    }

    //register components
    reg.register_component<Position>();
    reg.register_component<Velocity>();
    reg.register_component<HitBox>();
    reg.register_component<Damage>();
    reg.register_component<Health>();
    reg.register_component<Mob>();
    reg.register_component<PlayerBullet>();
    reg.register_component<MobBullet>();
    reg.register_component<Player>();
    reg.register_component<Controllable>();
    reg.register_component<Drawable>();
    reg.register_component<ShootCooldown>();
    reg.register_component<LocalPlayer>();
    reg.register_component<NetworkPlayer>();
    reg.register_component<Boulder>();
    reg.register_component<BasicCanon>();
    reg.register_component<LaserCanon>();
    reg.register_component<PlayerLaser>();
    reg.register_component<LaserCanonCollectable>();
    reg.register_component<HealthCollectable>();
    reg.register_component<TurretMob>();
    reg.register_component<TurretMobBullet>();
    reg.register_component<BossMob>();
    reg.register_component<BossMobBullet>();


    // spawn the player
    // auto player = reg.spawn_entity();
    // reg.add_component(player, Player());
    // reg.add_component(player, LocalPlayer());
    // reg.add_component(player, Position(500, 500));
    // reg.add_component(player, Velocity(20, 20));
    // reg.add_component(player, Controllable());
    // reg.add_component(player, Health(100));
    // reg.add_component(player, HitBox(50));
    // reg.add_component(player, ShootCooldown(0.2));
    // reg.add_component(player, BasicCanon());
    // reg.add_component(player, Drawable("src/server/assets/player.png"));

    reg.add_system<Boulder, Position, Velocity>(boulders_mouvement_system);
    reg.add_system<Player, BasicCanon, Position, Controllable, ShootCooldown>(players_basic_canon_shooting_system);
    reg.add_system<Position, HitBox, Damage, Health, Mob, PlayerBullet>(players_bullets_mobs_collisions_system);
    reg.add_system<Mob, Health, Position>(deaths_mobs_system);
    reg.add_system<Position, HitBox, Damage, Health, MobBullet, Player>(mobs_bullets_players_collision_system);
    reg.add_system<Player, Position, Velocity, Controllable>(players_mouvement_system);
    reg.add_system<Position, Velocity, MobBullet>(mobs_bullets_mouvement_system);
    reg.add_system<Position, Velocity, Mob, ShootCooldown>(mobs_ai_system);
    reg.add_system<Position, Velocity, PlayerBullet>(players_bullets_mouvement_system);
    reg.add_system<Player, Health, Position>(deaths_players_system);
    reg.add_system<Position, HitBox, Boulder, Player, Health, Damage>(boulders_players_collisions_system);
    reg.add_system<LocalPlayer, Controllable>(local_player_input_system);
    reg.add_system<Player, LaserCanon, Position, Controllable, ShootCooldown>(players_laser_canon_shooting_system);
    reg.add_system<PlayerLaser, Position, Velocity>(players_lasers_mouvement_system);
    reg.add_system<PlayerLaser, Position, HitBox, Mob, Health, Damage>(players_lasers_mobs_collisions_system);
    reg.add_system<LaserCanonCollectable, Position, HitBox, Player>(laser_canons_collectables_players_collisions_system);
    reg.add_system<HealthCollectable, Position, HitBox, Health, Player>(health_collectables_players_collisions_system);
    reg.add_system<TurretMob, Position, ShootCooldown, Player>(turrets_mobs_ai_system);
    reg.add_system<Position, HitBox, Damage, Health, TurretMobBullet, Player>(turrets_mobs_bullets_players_collisions_system);
    reg.add_system<TurretMobBullet, Position, Velocity>(turrets_mobs_bullets_mouvement_system);
    reg.add_system<BossMob, Position, ShootCooldown>(boss_mob_ai_system);
    reg.add_system<PlayerBullet, Position, HitBox, BossMob, Health, Damage>(players_bullets_boss_mob_collisions_system);
    reg.add_system<PlayerLaser, Position, HitBox, BossMob, Health, Damage>(players_lasers_boss_mob_collisions_system);
    reg.add_system<BossMob, Health, Position>(death_boss_mob_system);
    reg.add_system<BossMobBullet, Position, Velocity, Player>(boss_mob_bullets_mouvement_system);
    reg.add_system<BossMobBullet, Health, Position>(death_boss_mob_bullets_system);
    reg.add_system<PlayerLaser, Position, HitBox, Damage, BossMobBullet, Position, HitBox, Health, Player>(player_lasers_boss_mobs_bullets_collision_system);
    reg.add_system<PlayerBullet, Position, HitBox, Damage, BossMobBullet, Position, HitBox, Health, Player>(players_bullets_boss_mob_bullets_collisions_system);
    reg.add_system<BossMobBullet, Position, HitBox, Player, Health, Damage>(boss_mobs_bullets_players_collision_system);
    reg.add_system<Mob>(level_1_end_detection_system);
    reg.add_system<Player>(lose_detection_system);
    reg.add_system<NetworkPlayer, Position, Health, BasicCanon, LaserCanon>(players_data_packet_system);
    reg.add_system<PlayerBullet, Position>(players_bullets_data_packet_system);
    reg.add_system<PlayerLaser, Position>(players_lasers_data_packet_system);
    reg.add_system<Mob, Position, Health>(mobs_data_packet_system);
    reg.add_system<MobBullet, Position>(mobs_bullets_data_packet_system);
    reg.add_system<TurretMob, Position>(turrets_mobs_data_packet_system);
    reg.add_system<TurretMobBullet, Position>(turrets_mobs_bullets_data_package_system);
    reg.add_system<Boulder, Position>(boulders_data_package_system);
    reg.add_system<HealthCollectable, LaserCanonCollectable, Position>(collectables_data_packet_system);
    reg.add_system<BossMob, Position, Health>(boss_data_packages_system);
    reg.add_system<BossMobBullet, Position>(boss_bullets_packet_system);
    reg.add_system<NetworkPlayer, Controllable>(network_players_inputs_system);

    // LEVEL 1 //
    spawn_players_system(reg);
    spawn_mobs_level_1_system(reg);

    if (window_flag) {
        reg.add_system(clear_render_system);
        reg.add_system<Boulder, Position, Drawable>(boulders_render_system);
        reg.add_system<LaserCanonCollectable, Position, Drawable>(laser_canons_collectables_render_system);
        reg.add_system<HealthCollectable, Position, Drawable>(health_collectables_render_system);
        reg.add_system<Player, Position, Drawable>(players_render_system);
        reg.add_system<Player, Health, Position>(players_healths_render_system);
        reg.add_system<Player, Health, Position>(players_healths_render_system);
        reg.add_system<Mob, Position, Drawable>(mobs_render_system);
        reg.add_system<BossMob, Position, Drawable>(boss_mob_render_system);
        reg.add_system<TurretMob, Position, Drawable>(turrets_mobs_render_system);
        reg.add_system<PlayerBullet, Position, Drawable>(players_bullets_render_system);
        reg.add_system<PlayerLaser, Position, Drawable>(players_lasers_render_system);
        reg.add_system<MobBullet, Position, Drawable>(mobs_bullets_render_system);
        reg.add_system<TurretMobBullet, Position, Drawable>(turrets_mobs_bullets_render_system);
        reg.add_system<BossMobBullet, Position, Drawable>(boss_mobs_bullets_render_system);
        reg.add_system(display_render_system);
    }
    std::size_t next_level = 2;
    bool closed = false;
    while (true) {
        sf::Clock clock;
        sf::Event event;
        if (window_flag) {
            while (reg.get_class_instance<sf::RenderWindow>().pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    closed = true;
                }
            }
            if (closed) {
                break;
            }
        }
        if (this->_running == false) {
            break;
        }
        if (reg.get_class_instance<GameState>().getWin() || reg.get_class_instance<GameState>().getLose()) {
            break;
        }
        reg.run_systems();
        network_packet_system(reg);
        if ((next_level == 2) && (reg.get_class_instance<GameState>().getLevel() == next_level)) {
            std::cout << "Level 2" << std::endl;
            spawn_mobs_level_2_system(reg);
            spawn_turrets_mobs_level_2_system(reg);
            reg.add_system(spawn_laser_canons_collectables_system);
            reg.add_system<Mob>(level_2_end_detection_system);
            next_level = 3;
        }
        if ((next_level == 3) && (reg.get_class_instance<GameState>().getLevel() == next_level)) {
            std::cout << "Level 3" << std::endl;
            spawn_boss_mob_system(reg);
            spawn_mobs_level_3_system(reg);
            spawn_turrets_mobs_level_3_system(reg);
            reg.add_system(spawn_health_collectables_system);
            reg.add_system(spawn_health_collectables_system);
            reg.add_system(spawn_boulders_system);
            reg.add_system<BossMob>(win_detection_system);
            next_level = 4;
        }
        sf::Time elapsed = clock.getElapsedTime();
        sf::Time frameTime = sf::seconds(FRAME_DURATION);
        if (elapsed < frameTime) {
            sf::sleep(frameTime - elapsed);
        }
    }
    if (window_flag) {
        reg.get_class_instance<sf::RenderWindow>().close();
    }
    if (reg.get_class_instance<GameState>().getWin()) {
        std::cout << "You win" << std::endl;
    }
    if (reg.get_class_instance<GameState>().getLose()) {
        std::cout << "You lose" << std::endl;
    }
}
