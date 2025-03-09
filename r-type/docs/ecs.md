# 🕹️ **Entity Component System (ECS) Documentation**

This documentation provides an overview of the core functions in your ECS architecture, including how to register components, manage entities, and an example of how systems operate.

---

## 📦 **Components**

In your ECS, components are stored in the **`components`** folder. Components represent the **data** associated with entities.

### Example Components

- **Position**: Represents an entity's position in 2D space.
- **HitBox**: Defines the entity's collision boundaries.
- **Damage**: Represents the damage an entity can inflict.
- **Health**: Tracks the entity's health.
- **Mob**: Represents enemy entities.
- **PlayerBullet**: Represents bullets shot by the player.
- **HitEvent**: Tracks collision events.

---

## ⚙️ **Core ECS Functions**

### 1. **`register_component`**

Registers a component type with the **registry** so it can be managed by the ECS.

#### Signature

template <class Component>  
sparse_array<Component> &register_component();

#### Explanation

- This function registers a component type, allowing the registry to manage components of that type.
- **Returns** a reference to a `sparse_array` that will store the components.

#### Example Usage
```cpp
registry.register_component<Position>();  
registry.register_component<Health>();
```
---

### 2. **`add_component`**

Adds a component to a specific entity.

#### Signature
```cpp
template <typename Component>  
typename sparse_array<Component>::reference_type add_component(entity_t const &to, Component &&c);

#### Explanation

- Adds a component of type `Component` to the specified entity.
- **Returns** a reference to the newly added component.

#### Example Usage
```cpp
auto entity = registry.spawn_entity();  
registry.add_component<Position>(entity, Position{10, 20});  
registry.add_component<Health>(entity, Health{100});
```
---

### 3. **`spawn_entity`**

Creates a new entity and returns its identifier.

#### Signature
```cpp
entity_t spawn_entity();
```
#### Explanation

- Spawns a new entity and returns an `entity_t` representing it.

#### Example Usage
```cpp
entity_t new_entity = registry.spawn_entity();
```
---

### 4. **`entity_from_index`**

Retrieves an entity from its index.

#### Signature
```cpp
entity_t entity_from_index(std::size_t idx);
```
#### Explanation

- Returns the entity associated with the given index.

#### Example Usage
```cpp
entity_t entity = registry.entity_from_index(5);
```
---

### 5. **`kill_entity`**

Removes an entity and all its associated components.

#### Signature
```cpp
void kill_entity(entity_t const &e);
```
#### Explanation

- Destroys the specified entity and cleans up its components.

#### Example Usage
```cpp
registry.kill_entity(entity);
```
---

## 🛠️ **Systems**

Systems are the **logic** of the ECS. Each system processes entities that have specific components. Your systems are stored in the **`systems` folder** and are included in `systems.hpp`.

### **Example System: Bullet-Mob Collision**

This system handles collisions between player bullets and mobs, applying damage and removing entities when necessary.

#### Code Example
```cpp
void bullets_mobs_collisions_system(  
    Registry &r,  
    SparseArray<Position> &positions,  
    SparseArray<HitBox> &hitboxs,  
    SparseArray<Damage> &damages,  
    SparseArray<Health> &healths,  
    SparseArray<Mob> &mobs,  
    SparseArray<PlayerBullet> &bullets,  
    SparseArray<HitEvent> &hit_events)  
{  
    for (size_t i = 0; i < bullets.size() && i < positions.size() && i < hitboxs.size() && i < damages.size(); i++) {  
        auto &bullet = bullets[i];  
        auto &pos = positions[i];  
        auto &hitbox = hitboxs[i];  
        auto &damage = damages[i];  

        if (bullet && pos && hitbox && damage) {  
            // Check if bullet goes out of bounds  
            if (pos.value().getX() > 1920) {  
                r.kill_entity(r.entity_from_index(i));  
                continue;  
            }  

            for (size_t mi = 0; mi < mobs.size() && mi < positions.size() && mi < hitboxs.size() && mi < healths.size() && mi < hit_events.size(); mi++) {  
                auto &mob = mobs[mi];  
                auto &mpos = positions[mi];  
                auto &mhitbox = hitboxs[mi];  
                auto &mhealth = healths[mi];  
                auto &hit_event = hit_events[mi];  

                if (mob && mpos && mhitbox && mhealth && hit_event) {  
                    // Check for collision  
                    if (circleCircleCollisionMobs(pos.value(), hitbox.value(), mpos.value(), mhitbox.value())) {  
                        hit_event.value().setEvent(true);  
                        if (mhealth.value().getHealth() <= damage.value().getDamage()) {  
                            mhealth.value().setHealth(0);  
                        } else {  
                            mhealth.value().setHealth(mhealth.value().getHealth() - damage.value().getDamage());  
                        }  
                        r.kill_entity(r.entity_from_index(i));  
                        break;  
                    }  
                }  
            }  
        }  
    }  
}
```
#### Explanation

- **Outer Loop**: Iterates through bullets and their associated components (`Position`, `HitBox`, `Damage`).
- **Boundary Check**: Removes bullets that go out of screen bounds.
- **Inner Loop**: Iterates through mobs and checks for collisions.
- **Collision Detection**: Uses `circleCircleCollisionMobs` to detect collisions between bullets and mobs.
- **Damage Application**: Updates the mob's health based on the bullet's damage.
- **Entity Removal**: Deletes the bullet entity after a successful hit.

---

## 📝 **Summary**

- **Components**: Represent data.
- **Systems**: Handle logic by processing entities with specific components.
- **Core Functions**: Manage component registration, entity creation, and entity destruction.
- **Folder Organization**: Keeps components and systems modular and organized.

This structure promotes flexibility and scalability in your ECS-based project.
