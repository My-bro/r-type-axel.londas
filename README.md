
# R-Type Game Project

R-Type is a networked video game development project designed to implement a multi-threaded server and a graphical client for the classic R-Type game. This project showcases advanced C++ development techniques, good software engineering practices, and a custom-designed game engine.

---

## Project Overview

### Objective

The goal of this project is to:
- Develop a **networked multiplayer game** based on the R-Type legacy game.
- Create a **game engine** with visible and decoupled subsystems for rendering, networking, and game logic.
- Implement advanced features such as multi-threading, protocol design, and modular architecture.

### Key Deliverables
1. **Game Prototype**:
   - A playable R-Type game with core features.
   - Multiplayer support using a client-server architecture.
   - Core game engine implementation.
2. **Advanced Features**:
   - Enhanced software architecture.
   - Advanced networking and gameplay design.
   - Tools for content creation and management.

---

## Prerequisites

### Software Requirements
- **Build System**: CMake
- **Package Manager**: CPM
- **Languages**: C++, CMake, Docker
- **Target Platforms**: Linux, Windows
- **Rendering/Audio/Inputs Libraries**: SFML

### Installation
To install necessary dependencies, use the package manager specified in the repository and build the project using CMake:

```bash
mkdir build
cd build
cmake ..
cd ..
cmake --build build
```

---

## Architecture

### Server
- Implements all game logic.
- Handles multiplayer synchronization using UDP communication.
- **Features**:
  - Multi-threading for client handling.

### Client
- Responsible for graphical rendering and user inputs.
- Communicates with the server to sync game states.
- **Features**:
  - Smooth rendering of game entities and effects.
  - Input handling for player interactions.

### Protocol
- Binary protocol for communication between server and client.
- **Key Attributes**:
  - UDP-based communication for real-time performance.
  - Error handling for message drops, duplication, and reordering.
  - Extensible design for future updates.

---

## Usage

### Clone the Repository

```bash
git clone https://github.com/EpitechPromo2027/B-CPP-500-PAR-5-2-rtype-axel.londas.git R-type_Project
cd R-type_Project
```

### Build the Project

```bash
cmake --build build
```

### Running the Server

If there is no argument, default values are taken from [configuration_files/info.ini](documentation/configuration.md)
```bash
./r-type_server "[--port <server port>]"
```

### Running the Client

If there is no argument, default values are taken from [configuration_files/info.ini](documentation/configuration.md)
```bash
./r-type_client "[--host <server_ip>] [--port <server port>]"
```

---

## Testing

Unit tests are provided to validate core functionalities:

```bash
cd build
ctest
```

---

## Documentation

### Developer Documentation
- Includes architectural diagrams and system overviews.
- Provides a high-level explanation of the game engine and subsystems using Doxygen (documentation/docs/html/index.html).
- Available in the `documentation/` directory.
- To add a feature [documentation/add_features.md](documentation/add_features.md).

### Protocol Documentation
- Detailed binary protocol documentation is available in [documentation/protocol.md](documentation/protocol.md).
- Describes all message types, formats, and use cases.

### Tools
- CI/CD Workflow: Automated testing and builds for continuous integration.

---

## Contribution

### Guidelines
1. Follow the provided coding conventions [documentation/coding_guidelines.md](documentation/coding_guidelines.md).
2. Use feature branches for new development.
3. Submit merge requests with detailed descriptions.

---

## Contact

For any inquiries or contributions, contact the development team at:
- **Dev**: [Benjamin LAVALLEE](https://github.com/BenjaminLavallee)
- **Dev**: [Axel LONDAS](https://github.com/My-bro)
- **Dev**: [Abdallah Hammad](https://github.com/Abdlastreet)
- **Dev**: [reno-florian.roycee-raveendran](https://github.com/rno-flx)
- **Dev**: [Armod Elegbede](https://github.com/armod123)
- **Repository**: [GitHub Link](https://github.com/EpitechPromo2027/B-CPP-500-PAR-5-2-rtype-axel.londas.git)

---