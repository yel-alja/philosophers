# Philosophers 42

> Implementation of the classic **Dining Philosophers Problem** using threads and synchronization.  
> A project from the 42 curriculum that explores concurrency, deadlocks, and resource management.

---

## 🧵 About the Project
The Dining Philosophers problem is a classic concurrency challenge:  
- Philosophers sit around a table with a fork between each of them.  
- To eat, a philosopher needs **two forks**.  
- Philosophers alternate between **thinking**, **eating**, and **sleeping**.  
- The program must avoid **deadlocks** and **race conditions** while ensuring no philosopher starves.

This project demonstrates:
- Thread creation and management  
- Synchronization with mutexes  
- Avoiding deadlocks and starvation  
- Clean resource allocation and freeing  

---

### Installation
```bash
# Clone the repository
git clone https://github.com/<your-username>/philosopher42.git

# Navigate into the project
cd philosopher42

# Compilation
make

