/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, Nov, 2024                                                     *
 * Title           - R-type                                                             *
 * Description     -                                                                    *
 *     Protocol                                                                         *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** ProtocolServer - A class for serializing and deserializing game packets.
*/

// ProtocolServer.hpp
#ifndef INCLUDED_PROTOCOL_HPP
#define INCLUDED_PROTOCOL_HPP
#define MAGIC_NUMBER 0xABCD1234

#include <iostream>
#include <cstdint>
#include <vector>
#include <cstring>

namespace server_protocol {
    struct PlayerData {
        int id;
        int x;
        int y;
        int health;
        bool basic_canon = false;
        bool laser_canon = false;
    };

    struct PlayerAnimation {
        int x;
        int y;
        bool basic_shooting = false;
        bool laser_shooting = false;
        bool take_damage = false;
        bool died = false;
        int animation_frame = 0;
        float animation_speed = 1.0f;
    };

    struct PlayerBulletData {
        int x;
        int y;
    };

    struct PlayerLaserData {
        int x;
        int y;
        float direction = 0.0f;
        int damage = 10;
    };

    struct MobData {
        int x;
        int y;
        int health;
    };

    struct MobAnimation {
        int x;
        int y;
        bool shooting = false;
        bool take_damage = false;
        bool died = false;
        int animation_frame = 0;
        float animation_speed = 1.0f;
    };

    struct MobBulletData {
        int x;
        int y;
    };

    struct TurretData {
        int x;
        int y;
    };

    struct TurretAnimation {
        int x;
        int y;
        bool shooting = false;
        int animation_frame = 0;
        float animation_speed = 1.0f;
    };

    struct TurretBulletData {
        int x;
        int y;
    };

    struct BoulderData {
        int x;
        int y;
    };

    struct HealthCollectableData {
        int x;
        int y;
    };

    struct LaserCollectableData {
        int x;
        int y;
    };

    struct BossData {
        int x;
        int y;
        int health;
    };

    struct BossAnimation {
        int x;
        int y;
        bool shooting = false;
        bool take_damage = false;
        bool died = false;
        int animation_frame = 0;
        float animation_speed = 1.0f;
    };

    struct BossBulletData {
        int x;
        int y;
    };

    struct BossBulletAnimation {
        int x;
        int y;
        bool take_damage = false;
        bool died = false;
        int animation_frame = 0;
        float animation_speed = 1.0f;
    };

    struct packet {
        uint16_t message_id;
        uint8_t level;

        uint8_t player_count;
        std::vector<PlayerData> players;

        uint8_t player_animation_count;
        std::vector<PlayerAnimation> players_animations;

        uint8_t player_bullet_count;
        std::vector<PlayerBulletData> player_bullets;

        uint8_t player_laser_count;
        std::vector<PlayerLaserData> player_lasers;

        uint8_t enemy_count;
        std::vector<MobData> enemies;

        uint8_t enemy_animation_count;
        std::vector<MobAnimation> enemies_animations;

        uint8_t enemy_bullet_count;
        std::vector<MobBulletData> enemy_bullets;

        uint8_t turret_count;
        std::vector<TurretData> turrets;

        uint8_t turret_animation_count;
        std::vector<TurretAnimation> turrets_animations;

        uint8_t turret_bullet_count;
        std::vector<TurretBulletData> turret_bullets;

        uint8_t boulder_count;
        std::vector<BoulderData> boulders;

        uint8_t health_collectable_count;
        std::vector<HealthCollectableData> health_collectables;

        uint8_t laser_collectable_count;
        std::vector<LaserCollectableData> laser_collectables;

        uint8_t boss_count;
        std::vector<BossData> bosses;

        uint8_t boss_animation_count;
        std::vector<BossAnimation> bosses_animations;

        uint8_t boss_bullet_count;
        std::vector<BossBulletData> boss_bullets;

        uint8_t boss_bullet_animation_count;
        std::vector<BossBulletAnimation> boss_bullets_animations;
    };

    enum Input {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        SHOOT
    };
}

class ProtocolServer {
public:
    static std::vector<uint8_t> serializePacket(const server_protocol::packet& pkt);
    static server_protocol::Input deserializePacket(const std::vector<uint8_t>& buffer);

private:
    static void serializePlayerData(const server_protocol::PlayerData& player, std::vector<uint8_t>& buffer);
    static void serializePlayerAnimation(const server_protocol::PlayerAnimation& anim, std::vector<uint8_t>& buffer);
    static void serializePlayerBulletData(const server_protocol::PlayerBulletData& bullet, std::vector<uint8_t>& buffer);
    static void serializePlayerLaserData(const server_protocol::PlayerLaserData& laser, std::vector<uint8_t>& buffer);
    static void serializeMobData(const server_protocol::MobData& mob, std::vector<uint8_t>& buffer);
    static void serializeMobAnimation(const server_protocol::MobAnimation& anim, std::vector<uint8_t>& buffer);
    static void serializeMobBulletData(const server_protocol::MobBulletData& bullet, std::vector<uint8_t>& buffer);
    static void serializeTurretData(const server_protocol::TurretData& turret, std::vector<uint8_t>& buffer);
    static void serializeTurretAnimation(const server_protocol::TurretAnimation& anim, std::vector<uint8_t>& buffer);
    static void serializeTurretBulletData(const server_protocol::TurretBulletData& bullet, std::vector<uint8_t>& buffer);
    static void serializeBoulderData(const server_protocol::BoulderData& boulder, std::vector<uint8_t>& buffer);
    static void serializeHealthCollectableData(const server_protocol::HealthCollectableData& collectable, std::vector<uint8_t>& buffer);
    static void serializeLaserCollectableData(const server_protocol::LaserCollectableData& collectable, std::vector<uint8_t>& buffer);
    static void serializeBossData(const server_protocol::BossData& boss, std::vector<uint8_t>& buffer);
    static void serializeBossAnimation(const server_protocol::BossAnimation& anim, std::vector<uint8_t>& buffer);
    static void serializeBossBulletData(const server_protocol::BossBulletData& bullet, std::vector<uint8_t>& buffer);
    static void serializeBossBulletAnimation(const server_protocol::BossBulletAnimation& anim, std::vector<uint8_t>& buffer);
};

#endif