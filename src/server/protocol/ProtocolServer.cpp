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
/**
 * @file Protocol.cpp
 * @brief Implementation of the Protocol class for handling message encoding and decoding.
 */

#include "ProtocolServer.hpp"

std::vector<uint8_t> ProtocolServer::serializePacket(const server_protocol::packet& pkt) {
    std::vector<uint8_t> buffer;

    buffer.push_back(static_cast<uint8_t>(pkt.message_id >> 8));
    buffer.push_back(static_cast<uint8_t>(pkt.message_id & 0xFF));
    buffer.push_back(pkt.level);

    buffer.push_back(pkt.player_count);
    for (const auto& player : pkt.players) {
        serializePlayerData(player, buffer);
    }

    buffer.push_back(pkt.player_animation_count);
    for (const auto& animation : pkt.players_animations) {
        serializePlayerAnimation(animation, buffer);
    }

    buffer.push_back(pkt.player_bullet_count);
    for (const auto& bullet : pkt.player_bullets) {
        serializePlayerBulletData(bullet, buffer);
    }

    buffer.push_back(pkt.player_laser_count);
    for (const auto& laser : pkt.player_lasers) {
        serializePlayerLaserData(laser, buffer);
    }

    buffer.push_back(pkt.enemy_count);
    for (const auto& enemy : pkt.enemies) {
        serializeMobData(enemy, buffer);
    }

    buffer.push_back(pkt.enemy_animation_count);
    for (const auto& anim : pkt.enemies_animations) {
        serializeMobAnimation(anim, buffer);
    }

    buffer.push_back(pkt.enemy_bullet_count);
    for (const auto& bullet : pkt.enemy_bullets) {
        serializeMobBulletData(bullet, buffer);
    }

    buffer.push_back(pkt.turret_count);
    for (const auto& turret : pkt.turrets) {
        serializeTurretData(turret, buffer);
    }

    buffer.push_back(pkt.turret_animation_count);
    for (const auto& anim : pkt.turrets_animations) {
        serializeTurretAnimation(anim, buffer);
    }

    buffer.push_back(pkt.turret_bullet_count);
    for (const auto& bullet : pkt.turret_bullets) {
        serializeTurretBulletData(bullet, buffer);
    }

    buffer.push_back(pkt.boulder_count);
    for (const auto& boulder : pkt.boulders) {
        serializeBoulderData(boulder, buffer);
    }

    buffer.push_back(pkt.health_collectable_count);
    for (const auto& collectable : pkt.health_collectables) {
        serializeHealthCollectableData(collectable, buffer);
    }

    buffer.push_back(pkt.laser_collectable_count);
    for (const auto& collectable : pkt.laser_collectables) {
        serializeLaserCollectableData(collectable, buffer);
    }

    buffer.push_back(pkt.boss_count);
    for (const auto& boss : pkt.bosses) {
        serializeBossData(boss, buffer);
    }

    buffer.push_back(pkt.boss_animation_count);
    for (const auto& anim : pkt.bosses_animations) {
        serializeBossAnimation(anim, buffer);
    }

    buffer.push_back(pkt.boss_bullet_count);
    for (const auto& bullet : pkt.boss_bullets) {
        serializeBossBulletData(bullet, buffer);
    }

    buffer.push_back(pkt.boss_bullet_animation_count);
    for (const auto& anim : pkt.boss_bullets_animations) {
        serializeBossBulletAnimation(anim, buffer);
    }

    return buffer;
}

server_protocol::Input ProtocolServer::deserializePacket(const std::vector<uint8_t>& buffer) {
    return static_cast<server_protocol::Input>(buffer[0]);
}

