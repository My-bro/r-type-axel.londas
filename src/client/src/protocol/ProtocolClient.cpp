#include "ProtocolClient.hpp"
#include <cstring>

packet ProtocolClient::deserializePacket(const std::vector<uint8_t>& buffer) {
    packet pkt;
    size_t offset = 0;

    pkt.message_id = (buffer[offset] << 8) | buffer[offset + 1];
    offset += 2;
    pkt.level = buffer[offset++];

    pkt.player_count = buffer[offset++];
    pkt.players.resize(pkt.player_count);
    for (auto& player : pkt.players) {
        offset = deserializePlayerData(buffer, offset, player);
    }

    pkt.player_animation_count = buffer[offset++];
    pkt.players_animations.resize(pkt.player_animation_count);
    for (auto& anim : pkt.players_animations) {
        offset = deserializePlayerAnimation(buffer, offset, anim);
    }

    pkt.player_bullet_count = buffer[offset++];
    pkt.player_bullets.resize(pkt.player_bullet_count);
    for (auto& bullet : pkt.player_bullets) {
        offset = deserializePlayerBulletData(buffer, offset, bullet);
    }

    pkt.player_laser_count = buffer[offset++];
    pkt.player_lasers.resize(pkt.player_laser_count);
    for (auto& laser : pkt.player_lasers) {
        offset = deserializePlayerLaserData(buffer, offset, laser);
    }

    pkt.enemy_count = buffer[offset++];
    pkt.enemies.resize(pkt.enemy_count);
    for (auto& enemy : pkt.enemies) {
        offset = deserializeMobData(buffer, offset, enemy);
    }

    pkt.enemy_animation_count = buffer[offset++];
    pkt.enemies_animations.resize(pkt.enemy_animation_count);
    for (auto& anim : pkt.enemies_animations) {
        offset = deserializeMobAnimation(buffer, offset, anim);
    }

    pkt.enemy_bullet_count = buffer[offset++];
    pkt.enemy_bullets.resize(pkt.enemy_bullet_count);
    for (auto& bullet : pkt.enemy_bullets) {
        offset = deserializeMobBulletData(buffer, offset, bullet);
    }

    pkt.turret_count = buffer[offset++];
    pkt.turrets.resize(pkt.turret_count);
    for (auto& turret : pkt.turrets) {
        offset = deserializeTurretData(buffer, offset, turret);
    }

    pkt.turret_animation_count = buffer[offset++];
    pkt.turrets_animations.resize(pkt.turret_animation_count);
    for (auto& anim : pkt.turrets_animations) {
        offset = deserializeTurretAnimation(buffer, offset, anim);
    }

    pkt.turret_bullet_count = buffer[offset++];
    pkt.turret_bullets.resize(pkt.turret_bullet_count);
    for (auto& bullet : pkt.turret_bullets) {
        offset = deserializeTurretBulletData(buffer, offset, bullet);
    }

    pkt.boulder_count = buffer[offset++];
    pkt.boulders.resize(pkt.boulder_count);
    for (auto& boulder : pkt.boulders) {
        offset = deserializeBoulderData(buffer, offset, boulder);
    }

    pkt.health_collectable_count = buffer[offset++];
    pkt.health_collectables.resize(pkt.health_collectable_count);
    for (auto& collectable : pkt.health_collectables) {
        offset = deserializeHealthCollectableData(buffer, offset, collectable);
    }

    pkt.laser_collectable_count = buffer[offset++];
    pkt.laser_collectables.resize(pkt.laser_collectable_count);
    for (auto& collectable : pkt.laser_collectables) {
        offset = deserializeLaserCollectableData(buffer, offset, collectable);
    }

    pkt.boss_count = buffer[offset++];
    pkt.bosses.resize(pkt.boss_count);
    for (auto& boss : pkt.bosses) {
        offset = deserializeBossData(buffer, offset, boss);
    }

    pkt.boss_animation_count = buffer[offset++];
    pkt.bosses_animations.resize(pkt.boss_animation_count);
    for (auto& anim : pkt.bosses_animations) {
        offset = deserializeBossAnimation(buffer, offset, anim);
    }

    pkt.boss_bullet_count = buffer[offset++];
    pkt.boss_bullets.resize(pkt.boss_bullet_count);
    for (auto& bullet : pkt.boss_bullets) {
        offset = deserializeBossBulletData(buffer, offset, bullet);
    }

    pkt.boss_bullet_animation_count = buffer[offset++];
    pkt.boss_bullets_animations.resize(pkt.boss_bullet_animation_count);
    for (auto& anim : pkt.boss_bullets_animations) {
        offset = deserializeBossBulletAnimation(buffer, offset, anim);
    }

    return pkt;
}

