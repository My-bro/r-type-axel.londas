/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** PacketRepresentation
*/

#ifndef PACKETREPRESENTATION_HPP_
    #define PACKETREPRESENTATION_HPP_

    #include <string>
    #include <vector>

    class PlayerData {
        public:
            PlayerData() {};
            int id = 0;
            int x = 0;
            int y = 0;
            int health;
            bool basic_canon = false;
            bool laser_canon = false;
    };

    class PlayerAnimation {
        public:
            PlayerAnimation() {};
            int x = 0;
            int y = 0;
            bool basic_shooting = false;
            bool laser_shooting = false;
            bool take_damage = false;
            bool died = false;
    };

    class PlayerBulletData {
        public:
            PlayerBulletData() {};
            int x = 0;
            int y = 0;
    };

    class PlayerLaserData {
        public:
            PlayerLaserData() {};
            int x = 0;
            int y = 0;
    };

    class MobData {
        public:
            MobData() {};
            int x = 0;
            int y = 0;
            int health = 0;
    };

    class MobAnimation {
        public:
            MobAnimation() {};
            int x = 0;
            int y = 0;
            bool shooting = false;
            bool take_damage  = false;
            bool died = false;
    };

    class MobBulletData {
        public:
            MobBulletData() {};
            int x = 0;
            int y = 0;
    };

    class TurretData {
        public:
            TurretData() {};
            int x = 0;
            int y = 0;
    };

    class TurretAnimation {
        public:
            TurretAnimation() {};
            int x = 0;
            int y = 0;
            bool shooting = false;
    };

    class TurretBulletData {
        public:
            TurretBulletData() {};
            int x = 0;
            int y = 0;
    };

    class BoulderData {
        public:
            BoulderData() {};
            int x = 0;
            int y = 0;
    };

    class HealthCollectableData {
        public:
            HealthCollectableData() {};
            int x = 0;
            int y = 0;
    };

    class LaserCollectableData {
        public:
            LaserCollectableData() {};
            int x = 0;
            int y = 0;
    };

    class BossData {
        public:
            BossData() {};
            int x = 0;
            int y = 0;
            int health = 0;
    };

    class BossAnimation {
        public:
            BossAnimation() {};
            int x = 0;
            int y = 0;
            bool shooting = false;
            bool take_damage = false;
            bool died = false;
    };

    class BossBulletData {
        public:
            BossBulletData() {};
            int x = 0;
            int y = 0;
    };

    class BossBulletAnimation {
        public:
            BossBulletAnimation() {};
            int x = 0;
            int y = 0;
            bool take_damage = false;
            bool died = false;
    };

    class PacketRepresentation {
    public:
        PacketRepresentation() {};
        void resetPacket() {
            players_data.clear();
            players_animations.clear();
            players_bullets_data.clear();
            players_lasers_data.clear();
            mobs_data.clear();
            mobs_animations.clear();
            mobs_bullets_data.clear();
            turrets_data.clear();
            turrets_animations.clear();
            turrets_bullets_data.clear();
            boulders_data.clear();
            health_collectables_data.clear();
            laser_collectables_data.clear();
            boss_data.clear();
            boss_animations.clear();
            boss_bullets_data.clear();
            boss_bullets_animations.clear();
        }
        int level = 1;
        std::vector<PlayerData> players_data;
        std::vector<PlayerAnimation> players_animations;
        std::vector<PlayerBulletData> players_bullets_data;
        std::vector<PlayerLaserData> players_lasers_data;
        std::vector<MobData> mobs_data;
        std::vector<MobAnimation> mobs_animations;
        std::vector<MobBulletData> mobs_bullets_data;
        std::vector<TurretData> turrets_data;
        std::vector<TurretAnimation> turrets_animations;
        std::vector<TurretBulletData> turrets_bullets_data;
        std::vector<BoulderData> boulders_data;
        std::vector<HealthCollectableData> health_collectables_data;
        std::vector<LaserCollectableData> laser_collectables_data;
        std::vector<BossData> boss_data;
        std::vector<BossAnimation> boss_animations;
        std::vector<BossBulletData> boss_bullets_data;
        std::vector<BossBulletAnimation> boss_bullets_animations;

    };

#endif /* !PACKETREPRESENTATION_HPP_ */
