# Documentation du Jeu Multijoueur Serveur-Client

Ce fichier décrit la structure des données utilisées dans un jeu multijoueur en réseau entre un serveur et un client. Ces structures permettent de synchroniser l'état du jeu entre les joueurs et de gérer les événements du jeu tels que les animations, les tirs, les ennemis et les objets collectables.

## Structures de Données

### `PlayerData`
Représente les données d'un joueur, utilisées pour gérer son état dans le jeu.

- **id** : Identifiant unique du joueur.
- **x, y** : Position du joueur sur la carte (en coordonnées 2D).
- **health** : Points de vie du joueur.
- **basic_canon** : Indique si le joueur utilise un canon basique.
- **laser_canon** : Indique si le joueur utilise un canon laser.

### `PlayerAnimation`
Contient les informations relatives aux animations du joueur.

- **x, y** : Position de l'animation.
- **basic_shooting** : Animation pour le tir du canon basique.
- **laser_shooting** : Animation pour le tir du laser.
- **take_damage** : Animation de prise de dégâts.
- **died** : Animation de la mort du joueur.
- **animation_frame** : Numéro du cadre d'animation actuel.
- **animation_speed** : Vitesse de l'animation.

### `PlayerBulletData`
Données relatives aux projectiles tirés par le joueur.

- **x, y** : Position du projectile.

### `PlayerLaserData`
Données relatives au laser du joueur.

- **x, y** : Position du laser.
- **direction** : Direction du laser en radians.
- **damage** : Dégâts infligés par le laser.

### `MobData`
Représente les données d'un ennemi (mob).

- **x, y** : Position de l'ennemi.
- **health** : Points de vie de l'ennemi.

### `MobAnimation`
Contient les informations relatives aux animations d'un ennemi.

- **x, y** : Position de l'animation.
- **shooting** : Animation de tir de l'ennemi.
- **take_damage** : Animation de prise de dégâts par l'ennemi.
- **died** : Animation de la mort de l'ennemi.
- **animation_frame** : Numéro du cadre d'animation actuel.
- **animation_speed** : Vitesse de l'animation.

### `MobBulletData`
Données relatives aux projectiles tirés par un ennemi.

- **x, y** : Position du projectile.

### `TurretData`
Données relatives aux tourelles sur le terrain.

- **x, y** : Position de la tourelle.

### `TurretAnimation`
Contient les informations relatives aux animations des tourelles.

- **x, y** : Position de l'animation.
- **shooting** : Animation de tir de la tourelle.
- **animation_frame** : Numéro du cadre d'animation actuel.
- **animation_speed** : Vitesse de l'animation.

### `TurretBulletData`
Données relatives aux projectiles tirés par les tourelles.

- **x, y** : Position du projectile.

### `BoulderData`
Représente les données d'un rocher sur le terrain.

- **x, y** : Position du rocher.

### `HealthCollectableData`
Représente les données d'un objet collectable de santé.

- **x, y** : Position de l'objet collectable.

### `LaserCollectableData`
Représente les données d'un objet collectable de laser.

- **x, y** : Position de l'objet collectable.

### `BossData`
Données relatives aux boss du jeu.

- **x, y** : Position du boss.
- **health** : Points de vie du boss.

### `BossAnimation`
Contient les informations relatives aux animations du boss.

- **x, y** : Position de l'animation.
- **shooting** : Animation de tir du boss.
- **take_damage** : Animation de prise de dégâts par le boss.
- **died** : Animation de la mort du boss.
- **animation_frame** : Numéro du cadre d'animation actuel.
- **animation_speed** : Vitesse de l'animation.

### `BossBulletData`
Données relatives aux projectiles tirés par le boss.

- **x, y** : Position du projectile.

### `BossBulletAnimation`
Contient les informations relatives aux animations des projectiles du boss.

- **x, y** : Position de l'animation du projectile.
- **take_damage** : Animation du projectile qui prend des dégâts.
- **died** : Animation de la mort du projectile.
- **animation_frame** : Numéro du cadre d'animation actuel.
- **animation_speed** : Vitesse de l'animation.

### `packet`
Structure contenant toutes les données nécessaires pour une communication complète entre le serveur et le client dans le jeu.

- **message_id** : Identifiant du message.
- **level** : Niveau du jeu.
- **player_count** : Nombre de joueurs actifs.
- **players** : Liste des joueurs et de leurs données.
- **player_animation_count** : Nombre d'animations de joueurs à transmettre.
- **players_animations** : Liste des animations des joueurs.
- **player_bullet_count** : Nombre de projectiles tirés par les joueurs.
- **player_bullets** : Liste des projectiles des joueurs.
- **player_laser_count** : Nombre de lasers tirés par les joueurs.
- **player_lasers** : Liste des lasers des joueurs.
- **enemy_count** : Nombre d'ennemis (mobs) dans le jeu.
- **enemies** : Liste des ennemis et de leurs données.
- **enemy_animation_count** : Nombre d'animations d'ennemis.
- **enemies_animations** : Liste des animations des ennemis.
- **enemy_bullet_count** : Nombre de projectiles tirés par les ennemis.
- **enemy_bullets** : Liste des projectiles des ennemis.
- **turret_count** : Nombre de tourelles sur le terrain.
- **turrets** : Liste des tourelles et de leurs positions.
- **turret_animation_count** : Nombre d'animations de tourelles.
- **turrets_animations** : Liste des animations des tourelles.
- **turret_bullet_count** : Nombre de projectiles tirés par les tourelles.
- **turret_bullets** : Liste des projectiles des tourelles.
- **boulder_count** : Nombre de rochers sur le terrain.
- **boulders** : Liste des rochers et de leurs positions.
- **health_collectable_count** : Nombre d'objets de santé collectables.
- **health_collectables** : Liste des objets collectables de santé.
- **laser_collectable_count** : Nombre d'objets de laser collectables.
- **laser_collectables** : Liste des objets collectables de laser.
- **boss_count** : Nombre de boss dans le jeu.
- **bosses** : Liste des boss et de leurs données.
- **boss_animation_count** : Nombre d'animations de boss.
- **bosses_animations** : Liste des animations des boss.
- **boss_bullet_count** : Nombre de projectiles tirés par les boss.
- **boss_bullets** : Liste des projectiles des boss.
- **boss_bullet_animation_count** : Nombre d'animations des projectiles de boss.
- **boss_bullets_animations** : Liste des animations des projectiles des boss.

## Enumération `Input`
Cette énumération représente les différentes actions que le joueur peut effectuer.

- **LEFT** : Déplacement vers la gauche.
- **RIGHT** : Déplacement vers la droite.
- **UP** : Déplacement vers le haut.
- **DOWN** : Déplacement vers le bas.
- **SHOOT** : Action de tirer.

## Conclusion
Cette structure de données permet de maintenir une communication efficace entre le serveur et le client dans le jeu multijoueur. Chaque élément de l'environnement, y compris les joueurs, ennemis, tourelles, collectables et boss, possède des données et des animations qui sont envoyées et reçues à travers des paquets pour garantir une synchronisation en temps réel du jeu.
