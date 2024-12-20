
# Music Playlist Management System

A simple music playlist management system implemented using a **Doubly Circular Linked List** in C. This project allows users to manage songs in a playlist with functionalities like adding, inserting, deleting, playing songs, and displaying the playlist.

## Features

- **Add a song**: Adds a new song to the playlist.
- **Insert a song at a specific position**: Inserts a song at a specific position in the playlist.
- **Remove a song**: Deletes a song from the playlist by its position.
- **Play a song**: Play a song and navigate between songs in the playlist.
- **Display the Playlist**: View all songs in the playlist.

## Prerequisites

- **Programming Language**: C
- **Compiler**: Any C compiler (e.g., GCC)

## How to Run

1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-username/music-playlist-c.git
   cd music-playlist-c
   ```

2. **Build the project**:
   ```bash
   gcc -o playlist main.c
   ```

3. **Run the program**:
   ```bash
   ./playlist
   ```

## Usage

1. **Add Song**:
   ```bash
   1. Add song to playlist
   Enter the song name: Shape of You
   Enter the singer name: Ed Sheeran
   ```

2. **Insert Song**:
   ```bash
   2. Insert NEW song to playlist
   Enter the position to insert the song: 2
   Enter the song name: Blinding Lights
   Enter the singer name: The Weeknd
   ```

3. **Remove Song**:
   ```bash
   3. Remove song from playlist
   Enter the song number to delete: 2
   ```

4. **Play Song**:
   ```bash
   4. Play a song
   Enter the song number to play: 1
   ```

5. **Display Playlist**:
   ```bash
   5. Display the Playlist
   Song No.    Song                Singer
   ----------------------------------------------------------
   1           Shape of You         Ed Sheeran
   2           Blinding Lights      The Weeknd
   ----------------------------------------------------------
   ```

6. **Exit**:
   ```bash
   6. Quit
   ```

## Contribution

Contributions to this project are welcome! Fork the repository, make changes, and submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contact

- **Author**: Mayur Ahire
- **GitHub**: [github.com/your-username](https://github.com/your-username)

---

### Note:
This project uses basic memory management and may not be suitable for large inputs due to the use of `gets()` for input. It is recommended to use `fgets()` for more secure input handling in a real-world scenario.

---

Replace `your-username` with your actual GitHub username. This `README.md` file provides a concise guide on how to run the project and its features.