void ProtocolServer::serializePlayerData(const server_protocol::PlayerData& player, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(player.id >> 8));
    buffer.push_back(static_cast<uint8_t>(player.id & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(player.x >> 24));
    buffer.push_back(static_cast<uint8_t>(player.x >> 16));
    buffer.push_back(static_cast<uint8_t>(player.x >> 8));
    buffer.push_back(static_cast<uint8_t>(player.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(player.y >> 24));
    buffer.push_back(static_cast<uint8_t>(player.y >> 16));
    buffer.push_back(static_cast<uint8_t>(player.y >> 8));
    buffer.push_back(static_cast<uint8_t>(player.y & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(player.health >> 8));
    buffer.push_back(static_cast<uint8_t>(player.health & 0xFF));
    
    buffer.push_back(player.basic_canon ? 1 : 0);
    buffer.push_back(player.laser_canon ? 1 : 0);
}

void ProtocolServer::serializePlayerAnimation(const server_protocol::PlayerAnimation& anim, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(anim.x >> 24));
    buffer.push_back(static_cast<uint8_t>(anim.x >> 16));
    buffer.push_back(static_cast<uint8_t>(anim.x >> 8));
    buffer.push_back(static_cast<uint8_t>(anim.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(anim.y >> 24));
    buffer.push_back(static_cast<uint8_t>(anim.y >> 16));
    buffer.push_back(static_cast<uint8_t>(anim.y >> 8));
    buffer.push_back(static_cast<uint8_t>(anim.y & 0xFF));
    
    buffer.push_back(anim.basic_shooting ? 1 : 0);
    buffer.push_back(anim.laser_shooting ? 1 : 0);
    buffer.push_back(anim.take_damage ? 1 : 0);
    buffer.push_back(anim.died ? 1 : 0);
    buffer.push_back(anim.animation_frame);
    buffer.push_back(static_cast<uint8_t>(anim.animation_speed));
}

void ProtocolServer::serializePlayerBulletData(const server_protocol::PlayerBulletData& bullet, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(bullet.x >> 24));
    buffer.push_back(static_cast<uint8_t>(bullet.x >> 16));
    buffer.push_back(static_cast<uint8_t>(bullet.x >> 8));
    buffer.push_back(static_cast<uint8_t>(bullet.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(bullet.y >> 24));
    buffer.push_back(static_cast<uint8_t>(bullet.y >> 16));
    buffer.push_back(static_cast<uint8_t>(bullet.y >> 8));
    buffer.push_back(static_cast<uint8_t>(bullet.y & 0xFF));
}

void ProtocolServer::serializePlayerLaserData(const server_protocol::PlayerLaserData& laser, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(laser.x >> 24));
    buffer.push_back(static_cast<uint8_t>(laser.x >> 16));
    buffer.push_back(static_cast<uint8_t>(laser.x >> 8));
    buffer.push_back(static_cast<uint8_t>(laser.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(laser.y >> 24));
    buffer.push_back(static_cast<uint8_t>(laser.y >> 16));
    buffer.push_back(static_cast<uint8_t>(laser.y >> 8));
    buffer.push_back(static_cast<uint8_t>(laser.y & 0xFF));

    uint32_t dir_bits;
    std::memcpy(&dir_bits, &laser.direction, sizeof(float));
    buffer.push_back(static_cast<uint8_t>(dir_bits >> 24));
    buffer.push_back(static_cast<uint8_t>(dir_bits >> 16));
    buffer.push_back(static_cast<uint8_t>(dir_bits >> 8));
    buffer.push_back(static_cast<uint8_t>(dir_bits & 0xFF));

    buffer.push_back(static_cast<uint8_t>(laser.damage >> 8));
    buffer.push_back(static_cast<uint8_t>(laser.damage & 0xFF));
}

void ProtocolServer::serializeMobData(const server_protocol::MobData& mob, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(mob.x >> 24));
    buffer.push_back(static_cast<uint8_t>(mob.x >> 16));
    buffer.push_back(static_cast<uint8_t>(mob.x >> 8));
    buffer.push_back(static_cast<uint8_t>(mob.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(mob.y >> 24));
    buffer.push_back(static_cast<uint8_t>(mob.y >> 16));
    buffer.push_back(static_cast<uint8_t>(mob.y >> 8));
    buffer.push_back(static_cast<uint8_t>(mob.y & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(mob.health >> 8));
    buffer.push_back(static_cast<uint8_t>(mob.health & 0xFF));
}

void ProtocolServer::serializeMobAnimation(const server_protocol::MobAnimation& anim, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(anim.x >> 24));
    buffer.push_back(static_cast<uint8_t>(anim.x >> 16));
    buffer.push_back(static_cast<uint8_t>(anim.x >> 8));
    buffer.push_back(static_cast<uint8_t>(anim.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(anim.y >> 24));
    buffer.push_back(static_cast<uint8_t>(anim.y >> 16));
    buffer.push_back(static_cast<uint8_t>(anim.y >> 8));
    buffer.push_back(static_cast<uint8_t>(anim.y & 0xFF));
    
    buffer.push_back(anim.shooting ? 1 : 0);
    buffer.push_back(anim.take_damage ? 1 : 0);
    buffer.push_back(anim.died ? 1 : 0);
    buffer.push_back(anim.animation_frame);
    buffer.push_back(static_cast<uint8_t>(anim.animation_speed));
}

void ProtocolServer::serializeMobBulletData(const server_protocol::MobBulletData& bullet, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(bullet.x >> 24));
    buffer.push_back(static_cast<uint8_t>(bullet.x >> 16));
    buffer.push_back(static_cast<uint8_t>(bullet.x >> 8));
    buffer.push_back(static_cast<uint8_t>(bullet.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(bullet.y >> 24));
    buffer.push_back(static_cast<uint8_t>(bullet.y >> 16));
    buffer.push_back(static_cast<uint8_t>(bullet.y >> 8));
    buffer.push_back(static_cast<uint8_t>(bullet.y & 0xFF));
}

void ProtocolServer::serializeTurretData(const server_protocol::TurretData& turret, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(turret.x >> 24));
    buffer.push_back(static_cast<uint8_t>(turret.x >> 16));
    buffer.push_back(static_cast<uint8_t>(turret.x >> 8));
    buffer.push_back(static_cast<uint8_t>(turret.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(turret.y >> 24));
    buffer.push_back(static_cast<uint8_t>(turret.y >> 16));
    buffer.push_back(static_cast<uint8_t>(turret.y >> 8));
    buffer.push_back(static_cast<uint8_t>(turret.y & 0xFF));
}

void ProtocolServer::serializeTurretAnimation(const server_protocol::TurretAnimation& anim, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(anim.x >> 24));
    buffer.push_back(static_cast<uint8_t>(anim.x >> 16));
    buffer.push_back(static_cast<uint8_t>(anim.x >> 8));
    buffer.push_back(static_cast<uint8_t>(anim.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(anim.y >> 24));
    buffer.push_back(static_cast<uint8_t>(anim.y >> 16));
    buffer.push_back(static_cast<uint8_t>(anim.y >> 8));
    buffer.push_back(static_cast<uint8_t>(anim.y & 0xFF));
    
    buffer.push_back(anim.shooting ? 1 : 0);
    buffer.push_back(anim.animation_frame);
    buffer.push_back(static_cast<uint8_t>(anim.animation_speed));
}

void ProtocolServer::serializeTurretBulletData(const server_protocol::TurretBulletData& bullet, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(bullet.x >> 24));
    buffer.push_back(static_cast<uint8_t>(bullet.x >> 16));
    buffer.push_back(static_cast<uint8_t>(bullet.x >> 8));
    buffer.push_back(static_cast<uint8_t>(bullet.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(bullet.y >> 24));
    buffer.push_back(static_cast<uint8_t>(bullet.y >> 16));
    buffer.push_back(static_cast<uint8_t>(bullet.y >> 8));
    buffer.push_back(static_cast<uint8_t>(bullet.y & 0xFF));
}

void ProtocolServer::serializeBoulderData(const server_protocol::BoulderData& boulder, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(boulder.x >> 24));
    buffer.push_back(static_cast<uint8_t>(boulder.x >> 16));
    buffer.push_back(static_cast<uint8_t>(boulder.x >> 8));
    buffer.push_back(static_cast<uint8_t>(boulder.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(boulder.y >> 24));
    buffer.push_back(static_cast<uint8_t>(boulder.y >> 16));
    buffer.push_back(static_cast<uint8_t>(boulder.y >> 8));
    buffer.push_back(static_cast<uint8_t>(boulder.y & 0xFF));
}

void ProtocolServer::serializeHealthCollectableData(const server_protocol::HealthCollectableData& collectable, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(collectable.x >> 24));
    buffer.push_back(static_cast<uint8_t>(collectable.x >> 16));
    buffer.push_back(static_cast<uint8_t>(collectable.x >> 8));
    buffer.push_back(static_cast<uint8_t>(collectable.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(collectable.y >> 24));
    buffer.push_back(static_cast<uint8_t>(collectable.y >> 16));
    buffer.push_back(static_cast<uint8_t>(collectable.y >> 8));
    buffer.push_back(static_cast<uint8_t>(collectable.y & 0xFF));
}

void ProtocolServer::serializeLaserCollectableData(const server_protocol::LaserCollectableData& collectable, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(collectable.x >> 24));
    buffer.push_back(static_cast<uint8_t>(collectable.x >> 16));
    buffer.push_back(static_cast<uint8_t>(collectable.x >> 8));
    buffer.push_back(static_cast<uint8_t>(collectable.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(collectable.y >> 24));
    buffer.push_back(static_cast<uint8_t>(collectable.y >> 16));
    buffer.push_back(static_cast<uint8_t>(collectable.y >> 8));
    buffer.push_back(static_cast<uint8_t>(collectable.y & 0xFF));
}

void ProtocolServer::serializeBossData(const server_protocol::BossData& boss, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(boss.x >> 24));
    buffer.push_back(static_cast<uint8_t>(boss.x >> 16));
    buffer.push_back(static_cast<uint8_t>(boss.x >> 8));
    buffer.push_back(static_cast<uint8_t>(boss.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(boss.y >> 24));
    buffer.push_back(static_cast<uint8_t>(boss.y >> 16));
    buffer.push_back(static_cast<uint8_t>(boss.y >> 8));
    buffer.push_back(static_cast<uint8_t>(boss.y & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(boss.health >> 8));
    buffer.push_back(static_cast<uint8_t>(boss.health & 0xFF));
}

void ProtocolServer::serializeBossAnimation(const server_protocol::BossAnimation& anim, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(anim.x >> 24));
    buffer.push_back(static_cast<uint8_t>(anim.x >> 16));
    buffer.push_back(static_cast<uint8_t>(anim.x >> 8));
    buffer.push_back(static_cast<uint8_t>(anim.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(anim.y >> 24));
    buffer.push_back(static_cast<uint8_t>(anim.y >> 16));
    buffer.push_back(static_cast<uint8_t>(anim.y >> 8));
    buffer.push_back(static_cast<uint8_t>(anim.y & 0xFF));
    
    buffer.push_back(anim.shooting ? 1 : 0);
    buffer.push_back(anim.take_damage ? 1 : 0);
    buffer.push_back(anim.died ? 1 : 0);
    buffer.push_back(anim.animation_frame);
    buffer.push_back(static_cast<uint8_t>(anim.animation_speed));
}

void ProtocolServer::serializeBossBulletData(const server_protocol::BossBulletData& bullet, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(bullet.x >> 24));
    buffer.push_back(static_cast<uint8_t>(bullet.x >> 16));
    buffer.push_back(static_cast<uint8_t>(bullet.x >> 8));
    buffer.push_back(static_cast<uint8_t>(bullet.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(bullet.y >> 24));
    buffer.push_back(static_cast<uint8_t>(bullet.y >> 16));
    buffer.push_back(static_cast<uint8_t>(bullet.y >> 8));
    buffer.push_back(static_cast<uint8_t>(bullet.y & 0xFF));
}

void ProtocolServer::serializeBossBulletAnimation(const server_protocol::BossBulletAnimation& anim, std::vector<uint8_t>& buffer) {
    buffer.push_back(static_cast<uint8_t>(anim.x >> 24));
    buffer.push_back(static_cast<uint8_t>(anim.x >> 16));
    buffer.push_back(static_cast<uint8_t>(anim.x >> 8));
    buffer.push_back(static_cast<uint8_t>(anim.x & 0xFF));
    
    buffer.push_back(static_cast<uint8_t>(anim.y >> 24));
    buffer.push_back(static_cast<uint8_t>(anim.y >> 16));
    buffer.push_back(static_cast<uint8_t>(anim.y >> 8));
    buffer.push_back(static_cast<uint8_t>(anim.y & 0xFF));
    
    buffer.push_back(anim.take_damage ? 1 : 0);
    buffer.push_back(anim.died ? 1 : 0);
    buffer.push_back(anim.animation_frame);
    buffer.push_back(static_cast<uint8_t>(anim.animation_speed));
}