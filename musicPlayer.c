#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Doubly Circular Linked List
typedef struct node {
    char song[50];
    char singer[50];
    struct node *next;
    struct node *prev;
} Node;

// Add a song to the playlist
Node *addSong(Node *head) {
    int c;
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("\nMemory allocation failed!!!");
        return head;
    }

    printf("\nEnter the song name: ");
    while ((c = getchar()) != '\n' && c != EOF);
    gets(newNode->song);

    printf("\nEnter the singer name: ");
    gets(newNode->singer);

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } 
    else {
        Node *tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    printf("\nSong added successfully!\n");
    return head;
}

// Insert a song at a specific position
Node *insertSong(Node *head) {
    int pos, c;
    printf("\nEnter the position to insert the song: ");
    scanf("%d", &pos);

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("\nMemory allocation failed!\n");
        return head;
    }

    printf("\nEnter the song name: ");
    while ((c = getchar()) != '\n' && c != EOF);
    gets(newNode->song);

    printf("\nEnter the singer name: ");
    gets(newNode->singer);

    if (pos == 1) { // Insert at the beginning
        if (head == NULL) { // List is empty
            head = newNode;
            head->next = head;
            head->prev = head;
        } 
        else { // Update head and tail pointers
            Node *tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    } 
    else { // Insert at a specific position
        Node *temp = head;
        int count = 1;

        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (count != pos - 1) {
            printf("\nPosition %d is out of bounds!\n", pos);
            free(newNode);
            return head;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    printf("\nSong inserted successfully at position %d.\n", pos);
    return head;
}

// Delete a song at a specific position
Node *deleteSong(Node *head) {
    if (head == NULL) {
        printf("\nThe playlist is empty. No song to delete.\n");
        return head;
    }

    int pos;
    printf("\nEnter the song number to delete: ");
    scanf("%d", &pos);

    Node *temp = head;
    int count = 1;

    if (pos == 1) { // Delete the first song
        if (head->next == head) { // Single song in the playlist
            free(head);
            head = NULL;
        } 
        else { // Multiple songs in the playlist
            Node *tail = head->prev;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            free(temp);
        }
    } 
    else { // Delete a song at a specific position
        while (count < pos && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (count != pos) { 
            printf("\nSong number %d does not exist in the playlist.\n", pos);
            return head;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }

    printf("\nSong deleted successfully.\n");
    return head;
}

// Play a song by position
void playSong(Node *head) {
    if (head == NULL) {
        printf("\nThe playlist is empty. No song to play.\n");
        return;
    }

    int pos, count = 1;
    printf("\nEnter the song number to play: ");
    scanf("%d", &pos);

    Node *temp = head;

    do {
        if (count == pos) break;
        temp = temp->next;
        count++;
    } while (temp != head);

    if (count != pos) {
        printf("\nInvalid song number! No song found at position %d.\n", pos);
        return;
    }

    printf("\nPlaying Song...\n");
    printf("-----------------------------------\n");
    printf("Now Playing: %-20s\n", temp->song);
    printf("Singer:      %-20s\n", temp->singer);
    printf("-----------------------------------\n");

    char command;
    do {
        printf("\nOptions:\n");
        printf("n - Next song\n");
        printf("p - Previous song\n");
        printf("q - Pause/Resume\n");
        printf("e - Exit\n");
        printf("Enter command: ");
        scanf(" %c", &command);

        switch (command) {
            case 'n': {
                temp = temp->next;
                printf("\nNow Playing: %-20s\n", temp->song);
                printf("Singer:      %-20s\n", temp->singer);
                break;
            }

            case 'p': {
                temp = temp->prev;
                printf("\nNow Playing: %-20s\n", temp->song);
                printf("Singer:      %-20s\n", temp->singer);
                break;
            }

            case 'q': {
                printf("\nPlayback paused. Press 'q' again to resume.\n");
                break;
            }

            case 'e': {
                printf("\nExiting playback.\n");
                return;
            }

            default: {
                printf("\nInvalid command! Please enter 'n', 'p', 'q', or 'e'.\n");
                break;
            }
        }
    } while (command != 'e');
}

// Display all songs in the playlist
void displaySongs(Node *head) {
    if (head == NULL) {
        printf("\nNo songs to display.\n");
        return;
    }

    Node *temp = head;
    int i = 1;
    printf("\nSong No.\t%-20s\t%-20s\n", "Song", "Singer");
    printf("----------------------------------------------------------\n");
    do {
        printf("%d\t\t%-20s\t%-20s\n", i, temp->song, temp->singer);
        temp = temp->next;
        i++;
    } while (temp != head);
    printf("----------------------------------------------------------\n");
}

int main() {
    int choice;
    Node *head = NULL;

    while (1) {
        printf("\n.....MUSIC_LOVERS.....\n");
        printf("---------------------------------------------------\n");
        printf("1. Add song to playlist\n");
        printf("2. Insert NEW song to playlist\n");
        printf("3. Remove song from playlist\n");
        printf("4. Play a song\n");
        printf("5. Display the Playlist\n");
        printf("6. Quit\n");
        printf("---------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = addSong(head);
                break;
            case 2:
                head = insertSong(head);
                break;
            case 3:
                head = deleteSong(head);
                break;
            case 4:
                playSong(head);
                break;
            case 5:
                displaySongs(head);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}
