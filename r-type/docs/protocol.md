# Protocol

# Server and Client Communication Protocol

## 1. Introduction
The protocol defined here manages **serialization** and **deserialization** of data between a server and a client in a game. It uses structures to represent players, bullets, and enemies, and ensures efficient transmission of information in binary format.

## 2. Important Definitions

### MAGIC_NUMBER
- **Constant**: `0xABCD1234`
- **Purpose**: Ensures unique identification of sent and received packets.

---

## 3. Data Structures

### 3.1 `player_data` Structure
This structure contains information related to a player.
| Field          | Type        | Description                      |
|----------------|-------------|----------------------------------|
| `player_id`    | `uint8_t`   | Unique player identifier         |
| `x_position`   | `float`     | Player's X position              |
| `y_position`   | `float`     | Player's Y position              |
| `shot_flag`    | `uint8_t`   | Shot status (1 = active shot)    |
| `hit_flag`     | `uint8_t`   | Damage status (1 = hit)          |

### 3.2 `bullet_data` Structure
This structure contains information about fired bullets.
| Field                | Type        | Description                             |
|-----------------------|-------------|-----------------------------------------|
| `x_position`          | `float`     | Bullet's X position                     |
| `y_position`          | `float`     | Bullet's Y position                     |
| `ally_enemy_flag`     | `uint8_t`   | 0 = Ally, 1 = Enemy                     |

### 3.3 `enemy_data` Structure
This structure contains information about enemies.
| Field                | Type        | Description                             |
|-----------------------|-------------|-----------------------------------------|
| `x_position`          | `float`     | Enemy's X position                      |
| `y_position`          | `float`     | Enemy's Y position                      |
| `shooting_flag`       | `uint8_t`   | Shooting status (1 = actively shooting) |
| `hit_flag`            | `uint8_t`   | Damage status (1 = hit)                 |
| `enemy_type`          | `uint8_t`   | Enemy type                              |

### 3.4 `packet` Structure
Represents a packet containing all data to be sent or received.

| Field                | Type                   | Description                             |
|-----------------------|------------------------|-----------------------------------------|
| `message_id`          | `uint16_t`             | Message identifier                      |
| `player_count`        | `uint8_t`              | Number of players                       |
| `players`             | `vector<player_data>`  | List of players                         |
| `bullet_count`        | `uint8_t`              | Number of bullets                       |
| `bullets`             | `vector<bullet_data>`  | List of bullets                         |
| `enemy_count`         | `uint8_t`              | Number of enemies                       |
| `enemies`             | `vector<enemy_data>`   | List of enemies                         |

---

## 4. `Input` Enumeration
Represents possible player input actions.
| Name     | Value |
|----------|-------|
| `LEFT`   | 0     |
| `RIGHT`  | 1     |
| `UP`     | 2     |
| `DOWN`   | 3     |
| `SHOOT`  | 4     |

---

## 5. `ProtocolServer` Class
This class manages **serialization** of packets to be sent from the server.

### 5.1 `serializePacket` Method
- **Prototype**: `static std::vector<uint8_t> serializePacket(const packet& pkt);`
- **Description**: Converts a `packet` object into a binary sequence (vector of `uint8_t`).

### 5.2 `deserializePacket` Method
- **Prototype**: `static Input deserializePacket(const std::vector<uint8_t>& buffer);`
- **Description**: Retrieves input data (type `Input`) from a binary sequence.

---

## 6. `ProtocolClient` Class
This class manages **serialization** of player actions and **deserialization** of received packets.

### 6.1 `serializePacket` Method
- **Prototype**: `static std::vector<uint8_t> serializePacket(Input input_);`
- **Description**: Converts a user action (type `Input`) into a binary sequence.

### 6.2 `deserializePacket` Method
- **Prototype**: `static packet deserializePacket(const std::vector<uint8_t>& buffer);`
- **Description**: Converts a binary sequence into a `packet` object containing game data.

### 6.3 Private Methods
These methods facilitate deserialization of internal structures:
- `deserializePlayerData`
- `deserializeBulletData`
- `deserializeEnemyData`

---

## 7. Data Flow
1. **Server Side**:
   - Retrieves game data (players, bullets, enemies).
   - Uses `serializePacket` to send this data to clients.

2. **Client Side**:
   - Sends user actions via `serializePacket`.
   - Receives binary packets and uses `deserializePacket` to interpret the game state.

---

## 8. Workflow Example
- **Server** collects information from 3 players, 2 bullets, and 1 enemy.
- It creates a `packet` object and serializes it to send to clients.
- **Client** sends a user action (e.g., `SHOOT`) via `serializePacket`.
- **Client** receives the packet, deserializes it, and uses the data to update its local state.

---

## 9. Conclusion
This protocol ensures efficient bidirectional communication between the server and clients. Binary serialization optimizes data transfer, and clear methods facilitate interpretation and management of game states.