# Creating Your First System in the ECS Library

This guide will walk you through creating your first system using our Entity Component System (ECS) library.

## Prerequisites

- C++ compiler with C++17 support
- ECS library installed (`.so` shared library)

## Basic Setup

First, include the necessary header:

```cpp
#include <ecs/Registry.hpp>
```

## Understanding Components

Before creating a system, you'll need to define some components. Components are pure data structures that hold entity properties. Here's an example:

```cpp
struct Position {
    float x;
    float y;
};

struct Velocity {
    float dx;
    float dy;
};
```

## Registering Components

Before using components, you need to register them with the Registry:

```cpp
Registry registry;
registry.register_component<Position>();
registry.register_component<Velocity>();
```

## Creating Entities with Components

Let's create some entities that our system will process:

```cpp
// Spawn an entity
Entity entity = registry.spawn_entity();

// Add components to the entity
registry.add_component<Position>(entity, {0.0f, 0.0f});
registry.add_component<Velocity>(entity, {1.0f, 1.0f});
```

## Creating Your First System

A system is a function that processes entities with specific components. Here's how to create a movement system:

```cpp
void create_movement_system(Registry& registry)
{
    // Create a lambda that will be called each frame
    auto movement_system = [&registry]() {
        // Get the sparse arrays for Position and Velocity components
        auto& positions = registry.get_components<Position>();
        auto& velocities = registry.get_components<Velocity>();

        // Iterate through all entities that have both Position and Velocity
        for (size_t i = 0; i < positions.size(); ++i) {
            // Check if the entity has both components
            if (positions[i] && velocities[i]) {
                // Update position based on velocity
                positions[i]->x += velocities[i]->dx;
                positions[i]->y += velocities[i]->dy;
            }
        }
    };

    // Add the system to the registry
    registry.add_system(movement_system);
}
```

## Running Systems

To run all registered systems:

```cpp
// In your game loop or update function
registry.run_systems();
```

## Complete Example

Here's a complete example putting everything together:

```cpp
#include <ecs/Registry.hpp>

int main()
{
    // Create registry
    Registry registry;

    // Register components
    registry.register_component<Position>();
    registry.register_component<Velocity>();

    // Create movement system
    create_movement_system(registry);

    // Create some entities
    for (int i = 0; i < 5; ++i) {
        Entity entity = registry.spawn_entity();
        registry.add_component<Position>(entity, {float(i), 0.0f});
        registry.add_component<Velocity>(entity, {0.1f, 0.2f});
    }

    // Game loop
    for (int i = 0; i < 100; ++i) {
        registry.run_systems();
    }

    return 0;
}
```

## Error Handling

The library provides custom exceptions for error handling:

```cpp
try {
    // Your ECS code here
} catch (const RegistryError& e) {
    std::cerr << "Registry error: " << e.what() << std::endl;
} catch (const SparseArrayError& e) {
    std::cerr << "SparseArray error: " << e.what() << std::endl;
} catch (const ECSError& e) {
    std::cerr << "General ECS error: " << e.what() << std::endl;
}
```

## Best Practices

1. Always register components before using them
2. Use meaningful component names that describe their data
3. Keep systems focused on a single responsibility
4. Clean up entities when they're no longer needed using `registry.kill_entity(entity)`
5. Check for component existence before accessing them in systems

## Performance Tips

1. Register all components at startup to avoid runtime registration overhead
2. Batch entity creation when possible
3. Keep systems lightweight and focused on performance-critical operations
4. Consider component data locality when designing your systems

For more advanced usage and API details, refer to the library's header files.
