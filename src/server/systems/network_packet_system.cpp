/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** network_packet_system
*/

#include <ecs/Registry.hpp>
#include "../network/NetworkServer.hpp"
#include "../protocol/ProtocolServer.hpp"
#include "../PacketRepresentation.hpp"

void network_packet_system(Registry& r)
{
    PacketRepresentation& pac_rep = r.get_class_instance<PacketRepresentation>();
    server_protocol::packet packet;
    
    packet.level = pac_rep.level;
    
    packet.player_count = pac_rep.players_data.size();
    packet.players.reserve(pac_rep.players_data.size());
    for (const auto& player : pac_rep.players_data) {
        server_protocol::PlayerData p;
        p.id = player.id;
        p.x = player.x;
        p.y = player.y;
        p.health = player.health;
        p.basic_canon = player.basic_canon;
        p.laser_canon = player.laser_canon;
        packet.players.push_back(p);
    }
    
    packet.player_animation_count = pac_rep.players_animations.size();
    packet.players_animations.reserve(pac_rep.players_animations.size());
    for (const auto& anim : pac_rep.players_animations) {
        server_protocol::PlayerAnimation a;
        a.x = anim.x;
        a.y = anim.y;
        a.basic_shooting = anim.basic_shooting;
        a.laser_shooting = anim.laser_shooting;
        a.take_damage = anim.take_damage;
        a.died = anim.died;
        packet.players_animations.push_back(a);
    }
    
    packet.player_bullet_count = pac_rep.players_bullets_data.size();
    packet.player_bullets.reserve(pac_rep.players_bullets_data.size());
    for (const auto& bullet : pac_rep.players_bullets_data) {
        server_protocol::PlayerBulletData b;
        b.x = bullet.x;
        b.y = bullet.y;
        packet.player_bullets.push_back(b);
    }

    packet.player_laser_count = pac_rep.players_lasers_data.size();
    packet.player_lasers.reserve(pac_rep.players_lasers_data.size());
    for (const auto& laser : pac_rep.players_lasers_data) {
        server_protocol::PlayerLaserData l;
        l.x = laser.x;
        l.y = laser.y;
        packet.player_lasers.push_back(l);
    }

    packet.enemy_count = pac_rep.mobs_data.size();
    packet.enemies.reserve(pac_rep.mobs_data.size());
    for (const auto& mob : pac_rep.mobs_data) {
        server_protocol::MobData m;
        m.x = mob.x;
        m.y = mob.y;
        m.health = mob.health;
        packet.enemies.push_back(m);
    }

    packet.enemy_animation_count = pac_rep.mobs_animations.size();
    packet.enemies_animations.reserve(pac_rep.mobs_animations.size());
    for (const auto& anim : pac_rep.mobs_animations) {
        server_protocol::MobAnimation m;
        m.x = anim.x;
        m.y = anim.y;
        m.shooting = anim.shooting;
        m.take_damage = anim.take_damage;
        m.died = anim.died;
        packet.enemies_animations.push_back(m);
    }

    packet.enemy_bullet_count = pac_rep.mobs_bullets_data.size();
    packet.enemy_bullets.reserve(pac_rep.mobs_bullets_data.size());
    for (const auto& bullet : pac_rep.mobs_bullets_data) {
        server_protocol::MobBulletData m;
        m.x = bullet.x;
        m.y = bullet.y;
        packet.enemy_bullets.push_back(m);
    }

    packet.turret_count = pac_rep.turrets_data.size();
    packet.turrets.reserve(pac_rep.turrets_data.size());
    for (const auto& turret : pac_rep.turrets_data) {
        server_protocol::TurretData t;
        t.x = turret.x;
        t.y = turret.y;
        packet.turrets.push_back(t);
    }

    packet.turret_animation_count = pac_rep.turrets_animations.size();
    packet.turrets_animations.reserve(pac_rep.turrets_animations.size());
    for (const auto& anim : pac_rep.turrets_animations) {
        server_protocol::TurretAnimation t;
        t.x = anim.x;
        t.y = anim.y;
        t.shooting = anim.shooting;
        packet.turrets_animations.push_back(t);
    }

    packet.turret_bullet_count = pac_rep.turrets_bullets_data.size();
    packet.turret_bullets.reserve(pac_rep.turrets_bullets_data.size());
    for (const auto& bullet : pac_rep.turrets_bullets_data) {
        server_protocol::TurretBulletData t;
        t.x = bullet.x;
        t.y = bullet.y;
        packet.turret_bullets.push_back(t);
    }

    packet.boulder_count = pac_rep.boulders_data.size();
    packet.boulders.reserve(pac_rep.boulders_data.size());
    for (const auto& boulder : pac_rep.boulders_data) {
        server_protocol::BoulderData b;
        b.x = boulder.x;
        b.y = boulder.y;
        packet.boulders.push_back(b);
    }

    packet.health_collectable_count = pac_rep.health_collectables_data.size();
    packet.health_collectables.reserve(pac_rep.health_collectables_data.size());
    for (const auto& collectable : pac_rep.health_collectables_data) {
        server_protocol::HealthCollectableData h;
        h.x = collectable.x;
        h.y = collectable.y;
        packet.health_collectables.push_back(h);
    }

    packet.laser_collectable_count = pac_rep.laser_collectables_data.size();
    packet.laser_collectables.reserve(pac_rep.laser_collectables_data.size());
    for (const auto& collectable : pac_rep.laser_collectables_data) {
        server_protocol::LaserCollectableData l;
        l.x = collectable.x;
        l.y = collectable.y;
        packet.laser_collectables.push_back(l);
    }

    packet.boss_count = pac_rep.boss_data.size();
    packet.bosses.reserve(pac_rep.boss_data.size());
    for (const auto& boss : pac_rep.boss_data) {
        server_protocol::BossData b;
        b.x = boss.x;
        b.y = boss.y;
        b.health = boss.health;
        packet.bosses.push_back(b);
    }

    packet.boss_animation_count = pac_rep.boss_animations.size();
    packet.bosses_animations.reserve(pac_rep.boss_animations.size());
    for (const auto& anim : pac_rep.boss_animations) {
        server_protocol::BossAnimation b;
        b.x = anim.x;
        b.y = anim.y;
        b.shooting = anim.shooting;
        b.take_damage = anim.take_damage;
        b.died = anim.died;
        packet.bosses_animations.push_back(b);
    }

    packet.boss_bullet_count = pac_rep.boss_bullets_data.size();
    packet.boss_bullets.reserve(pac_rep.boss_bullets_data.size());
    for (const auto& bullet : pac_rep.boss_bullets_data) {
        server_protocol::BossBulletData b;
        b.x = bullet.x;
        b.y = bullet.y;
        packet.boss_bullets.push_back(b);
    }

    packet.boss_bullet_animation_count = pac_rep.boss_bullets_animations.size();
    packet.boss_bullets_animations.reserve(pac_rep.boss_bullets_animations.size());
    for (const auto& anim : pac_rep.boss_bullets_animations) {
        server_protocol::BossBulletAnimation b;
        b.x = anim.x;
        b.y = anim.y;
        b.take_damage = anim.take_damage;
        b.died = anim.died;
        packet.boss_bullets_animations.push_back(b);
    }

    std::vector<uint8_t> serialized_data = ProtocolServer::serializePacket(packet);
    r.get_class_instance<NetworkServer>().sendMessage(serialized_data);
    pac_rep.resetPacket();
}