std::vector<uint8_t> ProtocolClient::serializeInput(Input input) {
    std::vector<uint8_t> buffer;
    buffer.push_back(static_cast<uint8_t>(input));
    return buffer;
}

size_t ProtocolClient::deserializePlayerData(const std::vector<uint8_t>& buffer, size_t offset, PlayerData& player) {
    player.id = (buffer[offset] << 8) | buffer[offset + 1];
    offset += 2;
    
    player.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
               (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    player.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
               (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    player.health = (buffer[offset] << 8) | buffer[offset + 1];
    offset += 2;
    
    player.basic_canon = buffer[offset++] != 0;
    player.laser_canon = buffer[offset++] != 0;
    return offset;
}

size_t ProtocolClient::deserializePlayerAnimation(const std::vector<uint8_t>& buffer, size_t offset, PlayerAnimation& anim) {
    anim.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
             (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    anim.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
             (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    anim.basic_shooting = buffer[offset++] != 0;
    anim.laser_shooting = buffer[offset++] != 0;
    anim.take_damage = buffer[offset++] != 0;
    anim.died = buffer[offset++] != 0;
    anim.animation_frame = buffer[offset++];
    
    uint32_t speed_bits = (buffer[offset] << 24) | (buffer[offset + 1] << 16) |
                         (buffer[offset + 2] << 8) | buffer[offset + 3];
    std::memcpy(&anim.animation_speed, &speed_bits, sizeof(float));
    offset += 4;
    
    return offset;
}

size_t ProtocolClient::deserializePlayerBulletData(const std::vector<uint8_t>& buffer, size_t offset, PlayerBulletData& bullet) {
    bullet.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
               (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    bullet.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
               (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    return offset;
}

size_t ProtocolClient::deserializePlayerLaserData(const std::vector<uint8_t>& buffer, size_t offset, PlayerLaserData& laser) {
    laser.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
              (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    laser.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
              (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;

    uint32_t dir_bits = (buffer[offset] << 24) | (buffer[offset + 1] << 16) |
                       (buffer[offset + 2] << 8) | buffer[offset + 3];
    std::memcpy(&laser.direction, &dir_bits, sizeof(float));
    offset += 4;

    laser.damage = (buffer[offset] << 8) | buffer[offset + 1];
    offset += 2;
    
    return offset;
}

size_t ProtocolClient::deserializeMobData(const std::vector<uint8_t>& buffer, size_t offset, MobData& mob) {
    mob.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
            (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    mob.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
            (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    mob.health = (buffer[offset] << 8) | buffer[offset + 1];
    offset += 2;
    
    return offset;
}

size_t ProtocolClient::deserializeMobAnimation(const std::vector<uint8_t>& buffer, size_t offset, MobAnimation& anim) {
    // X coordinate (32-bit)
    anim.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
             (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    // Y coordinate (32-bit)
    anim.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
             (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    anim.shooting = buffer[offset++] != 0;
    anim.take_damage = buffer[offset++] != 0;
    anim.died = buffer[offset++] != 0;
    anim.animation_frame = buffer[offset++];
    
    uint32_t speed_bits = (buffer[offset] << 24) | (buffer[offset + 1] << 16) |
                         (buffer[offset + 2] << 8) | buffer[offset + 3];
    std::memcpy(&anim.animation_speed, &speed_bits, sizeof(float));
    offset += 4;
    
    return offset;
}

size_t ProtocolClient::deserializeMobBulletData(const std::vector<uint8_t>& buffer, size_t offset, MobBulletData& bullet) {
    bullet.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
               (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    bullet.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
               (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    return offset;
}

size_t ProtocolClient::deserializeTurretData(const std::vector<uint8_t>& buffer, size_t offset, TurretData& turret) {
    turret.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
               (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    turret.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
               (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    return offset;
}

size_t ProtocolClient::deserializeTurretAnimation(const std::vector<uint8_t>& buffer, size_t offset, TurretAnimation& anim) {
    anim.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
             (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    anim.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
             (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    anim.shooting = buffer[offset++] != 0;
    anim.animation_frame = buffer[offset++];
    
    uint32_t speed_bits = (buffer[offset] << 24) | (buffer[offset + 1] << 16) |
                         (buffer[offset + 2] << 8) | buffer[offset + 3];
    std::memcpy(&anim.animation_speed, &speed_bits, sizeof(float));
    offset += 4;
    
    return offset;
}

size_t ProtocolClient::deserializeTurretBulletData(const std::vector<uint8_t>& buffer, size_t offset, TurretBulletData& bullet) {
    bullet.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
               (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    bullet.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
               (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    return offset;
}

size_t ProtocolClient::deserializeBoulderData(const std::vector<uint8_t>& buffer, size_t offset, BoulderData& boulder) {
    boulder.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
                (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    boulder.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
                (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    return offset;
}

size_t ProtocolClient::deserializeHealthCollectableData(const std::vector<uint8_t>& buffer, size_t offset, HealthCollectableData& collectable) {
    collectable.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
                    (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    collectable.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
                    (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    return offset;
}

size_t ProtocolClient::deserializeLaserCollectableData(const std::vector<uint8_t>& buffer, size_t offset, LaserCollectableData& collectable) {
    collectable.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
                    (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    collectable.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
                    (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    return offset;
}

size_t ProtocolClient::deserializeBossData(const std::vector<uint8_t>& buffer, size_t offset, BossData& boss) {
    boss.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
             (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    boss.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
             (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    boss.health = (buffer[offset] << 8) | buffer[offset + 1];
    offset += 2;
    
    return offset;
}

size_t ProtocolClient::deserializeBossAnimation(const std::vector<uint8_t>& buffer, size_t offset, BossAnimation& anim) {
    anim.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
             (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    anim.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
             (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    anim.shooting = buffer[offset++] != 0;
    anim.take_damage = buffer[offset++] != 0;
    anim.died = buffer[offset++] != 0;
    anim.animation_frame = buffer[offset++];
    
    uint32_t speed_bits = (buffer[offset] << 24) | (buffer[offset + 1] << 16) |
                         (buffer[offset + 2] << 8) | buffer[offset + 3];
    std::memcpy(&anim.animation_speed, &speed_bits, sizeof(float));
    offset += 4;
    
    return offset;
}

size_t ProtocolClient::deserializeBossBulletData(const std::vector<uint8_t>& buffer, size_t offset, BossBulletData& bullet) {
    bullet.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
               (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    bullet.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
               (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    return offset;
}

size_t ProtocolClient::deserializeBossBulletAnimation(const std::vector<uint8_t>& buffer, size_t offset, BossBulletAnimation& anim) {
    anim.x = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
             (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    anim.y = (buffer[offset] << 24) | (buffer[offset + 1] << 16) | 
             (buffer[offset + 2] << 8) | buffer[offset + 3];
    offset += 4;
    
    anim.take_damage = buffer[offset++] != 0;
    anim.died = buffer[offset++] != 0;
    anim.animation_frame = buffer[offset++];
    
    uint32_t speed_bits = (buffer[offset] << 24) | (buffer[offset + 1] << 16) |
                         (buffer[offset + 2] << 8) | buffer[offset + 3];
    std::memcpy(&anim.animation_speed, &speed_bits, sizeof(float));
    offset += 4;
    
    return offset;
}
