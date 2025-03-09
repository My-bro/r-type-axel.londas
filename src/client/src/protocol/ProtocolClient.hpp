#ifndef INCLUDED_PROTOCOL_CLIENT_HPP
#define INCLUDED_PROTOCOL_CLIENT_HPP

#include <vector>
#include <cstdint>

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

class ProtocolClient {
public:
    // Main deserialization function for game state
    static packet deserializePacket(const std::vector<uint8_t>& buffer);

    // Serialization function for player input
    static std::vector<uint8_t> serializeInput(Input input);

private:
    // Player-related deserialization
    static size_t deserializePlayerData(const std::vector<uint8_t>& buffer, size_t offset, PlayerData& player);
    static size_t deserializePlayerAnimation(const std::vector<uint8_t>& buffer, size_t offset, PlayerAnimation& anim);
    static size_t deserializePlayerBulletData(const std::vector<uint8_t>& buffer, size_t offset, PlayerBulletData& bullet);
    static size_t deserializePlayerLaserData(const std::vector<uint8_t>& buffer, size_t offset, PlayerLaserData& laser);

    // Enemy-related deserialization
    static size_t deserializeMobData(const std::vector<uint8_t>& buffer, size_t offset, MobData& mob);
    static size_t deserializeMobAnimation(const std::vector<uint8_t>& buffer, size_t offset, MobAnimation& anim);
    static size_t deserializeMobBulletData(const std::vector<uint8_t>& buffer, size_t offset, MobBulletData& bullet);

    // Turret-related deserialization
    static size_t deserializeTurretData(const std::vector<uint8_t>& buffer, size_t offset, TurretData& turret);
    static size_t deserializeTurretAnimation(const std::vector<uint8_t>& buffer, size_t offset, TurretAnimation& anim);
    static size_t deserializeTurretBulletData(const std::vector<uint8_t>& buffer, size_t offset, TurretBulletData& bullet);

    // Environment objects deserialization
    static size_t deserializeBoulderData(const std::vector<uint8_t>& buffer, size_t offset, BoulderData& boulder);

    // Collectables deserialization
    static size_t deserializeHealthCollectableData(const std::vector<uint8_t>& buffer, size_t offset, HealthCollectableData& collectable);
    static size_t deserializeLaserCollectableData(const std::vector<uint8_t>& buffer, size_t offset, LaserCollectableData& collectable);

    // Boss-related deserialization
    static size_t deserializeBossData(const std::vector<uint8_t>& buffer, size_t offset, BossData& boss);
    static size_t deserializeBossAnimation(const std::vector<uint8_t>& buffer, size_t offset, BossAnimation& anim);
    static size_t deserializeBossBulletData(const std::vector<uint8_t>& buffer, size_t offset, BossBulletData& bullet);
    static size_t deserializeBossBulletAnimation(const std::vector<uint8_t>& buffer, size_t offset, BossBulletAnimation& anim);
};

#endif // INCLUDED_PROTOCOL_CLIENT_HPP