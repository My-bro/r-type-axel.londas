# 📚 **Comparative Study of Technologies Used**

## ⚙️ **1. Programming Language: C++**

### **Why C++?**

- **Performance**: C++ is known for its high performance due to low-level memory control, which is essential for real-time applications like games.
- **Object-Oriented**: Supports encapsulation, inheritance, and polymorphism, making code modular and maintainable.
- **Standard Libraries**: Offers powerful libraries for data structures (e.g., `std::vector`, `std::unordered_map`) and algorithms.
- **Concurrency**: Provides multi-threading capabilities (`std::thread`, `std::async`), crucial for handling asynchronous networking and game loops.

### **Comparison with Other Languages**

| **Language** | **Pros**                                | **Cons**                                |
|--------------|------------------------------------------|-----------------------------------------|
| **C++**     | High performance, low-level control     | Steeper learning curve                  |
| **C#**      | Easier syntax, strong tooling support   | Slower performance, requires .NET       |
| **Python**  | Fast prototyping, easy to learn         | Not suitable for real-time applications |
| **Rust**    | Memory safety, high performance         | Young ecosystem, steeper learning curve |

---

## 🖥️ **2. Graphics Library: SFML (Simple and Fast Multimedia Library)**

### **Why SFML?**

- **Ease of Use**: SFML provides a simple API for 2D graphics, making it ideal for projects where ease of use and quick development are priorities.
- **Cross-Platform**: Supports Windows, Linux, and macOS, ensuring broad compatibility.
- **Performance**: Built on top of OpenGL, providing good performance for 2D games and multimedia applications.
- **Features**: Offers modules for graphics, audio, window handling, and networking.

### **Comparison with Other Graphics Libraries**

| **Library**     | **Pros**                                | **Cons**                                |
|-----------------|------------------------------------------|-----------------------------------------|
| **SFML**        | Simple API, good for 2D applications    | Limited for 3D graphics                 |
| **SDL**         | Low-level control, widely used          | More complex than SFML                  |
| **OpenGL**      | Powerful for 3D graphics                | Steep learning curve                    |
| **Unreal Engine** | High-quality 3D rendering            | Overkill for simple 2D games            |

---

## 🌐 **3. Networking Library: ASIO**

### **Why ASIO?**

- **Asynchronous Operations**: ASIO provides asynchronous I/O operations, making it ideal for networking in real-time applications.
- **Scalability**: Supports handling multiple connections concurrently without blocking the main thread.
- **Cross-Platform**: Works on various operating systems like Linux, Windows, and macOS.
- **Integration**: Easily integrates with C++ standard libraries and can work seamlessly in multi-threaded environments.

### **Comparison with Other Networking Libraries**

| **Library**      | **Pros**                                     | **Cons**                                |
|------------------|-----------------------------------------------|-----------------------------------------|
| **ASIO**         | Asynchronous, cross-platform                | Requires more boilerplate code          |
| **Boost.Asio**   | Extends ASIO with more utilities            | Dependency on Boost library             |
| **Enet**         | Reliable UDP-based networking                | Limited to low-level networking         |
| **ZeroMQ**       | High-level messaging patterns                | Not as low-level as ASIO                |

---

## 🕹️ **4. ECS Architecture (Entity Component System)**

### **Why ECS?**

- **Decoupling**: ECS promotes a clear separation of concerns by decoupling entities, components, and systems.
- **Scalability**: Easily extendable; new components and systems can be added without modifying existing code.
- **Performance**: Efficient use of cache-friendly data structures (e.g., contiguous arrays like `std::vector`).
- **Flexibility**: Systems operate independently, making it easy to parallelize tasks and optimize performance.

### **Comparison with Other Architectures**

| **Architecture**     | **Pros**                                         | **Cons**                                 |
|----------------------|--------------------------------------------------|------------------------------------------|
| **ECS**              | Decoupled, scalable, parallelizable              | Initial learning curve                   |
| **OOP (Object-Oriented Programming)** | Intuitive for small projects           | Tight coupling, less flexible            |
| **MVC (Model-View-Controller)** | Good for UI-based applications          | Not suitable for real-time systems       |

### **Key ECS Functions**

- **`register_component`**: Registers new components.
- **`add_component`**: Adds a component to an entity.
- **`spawn_entity`**: Creates a new entity.
- **`kill_entity`**: Removes an entity and its components.

---

## 🧠 **Algorithms and Data Structures**

### **Algorithms**

1. **Collision Detection**:  
   - **Circle-Circle Collision** for detecting collisions between bullets and mobs.
   - Optimized for real-time checks.

2. **Game Loop**:  
   - Uses a **fixed-time step** for consistent updates and rendering.

### **Data Structures**

1. **Sparse Arrays**:  
   - Used to efficiently store components, ensuring fast lookup and minimal memory usage.
   
2. **Unordered Maps**:  
   - Used for storing entities and their associated components for quick access.

---

## 💾 **Storage**

### **Why In-Memory Storage?**

- **Real-Time Performance**: In-memory storage (using `std::vector`, `std::unordered_map`) ensures fast access times.
- **No Persistence Requirement**: Since this is a game, there is no need for long-term persistence.

### **Considerations**

- **Future Extensions**: For saving game states, a simple serialization mechanism (e.g., JSON, binary files) can be added.

---

## 🔒 **Security**

### **Considerations in Networking**

1. **Input Validation**:  
   - Ensure all network packets are validated to prevent malformed or malicious data.

2. **Error Handling**:  
   - Graceful handling of network disconnections and errors.

3. **Future Improvements**:  
   - **Encryption**: Implement encryption (e.g., TLS) for secure data transfer.  
   - **Authentication**: Add user authentication to prevent unauthorized access.

---

## 🌐 **Modern Documentation**

### **Why MkDocs?**

- **Ease of Use**: Simple to write documentation in **Markdown**.
- **Static Site**: Generates a static website that is fast and easy to deploy.
- **Themes and Plugins**: Supports themes like **Material** and various plugins for enhanced functionality.
- **Deployment**: Easily deployable to platforms like **GitHub Pages**, **Netlify**, or **Vercel**.

### **Structure**

1. **`docs/` Folder**: Contains Markdown files.
2. **`mkdocs.yml`**: Configuration file to organize the site.
3. **Mermaid.js**: Integrate diagrams directly in Markdown.

---

## ✅ **Summary**

| **Category**           | **Technology**         | **Reason for Choice**                               |
|-------------------------|------------------------|-----------------------------------------------------|
| **Language**            | C++                    | Performance, low-level control                     |
| **Graphics Library**    | SFML                   | Ease of use, cross-platform 2D graphics            |
| **Networking Library**  | ASIO                   | Asynchronous networking, scalability               |
| **Architecture**        | ECS                    | Decoupling, scalability, performance               |
| **Documentation**       | MkDocs                 | Modern, Markdown-based documentation               |
